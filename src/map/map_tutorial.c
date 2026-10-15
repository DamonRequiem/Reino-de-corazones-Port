/**
 * map_tutorial.c
 * Field Tutorial
 */

#include "map_tasks.h"
#include "sprites_emy.h"
#include "sprites_map.h"
#include "sprites_map_tasks.h"
#include "sprite_palettes.h"
#include "songs.h"
#include "anim.h"
#include "battle_actor_types.h"
#include "btl_collision.h"
#include "card_api.h"
#include "field_state.h"
#include "fld_types.h"
#include "game_state.h"
#include "m4a_song.h"
#include "map.h"
#include "map_api.h"
#include "map_types.h"
#include "obj.h"
#include "obj_api.h"
#include "player_progression_types.h"
#include "registration_data.h"
#include "task_descriptors.h"
#include "taskpool.h"
#include "types.h"
#include <stddef.h>
#include "battle_ids.h"
#include "card_message_data.h"

void MapTutorialStartBattle() {
    gFieldState->flags |= FIELD_FLAG_FREEZE_ENEMIES;
    gMapRoomState->battleId = BATTLE_TRAVERSE_TOWN_0;
    gMapRoomState->flags &= ~ROOM_FLAG_TUTORIAL_ACTIVE;
    gMapRoomState->flags |= ROOM_FLAG_START_BATTLE;
}

void MapTutorialWaitStart(MapTutorialWork* work) {
    u32 flags;

    if (gFieldState->lockonTarget == NULL) {
        flags = gFieldState->flags;

        if (!(flags & FIELD_FLAG_MENU_OPEN) && !(gMapRoomState->flags & ROOM_FLAG_SAVE_MENU_OPEN) && (gGameState.progression.tutorialFlags & TUTORIAL_FLAG_SAVE_POINT)) {
            gMapRoomState->flags |= ROOM_FLAG_TUTORIAL_ACTIVE;
            gFieldState->flags = flags | FIELD_FLAG_FREEZE_PLAYER;
            CreateCardMessageTask(&work->tasks, 0, CARD_MSG_MAP_TUTORIAL_0);
            work->update = MapTutorialDropBarrel;
        }
    }
}

void MapTutorialDropBarrel(MapTutorialWork* work) {
    if (!IsMessageWindowOpen()) {
        AnimState* anim;

        MapPickFreeFloorPosInView(&work->obj.fieldPosition, &work->obj.fieldPosition.y);
        work->obj.fieldPosition.z = 0;
        work->obj.fieldPosition.ground = GetFldPosFloor(&work->obj.fieldPosition);
        work->obj.fieldPosition.y -= work->obj.fieldPosition.ground;
        work->obj.fieldPosition.z = work->obj.fieldPosition.ground - 0xA000;
        work->obj.height = 24;
        work->obj.speed = 2;
        work->tiles = AllocObjTiles(0x400, gMapGmkBarrelTiles);
        work->palette = LoadObjPalette(gMapGmkBarrelPalette, sizeof(gMapGmkBarrelPalette));
        anim = &work->anim;
        AnimInit(anim, gMapGmkBarrelAnims, gMapGmkBarrelFrames);
        AnimStart(anim, 0, ANIM_FLAG_LOOP);
        work->gfx = AnimGetGfx(anim);
        ColliderInit(&work->collider, COLLIDER_TYPE_SOLID, 12, 24);
        ColliderSetPosition(&work->collider, work->obj.fieldPosition.x, work->obj.fieldPosition.y, work->obj.fieldPosition.z);
        work->shadowVisible = TRUE;
        TaskCreate(&work->tasks2, &gTaskDescFldShadow, &work->obj);
        work->visible = TRUE;
        work->update = MapTutorialBarrelFall;
    }
}

void MapTutorialBarrelFall(MapTutorialWork* work) {
    MapTutorialWork* barrel = work;

    work->obj.speed += 0x38;
    work->obj.fieldPosition.z += work->obj.speed;

    if (work->obj.fieldPosition.z > work->obj.fieldPosition.ground) {
        gFieldState->flags &= ~FIELD_FLAG_FREEZE_PLAYER;
        m4aSongNumStart(SONG_SND_215);
        work->obj.fieldPosition.z = work->obj.fieldPosition.ground;
        work->obj.speed = 0;
        work->shadowVisible = FALSE;
        work->update = MapTutorialWaitBarrelHit;
    }

    ColliderSetPosition(&barrel->collider, barrel->obj.fieldPosition.x, barrel->obj.fieldPosition.y, barrel->obj.fieldPosition.z);
}

