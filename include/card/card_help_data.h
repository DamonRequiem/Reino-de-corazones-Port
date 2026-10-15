#ifndef GUARD_CARD_HELP_DATA_H
#define GUARD_CARD_HELP_DATA_H

#include "text_types.h"
#include "types.h"

#ifdef VERSION_US
typedef u16 CardHelpText;
#elif defined(VERSION_JP)
typedef u8 CardHelpText;
#else
typedef LocalizedText CardHelpText;
#endif

typedef struct CardHelpDef {
    const CardHelpText** texts;
    u8 textCount;
} CardHelpDef;

#endif
