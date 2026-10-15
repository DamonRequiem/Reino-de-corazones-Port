#ifndef GUARD_MAP_RUNTIME_H
#define GUARD_MAP_RUNTIME_H

#include "map_types.h"
#include "text_types.h"
#include "fld_types.h"
#include "types.h"

typedef struct MapFloorDef {
    u8 entryRoom;
    u8 exitRoom;
    u8* links;
    MapEventDoor* eventDoors;
} MapFloorDef;

struct MapCardAttributes;

u8 GetOppositeDoorSide(u8 side);
void MarkEventRoomDone(MapEventDoor* door);
void SetHallDefaultSpawn();
void UpdateWorldFriendFlags();
const MapFloorDef* GetMapFloorDef(u8 floor);
u8* GetMapRoomLinks(u8 room);
MapEventDoor* GetMapEventDoor(u8 index);
MapFloorRoom* GetMapFloorRoom(u8 index);
u8 GetMapRoomLink(u8 room, u8 side);
u16 GetMapDoorFlags(u8 room, u8 side);
void UpdateGameWorld();
void SetWorldJiminyFlags();
void SetFloorJiminyFlags();
void AdvanceFloorStory();
void AdvanceToExitHall();
u8 GetEventStepKeyKind();
u8 GetCurrentEventDoorKeyKind();
u8 SelectCurrentEventDoor();
u8 GetEventRoomKind(u8 room);
s32 GetMapRoomCardValue(u8 room);
void SetCardlessRoomType(u8 room);
u8 GetRandomRoomType();
void CreateMapRoom(u8 room, struct MapCardAttributes* card);
void LoadMapRoomState(MapRoomState* state, u8 room);
void SetCurrentMapRoom(u8 room, u8 side);
u8 GetProgressFloor();
void* GetMapWorldName(u8 index);
void EnterEntranceHall();
void EnterExitHall();
void InitMapFloorState(u8 room, u8 entrySide);
void MarkPastEventRoomsDone();
void GoToFloor(u8 floor);
void GoToNextFloor();
void GoToPreviousFloor();
void WarpToFloor(u8 floor);
void SetFloorWorld(u8 world);
void EnterFloorWorld();
void StoreMapFloorState();
void InitStartFloor(u8 floor, u8 world);
void ResetMapFloors();
MapDoor* GetMapDoor(u8 side);
MapCell* FieldCellAt(s32 x, s32 y);
u8 IsFldPosBlocked(FldPos* pos);
u8 GetMapWalkOutMode();
void EndMapWalkOut();
u8 FldPosRevertIfBlocked(FldPos* pos, s32 x, s32 y);
u8 MapFindOpenDoor(FldPos* pos);
u8 IsAtTargetDoor(FldPos* pos);
u8 GetFldPosClimbDir(FldPos* pos);
s32 FieldFloorAt(s32 x, s32 y, s32 z);

#ifdef VERSION_EU
extern const LocalizedText gWorldNameCastleOblivionHallByLanguage;
#endif

#endif
