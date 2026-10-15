/*
 * pc_audio_out.c
 * Plays the emulated sound hardware's output through SDL2.
 *
 * The GBA produces 32768 Hz stereo (pc_apu.c). Each frame the game thread
 * converts the new samples to the sound card's rate with a windowed-sinc
 * resampler and queues them in a lock-free ring that SDL's audio thread
 * drains. The host's video pacing and the sound card's clock drift slowly
 * apart, so the conversion ratio is nudged (at most 0.5%, inaudible) to keep
 * the ring at its target fill: no gaps, no growing latency.
 */
#include <math.h>
#include <string.h>
#include <SDL.h>
#include "pc_platform.h"

#define TAPS 32                /* resampler taps (even) */
#define PHASES 256             /* sub-sample positions of the kernel table */
#define RING_FRAMES 16384      /* output ring, stereo frames */
#define MAX_ADJUST 0.005       /* +-0.5% rate correction */

static SDL_AudioDeviceID sDevice;
static int sRate;               /* device rate */
static float sKernel[PHASES + 1][TAPS];
static float sHistory[TAPS * 2][2];   /* recent input frames (doubled for wrap-free reads) */
static int sHistPos;
static double sPhase;           /* position between the last two inputs, 0..1 */
static double sStep;            /* input frames per output frame */
static double sSpeed = 1.0;     /* game speed relative to the GBA (60 Hz lock) */
static float sGain = 1.0f;
static int sTargetFill;

static float sRing[RING_FRAMES][2];
static SDL_atomic_t sRead, sWrite;  /* frame counters (wrap at 2^31 is fine for unsigned math) */
static unsigned sUnderruns;

static double Sinc(double x) {
    return fabs(x) < 1e-9 ? 1.0 : sin(M_PI * x) / (M_PI * x);
}

static void BuildKernel(double cutoff) {
    int p, t;
    for (p = 0; p <= PHASES; p++) {
        double frac = (double)p / PHASES;
        double sum = 0;
        for (t = 0; t < TAPS; t++) {
            double x = (double)(t - TAPS / 2 + 1) - frac; /* distance to the output point */
            double w = 0.42 + 0.5 * cos(M_PI * x / (TAPS / 2)) + 0.08 * cos(2 * M_PI * x / (TAPS / 2)); /* Blackman */
            double v = (fabs(x) >= TAPS / 2) ? 0.0 : cutoff * Sinc(cutoff * x) * w;
            sKernel[p][t] = (float)v;
            sum += v;
        }
        for (t = 0; t < TAPS; t++)
            sKernel[p][t] = (float)(sKernel[p][t] / sum); /* unity DC gain */
    }
}

static void SDLCALL Callback(void* user, Uint8* stream, int len) {
    int16_t* out = (int16_t*)stream;
    int frames = len / 4, i;
    unsigned r = (unsigned)SDL_AtomicGet(&sRead);
    unsigned w = (unsigned)SDL_AtomicGet(&sWrite);
    (void)user;

    for (i = 0; i < frames; i++) {
        if (r == w) {
            out[i * 2] = out[i * 2 + 1] = 0;
            if (i == 0)
                sUnderruns++;
            continue;
        }
        {
            float l = sRing[r % RING_FRAMES][0], rr = sRing[r % RING_FRAMES][1];
            l = l > 32767.f ? 32767.f : l < -32768.f ? -32768.f : l;
            rr = rr > 32767.f ? 32767.f : rr < -32768.f ? -32768.f : rr;
            out[i * 2] = (int16_t)lrintf(l);
            out[i * 2 + 1] = (int16_t)lrintf(rr);
        }
        r++;
    }
    SDL_AtomicSet(&sRead, (int)r);
}

int PcAudioOpen(int volumePercent) {
    SDL_AudioSpec want, have;

    if (SDL_InitSubSystem(SDL_INIT_AUDIO) != 0) {
        PcLog("[pc] audio: %s\n", SDL_GetError());
        return 0;
    }
    memset(&want, 0, sizeof(want));
    want.freq = 48000;
    want.format = AUDIO_S16SYS;
    want.channels = 2;
    want.samples = 1024;
    want.callback = Callback;
    sDevice = SDL_OpenAudioDevice(NULL, 0, &want, &have, SDL_AUDIO_ALLOW_FREQUENCY_CHANGE);
    if (sDevice == 0) {
        PcLog("[pc] audio: cannot open a device: %s\n", SDL_GetError());
        return 0;
    }
    sRate = have.freq;
    sStep = (double)PC_AUDIO_RATE / sRate * sSpeed;
    /* Cut a little below the lower of the two Nyquist rates. */
    BuildKernel(0.90 * (sRate < PC_AUDIO_RATE ? (double)sRate / PC_AUDIO_RATE : 1.0));
    sGain = (float)(volumePercent < 0 ? 0 : volumePercent > 100 ? 100 : volumePercent) / 100.0f;
    /* Aim to keep ~3 frames of sound queued beyond the device's own buffer. */
    sTargetFill = sRate / 20 + have.samples / 2;
    SDL_AtomicSet(&sRead, 0);
    SDL_AtomicSet(&sWrite, 0);
    PcLog("[pc] audio: %d Hz, device buffer %d frames, volume %d%%\n", sRate, have.samples, volumePercent);
    SDL_PauseAudioDevice(sDevice, 0);
    return 1;
}

