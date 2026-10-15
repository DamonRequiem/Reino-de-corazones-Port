/**
 * map_runtime.c
 * Floor and Room Progression
 */

#include "map_api.h"
#include "msg_api.h"
#include "monsgage.h"
#include "bos4.h"
#include "bos4_api.h"
#include "map_runtime.h"
#include "map_text_data.h"
#include "world_types.h"
#include "system_state.h"
#include "player_progression.h"
#include "jiminy_inline_text_data.h"
#include "jiminy_data.h"
#include "card_api.h"
#include "common_text.h"
#include "engine_math.h"
#include "fld_types.h"
#include "game_state.h"
#include "map_types.h"
#include "player_progression_types.h"
#include "types.h"
#include "save_types.h"
#include <stddef.h>
#include "map.h"
#include "map_room_tables.h"
#include "text_types.h"
#include "event_ids.h"
#include "jiminy_records_index_data.h"
#include "card_ids.h"
#include "map_room_types.h"

extern u8 gWorldBattleStages[];
extern u8 gRikuRoomTypes[];
extern const MapNameText* gMapWorldNames[];

static const u8 sSoraWorldExitEvents[13] = {
    EVENT_010_1F_GOAL_1,
    EVENT_013_2F_GOAL,
    EVENT_016_3F_GOAL,
    EVENT_019_4F_GOAL,
    EVENT_022_5F_GOAL,
    EVENT_025_6F_GOAL_1,
    EVENT_030_7F_GOAL_1,
    EVENT_033_8F_GOAL_1,
    EVENT_037_9F_GOAL,
    EVENT_040_10F_GOAL_1,
    EVENT_047_11F_DEMO_1,
    EVENT_058_12F_GOAL,
    EVENT_066_13F_CASTLE_OBLIVION_LAST1,
};

static const u8 sRikuWorldExitEvents[13] = {
    EVENT_155_RIKU_B12F_GOAL,
    MAP_EVENT_NONE,
    EVENT_160_RIKU_B10F_GOAL,
    MAP_EVENT_NONE,
    EVENT_163_RIKU_B8F_GOAL,
    MAP_EVENT_NONE,
    MAP_EVENT_NONE,
    MAP_EVENT_NONE,
    EVENT_171_RIKU_B4F_GOAL,
    MAP_EVENT_NONE,
    EVENT_190_RIKU_B2F_GOAL,
    EVENT_193_RIKU_B1F_LAST1,
    0,
};

u8 GetOppositeDoorSide(u8 side) {
    switch (side) {
    case MAP_DOOR_SIDE_UP_RIGHT:
        side = MAP_DOOR_SIDE_DOWN_LEFT;
        break;
    case MAP_DOOR_SIDE_DOWN_LEFT:
        side = MAP_DOOR_SIDE_UP_RIGHT;
        break;
    case MAP_DOOR_SIDE_DOWN_RIGHT:
        side = MAP_DOOR_SIDE_UP_LEFT;
        break;
    case MAP_DOOR_SIDE_UP_LEFT:
        side = MAP_DOOR_SIDE_DOWN_RIGHT;
        break;
    }

    return side;
}

void MarkEventRoomDone(MapEventDoor* door) {
    MapFloorRoom* floorRoom;

    if (door->kind == EVENT_DOOR_EVENT_ROOM || door->kind == EVENT_DOOR_BOSS_ROOM) {
        floorRoom = GetMapFloorRoom(door->room);
        floorRoom->cardValue = 0;
        floorRoom->nameId = ROOM_NAME_UNKNOWN_PLACE;
        floorRoom->roomType = ROOM_TYPE_PLAIN;
        floorRoom->flags |= FLOOR_ROOM_FLAG_EVENT_DONE;
    }
}

void SetHallDefaultSpawn() {
    if (gGameState.flags & GAME_FLAG_RIKU) {
        switch (gGameState.floor) {
        case 1:
        case 5:
        case 8:
        case 9:
        case 10:
        case 11:
            gMapFloorState.entrySide = MAP_DOOR_SIDE_NONE;
            break;
        }
    } else {
        if (gGameState.floor != 12) {
            gMapFloorState.entrySide = MAP_DOOR_SIDE_NONE;
        }
    }
}

