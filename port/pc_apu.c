/*
 * pc_apu.c
 * The GBA's sound hardware.
 *
 *  - PSG: the four Game Boy channels (two square waves, one with frequency
 *    sweep; a 4-bit wave channel with the GBA's two wave banks; noise), with
 *    their length counters, volume envelopes and the 512 Hz frame sequencer.
 *  - DirectSound: the two 8-bit FIFOs (A and B). A timer overflow plays the
 *    next byte of each FIFO bound to that timer; when a FIFO runs low, the
 *    DMA channel that targets it (special timing) refills it with 4 words.
 *  - Timers 0-3 (counting, prescalers, cascade) as far as sound needs them.
 *  - The output mixer (SOUNDCNT_L/H, SOUNDBIAS) producing 32768 Hz stereo,
 *    the rate the GBA's PWM output runs at by default.
 *
 * Time advances with the display beam: pc_frame.c calls PcApuStep() once per
 * scanline (1232 CPU cycles). Register writes take effect when the game
 * reports them through PcIoWritten() (see PC_IOW in include/gba/io_reg.h);
 * the IO array keeps the written values for the game to read back, and the
 * channel-status bits of SOUNDCNT_X are kept current.
 *
 * Behaviour follows GBATEK and was checked against mGBA's output.
 */
#include <string.h>
#include "pc_platform.h"

#define CYCLES_PER_SAMPLE 512     /* 16.78 MHz / 32768 Hz */
#define CYCLES_PER_SEQ_STEP 32768 /* 512 Hz frame sequencer */
#define OUT_RING 16384            /* stereo frames buffered for the frontend */

/* Register offsets */
#define R_NR10 0x60
#define R_NR11 0x62
#define R_NR12 0x63
#define R_NR13 0x64
#define R_NR14 0x65
#define R_NR21 0x68
#define R_NR22 0x69
#define R_NR23 0x6C
#define R_NR24 0x6D
#define R_NR30 0x70
#define R_NR31 0x72
#define R_NR32 0x73
#define R_NR33 0x74
#define R_NR34 0x75
#define R_NR41 0x78
#define R_NR42 0x79
#define R_NR43 0x7C
#define R_NR44 0x7D
#define R_NR50 0x80
#define R_NR51 0x81
#define R_SOUNDCNT_H 0x82
#define R_NR52 0x84
#define R_SOUNDBIAS 0x88
#define R_WAVE 0x90
#define R_FIFO_A 0xA0
#define R_FIFO_B 0xA4
#define R_DMA0 0xB0
#define R_TM0 0x100

typedef struct {
    int playing;
    int dacOn;
    /* envelope */
    int volume;
    int envInitial;
    int envDir;
    int envPeriod;
    int envCounter;
    /* length */
    int length;
    int lengthEnable;
    /* frequency / waveform position */
    int freq;
    int pos;
    uint64_t lastUpdate;
    /* square */
    int duty;
    /* sweep (channel 1) */
    int sweepPeriod;
    int sweepDir;
    int sweepShift;
    int sweepCounter;
    int sweepEnabled;
    int sweepShadow;
    /* noise */
    uint16_t lfsr;
    int noiseWidth7;
    int noiseDivisor;
    int noiseShift;
    int sample; /* current digital output 0..15 */
} PsgChannel;

typedef struct {
    uint8_t buf[32];
    int read;
    int count;
    int8_t sample; /* the byte currently on the DAC */
} Fifo;

typedef struct {
    int enabled;
    uint32_t src; /* internal source address (32-bit, as the game wrote it) */
} SoundDma;

typedef struct {
    int enabled;
    uint16_t reload;
    uint16_t control;
    uint32_t counter; /* 16-bit counter value */
    uint32_t prescaleAcc;
} Timer;

typedef struct {
    uint64_t now;          /* CPU cycles since boot */
    uint64_t nextSample;
    uint64_t nextSeqStep;
    int seqStep;
    int masterOn;
    PsgChannel ch[4];
    uint8_t wave[2][16];   /* the two wave RAM banks */
    Fifo fifo[2];
    SoundDma dma[4];
    Timer timer[4];
    float dcL, dcR;        /* DC-blocking filter state */
} ApuState;

