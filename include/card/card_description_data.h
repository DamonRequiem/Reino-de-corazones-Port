#ifndef GUARD_CARD_DESCRIPTION_DATA_H
#define GUARD_CARD_DESCRIPTION_DATA_H

#include "text_types.h"
#include "types.h"

#ifdef VERSION_US
typedef u16 CardDescriptionText;
#elif defined(VERSION_JP)
typedef u8 CardDescriptionText;
#else
typedef LocalizedText CardDescriptionText;
#endif

extern CardDescriptionText* gCardKindDescriptions[];
extern CardDescriptionText* gMapCardDescriptions[];
extern CardDescriptionText* gWorldDescriptions[];

#endif
