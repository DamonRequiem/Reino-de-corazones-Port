#ifndef GUARD_CARD_API_H
#define GUARD_CARD_API_H

#include "types.h"
#include "card_types.h"
#include "card_ui_types.h"

struct CardBattleState;
struct CardBattleWork;
struct LayeredCardSprite;
struct BtlObj;
struct LevelUpWork;
struct TaskPool;
struct StockKeys;
struct CardDisplayWork;
struct MapcardWork;
struct EventKey;
struct SaveLargeSlice;
struct SaveSmallSlice;
struct BtlPrizeSrc;

void Mapcard_2(struct MapcardWork* work);
void Level_Up_3(struct LevelUpWork* work);

void InitRikuDeckForWorld(u8 world);
void SelectPrevSoraCard(struct CardBattleWork* work, u8 listIndex, u8 timer);
void func_0807B3C4(s32 a);
u8 GetSoraCardListIndex();
u8 GetSoraStockCount();
void LoadPremiumCardGfx(struct CardBattleState* state);
void RequestRikuPotion();
void RequestRikuHiPotion();
void RequestRikuMegaPotion();
void RequestRikuEther();
void RequestRikuMegaEther();
void RequestRikuElixir();
void RequestRikuMegalixir();
void RequestRikuNextCard();
void RequestRikuPrevCard();
void RequestRikuCardUse();
void RequestRikuCardStock();
void RequestRikuStockUse();
void RequestOpenRikuCards();
void RequestCloseRikuCards();
u8 IsRikuReloadCardSelected();
u8 func_08081828();
void RequestBossCardValue(u8 value);
void RequestBossCardRandom();
u8 GetBossCardShownValue();
s16 ObtainCard(u16 cardId);
u8* GetDeckName(u8 index);
s16 CountActiveDeckCards(s32 cardSet);
u16 GetDeckCardCount(u8 index);
void InitSoraDecks();
void InitDebugDecks();
void func_08085FB0();
s32 AddMapCard(u16 cardId);
u16 CountRegularMapCards();
void InitMapCardInventory();
void ResetSelectedMapCard();
const void* GetRoomName(u16 kind);
void CreatePrizeCardTask(struct TaskPool* pool, struct BtlPrizeSrc* src);
void CreateBossPrizeCardTask(void* pool, void* src);
void DrawLayeredCardSprite(struct LayeredCardSprite* sprite, u16 flags);
void SetLayeredCardSpritePos(s32 x, s32 y, LayeredCardSprite* sprite);
void ReleaseLayeredCardSprite(LayeredCardSprite* sprite);
struct ObjTiles* AllocKeyValueTiles(u8 value);
void InitEventKeyCard(EventKeyCard* card, struct EventKey* key);
u8 GetRoomCardBackIndex(u16 kind);
void CreateREVCOUNTTask(void* pool, u8* shownList, s16* count, u8* visible, u8 side);
enum FriendCard {
    FRIEND_CARD_GOOFY,
    FRIEND_CARD_DONALD_DUCK,
    FRIEND_CARD_ALADDIN,
    FRIEND_CARD_ARIEL,
    FRIEND_CARD_JACK,
    FRIEND_CARD_PETER_PAN,
    FRIEND_CARD_THE_BEAST,
    FRIEND_CARD_THE_KING
};

void CreateFriendCardTask(void* pool, s16 x, s16 y, s16 z, u8 idx);
void PrintString(u8 x, u8 y, u8 color, const u8* text);
void PrintNumber(u16 x, u16 y, u16 color, s32 value);
u8 CreateLevelUpEffectTask(struct BtlObj* target, struct TaskPool* pool);
void WriteCardSaveSlice(struct SaveLargeSlice* out);
void ReadCardSaveSlice(struct SaveLargeSlice* in);
void CopyMapCardInventory(struct SaveSmallSlice* out);
void RestoreMapCardInventory(struct SaveSmallSlice* in);
void CreateCardMessageTask(void* pool, u32 bg, u16 message);
void CreateSysmsgwinTask(void* pool, u16 message);
void ResetMessageWindowFlags();
u8 IsMessageWindowOpen();
u8 IsMessageWindowAnswerYes();
u8 CloseMessageWindow();
s32 ResolveActiveCardsMove(s32* out);
s32 LookupStockName(struct CardDisplayWork** cards, u8 count, u8 value, struct StockKeys* stockKeys, u8* flag);
s32 LookupLinkStockName(struct CardDisplayWork** cards, u8 count, u8 value, struct StockKeys* stockKeys, u8* flag, s32 side);
s32 LookupStockPairName(struct StockKeys* cards, u8* output, u8 count);

struct CardListWork;

extern u8 gBossCardRequestValue;
extern u8 gBossCardRequest;
extern Deck gDecks[3];
extern u16 gCardCollection[999];
extern Deck* gLinkPartnerDeck;
extern Deck* gLinkSendDeck;
extern u16 gCardCount;
extern CardUiSpriteState gCardUiSpriteState;
extern MapCardUiResources gMapCardUiResources;
extern u8 gMapCardCounts[270];
extern struct CardListWork* gCardListWork;
extern u8 gMessageWindowOpen;
extern u8 gMessageWindowAnswerYes;
#ifndef VERSION_EU
extern u16 gSioTradeCardId;
#endif
extern u8 gRikuDeckTutorialState;

#endif
