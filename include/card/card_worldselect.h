#ifndef GUARD_CARD_WORLDSELECT_H
#define GUARD_CARD_WORLDSELECT_H

#include "card.h"
#include "taskpool.h"
#include "types.h"

enum MapSelectStatus {
    MAP_SELECT_STATUS_OPEN,
    MAP_SELECT_STATUS_CLOSED,
    MAP_SELECT_STATUS_CARD_CHOSEN
};

u8 UpdateMapSelectSetup(MapSelectWork* work, void* task);
u8 UpdateMapSelectSlideIn(MapSelectWork* work, void* task);
u8 UpdateMapSelectValueInput(MapSelectWork* work, void* task);
u8 UpdateMapSelectLeaveValues(MapSelectWork* work, void* task);
u8 UpdateMapSelectKindInput(MapSelectWork* work, void* task);
u8 UpdateMapSelectClose(MapSelectWork* work);
void CreateMapSelectCards(MapSelectWork* work);
void HandleMapSelectKindCursor(MapSelectWork* work);
void ApplyMapSelectPageScroll(MapSelectWork* work);
s32 SelectNearestMapSelectCard(MapSelectWork* work);
s32 RemoveMapCard(u16 cardId);
void CreateMapCardSelection(TaskPool* pool, u8* status);
void LoadMapSelectKindPalette(u16 baseCardId, MapSelectWork* work);
void LoadMapSelectGridPalette(u16 baseCardId, MapSelectWork* work);
s32 LoadMapSelectValueCounts(u16 baseCardId, MapSelectWork* work);
void HandleMapSelectValueCursor(MapSelectWork* work);
u8 UpdateMapSelectEventDoorTutorial(MapSelectWork* work, void* task);
s32 func_080948F0(MapcardWork* work, void* task);
void AimMapcardAtDoor(MapcardWork* work);
u8 UpdateMapcardFlyToDoor(MapcardWork* work, void* task);
void UpdateMapcardRise(MapcardWork* work);
void func_08094DEC(MapcardWork* work);
u8 func_08094E4C(MapcardWork* work);
MapcardWork* CreateMapCard(MapcardArgs* args, TaskPool* pool);
void LinkMapcardNode(MapcardWork* work);
u8 UpdateReloadGageIdle(CardDisplayWork* work, void* task);
void UpdateReloadGageRingPosition(CardDisplayWork* work);
void StepReloadGageSine(ReloadGauge* gauge);
void InitReloadGageCounterAnim(ReloadGauge* gauge, void* tiles, u8 listIndex, s32 count);
void SetReloadGageCounterAnim(ReloadGauge* gauge, s32 count);
s32 UpdateReloadGageSlide(ReloadGauge* gauge, CardDisplayWork* work);
void InitReloadGageAnims(ReloadGauge* gauge, CardDisplayWork* work, u8 idx);
void UpdateReloadGageAnims(ReloadGauge* gauge, CardDisplayWork* work);
void SetReloadGageIdleFrames(ReloadGauge* gauge, CardDisplayWork* work);
void AdvanceReloadGageAnim(ReloadGauge* gauge, CardDisplayWork* work);
void ResetReloadGageAnim(ReloadGauge* gauge);

#endif
