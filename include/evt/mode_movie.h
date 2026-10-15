#ifndef GUARD_MODE_MOVIE_H
#define GUARD_MODE_MOVIE_H

#include "types.h"
#include "text_types.h"

typedef struct MovieSub {
    s16 frame;
    s16 x;
    const TextChar* text;
    u8 line;
    u16 duration;
    u16 palette;
} MovieSub;

enum MovieFlag {
    MOVIE_FLAG_UPPER_SUB_PENDING = 0x1,
    MOVIE_FLAG_LOWER_SUB_PENDING = 0x2,
    MOVIE_FLAG_SOFT_RESET = 0x4,
    MOVIE_FLAG_PLAYING = 0x8
};

enum MovieId {
    MOVIE_OPENING = 1,
    MOVIE_6F_GOAL,
    MOVIE_12F_E2,
    MOVIE_ENDING,
    MOVIE_RIKU_ENDING
};

#ifndef VERSION_JP
s16 GetCenteredTextX(u16* widths, u16 count);
#endif
u16 CountNonSpaceChars(const TextChar* str);
void MovieVBlankIntr();
s32 HandleMovieFrame(s32 arg);

#endif