void UpdateWorldFriendFlags() {
    u16 friendFlags;

    if (gGameState.floor != GetProgressFloor() || gMapFloorState.room == MAP_ROOM_ENTRANCE_HALL
            || gMapFloorState.room == MAP_ROOM_EXIT_HALL) {
        if ((gGameState.flags & GAME_FLAG_FRIENDS_SAVED) == 0) {
            gGameState.flags |= GAME_FLAG_FRIENDS_SAVED;
            gGameState.progression.savedFriendFlags = gGameState.progression.friendFlags & FRIEND_FLAGS_WORLD;
        }

        if ((gGameState.flags & GAME_FLAG_RIKU) != 0) {
            return;
        }

        friendFlags = gGameState.progression.friendFlags & ~FRIEND_FLAGS_WORLD;
        gGameState.progression.friendFlags = friendFlags;

        if (gMapFloorState.room >= MAP_ROOM_EXIT_HALL && gMapFloorState.room <= MAP_ROOM_ENTRANCE_HALL) {
            return;
        }

        switch (gMapFloorState.world) {
        case WORLD_AGRABAH:
            friendFlags = FRIEND_FLAG_ALADDIN | gGameState.progression.friendFlags;
            gGameState.progression.friendFlags = friendFlags;
            break;
        case WORLD_ATLANTICA:
            friendFlags = FRIEND_FLAG_ARIEL | gGameState.progression.friendFlags;
            gGameState.progression.friendFlags = friendFlags;
            break;
        case WORLD_HALLOWEEN_TOWN:
            friendFlags = FRIEND_FLAG_JACK | gGameState.progression.friendFlags;
            gGameState.progression.friendFlags = friendFlags;
            break;
        case WORLD_NEVER_LAND:
            friendFlags = FRIEND_FLAG_PETER_PAN | gGameState.progression.friendFlags;
            gGameState.progression.friendFlags = friendFlags;
            break;
        case WORLD_HOLLOW_BASTION:
            friendFlags = FRIEND_FLAG_THE_BEAST | gGameState.progression.friendFlags;
            gGameState.progression.friendFlags = friendFlags;
            break;
        case WORLD_OLYMPUS_COLISEUM:
        case WORLD_WONDERLAND:
        case WORLD_MONSTRO:
        default:
            break;
        }
    } else {
        if ((gGameState.flags & GAME_FLAG_FRIENDS_SAVED) == 0) {
            return;
        }

        gGameState.flags &= ~GAME_FLAG_FRIENDS_SAVED;
        friendFlags = (gGameState.progression.friendFlags & ~FRIEND_FLAGS_WORLD) | gGameState.progression.savedFriendFlags;
        gGameState.progression.friendFlags = friendFlags;
    }
}

const MapFloorDef* GetMapFloorDef(u8 floor) {
    if (gGameState.flags & GAME_FLAG_RIKU) {
        return &gRikuMapFloorDefs[floor];
    }

    return &gMapFloorDefs[floor];
}

u8* GetMapRoomLinks(u8 room) {
    if (gGameState.flags & GAME_FLAG_RIKU) {
        return gRikuMapFloorDefs[gGameState.floor].links + room * 4;
    }

    return gMapFloorDefs[gGameState.floor].links + room * 4;
}

MapEventDoor* GetMapEventDoor(u8 index) {
    if (gGameState.flags & GAME_FLAG_RIKU) {
        return gRikuMapFloorDefs[gGameState.floor].eventDoors + index;
    }

    return gMapFloorDefs[gGameState.floor].eventDoors + index;
}

MapFloorRoom* GetMapFloorRoom(u8 index) {
    return &gMapFloorState.rooms[index];
}

u8 GetMapRoomLink(u8 room, u8 side) {
    return GetMapRoomLinks(room)[side];
}

u16 GetMapDoorFlags(u8 room, u8 side) {
    MapFloorRoom* floorRoom;
    MapEventDoor* door;
    u16 flags;
    u8 neighbor;
    u8 kind;

    neighbor = GetMapRoomLink(room, side);

    if (neighbor == MAP_ROOM_NONE) {
        return 0;
    }

    if (neighbor >= MAP_ROOM_EXIT_HALL && neighbor <= MAP_ROOM_ENTRANCE_HALL) {
        return DOOR_FLAG_PRESENT | DOOR_FLAG_OPEN;
    }

    floorRoom = GetMapFloorRoom(neighbor);
    flags = DOOR_FLAG_PRESENT;

    if ((floorRoom->flags & FLOOR_ROOM_FLAG_CREATED) != 0) {
        flags = DOOR_FLAG_PRESENT | DOOR_FLAG_OPEN;
    }

    if ((floorRoom->flags & FLOOR_ROOM_FLAG_EVENT_DONE) != 0) {
        flags |= DOOR_FLAG_SEALED;
    }

    if ((floorRoom->flags & FLOOR_ROOM_FLAG_LOCKED) != 0) {
        flags |= DOOR_FLAG_SEALED;
    }

    kind = GetEventRoomKind(neighbor);

    if (kind == EVENT_DOOR_EVENT_ROOM || kind == EVENT_DOOR_BOSS_ROOM || kind == EVENT_DOOR_HIDDEN_CHAMBER) {
        flags |= DOOR_FLAG_EVENT;
        door = GetMapEventDoor(0);

        while (door->kind != EVENT_DOOR_END) {
            if (door->room == neighbor) {
                if (door->side != side) {
                    flags |= DOOR_FLAG_SEALED;
                }

                break;
            }

            door++;
        }
    }

    if ((gMapFloorState.flags & FLOOR_FLAG_EVENT_ROOM_OPEN) != 0) {
        door = GetMapEventDoor(*GetMapRoomEvent(gMapFloorState.eventStep));

        if (door->room == neighbor && door->side == side) {
            flags |= DOOR_FLAG_OPEN;
        }
    }

    return flags;
}

