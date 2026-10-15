#ifndef GUARD_MODE_MAPINSPECT_H
#define GUARD_MODE_MAPINSPECT_H

#include "types.h"
#include "ms_types.h"
extern u16 gMapInspectNoticeText[];

s16 GetMapInspectTabStart(s16 tab);
s16 GetMapInspectSelectedIndex();
void MapInspectSelectFirstValue();
s16 GetMapInspectTabCount(s16 tab);
u8 MapInspectCanDelete();
s16 GetMapInspectValueIndex(s16 col, s16 row);
s16 GetMapInspectSelectedValue();
u16 MapInspectReadMenuKeys();
void MapInspectSelectValueInColumn(MapCardInventoryEntry* entry, u16 col);
void MapInspectDeleteCard();
u8 MapCardEntryIsEmpty(MapCardInventoryEntry* entry);
u8 MapCardEntrySelectedValueIsEmpty(MapCardInventoryEntry* entry);
void MapInspectSelectNextValue(MapCardInventoryEntry* entry);
void MapInspectRemoveEntry(MapCardInventoryEntry* entry);
void MapInspectHandleGridInput();
void MapInspectHandleTabInput();
void MapInspectHandleValueInput();
void MapInspectHandleConfirmInput();
void MapInspectHandleNoticeInput();
void MapInspectDraw();
void MapInspectBuildInventory();
struct MapCardInventoryEntry* GetMapInspectSelectedEntry();
void MapInspectDrawTab(s16 tab);
void MapInspectDrawCardTotal();
void MapInspectDrawCategoryCounts();
void MapInspectDrawValueCounts();
void MapInspectLoadGrid();
void MapInspectLoadSelectedCard();

#endif /* GUARD_MODE_MAPINSPECT_H */
