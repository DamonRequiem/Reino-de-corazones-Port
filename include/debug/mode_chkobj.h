#ifndef GUARD_MODE_CHKOBJ_H
#define GUARD_MODE_CHKOBJ_H

#include "types.h"
#include "chkobj.h"

typedef struct ChkObjEntry {
    ObjDef* defs;
    u16 count;
    const char* name;
} ChkObjEntry;

void ChkObjLoadDef(ObjDef* def);
void mode_chkobj_0();
void mode_chkobj_1();
void mode_chkobj_2();

#endif /* GUARD_MODE_CHKOBJ_H */
