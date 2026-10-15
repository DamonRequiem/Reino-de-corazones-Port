/**
 * mode_pooh.c
 * 100 Acre Wood Mode
 */

#include "mode_pooh.h"
#include "sprites_pooh.h"
#include "world_types.h"
#include "prize_types.h"
#include "mode_pooh_api.h"
#include "fade.h"
#include "songs.h"
#include <string.h>
#include "anim.h"
#include "battle_actor_types.h"
#include "btl_collision.h"
#include "card_api.h"
#include "display.h"
#include "engine_math.h"
#include "game_state.h"
#include "m4a_song.h"
#include "map_runtime.h"
#include "mode.h"
#include "msg_api.h"
#include "obj_api.h"
#include "poo_api.h"
#include "pooh_actor_types.h"
#include "registration_data.h"
#include <stddef.h>
#include "taskpool.h"
#include "types.h"
#include "sprite_palettes.h"
#include "card_message_data.h"
#include "event_ids.h"

Mode gModePooh = {
    "mode_pooh",
    mode_pooh_0,
    mode_pooh_1,
    mode_pooh_2,
};

const PooHitBox gPoohHitBox = { gPoohPalette, 36, 16, 6 };

static const s8 sPoohLookOffsets[8][8] = {
    { 0, 1, 2, 2, 3, -2, -2, -1 },
    { -1, 0, 1, 2, 2, 3, -2, -2 },
    { -2, -1, 0, 1, 2, 2, 3, -2 },
    { -2, -2, -1, 0, 1, 2, 2, 3 },
    { 3, -2, -2, -1, 0, 1, 2, 2 },
    { -2, 3, 2, 2, 1, 0, -1, -2 },
    { -2, -2, 3, 2, 2, 1, 0, -1 },
    { -1, -2, -2, 3, 2, 2, 1, 0 },
};

static AnimDef sPooh00AnimDefs[5] = {
    { gPoohBb00Frames, gPoohBb00Anims, gPoohBb00Tiles, 0 },
    { gPoohFf00Frames, gPoohFf00Anims, gPoohFf00Tiles, 0 },
    { gPoohFr00Frames, gPoohFr00Anims, gPoohFr00Tiles, 0 },
    { gPoohRr00Frames, gPoohRr00Anims, gPoohRr00Tiles, 0 },
    { gPoohBr00Frames, gPoohBr00Anims, gPoohBr00Tiles, 0 },
};

static AnimDef sPooh04AnimDefs[5] = {
    { gPoohBb04Frames, gPoohBb04Anims, gPoohBb04Tiles, 0 },
    { gPoohFf04Frames, gPoohFf04Anims, gPoohFf04Tiles, 0 },
    { gPoohFl04Frames, gPoohFl04Anims, gPoohFl04Tiles, 0 },
    { gPoohLl04Frames, gPoohLl04Anims, gPoohLl04Tiles, 0 },
    { gPoohBl04Frames, gPoohBl04Anims, gPoohBl04Tiles, 0 },
};

static AnimDef sPooh04aAnimDefs[5] = {
    { gPoohBb04aFrames, gPoohBb04aAnims, gPoohBb04aTiles, 0 },
    { gPoohFf04aFrames, gPoohFf04aAnims, gPoohFf04aTiles, 0 },
    { gPoohFl04aFrames, gPoohFl04aAnims, gPoohFl04aTiles, 0 },
    { gPoohLl04aFrames, gPoohLl04aAnims, gPoohLl04aTiles, 0 },
    { gPoohBl04aFrames, gPoohBl04aAnims, gPoohBl04aTiles, 0 },
};

static AnimDef sPooh01AnimDefs[8] = {
    { gPoohBb01Frames, gPoohBb01Anims, gPoohBb01Tiles, 0 },
    { gPoohFf01Frames, gPoohFf01Anims, gPoohFf01Tiles, 0 },
    { gPoohFr01Frames, gPoohFr01Anims, gPoohFr01Tiles, 0 },
    { gPoohRr01Frames, gPoohRr01Anims, gPoohRr01Tiles, 0 },
    { gPoohBr01Frames, gPoohBr01Anims, gPoohBr01Tiles, 0 },
    { gPoohFl01Frames, gPoohFl01Anims, gPoohFl01Tiles, 0 },
    { gPoohLl01Frames, gPoohLl01Anims, gPoohLl01Tiles, 0 },
    { gPoohBl01Frames, gPoohBl01Anims, gPoohBl01Tiles, 0 },
};

