/*
 * pc_intr.c
 * Interrupt dispatch, replacing IrqHandler in asm/crt0.s.
 *
 * The ARM handler checks IE & IF in a fixed priority order and calls the
 * matching entry of gIntrTable (serial, vblank, hblank, vcount, timer0-3,
 * dma0-3, keypad, gamepak). Here an interrupt is "raised" by the frame
 * scheduler and dispatched immediately if the game has it enabled.
 */
#include "pc_platform.h"

typedef void (*IntrFunc)(void);
extern IntrFunc gIntrTable[14];

/* Table slot for each IE/IF bit, from the dispatch order in crt0.s. */
static int IrqSlot(uint16_t flag) {
    switch (flag) {
        case 1 << 7:  return 0;  /* serial */
        case 1 << 0:  return 1;  /* vblank */
        case 1 << 1:  return 2;  /* hblank */
        case 1 << 2:  return 3;  /* vcount */
        case 1 << 3:  return 4;  /* timer0 */
        case 1 << 4:  return 5;
        case 1 << 5:  return 6;
        case 1 << 6:  return 7;  /* timer3 */
        case 1 << 8:  return 8;  /* dma0 */
        case 1 << 9:  return 9;
        case 1 << 10: return 10;
        case 1 << 11: return 11; /* dma3 */
        case 1 << 12: return 12; /* keypad */
        default:      return 13; /* gamepak */
    }
}

static int sIrqDepth;
/* Requested-but-undelivered interrupts. Kept apart from the IF register because
 * the game acknowledges IF by writing 1s, which a plain array cannot emulate. */
static uint16_t sPending;

/* Runs every requested interrupt that is enabled, in the crt0.s priority order.
 * Requests made while IME is off (or while a handler runs) stay pending
 * and are delivered at the next dispatch point, as on hardware. */
void PcDispatchPendingIrqs(void) {
    static const uint16_t order[] = {
        1 << 7, 1 << 0, 1 << 1, 1 << 2, 1 << 3, 1 << 4, 1 << 5,
        1 << 6, 1 << 8, 1 << 9, 1 << 10, 1 << 11, 1 << 12, 1 << 13,
    };
    size_t i;

    if (sIrqDepth > 0)
        return;

    for (i = 0; i < sizeof(order) / sizeof(order[0]); i++) {
        uint16_t flag = order[i];
        IntrFunc fn;

        if (!(PC_IO16(PC_REG_IME) & 1))
            return;
        if (!(PC_IO16(PC_REG_IE) & sPending & flag))
            continue;

        sPending &= ~flag;
        fn = gIntrTable[IrqSlot(flag)];
        if (fn == NULL)
            continue;
        sIrqDepth++;
        fn();
        sIrqDepth--;
    }
}

/* For snapshots (pc_state.c). Snapshots are taken outside interrupt handlers. */
void* PcIntrState(size_t* size) {
    *size = sizeof(sPending);
    return &sPending;
}

/* After a snapshot restore the old call stack (maybe inside a handler) is gone. */
void PcIntrResetDepth(void) {
    sIrqDepth = 0;
}

void PcClearPendingIrqs(void) {
    sPending = 0;
    sIrqDepth = 0;
}

void PcRaiseIrq(uint16_t flag) {
    sPending |= flag;
    PcDispatchPendingIrqs();
}
