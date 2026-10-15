#ifndef GUARD_MODE_MAPCHK_H
#define GUARD_MODE_MAPCHK_H

#include "types.h"

typedef struct MapChkWork {
    u8 cursor;
    u8 mode;
    u8 world;
    u8 floor;
    u8 form;
    u8 useParams;
    u8 unk_06[0x02];
} MapChkWork;

void MapChkSetParamToggle(u8* work, u8 on);
void MapChkSetFloorProgress(u8 floor, u8 cleared);
void MapChkEditMode(MapChkWork* work);
void MapChkEditWorld(MapChkWork* work);
void MapChkEditFloor(MapChkWork* work);
void MapChkEditForm(MapChkWork* work);
void MapChkEditWidth(MapChkWork* work);
void MapChkFlipParamToggle(MapChkWork* work);
void MapChkEditMinHeight(MapChkWork* work);
void MapChkEditMaxHeight(MapChkWork* work);
void MapChkEditMinDepth(MapChkWork* work);
void MapChkEditMaxDepth(MapChkWork* work);
void Mode_MapChk_0();
void Mode_MapChk_1();
void Mode_MapChk_2();

#endif