static ApuState sApu;
/* Test aid: bit 0 mutes the PSG, bit 1 mutes DirectSound (pc_main_headless --mute). */
int gPcApuMute;

/* Output ring (32768 Hz stereo). Not part of the snapshot. */
static int16_t sOut[OUT_RING * 2];
static unsigned sOutWrite, sOutRead;

static const uint8_t sDuty[4][8] = {
    {0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 0},
};

static inline uint8_t Io8(int off) { return gPcIoRegs[off]; }

/* ------------------------------------------------------------------ */
/* PSG channels                                                         */
/* ------------------------------------------------------------------ */

static void UpdateStatusBits(void) {
    uint8_t s = Io8(R_NR52) & 0xF0;
    int i;
    for (i = 0; i < 4; i++)
        if (sApu.ch[i].playing)
            s |= (uint8_t)(1 << i);
    gPcIoRegs[R_NR52] = s;
}

/* Cycles between waveform steps. */
static uint32_t ChannelPeriod(int i) {
    const PsgChannel* c = &sApu.ch[i];
    switch (i) {
        case 0:
        case 1:
            return 16u * (2048u - (uint32_t)c->freq);
        case 2:
            return 8u * (2048u - (uint32_t)c->freq);
        default: {
            uint32_t d = c->noiseDivisor ? 2u * (uint32_t)c->noiseDivisor : 1u;
            return (d << c->noiseShift) * 32u;
        }
    }
}

static int WaveSample(const PsgChannel* c) {
    int bank = (Io8(R_NR30) >> 6) & 1;
    int size64 = (Io8(R_NR30) >> 5) & 1;
    int pos = c->pos & (size64 ? 63 : 31);
    int b = size64 ? (bank ^ (pos >> 5)) : bank;
    uint8_t byte = sApu.wave[b][(pos & 31) >> 1];
    int nib = (pos & 1) ? (byte & 15) : (byte >> 4);
    uint8_t vol = Io8(R_NR32);
    if (vol & 0x80)
        return (nib * 3) >> 2;
    switch ((vol >> 5) & 3) {
        case 0: return 0;
        case 1: return nib;
        case 2: return nib >> 1;
        default: return nib >> 2;
    }
}

static void StepNoise(PsgChannel* c) {
    int bit = (c->lfsr ^ (c->lfsr >> 1)) & 1;
    c->lfsr = (uint16_t)((c->lfsr >> 1) | (bit << 14));
    if (c->noiseWidth7)
        c->lfsr = (uint16_t)((c->lfsr & ~0x40) | (bit << 6));
}

static void RefreshSample(int i) {
    PsgChannel* c = &sApu.ch[i];
    if (!c->playing || !c->dacOn) {
        c->sample = 0;
        return;
    }
    switch (i) {
        case 0:
        case 1:
            c->sample = sDuty[c->duty][c->pos & 7] ? c->volume : 0;
            break;
        case 2:
            c->sample = WaveSample(c);
            break;
        default:
            c->sample = (c->lfsr & 1) ? 0 : c->volume;
            break;
    }
}

/* Advances a channel's waveform to the current time. */
static void RunChannel(int i) {
    PsgChannel* c = &sApu.ch[i];
    uint64_t now = sApu.now;
    uint32_t period;
    uint64_t steps;

    if (!c->playing) {
        c->lastUpdate = now;
        return;
    }
    period = ChannelPeriod(i);
    if (now - c->lastUpdate < period)
        return;
    steps = (now - c->lastUpdate) / period;
    c->lastUpdate += steps * period;
    if (i == 3) {
        uint64_t k;
        if (steps > 0x8000)
            steps = 0x8000 + (steps & 0x7FFF); /* the LFSR cycle is at most 32767 long */
        for (k = 0; k < steps; k++)
            StepNoise(c);
    } else {
        c->pos = (int)((c->pos + steps) & 63);
    }
    RefreshSample(i);
}

