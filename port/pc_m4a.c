/*
 * pc_m4a.c
 * C translation of asm/m4a_1.s, the core of the game's sound engine ("m4a",
 * Nintendo's MusicPlayer2000): the sequencer that reads the song data
 * (MPlayMain and the ply_* commands), note allocation (ply_note) and the
 * software mixer that renders up to 12 sample channels into the PCM buffer
 * the GBA streams to its DACs (SoundMain / SoundMainRAM).
 *
 * Compiled with the game's flags and headers (it uses the game's structs).
 * Every function follows the ARM/Thumb original step by step, including its
 * integer widths, so the mixed PCM is bit-identical to the console's. Where
 * the assembly relies on a register trick, the comment says what it computes.
 *
 * The parts of the engine that were already C (m4a2.c: CgbSound, volume and
 * pitch helpers, the m4a* API) are unchanged.
 */
#include <stdint.h>
#include <string.h>
#include "gba/io_reg.h"
#include "m4a.h"
#include "macros.h"
#include "types.h"

#define TONEDATA_TYPE_CGB 0x07
#define TONEDATA_TYPE_SPL 0x40
#define TONEDATA_TYPE_RHY 0x80

#define VCOUNT_VBLANK 160
#define TOTAL_SCANLINES 228

#define SF_ON SOUND_CHANNEL_SF_ON /* 0xC7 */

/* The ARM code needs SoundMainRAM's machine code in RAM; m4aSoundInit still
 * copies 0x400 bytes from here into SoundMainRAM_Buffer, which is unused. */
char SoundMainRAM[0x400];

/* chk_adr_r2: the engine refuses to read song data from below EWRAM (the BIOS
 * area) and reads 0 instead. On PC that area is the first 64 KiB. */
static inline int AddressOk(const void* p) {
    return (uintptr_t)p >= 0x10000;
}

static inline u8 ReadChecked(const u8* p) {
    return AddressOk(p) ? *p : 0;
}

static inline u32 ReadWordChecked(const void* p) {
    u32 v;
    if (!AddressOk(p))
        return 0;
    memcpy(&v, p, 4);
    return v;
}

/* ld_r3_tp_adr_i: next byte of the track's command stream. */
static inline u8 ReadCmdByte(MusicPlayerTrack* track) {
    u8* p = track->cmdPtr;
    track->cmdPtr = p + 1;
    return ReadChecked(p);
}

/* ld_r3_tp_adr_i_unchecked */
static inline u8 ReadCmdByteUnchecked(MusicPlayerTrack* track) {
    u8* p = track->cmdPtr;
    track->cmdPtr = p + 1;
    return *p;
}

/* Walks a channel list; the engine breaks self-loops while doing so. */
static inline void* NextChannel(void* chan) {
    SoundChannel* c = chan;
    void* next = c->nextChannelPointer;
    if (next == chan) {
        c->nextChannelPointer = NULL;
        next = NULL;
    }
    return next;
}

u32 umul3232H32(u32 multiplier, u32 multiplicand) {
    return (u32)(((uint64_t)multiplier * multiplicand) >> 32);
}

void SoundMainBTM(void* work) {
    memset(work, 0, 64);
}

void RealClearChain(void* work) {
    SoundChannel* chan = work;
    MusicPlayerTrack* track = chan->track;
    SoundChannel* next;
    SoundChannel* prev;

    if (track == NULL)
        return;
    next = chan->nextChannelPointer;
    prev = chan->prevChannelPointer;
    if (prev != NULL)
        prev->nextChannelPointer = next;
    else
        track->chan = next;
    if (next != NULL)
        next->prevChannelPointer = prev;
    chan->track = NULL;
}

void MPlayJumpTableCopy(MPlayFunc* mplayJumpTable) {
    int i;
    for (i = 0; i < 36; i++)
        mplayJumpTable[i] = AddressOk(&gMPlayJumpTableTemplate[i]) ? gMPlayJumpTableTemplate[i] : NULL;
}

/* Replacement for the BIOS's MusicPlayerJumpTableCopy (swi 0x2A). */
void PcMusicPlayerJumpTableCopy(MPlayFunc* table) {
    MPlayJumpTableCopy(table);
}

/* ------------------------------------------------------------------ */
/* Sequence commands                                                    */
/* ------------------------------------------------------------------ */

