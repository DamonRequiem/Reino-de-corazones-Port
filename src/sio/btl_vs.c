/**
 * btl_vs.c
 * Link Battle Logic
 */

#include "display.h"
#include "m4a_song.h"
#include "battle.h"
#include "gba/keys.h"
#include "fade.h"
#include "battle_actor.h"
#include "battle_actor_types.h"
#include "battle_work.h"
#include "card_api.h"
#include "card_battle.h"
#include "gba/macro.h"
#include "mode.h"
#include "registration_data.h"
#include <stddef.h>
#include "task_descriptors.h"
#include "taskpool.h"
#include "types.h"
#include "key_state.h"
#include "card_battle_riku.h"
#include "card_label_data.h"
#include "engine_math.h"
#include "card.h"
#include "mode_riku_tutorial.h"

static u16 sVsKeyHoldL[2];
static u16 sVsKeyHoldR[2];
static u16 sVsKeyReleaseL[2];
static u16 sVsKeyReleaseR[2];
static u16 sVsKeyChordLatch[2];
static u16 sVsSoraReloadTimer;
static u16 sVsRikuReloadTimer;

void UpdateVsKeyHoldTimes(u16 keys, s32 side) {
    if (keys & L_BUTTON) {
        sVsKeyHoldL[side]++;
        sVsKeyReleaseL[side] = 0;

        if (sVsKeyHoldL[side] > 32) {
            sVsKeyHoldL[side] = 29;
        }
    } else {
        sVsKeyHoldL[side] = 0;

        if (sVsKeyReleaseL[side] < 255) {
            sVsKeyReleaseL[side]++;
        }
    }

    if (keys & R_BUTTON) {
        sVsKeyHoldR[side]++;
        sVsKeyReleaseR[side] = 0;

        if (sVsKeyHoldR[side] > 32) {
            sVsKeyHoldR[side] = 29;
        }
    } else {
        sVsKeyHoldR[side] = 0;

        if (sVsKeyReleaseR[side] < 255) {
            sVsKeyReleaseR[side]++;
        }
    }
}

s32 ReadVsKeyChord(u16 held, u16 pressed, s32 side) {
    s32 chord = 0;

    UpdateVsKeyHoldTimes(held, side);

    if (sVsKeyReleaseL[side] == 2) {
        sVsKeyChordLatch[side] &= ~L_BUTTON;
    }

    if (sVsKeyReleaseR[side] == 2) {
        sVsKeyChordLatch[side] &= ~R_BUTTON;
    }

    if (((pressed & L_BUTTON) && (held & R_BUTTON)) || ((pressed & R_BUTTON) && (held & L_BUTTON))) {
        sVsKeyChordLatch[side] |= (L_BUTTON | R_BUTTON);
        chord = L_BUTTON | R_BUTTON;
    }

    if (!(sVsKeyChordLatch[side] & L_BUTTON)) {
        if (sVsKeyHoldL[side] == 5 || sVsKeyReleaseL[side] == 1) {
            sVsKeyChordLatch[side] |= L_BUTTON;
            chord = L_BUTTON;
        }
    }

    if (!(sVsKeyChordLatch[side] & R_BUTTON)) {
        if (sVsKeyHoldR[side] == 5 || sVsKeyReleaseR[side] == 1) {
            sVsKeyChordLatch[side] |= R_BUTTON;
            chord = R_BUTTON;
        }
    }

    return chord;
}

void VsBtlWorkInit() {
    CpuFill32(0, gBtlWork, sizeof(BtlWork));
    CpuFill32(0, gRikuBtlWork, sizeof(BtlWork));
    gBtlWork->phase = BTL_PHASE_START;
    gBtlWork->fadeExcludedPalettes = -0x10000;
    gBtlWork->gravity = 66;
    gBtlWork->fadeAmount = 10;
    gBtlWork->flags |= BTL_FLAG_VS_BATTLE;
    sVsKeyHoldL[0] = 0;
    sVsKeyHoldR[0] = 0;
    sVsKeyReleaseL[0] = 0;
    sVsKeyReleaseR[0] = 0;
    sVsKeyHoldL[1] = 0;
    sVsKeyHoldR[1] = 0;
    sVsKeyReleaseL[1] = 0;
    sVsKeyReleaseR[1] = 0;
    sVsKeyChordLatch[0] = 0;
    sVsKeyChordLatch[1] = 0;
    sVsSoraReloadTimer = 0;
    sVsRikuReloadTimer = 0;
}

