#ifndef GUARD_MODE_TEST_H
#define GUARD_MODE_TEST_H

#include "mode.h"
#include "evt_types.h"
#include "types.h"

#ifndef VERSION_EU
extern Mode gModeTest;
#endif
void mode_test_0();
void mode_test_1();
void mode_test_2();

extern EventState* gEventState;

extern Mode gModeChkbtl;

#endif /* GUARD_MODE_TEST_H */