static AnimDef sTrap0001AnimDefs[8] = {
    { gTrap0001bbFrames, gTrap0001bbAnims, gTrap0001bbTiles, 0 },
    { gTrap0001ffFrames, gTrap0001ffAnims, gTrap0001ffTiles, 0 },
    { gTrap0001frFrames, gTrap0001frAnims, gTrap0001frTiles, 0 },
    { gTrap0001rrFrames, gTrap0001rrAnims, gTrap0001rrTiles, 0 },
    { gTrap0001brFrames, gTrap0001brAnims, gTrap0001brTiles, 0 },
    { gTrap0001flFrames, gTrap0001flAnims, gTrap0001flTiles, 0 },
    { gTrap0001llFrames, gTrap0001llAnims, gTrap0001llTiles, 0 },
    { gTrap0001blFrames, gTrap0001blAnims, gTrap0001blTiles, 0 },
};

static AnimDef sTrap0002Anim0Def = { gTrap0002Frames, gTrap0002Anims, gTrap0002Tiles, 0 };

static AnimDef sTrap0002Anim1Def = { gTrap0002Frames, gTrap0002Anims, gTrap0002Tiles, 1 };

static AnimDef sTrap0003Anim0Def = { gTrap0003Frames, gTrap0003Anims, gTrap0003Tiles, 0 };

static AnimDef sPoohOwlDescentAnimDef = { gPoohOwlDescentFrames, gPoohOwlDescentAnims, gPoohOwlDescentTiles, 1 };

static AnimDef sPooh03AnimDefs[2] = {
    { gPoohBl03Frames, gPoohBl03Anims, gPoohBl03Tiles, 0 },
    { gPoohFl03Frames, gPoohFl03Anims, gPoohFl03Tiles, 0 },
};

static AnimDef sPooh07Anim0Defs[2] = {
    { gPoohBl07Frames, gPoohBl07Anims, gPoohBl07Tiles, 0 },
    { gPoohFl07Frames, gPoohFl07Anims, gPoohFl07Tiles, 0 },
};

static AnimDef sPooh07Anim1Defs[2] = {
    { gPoohBl07Frames, gPoohBl07Anims, gPoohBl07Tiles, 1 },
    { gPoohFl07Frames, gPoohFl07Anims, gPoohFl07Tiles, 1 },
};

static AnimDef sPoohFl05Anim0Def = { gPoohFl05Frames, gPoohFl05Anims, gPoohFl05Tiles, 0 };

static AnimDef sPoohFl05Anim1Def = { gPoohFl05Frames, gPoohFl05Anims, gPoohFl05Tiles, 1 };

static AnimDef sPoohFl05Anim2Def = { gPoohFl05Frames, gPoohFl05Anims, gPoohFl05Tiles, 2 };

static AnimDef sPoohFl05Anim3Def = { gPoohFl05Frames, gPoohFl05Anims, gPoohFl05Tiles, 3 };

static AnimDef sPoohFl05Anim4Def = { gPoohFl05Frames, gPoohFl05Anims, gPoohFl05Tiles, 4 };

static AnimDef sPoohFl05Anim5Def = { gPoohFl05Frames, gPoohFl05Anims, gPoohFl05Tiles, 5 };

static AnimDef sPoohFl05Anim9Def = { gPoohFl05Frames, gPoohFl05Anims, gPoohFl05Tiles, 9 };

static AnimDef sPoohFl06Anim1Def = { gPoohFl06Frames, gPoohFl06Anims, gPoohFl06Tiles, 1 };

static AnimDef sPoohFl06Anim2Def = { gPoohFl06Frames, gPoohFl06Anims, gPoohFl06Tiles, 2 };

static AnimDef sPoohFl06Anim3Def = { gPoohFl06Frames, gPoohFl06Anims, gPoohFl06Tiles, 3 };

static AnimDef sPoohFl09Anim0Def = { gPoohFl09Frames, gPoohFl09Anims, gPoohFl09Tiles, 0 };

static AnimDef sPoohFl09Anim1Def = { gPoohFl09Frames, gPoohFl09Anims, gPoohFl09Tiles, 1 };

static AnimDef sPoohFl09Anim2Def = { gPoohFl09Frames, gPoohFl09Anims, gPoohFl09Tiles, 2 };

static AnimDef sPooh10AnimDefs[4] = {
    { gPoohLl10Frames, gPoohLl10Anims, gPoohLl10Tiles, 0 },
    { gPoohFf10Frames, gPoohFf10Anims, gPoohFf10Tiles, 0 },
    { gPoohLl10Frames, gPoohLl10Anims, gPoohLl10Tiles, 0 },
    { gPoohLl10Frames, gPoohLl10Anims, gPoohLl10Tiles, 0 },
};

AnimDef gPoohLl10Anim0Def = { gPoohLl10Frames, gPoohLl10Anims, gPoohLl10Tiles, 0 };

