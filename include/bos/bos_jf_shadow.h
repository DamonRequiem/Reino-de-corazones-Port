#ifndef GUARD_BOS_JF_SHADOW_H
#define GUARD_BOS_JF_SHADOW_H

#include "types.h"
#include "save_types.h"
#include "battle_actor_types.h"

typedef struct JfShadowWork {
    void* tiles;
    void* palette;
    void* gfx;
    BtlObj* actor;
} JfShadowWork;

void task_bos_jf_shadow_0(JfShadowWork* work, BtlObj* obj);
s32 task_bos_jf_shadow_1();
void task_bos_jf_shadow_2(JfShadowWork* work);
void task_bos_jf_shadow_3(JfShadowWork* work);

void ResetSaveSliceE6C();
void WriteSaveSliceE6C(SaveSliceE6C* out);
void ReadSaveSliceE6C(SaveSliceE6C* in);

#endif /* GUARD_BOS_JF_SHADOW_H */
