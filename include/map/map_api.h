#ifndef GUARD_MAP_API_H
#define GUARD_MAP_API_H

#include "types.h"
#include "map_types.h"
#include "fld_types.h"

struct EventKey;
struct MapCardAttributes;
struct MapCell;
struct MapProgress;

s32 GetFldPosGround(FldPos* pos);
void FldPosInitGround(FldPos* pos);
s32 GetLedgeAngleAt(s32 x, s32 y, s32 z);
void MapSetCameraTarget(s32 x, s32 y);
void MapMoveCameraTarget(s32 dx, s32 dy);
void SetMapAttackBox(s32 x, s32 y, s32 z);
void MapFreezeBg1();
FldObj* GetMapRoomDoor();
void RequestMapMode();
void ReturnToMap(u8 returnToMenu);
struct MapCell* MapCellAt(s16 x, s16 y);
u8* GetMapRoomEvent(u8 step);
void LoadMapForm(u8 form);
MapDoor* MapGetDoor(u8 side);
struct MapCell* MapFixCellAt(s16 x, s16 y);
u8 MapCellMaskBitAt(struct MapCell* cell, s32 x, s32 y);
u8 SelectEventDoor(u8 room, u8 side);
u8 CountRemainingEventKeys();
struct EventKey* GetEventKey(u8 index);
u8 DoorAcceptsMapCard(struct MapCardAttributes* card);
s32 PayEventKey(struct MapCardAttributes* card);
u8 AreWorldPrizesCollected();
void CopyMapProgress(struct MapProgress* progress);
void RestoreMapProgress(struct MapProgress* progress);

struct MapGmkPlacement;

extern MapRoomState* gMapRoomState;
extern MapFloorState gMapFloorState;
extern MapFormDef gMapForm;
extern struct MapGmkPlacement* gMapGmkPlacements;

#endif
