#ifndef GUARD_TUTORIAL_H
#define GUARD_TUTORIAL_H

#include "types.h"
#include "anim.h"

enum TutorialFlag {
    TUTORIAL_FLAG_CARD_ACTION_ACTIVE = 0x2,
    TUTORIAL_FLAG_SHOW_ARROW = 0x4
};

typedef struct TutorialWork {
    u16 flags;
    u16 message;
    u32 state;
    u32 nextState;
    s16 timer;
    s16 count;
    s16 inputCooldown;
    u16 arrowX;
    u16 arrowY;
    void* tiles;
    void* palette;
    AnimState anim;
} TutorialWork;

void TutorialOpenMessage(u16 message);
void TutorialOpenPersistentMessage(u16 message);
void TutorialRestoreBgMode();
void TutorialQueueMessage(TutorialWork* work, u16 message, u32 nextState);
void TutorialQueuePersistentMessage(TutorialWork* work, u16 message, u32 nextState);
void TutorialCloseMessage();
void TutorialWait(TutorialWork* work, u16 count, u32 nextState);
void TutorialShowArrow(TutorialWork* work, u16 x, u16 y, u16 animId);
void TutorialHideArrow(TutorialWork* work);
void task_tutorial_0(TutorialWork* work, s32 kind);
s32 task_tutorial_1(TutorialWork* work);
void task_tutorial_2(TutorialWork* work);
void task_tutorial_3(TutorialWork* work);

#endif /* GUARD_TUTORIAL_H */