void ply_fine(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    SoundChannel* chan = track->chan;

    while (chan != NULL) {
        u8 sf = chan->statusFlags;
        if (sf & SF_ON)
            chan->statusFlags = sf | SOUND_CHANNEL_SF_STOP;
        RealClearChain(chan);
        chan = NextChannel(chan);
    }
    track->flags = 0;
}

/* Reads the 32-bit target address at cmdPtr (only its first byte's address
 * is checked, as in the original). */
static void GotoFromCmdPtr(MusicPlayerTrack* track) {
    u8* p = track->cmdPtr;
    u32 addr = ((u32)p[3] << 24) | ((u32)p[2] << 16) | ((u32)p[1] << 8) | ReadChecked(p);
    track->cmdPtr = (u8*)(uintptr_t)addr;
}

void ply_goto(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    GotoFromCmdPtr(track);
}

void ply_patt(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    u8 level = track->patternLevel;
    if (level < 3) {
        track->patternStack[level] = track->cmdPtr + 4;
        track->patternLevel = level + 1;
        ply_goto(mplayInfo, track);
    } else {
        ply_fine(mplayInfo, track);
    }
}

void ply_pend(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    u8 level = track->patternLevel;
    if (level != 0) {
        level--;
        track->patternLevel = level;
        track->cmdPtr = track->patternStack[level];
    }
}

void ply_rept(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    u8* p = track->cmdPtr;
    u32 rep;
    u8 count;

    if (*p == 0) {
        track->cmdPtr = p + 1;
        GotoFromCmdPtr(track);
        return;
    }
    rep = track->repN + 1u; /* compared before truncation, as in r12 */
    track->repN = (u8)rep;
    count = ReadCmdByte(track); /* cmdPtr = p + 1 */
    if (rep < count) {
        GotoFromCmdPtr(track);
    } else {
        track->repN = 0;
        track->cmdPtr = p + 5;
    }
}

void ply_prio(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    track->priority = ReadCmdByte(track);
}

void ply_tempo(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    u32 t = (u32)ReadCmdByte(track) << 1;
    mplayInfo->tempoD = (u16)t;
    mplayInfo->tempoI = (u16)((t * mplayInfo->tempoU) >> 8);
}

void ply_keysh(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    track->keyShift = (s8)ReadCmdByte(track);
    track->flags |= MPT_FLG_PITCHG;
}

void ply_voice(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    u8 index = *track->cmdPtr; /* not checked in the original */
    const u8* src;
    u32 w;

    track->cmdPtr++;
    src = (const u8*)mplayInfo->tone + index * 12;
    w = ReadWordChecked(src);
    memcpy((u8*)&track->tone + 0, &w, 4);
    w = ReadWordChecked(src + 4);
    memcpy((u8*)&track->tone + 4, &w, 4);
    w = ReadWordChecked(src + 8);
    memcpy((u8*)&track->tone + 8, &w, 4);
}

void ply_vol(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    track->vol = ReadCmdByte(track);
    track->flags |= MPT_FLG_VOLCHG;
}

void ply_pan(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    track->pan = (s8)(ReadCmdByte(track) - 0x40);
    track->flags |= MPT_FLG_VOLCHG;
}

void ply_bend(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    track->bend = (s8)(ReadCmdByte(track) - 0x40);
    track->flags |= MPT_FLG_PITCHG;
}

void ply_bendr(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    track->bendRange = ReadCmdByte(track);
    track->flags |= MPT_FLG_PITCHG;
}

void ply_lfodl(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    track->lfoDelay = ReadCmdByte(track);
}

void ply_modt(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    u8 v = ReadCmdByte(track);
    if (track->modT != v) {
        track->modT = v;
        track->flags |= MPT_FLG_VOLCHG | MPT_FLG_PITCHG;
    }
}

void ply_tune(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    track->tune = (s8)(ReadCmdByte(track) - 0x40);
    track->flags |= MPT_FLG_PITCHG;
}

/* Writes a byte straight into a sound register (SOUND1CNT_L + offset). */
void ply_port(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    u8* p = track->cmdPtr;
    u8 offset = *p;
    u8 value;
    vu8* reg = (vu8*)(REG_ADDR_SOUND1CNT_L + offset);

    track->cmdPtr = p + 2;
    value = ReadChecked(p + 1);
    *reg = value;
    PcIoWritten((volatile void*)reg, 1);
}