static AnimDef sPooh00LookAnimDefs[5][5] = {
    {
        { gPoohBb00LlFrames, gPoohBb00LlAnims, gPoohBb00LlTiles, 0 },
        { gPoohBb00BlFrames, gPoohBb00BlAnims, gPoohBb00BlTiles, 0 },
        { gPoohBb00Frames, gPoohBb00Anims, gPoohBb00Tiles, 0 },
        { gPoohBb00BrFrames, gPoohBb00BrAnims, gPoohBb00BrTiles, 0 },
        { gPoohBb00RrFrames, gPoohBb00RrAnims, gPoohBb00RrTiles, 0 },
    },
    {
        { gPoohFf00RrFrames, gPoohFf00RrAnims, gPoohFf00RrTiles, 0 },
        { gPoohFf00FrFrames, gPoohFf00FrAnims, gPoohFf00FrTiles, 0 },
        { gPoohFf00Frames, gPoohFf00Anims, gPoohFf00Tiles, 0 },
        { gPoohFf00FlFrames, gPoohFf00FlAnims, gPoohFf00FlTiles, 0 },
        { gPoohFf00LlFrames, gPoohFf00LlAnims, gPoohFf00LlTiles, 0 },
    },
    {
        { gPoohFr00BrFrames, gPoohFr00BrAnims, gPoohFr00BrTiles, 0 },
        { gPoohFr00RrFrames, gPoohFr00RrAnims, gPoohFr00RrTiles, 0 },
        { gPoohFr00Frames, gPoohFr00Anims, gPoohFr00Tiles, 0 },
        { gPoohFr00FfFrames, gPoohFr00FfAnims, gPoohFr00FfTiles, 0 },
        { gPoohFr00FlFrames, gPoohFr00FlAnims, gPoohFr00FlTiles, 0 },
    },
    {
        { gPoohRr00BbFrames, gPoohRr00BbAnims, gPoohRr00BbTiles, 0 },
        { gPoohRr00BrFrames, gPoohRr00BrAnims, gPoohRr00BrTiles, 0 },
        { gPoohRr00Frames, gPoohRr00Anims, gPoohRr00Tiles, 0 },
        { gPoohRr00FrFrames, gPoohRr00FrAnims, gPoohRr00FrTiles, 0 },
        { gPoohRr00FfFrames, gPoohRr00FfAnims, gPoohRr00FfTiles, 0 },
    },
    {
        { gPoohBr00BlFrames, gPoohBr00BlAnims, gPoohBr00BlTiles, 0 },
        { gPoohBr00BbFrames, gPoohBr00BbAnims, gPoohBr00BbTiles, 0 },
        { gPoohBr00Frames, gPoohBr00Anims, gPoohBr00Tiles, 0 },
        { gPoohBr00RrFrames, gPoohBr00RrAnims, gPoohBr00RrTiles, 0 },
        { gPoohBr00FrFrames, gPoohBr00FrAnims, gPoohBr00FrTiles, 0 },
    },
};

static u16 sBackdropFadeColor;
static u32 sBackdropFadeAmount;
static u32 sBackdropFadeTarget;
static u32 sBackdropFadeLastAmount;
static u16 sBackdropFadeTimer;
static u32 sBackdropFadeMode;
static u8 sBackdropFadeActive;
static TaskPool sModePoohTasks;
static TaskPool sModePoohMessageTasks;
static u8 sModePoohExiting;
static u32 sModePoohExitEvent;
static u16 sModePoohMessage;
static Task* sPooPrizeTasks[12];
static TaskPool sModePoohWLogoTasks;
static Task* sWLogoTask;
static u8 sPooMapBeeVisible;
static s32 sPooAttackX;
static s32 sPooAttackY;
static s32 sPooAttackZ;

void BackdropFadeReset() {
    sBackdropFadeAmount = 0;
    sBackdropFadeTarget = 0;
    sBackdropFadeLastAmount = 0;
    sBackdropFadeTimer = 0;
    sBackdropFadeMode = FADE_MODE_BLACK;
    sBackdropFadeActive = FALSE;
}

void BackdropFadeSetColor(u16 r, u16 g, u16 b) {
    SetBackdropColor(r, g, b);
    sBackdropFadeColor = (b << 10) | (g << 5) | r;
}

