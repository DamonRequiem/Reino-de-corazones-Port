#ifndef GUARD_SND_STREAM_H
#define GUARD_SND_STREAM_H

#include "types.h"

typedef struct {
    void* buffers[2];
    u32 writePos[2];
    u32 totalWritten[2];
    u32 lockPos[2];
    u32 lockTotal[2];
    u32 dmaOffset;
    u32 playedTotal;
    u32 samplesPerFrame;
    u32 bufferSize;
    u32 sampleRate;
    u32 timerReload;
    u32 channels;
    u32 playing;
    void* (*iwramAlloc)(u32);
    void* (*alloc)(u32);
    void (*iwramFree)(const void*);
    void (*free)(const void*);
} SoundStream;

extern SoundStream gSndStream;

void SndStreamStop();

void SndStreamInit(u32 rate, u32 channels);
void SndStreamUpdate();
void SndStreamLock(u32 ch, u32 len, void** dst1, u32* len1, void** dst2, u32* len2);
void SndStreamSetCallbacks(void* (*a)(u32), void* (*b)(u32), void (*c)(const void*), void (*d)(const void*));
void SndStreamClose();
void SndStreamStart();
void SndStreamUnlock(u32 ch);

#endif /* GUARD_SND_STREAM_H */