static void ClearModMInternal(MusicPlayerTrack* track) {
    track->modM = 0;
    track->lfoSpeedC = 0;
    track->flags |= (track->modT == 0) ? MPT_FLG_PITCHG : MPT_FLG_VOLCHG;
}

void ply_lfos(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    u8 v = ReadCmdByteUnchecked(track);
    track->lfoSpeed = v;
    if (v == 0)
        ClearModMInternal(track);
}

void ply_mod(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    u8 v = ReadCmdByteUnchecked(track);
    track->mod = v;
    if (v == 0)
        ClearModMInternal(track);
}

void ply_endtie(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    u8* p = track->cmdPtr;
    u8 key;
    SoundChannel* chan;

    if (*p < 0x80) {
        key = *p;
        track->key = key;
        track->cmdPtr = p + 1;
    } else {
        key = track->key;
    }

    for (chan = track->chan; chan != NULL; chan = NextChannel(chan)) {
        u8 sf = chan->statusFlags;
        if ((sf & (SOUND_CHANNEL_SF_START | SOUND_CHANNEL_SF_ENV)) && !(sf & SOUND_CHANNEL_SF_STOP) &&
            chan->midiKey == key) {
            chan->statusFlags = sf | SOUND_CHANNEL_SF_STOP;
            return;
        }
    }
}

void TrackStop(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    SoundChannel* chan;

    if (!(track->flags & MPT_FLG_EXIST))
        return;
    for (chan = track->chan; chan != NULL; chan = NextChannel(chan)) {
        if (chan->statusFlags != 0) {
            u8 cgb = chan->type & TONEDATA_TYPE_CGB;
            if (cgb)
                gSoundInfoPtr->CgbOscOff(cgb);
            chan->statusFlags = 0;
        }
        chan->track = NULL;
    }
    track->chan = NULL;
}

/* ChnVolSetAsm (r4 = channel, r5 = track) */
static void ChnVolSet(SoundChannel* chan, MusicPlayerTrack* track) {
    s32 velocity = chan->velocity;
    s32 rhythmPan = (s8)chan->rhythmPan;
    u32 v;

    v = (u32)((s32)((0x80 + rhythmPan) * velocity) * (s32)track->volMR) >> 14;
    chan->rightVolume = v > 0xFF ? 0xFF : (u8)v;
    v = (u32)((s32)((0x7F - rhythmPan) * velocity) * (s32)track->volML) >> 14;
    chan->leftVolume = v > 0xFF ? 0xFF : (u8)v;
}

