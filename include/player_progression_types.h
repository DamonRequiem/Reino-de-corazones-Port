#ifndef GUARD_PLAYER_PROGRESSION_TYPES_H
#define GUARD_PLAYER_PROGRESSION_TYPES_H

#include "types.h"
#include "macros.h"

enum FriendFlag {
    FRIEND_FLAG_GOOFY = 0x1,
    FRIEND_FLAG_DONALD_DUCK = 0x2,
    FRIEND_FLAG_ALADDIN = 0x4,
    FRIEND_FLAG_ARIEL = 0x8,
    FRIEND_FLAG_JACK = 0x10,
    FRIEND_FLAG_PETER_PAN = 0x20,
    FRIEND_FLAG_THE_BEAST = 0x40,
    FRIEND_FLAG_THE_KING = 0x80
};

#define FRIEND_FLAGS_WORLD (FRIEND_FLAG_ALADDIN | FRIEND_FLAG_ARIEL | FRIEND_FLAG_JACK | FRIEND_FLAG_PETER_PAN | FRIEND_FLAG_THE_BEAST)

enum TutorialFlag {
    TUTORIAL_FLAG_WORLDSELECT = 0x1,
    TUTORIAL_FLAG_MAP_SELECT = 0x8,
    TUTORIAL_FLAG_SAVE_POINT = 0x10,
    TUTORIAL_FLAG_MAP = 0x20,
    TUTORIAL_FLAG_MAP_SELECT_EVENT_DOOR = 0x40,
    TUTORIAL_FLAG_MOOGLE_SHOP = 0x80,
    TUTORIAL_FLAG_WARP_POINT = 0x100,
    TUTORIAL_FLAG_ROOM_CREATE = 0x200,
    TUTORIAL_FLAG_MAP_STAIR = 0x400,
    TUTORIAL_FLAG_RIKU_DECK = 0x800,
    TUTORIAL_FLAG_RIKU_BATTLE = 0x1000,
    TUTORIAL_FLAG_MAP_BARREL = 0x2000
};

typedef struct PlayerProgression {
    s16 maxHp;
    s16 cp;
    s16 dp;
    s16 ap;
    u32 exp;
    u32 nextExp;
    u8 level;
    u64 learnedStocks;
    u64 learnedStocks2;
    u64 newStocks;
    u64 newStocks2;
    u64 obtainedCardKinds;
    u64 jiminyFlags[8];
    u32 mooglePoints;
    u16 levelMilestone;
    u16 tutorialFlags;
    u16 friendFlags;
    u16 savedFriendFlags;
} PlayerProgression;

STATIC_ASSERT(sizeof(PlayerProgression) == 0x88, PlayerProgressionSize);

#endif