static void RunAllChannels(void) {
    int i;
    for (i = 0; i < 4; i++)
        RunChannel(i);
}

static int SweepNext(PsgChannel* c) {
    int delta = c->sweepShadow >> c->sweepShift;
    return c->sweepDir ? c->sweepShadow - delta : c->sweepShadow + delta;
}

static void Trigger(int i) {
    PsgChannel* c = &sApu.ch[i];

    RunChannel(i);
    c->playing = c->dacOn;
    if (c->length == 0)
        c->length = (i == 2) ? 256 : 64;
    c->lastUpdate = sApu.now;
    if (i == 2) {
        c->pos = 0;
    } else {
        c->volume = c->envInitial;
        c->envCounter = c->envPeriod;
    }
    if (i == 3)
        c->lfsr = 0x7FFF;
    if (i == 0) {
        c->sweepShadow = c->freq;
        c->sweepCounter = c->sweepPeriod ? c->sweepPeriod : 8;
        c->sweepEnabled = c->sweepPeriod || c->sweepShift;
        if (c->sweepShift && SweepNext(c) > 2047)
            c->playing = 0;
    }
    RefreshSample(i);
    UpdateStatusBits();
}

static void WriteEnvelope(int i, uint8_t v) {
    PsgChannel* c = &sApu.ch[i];
    c->envInitial = v >> 4;
    c->envDir = (v >> 3) & 1;
    c->envPeriod = v & 7;
    c->dacOn = (v & 0xF8) != 0;
    if (!c->dacOn)
        c->playing = 0;
}

static void WriteControl(int i, uint8_t v) {
    PsgChannel* c = &sApu.ch[i];
    if (i != 3)
        c->freq = (c->freq & 0xFF) | ((v & 7) << 8);
    c->lengthEnable = (v >> 6) & 1;
    if (v & 0x80)
        Trigger(i);
}

static void SequencerStep(void) {
    int step = sApu.seqStep;
    int i;

    RunAllChannels();
    if ((step & 1) == 0) { /* length: 256 Hz */
        for (i = 0; i < 4; i++) {
            PsgChannel* c = &sApu.ch[i];
            if (c->lengthEnable && c->length > 0 && --c->length == 0)
                c->playing = 0;
        }
    }
    if (step == 2 || step == 6) { /* sweep: 128 Hz */
        PsgChannel* c = &sApu.ch[0];
        if (c->sweepEnabled && --c->sweepCounter <= 0) {
            c->sweepCounter = c->sweepPeriod ? c->sweepPeriod : 8;
            if (c->sweepPeriod) {
                int f = SweepNext(c);
                if (f > 2047) {
                    c->playing = 0;
                } else if (c->sweepShift) {
                    c->sweepShadow = f;
                    c->freq = f;
                    if (SweepNext(c) > 2047)
                        c->playing = 0;
                }
            }
        }
    }
    if (step == 7) { /* envelope: 64 Hz */
        for (i = 0; i < 4; i++) {
            PsgChannel* c = &sApu.ch[i];
            if (i == 2 || c->envPeriod == 0)
                continue;
            if (--c->envCounter <= 0) {
                c->envCounter = c->envPeriod;
                if (c->envDir && c->volume < 15)
                    c->volume++;
                else if (!c->envDir && c->volume > 0)
                    c->volume--;
            }
        }
    }
    sApu.seqStep = (step + 1) & 7;
    for (i = 0; i < 4; i++)
        RefreshSample(i);
    UpdateStatusBits();
}

/* ------------------------------------------------------------------ */
/* DirectSound                                                          */
/* ------------------------------------------------------------------ */

static uint32_t FifoAddress(int f) {
    return (uint32_t)(uintptr_t)(gPcIoRegs + (f ? R_FIFO_B : R_FIFO_A));
}

static void FifoPush(Fifo* f, uint8_t b) {
    if (f->count >= 32) {
        /* Overflow: the hardware drops the oldest data. */
        f->read = (f->read + 1) & 31;
        f->count--;
    }
    f->buf[(f->read + f->count) & 31] = b;
    f->count++;
}