void ply_note(u32 noteCmd, MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    SoundInfo* soundInfo = gSoundInfoPtr;
    u8* p;
    s32 rhythmPan = 0;
    u8 type;
    u32 key;
    const ToneData* tone;
    u32 priority;
    u32 cgbType;
    SoundChannel* chan;
    s32 k;

    track->gateTime = gClockTable[noteCmd];
    p = track->cmdPtr;
    if (*p < 0x80) {
        track->key = *p;
        p++;
        if (*p < 0x80) {
            track->velocity = *p;
            p++;
            if (*p < 0x80) {
                track->gateTime += *p;
                p++;
            }
        }
        track->cmdPtr = p;
    }

    type = track->tone.type;
    if (type & (TONEDATA_TYPE_RHY | TONEDATA_TYPE_SPL)) {
        u32 index = track->key;
        key = track->key;
        if (type & TONEDATA_TYPE_SPL) {
            /* For key-split instruments the attack..release word holds the
             * key split table. */
            const u8* split;
            memcpy(&split, &track->tone.attack, sizeof(split));
            index = split[key];
        }
        tone = (const ToneData*)((const u8*)track->tone.wav + index * 12);
        if (tone->type & (TONEDATA_TYPE_RHY | TONEDATA_TYPE_SPL))
            return;
        if (type & TONEDATA_TYPE_RHY) {
            if (tone->pan_sweep & 0x80)
                rhythmPan = ((s32)tone->pan_sweep - 0xC0) * 2;
            key = tone->key;
        }
    } else {
        tone = &track->tone;
        key = track->key;
    }

    priority = mplayInfo->priority + track->priority;
    if (priority > 0xFF)
        priority = 0xFF;

    cgbType = tone->type & TONEDATA_TYPE_CGB;
    if (cgbType) {
        CgbChannel* cgb = soundInfo->cgbChans;
        u8 sf;
        if (cgb == NULL)
            return;
        chan = (SoundChannel*)&cgb[cgbType - 1];
        sf = chan->statusFlags;
        if ((sf & SF_ON) && !(sf & SOUND_CHANNEL_SF_STOP)) {
            if (chan->priority > priority)
                return;
            if (chan->priority == priority && (uintptr_t)chan->track < (uintptr_t)track)
                return;
        }
    } else {
        /* Pick a free channel, else a releasing one, else the one with the
         * lowest priority (latest track on ties). */
        u32 bestPriority = priority;
        uintptr_t bestTrack = (uintptr_t)track;
        int foundStopping = 0;
        SoundChannel* best = NULL;
        SoundChannel* c = soundInfo->chans;
        s32 n = soundInfo->maxChans;

        chan = NULL;
        do {
            u8 sf = c->statusFlags;
            if (!(sf & SF_ON)) {
                chan = c;
                break;
            }
            if (sf & SOUND_CHANNEL_SF_STOP) {
                if (!foundStopping) {
                    foundStopping = 1;
                    bestPriority = c->priority;
                    bestTrack = (uintptr_t)c->track;
                    best = c;
                    goto next;
                }
            } else if (foundStopping) {
                goto next;
            }
            if (c->priority < bestPriority) {
                bestPriority = c->priority;
                bestTrack = (uintptr_t)c->track;
                best = c;
            } else if (c->priority == bestPriority) {
                if ((uintptr_t)c->track > bestTrack) {
                    bestTrack = (uintptr_t)c->track;
                    best = c;
                } else if ((uintptr_t)c->track == bestTrack) {
                    best = c;
                }
            }
        next:
            c++;
        } while (--n > 0);
        if (chan == NULL) {
            chan = best;
            if (chan == NULL)
                return;
        }
    }

    ClearChain(chan);
    chan->prevChannelPointer = NULL;
    chan->nextChannelPointer = track->chan;
    if (track->chan != NULL)
        track->chan->prevChannelPointer = chan;
    track->chan = chan;
    chan->track = track;

    track->lfoDelayC = track->lfoDelay;
    if (track->lfoDelay != 0)
        ClearModMInternal(track);
    TrkVolPitSet(mplayInfo, track);

    chan->gateTime = track->gateTime;
    chan->midiKey = track->key;
    chan->velocity = track->velocity;
    chan->priority = (u8)priority;
    chan->key = (u8)key;
    chan->rhythmPan = (u8)rhythmPan;
    chan->type = tone->type;
    chan->wav = tone->wav;
    chan->attack = tone->attack;
    chan->decay = tone->decay;
    chan->sustain = tone->sustain;
    chan->release = tone->release;
    chan->pseudoEchoVolume = track->pseudoEchoVolume;
    chan->pseudoEchoLength = track->pseudoEchoLength;
    ChnVolSet(chan, track);

    k = (s32)chan->key + (s8)track->keyM;
    if (k < 0)
        k = 0;

    if (cgbType) {
        CgbChannel* cgb = (CgbChannel*)chan;
        u8 ps = tone->pan_sweep;
        cgb->length = tone->length;
        if ((ps & 0x80) || !(ps & 0x70))
            cgb->sweep = 8;
        else
            cgb->sweep = ps;
        cgb->frequency = soundInfo->MidiKeyToCgbFreq(cgbType, (u8)k, track->pitM);
    } else {
        chan->frequency = MidiKeyToFreq(chan->wav, (u8)k, track->pitM);
    }
    chan->statusFlags = SOUND_CHANNEL_SF_START;
    track->flags &= 0xF0;
}

/* ------------------------------------------------------------------ */
/* Sequencer                                                            */
/* ------------------------------------------------------------------ */