void UpdateGameWorld() {
    u16 friendFlags;

    switch (gMapFloorState.room) {
    case MAP_ROOM_EXIT_HALL:
    case MAP_ROOM_ENTRANCE_HALL:
        gGameState.world = 0;
        gGameState.battleStage = BATTLE_STAGE_CASTLE_OBLIVION;
        break;
    case MAP_ROOM_TUTORIAL:
        gGameState.world = WORLD_TRAVERSE_TOWN;
        gGameState.battleStage = BATTLE_STAGE_TRAVERSE_TOWN;
        break;
    default:
        gGameState.world = gMapFloorState.world;
        gGameState.battleStage = gWorldBattleStages[gMapFloorState.world];
        break;
    }

    if ((gGameState.flags & GAME_FLAG_RIKU) != 0) {
        InitRikuDeckForWorld(gGameState.world);

        if ((gGameState.flags & GAME_FLAG_RIKU) != 0) {
            friendFlags = gGameState.progression.friendFlags & 0xFF80;
            gGameState.progression.friendFlags = friendFlags;
            return;
        }
    }

    switch (gGameState.world) {
    case 0:
        break;
    case WORLD_AGRABAH:
        friendFlags = gGameState.progression.friendFlags & 0xFF07;
        gGameState.progression.friendFlags = friendFlags;
        break;
    case WORLD_ATLANTICA:
        friendFlags = gGameState.progression.friendFlags & 0xFF0B;
        gGameState.progression.friendFlags = friendFlags;
        break;
    case WORLD_HALLOWEEN_TOWN:
        friendFlags = gGameState.progression.friendFlags & 0xFF13;
        gGameState.progression.friendFlags = friendFlags;
        break;
    case WORLD_NEVER_LAND:
        friendFlags = gGameState.progression.friendFlags & 0xFF23;
        gGameState.progression.friendFlags = friendFlags;
        break;
    case WORLD_HOLLOW_BASTION:
        friendFlags = gGameState.progression.friendFlags & 0xFF43;
        gGameState.progression.friendFlags = friendFlags;
        break;
    case WORLD_OLYMPUS_COLISEUM:
    case WORLD_WONDERLAND:
    case WORLD_MONSTRO:
    default:
        friendFlags = gGameState.progression.friendFlags & 0xFF03;
        gGameState.progression.friendFlags = friendFlags;
        break;
    }
}

void SetWorldJiminyFlags() {
    if ((gGameState.flags & GAME_FLAG_RIKU) != 0) {
        switch (gGameState.world) {
        case WORLD_AGRABAH:
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_JAFAR_GENIE);
            break;
        case WORLD_ATLANTICA:
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_URSULA);
            break;
        case WORLD_OLYMPUS_COLISEUM:
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_HADES);
            break;
        case WORLD_HALLOWEEN_TOWN:
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_OOGIE_BOOGIE);
            break;
        case WORLD_NEVER_LAND:
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_HOOK);
            break;
        case WORLD_HOLLOW_BASTION:
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_MALEFICENT);
            break;
        }
    } else {
        switch (gGameState.world) {
        case WORLD_TRAVERSE_TOWN:
            SetJiminyFlag(JIMINY_RECORD_STORY_TRAVERSE_TOWN);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_LEON);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_YUFFIE);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_AERITH);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_CID);
            break;
        case WORLD_WONDERLAND:
            SetJiminyFlag(JIMINY_RECORD_STORY_WONDERLAND);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_ALICE);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_QUEEN_OF_HEARTS);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_WHITE_RABBIT);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_CARD_OF_HEARTS);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_CARD_OF_SPADES);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_CHESHIRE_CAT);
            break;
        case WORLD_OLYMPUS_COLISEUM:
            SetJiminyFlag(JIMINY_RECORD_STORY_OLYMPUS_COLISEUM);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_CLOUD);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_HERCULES);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_PHILOCTETES);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_HADES);
            break;
        case WORLD_AGRABAH:
            SetJiminyFlag(JIMINY_RECORD_STORY_AGRABAH);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_ALADDIN);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_GENIE);
            SetJiminyFlag(53);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_JASMINE);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_IAGO);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_JAFAR);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_JAFAR_GENIE);
            break;
        case WORLD_HALLOWEEN_TOWN:
            SetJiminyFlag(JIMINY_RECORD_STORY_HALLOWEEN_TOWN);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_JACK);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_SALLY);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_DR_FINKELSTEIN);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_OOGIE_BOOGIE);
            break;
        case WORLD_MONSTRO:
            SetJiminyFlag(JIMINY_RECORD_STORY_MONSTRO);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_PINOCCHIO);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_GEPPETTO);
            break;
        case WORLD_ATLANTICA:
            SetJiminyFlag(JIMINY_RECORD_STORY_ATLANTICA);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_ARIEL);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_SEBASTIAN);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_FLOUNDER);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_URSULA);
            SetJiminyFlag(68);
            break;
        case WORLD_NEVER_LAND:
            SetJiminyFlag(JIMINY_RECORD_STORY_NEVER_LAND);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_PETER_PAN);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_TINKER_BELL);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_WENDY);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_HOOK);
            break;
        case WORLD_HOLLOW_BASTION:
            SetJiminyFlag(JIMINY_RECORD_STORY_HOLLOW_BASTION);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_BEAST);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_BELLE);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_MALEFICENT);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_DRAGON_MALEFICENT);
            break;
        case WORLD_TWILIGHT_TOWN:
            SetJiminyFlag(JIMINY_RECORD_STORY_TWILIGHT_TOWN);
            break;
        case WORLD_DESTINY_ISLANDS:
            SetJiminyFlag(JIMINY_RECORD_STORY_DESTINY_ISLANDS);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_TIDUS);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_WAKKA);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_SELPHIE);
            break;
        }
    }
}

