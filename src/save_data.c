/**
 * save_data.c
 * Save Data Serialization
 */

#include "save.h"
#include "types.h"
#include "bos_jf_shadow.h"
#include "bos4_api.h"
#include "card_api.h"
#include "game_state.h"
#include "map_api.h"
#include "ms_api.h"
#include "player_progression_types.h"
#include "save_api.h"
#include "save_types.h"
#include "system_state.h"
#include <string.h>
#include "save_data.h"

const u8* gSaveSignature = gSaveSignatureText;

const u8 gSaveSignatureText[SAVE_SIGNATURE_SIZE + 1] =
#ifdef VERSION_EU
    "KHCOM_BACKUP_VER00000013";
#else
    "KHCOM_BACKUP_VER00000012";
#endif

void MakeSaveHeaderData(SaveHeaderData* data, s16 file) {
    s16 i;

    data->flags = 0;

    if (gGameState.flags & GAME_FLAG_SORA_CLEAR) {
        data->flags = SAVE_HEADER_SORA_CLEAR;
    }

    if (gGameState.flags & GAME_FLAG_RIKU_CLEAR) {
        data->flags |= SAVE_HEADER_RIKU_CLEAR;

        if (gGameState.flags & GAME_FLAG_RIKU) {
            data->flags |= SAVE_HEADER_RIKU_TITLE;
        } else {
            data->flags &= ~SAVE_HEADER_RIKU_TITLE;
        }
    } else if (gGameState.flags & GAME_FLAG_SORA_CLEAR) {
        data->flags |= SAVE_HEADER_RIKU_TITLE;
    }

#ifdef VERSION_EU
    data->language = gLanguage;
#endif

    for (i = 0; i < 4; i++) {
        if (file == i) {
            data->files[i].floor = gGameState.floor;
            data->files[i].world = gGameState.world;
            data->files[i].level = gGameState.progression.level;
            data->files[i].playTime = gGameState.playTime;
        } else {
            data->files[i].floor = gGameState.fileSummaries[i].floor;
            data->files[i].world = gGameState.fileSummaries[i].world;
            data->files[i].level = gGameState.fileSummaries[i].level;
            data->files[i].playTime = gGameState.fileSummaries[i].playTime;
        }
    }
}

void MakeSaveSystem(SaveFileLarge* save) {
    save->common.flags = gGameState.flags;
    save->common.hp = gGameState.hp;
    memcpy(save->common.progression, &gGameState.progression.maxHp, sizeof(save->common.progression));
    save->common.availableWorlds = gGameState.availableWorlds;
    save->common.floor = gGameState.floor;
    save->common.world = gGameState.world;
    save->common.playTime = gGameState.playTime;
    CopyMapProgress(&save->shared);
    WriteCardSaveSlice(&save->large);
    WriteSaveSliceE6C(&save->unk_E6C);
    SavePooState(save->pooState);
    SaveMoogleShopFlags(&save->moogleShop);
}

void MakeSaveFileLarge(SaveFileLarge* save) {
    save->common.flags = gGameState.flags;
    save->common.hp = gGameState.hp;
    memcpy(save->common.progression, &gGameState.progression.maxHp, sizeof(save->common.progression));
    save->common.availableWorlds = gGameState.availableWorlds;
    save->common.floor = gGameState.floor;
    save->common.world = gGameState.world;
    save->common.playTime = gGameState.playTime;
    CopyMapProgress(&save->shared);
    WriteCardSaveSlice(&save->large);
    WriteSaveSliceE6C(&save->unk_E6C);
    SavePooState(save->pooState);
    SaveMoogleShopFlags(&save->moogleShop);

    if (gGameState.flags & GAME_FLAG_SECOND_FILE) {
        gGameState.fileSummaries[1].floor = gGameState.floor;
        gGameState.fileSummaries[1].world = gGameState.world;
        gGameState.fileSummaries[1].level = gGameState.progression.level;
        gGameState.fileSummaries[1].playTime = gGameState.playTime;
    } else {
        gGameState.fileSummaries[0].floor = gGameState.floor;
        gGameState.fileSummaries[0].world = gGameState.world;
        gGameState.fileSummaries[0].level = gGameState.progression.level;
        gGameState.fileSummaries[0].playTime = gGameState.playTime;
    }
}

void MakeSaveFileSmall(SaveFileSmall* save) {
    save->common.flags = gGameState.flags;
    save->common.hp = gGameState.hp;
    memcpy(save->common.progression, &gGameState.progression.maxHp, sizeof(save->common.progression));
    save->common.availableWorlds = gGameState.availableWorlds;
    save->common.floor = gGameState.floor;
    save->common.world = gGameState.world;
    save->common.playTime = gGameState.playTime;
    CopyMapProgress(&save->shared);
    CopyMapCardInventory(&save->small);

    if (gGameState.flags & GAME_FLAG_SECOND_FILE) {
        gGameState.fileSummaries[3].floor = gGameState.floor;
        gGameState.fileSummaries[3].world = gGameState.world;
        gGameState.fileSummaries[3].level = gGameState.progression.level;
        gGameState.fileSummaries[3].playTime = gGameState.playTime;
    } else {
        gGameState.fileSummaries[2].floor = gGameState.floor;
        gGameState.fileSummaries[2].world = gGameState.world;
        gGameState.fileSummaries[2].level = gGameState.progression.level;
        gGameState.fileSummaries[2].playTime = gGameState.playTime;
    }
}