void MPlayMain(MusicPlayerInfo* mplayInfo) {
    SoundInfo* soundInfo;
    u32 tempo;

    if (mplayInfo->ident != ID_NUMBER)
        return;
    mplayInfo->ident++;

    if (mplayInfo->MPlayMainNext != NULL)
        mplayInfo->MPlayMainNext(mplayInfo->musicPlayerNext);

    if ((s32)mplayInfo->status < 0)
        goto end;
    soundInfo = gSoundInfoPtr;
    FadeOutBody(mplayInfo);
    if ((s32)mplayInfo->status < 0)
        goto end;

    tempo = (u32)mplayInfo->tempoC + mplayInfo->tempoI;
    for (;;) {
        s32 n;
        MusicPlayerTrack* track;
        u32 bit;
        u32 active;

        mplayInfo->tempoC = (u16)tempo;
        if (tempo < 150)
            break;

        /* One sequencer tick. */
        n = mplayInfo->trackCount;
        track = mplayInfo->tracks;
        bit = 1;
        active = 0;
        do {
            if (track->flags & MPT_FLG_EXIST) {
                SoundChannel* chan;

                active |= bit;
                for (chan = track->chan; chan != NULL; chan = NextChannel(chan)) {
                    u8 sf = chan->statusFlags;
                    if (sf & SF_ON) {
                        if (chan->gateTime != 0) {
                            chan->gateTime--;
                            if (chan->gateTime == 0)
                                chan->statusFlags = sf | SOUND_CHANNEL_SF_STOP;
                        }
                    } else {
                        ClearChain(chan);
                    }
                }

                if (track->flags & MPT_FLG_START) {
                    Clear64byte(track);
                    track->flags = MPT_FLG_EXIST;
                    track->bendRange = 2;
                    track->volX = 0x40;
                    track->lfoSpeed = 0x16;
                    track->tone.type = 1;
                }

                while (track->wait == 0) {
                    u8* p = track->cmdPtr;
                    u32 cmd = *p;
                    if (cmd < 0x80) {
                        cmd = track->runningStatus;
                    } else {
                        track->cmdPtr = p + 1;
                        if (cmd >= 0xBD)
                            track->runningStatus = (u8)cmd;
                    }
                    if (cmd >= 0xCF) {
                        soundInfo->plynote(cmd - 0xCF, mplayInfo, track);
                    } else if (cmd > 0xB0) {
                        mplayInfo->cmd = (u8)(cmd - 0xB1);
                        ((void (*)(MusicPlayerInfo*, MusicPlayerTrack*))soundInfo->MPlayJumpTable[cmd - 0xB1])(
                            mplayInfo, track);
                        if (track->flags == 0)
                            goto track_done;
                    } else {
                        track->wait = gClockTable[(s32)cmd - 0x80];
                    }
                }

                track->wait--;
                if (track->lfoSpeed != 0 && track->mod != 0) {
                    if (track->lfoDelayC != 0) {
                        track->lfoDelayC--;
                    } else {
                        u32 sum = (u32)track->lfoSpeedC + track->lfoSpeed; /* not truncated */
                        s32 wave;
                        s32 m;
                        track->lfoSpeedC = (u8)sum;
                        if ((u8)(sum - 0x40) & 0x80)
                            wave = (s8)sum;
                        else
                            wave = 0x80 - (s32)sum;
                        m = (s32)(track->mod * wave) >> 6;
                        if ((u8)(track->modM ^ m) != 0) {
                            track->modM = (s8)m;
                            track->flags |= (track->modT == 0) ? MPT_FLG_PITCHG : MPT_FLG_VOLCHG;
                        }
                    }
                }
            }
        track_done:
            bit <<= 1;
            track++;
        } while (--n > 0);

        mplayInfo->clock++;
        if (active == 0) {
            mplayInfo->status = MUSICPLAYER_STATUS_PAUSE;
            goto end;
        }
        mplayInfo->status = active;
        tempo = (u32)mplayInfo->tempoC - 150;
    }

    /* Apply volume and pitch changes to the playing channels. */
    {
        s32 n = mplayInfo->trackCount;
        MusicPlayerTrack* track = mplayInfo->tracks;

        do {
            u8 fl = track->flags;
            if ((fl & MPT_FLG_EXIST) && (fl & 0x0F)) {
                SoundChannel* chan;

                TrkVolPitSet(mplayInfo, track);
                for (chan = track->chan; chan != NULL; chan = NextChannel(chan)) {
                    u32 cgbType;
                    if (!(chan->statusFlags & SF_ON)) {
                        ClearChain(chan);
                        continue;
                    }
                    cgbType = chan->type & TONEDATA_TYPE_CGB;
                    if (track->flags & MPT_FLG_VOLCHG) {
                        ChnVolSet(chan, track);
                        if (cgbType)
                            ((CgbChannel*)chan)->modify |= CGB_CHANNEL_MO_VOL;
                    }
                    if (track->flags & MPT_FLG_PITCHG) {
                        s32 k = (s32)chan->key + (s8)track->keyM;
                        if (k < 0)
                            k = 0;
                        if (cgbType) {
                            CgbChannel* cgb = (CgbChannel*)chan;
                            cgb->frequency = soundInfo->MidiKeyToCgbFreq(cgbType, (u8)k, track->pitM);
                            cgb->modify |= CGB_CHANNEL_MO_PIT;
                        } else {
                            chan->frequency = MidiKeyToFreq(chan->wav, (u8)k, track->pitM);
                        }
                    }
                }
                track->flags &= 0xF0;
            }
            track++;
        } while (--n > 0);
    }

end:
    mplayInfo->ident = ID_NUMBER;
}