static void FifoPushWord(Fifo* f, uint32_t w) {
    FifoPush(f, (uint8_t)w);
    FifoPush(f, (uint8_t)(w >> 8));
    FifoPush(f, (uint8_t)(w >> 16));
    FifoPush(f, (uint8_t)(w >> 24));
}

/* Copies 4 words from a sound DMA's source into a FIFO. */
static void DmaTransfer(int d, int f) {
    SoundDma* dma = &sApu.dma[d];
    uint16_t cntH = (uint16_t)(PC_IO32(R_DMA0 + d * 12 + 8) >> 16);
    int srcMode = (cntH >> 7) & 3;
    int i;

    for (i = 0; i < 4; i++) {
        uint32_t w;
        const uint8_t* p = (const uint8_t*)(uintptr_t)(dma->src & ~3u);
        if ((uintptr_t)p < 0x10000)
            w = 0; /* nothing mapped there on PC */
        else
            memcpy(&w, p, 4);
        FifoPushWord(&sApu.fifo[f], w);
        if (srcMode == 0 || srcMode == 3)
            dma->src += 4;
        else if (srcMode == 1)
            dma->src -= 4;
    }
}

/* The DMA channel (1 or 2) feeding FIFO f, or -1. */
static int DmaForFifo(int f) {
    int d;
    for (d = 1; d <= 2; d++) {
        uint32_t dad = PC_IO32(R_DMA0 + d * 12 + 4);
        uint16_t cntH = (uint16_t)(PC_IO32(R_DMA0 + d * 12 + 8) >> 16);
        if (sApu.dma[d].enabled && ((cntH >> 12) & 3) == 3 && dad == FifoAddress(f))
            return d;
    }
    return -1;
}

static void TimerOverflow(int t) {
    uint16_t cnt = PC_IO16(R_SOUNDCNT_H);
    int f;

    for (f = 0; f < 2; f++) {
        int timerSel = (cnt >> (f ? 14 : 10)) & 1;
        Fifo* fifo = &sApu.fifo[f];
        if (timerSel != t)
            continue;
        if (fifo->count > 0) {
            fifo->sample = (int8_t)fifo->buf[fifo->read];
            fifo->read = (fifo->read + 1) & 31;
            fifo->count--;
        }
        if (fifo->count <= 16) {
            int d = DmaForFifo(f);
            if (d >= 0)
                DmaTransfer(d, f);
        }
    }
}

/* ------------------------------------------------------------------ */
/* Timers                                                               */
/* ------------------------------------------------------------------ */

static const int sPrescaleShift[4] = {0, 6, 8, 10};

/* Cycles until timer t overflows (only for free-running timers). */
static uint64_t TimerCyclesToOverflow(const Timer* tm) {
    uint32_t shift = (uint32_t)sPrescaleShift[tm->control & 3];
    uint64_t ticks = 0x10000u - tm->counter;
    return (ticks << shift) - tm->prescaleAcc;
}

static void TimerTick(int t, uint32_t ticks);

static void TimerOverflowChain(int t) {
    TimerOverflow(t);
    if (t < 3) {
        Timer* next = &sApu.timer[t + 1];
        if (next->enabled && (next->control & 4))
            TimerTick(t + 1, 1);
    }
}

static void TimerTick(int t, uint32_t ticks) {
    Timer* tm = &sApu.timer[t];
    while (ticks > 0) {
        uint32_t room = 0x10000u - tm->counter;
        if (ticks < room) {
            tm->counter += ticks;
            return;
        }
        ticks -= room;
        tm->counter = tm->reload;
        TimerOverflowChain(t);
    }
}

/* Advances free-running timers by `cycles`. */
static void RunTimers(uint32_t cycles) {
    int t;
    for (t = 0; t < 4; t++) {
        Timer* tm = &sApu.timer[t];
        uint32_t shift;
        uint64_t total;
        if (!tm->enabled || (tm->control & 4))
            continue;
        shift = (uint32_t)sPrescaleShift[tm->control & 3];
        total = (uint64_t)tm->prescaleAcc + cycles;
        tm->prescaleAcc = (uint32_t)(total & ((1u << shift) - 1));
        TimerTick(t, (uint32_t)(total >> shift));
    }
}