void BackdropFadeUpdate() {
    u16 amt;
    u16 r;
    u16 g;
    u16 b;

    if (sBackdropFadeAmount != sBackdropFadeLastAmount) {
        amt = sBackdropFadeAmount >> 8;
        r = sBackdropFadeColor & 31;
        g = (sBackdropFadeColor >> 5) & 31;
        b = (sBackdropFadeColor >> 10) & 31;

        switch (sBackdropFadeMode) {
        case FADE_MODE_BLACK:
            r -= amt;
            g -= amt;
            b -= amt;

            if ((s16)r < 0) {
                r = 0;
            }

            if ((s16)g < 0) {
                g = 0;
            }

            if ((s16)b < 0) {
                b = 0;
            }

            break;
        case FADE_MODE_WHITE:
            if ((s16)r < amt) {
                r = amt;
            }

            if ((s16)g < amt) {
                g = amt;
            }

            if ((s16)b < amt) {
                b = amt;
            }

            break;
        case FADE_MODE_RED:
            r = amt + r;
            g -= amt;
            b -= amt;

            if ((s16)r > 31) {
                r = 31;
            }

            if ((s16)g < 0) {
                g = 0;
            }

            if ((s16)b < 0) {
                b = 0;
            }

            break;
        case FADE_MODE_GREEN:
            r -= amt;
            g = amt + g;
            b -= amt;

            if ((s16)r < 0) {
                r = 0;
            }

            if ((s16)g > 31) {
                g = 31;
            }

            if ((s16)b < 0) {
                b = 0;
            }

            break;
        case FADE_MODE_BLUE:
            r -= amt;
            g -= amt;
            b = amt + b;

            if ((s16)r < 0) {
                r = 0;
            }

            if ((s16)g < 0) {
                g = 0;
            }

            if ((s16)b > 31) {
                b = 31;
            }

            break;
        default:
            r = amt + r;
            g = amt + g;
            b = amt + b;

            if ((s16)r > 31) {
                r = 31;
            }

            if ((s16)g > 31) {
                g = 31;
            }

            if ((s16)b > 31) {
                b = 31;
            }

            break;
        }

        SetBackdropColor(r, g, b);
    }

    if (sBackdropFadeTimer != 0) {
        sBackdropFadeLastAmount = sBackdropFadeAmount;
        ApproachValue(&sBackdropFadeAmount, sBackdropFadeTarget, sBackdropFadeTimer);
        sBackdropFadeTimer--;
    } else {
        sBackdropFadeActive = FALSE;
    }
}

void BackdropFadeStartIn(u32 mode, u16 frames) {
    sBackdropFadeActive = TRUE;
    sBackdropFadeTimer = frames;
    sBackdropFadeAmount = 0x1F00;
    sBackdropFadeTarget = 0;
    sBackdropFadeLastAmount = 0;
    sBackdropFadeMode = mode;
}

void BackdropFadeStartOut(u32 mode, u16 frames) {
    sBackdropFadeActive = TRUE;
    sBackdropFadeTimer = frames;
    sBackdropFadeAmount = 0;
    sBackdropFadeTarget = 0x1F00;
    sBackdropFadeLastAmount = 0;
    sBackdropFadeMode = mode;
}

void BackdropFadeToOriginal(u32 mode, u16 frames) {
    sBackdropFadeActive = TRUE;
    sBackdropFadeTimer = frames;
    sBackdropFadeTarget = 0;
    sBackdropFadeMode = mode;
}

void BackdropFadeToAmount(u32 mode, u16 amount, u16 frames) {
    sBackdropFadeActive = TRUE;
    sBackdropFadeTimer = frames;
    sBackdropFadeTarget = amount << 8;
    sBackdropFadeMode = mode;
}

u8 BackdropFadeIsActive() {
    return sBackdropFadeActive;
}

void BackdropFadeFromAmount(u32 mode, u16 amount, u16 frames) {
    sBackdropFadeActive = TRUE;
    sBackdropFadeTimer = frames;
    sBackdropFadeAmount = amount << 8;
    sBackdropFadeLastAmount = 0;
    sBackdropFadeTarget = 0;
    sBackdropFadeMode = mode;
}

void SetPooAttackPoint(s32 x, s32 y, s32 z) {
    gPooAttackActive = TRUE;
    sPooAttackX = x;
    sPooAttackY = y * 2;
    sPooAttackZ = z;
}

u8 PooAttackHitsCollider(Collider* collider) {
    s32 lim;
    s32 dx;
    s32 dy;
    s32 dz;

    lim = collider->radius + 0x1400;
    dx = sPooAttackX - collider->x;

    if (dx < 0) {
        dx = collider->x - sPooAttackX;
    }

    dy = sPooAttackY - collider->y;

    if (dy < 0) {
        dy = collider->y - sPooAttackY;
    }

    dz = sPooAttackZ - collider->z;

    if (dx < lim && dy < lim && dz <= 0x1FFF && -dz < collider->height) {
        return TRUE;
    }

    return FALSE;
}

void SetPooStartPositions() {
    PooPos pos;

    pos.x = 0x13000;
    pos.y = 0xE800;
    pos.z = 0;
    SetPooStatePos2(&pos);
    pos.x = 0x11000;
    pos.y = 0xF800;
    pos.z = 0;
    SetPooStatePooh(&pos, POOH_ACTION_IDLE);
}

void SetPooReentryPositions() {
    PooPos pos;

    pos.x = 0xB5400;
    pos.y = 0x5DE00;
    pos.z = 0;
    SetPooStatePos2(&pos);

    if (IsPooFlagSet(3)) {
        pos.x = 0xB3400;
        pos.y = 0x5EE00;
        pos.z = 0;
        SetPooStatePooh(&pos, POOH_ACTION_IDLE);
    }
}

