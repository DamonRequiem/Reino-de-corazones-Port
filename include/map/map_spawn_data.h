#ifndef GUARD_MAP_SPAWN_DATA_H
#define GUARD_MAP_SPAWN_DATA_H

#include "types.h"

struct PrzCardChance;
struct PrizeEntry;

extern const struct PrzCardChance gPrzCardChancesDefault[7];
extern const struct PrzCardChance gPrzCardChancesTraverseTown[8];
extern const struct PrzCardChance gPrzCardChancesAgrabah[12];
extern const struct PrzCardChance gPrzCardChancesHalloweenTown[13];
extern const struct PrzCardChance gPrzCardChancesMonstro[13];
extern const struct PrzCardChance gPrzCardChancesOlympusColiseum[13];
extern const struct PrzCardChance gPrzCardChancesWonderland[13];
extern const struct PrzCardChance gPrzCardChancesAtlantica[17];
extern const struct PrzCardChance gPrzCardChancesNeverLand[16];
extern const struct PrzCardChance gPrzCardChancesHollowBastion[15];
extern const struct PrzCardChance gPrzCardChancesTwilightTown[25];
extern const struct PrzCardChance gPrzCardChancesDestinyIslands[16];
extern const struct PrzCardChance gPrzCardChancesCastleOblivion[25];
extern const struct PrizeEntry gPrzCardKinds[40];
extern const struct PrizeEntry gPrzStocks[19];
extern const u16 gCardValueWeights[10];
extern const struct PrizeEntry gPrizeListEmpty[1];
extern const struct PrizeEntry gPrizeListTraverseTown[2];
extern const struct PrizeEntry gPrizeListAgrabah[3];
extern const struct PrizeEntry gPrizeListHalloweenTown[3];
extern const struct PrizeEntry gPrizeListMonstro[3];
extern const struct PrizeEntry gPrizeListOlympusColiseum[3];
extern const struct PrizeEntry gPrizeListWonderland[3];
extern const struct PrizeEntry gPrizeListAtlantica[4];
extern const struct PrizeEntry gPrizeListNeverLand[4];
extern const struct PrizeEntry gPrizeListHollowBastion[4];
extern const struct PrizeEntry gPrizeListTwilightTown[3];
extern const struct PrizeEntry gPrizeListDestinyIslands[3];
extern const struct PrizeEntry gPrizeListCastleOblivion[1];

#endif