/* ------------------------------------------------------------------ */
/* Output                                                               */
/* ------------------------------------------------------------------ */

static void EmitSample(void) {
    uint16_t cntL = PC_IO16(R_NR50);
    uint16_t cntH = PC_IO16(R_SOUNDCNT_H);
    uint16_t bias = PC_IO16(R_SOUNDBIAS) & 0x3FE;
    int psgL = 0, psgR = 0, l, r, i;
    int psgShift = 4 - (cntH & 3);
    float fl, fr;

    if (psgShift < 2)
        psgShift = 2; /* value 3 is "prohibited"; treat as 100% */
    RunAllChannels();
    for (i = 0; i < 4; i++) {
        int s = sApu.ch[i].sample;
        if (cntL & (0x100 << i))
            psgR += s;
        if (cntL & (0x1000 << i))
            psgL += s;
    }
    psgR = ((psgR << 3) * (1 + (cntL & 7))) >> psgShift;
    psgL = ((psgL << 3) * (1 + ((cntL >> 4) & 7))) >> psgShift;
    if (!sApu.masterOn || (gPcApuMute & 1))
        psgL = psgR = 0;

    l = psgL;
    r = psgR;
    for (i = 0; i < 2; i++) {
        int s = (gPcApuMute & 2) ? 0 : (sApu.fifo[i].sample << 2) >> !((cntH >> (2 + i)) & 1);
        if (cntH & (0x100 << (i * 4)))
            r += s;
        if (cntH & (0x200 << (i * 4)))
            l += s;
    }

    /* 10-bit DAC around SOUNDBIAS. */
    l += bias;
    r += bias;
    l = l < 0 ? 0 : l > 0x3FF ? 0x3FF : l;
    r = r < 0 ? 0 : r > 0x3FF ? 0x3FF : r;
    l = ((l - bias) * 0x100 * 3) >> 4;
    r = ((r - bias) * 0x100 * 3) >> 4;

    /* The console's output capacitors remove DC (the PSG is unipolar). */
    if (!(gPcApuMute & 4)) {
        fl = (float)l - sApu.dcL;
        fr = (float)r - sApu.dcR;
        sApu.dcL += fl * 0.0005f;
        sApu.dcR += fr * 0.0005f;
        l = (int)fl;
        r = (int)fr;
    }
    l = l < -32768 ? -32768 : l > 32767 ? 32767 : l;
    r = r < -32768 ? -32768 : r > 32767 ? 32767 : r;

    if (sOutWrite - sOutRead >= OUT_RING)
        sOutRead++; /* nobody is reading fast enough: drop the oldest */
    sOut[(sOutWrite % OUT_RING) * 2] = (int16_t)l;
    sOut[(sOutWrite % OUT_RING) * 2 + 1] = (int16_t)r;
    sOutWrite++;
}

unsigned PcApuReadSamples(int16_t* out, unsigned maxFrames) {
    unsigned n = 0;
    while (n < maxFrames && sOutRead != sOutWrite) {
        out[n * 2] = sOut[(sOutRead % OUT_RING) * 2];
        out[n * 2 + 1] = sOut[(sOutRead % OUT_RING) * 2 + 1];
        sOutRead++;
        n++;
    }
    return n;
}

/* ------------------------------------------------------------------ */
/* Time                                                                 */
/* ------------------------------------------------------------------ */