void mode_pooh_0(s32 arg) {
    s32 i;

    gGameState.world = WORLD_100_ACRE_WOOD;

    if (arg == 0) {
        ClearPooPrizesDropped();
        SetPooStartPositions();
    } else if (arg == 2) {
        ClearPooPrizesDropped();
        SetPooReentryPositions();
    }

    m4aSongNumStart(SONG_BGM_POOHGAME);
    m4aSongNumStart(SONG_BG_POO);
    SetBgMode0();
    SetupBg(3, 0, 28, 0);
    SetupBg(1, 0, 29, 0);
    SetupBg(2, 2, 30, 0);
    SetupBg(0, 3, 31, 14);
    SetBgPriority(0, 0);
    SetBgPriority(1, 1);
    SetBgPriority(2, 2);
    SetBgPriority(3, 3);
    ColliderPoolsInit();
    InitPooNodes();
    InitPoohInteractions();

    TaskPoolInit(&sModePoohTasks, 32);

    for (i = 0; i < 12; i++) {
        sPooPrizeTasks[i] = NULL;
    }

    TaskCreate(&sModePoohTasks, &gTaskDescPooSora, NULL);
    TaskCreate(&sModePoohTasks, &gTaskDescPooPiglet, NULL);

    if (!IsPooEventDone(POO_EVENT_EEYORE)) {
        TaskCreate(&sModePoohTasks, &gTaskDescPooEeyoretail, NULL);
        TaskCreate(&sModePoohTasks, &gTaskDescPooBee, NULL);
    } else {
        TaskCreate(&sModePoohTasks, &gTaskDescPooBeeAfterEvent, NULL);
    }

    TaskCreate(&sModePoohTasks, &gTaskDescPooEeyore, NULL);
    TaskCreate(&sModePoohTasks, &gTaskDescPooHoneycomb, NULL);
    TaskCreate(&sModePoohTasks, &gTaskDescPooOwl, NULL);
    TaskCreate(&sModePoohTasks, &gTaskDescPooWagon, NULL);
    TaskCreate(&sModePoohTasks, &gTaskDescPooWagonwheel, NULL);

    if (!IsPooEventDone(POO_EVENT_RABBIT)) {
        TaskCreate(&sModePoohTasks, &gTaskDescPooRabbit, NULL);
        TaskCreate(&sModePoohTasks, &gTaskDescPooCabbageborn, NULL);
    } else {
        TaskCreate(&sModePoohTasks, &gTaskDescPooRabbitAfterEvent, NULL);
        TaskCreate(&sModePoohTasks, &gTaskDescPooCabbageAfterEvent, NULL);
    }

    TaskCreate(&sModePoohTasks, &gTaskDescPooVegetable, NULL);
    TaskCreate(&sModePoohTasks, &gTaskDescPooTigger, NULL);
    TaskCreate(&sModePoohTasks, &gTaskDescPooRooFootmark, NULL);

    if (IsPooEventDone(POO_EVENT_ROO)) {
        if (!IsPooEventDone(POO_EVENT_TIGGER)) {
            TaskCreate(&sModePoohTasks, &gTaskDescPooRoo, NULL);
        } else {
            TaskCreate(&sModePoohTasks, &gTaskDescPooTiggerroo, NULL);
        }
    }

    TaskCreate(&sModePoohTasks, &gTaskDescPooMap, NULL);
    TaskCreate(&sModePoohTasks, &gTaskDescPooPooh, NULL);
    TaskCreate(&sModePoohTasks, &gTaskDescPooGauge, NULL);

    TaskPoolInit(&sModePoohWLogoTasks, 1);

    if (IsPooFlagSet(2)) {
        sWLogoTask = NULL;
    } else {
        sWLogoTask = TaskCreate(&sModePoohWLogoTasks, &gTaskDescWLogo, NULL);
        SetPooFlag(2);
    }

    TaskPoolInit(&sModePoohMessageTasks, 1);
    BackdropFadeReset();
    BackdropFadeSetColor(6, 31, 31);
    FadeStartIn(FADE_MODE_BLACK, 16);
    BackdropFadeStartIn(0, 16);
    sModePoohExiting = FALSE;
    sModePoohMessage = CARD_MSG_COUNT;
}

void mode_pooh_1() {
    UpdatePlayTime();
    SetPooMapBeeVisible(FALSE);

    if (sModePoohExiting && !FadeIsActive()) {
        if (sModePoohExitEvent == EVENT_COUNT) {
            EnterEntranceHall();
        } else {
            RequestEventMode(sModePoohExitEvent);
        }

        return;
    }

    if (!FadeIsActive()) {
        gPooAttackActive = FALSE;

        if (IsTaskActive(sWLogoTask)) {
            TaskPoolUpdate(&sModePoohWLogoTasks);
        } else if (!IsMessageWindowOpen()) {
            if (sModePoohMessage == 0xFFFE) {
                if (IsMessageWindowAnswerYes()) {
                    ExitPoohMode(EVENT_COUNT);
                } else {
                    sModePoohMessage = CARD_MSG_COUNT;
                }
            } else if (sModePoohMessage == 0xFFFD) {
                if (IsMessageWindowAnswerYes()) {
                    ExitPoohMode(EVENT_148_100ACREWOOD_END_SORAONLY);
                } else {
                    sModePoohMessage = CARD_MSG_COUNT;
                }
            } else {
                TaskPoolUpdate(&sModePoohTasks);
            }
        } else {
            TaskPoolUpdate(&sModePoohMessageTasks);
        }
    }

    TaskPoolDraw(&sModePoohWLogoTasks);
    TaskPoolDraw(&sModePoohMessageTasks);
    TaskPoolDraw(&sModePoohTasks);
    ColliderUpdateAll();
    BackdropFadeUpdate();
}