void ApplySaveHeaderData(SaveHeaderData* data) {
    if (SaveRepairHeader() == SAVE_OK) {
        if (data->flags & SAVE_HEADER_SORA_CLEAR) {
            gGameState.flags |= GAME_FLAG_SORA_CLEAR;
        }

        if (data->flags & SAVE_HEADER_RIKU_CLEAR) {
            gGameState.flags |= GAME_FLAG_RIKU_CLEAR;
        }

        if (data->flags & SAVE_HEADER_RIKU_TITLE) {
            gGameState.flags |= GAME_FLAG_RIKU_TITLE;
        }

#ifdef VERSION_EU
        gLanguage = data->language;
#endif
    }

    if (SaveRepairFileLarge(0) == SAVE_OK) {
        gGameState.fileSummaries[0].floor = data->files[0].floor;
        gGameState.fileSummaries[0].world = data->files[0].world;
        gGameState.fileSummaries[0].level = data->files[0].level;
        gGameState.fileSummaries[0].playTime = data->files[0].playTime;
    } else {
        gGameState.fileSummaries[0].floor = 0;
        gGameState.fileSummaries[0].world = 0;
        gGameState.fileSummaries[0].level = 0;
        gGameState.fileSummaries[0].playTime = 0;
    }

    if (SaveRepairFileLarge(1) == SAVE_OK) {
        gGameState.fileSummaries[1].floor = data->files[1].floor;
        gGameState.fileSummaries[1].world = data->files[1].world;
        gGameState.fileSummaries[1].level = data->files[1].level;
        gGameState.fileSummaries[1].playTime = data->files[1].playTime;
    } else {
        gGameState.fileSummaries[1].floor = 0;
        gGameState.fileSummaries[1].world = 0;
        gGameState.fileSummaries[1].level = 0;
        gGameState.fileSummaries[1].playTime = 0;
    }

    if (SaveRepairFileSmall(0) == SAVE_OK) {
        gGameState.fileSummaries[2].floor = data->files[2].floor;
        gGameState.fileSummaries[2].world = data->files[2].world;
        gGameState.fileSummaries[2].level = data->files[2].level;
        gGameState.fileSummaries[2].playTime = data->files[2].playTime;
    } else {
        gGameState.fileSummaries[2].floor = 0;
        gGameState.fileSummaries[2].world = 0;
        gGameState.fileSummaries[2].level = 0;
        gGameState.fileSummaries[2].playTime = 0;
    }

    if (SaveRepairFileSmall(1) == SAVE_OK) {
        gGameState.fileSummaries[3].floor = data->files[3].floor;
        gGameState.fileSummaries[3].world = data->files[3].world;
        gGameState.fileSummaries[3].level = data->files[3].level;
        gGameState.fileSummaries[3].playTime = data->files[3].playTime;
    } else {
        gGameState.fileSummaries[3].floor = 0;
        gGameState.fileSummaries[3].world = 0;
        gGameState.fileSummaries[3].level = 0;
        gGameState.fileSummaries[3].playTime = 0;
    }
}

void ApplySaveSystem(SaveFileLarge* save) {
    u32 headerFlags;

    headerFlags = gGameState.flags & GAME_FLAGS_HEADER;
    save->common.flags &= ~GAME_FLAGS_HEADER;
    gGameState.flags = save->common.flags | headerFlags;
    gGameState.hp = save->common.hp;
    memcpy(&gGameState.progression.maxHp, save->common.progression, sizeof(save->common.progression));
    gGameState.availableWorlds = save->common.availableWorlds;
    gGameState.floor = save->common.floor;
    gGameState.world = save->common.world;
    gGameState.playTime = save->common.playTime;
    RestoreMapProgress(&save->shared);
    ReadCardSaveSlice(&save->large);
    ReadSaveSliceE6C(&save->unk_E6C);
    LoadPooState(save->pooState);
    LoadMoogleShopFlags(&save->moogleShop);
}

void ApplySaveFileLarge(SaveFileLarge* save) {
    u32 headerFlags;

    headerFlags = gGameState.flags & GAME_FLAGS_HEADER;
    save->common.flags &= ~GAME_FLAGS_HEADER;
    gGameState.flags = save->common.flags | headerFlags;
    gGameState.hp = save->common.hp;
    memcpy(&gGameState.progression.maxHp, save->common.progression, sizeof(save->common.progression));
    gGameState.availableWorlds = save->common.availableWorlds;
    gGameState.floor = save->common.floor;
    gGameState.world = save->common.world;
    gGameState.playTime = save->common.playTime;
    RestoreMapProgress(&save->shared);
    ReadCardSaveSlice(&save->large);
    ReadSaveSliceE6C(&save->unk_E6C);
    LoadPooState(save->pooState);
    LoadMoogleShopFlags(&save->moogleShop);
    gGameState.flags &= ~GAME_FLAG_RIKU;
}

void ApplySaveFileSmall(SaveFileSmall* save) {
    u32 headerFlags;

    headerFlags = gGameState.flags & GAME_FLAGS_HEADER;
    save->common.flags &= ~GAME_FLAGS_HEADER;
    gGameState.flags = save->common.flags | headerFlags;
    gGameState.hp = save->common.hp;
    memcpy(&gGameState.progression.maxHp, save->common.progression, sizeof(save->common.progression));
    gGameState.availableWorlds = save->common.availableWorlds;
    gGameState.floor = save->common.floor;
    gGameState.world = save->common.world;
    gGameState.playTime = save->common.playTime;
    RestoreMapProgress(&save->shared);
    RestoreMapCardInventory(&save->small);
    gGameState.flags |= GAME_FLAG_RIKU;
}