void HandleVsRikuCardInput() {
    BtlWork* btl;
    BtlObj* actor;
    u16 held;
    u16 pressed;
    s32 chord;
    u8 reloadSelected;

    btl = gRikuBtlWork;

    if (gBtlWork->flags & BTL_FLAG_VS_LINK_PARENT) {
        held = SioKeyGetHeldB();
        pressed = SioKeyGetPressedB();
    } else {
        held = SioKeyGetHeldA();
        pressed = SioKeyGetPressedA();
    }

    if (gRikuBtlWork->flags & BTL_FLAG_CAN_CHARGE_RELOAD) {
        if (held & A_BUTTON) {
            if (!(held & (L_BUTTON | R_BUTTON))) {
                SetRikuReloadCharging();
            }
        }
    }

    if (gRikuBtlWork->flags & BTL_FLAG_RELOAD_CHARGING) {
        sVsRikuReloadTimer = 5;
        return;
    }

    if ((s16)gRikuBtlWork->listSwitchTimer > 0) {
        if (--gRikuBtlWork->listSwitchTimer == 0) {
            RequestSwitchRikuCardList();
        }

        return;
    }

    if ((s16)sVsRikuReloadTimer > 0) {
        sVsRikuReloadTimer--;
    }

    chord = (u16)ReadVsKeyChord(held, pressed, LINK_SIDE_PARTNER);

    switch (chord) {
    case L_BUTTON:
        RequestRikuNextCard();
        break;
    case R_BUTTON:
        RequestRikuPrevCard();
        break;
    }

    if (pressed & SELECT_BUTTON) {
        RequestSwitchRikuCardList();
    }

    reloadSelected = IsRikuReloadCardSelected();

    if (reloadSelected) {
        btl->lHeldFrames = 0;
        btl->rHeldFrames = 0;
    } else {
        if ((held & L_BUTTON) && !(held & R_BUTTON)) {
            if (btl->lHeldFrames <= 254) {
                btl->lHeldFrames++;
            }
        } else {
            btl->lHeldFrames = reloadSelected;
        }

        if ((held & R_BUTTON) && !(held & L_BUTTON)) {
            if (btl->rHeldFrames <= 254) {
                btl->rHeldFrames++;
            }
        } else {
            btl->rHeldFrames = 0;
        }
    }

    if (btl->lHeldFrames > 32) {
        RequestRikuNextCard();
    }

    if (btl->rHeldFrames > 32) {
        RequestRikuPrevCard();
    }

    actor = btl->actor;

    if (actor->flags & BTLOBJ_FLAG_CARD_USE_BLOCKED) {
        return;
    }

    if (gBtlWork->flags & BTL_FLAG_OPPONENT_CARD_ACTION) {
        return;
    }

    if (gBtlWork->flags & BTL_FLAG_OPPONENT_CARD_BUSY) {
        return;
    }

    if (gBtlWork->flags & BTL_FLAG_CARD_BREAK) {
        return;
    }

    if (actor->flags & BTLOBJ_FLAG_DAMAGE_PENDING) {
        return;
    }

    if (chord == (L_BUTTON | R_BUTTON)) {
        if (GetRikuStockCount() > 2) {
            RequestRikuStockUse();
        } else {
            RequestRikuCardStock();
        }
    }

    if (pressed & A_BUTTON) {
        RequestRikuCardUse();

        if (GetRikuCardListIndex() == CARD_LIST_ENEMY) {
            if (IsRikuSelectionEmpty() == 0) {
                gRikuBtlWork->listSwitchTimer = 15;
            }
        }
    }
}