void PcApuStep(uint32_t cycles) {
    uint64_t end = sApu.now + cycles;

    while (sApu.now < end) {
        uint64_t next = end;
        uint64_t t;
        int k;

        if (sApu.nextSample < next)
            next = sApu.nextSample;
        if (sApu.nextSeqStep < next)
            next = sApu.nextSeqStep;
        for (k = 0; k < 4; k++) {
            Timer* tm = &sApu.timer[k];
            if (tm->enabled && !(tm->control & 4)) {
                t = sApu.now + TimerCyclesToOverflow(tm);
                if (t < next)
                    next = t;
            }
        }

        RunTimers((uint32_t)(next - sApu.now));
        sApu.now = next;
        if (sApu.now >= sApu.nextSeqStep) {
            sApu.nextSeqStep += CYCLES_PER_SEQ_STEP;
            if (sApu.masterOn)
                SequencerStep();
        }
        if (sApu.now >= sApu.nextSample) {
            sApu.nextSample += CYCLES_PER_SAMPLE;
            EmitSample();
        }
    }
}

/* ------------------------------------------------------------------ */
/* Register writes                                                      */
/* ------------------------------------------------------------------ */

static void SoundDmaControlWritten(int d) {
    uint16_t cntH = (uint16_t)(PC_IO32(R_DMA0 + d * 12 + 8) >> 16);
    int enable = (cntH >> 15) & 1;
    SoundDma* dma = &sApu.dma[d];

    if (enable && !dma->enabled) {
        dma->src = PC_IO32(R_DMA0 + d * 12);
        dma->enabled = 1;
        if (((cntH >> 12) & 3) == 0) {
            /* Immediate transfer into a FIFO (the m4a "flush" idiom). */
            uint32_t dad = PC_IO32(R_DMA0 + d * 12 + 4);
            int f = dad == FifoAddress(0) ? 0 : dad == FifoAddress(1) ? 1 : -1;
            if (f >= 0)
                DmaTransfer(d, f);
            dma->enabled = 0;
            PC_IO32(R_DMA0 + d * 12 + 8) &= ~0x80000000u;
        }
    } else if (!enable) {
        dma->enabled = 0;
    }
}

static void TimerControlWritten(int t) {
    Timer* tm = &sApu.timer[t];
    uint16_t cnt = PC_IO16(R_TM0 + t * 4 + 2);
    int enable = (cnt >> 7) & 1;

    if (enable && !tm->enabled) {
        tm->counter = PC_IO16(R_TM0 + t * 4);
        tm->prescaleAcc = 0;
    }
    tm->enabled = enable;
    tm->control = cnt;
    tm->reload = PC_IO16(R_TM0 + t * 4);
}

static void MasterWritten(void) {
    int on = (Io8(R_NR52) >> 7) & 1;
    if (!on && sApu.masterOn) {
        int i;
        for (i = 0; i < 4; i++)
            memset(&sApu.ch[i], 0, sizeof(sApu.ch[i]));
        memset(gPcIoRegs + 0x60, 0, 0x22); /* SOUND1CNT_L .. SOUNDCNT_L */
    } else if (on && !sApu.masterOn) {
        sApu.seqStep = 0;
    }
    sApu.masterOn = on;
    UpdateStatusBits();
}

