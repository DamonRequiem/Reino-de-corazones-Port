#ifndef GUARD_MODE_LANG_H
#define GUARD_MODE_LANG_H

#include "types.h"

#ifdef VERSION_EU
struct ObjPalette;
struct ObjTiles;

enum LangFlag {
    LANG_FLAG_HIDE_CURSOR = 0x1
};

typedef struct LangWork {
    s16 cursor;
    s16 timer;
    u32 state;
    u16 flags;
    u32 language;
    struct ObjTiles* tiles;
    struct ObjPalette* palette;
} LangWork;

void mode_lang_0(s32 arg);
void mode_lang_1();
void mode_lang_2();
#endif

#endif /* GUARD_MODE_LANG_H */