void MapTutorialWaitBarrelHit(MapTutorialWork* work) {
    if (IsHitByMapAttack(&work->obj.fieldPosition, 8, 8)) {
        m4aSongNumStart(SONG_SYS_OBJ_BREAK);
        TaskCreate(&gFieldState->tasks, &gTaskDescMapSpark, &work->obj);
        gMapRoomState->flags &= ~ROOM_FLAG_NO_RANDOM_PRIZE;
        TryCreateRandomPrzCard(FALSE, work->obj.fieldPosition.x, work->obj.fieldPosition.y, work->obj.fieldPosition.z);
        AnimStart(&work->anim, 1, 0);
        work->update = MapTutorialBarrelBreak;
        ColliderUnregister(&work->collider);
    }
}

void MapTutorialBarrelBreak(MapTutorialWork* work) {
    if (AnimIsFinished(&work->anim)) {
        work->update = MapTutorialWaitPrizeCard;
    } else {
        work->gfx = AnimUpdate(&work->anim);
    }
}

void MapTutorialWaitPrizeCard(MapTutorialWork* work) {
    if ((gMapRoomState->flags & ROOM_FLAG_PRIZE_CARD_ACTIVE) == 0) {
        gGameState.progression.tutorialFlags |= TUTORIAL_FLAG_MAP_BARREL;
        gFieldState->flags |= FIELD_FLAG_FREEZE_PLAYER;
        CreateCardMessageTask(&work->tasks, 0, CARD_MSG_MAP_TUTORIAL_1);
        work->update = MapTutorialSpawnEnemy;
    }
}

void MapTutorialSpawnEnemy(MapTutorialWork* work) {
    if (!IsMessageWindowOpen()) {
        AnimState* anim;
        u8 flip;

        MapPickFreeFloorPosInView(&work->obj.fieldPosition, &work->obj.fieldPosition.y);
        work->obj.fieldPosition.z = 0;
        work->obj.fieldPosition.ground = GetFldPosFloor(&work->obj.fieldPosition);
        work->obj.fieldPosition.y -= work->obj.fieldPosition.ground;
        work->obj.fieldPosition.z = work->obj.fieldPosition.ground;
        work->obj.height = 16;
        flip = FALSE;

        if (gFieldState->actor.fieldPosition.x > work->obj.fieldPosition.x) {
            flip = TRUE;
        }

        work->flip = flip;
        work->tiles = AllocObjTiles(0x400, gEmy00L06Tiles);
        work->palette = LoadObjPalette(gEmy00Palette, sizeof(gEmy00Palette));
        anim = &work->anim;
        AnimInit(anim, gEmy00L06Anims, gEmy00L06Frames);
        AnimStart(anim, 0, ANIM_FLAG_LOOP);
        work->gfx = AnimGetGfx(anim);
        ColliderInit(&work->collider, COLLIDER_TYPE_ENEMY, 8, 16);
        ColliderSetPosition(&work->collider, work->obj.fieldPosition.x, work->obj.fieldPosition.y, work->obj.fieldPosition.z);
        ColliderSetDisabled(&work->collider, TRUE);
        work->update = MapTutorialEnemyAppear;
    }
}

void MapTutorialEnemyAppear(MapTutorialWork* work) {
    AnimState* anim = &work->anim;

    if (AnimIsFinished(anim)) {
        AnimChangeWithTables(anim, 0, ANIM_FLAG_LOOP, gEmy00L00Anims, gEmy00L00Frames);
        SetObjTileSource(work->tiles, gEmy00L00Tiles);
        CreateCardMessageTask(&work->tasks, 0, CARD_MSG_MAP_TUTORIAL_2);
        work->update = MapTutorialWaitEnemyMessage;
    } else {
        work->gfx = AnimUpdate(anim);
    }
}

void MapTutorialWaitEnemyMessage(MapTutorialWork* work) {
    work->gfx = AnimUpdate(&work->anim);

    if (!IsMessageWindowOpen()) {
        gFieldState->flags &= ~FIELD_FLAG_FREEZE_PLAYER;
        ColliderSetDisabled(&work->collider, FALSE);
        work->update = MapTutorialEnemyUpdate;
    }
}