void mode_pooh_2() {
    TaskPoolDestroy(&sModePoohTasks);
    TaskPoolDestroy(&sModePoohMessageTasks);
    TaskPoolDestroy(&sModePoohWLogoTasks);
    FreePoohInteractions();
    m4aSongNumStop(SONG_BG_POO);
}

void ExitPoohMode(u32 event) {
    s32 i;

    if (!sModePoohExiting) {
        sModePoohExitEvent = event;

        for (i = 0; i <= 31; i++) {
            FadeSetPaletteExcluded(i, FALSE);
        }

        FadeStartOut(FADE_MODE_BLACK, 16);
        BackdropFadeStartOut(0, 16);
        sModePoohExiting = TRUE;
    }
}

void OpenPoohModeMessage(u16 message) {
    sModePoohMessage = message;

    if (message == 0xFFFD || message == 0xFFFE) {
        message = CARD_MSG_POOH_LEAVE_WORLD;
    }

    CreateCardMessageTask(&sModePoohMessageTasks, 0, message);
}

u16 SpawnPooPrizes(u8 kind, u8 count, s32 x, s32 y, s32 z) {
    PoohPrizeArgs args;
    u16 made;
    s32 i;
    s32 j;

    args.x = x;
    args.y = y;
    args.z = z;
    args.kind = kind;
    made = 0;
    j = 0;

    for (i = 0; i < count; i++) {
        for (; j < 12; j++) {
            if (!IsTaskActive(sPooPrizeTasks[j])) {
                sPooPrizeTasks[j] = TaskCreate(&sModePoohTasks, &gTaskDescPooPrize, &args);
                made++;
                break;
            }
        }
    }

    return made;
}

u16 CountPooPrizes() {
    u16 n;
    s32 i;

    n = 0;

    for (i = 0; i < 12; i++) {
        if (IsTaskActive(sPooPrizeTasks[i])) {
            n++;
        }
    }

    return n;
}

void SetPooMapBeeVisible(u8 visible) {
    sPooMapBeeVisible = visible;
}

u8 IsPooMapBeeVisible() {
    return sPooMapBeeVisible;
}

void SetPoohDir5Right(PoohWork* work) {
    switch (ANGLE_DIR8(work->angle)) {
    case DIR8_UP_RIGHT:
        work->dirIndex = 4;
        work->flipped = 0;
        break;
    case DIR8_RIGHT:
        work->dirIndex = 3;
        work->flipped = 0;
        break;
    case DIR8_DOWN_RIGHT:
        work->dirIndex = 2;
        work->flipped = 0;
        break;
    case DIR8_DOWN:
        work->dirIndex = 1;
        work->flipped = 0;
        break;
    case DIR8_DOWN_LEFT:
        work->dirIndex = 2;
        work->flipped = 1;
        break;
    case DIR8_LEFT:
        work->dirIndex = 3;
        work->flipped = 1;
        break;
    case DIR8_UP_LEFT:
        work->dirIndex = 4;
        work->flipped = 1;
        break;
    case DIR8_UP:
    default:
        work->dirIndex = 0;
        work->flipped = 0;
        break;
    }
}

void SetPoohDir5Left(PoohWork* work) {
    switch (ANGLE_DIR8(work->angle)) {
    case DIR8_UP_RIGHT:
        work->dirIndex = 4;
        work->flipped = 1;
        break;
    case DIR8_RIGHT:
        work->dirIndex = 3;
        work->flipped = 1;
        break;
    case DIR8_DOWN_RIGHT:
        work->dirIndex = 2;
        work->flipped = 1;
        break;
    case DIR8_DOWN:
        work->dirIndex = 1;
        work->flipped = 0;
        break;
    case DIR8_DOWN_LEFT:
        work->dirIndex = 2;
        work->flipped = 0;
        break;
    case DIR8_LEFT:
        work->dirIndex = 3;
        work->flipped = 0;
        break;
    case DIR8_UP_LEFT:
        work->dirIndex = 4;
        work->flipped = 0;
        break;
    case DIR8_UP:
    default:
        work->dirIndex = 0;
        work->flipped = 0;
        break;
    }
}