/* ------------------------------------------------------------------ */
/* Mixer                                                                */
/* ------------------------------------------------------------------ */

/* The ARM mixer adds each channel byte-wise into the PCM buffer (bytes
 * wrap, they do not saturate): out += (volume * sample) >> 8. */
static inline void MixSample(s8* out, s32 vol, s32 sample) {
    *out = (s8)(*out + ((vol * sample) >> 8));
}

static void MixChannel(SoundInfo* soundInfo, SoundChannel* chan, s8* outR, s32 samples) {
    WaveData* wav = chan->wav;
    s8* outL = outR + PCM_DMA_BUF_SIZE;
    s32 envR = chan->envelopeVolumeRight;
    s32 envL = chan->envelopeVolumeLeft;
    s8* loopStart = NULL;
    s32 loopLen = 0;
    s32 count = (s32)chan->count;
    s8* src = chan->currentPointer;
    s32 i;

    if (chan->statusFlags & 0x10) { /* looping sample */
        loopStart = wav->data + wav->loopStart;
        loopLen = (s32)(wav->size - wav->loopStart);
    }

    if (chan->type & TONEDATA_TYPE_FIX) {
        /* Played at the mixing rate, one source sample per output sample. */
        for (i = 0; i < samples; i++) {
            s32 s = *src++;
            MixSample(&outR[i], envR, s);
            MixSample(&outL[i], envL, s);
            if (--count == 0) {
                if (loopLen != 0) {
                    count = loopLen;
                    src = loopStart;
                } else {
                    chan->statusFlags = 0;
                    return;
                }
            }
        }
        chan->count = (u32)count;
        chan->currentPointer = src;
        return;
    }

    /* Resampled with linear interpolation; fw is the 23-bit fraction. */
    {
        u32 fw = chan->fw;
        u32 step = (u32)soundInfo->divFreq * chan->frequency;
        s32 cur = src[0];
        s32 delta = src[1];
        src++;
        delta -= cur;

        for (i = 0; i < samples; i++) {
            s32 v = cur + ((s32)(fw * (u32)delta) >> 23);
            u32 adv;

            MixSample(&outR[i], envR, v);
            MixSample(&outL[i], envL, v);

            fw += step;
            adv = fw >> 23;
            if (adv == 0)
                continue;
            fw &= ~0x3F800000u;
            count -= (s32)adv;
            if (count <= 0) {
                s32 skip;
                if (loopLen == 0) {
                    chan->statusFlags = 0;
                    return;
                }
                src = loopStart;
                skip = -count;
                for (;;) {
                    count += loopLen;
                    if (count > 0)
                        break;
                    skip -= loopLen;
                }
                src += skip;
                cur = *src;
            } else if (--adv == 0) {
                cur = cur + delta;
            } else {
                src += adv;
                cur = *src;
            }
            src++;
            delta = *src - cur;
        }
        chan->fw = fw;
        chan->count = (u32)count;
        chan->currentPointer = src - 1;
    }
}

/* SoundMainRAM: reverb/clear of this frame's PCM slice, then the envelope
 * and mixing of every DirectSound channel. */
