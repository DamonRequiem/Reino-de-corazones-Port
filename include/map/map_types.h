#ifndef GUARD_MAP_TYPES_H
#define GUARD_MAP_TYPES_H

#include "types.h"
#include "fld_types.h"
#include "taskpool.h"

enum EventKeyRule {
    EVENT_KEY_RULE_NONE,
    EVENT_KEY_RULE_AT_LEAST,
    EVENT_KEY_RULE_AT_MOST,
    EVENT_KEY_RULE_EXACT,
    EVENT_KEY_RULE_TOTAL
};

typedef struct EventKey {
    u8 kind;
    u8 color;
    u8 rule;
    u8 value;
} EventKey;

typedef struct EventKeyList {
    u8 count;
    EventKey* keys;
} EventKeyList;

enum MapRoomId {
    MAP_ROOM_TUTORIAL = 0xFC,
    MAP_ROOM_EXIT_HALL = 0xFD,
    MAP_ROOM_ENTRANCE_HALL = 0xFE,
    MAP_ROOM_NONE = 0xFF
};

#define MAP_EVENT_NONE 0xFF

enum DoorFlag {
    DOOR_FLAG_PRESENT = 0x1,
    DOOR_FLAG_OPEN = 0x2,
    DOOR_FLAG_SEALED = 0x8,
    DOOR_FLAG_EVENT = 0x10
};

enum RoomFlag {
    ROOM_FLAG_BG1_FROZEN = 0x1,
    ROOM_FLAG_START_BATTLE = 0x2,
    ROOM_FLAG_ENEMY_STRUCK = 0x4,
    ROOM_FLAG_PRIZE_CARD_ACTIVE = 0x10,
    ROOM_FLAG_NO_RANDOM_PRIZE = 0x20,
    ROOM_FLAG_ATTACK_HIT = 0x80,
    ROOM_FLAG_WALK_OUT = 0x100,
    ROOM_FLAG_ENTER_WORLD = 0x200,
    ROOM_FLAG_EXIT_NEXT_FLOOR = 0x400,
    ROOM_FLAG_EXIT_PREV_FLOOR = 0x800,
    ROOM_FLAG_HIDE_PLAYER = 0x1000,
    ROOM_FLAG_SAVE_MENU_OPEN = 0x2000,
    ROOM_FLAG_TUTORIAL_ACTIVE = 0x4000
};

#define ROOM_FLAG_DOOR(side) (0x1000000 << (side))
#define ROOM_FLAG_FIXED_ROOM 0x80000000
enum MapCellFlag {
    MAP_CELL_FLAG_EDGE_LEFT = 0x4,
    MAP_CELL_FLAG_EDGE_RIGHT = 0x8,
    MAP_CELL_FLAG_CORNER = 0x10,
    MAP_CELL_FLAG_STAIRS = 0x20,
    MAP_CELL_FLAG_JUMP_PAD = 0x40,
    MAP_CELL_FLAG_CHEST = 0x80,
    MAP_CELL_FLAG_GMK_RESERVED = 0x100,
    MAP_CELL_FLAG_DOOR_WALL = 0x400,
    MAP_CELL_FLAG_KEEP_CLEAR = 0x800
};

enum FloorRoomFlag {
    FLOOR_ROOM_FLAG_CREATED = 0x1,
    FLOOR_ROOM_FLAG_VISITED = 0x2,
    FLOOR_ROOM_FLAG_LOCKED = 0x4,
    FLOOR_ROOM_FLAG_EVENT_DONE = 0x8,
    FLOOR_ROOM_FLAG_CHEST_OPENED = 0x10,
    FLOOR_ROOM_FLAG_SHOP_VISITED = 0x20
};

enum RoomType {
    ROOM_TYPE_PLAIN,
    ROOM_TYPE_TEEMING_DARKNESS,
    ROOM_TYPE_TRANQUIL_DARKNESS,
    ROOM_TYPE_GUARDED_TROVE,
    ROOM_TYPE_LOOMING_DARKNESS,
    ROOM_TYPE_SLEEPING_DARKNESS,
    ROOM_TYPE_MOMENTS_REPRIEVE,
    ROOM_TYPE_FEEBLE_DARKNESS,
    ROOM_TYPE_ALMIGHTY_DARKNESS,
    ROOM_TYPE_CALM_BOUNTY,
    ROOM_TYPE_FALSE_BOUNTY,
    ROOM_TYPE_MOOGLE_ROOM,
    ROOM_TYPE_SORCEROUS_WAKING,
    ROOM_TYPE_MARTIAL_WAKING,
    ROOM_TYPE_ALCHEMIC_WAKING,
    ROOM_TYPE_MEETING_GROUND,
    ROOM_TYPE_STRONG_INITIATIVE,
    ROOM_TYPE_LASTING_DAZE,
    ROOM_TYPE_STAGNANT_SPACE,
    ROOM_TYPE_PREMIUM_ROOM,
    ROOM_TYPE_WHITE_ROOM,
    ROOM_TYPE_BLACK_ROOM,
    ROOM_TYPE_HIDDEN_CHAMBER,
    ROOM_TYPE_EXIT_ROOM,
    ROOM_TYPE_RANDOM = 25
};

