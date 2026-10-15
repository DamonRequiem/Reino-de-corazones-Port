#ifndef GUARD_TITLE_H
#define GUARD_TITLE_H

#include "obj.h"
#include "types.h"
#include "taskpool.h"
#include "title_types.h"
#include "anim.h"

typedef struct TitleObjSprite {
    void* tiles;
    void* palette;
    void* gfx;
    s16 y;
    s32 x;
    s32 targetX;
} TitleObjSprite;

typedef struct TitleObjWork {
    TitleObjSprite sprites[3];
    AnimState anim;
    u16 slideTimer;
    u16 slideDelay;
} TitleObjWork;

typedef struct TitleMenuWork {
    void* tiles;
    ObjPalette* palette;
    void* tiles2[3];
    ObjPalette* palette2[3];
    void* gfx[3];
    AnimState anim;
    s16* choice;
    TaskPool tasks;
    s32 layout;
    s16 x;
} TitleMenuWork;

typedef struct TitleLumiChangeWork {
    void* tiles;
    void* palette;
    void* gfx;
} TitleLumiChangeWork;

void TitleLogoLoadSprites(TitleLogoWork* work);

void task_title_logo_0(TitleLogoWork* work);
u8 task_title_logo_1(TitleLogoWork* work);
void task_title_logo_2(TitleLogoWork* work);
void task_title_logo_3(TitleLogoWork* work);
void PackLowBytes(u8* src, u16* dst, u16 size);
u8 IsTitleLogoScaleDone();
void task_title_obj_0(TitleObjWork* work);
u8 task_title_obj_1(TitleObjWork* work);
void task_title_obj_2(TitleObjWork* work);
void task_title_obj_3(TitleObjWork* work);
void task_title_menu_0(TitleMenuWork* work, s16* choice);
s16 TitleMenuChoiceRow(s16 choice);
void TitleMenuMoveBasic(s16* choice);
void TitleMenuMoveOrdered(s16* choice, s16 count);
u8 task_title_menu_1(TitleMenuWork* work);
void TitleMenuDrawBasic(TitleMenuWork* work);
void TitleMenuDrawFull(TitleMenuWork* work);
void TitleMenuDrawNewGame(TitleMenuWork* work);
void TitleMenuDrawSingle(TitleMenuWork* work);
void task_title_menu_2(TitleMenuWork* work);
void task_title_menu_3(TitleMenuWork* work);
void task_title_lumichange_0(TitleLumiChangeWork* work);
u8 task_title_lumichange_1(TitleLumiChangeWork* work);
void task_title_lumichange_2(TitleLumiChangeWork* work);
void task_title_lumichange_3(TitleLumiChangeWork* work);

#endif /* GUARD_TITLE_H */
