#ifndef GUARD_CONTINUE_TYPES_H
#define GUARD_CONTINUE_TYPES_H

#include "types.h"
#include "anim.h"

struct ObjPalette;

enum ContinueState {
    CONTINUE_STATE_FADE_IN,
    CONTINUE_STATE_SELECT,
    CONTINUE_STATE_FADE_OUT,
    CONTINUE_STATE_DONE
};

enum ContinueOption {
    CONTINUE_OPTION_CONTINUE,
    CONTINUE_OPTION_RETURN_TO_TITLE
};

typedef struct ContinueWork {
    void* tiles;
    struct ObjPalette* palette;
    void* tiles2;
    struct ObjPalette* palette2;
    void* tiles3;
    struct ObjPalette* palette3;
    void* gfx;
    void* gfx2;
    AnimState anim;
    AnimState anim2;
    s32 x;
    s32 y;
    s32 x2;
    s32 y2;
    s32 cursor;
    u8 unk_64;
    u16 blendAlpha;
    u8 unk_68[2];
    u8 state;
    s8 steps;
} ContinueWork;

#endif