static void Push(float l, float r) {
    unsigned w = (unsigned)SDL_AtomicGet(&sWrite);
    unsigned rd = (unsigned)SDL_AtomicGet(&sRead);
    if (w - rd >= RING_FRAMES)
        return; /* full: drop */
    sRing[w % RING_FRAMES][0] = l;
    sRing[w % RING_FRAMES][1] = r;
    SDL_AtomicSet(&sWrite, (int)(w + 1));
}

/* Converts newly produced GBA samples; call once per frame. When `mute` is
 * set (fast forward) the samples are discarded. */
void PcAudioUpdate(int mute) {
    int16_t in[2048 * 2];
    unsigned n, i;
    double step;
    int fill;

    if (sDevice == 0) {
        while (PcApuReadSamples(in, 2048) > 0) {
        }
        return;
    }

    fill = (int)((unsigned)SDL_AtomicGet(&sWrite) - (unsigned)SDL_AtomicGet(&sRead));
    if (!mute && fill < sTargetFill / 4) {
        /* Starting, or back from mute / fast forward / a stall: queue a
         * short silence so playback resumes at the target latency instead
         * of crackling while the rate control catches up. */
        while (fill < sTargetFill) {
            Push(0, 0);
            fill++;
        }
    }
    {
        double err = (double)(fill - sTargetFill) / sTargetFill;
        double adj = err * MAX_ADJUST;
        if (adj > MAX_ADJUST) adj = MAX_ADJUST;
        if (adj < -MAX_ADJUST) adj = -MAX_ADJUST;
        /* Too full: consume input faster per output frame (fewer outputs). */
        step = sStep * (1.0 + adj);
    }

    while ((n = PcApuReadSamples(in, 2048)) > 0) {
        if (mute)
            continue;
        for (i = 0; i < n; i++) {
            /* Add one input frame to the history. */
            sHistPos = (sHistPos + 1) % TAPS;
            sHistory[sHistPos][0] = sHistory[sHistPos + TAPS][0] = in[i * 2] * sGain;
            sHistory[sHistPos][1] = sHistory[sHistPos + TAPS][1] = in[i * 2 + 1] * sGain;
            /* Emit every output frame that falls before the next input. */
            while (sPhase < 1.0) {
                const float* k = sKernel[(int)(sPhase * PHASES)];
                const float(*h)[2] = &sHistory[sHistPos + 1];
                float l = 0, r = 0;
                int t;
                for (t = 0; t < TAPS; t++) {
                    l += h[t][0] * k[t];
                    r += h[t][1] * k[t];
                }
                Push(l, r);
                sPhase += step;
            }
            sPhase -= 1.0;
        }
    }
}

/* The game runs `speed` times faster than a GBA (locked to a 60 Hz
 * monitor: 60 / 59.73); play its sound that much faster to keep up. */
void PcAudioSetSpeed(double speed) {
    if (speed < 0.5)
        speed = 0.5;
    sSpeed = speed;
    if (sRate) {
        double inRate = PC_AUDIO_RATE * (speed > 1.0 ? speed : 1.0);
        sStep = (double)PC_AUDIO_RATE / sRate * sSpeed;
        /* Fast forward reads the input N times faster: cut below the new
         * Nyquist rate so the sped-up music does not alias. */
        BuildKernel(0.90 * (sRate < inRate ? (double)sRate / inRate : 1.0));
    }
}

void PcAudioSetVolume(int volumePercent) {
    sGain = (float)(volumePercent < 0 ? 0 : volumePercent > 100 ? 100 : volumePercent) / 100.0f;
}

void PcAudioPause(int paused) {
    if (sDevice)
        SDL_PauseAudioDevice(sDevice, paused);
}

void PcAudioClose(void) {
    if (sDevice) {
        SDL_CloseAudioDevice(sDevice);
        sDevice = 0;
    }
    if (sUnderruns)
        PcLog("[pc] audio: %u buffer underruns\n", sUnderruns);
}
