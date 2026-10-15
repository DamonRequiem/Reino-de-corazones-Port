#ifndef GUARD_MAP_TEXT_DATA_H
#define GUARD_MAP_TEXT_DATA_H

#include "text_types.h"
#include "types.h"

#ifdef VERSION_US
typedef u16 MapNameText;
#elif defined(VERSION_JP)
typedef u8 MapNameText;
#else
typedef LocalizedText MapNameText;
#endif

extern const MapNameText* gRoomNames[28];

#ifdef VERSION_EU

extern const LocalizedText gRoomNameUnknownPlaceByLanguage;
extern const LocalizedText gRoomNameHiddenChamberByLanguage;
extern const LocalizedText gFloorName1ByLanguage;
extern const LocalizedText gFloorName2ByLanguage;
extern const LocalizedText gFloorName3ByLanguage;
extern const LocalizedText gFloorName4ByLanguage;
extern const LocalizedText gFloorName5ByLanguage;
extern const LocalizedText gFloorName6ByLanguage;
extern const LocalizedText gFloorName7ByLanguage;
extern const LocalizedText gFloorName8ByLanguage;
extern const LocalizedText gFloorName9ByLanguage;
extern const LocalizedText gFloorName10ByLanguage;
extern const LocalizedText gFloorName11ByLanguage;
extern const LocalizedText gFloorName12ByLanguage;
extern const LocalizedText gFloorName13ByLanguage;
extern const LocalizedText gBasementFloorName12ByLanguage;
extern const LocalizedText gBasementFloorName11ByLanguage;
extern const LocalizedText gBasementFloorName10ByLanguage;
extern const LocalizedText gBasementFloorName9ByLanguage;
extern const LocalizedText gBasementFloorName8ByLanguage;
extern const LocalizedText gBasementFloorName7ByLanguage;
extern const LocalizedText gBasementFloorName6ByLanguage;
extern const LocalizedText gBasementFloorName5ByLanguage;
extern const LocalizedText gBasementFloorName4ByLanguage;
extern const LocalizedText gBasementFloorName3ByLanguage;
extern const LocalizedText gBasementFloorName2ByLanguage;
extern const LocalizedText gBasementFloorName1ByLanguage;
#endif

#endif