void MapTutorialEnemyUpdate(MapTutorialWork* work) {
    AnimState* anim = &work->anim;

    work->gfx = AnimUpdate(anim);

    if (IsHitByMapAttack(&work->obj.fieldPosition, 8, 16)) {
        gMapRoomState->flags |= ROOM_FLAG_ATTACK_HIT;
        gMapRoomState->flags |= ROOM_FLAG_ENEMY_STRUCK;
        TaskCreate(&gFieldState->tasks, &gTaskDescMapSpark, &work->obj);
        m4aSongNumStart(SONG_SYS_FIELD_ATT00);
        AnimChangeWithTables(anim, 0, ANIM_FLAG_LOOP, gEmy00L09Anims, gEmy00L09Frames);
        SetObjTileSource(work->tiles, gEmy00L09Tiles);
        work->update = MapTutorialEnemyHit;
    } else if (work->collider.colliding) {
        if (!(gMapRoomState->flags & ROOM_FLAG_ENEMY_STRUCK) && work->collider.otherType == COLLIDER_TYPE_PLAYER) {
            ColliderSetDisabled(&work->collider, TRUE);
            MapTutorialStartBattle();
        } else {
            work->obj.fieldPosition.x += work->collider.pushX;
            work->obj.fieldPosition.y += work->collider.pushY;
        }
    }
}

void MapTutorialEnemyHit(MapTutorialWork* work) {
    AnimState* anim = &work->anim;

    if (AnimIsFinished(anim)) {
        ColliderSetDisabled(&work->collider, TRUE);
        gGameState.flags |= GAME_FLAG_FIRST_STRIKE;
        MapTutorialStartBattle();
    } else {
        work->gfx = AnimUpdate(anim);
    }
}

void Task_MapTutorial_0(MapTutorialWork* work) {
    u16 barrelDone;

    TaskPoolInit(&work->tasks, 1);
    TaskPoolInit(&work->tasks2, 1);
    gMapRoomState->flags |= ROOM_FLAG_NO_RANDOM_PRIZE;
    work->tiles = NULL;
    work->palette = NULL;
    work->flip = FALSE;
    barrelDone = gGameState.progression.tutorialFlags & TUTORIAL_FLAG_MAP_BARREL;

    if (barrelDone == 0) {
        work->shadowVisible = FALSE;
        work->visible = FALSE;
        work->update = MapTutorialWaitStart;
    } else {
        gFieldState->flags |= FIELD_FLAG_FREEZE_PLAYER;
        TaskCreate(&work->tasks2, &gTaskDescFldShadow, &work->obj);
        work->visible = TRUE;
        work->shadowVisible = TRUE;
        work->update = MapTutorialSpawnEnemy;
    }
}

s32 Task_MapTutorial_1(MapTutorialWork* work) {
    TaskPoolUpdate(&work->tasks);
    TaskPoolUpdate(&work->tasks2);

    if (work->update != NULL) {
        work->update(work);

        if (work->update != NULL) {
            return 1;
        }
    }

    return 0;
}

void Task_MapTutorial_2(MapTutorialWork* work) {
    u16 flags;
    u16 priority;
    s32 pixelY;
    s32 flip;
    s16 x;
    s16 y;

    TaskPoolDraw(&work->tasks);

    if (work->visible) {
        x = (work->obj.fieldPosition.x >> 8) - (gFieldState->x >> 8);
        pixelY = work->obj.fieldPosition.y >> 8;
        y = pixelY + (work->obj.fieldPosition.z >> 8) - (gFieldState->y >> 8);
        priority = -0x1004 - pixelY * 4;
        flip = work->flip;
        flags = SPRITE_PRIORITY(2);

        if (flip) {
            flags = SPRITE_PRIORITY(2) | SPRITE_FLAG_HFLIP;
        }

        DrawSprite(x, y, work->gfx, work->tiles, work->palette, NULL, flags, priority);

        if (work->shadowVisible) {
            work->obj.shadowZ = work->obj.fieldPosition.ground;
            work->obj.shadowPriority = priority + 1;
            TaskPoolDraw(&work->tasks2);
        }
    }
}

void Task_MapTutorial_3(MapTutorialWork* work) {
    if (work->tiles != NULL) {
        ReleaseObjTiles(work->tiles);
        ReleaseObjPalette(work->palette);
    }

    TaskPoolDestroy(&work->tasks);
    TaskPoolDestroy(&work->tasks2);
}

TaskDesc gTaskDescMapTutorial = {
    "Task_MapTutorial",
    (TaskInitFunc)Task_MapTutorial_0,
    (TaskUpdateFunc)Task_MapTutorial_1,
    (TaskDrawFunc)Task_MapTutorial_2,
    (TaskDestroyFunc)Task_MapTutorial_3,
    sizeof(MapTutorialWork),
};
