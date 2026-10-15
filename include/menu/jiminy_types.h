#ifndef GUARD_JIMINY_TYPES_H
#define GUARD_JIMINY_TYPES_H

#include "types.h"
#include "anim.h"
#include "obj.h"
#include "text_types.h"
#include "macros.h"

#ifdef VERSION_US
typedef u16 JiminyTextChar;
#else
typedef u8 JiminyTextChar;
#endif

#ifdef VERSION_EU
typedef LocalizedText JiminyLocalizedName;

typedef struct JiminyLocalizedText {
    JiminyTextChar** lines[5];
    u16 lineCounts[5];
} JiminyLocalizedText;

STATIC_ASSERT(sizeof(JiminyLocalizedName) == 20, JiminyLocalizedNameSize);
STATIC_ASSERT(sizeof(JiminyLocalizedText) == 32, JiminyLocalizedTextSize);
#endif

typedef struct JiminyPair {
    u16 cursor;
    u16 cursorRow;
} JiminyPair;

typedef struct JiminyDetail {
    const void* name;
    const void* text;
#ifndef VERSION_EU
    s16 lineCount;
#endif
    void* sprite;
    void* palette;
    void* tiles;
    void* sprite2;
    void* palette2;
    void* tiles2;
    void* bgMap;
    void* bgPalette;
    void* bgTiles;
    s16 paletteSize;
    u16 tileSize;
    s16 x;
    s16 y;
} JiminyDetail;

typedef struct JiminyLine {
    TextSlot textSlots[48];
} JiminyLine;

#define JIMINY_ENTRY_NONE (-1)

typedef struct JiminyEntry {
    void* map;
    const void* names;
    s16 count;
    s16 parent;
    const u16* children;
    const u16* flags;
    s32 detail;
} JiminyEntry;

enum JiminyFlag {
    JIMINY_FLAG_SHOW_MESSAGE = 0x1,
    JIMINY_FLAG_SHOW_TITLE = 0x2,
    JIMINY_FLAG_SHOW_CURSOR = 0x4,
    JIMINY_FLAG_SCROLL_UP = 0x8,
    JIMINY_FLAG_SCROLL_DOWN = 0x10
};

typedef struct JiminyWork {
    s32 state;
    void* tiles;
    ObjPalette* palette;
    void* tiles2;
    ObjPalette* palette2;
    ObjPalette* palette3;
    void* tiles3;
    ObjPalette* palette4;
    void* tiles4;
    ObjPalette* palette5;
    void* tiles5;
    ObjPalette* palette6;
    void* tiles6;
    ObjPalette* palette7;
    void* tiles7;
    ObjPalette* palette8;
    void* tiles8;
    ObjPalette* palette9;
    s16 stateTimer;
    s16 steps;
    s32 x3;
    s32 y3;
    s32 y4;
    s32 x4;
    s32 y5;
    JiminyLine lines[8];
    u8 textSlotCounts[8];
    u8 rowStates[8];
    u8 shownChars;
    u8 charCount;
    s16 cursor;
    s16 cursorRow;
    s16 itemCount;
    s16 visibleRows;
    AnimState anim;
    AnimState anim2;
    u16 flags;
    s16 listX;
    s16 listY;
    s16 rowHeight;
    const u16* const* itemTexts;
    const u16* itemFlags;
    const u16* itemChildren;
    s16 moveDelay;
    s16 x;
    s16 y;
    s16 x2;
    s16 y2;
    const JiminyDetail* detail;
    u16 detailCount;
    s16 detailIndex;
    s16 nextDetail;
    s16 prevDetail;
    JiminyPair pairs[21];
    s32 entry;
    u32 detailLayout;
    s32 detailTable;
    s32 unk_D38;
    u16 detailTimer;
    u16 frame;
#ifdef VERSION_EU
    const u16* resolvedTexts[100];
#endif
} JiminyWork;

#endif