static void SoundMainRAM_C(SoundInfo* soundInfo, s8* out, s32 samples, u32 dmaCounter, s32 lineLimit) {
    u32 reverb = soundInfo->reverb;
    SoundChannel* chan;
    s32 n;
    s32 i;

    if (reverb != 0) {
        s8* next = (dmaCounter == 2) ? soundInfo->pcmBuffer : out + samples;
        s8* p = out;
        for (i = samples; i > 0; i--) {
            s32 sum = p[PCM_DMA_BUF_SIZE] + p[0] + next[PCM_DMA_BUF_SIZE] + next[0];
            s32 v = (sum * (s32)reverb) >> 9;
            next++;
            if (v & 0x80)
                v++;
            p[PCM_DMA_BUF_SIZE] = (s8)v;
            p[0] = (s8)v;
            p++;
        }
    } else {
        memset(out, 0, samples);
        memset(out + PCM_DMA_BUF_SIZE, 0, samples);
    }

    chan = soundInfo->chans;
    n = soundInfo->maxChans;
    do {
        u8 sf;
        u32 env;
        WaveData* wav = chan->wav;

        if (lineLimit != 0) {
            u32 vc = (u8)REG_VCOUNT;
            if (vc < VCOUNT_VBLANK)
                vc += TOTAL_SCANLINES;
            if (vc >= (u32)lineLimit)
                break;
        }

        sf = chan->statusFlags;
        if (!(sf & SF_ON))
            goto next_channel;

        if (sf & SOUND_CHANNEL_SF_START) {
            if (sf & SOUND_CHANNEL_SF_STOP) {
                chan->statusFlags = 0;
                goto next_channel;
            }
            sf = SOUND_CHANNEL_SF_ENV_ATTACK;
            chan->statusFlags = sf;
            chan->currentPointer = wav->data;
            chan->count = wav->size;
            env = 0;
            chan->envelopeVolume = 0;
            chan->fw = 0;
            if ((wav->status >> 8) & 0xC0) {
                sf |= 0x10;
                chan->statusFlags = sf;
            }
            goto attack;
        }

        env = chan->envelopeVolume;
        if (sf & SOUND_CHANNEL_SF_IEC) {
            u8 len = chan->pseudoEchoLength;
            chan->pseudoEchoLength = len - 1;
            if (len < 2) {
                chan->statusFlags = 0;
                goto next_channel;
            }
        } else if (sf & SOUND_CHANNEL_SF_STOP) {
            env = (env * chan->release) >> 8;
            if (env <= chan->pseudoEchoVolume) {
            echo_start:
                env = chan->pseudoEchoVolume;
                if (env == 0) {
                    chan->statusFlags = 0;
                    goto next_channel;
                }
                sf |= SOUND_CHANNEL_SF_IEC;
                chan->statusFlags = sf;
            }
        } else {
            u32 phase = sf & SOUND_CHANNEL_SF_ENV;
            if (phase == SOUND_CHANNEL_SF_ENV_DECAY) {
                env = (env * chan->decay) >> 8;
                if (env <= chan->sustain) {
                    env = chan->sustain;
                    if (env == 0)
                        goto echo_start;
                    sf--;
                    chan->statusFlags = sf;
                }
            } else if (phase == SOUND_CHANNEL_SF_ENV_ATTACK) {
            attack:
                env += chan->attack;
                if (env >= 0xFF) {
                    env = 0xFF;
                    sf--;
                    chan->statusFlags = sf;
                }
            }
        }

        chan->envelopeVolume = (u8)env;
        env = ((u32)soundInfo->masterVolume + 1) * env >> 4;
        chan->envelopeVolumeRight = (u8)((chan->rightVolume * env) >> 8);
        chan->envelopeVolumeLeft = (u8)((chan->leftVolume * env) >> 8);

        MixChannel(soundInfo, chan, out, samples);

    next_channel:
        chan++;
    } while (--n > 0);

    soundInfo->ident = ID_NUMBER;
}

void SoundMain(void) {
    SoundInfo* soundInfo = gSoundInfoPtr;
    s32 lineLimit;
    s32 samples;
    s8* out;
    u32 dmaCounter;

    if (soundInfo->ident != ID_NUMBER)
        return;
    soundInfo->ident++;

    lineLimit = soundInfo->maxLines;
    if (lineLimit != 0) {
        u32 vc = (u8)REG_VCOUNT;
        if (vc < VCOUNT_VBLANK)
            vc += TOTAL_SCANLINES;
        lineLimit += (s32)vc;
    }

    if (soundInfo->MPlayMainHead != NULL)
        soundInfo->MPlayMainHead(soundInfo->musicPlayerHead);
    soundInfo->CgbSound();

    samples = soundInfo->pcmSamplesPerVBlank;
    out = soundInfo->pcmBuffer;
    dmaCounter = soundInfo->pcmDmaCounter;
    if (dmaCounter > 1)
        out += (s32)(soundInfo->pcmDmaPeriod - (dmaCounter - 1)) * samples;

    SoundMainRAM_C(soundInfo, out, samples, dmaCounter, lineLimit);
}