void HandleVsSoraCardInput() {
    BtlWork* btl;
    BtlObj* actor;
    u16 held;
    u16 pressed;
    s32 chord;
    u8 reloadSelected;

    btl = gBtlWork;

    if (btl->flags & BTL_FLAG_VS_LINK_PARENT) {
        held = SioKeyGetHeldA();
        pressed = SioKeyGetPressedA();
    } else {
        held = SioKeyGetHeldB();
        pressed = SioKeyGetPressedB();
    }

    if (gBtlWork->flags & BTL_FLAG_CAN_CHARGE_RELOAD) {
        if (held & A_BUTTON) {
            if (!(held & (L_BUTTON | R_BUTTON))) {
                SetSoraReloadCharging();
            }
        }
    }

    if (gBtlWork->flags & BTL_FLAG_RELOAD_CHARGING) {
        sVsSoraReloadTimer = 5;
        return;
    }

    if ((s16)gBtlWork->listSwitchTimer > 0) {
        if (--gBtlWork->listSwitchTimer == 0) {
            RequestSwitchSoraCardList();
        }

        return;
    }

    if ((s16)sVsSoraReloadTimer > 0) {
        sVsSoraReloadTimer--;
    }

    chord = (u16)ReadVsKeyChord(held, pressed, LINK_SIDE_SELF);

    switch (chord) {
    case L_BUTTON:
        RequestSoraNextCard();
        break;
    case R_BUTTON:
        RequestSoraPrevCard();
        break;
    }

    if (pressed & SELECT_BUTTON) {
        RequestSwitchSoraCardList();
    }

    reloadSelected = IsSoraReloadCardSelected();

    if (reloadSelected) {
        btl->lHeldFrames = 0;
        btl->rHeldFrames = 0;
    } else {
        if ((held & L_BUTTON) && !(held & R_BUTTON)) {
            if (btl->lHeldFrames <= 254) {
                btl->lHeldFrames++;
            }
        } else {
            btl->lHeldFrames = reloadSelected;
        }

        if ((held & R_BUTTON) && !(held & L_BUTTON)) {
            if (btl->rHeldFrames <= 254) {
                btl->rHeldFrames++;
            }
        } else {
            btl->rHeldFrames = 0;
        }
    }

    if (btl->lHeldFrames > 32) {
        RequestSoraNextCard();
    }

    if (btl->rHeldFrames > 32) {
        RequestSoraPrevCard();
    }

    actor = btl->actor;

    if (actor->flags & BTLOBJ_FLAG_CARD_USE_BLOCKED) {
        return;
    }

    if (gBtlWork->flags & BTL_FLAG_PLAYER_CARD_ACTION) {
        return;
    }

    if (gBtlWork->flags & BTL_FLAG_PLAYER_CARD_BUSY) {
        return;
    }

    if (gBtlWork->flags & BTL_FLAG_CARD_BREAK) {
        return;
    }

    if (actor->flags & BTLOBJ_FLAG_DAMAGE_PENDING) {
        return;
    }

    if (chord == (L_BUTTON | R_BUTTON)) {
        if (GetSoraStockCount() > 2) {
            RequestSoraStockUse();
        } else {
            RequestSoraCardStock();
        }
    }

    if (pressed & A_BUTTON) {
        RequestSoraCardUse();

        if (GetSoraCardListIndex() == CARD_LIST_ENEMY) {
            if (IsSoraSelectionEmpty() == 0) {
                gBtlWork->listSwitchTimer = 15;
            }
        }
    }
}

void VsEndCardPlay() {
    gBtlWork->phase = BTL_PHASE_IDLE;

    if (!(gBtlWork->flags & BTL_FLAG_CARD_BREAK)) {
        gBtlWork->flags |= BTL_FLAG_CARD_PLAY_ENDED;
    }

    gBtlWork->flags &= ~BTL_FLAG_OPPONENT_CARD_ACTION;
    gBtlWork->flags &= ~BTL_FLAG_PLAYER_CARD_ACTION;
}