void SetFloorJiminyFlags() {
    if ((gGameState.flags & GAME_FLAG_RIKU) != 0) {
        switch (gGameState.floor) {
        case 0:
            SetJiminyFlag(JIMINY_RECORD_STORY_TALE_2);
            break;
        case 2:
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_VEXEN);
            break;
        case 4:
            SetJiminyFlag(JIMINY_RECORD_STORY_TALE_3);
            SetJiminyFlag(JIMINY_RECORD_RIKU_CHARACTER_RIKU_REPLICA);
            break;
        case 8:
            SetJiminyFlag(JIMINY_RECORD_STORY_TALE_4);
            SetJiminyFlag(JIMINY_RECORD_RIKU_CHARACTER_LEXAEUS);
            break;
        case 9:
            SetJiminyFlag(JIMINY_RECORD_RIKU_STORY_TALE_5);
            SetJiminyFlag(JIMINY_RECORD_RIKU_CHARACTER_ZEXION);
            break;
        case 10:
            SetJiminyFlag(JIMINY_RECORD_RIKU_STORY_TALE_6);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_NAMINE);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_AXEL);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_MARLUXIA);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_LARXENE);
            SetJiminyFlag(JIMINY_RECORD_RIKU_CHARACTER_DIZ);
            break;
        }
    } else {
        switch (gGameState.floor) {
        case 0:
            SetJiminyFlag(JIMINY_RECORD_STORY_TALE_1);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_AXEL);
            break;
        case 5:
            SetJiminyFlag(JIMINY_RECORD_STORY_TALE_2);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_LARXENE);
            break;
        case 8:
            SetJiminyFlag(JIMINY_RECORD_STORY_TALE_3);
            break;
        case 9:
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_VEXEN);
            break;
        case 11:
            SetJiminyFlag(JIMINY_RECORD_STORY_TALE_4);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_NAMINE);
            SetJiminyFlag(JIMINY_RECORD_CHARACTER_RIKU_REPLICA);
            break;
        }
    }
}

void AdvanceFloorStory() {
    u8* event = GetMapRoomEvent(gMapFloorState.eventStep);
    MapEventDoor* door;
    MapFloorRoom* exitRoom;
    u16 flags;
    u16 clearedFlags;
    u16 exitEventFlags;

    if (gMapFloorState.room == MAP_ROOM_ENTRANCE_HALL) {
        flags = gMapFloorState.flags | FLOOR_FLAG_ENTRY_EVENT_DONE;
        gMapFloorState.flags = flags;

        if ((gGameState.flags & GAME_FLAG_RIKU) != 0) {
            if (gGameState.floor == 0x0A) {
                gMapFloorState.progress++;
            }
        } else {
            if (gGameState.floor == 0) {
                gMapFloorState.room = MAP_ROOM_TUTORIAL;
                gMapFloorState.entrySide = MAP_DOOR_SIDE_NONE;
                return;
            }

            if (gGameState.floor == 0x0C) {
                gMapFloorState.progress++;
            }
        }

        EnterFloorWorld();
    } else if (gMapFloorState.room == MAP_ROOM_EXIT_HALL) {
        clearedFlags = gMapFloorState.flags | FLOOR_FLAG_CLEARED;
        gMapFloorState.flags = clearedFlags;
        SetFloorJiminyFlags();
        gMapFloorState.progress++;
        StoreMapFloorState();
        GoToNextFloor();
        SetHallDefaultSpawn();
    } else if (event[0] == MAP_ROOM_EVENT_END) {
        exitEventFlags = gMapFloorState.flags | FLOOR_FLAG_EXIT_EVENT_DONE;
        gMapFloorState.flags = exitEventFlags;
        gMapFloorState.progress++;
        SetCurrentMapRoom(MAP_ROOM_EXIT_HALL, MAP_DOOR_SIDE_NONE);
    } else {
        flags = gMapFloorState.flags & ~FLOOR_FLAG_EVENT_ROOM_OPEN;
        gMapFloorState.flags = flags;
        door = GetMapEventDoor(event[0]);
        MarkEventRoomDone(door);
        CreateMapRoom(door->returnRoom, NULL);
        SetCurrentMapRoom(door->returnRoom, door->returnSide);
        gMapFloorState.eventStep++;

        if (event[4] == MAP_ROOM_EVENT_END) {
            exitRoom = GetMapFloorRoom(GetMapFloorDef(gGameState.floor)->exitRoom);
            flags = exitRoom->flags & ~FLOOR_ROOM_FLAG_LOCKED;
            exitRoom->flags = flags;
            gMapFloorState.flags |= FLOOR_FLAG_EXIT_UNLOCKED;
            SetWorldJiminyFlags();
        }
    }
}

void AdvanceToExitHall() {
    gMapFloorState.progress++;
    SetCurrentMapRoom(MAP_ROOM_EXIT_HALL, MAP_DOOR_SIDE_NONE);
}

u8 GetEventStepKeyKind() {
    u8* event = GetMapRoomEvent(gMapFloorState.eventStep);
    const EventKeyList* list = &gEventKeyLists[GetMapEventDoor(*event)->keyList];
    EventKey* key;

    list += *event;
    key = list->keys;

    while (key->kind == MAP_CARD_NONE) {
        key++;
    }

    return key->kind;
}

u8 GetCurrentEventDoorKeyKind() {
    if (SelectEventDoor(gMapRoomState->doorRoom, gMapRoomState->doorSide)) {
        return GetEventKey(0)->kind;
    }

    return MAP_CARD_NONE;
}