void SetPoohDir8(PoohWork* work) {
    work->flipped = 0;

    switch (ANGLE_DIR8(work->angle)) {
    case DIR8_UP:
        work->dirIndex = 0;
        break;
    case DIR8_UP_RIGHT:
        work->dirIndex = 4;
        break;
    case DIR8_RIGHT:
        work->dirIndex = 3;
        break;
    case DIR8_DOWN_RIGHT:
        work->dirIndex = 2;
        break;
    case DIR8_DOWN:
        work->dirIndex = 1;
        break;
    case DIR8_DOWN_LEFT:
        work->dirIndex = 5;
        break;
    case DIR8_LEFT:
        work->dirIndex = 6;
        break;
    case DIR8_UP_LEFT:
        work->dirIndex = 7;
        break;
    default:
        work->dirIndex = 0;
        break;
    }
}

void SetPoohDir2(PoohWork* work) {
    switch (ANGLE_DIR8(work->angle)) {
    case DIR8_UP:
    case DIR8_UP_RIGHT:
        work->dirIndex = 0;
        work->flipped = 1;
        break;
    case DIR8_RIGHT:
        work->dirIndex = 1;
        work->flipped = 1;
        break;
    case DIR8_DOWN_RIGHT:
        work->dirIndex = 1;
        work->flipped = 1;
        break;
    case DIR8_DOWN:
    case DIR8_DOWN_LEFT:
    case DIR8_LEFT:
        work->dirIndex = 1;
        work->flipped = 0;
        break;
    case DIR8_UP_LEFT:
    default:
        work->dirIndex = 0;
        work->flipped = 0;
        break;
    }
}

void SetPoohDir3(PoohWork* work) {
    if (work->angle <= 99) {
        work->dirIndex = 3;
        work->flipped = 1;
    } else if (work->angle <= 156) {
        work->dirIndex = 1;
        work->flipped = 0;
    } else {
        work->dirIndex = 3;
        work->flipped = 0;
    }
}

u8 IsAngleFacingRight(u8 angle) {
    switch (ANGLE_DIR8(angle)) {
    case DIR8_UP_RIGHT:
    case DIR8_RIGHT:
    case DIR8_DOWN_RIGHT:
        return 1;
    case DIR8_UP:
    case DIR8_DOWN:
    case DIR8_DOWN_LEFT:
    case DIR8_LEFT:
    case DIR8_UP_LEFT:
        return 0;
    }

    return 0;
}

u8 GetPoohLookColumn(PoohWork* work) {
    u8 offsets[8][8];
    u32 row;
    u32 col;

    memcpy(offsets, sPoohLookOffsets, sizeof(offsets));
    row = (u32)((work->angle + 16) & 0xFF) >> 5;
    col = (u32)((work->lookAngle + 16) & 0xFF) >> 5;

    if ((s8)offsets[row][col] == 3) {
        return work->lookColumn;
    }

    return offsets[row][col] + 2;
}

