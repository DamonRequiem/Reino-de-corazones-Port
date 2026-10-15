#ifndef GUARD_TEXT_TYPES_H
#define GUARD_TEXT_TYPES_H

#include "types.h"

#ifdef VERSION_US
typedef u16 TextChar;
#else
typedef u8 TextChar;
#endif

typedef struct LocalizedText {
    const u8* strings[5];
} LocalizedText;

#ifdef VERSION_EU
#define LOCALIZED(name) (&name##ByLanguage)
#define LOCALIZED_STRING(name) GetLocalizedString(&name##ByLanguage)
#else
#define LOCALIZED(name) (name)
#define LOCALIZED_STRING(name) (name)
#endif

#define TEXT_ADVANCE_SPACE (-1)

typedef struct TextSlot {
    void* tiles;
    u8 useAlternatePalette;
    s8 advance;
} TextSlot;

#endif