enum RoomEffect {
    ROOM_EFFECT_NONE,
    ROOM_EFFECT_ALMIGHTY_DARKNESS,
    ROOM_EFFECT_FEEBLE_DARKNESS,
    ROOM_EFFECT_STRONG_INITIATIVE,
    ROOM_EFFECT_LASTING_DAZE,
    ROOM_EFFECT_MEETING_GROUND,
    ROOM_EFFECT_PREMIUM_ROOM,
    ROOM_EFFECT_SORCEROUS_WAKING,
    ROOM_EFFECT_ALCHEMIC_WAKING,
    ROOM_EFFECT_MARTIAL_WAKING,
    ROOM_EFFECT_ENEMY_CARD_DROPS
};

enum MapPrizeKind {
    MAP_PRIZE_HP_SMALL,
    MAP_PRIZE_HP_LARGE,
    MAP_PRIZE_MOOGLE_POINTS_SMALL,
    MAP_PRIZE_MOOGLE_POINTS_LARGE
};

enum MapDoorSide {
    MAP_DOOR_SIDE_UP_RIGHT,
    MAP_DOOR_SIDE_DOWN_LEFT,
    MAP_DOOR_SIDE_DOWN_RIGHT,
    MAP_DOOR_SIDE_UP_LEFT,
    MAP_DOOR_SIDE_NONE = 5
};

typedef struct MapDoor {
    u16 flags;
    u16 cellX;
    u16 cellY;
    u8 side;
    u8 room;
} MapDoor;

typedef struct MapRoomState {
    u32 flags;
    u16 cols;
    u16 rows;
    u16 topRow;
    u16 bottomRow;
    u8 nameId;
    u8 roomType;
    u8 battleId;
    u8 doorRoom;
    u8 doorSide;
    FldObj* door;
    u8 jumpGmkAngle;
    s32 jumpGmkHeight;
    u8 attackActive;
    s32 attackX;
    s32 attackY;
    s32 attackZ;
    TaskPool tasks;
} MapRoomState;

enum MapCellType {
    MAP_CELL_TYPE_FLOOR,
    MAP_CELL_TYPE_BACK_WALL_TOP,
    MAP_CELL_TYPE_BACK_WALL_BASE,
    MAP_CELL_TYPE_LEFT_WALL_TOP,
    MAP_CELL_TYPE_LEFT_WALL_BASE,
    MAP_CELL_TYPE_RIGHT_WALL_TOP,
    MAP_CELL_TYPE_RIGHT_WALL_BASE,
    MAP_CELL_TYPE_BACK_WALL_FACE,
    MAP_CELL_TYPE_LEFT_WALL_FACE,
    MAP_CELL_TYPE_RIGHT_WALL_FACE,
    MAP_CELL_TYPE_NONE,
    MAP_CELL_TYPE_UNSET
};

typedef struct MapCell {
    u16 flags;
    u8 type;
    u8 bg3Piece;
    u8 bg2Piece;
    u8 bg1Piece;
    s32 upperZ;
    s32 lowerZ;
    void* maskTable;
    u16* bg3Map;
    u16* bg2Map;
    u16* bg1Map;
} MapCell;

#define MAP_Z_TOP (-0x100000)
#define MAP_Z_BOTTOM 0x100000

#define EVENT_KEY_LIST_NONE 0xFF

enum EventDoorKind {
    EVENT_DOOR_NONE,
    EVENT_DOOR_EVENT_ROOM,
    EVENT_DOOR_HIDDEN_CHAMBER,
    EVENT_DOOR_WALK_IN,
    EVENT_DOOR_BOSS_ROOM,
    EVENT_DOOR_END
};

typedef struct MapEventDoor {
    u8 kind;
    u8 keyList;
    u8 room;
    u8 side;
    u8 returnRoom;
    u8 returnSide;
    u8 unk_06[0x02];
} MapEventDoor;

typedef struct MapFloorRoom {
    u16 flags;
    u32 seed;
    u8 nameId;
    u8 roomType;
    u8 cardValue;
    u8 enemiesLeft;
    u8 przCardsLeft;
} MapFloorRoom;

typedef struct EventKeyProgress {
    u8 paid;
    u8 remaining;
    u8 unk_02[0x02];
} EventKeyProgress;

typedef struct MapFloorState {
    u8 progress;
    u16 flags;
    u8 world;
    u8 eventStep;
    u8 room;
    u8 entrySide;
    EventKeyProgress eventKeyProgress[4];
    u8 unk_18[0x04];
    MapFloorRoom rooms[32];
} MapFloorState;

typedef struct MapFormDef {
    u8 layout;
    u8 minWidth;
    u8 maxWidth;
    u8 minHeight;
    u8 maxHeight;
    u8 minDepth;
    u8 maxDepth;
    u8 unk_07;
} MapFormDef;

#endif