void VsBattleUpdate() {
    BtlObj* player = gBtlWork->actor;
    BtlObj* other = gRikuBtlWork->actor;
    s32 entered;
    s32 i;
    s32 busy;
    s8 rank;

    if (gBtlWork->hcEffect == HC_EFFECT_FLOAT || gRikuBtlWork->hcEffect == HC_EFFECT_FLOAT) {
        gBtlWork->gravity = 38;
    } else {
        gBtlWork->gravity = 66;
    }

    switch ((u32)gBtlWork->phase) {
    case BTL_PHASE_IDLE:
    case BTL_PHASE_CARD_PLAY:
        if (gBtlWork->flags & BTL_FLAG_VS_LINK_PARENT) {
            HandleVsSoraCardInput();
            HandleVsRikuCardInput();
        } else {
            HandleVsRikuCardInput();
            HandleVsSoraCardInput();
        }

        break;
    }

    TaskPoolUpdate(&gBtlWork->taskPools[1]);

    if (gBtlWork->flags & BTL_FLAG_CARD_BREAK) {
        gBtlWork->flags |= BTL_FLAG_STOP_BGFX;
        gBtlWork->flags &= ~BTL_FLAG_STOCK_SEQUENCE;
        gRikuBtlWork->flags &= ~BTL_FLAG_STOCK_SEQUENCE;
        gBtlWork->phase = BTL_PHASE_IDLE;

        if (gBtlWork->soraOwnsPlay) {
            gBtlWork->flags &= ~BTL_FLAG_OPPONENT_CARD_ACTION;
            other->flags |= BTLOBJ_FLAG_CARD_BREAK_PENDING;
            FadeFromAmount(FADE_MODE_ADD_WHITE, 10, 4);
        } else {
            gBtlWork->flags &= ~BTL_FLAG_PLAYER_CARD_ACTION;
            player->flags |= BTLOBJ_FLAG_CARD_BREAK_PENDING;
            FadeFromAmount(FADE_MODE_RED, 10, 4);
        }

        MosaicStartIn(16, 15);
        SetBattleZoom(1, Q_8_8(1), gBtlWork->x2, gBtlWork->y2);
        gBtlWork->phaseStep = 0;
    }

    if (gBtlWork->flags & BTL_FLAG_CARD_PLAY_START) {
        entered = TRUE;
        gBtlWork->flags &= ~BTL_FLAG_CARD_PLAY_START;

        if (gBtlWork->soraOwnsPlay) {
            gBtlWork->flags |= BTL_FLAG_PLAYER_CARD_ACTION;
            player->flags |= BTLOBJ_FLAG_CARD_ACTION_PENDING;
        } else {
            gBtlWork->flags |= BTL_FLAG_OPPONENT_CARD_ACTION;
            other->flags |= BTLOBJ_FLAG_CARD_ACTION_PENDING;
        }

        gBtlWork->phase = BTL_PHASE_CARD_PLAY;
        gBtlWork->phaseStep = 0;
    } else {
        entered = FALSE;
    }

    if ((gBtlWork->flags & BTL_FLAG_PLAYER_DEFEATED) && gBtlWork->phase != BTL_PHASE_END) {
        gBtlWork->phase = BTL_PHASE_END;
        gBtlWork->phaseStep = 0;
    }

    switch ((u32)gBtlWork->phase) {
    case BTL_PHASE_IDLE:
        break;
    case BTL_PHASE_START:
        if (gBtlWork->phaseStep == BTL_START_STEP_INTRO) {
            gBtlWork->task = NULL;
            gBtlWork->phaseStep = BTL_START_STEP_EXCLUDE_PALETTES;
        }

        if (FadeIsActive()) return;

        if (gBtlWork->phaseStep == BTL_START_STEP_EXCLUDE_PALETTES) {
            for (i = 0; i < 32; i++) {
                if (gBtlWork->fadeExcludedPalettes & (s32)(1U << i)) FadeSetPaletteExcluded(i, TRUE);
            }

            gBtlWork->phaseStep = BTL_START_STEP_CREATE_TASKS;
        }

        if (IsTaskActive(gBtlWork->task)) return;

        if (gBtlWork->phaseStep == BTL_START_STEP_CREATE_TASKS) {
            TaskCreate(&gBtlWork->taskPools[0], &gTaskDescBtlVslockon, NULL);
            TaskCreate(&gBtlWork->taskPools[1], &gTaskDescBtlHpply, NULL);
            TaskCreate(&gBtlWork->taskPools[1], &gTaskDescBtlHpoth, NULL);

            if (gBtlWork->flags & BTL_FLAG_VS_LINK_PARENT) {
                TaskCreate(&gBtlWork->taskPools[1], &gTaskDescCardBattleSora, NULL);
                TaskCreate(&gBtlWork->taskPools[1], &gTaskDescCardBattleRiku, NULL);
            } else {
                TaskCreate(&gBtlWork->taskPools[1], &gTaskDescCardBattleRiku, NULL);
                TaskCreate(&gBtlWork->taskPools[1], &gTaskDescCardBattleSora, NULL);
            }

            RequestOpenCards();
            RequestBossCardOpen();
            gBtlWork->phaseStep = BTL_START_STEP_FINISH;
        } else if (gBtlWork->phaseStep == BTL_START_STEP_FINISH) {
            gBtlWork->phase = BTL_PHASE_IDLE;
            gBtlWork->phaseStep = 0;
        }

        break;
    case BTL_PHASE_END:
        if (gBtlWork->phaseStep == 0) {
            RequestCloseCards();
            RequestBossCardClose();
            gBtlWork->flags |= BTL_FLAG_CARD_PLAY_ENDED;
            gRikuBtlWork->flags |= BTL_FLAG_DISMISS_SUMMONS;
            gBtlWork->flags |= BTL_FLAG_DISMISS_SUMMONS;
            SetBattleZoom(8, Q_8_8(1), gBtlWork->x2, gBtlWork->y2);
            gBtlWork->hcEffect = HC_EFFECT_NONE;
            gRikuBtlWork->hcEffect = HC_EFFECT_NONE;
        }

        if (gBtlWork->phaseStep == 140) {
            FadeStartOut(FADE_MODE_WHITE, 100);
            FadeLock();
            gBtlWork->flags |= BTL_FLAG_STOP_BGFX;
            gBtlWork->hitStop = 100;
        } else if (gBtlWork->phaseStep > 140 && !FadeIsActive()) {
            m4aMPlayAllStop();

            if (player->hp <= 0) ModeRequest(&gModeSioBtlCardget, 1);
            else ModeRequest(&gModeSioBtlCardget, 0);

            return;
        }

        gBtlWork->phaseStep++;
        break;
    case BTL_PHASE_CARD_PLAY:
        if (entered) return;

        busy = FALSE;

        if (player->flags & BTLOBJ_FLAG_IN_CARD_ACTION) busy = TRUE;

        if (other->flags & BTLOBJ_FLAG_IN_CARD_ACTION) busy = TRUE;

        if (busy) return;

        rank = GetStockMoveCount();
        gBtlWork->phaseStep = 0;

        if (gBtlWork->flags & BTL_FLAG_PLAYER_CARD_ACTION) {
            if (gBtlWork->stockMove >= rank) gBtlWork->flags &= ~BTL_FLAG_STOCK_SEQUENCE;

            if (gBtlWork->flags & BTL_FLAG_STOCK_SEQUENCE) player->flags |= BTLOBJ_FLAG_CARD_ACTION_PENDING;
            else VsEndCardPlay();
        } else {
            if (gRikuBtlWork->stockMove >= rank) gRikuBtlWork->flags &= ~BTL_FLAG_STOCK_SEQUENCE;

            if (gRikuBtlWork->flags & BTL_FLAG_STOCK_SEQUENCE) other->flags |= BTLOBJ_FLAG_CARD_ACTION_PENDING;
            else VsEndCardPlay();
        }

        break;
    }
}