u8 SelectCurrentEventDoor() {
    return SelectEventDoor(gMapRoomState->doorRoom, gMapRoomState->doorSide);
}

u8 GetEventRoomKind(u8 room) {
    MapEventDoor* door = GetMapEventDoor(0);

    while (door->kind != EVENT_DOOR_END) {
        if (door->room == room) {
            return door->kind;
        }

        door++;
    }

    return EVENT_DOOR_NONE;
}

s32 GetMapRoomCardValue(u8 room) {
    u8* base;
    u8* roomBase;

    if ((s32)gMapRoomState->flags < 0) {
        return 0;
    }

    base = (u8*)&gMapFloorState;
    roomBase = base + room * 0x10;

    return roomBase[0x26];
}

void SetCardlessRoomType(u8 room) {
    MapFloorRoom* floorRoom = GetMapFloorRoom(room);
    MapEventDoor* door = GetMapEventDoor(0);

    while (door->kind != EVENT_DOOR_END) {
        if (door->room == room) {
            if (door->kind == EVENT_DOOR_HIDDEN_CHAMBER) {
                floorRoom->cardValue = 0;
                floorRoom->nameId = ROOM_NAME_HIDDEN_CHAMBER;
                floorRoom->roomType = ROOM_TYPE_HIDDEN_CHAMBER;
                return;
            }

            gMapFloorState.flags |= FLOOR_FLAG_EVENT_ROOM_OPEN;
            floorRoom->cardValue = 0;
            floorRoom->nameId = ROOM_NAME_UNKNOWN_PLACE;
            floorRoom->roomType = ROOM_TYPE_PLAIN;
        }

        door++;
    }

    if (GetMapFloorDef(gGameState.floor)->exitRoom != room) {
        floorRoom->cardValue = 0;
        floorRoom->nameId = ROOM_NAME_UNKNOWN_PLACE;
        floorRoom->roomType = ROOM_TYPE_PLAIN;
        return;
    }

    floorRoom->cardValue = 0;
    floorRoom->nameId = MAP_CARD_MOMENTS_REPRIEVE;
    floorRoom->roomType = ROOM_TYPE_EXIT_ROOM;
}

u8 GetRandomRoomType() {
    if ((gGameState.flags & GAME_FLAG_RIKU) == 0) {
        return GetRandom() % 21 + ROOM_TYPE_TEEMING_DARKNESS;
    }

    return gRikuRoomTypes[GetRandom() % 13];
}

void CreateMapRoom(u8 room, MapCardAttributes* card) {
    MapFloorRoom* floorRoom = GetMapFloorRoom(room);
    const u8* row;
    const u8* anim;

    if (card == NULL && (floorRoom->flags & FLOOR_ROOM_FLAG_CREATED) != 0) {
        return;
    }

    floorRoom->flags &= ~FLOOR_ROOM_FLAG_CHEST_OPENED;
    floorRoom->flags &= ~FLOOR_ROOM_FLAG_SHOP_VISITED;
    floorRoom->flags |= FLOOR_ROOM_FLAG_CREATED;
    floorRoom->seed = gFrameCounter * gFrameCounter;

    if (card != NULL) {
        row = gMapRoomCodes[card->kind];
        floorRoom->cardValue = card->value;
        floorRoom->nameId = row[0];

        if (row[1] != ROOM_TYPE_RANDOM) {
            floorRoom->roomType = row[1];
        } else {
            floorRoom->roomType = GetRandomRoomType();
        }
    } else {
        SetCardlessRoomType(room);
    }

    anim = gMapRoomShapes[floorRoom->roomType];
    floorRoom->enemiesLeft = anim[2];
    floorRoom->przCardsLeft = anim[6];
}

void LoadMapRoomState(MapRoomState* state, u8 room) {
    MapFloorRoom* floorRoom = GetMapFloorRoom(room);
    const u8* row;
    u16 flags;

    flags = floorRoom->flags | FLOOR_ROOM_FLAG_VISITED;
    floorRoom->flags = flags;
    SeedRandom(floorRoom->seed);
    gMapRoomState->nameId = floorRoom->nameId;
    gMapRoomState->roomType = floorRoom->roomType;

    if (!gMapChkUseParams) {
        row = gMapRoomShapes[floorRoom->roomType];
        gGameState.roomEffect = row[5];
        LoadMapForm(row[0]);
    }
}

void SetCurrentMapRoom(u8 room, u8 side) {
    gMapFloorState.room = room;
    gMapFloorState.entrySide = GetOppositeDoorSide(side);
    UpdateWorldFriendFlags();
}