void SetPoohAnimation(PoohWork* work, u32 action) {
    AnimDef* def;
    u16 flags;

    flags = 0;
    ColliderSetRadius(&work->collider, gPoohHitBox.radius);

    if (work->animAction == action) {
        flags = ANIM_FLAG_KEEP_FRAME;
    }

    work->animAction = action;

    switch (action) {
    case POOH_ACTION_WALK:
    case POOH_ACTION_WALK_AWAY:
    case POOH_ACTION_STUMP_WALK:
        flags |= ANIM_FLAG_LOOP;
        SetPoohDir8(work);
        def = &sPooh01AnimDefs[work->dirIndex];
        break;
    case POOH_ACTION_FLEE_BEES_1:
    case POOH_ACTION_FLEE_BEES_2:
        flags |= ANIM_FLAG_LOOP;
        SetPoohDir3(work);
        def = &sPooh10AnimDefs[work->dirIndex];
        break;
    case POOH_ACTION_TRAP_FALL:
        SetPoohDir8(work);
        def = &sTrap0001AnimDefs[work->dirIndex];
        break;
    case POOH_ACTION_TRIP:
        SetPoohDir5Left(work);
        def = &sPooh04AnimDefs[work->dirIndex];
        break;
    case POOH_ACTION_GET_UP:
        SetPoohDir5Left(work);
        def = &sPooh04aAnimDefs[work->dirIndex];
        break;
    case POOH_ACTION_STUMP_JUMP:
        SetPoohDir2(work);
        def = &sPooh03AnimDefs[work->dirIndex];
        break;
    case POOH_ACTION_STUMP_CLIMB:
        work->hideShadow = TRUE;
        SetPoohDir2(work);
        def = &sPooh07Anim0Defs[work->dirIndex];
        break;
    case POOH_ACTION_WAGON_CLIMB:
        work->hideShadow = TRUE;
        SetPoohDir2(work);

        if (IsPooEventDone(POO_EVENT_WAGON) || work->leavingWagon || (work->dirIndex == 5 && work->flipped == 0)) {
            def = &sPooh07Anim0Defs[work->dirIndex];
        } else {
            def = &sPooh07Anim1Defs[work->dirIndex];
        }

        break;
    case POOH_ACTION_TRAPPED:
        work->flipped = 0;
        def = &sTrap0002Anim0Def;
        break;
    case POOH_ACTION_TRAPPED_WITH_ROO:
        work->flipped = 0;
        def = &sTrap0002Anim1Def;
        break;
    case POOH_ACTION_SIT_DOWN:
        work->flipped = IsAngleFacingRight(work->angle);
        def = &sPoohFl05Anim0Def;
        work->hideShadow = TRUE;
        break;
    case POOH_ACTION_SIT_FOR_HONEY:
        work->flipped = 0;
        def = &sPoohFl05Anim9Def;
        work->hideShadow = TRUE;
        break;
    case POOH_ACTION_EAT_HONEY_1:
        work->flipped = 0;
        def = &sPoohFl09Anim0Def;
        break;
    case POOH_ACTION_EAT_HONEY_2:
        work->flipped = 0;
        def = &sPoohFl09Anim1Def;
        break;
    case POOH_ACTION_EAT_HONEY_3:
        work->flipped = 0;
        def = &sPoohFl09Anim2Def;
        break;
    case POOH_ACTION_SIT:
        work->flipped = IsAngleFacingRight(work->angle);
        def = &sPoohFl05Anim1Def;
        work->hideShadow = TRUE;
        break;
    case POOH_ACTION_LIE_DOWN:
        work->flipped = IsAngleFacingRight(work->angle);
        def = &sPoohFl05Anim2Def;
        work->hideShadow = TRUE;
        break;
    case POOH_ACTION_SLEEP:
        ColliderSetRadius(&work->collider, 14);
        flags |= ANIM_FLAG_LOOP;
        work->flipped = IsAngleFacingRight(work->angle);
        def = &sPoohFl05Anim3Def;
        work->hideShadow = TRUE;
        break;
    case POOH_ACTION_WAKE_UP:
        work->flipped = IsAngleFacingRight(work->angle);
        def = &sPoohFl05Anim4Def;
        work->hideShadow = TRUE;
        break;
    case POOH_ACTION_STAND_UP:
        work->flipped = IsAngleFacingRight(work->angle);
        def = &sPoohFl05Anim5Def;
        work->hideShadow = TRUE;
        break;
    case POOH_ACTION_THINK_START:
        work->flipped = IsAngleFacingRight(work->angle);
        def = &sPoohFl06Anim1Def;
        break;
    case POOH_ACTION_THINK:
        flags |= ANIM_FLAG_LOOP;
        work->flipped = IsAngleFacingRight(work->angle);
        def = &sPoohFl06Anim2Def;
        break;
    case POOH_ACTION_THINK_END:
        work->flipped = IsAngleFacingRight(work->angle);
        def = &sPoohFl06Anim3Def;
        break;
    case POOH_ACTION_BALLOON:
    case POOH_ACTION_OWL_BALLOON:
        flags |= ANIM_FLAG_LOOP;
        work->flipped = 0;
        def = &sTrap0003Anim0Def;
        break;
    case POOH_ACTION_OWL_DESCENT:
        flags |= ANIM_FLAG_LOOP;
        work->flipped = 0;
        def = &sPoohOwlDescentAnimDef;
        break;
    case POOH_ACTION_IDLE:
    case POOH_ACTION_FALL:
    case POOH_ACTION_WAGON_DROP:
    case POOH_ACTION_STUMP_WAIT:
    case POOH_ACTION_LOOK:
    case POOH_ACTION_BLOCKED:
    case POOH_ACTION_LOOK_AT_HONEYCOMB_DONE:
    case POOH_ACTION_LOOK_AT_HONEYCOMB:
    case POOH_ACTION_WAGON_WAIT:
    case POOH_ACTION_BEE_CHASE_OVER:
    case POOH_ACTION_JUMP_SCARED:
        flags |= ANIM_FLAG_LOOP;
        SetPoohDir5Right(work);
        work->lookColumn = GetPoohLookColumn(work);
        def = &sPooh00LookAnimDefs[work->dirIndex][GetPoohLookColumn(work)];
        break;
    default:
        flags |= ANIM_FLAG_LOOP;
        SetPoohDir5Right(work);
        def = &sPooh00AnimDefs[work->dirIndex];
        break;
    }

    AnimChangeWithTables(&work->anim, def->animId, flags, def->anims, def->gfxTable);
    SetObjTileSource(work->tiles, def->tiles);
}

u8 IsWithinPoohRadius(u16 x, u16 y, u16 px, u16 py) {
    if (x - gPoohHitBox.radius < px && px < x + gPoohHitBox.radius &&
        y - gPoohHitBox.radius < py && py < y + gPoohHitBox.radius) {
        return TRUE;
    }

    return FALSE;
}