static void ByteWritten(int off, unsigned size, unsigned index) {
    uint8_t v = Io8(off);

    if (off >= R_WAVE && off < R_WAVE + 16) {
        int bank = ((Io8(R_NR30) >> 6) & 1) ^ 1; /* the CPU sees the other bank */
        if (!sApu.masterOn)
            bank = 1;
        RunChannel(2);
        sApu.wave[bank][off - R_WAVE] = v;
        return;
    }
    if (off >= R_FIFO_A && off < R_FIFO_A + 8) {
        FifoPush(&sApu.fifo[off >= R_FIFO_B], v);
        return;
    }
    if (!sApu.masterOn && off >= 0x60 && off < 0x82)
        return; /* PSG registers ignore writes while sound is off */

    switch (off) {
        case R_NR10:
            sApu.ch[0].sweepShift = v & 7;
            sApu.ch[0].sweepDir = (v >> 3) & 1;
            sApu.ch[0].sweepPeriod = (v >> 4) & 7;
            break;
        case R_NR11:
        case R_NR21:
        case R_NR41: {
            int i = off == R_NR11 ? 0 : off == R_NR21 ? 1 : 3;
            RunChannel(i);
            sApu.ch[i].duty = v >> 6;
            sApu.ch[i].length = 64 - (v & 63);
            break;
        }
        case R_NR12:
            RunChannel(0);
            WriteEnvelope(0, v);
            break;
        case R_NR22:
            RunChannel(1);
            WriteEnvelope(1, v);
            break;
        case R_NR42:
            RunChannel(3);
            WriteEnvelope(3, v);
            break;
        case R_NR13:
        case R_NR23:
        case R_NR33: {
            int i = off == R_NR13 ? 0 : off == R_NR23 ? 1 : 2;
            RunChannel(i);
            sApu.ch[i].freq = (sApu.ch[i].freq & 0x700) | v;
            break;
        }
        case R_NR14:
            WriteControl(0, v);
            break;
        case R_NR24:
            WriteControl(1, v);
            break;
        case R_NR34:
            WriteControl(2, v);
            break;
        case R_NR44:
            WriteControl(3, v);
            break;
        case R_NR30:
            RunChannel(2);
            sApu.ch[2].dacOn = (v >> 7) & 1;
            if (!sApu.ch[2].dacOn)
                sApu.ch[2].playing = 0;
            break;
        case R_NR31:
            sApu.ch[2].length = 256 - v;
            break;
        case R_NR32:
            RunChannel(2);
            break;
        case R_NR43:
            RunChannel(3);
            sApu.ch[3].noiseDivisor = v & 7;
            sApu.ch[3].noiseWidth7 = (v >> 3) & 1;
            sApu.ch[3].noiseShift = v >> 4;
            break;
        case R_SOUNDCNT_H + 1:
            if (v & 0x08) { /* FIFO A reset */
                sApu.fifo[0].count = 0;
                sApu.fifo[0].read = 0;
            }
            if (v & 0x80) { /* FIFO B reset */
                sApu.fifo[1].count = 0;
                sApu.fifo[1].read = 0;
            }
            gPcIoRegs[off] = v & 0x77; /* reset bits are write-only */
            break;
        case R_NR52:
            MasterWritten();
            break;
        default:
            break;
    }
    UpdateStatusBits();
    (void)size;
    (void)index;
}

void PcIoWritten(volatile void* reg, unsigned size) {
    uintptr_t addr = (uintptr_t)reg;
    int off;
    unsigned i;

    if (addr < (uintptr_t)gPcIoRegs || addr >= (uintptr_t)gPcIoRegs + PC_IO_SIZE)
        return;
    off = (int)(addr - (uintptr_t)gPcIoRegs);

    /* DMA and timer control registers are handled as units. */
    if (off >= R_DMA0 && off < R_DMA0 + 48) {
        int d = (off - R_DMA0) / 12;
        int last = off + (int)size - 1;
        int cntH = R_DMA0 + d * 12 + 10;
        if (off <= cntH + 1 && last >= cntH && (d == 1 || d == 2))
            SoundDmaControlWritten(d);
        return;
    }
    if (off >= R_TM0 && off < R_TM0 + 16) {
        int t = (off - R_TM0) / 4;
        int last = off + (int)size - 1;
        int cntH = R_TM0 + t * 4 + 2;
        if (off <= cntH + 1 && last >= cntH) {
            RunTimers(0);
            TimerControlWritten(t);
        } else {
            sApu.timer[t].reload = PC_IO16(R_TM0 + t * 4);
        }
        return;
    }
    for (i = 0; i < size; i++) {
        /* NR52 is a 16-bit register whose low byte holds the read-only
         * status bits; a 16-bit write must not lose the master bit. */
        ByteWritten(off + (int)i, size, i);
    }
}

void PcApuReset(void) {
    memset(&sApu, 0, sizeof(sApu));
    sApu.nextSample = CYCLES_PER_SAMPLE;
    sApu.nextSeqStep = CYCLES_PER_SEQ_STEP;
    PC_IO16(R_SOUNDBIAS) = 0x200;
}

void* PcApuState(size_t* size) {
    *size = sizeof(sApu);
    return &sApu;
}
