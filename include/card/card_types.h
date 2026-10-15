#ifndef GUARD_CARD_TYPES_H
#define GUARD_CARD_TYPES_H

#include "types.h"

#define DECK_SIZE 99
#define DECK_ANY 3
#define CARD_ID_MASK 0xFFF
#define CARD_COLLECTION_EMPTY 0xFFF
#define CARD_NONE 0xFFFF

enum CardIdSentinel {
    CARD_ID_RELOAD = 0xFFFE,
    CARD_ID_NONE = 0xFFFF
};

enum CardFlag {
    CARD_FLAG_IN_DECK_1 = 0x1000,
    CARD_FLAG_IN_DECK_2 = 0x2000,
    CARD_FLAG_IN_DECK_3 = 0x4000,
    CARD_FLAG_IN_ANY_DECK = 0x7000,
    CARD_FLAG_PREMIUM = 0x8000
};

typedef struct Deck {
    u16 cards[DECK_SIZE];
    u8 name[0x14];
    u16 cpCost;
    u16 cardCount;
    u16 unk_DE;
} Deck;

enum CardDefFlag {
    CARD_DEF_FLAG_ITEM = 0x2,
    CARD_DEF_FLAG_SUMMON = 0x4,
    CARD_DEF_FLAG_FRIEND = 0x8,
    CARD_DEF_FLAG_GIMMICK = 0x10
};

enum CardCategory {
    CARD_CATEGORY_ATTACK,
    CARD_CATEGORY_MAGIC,
    CARD_CATEGORY_ITEM,
    CARD_CATEGORY_ENEMY
};

typedef struct CardDef {
    void* gfx;
    void* tiles;
    void* palette;
    const void* name;
    void* gfx2;
    void* tiles2;
    void* palette2;
    u16 kind;
    u16 flags;
    u8 value;
    u32 move;
    u16 catalogNumber;
    u8 category;
    u16 cpCost;
    u8 unk_2E[0x06];
} CardDef;

typedef struct CardBack {
    void* gfx;
    void* gfx2;
    void* gfx3;
    void* tiles;
    void* tiles2;
    void* tiles3;
} CardBack;

enum CardBackColor {
    CARD_BACK_RED,
    CARD_BACK_BLUE,
    CARD_BACK_GREEN,
    CARD_BACK_BLACK,
    CARD_BACK_WHITE
};

typedef struct CardStat {
    u16 kind;
    u16 flags;
    u8 value;
    u32 move;
    u16 catalogNumber;
    u8 category;
    u16 cpCost;
    u8 unk_12[0x06];
} CardStat;

#endif