u8 GetProgressFloor() {
    if ((gGameState.flags & GAME_FLAG_RIKU) != 0) {
        if (gMapFloorState.progress > 0x16) {
            return 11;
        }

        if (gMapFloorState.progress > 0x13) {
            return 10;
        }

        if (gMapFloorState.progress > 0x11) {
            return 9;
        }

        if (gMapFloorState.progress > 0x0F) {
            return 8;
        }

        if (gMapFloorState.progress > 0x0D) {
            return 7;
        }

        if (gMapFloorState.progress > 0x0B) {
            return 6;
        }

        if (gMapFloorState.progress > 0x09) {
            return 5;
        }

        if (gMapFloorState.progress > 0x07) {
            return 4;
        }

        if (gMapFloorState.progress > 0x05) {
            return 3;
        }

        if (gMapFloorState.progress > 0x03) {
            return 2;
        }

        if (gMapFloorState.progress <= 0x01) {
            return 0;
        }

        return 1;
    }

    if (gMapFloorState.progress > 0x18) {
        return 12;
    }

    if (gMapFloorState.progress > 0x15) {
        return 11;
    }

    if (gMapFloorState.progress > 0x13) {
        return 10;
    }

    if (gMapFloorState.progress > 0x11) {
        return 9;
    }

    if (gMapFloorState.progress > 0x0F) {
        return 8;
    }

    if (gMapFloorState.progress > 0x0D) {
        return 7;
    }

    if (gMapFloorState.progress > 0x0B) {
        return 6;
    }

    if (gMapFloorState.progress > 0x09) {
        return 5;
    }

    if (gMapFloorState.progress > 0x07) {
        return 4;
    }

    if (gMapFloorState.progress > 0x05) {
        return 3;
    }

    if (gMapFloorState.progress > 0x03) {
        return 2;
    }

    if (gMapFloorState.progress <= 0x01) {
        return 0;
    }

    return 1;
}

void* GetMapWorldName(u8 index) {
#ifdef VERSION_EU
    return GetLocalizedString(gMapWorldNames[index]);
#else
    return (void*)gMapWorldNames[index];
#endif
}

void EnterEntranceHall() {
    SetCurrentMapRoom(MAP_ROOM_ENTRANCE_HALL, MAP_DOOR_SIDE_DOWN_LEFT);
    RequestMapMode();
}

void EnterExitHall() {
    u8 eventId;
    u16 flags;

    if ((gMapFloorState.flags & FLOOR_FLAG_EXIT_EVENT_DONE) != 0) {
        eventId = MAP_EVENT_NONE;
    } else {
        if ((gGameState.flags & GAME_FLAG_RIKU) != 0) {
            eventId = sRikuWorldExitEvents[gGameState.floor];
        } else {
            eventId = sSoraWorldExitEvents[gGameState.floor];
        }
    }

    if (eventId != MAP_EVENT_NONE) {
        gGameState.world = 0;
        gGameState.battleStage = BATTLE_STAGE_CASTLE_OBLIVION;
        gGameState.roomEffect = ROOM_EFFECT_NONE;

        if ((gGameState.flags & GAME_FLAG_RIKU) != 0) {
            InitRikuDeckForWorld(0);
        }

        RequestEventMode(eventId);
    } else {
        if ((gMapFloorState.flags & FLOOR_FLAG_EXIT_EVENT_DONE) == 0) {
            flags = gMapFloorState.flags | FLOOR_FLAG_EXIT_EVENT_DONE;
            gMapFloorState.flags = flags;
            gMapFloorState.progress++;
        }

        SetCurrentMapRoom(MAP_ROOM_EXIT_HALL, MAP_DOOR_SIDE_UP_RIGHT);
        RequestMapMode();
    }
}

void InitMapFloorState(u8 room, u8 entrySide) {
    s32 i;
    u16 flags;

    gMapFloorState.flags = gGameState.floors[gGameState.floor].flags;
    gMapFloorState.world = gGameState.floors[gGameState.floor].world;
    gMapFloorState.eventStep = gGameState.floors[gGameState.floor].eventStep;
    gMapFloorState.room = room;
    gMapFloorState.entrySide = entrySide;

    for (i = 0; i <= 3; i++) {
        gMapFloorState.unk_18[i] = 0;
        gMapFloorState.eventKeyProgress[i].paid = 0;
        gMapFloorState.eventKeyProgress[i].remaining = 0;
    }

    for (i = 0; i < 32; i++) {
        gMapFloorState.rooms[i].flags = 0;
        gMapFloorState.rooms[i].seed = 0;
        gMapFloorState.rooms[i].nameId = 0;
        gMapFloorState.rooms[i].cardValue = 0;
        gMapFloorState.rooms[i].roomType = 0;
    }

    gGameState.mapMenuCursor = 0xFF;
    flags = gMapFloorState.flags | FLOOR_FLAG_SHOW_FLOOR_NAME;
    gMapFloorState.flags = flags;
}

void MarkPastEventRoomsDone() {
    s32 i;

    for (i = 0; i < gMapFloorState.eventStep; i++) {
        MarkEventRoomDone(GetMapEventDoor(*GetMapRoomEvent(i)));
    }
}

void GoToFloor(u8 floor) {
    gGameState.floor = floor;
    InitMapFloorState(MAP_ROOM_ENTRANCE_HALL, MAP_DOOR_SIDE_UP_RIGHT);
}

void GoToNextFloor() {
    gGameState.floor++;
    InitMapFloorState(MAP_ROOM_ENTRANCE_HALL, MAP_DOOR_SIDE_DOWN_LEFT);
}

void GoToPreviousFloor() {
    gGameState.floor--;
    InitMapFloorState(MAP_ROOM_EXIT_HALL, MAP_DOOR_SIDE_UP_RIGHT);
}

