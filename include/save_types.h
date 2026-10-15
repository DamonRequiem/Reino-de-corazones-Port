#ifndef GUARD_SAVE_TYPES_H
#define GUARD_SAVE_TYPES_H

#include "types.h"
#include "card_types.h"
#include "macros.h"

#define SAVE_FILES 4
#define SAVE_CARDS 999
#define SAVE_DECKS 3

#define SAVE_BAD_SIGNATURE 0
#define SAVE_BAD_CHECKSUM 1
#define SAVE_OK 2

enum SaveHeaderFlag {
    SAVE_HEADER_SORA_CLEAR = 0x1,
    SAVE_HEADER_RIKU_TITLE = 0x2,
    SAVE_HEADER_RIKU_CLEAR = 0x4
};

typedef struct SaveCommon {
    u32 flags;
    u8 progression[0x88];
    u16 availableWorlds;
    u16 hp;
    u8 floor;
    u8 world;
    u32 playTime;
} SaveCommon;

typedef struct SaveFileSummary {
    u8 floor;
    u8 world;
    u8 level;
    u32 playTime;
} SaveFileSummary;

typedef struct SaveHeaderData {
    u16 flags;
    u16 language;
    SaveFileSummary files[SAVE_FILES];
} SaveHeaderData;

enum FloorFlag {
    FLOOR_FLAG_CLEARED = 0x1,
    FLOOR_FLAG_ENTRY_EVENT_DONE = 0x2,
    FLOOR_FLAG_EXIT_EVENT_DONE = 0x4,
    FLOOR_FLAG_EVENT_ROOM_OPEN = 0x8,
    FLOOR_FLAG_LOGO_SHOWN = 0x10,
    FLOOR_FLAG_EXIT_UNLOCKED = 0x20,
    FLOOR_FLAG_CHAMBER_PRIZE_TAKEN = 0x40,
    FLOOR_FLAG_WARP_IN = 0x80,
    FLOOR_FLAG_SHOW_FLOOR_NAME = 0x100
};

typedef struct GameFloor {
    u16 flags;
    u8 world;
    u8 eventStep;
} GameFloor;

STATIC_ASSERT(sizeof(GameFloor) == 4, GameFloorSize);

typedef struct MapProgress {
    u8 world;
    u8 floor;
    u8 unk_02[0x02];
    u8 floorState[0x21C];
    GameFloor floors[13];
} MapProgress;

typedef struct SaveLargeSlice {
    u8 activeDeck;
    u8 mapCardCounts[0x10E];
    u16 cards[SAVE_CARDS];
    u16 cardCount;
    Deck decks[SAVE_DECKS];
} SaveLargeSlice;

typedef struct SaveSmallSlice {
    u8 mapCardCounts[0x10E];
    u8 unk_10E[2];
} SaveSmallSlice;

typedef struct SaveSliceE6C {
    u16 unk_00;
    u16 unk_02;
} SaveSliceE6C;

typedef struct SaveMoogleShop {
    u16 packBoughtFlags[32];
    u16 freePackFlags[2];
} SaveMoogleShop;

typedef struct SaveFileLarge {
    SaveCommon common;
    MapProgress shared;
    SaveLargeSlice large;
    SaveSliceE6C unk_E6C;
    u8 pooState[0x044];
    SaveMoogleShop moogleShop;
} SaveFileLarge;

typedef struct SaveFileSmall {
    SaveCommon common;
    MapProgress shared;
    SaveSmallSlice small;
} SaveFileSmall;

#endif
