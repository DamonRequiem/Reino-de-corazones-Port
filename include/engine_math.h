#ifndef GUARD_ENGINE_MATH_H
#define GUARD_ENGINE_MATH_H

#include "types.h"

extern const s16 gSineTable[320];

#define SIN(angle) gSineTable[(angle) & 0xFF]
#define COS(angle) gSineTable[((angle) & 0xFF) + 64]

#define Q_8_8(n) ((s16)((n) * 256))

enum Dir8 {
    DIR8_UP,
    DIR8_UP_RIGHT,
    DIR8_RIGHT,
    DIR8_DOWN_RIGHT,
    DIR8_DOWN,
    DIR8_DOWN_LEFT,
    DIR8_LEFT,
    DIR8_UP_LEFT
};

#define ANGLE_DIR8(angle) ((((angle) + 16) & 0xFF) >> 5)

u8 GetAngle(s32 x0, s32 y0, s32 x1, s32 y1);
s16 GetAngleDiff(s32 target, s32 angle);
s32 GetAngleDiff16(s32 target, s32 angle);
void ApproachAngle(u16* value, u16 target, u16 shift);
void ApproachAngle16(u16* value, u16 target, u16 shift);
void ApproachValue(s32* value, s32 target, u16 steps);
s32 GetHalfStepDivisor(u16 steps);
void ApproachValueHalfSteps(s32* value, s32 target, u16 steps);
void ApproachValueHalf(s32* value, s32 target);
void SeedRand(u32 seed);
u32 Rand();
void SeedRandom(u32 seed);
u16 GetRandom();

s32 Sqrt8(s32 value);

#endif