void WarpToFloor(u8 floor) {
    u16 flags;

    ClearFieldResume();
    StoreMapFloorState();
    GoToFloor(floor);
    gMapFloorState.room = MAP_ROOM_ENTRANCE_HALL;
    gMapFloorState.entrySide = MAP_DOOR_SIDE_NONE;
    flags = gMapFloorState.flags | FLOOR_FLAG_WARP_IN;
    gMapFloorState.flags = flags;
    RequestMapMode();
}

void SetFloorWorld(u8 world) {
    gMapFloorState.world = world;
    gGameState.floors[gGameState.floor].world = world;
}

void EnterFloorWorld() {
    const MapFloorDef* floorDef = GetMapFloorDef(gGameState.floor);
    MapFloorRoom* exitRoom;
    u16 flags;

    if (gGameState.floor == 13) {
        gGameState.floor = 0;
    }

    if (gMapFloorState.room == MAP_ROOM_EXIT_HALL) {
        SetCurrentMapRoom(floorDef->exitRoom, MAP_DOOR_SIDE_DOWN_LEFT);
    } else {
        SetCurrentMapRoom(floorDef->entryRoom, MAP_DOOR_SIDE_UP_RIGHT);
    }

    MarkPastEventRoomsDone();

    if ((gMapFloorState.flags & FLOOR_FLAG_EXIT_UNLOCKED) == 0) {
        exitRoom = GetMapFloorRoom(floorDef->exitRoom);
        flags = exitRoom->flags | FLOOR_ROOM_FLAG_LOCKED;
        exitRoom->flags = flags;
    }

    CreateMapRoom(gMapFloorState.room, NULL);
}

void StoreMapFloorState() {
    gGameState.floors[gGameState.floor].flags = gMapFloorState.flags;
    gGameState.floors[gGameState.floor].world = gMapFloorState.world;
    gGameState.floors[gGameState.floor].eventStep = gMapFloorState.eventStep;
}

void InitStartFloor(u8 floor, u8 world) {
    GoToFloor(floor);
    SetFloorWorld(world);

    if (floor == 0) {
        gMapFloorState.progress = 0;
        gMapFloorState.flags &= ~FLOOR_FLAG_SHOW_FLOOR_NAME;
    }
}

void ResetMapFloors() {
    s32 i;

    for (i = 0; i < 13; i++) {
        gGameState.floors[i].flags = 0;
        gGameState.floors[i].world = 0;
        gGameState.floors[i].eventStep = 0;
    }

    gMapFloorState.progress = 0;

    if ((gGameState.flags & GAME_FLAG_RIKU) == 0) {
        InitSoraDecks();
    }

    GoToFloor(0);
}

MapDoor* GetMapDoor(u8 side) {
    return MapGetDoor(side);
}

MapCell* FieldCellAt(s32 x, s32 y) {
    s16 cellX = x / 0x2000;
    s16 cellY = y / 0x1000;

    if ((s32)gMapRoomState->flags < 0) {
        return MapFixCellAt(cellX, cellY);
    }

    return MapCellAt(cellX, cellY);
}

u8 IsFldPosBlocked(FldPos* pos) {
    s32 y = pos->y + pos->ground;
    MapCell* cell = FieldCellAt(pos->x, y);

    if (cell == NULL) {
        return 1;
    }

    if (cell->upperZ >= pos->z && cell->lowerZ != MAP_Z_BOTTOM) {
        return 0;
    }

    return MapCellMaskBitAt(cell, pos->x, y);
}

u8 GetMapWalkOutMode() {
    if (gMapRoomState->flags & ROOM_FLAG_WALK_OUT) {
        if (gMapFloorState.world != 0) {
            return 2;
        }

        if ((gGameState.flags & GAME_FLAG_RIKU) == 0 && gGameState.floor == 12) {
            SetFloorWorld(WORLD_CASTLE_OBLIVION);
            return 2;
        }

        return 1;
    }

    return 0;
}

void EndMapWalkOut() {
    gMapRoomState->flags &= ~ROOM_FLAG_WALK_OUT;
}

u8 FldPosRevertIfBlocked(FldPos* pos, s32 x, s32 y) {
    s32 old;

    if (IsFldPosBlocked(pos) != 0) {
        pos->x = x;
        pos->y = y;
        return TRUE;
    }

    old = pos->ground;
    pos->ground = GetFldPosGround(pos);

    if (old != pos->ground) {
        if (IsFldPosBlocked(pos) != 0) {
            pos->x = x;
            pos->y = y;
            pos->ground = old;
            return TRUE;
        }
    }

    return FALSE;
}

u8 MapFindOpenDoor(FldPos* pos) {
    s32 i;
    u16 cellX;
    u16 cellY;
    MapDoor* door;
    u8 found = FALSE;

    if ((s32)gMapRoomState->flags < 0) {
        return FALSE;
    }

    if ((gGameState.progression.tutorialFlags & TUTORIAL_FLAG_ROOM_CREATE) == 0) {
        return FALSE;
    }

    if (pos->z != pos->ground) {
        return FALSE;
    }

    cellX = (pos->x >> 8) / 32;
    cellY = ((pos->y + pos->z) >> 8) / 16;

    for (i = 0; i <= 3; i++) {
        door = GetMapDoor(i);

        if ((door->flags & DOOR_FLAG_PRESENT) != 0 && (door->flags & (DOOR_FLAG_OPEN | DOOR_FLAG_SEALED)) == DOOR_FLAG_OPEN && door->cellX == cellX && door->cellY == cellY) {
            gMapRoomState->doorRoom = door->room;
            gMapRoomState->doorSide = door->side;
            found = TRUE;
            break;
        }
    }

    return found;
}

u8 IsAtTargetDoor(FldPos* pos) {
    s32 i;
    u16 cellX;
    u16 cellY;
    MapDoor* door;

    if ((s32)gMapRoomState->flags < 0) {
        return gMapRoomState->flags >> 9 & 1;
    }

    if (pos->z != pos->ground) {
        return 0;
    }

    cellX = (pos->x >> 8) / 32;
    cellY = ((pos->y + pos->z) >> 8) / 16;

    for (i = 0; i <= 3; i++) {
        door = GetMapDoor(i);

        if ((door->flags & DOOR_FLAG_PRESENT) != 0 && (door->flags & (DOOR_FLAG_OPEN | DOOR_FLAG_SEALED)) == DOOR_FLAG_OPEN && door->cellX == cellX && door->cellY == cellY
                && door->room == gMapRoomState->doorRoom && door->side == gMapRoomState->doorSide) {
            return 1;
        }
    }

    return 0;
}

u8 GetFldPosClimbDir(FldPos* pos) {
    MapCell* cell = FieldCellAt(pos->x, pos->y + pos->ground);

    if (cell->flags & MAP_CELL_FLAG_STAIRS) {
        switch (cell->type) {
        case MAP_CELL_TYPE_LEFT_WALL_TOP:
        case MAP_CELL_TYPE_LEFT_WALL_BASE:
        case MAP_CELL_TYPE_LEFT_WALL_FACE:
            return FLD_CLIMB_DIR_UP_LEFT;
        case MAP_CELL_TYPE_RIGHT_WALL_TOP:
        case MAP_CELL_TYPE_RIGHT_WALL_BASE:
        case MAP_CELL_TYPE_RIGHT_WALL_FACE:
            return FLD_CLIMB_DIR_UP_RIGHT;
        case MAP_CELL_TYPE_BACK_WALL_FACE:
            return FLD_CLIMB_DIR_NONE;
        }
    }

    return FLD_CLIMB_DIR_NONE;
}

s32 FieldFloorAt(s32 x, s32 y, s32 z) {
    MapCell* cell;
    s32 floorZ;

    y += z;
    cell = FieldCellAt(x, y);

    if (cell == NULL) {
        return 0;
    }

    if (cell->type == MAP_CELL_TYPE_LEFT_WALL_BASE || cell->type == MAP_CELL_TYPE_RIGHT_WALL_BASE) {
        if (MapCellMaskBitAt(cell, x, y) != 0) {
            floorZ = cell->lowerZ;
        } else {
            floorZ = cell->upperZ;
        }
    } else {
        floorZ = cell->lowerZ;
    }

    return floorZ;
}

u8 gWorldBattleStages[14] = {
    BATTLE_STAGE_CASTLE_OBLIVION,
    BATTLE_STAGE_AGRABAH,
    BATTLE_STAGE_ATLANTICA,
    BATTLE_STAGE_OLYMPUS_COLISEUM,
    BATTLE_STAGE_WONDERLAND,
    BATTLE_STAGE_MONSTRO,
    BATTLE_STAGE_HALLOWEEN_TOWN,
    BATTLE_STAGE_NEVER_LAND,
    BATTLE_STAGE_HOLLOW_BASTION,
    BATTLE_STAGE_DESTINY_ISLANDS,
    BATTLE_STAGE_TRAVERSE_TOWN,
    BATTLE_STAGE_TWILIGHT_TOWN,
    BATTLE_STAGE_CASTLE_OBLIVION,
};

u8 gRikuRoomTypes[14] = {
    ROOM_TYPE_TEEMING_DARKNESS,
    ROOM_TYPE_TRANQUIL_DARKNESS,
    ROOM_TYPE_LOOMING_DARKNESS,
    ROOM_TYPE_SLEEPING_DARKNESS,
    ROOM_TYPE_MOMENTS_REPRIEVE,
    ROOM_TYPE_FEEBLE_DARKNESS,
    ROOM_TYPE_ALMIGHTY_DARKNESS,
    ROOM_TYPE_MARTIAL_WAKING,
    ROOM_TYPE_ALCHEMIC_WAKING,
    ROOM_TYPE_MEETING_GROUND,
    ROOM_TYPE_STRONG_INITIATIVE,
    ROOM_TYPE_LASTING_DAZE,
    ROOM_TYPE_STAGNANT_SPACE,
};

const MapNameText* gMapWorldNames[14] = {
    LOCALIZED(gWorldNameCastleOblivionHall),
    LOCALIZED(gWorldNameAgrabah),
    LOCALIZED(gWorldNameAtlantica),
    LOCALIZED(gWorldNameOlympusColiseum),
    LOCALIZED(gWorldNameWonderland),
    LOCALIZED(gWorldNameMonstro),
    LOCALIZED(gWorldNameHalloweenTown),
    LOCALIZED(gWorldNameNeverLand),
    LOCALIZED(gWorldNameHollowBastion),
    LOCALIZED(gWorldNameDestinyIslands),
    LOCALIZED(gWorldNameTraverseTown),
    LOCALIZED(gWorldNameTwilightTown),
    LOCALIZED(gWorldNameCastleOblivion),
    LOCALIZED(gWorldName100AcreWood),
};
