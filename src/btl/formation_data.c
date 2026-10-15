/**
 * formation_data.c
 * Enemy Formation Data
 */

#include "formation_data.h"
#include "formation_types.h"
#include "enemy_ids.h"
#include "macros.h"

#ifdef VERSION_EU
#define FORMATION_LIST_DROP 1
#else
#define FORMATION_LIST_DROP 0
#endif

static const BtlFormStep sBtlFormShadow8Steps[] = {
    { ENEMY_SHADOW, 25, -25, 0, 0 },
    { ENEMY_SHADOW, 65, -12, 0, 1 },
    { ENEMY_SHADOW, 85, 12, 0, 2 },
    { ENEMY_SHADOW, 55, 25, 0, 3 },
    { ENEMY_SHADOW, -55, 25, 0, 4 },
    { ENEMY_SHADOW, -85, 12, 0, 5 },
    { ENEMY_SHADOW, -65, -12, 0, 6 },
    { ENEMY_SHADOW, -25, -25, 0, 7 },
};

static const BtlFormEntry sBtlFormShadow8 = { ARRAY_COUNT(sBtlFormShadow8Steps), sBtlFormShadow8Steps, 60 };

static const BtlFormStep sBtlFormShadow7Steps[] = {
    { ENEMY_SHADOW, 90, 0, 0, 0 },
    { ENEMY_SHADOW, 55, 25, 0, 1 },
    { ENEMY_SHADOW, 40, 0, 0, 2 },
    { ENEMY_SHADOW, 25, -25, 0, 3 },
    { ENEMY_SHADOW, -25, -25, 0, 4 },
    { ENEMY_SHADOW, -55, 25, 0, 5 },
    { ENEMY_SHADOW, -64, 0, 0, 6 },
};

static const BtlFormEntry sBtlFormShadow7 = { ARRAY_COUNT(sBtlFormShadow7Steps), sBtlFormShadow7Steps, 60 };

static const BtlFormStep sBtlFormShadow6ASteps[] = {
    { ENEMY_SHADOW, 25, -25, 0, 0 },
    { ENEMY_SHADOW, 40, 0, 0, 1 },
    { ENEMY_SHADOW, 25, 25, 0, 2 },
    { ENEMY_SHADOW, -25, 25, 0, 3 },
    { ENEMY_SHADOW, -40, 0, 0, 4 },
    { ENEMY_SHADOW, -25, -25, 0, 5 },
};

static const BtlFormEntry sBtlFormShadow6A = { ARRAY_COUNT(sBtlFormShadow6ASteps), sBtlFormShadow6ASteps, 60 };

static const BtlFormStep sBtlFormShadow6BSteps[] = {
    { ENEMY_SHADOW, 25, -25, 0, 0 },
    { ENEMY_SHADOW, 40, 0, 0, 1 },
    { ENEMY_SHADOW, 55, 25, 0, 2 },
    { ENEMY_SHADOW, -55, -25, 0, 3 },
    { ENEMY_SHADOW, -40, 0, 0, 4 },
    { ENEMY_SHADOW, -25, 25, 0, 5 },
};

const BtlFormEntry gBtlFormShadow6B = { ARRAY_COUNT(sBtlFormShadow6BSteps), sBtlFormShadow6BSteps, 60 };

static const BtlFormStep sBtlFormShadow6CSteps[] = {
    { ENEMY_SHADOW, 90, 0, 0, 0 },
    { ENEMY_SHADOW, 64, 0, 0, 1 },
    { ENEMY_SHADOW, 40, 0, 0, 2 },
    { ENEMY_SHADOW, -40, 0, 0, 3 },
    { ENEMY_SHADOW, -64, 0, 0, 4 },
    { ENEMY_SHADOW, -90, 0, 0, 5 },
};

const BtlFormEntry gBtlFormShadow6C = { ARRAY_COUNT(sBtlFormShadow6CSteps), sBtlFormShadow6CSteps, 60 };

static const BtlFormStep sBtlFormShadow5ASteps[] = {
    { ENEMY_SHADOW, 25, -25, 0, 0 },
    { ENEMY_SHADOW, 40, 0, 0, 1 },
    { ENEMY_SHADOW, 55, 25, 0, 2 },
    { ENEMY_SHADOW, 65, -12, 0, 3 },
    { ENEMY_SHADOW, 85, 12, 0, 4 },
};

const BtlFormEntry gBtlFormShadow5A = { ARRAY_COUNT(sBtlFormShadow5ASteps), sBtlFormShadow5ASteps, 60 };

static const BtlFormStep sBtlFormShadow5BSteps[] = {
    { ENEMY_SHADOW, 25, -25, 0, 0 },
    { ENEMY_SHADOW, 55, 25, 0, 1 },
    { ENEMY_SHADOW, 90, 0, 0, 2 },
    { ENEMY_SHADOW, -65, -12, 0, 3 },
    { ENEMY_SHADOW, -85, 12, 0, 4 },
};

static const BtlFormEntry sBtlFormShadow5B = { ARRAY_COUNT(sBtlFormShadow5BSteps), sBtlFormShadow5BSteps, 60 };

static const BtlFormStep sBtlFormShadow5CSteps[] = {
    { ENEMY_SHADOW, 65, -12, 0, 0 },
    { ENEMY_SHADOW, 85, 12, 0, 1 },
    { ENEMY_SHADOW, -25, -25, 0, 2 },
    { ENEMY_SHADOW, -40, 0, 0, 3 },
    { ENEMY_SHADOW, -55, 25, 0, 4 },
};

static const BtlFormEntry sBtlFormShadow5C = { ARRAY_COUNT(sBtlFormShadow5CSteps), sBtlFormShadow5CSteps, 60 };

static const BtlFormStep sBtlFormShadow5DSteps[] = {
    { ENEMY_SHADOW, 25, -25, 0, 0 },
    { ENEMY_SHADOW, 65, -12, 0, 1 },
    { ENEMY_SHADOW, 90, 0, 0, 2 },
    { ENEMY_SHADOW, 85, 12, 0, 3 },
    { ENEMY_SHADOW, 55, 25, 0, 4 },
};

static const BtlFormEntry sBtlFormShadow5D = { ARRAY_COUNT(sBtlFormShadow5DSteps), sBtlFormShadow5DSteps, 60 };

static const BtlFormStep sBtlFormShadow4ASteps[] = {
    { ENEMY_SHADOW, 25, -25, 0, 0 },
    { ENEMY_SHADOW, 55, 25, 0, 1 },
    { ENEMY_SHADOW, 65, -12, 0, 2 },
    { ENEMY_SHADOW, 85, 12, 0, 3 },
};

static const BtlFormEntry sBtlFormShadow4A = { ARRAY_COUNT(sBtlFormShadow4ASteps), sBtlFormShadow4ASteps, 60 };

static const BtlFormStep sBtlFormShadow4BSteps[] = {
    { ENEMY_SHADOW, 40, 0, 0, 0 },
    { ENEMY_SHADOW, 65, -12, 0, 1 },
    { ENEMY_SHADOW, 85, 12, 0, 2 },
    { ENEMY_SHADOW, 90, 0, 0, 3 },
};

static const BtlFormEntry sBtlFormShadow4B = { ARRAY_COUNT(sBtlFormShadow4BSteps), sBtlFormShadow4BSteps, 60 };

static const BtlFormStep sBtlFormShadow4CSteps[] = {
    { ENEMY_SHADOW, 65, -12, 0, 0 },
    { ENEMY_SHADOW, 85, 12, 0, 1 },
    { ENEMY_SHADOW, -65, -12, 0, 2 },
    { ENEMY_SHADOW, -85, 12, 0, 3 },
};

static const BtlFormEntry sBtlFormShadow4C = { ARRAY_COUNT(sBtlFormShadow4CSteps), sBtlFormShadow4CSteps, 60 };

static const BtlFormStep sBtlFormShadow4DSteps[] = {
    { ENEMY_SHADOW, -55, 25, 0, 0 },
    { ENEMY_SHADOW, -85, 12, 0, 1 },
    { ENEMY_SHADOW, -65, -12, 0, 2 },
    { ENEMY_SHADOW, -25, -25, 0, 3 },
};

static const BtlFormEntry sBtlFormShadow4D = { ARRAY_COUNT(sBtlFormShadow4DSteps), sBtlFormShadow4DSteps, 60 };

static const BtlFormStep sBtlFormShadow3ASteps[] = {
    { ENEMY_SHADOW, 40, 0, 0, 0 },
    { ENEMY_SHADOW, 65, -12, 0, 1 },
    { ENEMY_SHADOW, 85, 12, 0, 2 },
};

static const BtlFormEntry sBtlFormShadow3A = { ARRAY_COUNT(sBtlFormShadow3ASteps), sBtlFormShadow3ASteps, 60 };

static const BtlFormStep sBtlFormShadow3BSteps[] = {
    { ENEMY_SHADOW, 65, -12, 0, 0 },
    { ENEMY_SHADOW, 85, 12, 0, 1 },
    { ENEMY_SHADOW, 90, 0, 0, 2 },
};

static const BtlFormEntry sBtlFormShadow3B = { ARRAY_COUNT(sBtlFormShadow3BSteps), sBtlFormShadow3BSteps, 60 };

static const BtlFormStep sBtlFormShadow3CSteps[] = {
    { ENEMY_SHADOW, 65, -12, 0, 0 },
    { ENEMY_SHADOW, 85, 12, 0, 1 },
    { ENEMY_SHADOW, -40, 0, 0, 2 },
};

static const BtlFormEntry sBtlFormShadow3C = { ARRAY_COUNT(sBtlFormShadow3CSteps), sBtlFormShadow3CSteps, 60 };

static const BtlFormStep sBtlFormShadow3DSteps[] = {
    { ENEMY_SHADOW, 25, -25, 0, 0 },
    { ENEMY_SHADOW, 64, 0, 0, 1 },
    { ENEMY_SHADOW, 55, 25, 0, 2 },
};

static const BtlFormEntry sBtlFormShadow3D = { ARRAY_COUNT(sBtlFormShadow3DSteps), sBtlFormShadow3DSteps, 60 };

static const BtlFormStep sBtlFormShadow3ESteps[] = {
    { ENEMY_SHADOW, -25, 25, 0, 0 },
    { ENEMY_SHADOW, -64, 0, 0, 1 },
    { ENEMY_SHADOW, -55, -25, 0, 2 },
};

static const BtlFormEntry sBtlFormShadow3E = { ARRAY_COUNT(sBtlFormShadow3ESteps), sBtlFormShadow3ESteps, 60 };

static const BtlFormStep sBtlFormShadow3FSteps[] = {
    { ENEMY_SHADOW, -65, -12, 0, 0 },
    { ENEMY_SHADOW, -85, 12, 0, 1 },
    { ENEMY_SHADOW, 40, 0, 0, 2 },
};

static const BtlFormEntry sBtlFormShadow3F = { ARRAY_COUNT(sBtlFormShadow3FSteps), sBtlFormShadow3FSteps, 60 };

static const BtlFormStep sBtlFormShadow2ASteps[] = {
    { ENEMY_SHADOW, 65, -12, 0, 0 },
    { ENEMY_SHADOW, 85, 12, 0, 1 },
};

static const BtlFormEntry sBtlFormShadow2A = { ARRAY_COUNT(sBtlFormShadow2ASteps), sBtlFormShadow2ASteps, 60 };

static const BtlFormStep sBtlFormShadow2BSteps[] = {
    { ENEMY_SHADOW, 25, -25, 0, 0 },
    { ENEMY_SHADOW, 55, 25, 0, 1 },
};

static const BtlFormEntry sBtlFormShadow2B = { ARRAY_COUNT(sBtlFormShadow2BSteps), sBtlFormShadow2BSteps, 60 };

static const BtlFormStep sBtlFormShadow2CSteps[] = {
    { ENEMY_SHADOW, 40, 0, 0, 0 },
    { ENEMY_SHADOW, -40, 0, 0, 1 },
};

static const BtlFormEntry sBtlFormShadow2C = { ARRAY_COUNT(sBtlFormShadow2CSteps), sBtlFormShadow2CSteps, 60 };

static const BtlFormStep sBtlFormShadow2DSteps[] = {
    { ENEMY_SHADOW, 40, 0, 0, 0 },
    { ENEMY_SHADOW, 90, 0, 0, 1 },
};

static const BtlFormEntry sBtlFormShadow2D = { ARRAY_COUNT(sBtlFormShadow2DSteps), sBtlFormShadow2DSteps, 60 };

static const BtlFormStep sBtlFormShadow2ESteps[] = {
    { ENEMY_SHADOW, -65, -12, 0, 0 },
    { ENEMY_SHADOW, -85, 12, 0, 1 },
};

static const BtlFormEntry sBtlFormShadow2E = { ARRAY_COUNT(sBtlFormShadow2ESteps), sBtlFormShadow2ESteps, 60 };

static const BtlFormStep sBtlFormShadow2FSteps[] = {
    { ENEMY_SHADOW, -55, 25, 0, 0 },
    { ENEMY_SHADOW, -25, -25, 0, 1 },
};

static const BtlFormEntry sBtlFormShadow2F = { ARRAY_COUNT(sBtlFormShadow2FSteps), sBtlFormShadow2FSteps, 60 };

static const BtlFormStep sBtlFormShadow1Steps[] = {
    { ENEMY_SHADOW, 64, 0, 0, 0 },
};

static const BtlFormEntry sBtlFormShadow1 = { ARRAY_COUNT(sBtlFormShadow1Steps), sBtlFormShadow1Steps, 60 };

static const BtlFormStep sBtlFormRedNocturne5Steps[] = {
    { ENEMY_RED_NOCTURNE, 25, -25, -30, 0 },
    { ENEMY_RED_NOCTURNE, 40, 0, -30, 1 },
    { ENEMY_RED_NOCTURNE, 55, 25, -30, 2 },
    { ENEMY_RED_NOCTURNE, 65, -12, -40, 3 },
    { ENEMY_RED_NOCTURNE, 85, 12, -40, 4 },
};

const BtlFormEntry gBtlFormRedNocturne5 = { ARRAY_COUNT(sBtlFormRedNocturne5Steps), sBtlFormRedNocturne5Steps, 60 };

static const BtlFormStep sBtlFormRedNocturne4Steps[] = {
    { ENEMY_RED_NOCTURNE, 25, -25, -30, 0 },
    { ENEMY_RED_NOCTURNE, 55, 25, -30, 1 },
    { ENEMY_RED_NOCTURNE, 65, -12, -40, 2 },
    { ENEMY_RED_NOCTURNE, 85, 12, -40, 3 },
};

static const BtlFormEntry sBtlFormRedNocturne4 = { ARRAY_COUNT(sBtlFormRedNocturne4Steps), sBtlFormRedNocturne4Steps, 60 };

static const BtlFormStep sBtlFormRedNocturne3ASteps[] = {
    { ENEMY_RED_NOCTURNE, 40, 0, -30, 0 },
    { ENEMY_RED_NOCTURNE, 65, -12, -40, 1 },
    { ENEMY_RED_NOCTURNE, 85, 12, -40, 2 },
};

const BtlFormEntry gBtlFormRedNocturne3A = { ARRAY_COUNT(sBtlFormRedNocturne3ASteps), sBtlFormRedNocturne3ASteps, 60 };

static const BtlFormStep sBtlFormRedNocturne3BSteps[] = {
    { ENEMY_RED_NOCTURNE, 65, -12, -40, 0 },
    { ENEMY_RED_NOCTURNE, 85, 12, -40, 1 },
    { ENEMY_RED_NOCTURNE, -40, 0, -30, 2 },
};

static const BtlFormEntry sBtlFormRedNocturne3B = { ARRAY_COUNT(sBtlFormRedNocturne3BSteps), sBtlFormRedNocturne3BSteps, 60 };

static const BtlFormStep sBtlFormRedNocturne2ASteps[] = {
    { ENEMY_RED_NOCTURNE, 65, -12, -40, 0 },
    { ENEMY_RED_NOCTURNE, 85, 12, -40, 1 },
};

static const BtlFormEntry sBtlFormRedNocturne2A = { ARRAY_COUNT(sBtlFormRedNocturne2ASteps), sBtlFormRedNocturne2ASteps, 60 };

static const BtlFormStep sBtlFormRedNocturne2BSteps[] = {
    { ENEMY_RED_NOCTURNE, -65, -12, -40, 0 },
    { ENEMY_RED_NOCTURNE, -85, 12, -40, 1 },
};

static const BtlFormEntry sBtlFormRedNocturne2B = { ARRAY_COUNT(sBtlFormRedNocturne2BSteps), sBtlFormRedNocturne2BSteps, 60 };

static const BtlFormStep sBtlFormRedNocturne1ASteps[] = {
    { ENEMY_RED_NOCTURNE, 64, 0, -50, 0 },
};

static const BtlFormEntry sBtlFormRedNocturne1A = { ARRAY_COUNT(sBtlFormRedNocturne1ASteps), sBtlFormRedNocturne1ASteps, 60 };

static const BtlFormStep sBtlFormRedNocturne1BSteps[] = {
    { ENEMY_RED_NOCTURNE, 25, -25, -30, 0 },
};

static const BtlFormEntry sBtlFormRedNocturne1B = { ARRAY_COUNT(sBtlFormRedNocturne1BSteps), sBtlFormRedNocturne1BSteps, 60 };

static const BtlFormStep sBtlFormRedNocturne1CSteps[] = {
    { ENEMY_RED_NOCTURNE, -25, -25, -30, 0 },
};

const BtlFormEntry gBtlFormRedNocturne1C = { ARRAY_COUNT(sBtlFormRedNocturne1CSteps), sBtlFormRedNocturne1CSteps, 60 };

static const BtlFormStep sBtlFormRedNocturne1DSteps[] = {
    { ENEMY_RED_NOCTURNE, 55, 25, -30, 0 },
};

const BtlFormEntry gBtlFormRedNocturne1D = { ARRAY_COUNT(sBtlFormRedNocturne1DSteps), sBtlFormRedNocturne1DSteps, 60 };

static const BtlFormStep sBtlFormRedNocturne1ESteps[] = {
    { ENEMY_RED_NOCTURNE, -55, 25, -30, 0 },
};

const BtlFormEntry gBtlFormRedNocturne1E = { ARRAY_COUNT(sBtlFormRedNocturne1ESteps), sBtlFormRedNocturne1ESteps, 60 };

static const BtlFormStep sBtlFormBlueRhapsody5Steps[] = {
    { ENEMY_BLUE_RHAPSODY, 25, -25, -30, 0 },
    { ENEMY_BLUE_RHAPSODY, 55, 25, -30, 1 },
    { ENEMY_BLUE_RHAPSODY, 90, 0, -50, 2 },
    { ENEMY_BLUE_RHAPSODY, -65, -12, -40, 3 },
    { ENEMY_BLUE_RHAPSODY, -85, 12, -40, 4 },
};

const BtlFormEntry gBtlFormBlueRhapsody5 = { ARRAY_COUNT(sBtlFormBlueRhapsody5Steps), sBtlFormBlueRhapsody5Steps, 60 };

static const BtlFormStep sBtlFormBlueRhapsody4Steps[] = {
    { ENEMY_BLUE_RHAPSODY, 40, 0, -30, 0 },
    { ENEMY_BLUE_RHAPSODY, 65, -12, -40, 1 },
    { ENEMY_BLUE_RHAPSODY, 85, 12, -40, 2 },
    { ENEMY_BLUE_RHAPSODY, 90, 0, -50, 3 },
};

static const BtlFormEntry sBtlFormBlueRhapsody4 = { ARRAY_COUNT(sBtlFormBlueRhapsody4Steps), sBtlFormBlueRhapsody4Steps, 60 };

static const BtlFormStep sBtlFormBlueRhapsody3Steps[] = {
    { ENEMY_BLUE_RHAPSODY, 65, -12, -40, 0 },
    { ENEMY_BLUE_RHAPSODY, 85, 12, -40, 1 },
    { ENEMY_BLUE_RHAPSODY, 90, 0, -50, 2 },
};

static const BtlFormEntry sBtlFormBlueRhapsody3 = { ARRAY_COUNT(sBtlFormBlueRhapsody3Steps), sBtlFormBlueRhapsody3Steps, 60 };

static const BtlFormStep sBtlFormBlueRhapsody2ASteps[] = {
    { ENEMY_BLUE_RHAPSODY, 25, -25, -30, 0 },
    { ENEMY_BLUE_RHAPSODY, 55, 25, -30, 1 },
};

static const BtlFormEntry sBtlFormBlueRhapsody2A = { ARRAY_COUNT(sBtlFormBlueRhapsody2ASteps), sBtlFormBlueRhapsody2ASteps, 60 };

static const BtlFormStep sBtlFormBlueRhapsody2BSteps[] = {
    { ENEMY_BLUE_RHAPSODY, -65, -12, -40, 0 },
    { ENEMY_BLUE_RHAPSODY, -85, 12, -40, 1 },
};

static const BtlFormEntry sBtlFormBlueRhapsody2B = { ARRAY_COUNT(sBtlFormBlueRhapsody2BSteps), sBtlFormBlueRhapsody2BSteps, 60 };

static const BtlFormStep sBtlFormBlueRhapsody2CSteps[] = {
    { ENEMY_BLUE_RHAPSODY, -55, 25, -30, 0 },
    { ENEMY_BLUE_RHAPSODY, -25, -25, -30, 1 },
};

static const BtlFormEntry sBtlFormBlueRhapsody2C = { ARRAY_COUNT(sBtlFormBlueRhapsody2CSteps), sBtlFormBlueRhapsody2CSteps, 60 };

static const BtlFormStep sBtlFormBlueRhapsody1ASteps[] = {
    { ENEMY_BLUE_RHAPSODY, 64, 0, -50, 0 },
};

const BtlFormEntry gBtlFormBlueRhapsody1A = { ARRAY_COUNT(sBtlFormBlueRhapsody1ASteps), sBtlFormBlueRhapsody1ASteps, 60 };

static const BtlFormStep sBtlFormBlueRhapsody1BSteps[] = {
    { ENEMY_BLUE_RHAPSODY, 40, 0, -30, 0 },
};

static const BtlFormEntry sBtlFormBlueRhapsody1B = { ARRAY_COUNT(sBtlFormBlueRhapsody1BSteps), sBtlFormBlueRhapsody1BSteps, 60 };

static const BtlFormStep sBtlFormBlueRhapsody1CSteps[] = {
    { ENEMY_BLUE_RHAPSODY, -64, 0, -50, 0 },
};

static const BtlFormEntry sBtlFormBlueRhapsody1C = { ARRAY_COUNT(sBtlFormBlueRhapsody1CSteps), sBtlFormBlueRhapsody1CSteps, 60 };

static const BtlFormStep sBtlFormBlueRhapsody1DSteps[] = {
    { ENEMY_BLUE_RHAPSODY, 25, -25, -30, 0 },
};

const BtlFormEntry gBtlFormBlueRhapsody1D = { ARRAY_COUNT(sBtlFormBlueRhapsody1DSteps), sBtlFormBlueRhapsody1DSteps, 60 };

static const BtlFormStep sBtlFormBlueRhapsody1ESteps[] = {
    { ENEMY_BLUE_RHAPSODY, -25, -25, -30, 0 },
};

const BtlFormEntry gBtlFormBlueRhapsody1E = { ARRAY_COUNT(sBtlFormBlueRhapsody1ESteps), sBtlFormBlueRhapsody1ESteps, 60 };

static const BtlFormStep sBtlFormBlueRhapsody1FSteps[] = {
    { ENEMY_BLUE_RHAPSODY, 55, 25, -30, 0 },
};

const BtlFormEntry gBtlFormBlueRhapsody1F = { ARRAY_COUNT(sBtlFormBlueRhapsody1FSteps), sBtlFormBlueRhapsody1FSteps, 60 };

static const BtlFormStep sBtlFormBlueRhapsody1GSteps[] = {
    { ENEMY_BLUE_RHAPSODY, -55, 25, -30, 0 },
};

static const BtlFormEntry sBtlFormBlueRhapsody1G = { ARRAY_COUNT(sBtlFormBlueRhapsody1GSteps), sBtlFormBlueRhapsody1GSteps, 60 };

static const BtlFormStep sBtlFormYellowOpera5Steps[] = {
    { ENEMY_YELLOW_OPERA, 65, -12, -40, 0 },
    { ENEMY_YELLOW_OPERA, 85, 12, -40, 1 },
    { ENEMY_YELLOW_OPERA, -25, -25, -30, 2 },
    { ENEMY_YELLOW_OPERA, -40, 0, -30, 3 },
    { ENEMY_YELLOW_OPERA, -55, 25, -30, 4 },
};

const BtlFormEntry gBtlFormYellowOpera5 = { ARRAY_COUNT(sBtlFormYellowOpera5Steps), sBtlFormYellowOpera5Steps, 60 };

static const BtlFormStep sBtlFormYellowOpera4Steps[] = {
    { ENEMY_YELLOW_OPERA, 65, -12, -40, 0 },
    { ENEMY_YELLOW_OPERA, 85, 12, -40, 1 },
    { ENEMY_YELLOW_OPERA, -65, -12, -40, 2 },
    { ENEMY_YELLOW_OPERA, -85, 12, -40, 3 },
};

static const BtlFormEntry sBtlFormYellowOpera4 = { ARRAY_COUNT(sBtlFormYellowOpera4Steps), sBtlFormYellowOpera4Steps, 60 };

static const BtlFormStep sBtlFormYellowOpera3ASteps[] = {
    { ENEMY_YELLOW_OPERA, 65, -12, -40, 0 },
    { ENEMY_YELLOW_OPERA, 85, 12, -40, 1 },
    { ENEMY_YELLOW_OPERA, -40, 0, -30, 2 },
};

static const BtlFormEntry sBtlFormYellowOpera3A = { ARRAY_COUNT(sBtlFormYellowOpera3ASteps), sBtlFormYellowOpera3ASteps, 60 };

static const BtlFormStep sBtlFormYellowOpera3BSteps[] = {
    { ENEMY_YELLOW_OPERA, -25, 25, -30, 0 },
    { ENEMY_YELLOW_OPERA, -64, 0, -50, 1 },
    { ENEMY_YELLOW_OPERA, -55, -25, -30, 2 },
};

static const BtlFormEntry sBtlFormYellowOpera3B = { ARRAY_COUNT(sBtlFormYellowOpera3BSteps), sBtlFormYellowOpera3BSteps, 60 };

static const BtlFormStep sBtlFormYellowOpera2ASteps[] = {
    { ENEMY_YELLOW_OPERA, 65, -12, -40, 0 },
    { ENEMY_YELLOW_OPERA, 85, 12, -40, 1 },
};

const BtlFormEntry gBtlFormYellowOpera2A = { ARRAY_COUNT(sBtlFormYellowOpera2ASteps), sBtlFormYellowOpera2ASteps, 60 };

static const BtlFormStep sBtlFormYellowOpera2BSteps[] = {
    { ENEMY_YELLOW_OPERA, 25, -25, -30, 0 },
    { ENEMY_YELLOW_OPERA, 55, 25, -30, 1 },
};

static const BtlFormEntry sBtlFormYellowOpera2B = { ARRAY_COUNT(sBtlFormYellowOpera2BSteps), sBtlFormYellowOpera2BSteps, 60 };

static const BtlFormStep sBtlFormYellowOpera2CSteps[] = {
    { ENEMY_YELLOW_OPERA, 40, 0, -30, 0 },
    { ENEMY_YELLOW_OPERA, -40, 0, -30, 1 },
};

const BtlFormEntry gBtlFormYellowOpera2C = { ARRAY_COUNT(sBtlFormYellowOpera2CSteps), sBtlFormYellowOpera2CSteps, 60 };

static const BtlFormStep sBtlFormYellowOpera2DSteps[] = {
    { ENEMY_YELLOW_OPERA, 40, 0, -30, 0 },
    { ENEMY_YELLOW_OPERA, 90, 0, -50, 1 },
};

static const BtlFormEntry sBtlFormYellowOpera2D = { ARRAY_COUNT(sBtlFormYellowOpera2DSteps), sBtlFormYellowOpera2DSteps, 60 };

static const BtlFormStep sBtlFormYellowOpera2ESteps[] = {
    { ENEMY_YELLOW_OPERA, -65, -12, -40, 0 },
    { ENEMY_YELLOW_OPERA, -85, 12, -40, 1 },
};

static const BtlFormEntry sBtlFormYellowOpera2E = { ARRAY_COUNT(sBtlFormYellowOpera2ESteps), sBtlFormYellowOpera2ESteps, 60 };

static const BtlFormStep sBtlFormYellowOpera2FSteps[] = {
    { ENEMY_YELLOW_OPERA, -55, 25, -30, 0 },
    { ENEMY_YELLOW_OPERA, -25, -25, -30, 1 },
};

static const BtlFormEntry sBtlFormYellowOpera2F = { ARRAY_COUNT(sBtlFormYellowOpera2FSteps), sBtlFormYellowOpera2FSteps, 60 };

static const BtlFormStep sBtlFormYellowOpera1ASteps[] = {
    { ENEMY_YELLOW_OPERA, 64, 0, -50, 0 },
};

const BtlFormEntry gBtlFormYellowOpera1A = { ARRAY_COUNT(sBtlFormYellowOpera1ASteps), sBtlFormYellowOpera1ASteps, 60 };

static const BtlFormStep sBtlFormYellowOpera1BSteps[] = {
    { ENEMY_YELLOW_OPERA, 25, -25, -30, 0 },
};

const BtlFormEntry gBtlFormYellowOpera1B = { ARRAY_COUNT(sBtlFormYellowOpera1BSteps), sBtlFormYellowOpera1BSteps, 60 };

static const BtlFormStep sBtlFormYellowOpera1CSteps[] = {
    { ENEMY_YELLOW_OPERA, -25, -25, -30, 0 },
};

static const BtlFormEntry sBtlFormYellowOpera1C = { ARRAY_COUNT(sBtlFormYellowOpera1CSteps), sBtlFormYellowOpera1CSteps, 60 };

static const BtlFormStep sBtlFormYellowOpera1DSteps[] = {
    { ENEMY_YELLOW_OPERA, 55, 25, -30, 0 },
};

const BtlFormEntry gBtlFormYellowOpera1D = { ARRAY_COUNT(sBtlFormYellowOpera1DSteps), sBtlFormYellowOpera1DSteps, 60 };

static const BtlFormStep sBtlFormYellowOpera1ESteps[] = {
    { ENEMY_YELLOW_OPERA, -55, 25, -30, 0 },
};

const BtlFormEntry gBtlFormYellowOpera1E = { ARRAY_COUNT(sBtlFormYellowOpera1ESteps), sBtlFormYellowOpera1ESteps, 60 };

static const BtlFormStep sBtlFormGreenRequiem5Steps[] = {
    { ENEMY_GREEN_REQUIEM, 65, -12, -40, 0 },
    { ENEMY_GREEN_REQUIEM, 85, 12, -40, 1 },
    { ENEMY_GREEN_REQUIEM, -25, -25, -30, 2 },
    { ENEMY_GREEN_REQUIEM, -40, 0, -30, 3 },
    { ENEMY_GREEN_REQUIEM, -55, 25, -30, 4 },
};

const BtlFormEntry gBtlFormGreenRequiem5 = { ARRAY_COUNT(sBtlFormGreenRequiem5Steps), sBtlFormGreenRequiem5Steps, 60 };

static const BtlFormStep sBtlFormGreenRequiem4Steps[] = {
    { ENEMY_GREEN_REQUIEM, 65, -12, -40, 0 },
    { ENEMY_GREEN_REQUIEM, 85, 12, -40, 1 },
    { ENEMY_GREEN_REQUIEM, -65, -12, -40, 2 },
    { ENEMY_GREEN_REQUIEM, -85, 12, -40, 3 },
};

static const BtlFormEntry sBtlFormGreenRequiem4 = { ARRAY_COUNT(sBtlFormGreenRequiem4Steps), sBtlFormGreenRequiem4Steps, 60 };

static const BtlFormStep sBtlFormGreenRequiem3ASteps[] = {
    { ENEMY_GREEN_REQUIEM, 65, -12, -40, 0 },
    { ENEMY_GREEN_REQUIEM, 85, 12, -40, 1 },
    { ENEMY_GREEN_REQUIEM, -40, 0, -30, 2 },
};

const BtlFormEntry gBtlFormGreenRequiem3A = { ARRAY_COUNT(sBtlFormGreenRequiem3ASteps), sBtlFormGreenRequiem3ASteps, 60 };

static const BtlFormStep sBtlFormGreenRequiem3BSteps[] = {
    { ENEMY_GREEN_REQUIEM, -65, -12, -40, 0 },
    { ENEMY_GREEN_REQUIEM, -85, 12, -40, 1 },
    { ENEMY_GREEN_REQUIEM, 40, 0, -30, 2 },
};

static const BtlFormEntry sBtlFormGreenRequiem3B = { ARRAY_COUNT(sBtlFormGreenRequiem3BSteps), sBtlFormGreenRequiem3BSteps, 60 };

static const BtlFormStep sBtlFormGreenRequiem2ASteps[] = {
    { ENEMY_GREEN_REQUIEM, 65, -12, -40, 0 },
    { ENEMY_GREEN_REQUIEM, 85, 12, -40, 1 },
};

static const BtlFormEntry sBtlFormGreenRequiem2A = { ARRAY_COUNT(sBtlFormGreenRequiem2ASteps), sBtlFormGreenRequiem2ASteps, 60 };

static const BtlFormStep sBtlFormGreenRequiem2BSteps[] = {
    { ENEMY_GREEN_REQUIEM, 25, -25, -30, 0 },
    { ENEMY_GREEN_REQUIEM, 55, 25, -30, 1 },
};

const BtlFormEntry gBtlFormGreenRequiem2B = { ARRAY_COUNT(sBtlFormGreenRequiem2BSteps), sBtlFormGreenRequiem2BSteps, 60 };

static const BtlFormStep sBtlFormGreenRequiem2CSteps[] = {
    { ENEMY_GREEN_REQUIEM, 40, 0, -30, 0 },
    { ENEMY_GREEN_REQUIEM, -40, 0, -30, 1 },
};

static const BtlFormEntry sBtlFormGreenRequiem2C = { ARRAY_COUNT(sBtlFormGreenRequiem2CSteps), sBtlFormGreenRequiem2CSteps, 60 };

static const BtlFormStep sBtlFormGreenRequiem2DSteps[] = {
    { ENEMY_GREEN_REQUIEM, -65, -12, -40, 0 },
    { ENEMY_GREEN_REQUIEM, -85, 12, -40, 1 },
};

static const BtlFormEntry sBtlFormGreenRequiem2D = { ARRAY_COUNT(sBtlFormGreenRequiem2DSteps), sBtlFormGreenRequiem2DSteps, 60 };

static const BtlFormStep sBtlFormGreenRequiem2ESteps[] = {
    { ENEMY_GREEN_REQUIEM, -55, 25, -30, 0 },
    { ENEMY_GREEN_REQUIEM, -25, -25, -30, 1 },
};

static const BtlFormEntry sBtlFormGreenRequiem2E = { ARRAY_COUNT(sBtlFormGreenRequiem2ESteps), sBtlFormGreenRequiem2ESteps, 60 };

static const BtlFormStep sBtlFormGreenRequiem1ASteps[] = {
    { ENEMY_GREEN_REQUIEM, 64, 0, -50, 0 },
};

static const BtlFormEntry sBtlFormGreenRequiem1A = { ARRAY_COUNT(sBtlFormGreenRequiem1ASteps), sBtlFormGreenRequiem1ASteps, 60 };

static const BtlFormStep sBtlFormGreenRequiem1BSteps[] = {
    { ENEMY_GREEN_REQUIEM, 25, -25, -30, 0 },
};

const BtlFormEntry gBtlFormGreenRequiem1B = { ARRAY_COUNT(sBtlFormGreenRequiem1BSteps), sBtlFormGreenRequiem1BSteps, 60 };

static const BtlFormStep sBtlFormGreenRequiem1CSteps[] = {
    { ENEMY_GREEN_REQUIEM, -25, -25, -30, 0 },
};

const BtlFormEntry gBtlFormGreenRequiem1C = { ARRAY_COUNT(sBtlFormGreenRequiem1CSteps), sBtlFormGreenRequiem1CSteps, 60 };

static const BtlFormStep sBtlFormGreenRequiem1DSteps[] = {
    { ENEMY_GREEN_REQUIEM, 55, 25, -30, 0 },
};

static const BtlFormEntry sBtlFormGreenRequiem1D = { ARRAY_COUNT(sBtlFormGreenRequiem1DSteps), sBtlFormGreenRequiem1DSteps, 60 };

static const BtlFormStep sBtlFormGreenRequiem1ESteps[] = {
    { ENEMY_GREEN_REQUIEM, -55, 25, -30, 0 },
};

const BtlFormEntry gBtlFormGreenRequiem1E = { ARRAY_COUNT(sBtlFormGreenRequiem1ESteps), sBtlFormGreenRequiem1ESteps, 60 };

static const BtlFormStep sBtlFormSeaNeon6Steps[] = {
    { ENEMY_SEA_NEON, 25, -25, -30, 0 },
    { ENEMY_SEA_NEON, 40, 0, -30, 1 },
    { ENEMY_SEA_NEON, 25, 25, -30, 2 },
    { ENEMY_SEA_NEON, -25, 25, -30, 3 },
    { ENEMY_SEA_NEON, -40, 0, -30, 4 },
    { ENEMY_SEA_NEON, -25, -25, -30, 5 },
};

static const BtlFormEntry sBtlFormSeaNeon6 = { ARRAY_COUNT(sBtlFormSeaNeon6Steps), sBtlFormSeaNeon6Steps, 60 };

static const BtlFormStep sBtlFormSeaNeon5Steps[] = {
    { ENEMY_SEA_NEON, 25, -25, -30, 0 },
    { ENEMY_SEA_NEON, 40, 0, -30, 1 },
    { ENEMY_SEA_NEON, 55, 25, -30, 2 },
    { ENEMY_SEA_NEON, 65, -12, -40, 3 },
    { ENEMY_SEA_NEON, 85, 12, -40, 4 },
};

const BtlFormEntry gBtlFormSeaNeon5 = { ARRAY_COUNT(sBtlFormSeaNeon5Steps), sBtlFormSeaNeon5Steps, 60 };

static const BtlFormStep sBtlFormSeaNeon4ASteps[] = {
    { ENEMY_SEA_NEON, 25, -25, -30, 0 },
    { ENEMY_SEA_NEON, 55, 25, -30, 1 },
    { ENEMY_SEA_NEON, 65, -12, -40, 2 },
    { ENEMY_SEA_NEON, 85, 12, -40, 3 },
};

static const BtlFormEntry sBtlFormSeaNeon4A = { ARRAY_COUNT(sBtlFormSeaNeon4ASteps), sBtlFormSeaNeon4ASteps, 60 };

static const BtlFormStep sBtlFormSeaNeon4BSteps[] = {
    { ENEMY_SEA_NEON, 65, -12, -40, 0 },
    { ENEMY_SEA_NEON, 85, 12, -40, 1 },
    { ENEMY_SEA_NEON, -65, -12, -40, 2 },
    { ENEMY_SEA_NEON, -85, 12, -40, 3 },
};

static const BtlFormEntry sBtlFormSeaNeon4B = { ARRAY_COUNT(sBtlFormSeaNeon4BSteps), sBtlFormSeaNeon4BSteps, 60 };

static const BtlFormStep sBtlFormSeaNeon3ASteps[] = {
    { ENEMY_SEA_NEON, 40, 0, -30, 0 },
    { ENEMY_SEA_NEON, 65, -12, -40, 1 },
    { ENEMY_SEA_NEON, 85, 12, -40, 2 },
};

static const BtlFormEntry sBtlFormSeaNeon3A = { ARRAY_COUNT(sBtlFormSeaNeon3ASteps), sBtlFormSeaNeon3ASteps, 60 };

static const BtlFormStep sBtlFormSeaNeon3BSteps[] = {
    { ENEMY_SEA_NEON, -25, 25, -30, 0 },
    { ENEMY_SEA_NEON, -64, 0, -50, 1 },
    { ENEMY_SEA_NEON, -55, -25, -30, 2 },
};

const BtlFormEntry gBtlFormSeaNeon3B = { ARRAY_COUNT(sBtlFormSeaNeon3BSteps), sBtlFormSeaNeon3BSteps, 60 };

static const BtlFormStep sBtlFormSeaNeon2Steps[] = {
    { ENEMY_SEA_NEON, 65, -12, -40, 0 },
    { ENEMY_SEA_NEON, 85, 12, -40, 1 },
};

const BtlFormEntry gBtlFormSeaNeon2 = { ARRAY_COUNT(sBtlFormSeaNeon2Steps), sBtlFormSeaNeon2Steps, 60 };

static const BtlFormStep sBtlFormSeaNeon1Steps[] = {
    { ENEMY_SEA_NEON, 64, 0, -50, 0 },
};

const BtlFormEntry gBtlFormSeaNeon1 = { ARRAY_COUNT(sBtlFormSeaNeon1Steps), sBtlFormSeaNeon1Steps, 60 };

static const BtlFormStep sBtlFormWhiteMushroom4Steps[] = {
    { ENEMY_WHITE_MUSHROOM, 65, -12, 0, 0 },
    { ENEMY_WHITE_MUSHROOM, 85, 12, 0, 1 },
    { ENEMY_WHITE_MUSHROOM, -65, -12, 0, 2 },
    { ENEMY_WHITE_MUSHROOM, -85, 12, 0, 3 },
};

static const BtlFormEntry sBtlFormWhiteMushroom4 = { ARRAY_COUNT(sBtlFormWhiteMushroom4Steps), sBtlFormWhiteMushroom4Steps, 60 };

static const BtlFormStep sBtlFormWhiteMushroom3Steps[] = {
    { ENEMY_WHITE_MUSHROOM, 40, 0, 0, 0 },
    { ENEMY_WHITE_MUSHROOM, 65, -12, 0, 1 },
    { ENEMY_WHITE_MUSHROOM, 85, 12, 0, 2 },
};

const BtlFormEntry gBtlFormWhiteMushroom3 = { ARRAY_COUNT(sBtlFormWhiteMushroom3Steps), sBtlFormWhiteMushroom3Steps, 60 };

static const BtlFormStep sBtlFormWhiteMushroom2ASteps[] = {
    { ENEMY_WHITE_MUSHROOM, 25, -25, 0, 0 },
    { ENEMY_WHITE_MUSHROOM, 55, 25, 0, 1 },
};

const BtlFormEntry gBtlFormWhiteMushroom2A = { ARRAY_COUNT(sBtlFormWhiteMushroom2ASteps), sBtlFormWhiteMushroom2ASteps, 60 };

static const BtlFormStep sBtlFormWhiteMushroom2BSteps[] = {
    { ENEMY_WHITE_MUSHROOM, 40, 0, 0, 0 },
    { ENEMY_WHITE_MUSHROOM, -40, 0, 0, 1 },
};

static const BtlFormEntry sBtlFormWhiteMushroom2B = { ARRAY_COUNT(sBtlFormWhiteMushroom2BSteps), sBtlFormWhiteMushroom2BSteps, 60 };

static const BtlFormStep sBtlFormWhiteMushroom1Steps[] = {
    { ENEMY_WHITE_MUSHROOM, 64, 0, 0, 0 },
};

static const BtlFormEntry sBtlFormWhiteMushroom1 = { ARRAY_COUNT(sBtlFormWhiteMushroom1Steps), sBtlFormWhiteMushroom1Steps, 60 };

static const BtlFormStep sBtlFormBlackFungus4Steps[] = {
    { ENEMY_BLACK_FUNGUS, 65, -12, 0, 0 },
    { ENEMY_BLACK_FUNGUS, 85, 12, 0, 1 },
    { ENEMY_BLACK_FUNGUS, -65, -12, 0, 2 },
    { ENEMY_BLACK_FUNGUS, -85, 12, 0, 3 },
};

static const BtlFormEntry sBtlFormBlackFungus4 = { ARRAY_COUNT(sBtlFormBlackFungus4Steps), sBtlFormBlackFungus4Steps, 60 };

static const BtlFormStep sBtlFormBlackFungus3Steps[] = {
    { ENEMY_BLACK_FUNGUS, 65, -12, 0, 0 },
    { ENEMY_BLACK_FUNGUS, 85, 12, 0, 1 },
    { ENEMY_BLACK_FUNGUS, -40, 0, 0, 2 },
};

const BtlFormEntry gBtlFormBlackFungus3 = { ARRAY_COUNT(sBtlFormBlackFungus3Steps), sBtlFormBlackFungus3Steps, 60 };

static const BtlFormStep sBtlFormBlackFungus2ASteps[] = {
    { ENEMY_BLACK_FUNGUS, 65, -12, 0, 0 },
    { ENEMY_BLACK_FUNGUS, 85, 12, 0, 1 },
};

const BtlFormEntry gBtlFormBlackFungus2A = { ARRAY_COUNT(sBtlFormBlackFungus2ASteps), sBtlFormBlackFungus2ASteps, 60 };

static const BtlFormStep sBtlFormBlackFungus2BSteps[] = {
    { ENEMY_BLACK_FUNGUS, 40, 0, 0, 0 },
    { ENEMY_BLACK_FUNGUS, -40, 0, 0, 1 },
};

static const BtlFormEntry sBtlFormBlackFungus2B = { ARRAY_COUNT(sBtlFormBlackFungus2BSteps), sBtlFormBlackFungus2BSteps, 60 };

static const BtlFormStep sBtlFormBlackFungus1Steps[] = {
    { ENEMY_BLACK_FUNGUS, 64, 0, 0, 0 },
};

static const BtlFormEntry sBtlFormBlackFungus1 = { ARRAY_COUNT(sBtlFormBlackFungus1Steps), sBtlFormBlackFungus1Steps, 60 };

static const BtlFormStep sBtlFormSoldier6Steps[] = {
    { ENEMY_SOLDIER, 25, -25, 0, 0 },
    { ENEMY_SOLDIER, 40, 0, 0, 1 },
    { ENEMY_SOLDIER, 55, 25, 0, 2 },
    { ENEMY_SOLDIER, -55, -25, 0, 3 },
    { ENEMY_SOLDIER, -40, 0, 0, 4 },
    { ENEMY_SOLDIER, -25, 25, 0, 5 },
};

static const BtlFormEntry sBtlFormSoldier6 = { ARRAY_COUNT(sBtlFormSoldier6Steps), sBtlFormSoldier6Steps, 60 };

static const BtlFormStep sBtlFormSoldier5ASteps[] = {
    { ENEMY_SOLDIER, 25, -25, 0, 0 },
    { ENEMY_SOLDIER, 55, 25, 0, 1 },
    { ENEMY_SOLDIER, 90, 0, 0, 2 },
    { ENEMY_SOLDIER, -65, -12, 0, 3 },
    { ENEMY_SOLDIER, -85, 12, 0, 4 },
};

const BtlFormEntry gBtlFormSoldier5A = { ARRAY_COUNT(sBtlFormSoldier5ASteps), sBtlFormSoldier5ASteps, 60 };

static const BtlFormStep sBtlFormSoldier5BSteps[] = {
    { ENEMY_SOLDIER, 65, -12, -40, 0 },
    { ENEMY_SOLDIER, 85, 12, -40, 1 },
    { ENEMY_SOLDIER, -25, -25, -30, 2 },
    { ENEMY_SOLDIER, -40, 0, -30, 3 },
    { ENEMY_SOLDIER, -55, 25, -30, 4 },
};

const BtlFormEntry gBtlFormSoldier5B = { ARRAY_COUNT(sBtlFormSoldier5BSteps), sBtlFormSoldier5BSteps, 60 };

static const BtlFormStep sBtlFormSoldier4ASteps[] = {
    { ENEMY_SOLDIER, 25, -25, 0, 0 },
    { ENEMY_SOLDIER, 55, 25, 0, 1 },
    { ENEMY_SOLDIER, 65, -12, 0, 2 },
    { ENEMY_SOLDIER, 85, 12, 0, 3 },
};

const BtlFormEntry gBtlFormSoldier4A = { ARRAY_COUNT(sBtlFormSoldier4ASteps), sBtlFormSoldier4ASteps, 60 };

static const BtlFormStep sBtlFormSoldier4BSteps[] = {
    { ENEMY_SOLDIER, 40, 0, -30, 0 },
    { ENEMY_SOLDIER, 65, -12, -40, 1 },
    { ENEMY_SOLDIER, 85, 12, -40, 2 },
    { ENEMY_SOLDIER, 90, 0, -50, 3 },
};

static const BtlFormEntry sBtlFormSoldier4B = { ARRAY_COUNT(sBtlFormSoldier4BSteps), sBtlFormSoldier4BSteps, 60 };

static const BtlFormStep sBtlFormSoldier4CSteps[] = {
    { ENEMY_SOLDIER, 65, -12, 0, 0 },
    { ENEMY_SOLDIER, 85, 12, 0, 1 },
    { ENEMY_SOLDIER, -65, -12, 0, 2 },
    { ENEMY_SOLDIER, -85, 12, 0, 3 },
};

static const BtlFormEntry sBtlFormSoldier4C = { ARRAY_COUNT(sBtlFormSoldier4CSteps), sBtlFormSoldier4CSteps, 60 };

static const BtlFormStep sBtlFormSoldier3ASteps[] = {
    { ENEMY_SOLDIER, 40, 0, -30, 0 },
    { ENEMY_SOLDIER, 65, -12, -40, 1 },
    { ENEMY_SOLDIER, 85, 12, -40, 2 },
};

const BtlFormEntry gBtlFormSoldier3A = { ARRAY_COUNT(sBtlFormSoldier3ASteps), sBtlFormSoldier3ASteps, 60 };

static const BtlFormStep sBtlFormSoldier3BSteps[] = {
    { ENEMY_SOLDIER, 65, -12, 0, 0 },
    { ENEMY_SOLDIER, 85, 12, 0, 1 },
    { ENEMY_SOLDIER, 90, 0, 0, 2 },
};

const BtlFormEntry gBtlFormSoldier3B = { ARRAY_COUNT(sBtlFormSoldier3BSteps), sBtlFormSoldier3BSteps, 60 };

static const BtlFormStep sBtlFormSoldier3CSteps[] = {
    { ENEMY_SOLDIER, 65, -12, -40, 0 },
    { ENEMY_SOLDIER, 85, 12, -40, 1 },
    { ENEMY_SOLDIER, -40, 0, -30, 2 },
};

const BtlFormEntry gBtlFormSoldier3C = { ARRAY_COUNT(sBtlFormSoldier3CSteps), sBtlFormSoldier3CSteps, 60 };

static const BtlFormStep sBtlFormSoldier3DSteps[] = {
    { ENEMY_SOLDIER, 25, -25, 0, 0 },
    { ENEMY_SOLDIER, 64, 0, 0, 1 },
    { ENEMY_SOLDIER, 55, 25, 0, 2 },
};

static const BtlFormEntry sBtlFormSoldier3D = { ARRAY_COUNT(sBtlFormSoldier3DSteps), sBtlFormSoldier3DSteps, 60 };

static const BtlFormStep sBtlFormSoldier3ESteps[] = {
    { ENEMY_SOLDIER, -25, 25, 0, 0 },
    { ENEMY_SOLDIER, -64, 0, 0, 1 },
    { ENEMY_SOLDIER, -55, -25, 0, 2 },
};

static const BtlFormEntry sBtlFormSoldier3E = { ARRAY_COUNT(sBtlFormSoldier3ESteps), sBtlFormSoldier3ESteps, 60 };

static const BtlFormStep sBtlFormSoldier2ASteps[] = {
    { ENEMY_SOLDIER, 65, -12, 0, 0 },
    { ENEMY_SOLDIER, 85, 12, 0, 1 },
};

static const BtlFormEntry sBtlFormSoldier2A = { ARRAY_COUNT(sBtlFormSoldier2ASteps), sBtlFormSoldier2ASteps, 60 };

static const BtlFormStep sBtlFormSoldier2BSteps[] = {
    { ENEMY_SOLDIER, 25, -25, -30, 0 },
    { ENEMY_SOLDIER, 55, 25, -30, 1 },
};

static const BtlFormEntry sBtlFormSoldier2B = { ARRAY_COUNT(sBtlFormSoldier2BSteps), sBtlFormSoldier2BSteps, 60 };

static const BtlFormStep sBtlFormSoldier2CSteps[] = {
    { ENEMY_SOLDIER, 40, 0, 0, 0 },
    { ENEMY_SOLDIER, -40, 0, 0, 1 },
};

static const BtlFormEntry sBtlFormSoldier2C = { ARRAY_COUNT(sBtlFormSoldier2CSteps), sBtlFormSoldier2CSteps, 60 };

static const BtlFormStep sBtlFormSoldier2DSteps[] = {
    { ENEMY_SOLDIER, -65, -12, 0, 0 },
    { ENEMY_SOLDIER, -85, 12, 0, 1 },
};

static const BtlFormEntry sBtlFormSoldier2D = { ARRAY_COUNT(sBtlFormSoldier2DSteps), sBtlFormSoldier2DSteps, 60 };

static const BtlFormStep sBtlFormSoldier1ASteps[] = {
    { ENEMY_SOLDIER, 64, 0, -50, 0 },
};

static const BtlFormEntry sBtlFormSoldier1A = { ARRAY_COUNT(sBtlFormSoldier1ASteps), sBtlFormSoldier1ASteps, 60 };

static const BtlFormStep sBtlFormSoldier1BSteps[] = {
    { ENEMY_SOLDIER, 40, 0, 0, 0 },
};

const BtlFormEntry gBtlFormSoldier1B = { ARRAY_COUNT(sBtlFormSoldier1BSteps), sBtlFormSoldier1BSteps, 60 };

static const BtlFormStep sBtlFormSoldier1CSteps[] = {
    { ENEMY_SOLDIER, -64, 0, 0, 0 },
};

static const BtlFormEntry sBtlFormSoldier1C = { ARRAY_COUNT(sBtlFormSoldier1CSteps), sBtlFormSoldier1CSteps, 60 };

static const BtlFormStep sBtlFormSoldier1DSteps[] = {
    { ENEMY_SOLDIER, -40, 0, 0, 0 },
};

const BtlFormEntry gBtlFormSoldier1D = { ARRAY_COUNT(sBtlFormSoldier1DSteps), sBtlFormSoldier1DSteps, 60 };

static const BtlFormStep sBtlFormPowerwild3Steps[] = {
    { ENEMY_POWERWILD, 40, 0, 0, 0 },
    { ENEMY_POWERWILD, 65, -12, 0, 1 },
    { ENEMY_POWERWILD, 85, 12, 0, 2 },
};

static const BtlFormEntry sBtlFormPowerwild3 = { ARRAY_COUNT(sBtlFormPowerwild3Steps), sBtlFormPowerwild3Steps, 60 };

static const BtlFormStep sBtlFormPowerwild2ASteps[] = {
    { ENEMY_POWERWILD, 25, -25, 0, 0 },
    { ENEMY_POWERWILD, 55, 25, 0, 1 },
};

static const BtlFormEntry sBtlFormPowerwild2A = { ARRAY_COUNT(sBtlFormPowerwild2ASteps), sBtlFormPowerwild2ASteps, 60 };

static const BtlFormStep sBtlFormPowerwild2BSteps[] = {
    { ENEMY_POWERWILD, -65, -12, 0, 0 },
    { ENEMY_POWERWILD, -85, 12, 0, 1 },
};

static const BtlFormEntry sBtlFormPowerwild2B = { ARRAY_COUNT(sBtlFormPowerwild2BSteps), sBtlFormPowerwild2BSteps, 60 };

static const BtlFormStep sBtlFormPowerwild1Steps[] = {
    { ENEMY_POWERWILD, 64, 0, 0, 0 },
};

static const BtlFormEntry sBtlFormPowerwild1 = { ARRAY_COUNT(sBtlFormPowerwild1Steps), sBtlFormPowerwild1Steps, 60 };

static const BtlFormStep sBtlFormBouncywild3Steps[] = {
    { ENEMY_BOUNCYWILD, 65, -12, 0, 0 },
    { ENEMY_BOUNCYWILD, 85, 12, 0, 1 },
    { ENEMY_BOUNCYWILD, 90, 0, 0, 2 },
};

static const BtlFormEntry sBtlFormBouncywild3 = { ARRAY_COUNT(sBtlFormBouncywild3Steps), sBtlFormBouncywild3Steps, 60 };

static const BtlFormStep sBtlFormBouncywild2ASteps[] = {
    { ENEMY_BOUNCYWILD, 40, 0, 0, 0 },
    { ENEMY_BOUNCYWILD, -40, 0, 0, 1 },
};

static const BtlFormEntry sBtlFormBouncywild2A = { ARRAY_COUNT(sBtlFormBouncywild2ASteps), sBtlFormBouncywild2ASteps, 60 };

static const BtlFormStep sBtlFormBouncywild2BSteps[] = {
    { ENEMY_BOUNCYWILD, -55, 25, 0, 0 },
    { ENEMY_BOUNCYWILD, -25, -25, 0, 1 },
};

static const BtlFormEntry sBtlFormBouncywild2B = { ARRAY_COUNT(sBtlFormBouncywild2BSteps), sBtlFormBouncywild2BSteps, 60 };

static const BtlFormStep sBtlFormBouncywild1Steps[] = {
    { ENEMY_BOUNCYWILD, 64, 0, 0, 0 },
};

static const BtlFormEntry sBtlFormBouncywild1 = { ARRAY_COUNT(sBtlFormBouncywild1Steps), sBtlFormBouncywild1Steps, 60 };

static const BtlFormStep sBtlFormAirSoldier4ASteps[] = {
    { ENEMY_AIR_SOLDIER, 25, -25, -30, 0 },
    { ENEMY_AIR_SOLDIER, 55, 25, -30, 1 },
    { ENEMY_AIR_SOLDIER, 65, -12, -40, 2 },
    { ENEMY_AIR_SOLDIER, 85, 12, -40, 3 },
};

static const BtlFormEntry sBtlFormAirSoldier4A = { ARRAY_COUNT(sBtlFormAirSoldier4ASteps), sBtlFormAirSoldier4ASteps, 60 };

static const BtlFormStep sBtlFormAirSoldier4BSteps[] = {
    { ENEMY_AIR_SOLDIER, 65, -12, -40, 0 },
    { ENEMY_AIR_SOLDIER, 85, 12, -40, 1 },
    { ENEMY_AIR_SOLDIER, -65, -12, -40, 2 },
    { ENEMY_AIR_SOLDIER, -85, 12, -40, 3 },
};

static const BtlFormEntry sBtlFormAirSoldier4B = { ARRAY_COUNT(sBtlFormAirSoldier4BSteps), sBtlFormAirSoldier4BSteps, 60 };

static const BtlFormStep sBtlFormAirSoldier3ASteps[] = {
    { ENEMY_AIR_SOLDIER, 65, -12, -40, 0 },
    { ENEMY_AIR_SOLDIER, 85, 12, -40, 1 },
    { ENEMY_AIR_SOLDIER, 90, 0, -50, 2 },
};

static const BtlFormEntry sBtlFormAirSoldier3A = { ARRAY_COUNT(sBtlFormAirSoldier3ASteps), sBtlFormAirSoldier3ASteps, 60 };

static const BtlFormStep sBtlFormAirSoldier3BSteps[] = {
    { ENEMY_AIR_SOLDIER, 65, -12, -40, 0 },
    { ENEMY_AIR_SOLDIER, 85, 12, -40, 1 },
    { ENEMY_AIR_SOLDIER, -40, 0, -30, 2 },
};

static const BtlFormEntry sBtlFormAirSoldier3B = { ARRAY_COUNT(sBtlFormAirSoldier3BSteps), sBtlFormAirSoldier3BSteps, 60 };

static const BtlFormStep sBtlFormAirSoldier2ASteps[] = {
    { ENEMY_AIR_SOLDIER, 40, 0, -30, 0 },
    { ENEMY_AIR_SOLDIER, -40, 0, -30, 1 },
};

static const BtlFormEntry sBtlFormAirSoldier2A = { ARRAY_COUNT(sBtlFormAirSoldier2ASteps), sBtlFormAirSoldier2ASteps, 60 };

static const BtlFormStep sBtlFormAirSoldier2BSteps[] = {
    { ENEMY_AIR_SOLDIER, -55, 25, -30, 0 },
    { ENEMY_AIR_SOLDIER, -25, -25, -30, 1 },
};

static const BtlFormEntry sBtlFormAirSoldier2B = { ARRAY_COUNT(sBtlFormAirSoldier2BSteps), sBtlFormAirSoldier2BSteps, 60 };

static const BtlFormStep sBtlFormAirSoldier1Steps[] = {
    { ENEMY_AIR_SOLDIER, 64, 0, -50, 0 },
};

const BtlFormEntry gBtlFormAirSoldier1 = { ARRAY_COUNT(sBtlFormAirSoldier1Steps), sBtlFormAirSoldier1Steps, 60 };

static const BtlFormStep sBtlFormBandit5Steps[] = {
    { ENEMY_BANDIT, 25, -25, 0, 0 },
    { ENEMY_BANDIT, 55, 25, 0, 1 },
    { ENEMY_BANDIT, 90, 0, 0, 2 },
    { ENEMY_BANDIT, -65, -12, 0, 3 },
    { ENEMY_BANDIT, -85, 12, 0, 4 },
};

const BtlFormEntry gBtlFormBandit5 = { ARRAY_COUNT(sBtlFormBandit5Steps), sBtlFormBandit5Steps, 60 };

static const BtlFormStep sBtlFormBandit4ASteps[] = {
    { ENEMY_BANDIT, 25, -25, 0, 0 },
    { ENEMY_BANDIT, 55, 25, 0, 1 },
    { ENEMY_BANDIT, 65, -12, 0, 2 },
    { ENEMY_BANDIT, 85, 12, 0, 3 },
};

const BtlFormEntry gBtlFormBandit4A = { ARRAY_COUNT(sBtlFormBandit4ASteps), sBtlFormBandit4ASteps, 60 };

static const BtlFormStep sBtlFormBandit4BSteps[] = {
    { ENEMY_BANDIT, 65, -12, 0, 0 },
    { ENEMY_BANDIT, 85, 12, 0, 1 },
    { ENEMY_BANDIT, -65, -12, 0, 2 },
    { ENEMY_BANDIT, -85, 12, 0, 3 },
};

static const BtlFormEntry sBtlFormBandit4B = { ARRAY_COUNT(sBtlFormBandit4BSteps), sBtlFormBandit4BSteps, 60 };

static const BtlFormStep sBtlFormBandit3Steps[] = {
    { ENEMY_BANDIT, 65, -12, 0, 0 },
    { ENEMY_BANDIT, 85, 12, 0, 1 },
    { ENEMY_BANDIT, -40, 0, 0, 2 },
};

const BtlFormEntry gBtlFormBandit3 = { ARRAY_COUNT(sBtlFormBandit3Steps), sBtlFormBandit3Steps, 60 };

static const BtlFormStep sBtlFormBandit2ASteps[] = {
    { ENEMY_BANDIT, 25, -25, 0, 0 },
    { ENEMY_BANDIT, 55, 25, 0, 1 },
};

static const BtlFormEntry sBtlFormBandit2A = { ARRAY_COUNT(sBtlFormBandit2ASteps), sBtlFormBandit2ASteps, 60 };

static const BtlFormStep sBtlFormBandit2BSteps[] = {
    { ENEMY_BANDIT, -55, 25, 0, 0 },
    { ENEMY_BANDIT, -25, -25, 0, 1 },
};

static const BtlFormEntry sBtlFormBandit2B = { ARRAY_COUNT(sBtlFormBandit2BSteps), sBtlFormBandit2BSteps, 60 };

static const BtlFormStep sBtlFormBandit1ASteps[] = {
    { ENEMY_BANDIT, 64, 0, 0, 0 },
};

const BtlFormEntry gBtlFormBandit1A = { ARRAY_COUNT(sBtlFormBandit1ASteps), sBtlFormBandit1ASteps, 60 };

static const BtlFormStep sBtlFormBandit1BSteps[] = {
    { ENEMY_BANDIT, 40, 0, 0, 0 },
};

static const BtlFormEntry sBtlFormBandit1B = { ARRAY_COUNT(sBtlFormBandit1BSteps), sBtlFormBandit1BSteps, 60 };

static const BtlFormStep sBtlFormBarrelSpider3Steps[] = {
    { ENEMY_BARREL_SPIDER, 40, 0, 0, 0 },
    { ENEMY_BARREL_SPIDER, 65, -12, 0, 1 },
    { ENEMY_BARREL_SPIDER, 85, 12, 0, 2 },
};

static const BtlFormEntry sBtlFormBarrelSpider3 = { ARRAY_COUNT(sBtlFormBarrelSpider3Steps), sBtlFormBarrelSpider3Steps, 60 };

static const BtlFormStep sBtlFormBarrelSpider2ASteps[] = {
    { ENEMY_BARREL_SPIDER, 65, -12, 0, 0 },
    { ENEMY_BARREL_SPIDER, 85, 12, 0, 1 },
};

static const BtlFormEntry sBtlFormBarrelSpider2A = { ARRAY_COUNT(sBtlFormBarrelSpider2ASteps), sBtlFormBarrelSpider2ASteps, 60 };

static const BtlFormStep sBtlFormBarrelSpider2BSteps[] = {
    { ENEMY_BARREL_SPIDER, 40, 0, 0, 0 },
    { ENEMY_BARREL_SPIDER, -40, 0, 0, 1 },
};

static const BtlFormEntry sBtlFormBarrelSpider2B = { ARRAY_COUNT(sBtlFormBarrelSpider2BSteps), sBtlFormBarrelSpider2BSteps, 60 };

static const BtlFormStep sBtlFormBarrelSpider2CSteps[] = {
    { ENEMY_BARREL_SPIDER, -65, -12, 0, 0 },
    { ENEMY_BARREL_SPIDER, -85, 12, 0, 1 },
};

static const BtlFormEntry sBtlFormBarrelSpider2C = { ARRAY_COUNT(sBtlFormBarrelSpider2CSteps), sBtlFormBarrelSpider2CSteps, 60 };

static const BtlFormStep sBtlFormBarrelSpider1ASteps[] = {
    { ENEMY_BARREL_SPIDER, 64, 0, 0, 0 },
};

static const BtlFormEntry sBtlFormBarrelSpider1A = { ARRAY_COUNT(sBtlFormBarrelSpider1ASteps), sBtlFormBarrelSpider1ASteps, 60 };

static const BtlFormStep sBtlFormBarrelSpider1BSteps[] = {
    { ENEMY_BARREL_SPIDER, -64, 0, 0, 0 },
};

static const BtlFormEntry sBtlFormBarrelSpider1B = { ARRAY_COUNT(sBtlFormBarrelSpider1BSteps), sBtlFormBarrelSpider1BSteps, 60 };

static const BtlFormStep sBtlFormSearchGhost3Steps[] = {
    { ENEMY_SEARCH_GHOST, 65, -12, -40, 0 },
    { ENEMY_SEARCH_GHOST, 85, 12, -40, 1 },
    { ENEMY_SEARCH_GHOST, 90, 0, -50, 2 },
};

static const BtlFormEntry sBtlFormSearchGhost3 = { ARRAY_COUNT(sBtlFormSearchGhost3Steps), sBtlFormSearchGhost3Steps, 60 };

static const BtlFormStep sBtlFormSearchGhost2ASteps[] = {
    { ENEMY_SEARCH_GHOST, 25, -25, -30, 0 },
    { ENEMY_SEARCH_GHOST, 55, 25, -30, 1 },
};

static const BtlFormEntry sBtlFormSearchGhost2A = { ARRAY_COUNT(sBtlFormSearchGhost2ASteps), sBtlFormSearchGhost2ASteps, 60 };

static const BtlFormStep sBtlFormSearchGhost2BSteps[] = {
    { ENEMY_SEARCH_GHOST, 40, 0, -30, 0 },
    { ENEMY_SEARCH_GHOST, -40, 0, -30, 1 },
};

static const BtlFormEntry sBtlFormSearchGhost2B = { ARRAY_COUNT(sBtlFormSearchGhost2BSteps), sBtlFormSearchGhost2BSteps, 60 };

static const BtlFormStep sBtlFormSearchGhost2CSteps[] = {
    { ENEMY_SEARCH_GHOST, -65, -12, -40, 0 },
    { ENEMY_SEARCH_GHOST, -85, 12, -40, 1 },
};

static const BtlFormEntry sBtlFormSearchGhost2C = { ARRAY_COUNT(sBtlFormSearchGhost2CSteps), sBtlFormSearchGhost2CSteps, 60 };

static const BtlFormStep sBtlFormSearchGhost1ASteps[] = {
    { ENEMY_SEARCH_GHOST, 64, 0, -50, 0 },
};

static const BtlFormEntry sBtlFormSearchGhost1A = { ARRAY_COUNT(sBtlFormSearchGhost1ASteps), sBtlFormSearchGhost1ASteps, 60 };

static const BtlFormStep sBtlFormSearchGhost1BSteps[] = {
    { ENEMY_SEARCH_GHOST, -64, 0, -50, 0 },
};

static const BtlFormEntry sBtlFormSearchGhost1B = { ARRAY_COUNT(sBtlFormSearchGhost1BSteps), sBtlFormSearchGhost1BSteps, 60 };

static const BtlFormStep sBtlFormScrewdiver2ASteps[] = {
    { ENEMY_SCREWDIVER, 65, -12, -40, 0 },
    { ENEMY_SCREWDIVER, 85, 12, -40, 1 },
};

static const BtlFormEntry sBtlFormScrewdiver2A = { ARRAY_COUNT(sBtlFormScrewdiver2ASteps), sBtlFormScrewdiver2ASteps, 60 };

static const BtlFormStep sBtlFormScrewdiver2BSteps[] = {
    { ENEMY_SCREWDIVER, -55, 25, -30, 0 },
    { ENEMY_SCREWDIVER, -25, -25, -30, 1 },
};

static const BtlFormEntry sBtlFormScrewdiver2B = { ARRAY_COUNT(sBtlFormScrewdiver2BSteps), sBtlFormScrewdiver2BSteps, 60 };

static const BtlFormStep sBtlFormScrewdiver1ASteps[] = {
    { ENEMY_SCREWDIVER, 64, 0, -50, 0 },
};

static const BtlFormEntry sBtlFormScrewdiver1A = { ARRAY_COUNT(sBtlFormScrewdiver1ASteps), sBtlFormScrewdiver1ASteps, 60 };

static const BtlFormStep sBtlFormScrewdiver1BSteps[] = {
    { ENEMY_SCREWDIVER, -64, 0, -50, 0 },
};

static const BtlFormEntry sBtlFormScrewdiver1B = { ARRAY_COUNT(sBtlFormScrewdiver1BSteps), sBtlFormScrewdiver1BSteps, 60 };

static const BtlFormStep sBtlFormScrewdiver1CSteps[] = {
    { ENEMY_SCREWDIVER, 25, -25, -30, 0 },
};

static const BtlFormEntry sBtlFormScrewdiver1C = { ARRAY_COUNT(sBtlFormScrewdiver1CSteps), sBtlFormScrewdiver1CSteps, 60 };

static const BtlFormStep sBtlFormScrewdiver1DSteps[] = {
    { ENEMY_SCREWDIVER, -25, -25, -30, 0 },
};

static const BtlFormEntry sBtlFormScrewdiver1D = { ARRAY_COUNT(sBtlFormScrewdiver1DSteps), sBtlFormScrewdiver1DSteps, 60 };

static const BtlFormStep sBtlFormScrewdiver1ESteps[] = {
    { ENEMY_SCREWDIVER, 55, 25, -30, 0 },
};

static const BtlFormEntry sBtlFormScrewdiver1E = { ARRAY_COUNT(sBtlFormScrewdiver1ESteps), sBtlFormScrewdiver1ESteps, 60 };

static const BtlFormStep sBtlFormScrewdiver1FSteps[] = {
    { ENEMY_SCREWDIVER, -55, 25, -30, 0 },
};

static const BtlFormEntry sBtlFormScrewdiver1F = { ARRAY_COUNT(sBtlFormScrewdiver1FSteps), sBtlFormScrewdiver1FSteps, 60 };

static const BtlFormStep sBtlFormWightKnight3Steps[] = {
    { ENEMY_WIGHT_KNIGHT, 65, -12, 0, 0 },
    { ENEMY_WIGHT_KNIGHT, 85, 12, 0, 1 },
    { ENEMY_WIGHT_KNIGHT, -40, 0, 0, 2 },
};

const BtlFormEntry gBtlFormWightKnight3 = { ARRAY_COUNT(sBtlFormWightKnight3Steps), sBtlFormWightKnight3Steps, 60 };

static const BtlFormStep sBtlFormWightKnight2ASteps[] = {
    { ENEMY_WIGHT_KNIGHT, 25, -25, 0, 0 },
    { ENEMY_WIGHT_KNIGHT, 55, 25, 0, 1 },
};

static const BtlFormEntry sBtlFormWightKnight2A = { ARRAY_COUNT(sBtlFormWightKnight2ASteps), sBtlFormWightKnight2ASteps, 60 };

static const BtlFormStep sBtlFormWightKnight2BSteps[] = {
    { ENEMY_WIGHT_KNIGHT, 40, 0, 0, 0 },
    { ENEMY_WIGHT_KNIGHT, -40, 0, 0, 1 },
};

const BtlFormEntry gBtlFormWightKnight2B = { ARRAY_COUNT(sBtlFormWightKnight2BSteps), sBtlFormWightKnight2BSteps, 60 };

static const BtlFormStep sBtlFormWightKnight2CSteps[] = {
    { ENEMY_WIGHT_KNIGHT, 65, -12, 0, 0 },
    { ENEMY_WIGHT_KNIGHT, 85, 12, 0, 1 },
};

static const BtlFormEntry sBtlFormWightKnight2C = { ARRAY_COUNT(sBtlFormWightKnight2CSteps), sBtlFormWightKnight2CSteps, 60 };

static const BtlFormStep sBtlFormWightKnight2DSteps[] = {
    { ENEMY_WIGHT_KNIGHT, -55, 25, 0, 0 },
    { ENEMY_WIGHT_KNIGHT, -25, -25, 0, 1 },
};

static const BtlFormEntry sBtlFormWightKnight2D = { ARRAY_COUNT(sBtlFormWightKnight2DSteps), sBtlFormWightKnight2DSteps, 60 };

static const BtlFormStep sBtlFormWightKnight1ASteps[] = {
    { ENEMY_WIGHT_KNIGHT, 64, 0, 0, 0 },
};

static const BtlFormEntry sBtlFormWightKnight1A = { ARRAY_COUNT(sBtlFormWightKnight1ASteps), sBtlFormWightKnight1ASteps, 60 };

static const BtlFormStep sBtlFormWightKnight1BSteps[] = {
    { ENEMY_WIGHT_KNIGHT, -64, 0, 0, 0 },
};

static const BtlFormEntry sBtlFormWightKnight1B = { ARRAY_COUNT(sBtlFormWightKnight1BSteps), sBtlFormWightKnight1BSteps, 60 };

static const BtlFormStep sBtlFormGargoyle3Steps[] = {
    { ENEMY_GARGOYLE, 40, 0, -30, 0 },
    { ENEMY_GARGOYLE, 65, -12, -40, 1 },
    { ENEMY_GARGOYLE, 85, 12, -40, 2 },
};

static const BtlFormEntry sBtlFormGargoyle3 = { ARRAY_COUNT(sBtlFormGargoyle3Steps), sBtlFormGargoyle3Steps, 60 };

static const BtlFormStep sBtlFormGargoyle2ASteps[] = {
    { ENEMY_GARGOYLE, 25, -25, -30, 0 },
    { ENEMY_GARGOYLE, 55, 25, -30, 1 },
};

static const BtlFormEntry sBtlFormGargoyle2A = { ARRAY_COUNT(sBtlFormGargoyle2ASteps), sBtlFormGargoyle2ASteps, 60 };

static const BtlFormStep sBtlFormGargoyle2BSteps[] = {
    { ENEMY_GARGOYLE, -55, 25, -30, 0 },
    { ENEMY_GARGOYLE, -25, -25, -30, 1 },
};

static const BtlFormEntry sBtlFormGargoyle2B = { ARRAY_COUNT(sBtlFormGargoyle2BSteps), sBtlFormGargoyle2BSteps, 60 };

static const BtlFormStep sBtlFormGargoyle1ASteps[] = {
    { ENEMY_GARGOYLE, 64, 0, -50, 0 },
};

static const BtlFormEntry sBtlFormGargoyle1A = { ARRAY_COUNT(sBtlFormGargoyle1ASteps), sBtlFormGargoyle1ASteps, 60 };

static const BtlFormStep sBtlFormGargoyle1BSteps[] = {
    { ENEMY_GARGOYLE, -64, 0, -50, 0 },
};

static const BtlFormEntry sBtlFormGargoyle1B = { ARRAY_COUNT(sBtlFormGargoyle1BSteps), sBtlFormGargoyle1BSteps, 60 };

static const BtlFormStep sBtlFormPirate5Steps[] = {
    { ENEMY_PIRATE, 25, -25, 0, 0 },
    { ENEMY_PIRATE, 40, 0, 0, 1 },
    { ENEMY_PIRATE, 55, 25, 0, 2 },
    { ENEMY_PIRATE, 65, -12, 0, 3 },
    { ENEMY_PIRATE, 85, 12, 0, 4 },
};

const BtlFormEntry gBtlFormPirate5 = { ARRAY_COUNT(sBtlFormPirate5Steps), sBtlFormPirate5Steps, 60 };

static const BtlFormStep sBtlFormPirate4Steps[] = {
    { ENEMY_PIRATE, 65, -12, 0, 0 },
    { ENEMY_PIRATE, 85, 12, 0, 1 },
    { ENEMY_PIRATE, -65, -12, 0, 2 },
    { ENEMY_PIRATE, -85, 12, 0, 3 },
};

const BtlFormEntry gBtlFormPirate4 = { ARRAY_COUNT(sBtlFormPirate4Steps), sBtlFormPirate4Steps, 60 };

static const BtlFormStep sBtlFormPirate3ASteps[] = {
    { ENEMY_PIRATE, 65, -12, 0, 0 },
    { ENEMY_PIRATE, 85, 12, 0, 1 },
    { ENEMY_PIRATE, 90, 0, 0, 2 },
};

static const BtlFormEntry sBtlFormPirate3A = { ARRAY_COUNT(sBtlFormPirate3ASteps), sBtlFormPirate3ASteps, 60 };

static const BtlFormStep sBtlFormPirate3BSteps[] = {
    { ENEMY_PIRATE, -65, -12, 0, 0 },
    { ENEMY_PIRATE, -85, 12, 0, 1 },
    { ENEMY_PIRATE, 40, 0, 0, 2 },
};

static const BtlFormEntry sBtlFormPirate3B = { ARRAY_COUNT(sBtlFormPirate3BSteps), sBtlFormPirate3BSteps, 60 };

static const BtlFormStep sBtlFormPirate2ASteps[] = {
    { ENEMY_PIRATE, 65, -12, 0, 0 },
    { ENEMY_PIRATE, 85, 12, 0, 1 },
};

const BtlFormEntry gBtlFormPirate2A = { ARRAY_COUNT(sBtlFormPirate2ASteps), sBtlFormPirate2ASteps, 60 };

static const BtlFormStep sBtlFormPirate2BSteps[] = {
    { ENEMY_PIRATE, -65, -12, 0, 0 },
    { ENEMY_PIRATE, -85, 12, 0, 1 },
};

const BtlFormEntry gBtlFormPirate2B = { ARRAY_COUNT(sBtlFormPirate2BSteps), sBtlFormPirate2BSteps, 60 };

static const BtlFormStep sBtlFormPirate2CSteps[] = {
    { ENEMY_PIRATE, 40, 0, 0, 0 },
    { ENEMY_PIRATE, -40, 0, 0, 1 },
};

static const BtlFormEntry sBtlFormPirate2C = { ARRAY_COUNT(sBtlFormPirate2CSteps), sBtlFormPirate2CSteps, 60 };

static const BtlFormStep sBtlFormPirate1Steps[] = {
    { ENEMY_PIRATE, 64, 0, 0, 0 },
};

const BtlFormEntry gBtlFormPirate1 = { ARRAY_COUNT(sBtlFormPirate1Steps), sBtlFormPirate1Steps, 60 };

static const BtlFormStep sBtlFormAirPirate2ASteps[] = {
    { ENEMY_AIR_PIRATE, 25, -25, -30, 0 },
    { ENEMY_AIR_PIRATE, 55, 25, -30, 1 },
};

static const BtlFormEntry sBtlFormAirPirate2A = { ARRAY_COUNT(sBtlFormAirPirate2ASteps), sBtlFormAirPirate2ASteps, 60 };

static const BtlFormStep sBtlFormAirPirate2BSteps[] = {
    { ENEMY_AIR_PIRATE, 40, 0, -30, 0 },
    { ENEMY_AIR_PIRATE, -40, 0, -30, 1 },
};

static const BtlFormEntry sBtlFormAirPirate2B = { ARRAY_COUNT(sBtlFormAirPirate2BSteps), sBtlFormAirPirate2BSteps, 60 };

static const BtlFormStep sBtlFormAirPirate2CSteps[] = {
    { ENEMY_AIR_PIRATE, -55, 25, -30, 0 },
    { ENEMY_AIR_PIRATE, -25, -25, -30, 1 },
};

static const BtlFormEntry sBtlFormAirPirate2C = { ARRAY_COUNT(sBtlFormAirPirate2CSteps), sBtlFormAirPirate2CSteps, 60 };

static const BtlFormStep sBtlFormAirPirate1ASteps[] = {
    { ENEMY_AIR_PIRATE, 64, 0, -50, 0 },
};

static const BtlFormEntry sBtlFormAirPirate1A = { ARRAY_COUNT(sBtlFormAirPirate1ASteps), sBtlFormAirPirate1ASteps, 60 };

static const BtlFormStep sBtlFormAirPirate1BSteps[] = {
    { ENEMY_AIR_PIRATE, -64, 0, -50, 0 },
};

const BtlFormEntry gBtlFormAirPirate1B = { ARRAY_COUNT(sBtlFormAirPirate1BSteps), sBtlFormAirPirate1BSteps, 60 };

static const BtlFormStep sBtlFormAirPirate1CSteps[] = {
    { ENEMY_AIR_PIRATE, 25, -25, -30, 0 },
};

static const BtlFormEntry sBtlFormAirPirate1C = { ARRAY_COUNT(sBtlFormAirPirate1CSteps), sBtlFormAirPirate1CSteps, 60 };

static const BtlFormStep sBtlFormDarkball2ASteps[] = {
    { ENEMY_DARKBALL, 65, -12, -40, 0 },
    { ENEMY_DARKBALL, 85, 12, -40, 1 },
};

const BtlFormEntry gBtlFormDarkball2A = { ARRAY_COUNT(sBtlFormDarkball2ASteps), sBtlFormDarkball2ASteps, 60 };

static const BtlFormStep sBtlFormDarkball2BSteps[] = {
    { ENEMY_DARKBALL, 25, -25, -30, 0 },
    { ENEMY_DARKBALL, 55, 25, -30, 1 },
};

static const BtlFormEntry sBtlFormDarkball2B = { ARRAY_COUNT(sBtlFormDarkball2BSteps), sBtlFormDarkball2BSteps, 60 };

static const BtlFormStep sBtlFormDarkball2CSteps[] = {
    { ENEMY_DARKBALL, 40, 0, -30, 0 },
    { ENEMY_DARKBALL, -40, 0, -30, 1 },
};

static const BtlFormEntry sBtlFormDarkball2C = { ARRAY_COUNT(sBtlFormDarkball2CSteps), sBtlFormDarkball2CSteps, 60 };

static const BtlFormStep sBtlFormDarkball2DSteps[] = {
    { ENEMY_DARKBALL, 40, 0, -30, 0 },
    { ENEMY_DARKBALL, 90, 0, -50, 1 },
};

static const BtlFormEntry sBtlFormDarkball2D = { ARRAY_COUNT(sBtlFormDarkball2DSteps), sBtlFormDarkball2DSteps, 60 };

static const BtlFormStep sBtlFormDarkball2ESteps[] = {
    { ENEMY_DARKBALL, -65, -12, -40, 0 },
    { ENEMY_DARKBALL, -85, 12, -40, 1 },
};

static const BtlFormEntry sBtlFormDarkball2E = { ARRAY_COUNT(sBtlFormDarkball2ESteps), sBtlFormDarkball2ESteps, 60 };

static const BtlFormStep sBtlFormDarkball2FSteps[] = {
    { ENEMY_DARKBALL, -55, 25, -30, 0 },
    { ENEMY_DARKBALL, -25, -25, -30, 1 },
};

static const BtlFormEntry sBtlFormDarkball2F = { ARRAY_COUNT(sBtlFormDarkball2FSteps), sBtlFormDarkball2FSteps, 60 };

static const BtlFormStep sBtlFormDarkball1ASteps[] = {
    { ENEMY_DARKBALL, 64, 0, -50, 0 },
};

static const BtlFormEntry sBtlFormDarkball1A = { ARRAY_COUNT(sBtlFormDarkball1ASteps), sBtlFormDarkball1ASteps, 60 };

static const BtlFormStep sBtlFormDarkball1BSteps[] = {
    { ENEMY_DARKBALL, -64, 0, -50, 0 },
};

static const BtlFormEntry sBtlFormDarkball1B = { ARRAY_COUNT(sBtlFormDarkball1BSteps), sBtlFormDarkball1BSteps, 60 };

static const BtlFormStep sBtlFormDarkball1CSteps[] = {
    { ENEMY_DARKBALL, 25, -25, -30, 0 },
};

static const BtlFormEntry sBtlFormDarkball1C = { ARRAY_COUNT(sBtlFormDarkball1CSteps), sBtlFormDarkball1CSteps, 60 };

static const BtlFormStep sBtlFormDarkball1DSteps[] = {
    { ENEMY_DARKBALL, -25, -25, -30, 0 },
};

static const BtlFormEntry sBtlFormDarkball1D = { ARRAY_COUNT(sBtlFormDarkball1DSteps), sBtlFormDarkball1DSteps, 60 };

static const BtlFormStep sBtlFormDarkball1ESteps[] = {
    { ENEMY_DARKBALL, 55, 25, -30, 0 },
};

static const BtlFormEntry sBtlFormDarkball1E = { ARRAY_COUNT(sBtlFormDarkball1ESteps), sBtlFormDarkball1ESteps, 60 };

static const BtlFormStep sBtlFormDarkball1FSteps[] = {
    { ENEMY_DARKBALL, -55, 25, -30, 0 },
};

static const BtlFormEntry sBtlFormDarkball1F = { ARRAY_COUNT(sBtlFormDarkball1FSteps), sBtlFormDarkball1FSteps, 60 };

static const BtlFormStep sBtlFormWyvern2Steps[] = {
    { ENEMY_WYVERN, 65, -12, -40, 0 },
    { ENEMY_WYVERN, 85, 12, -40, 1 },
};

static const BtlFormEntry sBtlFormWyvern2 = { ARRAY_COUNT(sBtlFormWyvern2Steps), sBtlFormWyvern2Steps, 60 };

static const BtlFormStep sBtlFormWyvern1ASteps[] = {
    { ENEMY_WYVERN, 64, 0, -50, 0 },
};

static const BtlFormEntry sBtlFormWyvern1A = { ARRAY_COUNT(sBtlFormWyvern1ASteps), sBtlFormWyvern1ASteps, 60 };

static const BtlFormStep sBtlFormWyvern1BSteps[] = {
    { ENEMY_WYVERN, -64, 0, -50, 0 },
};

static const BtlFormEntry sBtlFormWyvern1B = { ARRAY_COUNT(sBtlFormWyvern1BSteps), sBtlFormWyvern1BSteps, 60 };

static const BtlFormStep sBtlFormWizard3Steps[] = {
    { ENEMY_WIZARD, 65, -12, -40, 0 },
    { ENEMY_WIZARD, 85, 12, -40, 1 },
    { ENEMY_WIZARD, 90, 0, -50, 2 },
};

const BtlFormEntry gBtlFormWizard3 = { ARRAY_COUNT(sBtlFormWizard3Steps), sBtlFormWizard3Steps, 60 };

static const BtlFormStep sBtlFormWizard2Steps[] = {
    { ENEMY_WIZARD, 40, 0, -30, 0 },
    { ENEMY_WIZARD, -40, 0, -30, 1 },
};

static const BtlFormEntry sBtlFormWizard2 = { ARRAY_COUNT(sBtlFormWizard2Steps), sBtlFormWizard2Steps, 60 };

static const BtlFormStep sBtlFormWizard1ASteps[] = {
    { ENEMY_WIZARD, 64, 0, -50, 0 },
};

static const BtlFormEntry sBtlFormWizard1A = { ARRAY_COUNT(sBtlFormWizard1ASteps), sBtlFormWizard1ASteps, 60 };

static const BtlFormStep sBtlFormWizard1BSteps[] = {
    { ENEMY_WIZARD, -64, 0, -50, 0 },
};

static const BtlFormEntry sBtlFormWizard1B = { ARRAY_COUNT(sBtlFormWizard1BSteps), sBtlFormWizard1BSteps, 60 };

static const BtlFormStep sBtlFormNeoshadow3ASteps[] = {
    { ENEMY_NEOSHADOW, 40, 0, 0, 0 },
    { ENEMY_NEOSHADOW, 65, -12, 0, 1 },
    { ENEMY_NEOSHADOW, 85, 12, 0, 2 },
};

const BtlFormEntry gBtlFormNeoshadow3A = { ARRAY_COUNT(sBtlFormNeoshadow3ASteps), sBtlFormNeoshadow3ASteps, 60 };

static const BtlFormStep sBtlFormNeoshadow3BSteps[] = {
    { ENEMY_NEOSHADOW, 65, -12, 0, 0 },
    { ENEMY_NEOSHADOW, 85, 12, 0, 1 },
    { ENEMY_NEOSHADOW, -40, 0, 0, 2 },
};

static const BtlFormEntry sBtlFormNeoshadow3B = { ARRAY_COUNT(sBtlFormNeoshadow3BSteps), sBtlFormNeoshadow3BSteps, 60 };

static const BtlFormStep sBtlFormNeoshadow2Steps[] = {
    { ENEMY_NEOSHADOW, 65, -12, 0, 0 },
    { ENEMY_NEOSHADOW, 85, 12, 0, 1 },
};

static const BtlFormEntry sBtlFormNeoshadow2 = { ARRAY_COUNT(sBtlFormNeoshadow2Steps), sBtlFormNeoshadow2Steps, 60 };

static const BtlFormStep sBtlFormNeoshadow1ASteps[] = {
    { ENEMY_NEOSHADOW, 64, 0, 0, 0 },
};

static const BtlFormEntry sBtlFormNeoshadow1A = { ARRAY_COUNT(sBtlFormNeoshadow1ASteps), sBtlFormNeoshadow1ASteps, 60 };

static const BtlFormStep sBtlFormNeoshadow1BSteps[] = {
    { ENEMY_NEOSHADOW, -64, 0, 0, 0 },
};

static const BtlFormEntry sBtlFormNeoshadow1B = { ARRAY_COUNT(sBtlFormNeoshadow1BSteps), sBtlFormNeoshadow1BSteps, 60 };

static const BtlFormStep sBtlFormLargeBody2ASteps[] = {
    { ENEMY_LARGE_BODY, 65, -12, 0, 0 },
    { ENEMY_LARGE_BODY, 85, 12, 0, 1 },
};

const BtlFormEntry gBtlFormLargeBody2A = { ARRAY_COUNT(sBtlFormLargeBody2ASteps), sBtlFormLargeBody2ASteps, 60 };

static const BtlFormStep sBtlFormLargeBody2BSteps[] = {
    { ENEMY_LARGE_BODY, 40, 0, 0, 0 },
    { ENEMY_LARGE_BODY, -40, 0, 0, 1 },
};

static const BtlFormEntry sBtlFormLargeBody2B = { ARRAY_COUNT(sBtlFormLargeBody2BSteps), sBtlFormLargeBody2BSteps, 60 };

static const BtlFormStep sBtlFormLargeBody1ASteps[] = {
    { ENEMY_LARGE_BODY, 64, 0, 0, 0 },
};

static const BtlFormEntry sBtlFormLargeBody1A = { ARRAY_COUNT(sBtlFormLargeBody1ASteps), sBtlFormLargeBody1ASteps, 60 };

static const BtlFormStep sBtlFormLargeBody1BSteps[] = {
    { ENEMY_LARGE_BODY, -64, 0, 0, 0 },
};

static const BtlFormEntry sBtlFormLargeBody1B = { ARRAY_COUNT(sBtlFormLargeBody1BSteps), sBtlFormLargeBody1BSteps, 60 };

static const BtlFormStep sBtlFormFatBandit2ASteps[] = {
    { ENEMY_FAT_BANDIT, 25, -25, 0, 0 },
    { ENEMY_FAT_BANDIT, 55, 25, 0, 1 },
};

const BtlFormEntry gBtlFormFatBandit2A = { ARRAY_COUNT(sBtlFormFatBandit2ASteps), sBtlFormFatBandit2ASteps, 60 };

static const BtlFormStep sBtlFormFatBandit2BSteps[] = {
    { ENEMY_FAT_BANDIT, 40, 0, 0, 0 },
    { ENEMY_FAT_BANDIT, -40, 0, 0, 1 },
};

static const BtlFormEntry sBtlFormFatBandit2B = { ARRAY_COUNT(sBtlFormFatBandit2BSteps), sBtlFormFatBandit2BSteps, 60 };

static const BtlFormStep sBtlFormFatBandit1ASteps[] = {
    { ENEMY_FAT_BANDIT, -64, 0, 0, 0 },
};

static const BtlFormEntry sBtlFormFatBandit1A = { ARRAY_COUNT(sBtlFormFatBandit1ASteps), sBtlFormFatBandit1ASteps, 60 };

static const BtlFormStep sBtlFormFatBandit1BSteps[] = {
    { ENEMY_FAT_BANDIT, 64, 0, 0, 0 },
};

static const BtlFormEntry sBtlFormFatBandit1B = { ARRAY_COUNT(sBtlFormFatBandit1BSteps), sBtlFormFatBandit1BSteps, 60 };

static const BtlFormStep sBtlFormAquatank2Steps[] = {
    { ENEMY_AQUATANK, 65, -12, -40, 0 },
    { ENEMY_AQUATANK, 85, 12, -40, 1 },
};

const BtlFormEntry gBtlFormAquatank2 = { ARRAY_COUNT(sBtlFormAquatank2Steps), sBtlFormAquatank2Steps, 60 };

static const BtlFormStep sBtlFormAquatank1ASteps[] = {
    { ENEMY_AQUATANK, 64, 0, -50, 0 },
};

static const BtlFormEntry sBtlFormAquatank1A = { ARRAY_COUNT(sBtlFormAquatank1ASteps), sBtlFormAquatank1ASteps, 60 };

static const BtlFormStep sBtlFormAquatank1BSteps[] = {
    { ENEMY_AQUATANK, -64, 0, -50, 0 },
};

static const BtlFormEntry sBtlFormAquatank1B = { ARRAY_COUNT(sBtlFormAquatank1BSteps), sBtlFormAquatank1BSteps, 60 };

static const BtlFormStep sBtlFormDefender2Steps[] = {
    { ENEMY_DEFENDER, 25, -25, 0, 0 },
    { ENEMY_DEFENDER, 55, 25, 0, 1 },
};

static const BtlFormEntry sBtlFormDefender2 = { ARRAY_COUNT(sBtlFormDefender2Steps), sBtlFormDefender2Steps, 60 };

static const BtlFormStep sBtlFormDefender1Steps[] = {
    { ENEMY_DEFENDER, 64, 0, 0, 0 },
};

static const BtlFormEntry sBtlFormDefender1 = { ARRAY_COUNT(sBtlFormDefender1Steps), sBtlFormDefender1Steps, 60 };

static const BtlFormStep sBtlFormTornadoStep5ASteps[] = {
    { ENEMY_TORNADO_STEP, 25, -25, 0, 0 },
    { ENEMY_TORNADO_STEP, 40, 0, 0, 1 },
    { ENEMY_TORNADO_STEP, 55, 25, 0, 2 },
    { ENEMY_TORNADO_STEP, 65, -12, 0, 3 },
    { ENEMY_TORNADO_STEP, 85, 12, 0, 4 },
};

const BtlFormEntry gBtlFormTornadoStep5A = { ARRAY_COUNT(sBtlFormTornadoStep5ASteps), sBtlFormTornadoStep5ASteps, 60 };

static const BtlFormStep sBtlFormTornadoStep5BSteps[] = {
    { ENEMY_TORNADO_STEP, 25, -25, 0, 0 },
    { ENEMY_TORNADO_STEP, 55, 25, 0, 1 },
    { ENEMY_TORNADO_STEP, 90, 0, 0, 2 },
    { ENEMY_TORNADO_STEP, -65, -12, 0, 3 },
    { ENEMY_TORNADO_STEP, -85, 12, 0, 4 },
};

static const BtlFormEntry sBtlFormTornadoStep5B = { ARRAY_COUNT(sBtlFormTornadoStep5BSteps), sBtlFormTornadoStep5BSteps, 60 };

static const BtlFormStep sBtlFormTornadoStep4Steps[] = {
    { ENEMY_TORNADO_STEP, 25, -25, 0, 0 },
    { ENEMY_TORNADO_STEP, 55, 25, 0, 1 },
    { ENEMY_TORNADO_STEP, 65, -12, 0, 2 },
    { ENEMY_TORNADO_STEP, 85, 12, 0, 3 },
};

const BtlFormEntry gBtlFormTornadoStep4 = { ARRAY_COUNT(sBtlFormTornadoStep4Steps), sBtlFormTornadoStep4Steps, 60 };

static const BtlFormStep sBtlFormTornadoStep3ASteps[] = {
    { ENEMY_TORNADO_STEP, 40, 0, 0, 0 },
    { ENEMY_TORNADO_STEP, 65, -12, 0, 1 },
    { ENEMY_TORNADO_STEP, 85, 12, 0, 2 },
};

static const BtlFormEntry sBtlFormTornadoStep3A = { ARRAY_COUNT(sBtlFormTornadoStep3ASteps), sBtlFormTornadoStep3ASteps, 60 };

static const BtlFormStep sBtlFormTornadoStep3BSteps[] = {
    { ENEMY_TORNADO_STEP, 25, -25, 0, 0 },
    { ENEMY_TORNADO_STEP, 64, 0, 0, 1 },
    { ENEMY_TORNADO_STEP, 55, 25, 0, 2 },
};

static const BtlFormEntry sBtlFormTornadoStep3B = { ARRAY_COUNT(sBtlFormTornadoStep3BSteps), sBtlFormTornadoStep3BSteps, 60 };

static const BtlFormStep sBtlFormTornadoStep3CSteps[] = {
    { ENEMY_TORNADO_STEP, -25, 25, 0, 0 },
    { ENEMY_TORNADO_STEP, -64, 0, 0, 1 },
    { ENEMY_TORNADO_STEP, -55, -25, 0, 2 },
};

static const BtlFormEntry sBtlFormTornadoStep3C = { ARRAY_COUNT(sBtlFormTornadoStep3CSteps), sBtlFormTornadoStep3CSteps, 60 };

static const BtlFormStep sBtlFormTornadoStep2ASteps[] = {
    { ENEMY_TORNADO_STEP, 65, -12, 0, 0 },
    { ENEMY_TORNADO_STEP, 85, 12, 0, 1 },
};

const BtlFormEntry gBtlFormTornadoStep2A = { ARRAY_COUNT(sBtlFormTornadoStep2ASteps), sBtlFormTornadoStep2ASteps, 60 };

static const BtlFormStep sBtlFormTornadoStep2BSteps[] = {
    { ENEMY_TORNADO_STEP, 40, 0, 0, 0 },
    { ENEMY_TORNADO_STEP, -40, 0, 0, 1 },
};

static const BtlFormEntry sBtlFormTornadoStep2B = { ARRAY_COUNT(sBtlFormTornadoStep2BSteps), sBtlFormTornadoStep2BSteps, 60 };

static const BtlFormStep sBtlFormTornadoStep2CSteps[] = {
    { ENEMY_TORNADO_STEP, -65, -12, 0, 0 },
    { ENEMY_TORNADO_STEP, -85, 12, 0, 1 },
};

static const BtlFormEntry sBtlFormTornadoStep2C = { ARRAY_COUNT(sBtlFormTornadoStep2CSteps), sBtlFormTornadoStep2CSteps, 60 };

static const BtlFormStep sBtlFormTornadoStep2DSteps[] = {
    { ENEMY_TORNADO_STEP, -55, 25, 0, 0 },
    { ENEMY_TORNADO_STEP, -25, -25, 0, 1 },
};

const BtlFormEntry gBtlFormTornadoStep2D = { ARRAY_COUNT(sBtlFormTornadoStep2DSteps), sBtlFormTornadoStep2DSteps, 60 };

static const BtlFormStep sBtlFormTornadoStep1Steps[] = {
    { ENEMY_TORNADO_STEP, 64, 0, 0, 0 },
};

static const BtlFormEntry sBtlFormTornadoStep1 = { ARRAY_COUNT(sBtlFormTornadoStep1Steps), sBtlFormTornadoStep1Steps, 60 };

static const BtlFormStep sBtlFormCrescendo5Steps[] = {
    { ENEMY_CRESCENDO, 25, -25, 0, 0 },
    { ENEMY_CRESCENDO, 40, 0, 0, 1 },
    { ENEMY_CRESCENDO, 55, 25, 0, 2 },
    { ENEMY_CRESCENDO, 65, -12, 0, 3 },
    { ENEMY_CRESCENDO, 85, 12, 0, 4 },
};

static const BtlFormEntry sBtlFormCrescendo5 = { ARRAY_COUNT(sBtlFormCrescendo5Steps), sBtlFormCrescendo5Steps, 60 };

static const BtlFormStep sBtlFormCrescendo4Steps[] = {
    { ENEMY_CRESCENDO, 25, -25, 0, 0 },
    { ENEMY_CRESCENDO, 55, 25, 0, 1 },
    { ENEMY_CRESCENDO, 65, -12, 0, 2 },
    { ENEMY_CRESCENDO, 85, 12, 0, 3 },
};

const BtlFormEntry gBtlFormCrescendo4 = { ARRAY_COUNT(sBtlFormCrescendo4Steps), sBtlFormCrescendo4Steps, 60 };

static const BtlFormStep sBtlFormCrescendo3ASteps[] = {
    { ENEMY_CRESCENDO, 40, 0, 0, 0 },
    { ENEMY_CRESCENDO, 65, -12, 0, 1 },
    { ENEMY_CRESCENDO, 85, 12, 0, 2 },
};

const BtlFormEntry gBtlFormCrescendo3A = { ARRAY_COUNT(sBtlFormCrescendo3ASteps), sBtlFormCrescendo3ASteps, 60 };

static const BtlFormStep sBtlFormCrescendo3BSteps[] = {
    { ENEMY_CRESCENDO, 25, -25, 0, 0 },
    { ENEMY_CRESCENDO, 64, 0, 0, 1 },
    { ENEMY_CRESCENDO, 55, 25, 0, 2 },
};

static const BtlFormEntry sBtlFormCrescendo3B = { ARRAY_COUNT(sBtlFormCrescendo3BSteps), sBtlFormCrescendo3BSteps, 60 };

static const BtlFormStep sBtlFormCrescendo3CSteps[] = {
    { ENEMY_CRESCENDO, -25, 25, 0, 0 },
    { ENEMY_CRESCENDO, -64, 0, 0, 1 },
    { ENEMY_CRESCENDO, -55, -25, 0, 2 },
};

static const BtlFormEntry sBtlFormCrescendo3C = { ARRAY_COUNT(sBtlFormCrescendo3CSteps), sBtlFormCrescendo3CSteps, 60 };

static const BtlFormStep sBtlFormCrescendo2ASteps[] = {
    { ENEMY_CRESCENDO, 65, -12, 0, 0 },
    { ENEMY_CRESCENDO, 85, 12, 0, 1 },
};

static const BtlFormEntry sBtlFormCrescendo2A = { ARRAY_COUNT(sBtlFormCrescendo2ASteps), sBtlFormCrescendo2ASteps, 60 };

static const BtlFormStep sBtlFormCrescendo2BSteps[] = {
    { ENEMY_CRESCENDO, -65, -12, 0, 0 },
    { ENEMY_CRESCENDO, -85, 12, 0, 1 },
};

static const BtlFormEntry sBtlFormCrescendo2B = { ARRAY_COUNT(sBtlFormCrescendo2BSteps), sBtlFormCrescendo2BSteps, 60 };

static const BtlFormStep sBtlFormCrescendo2CSteps[] = {
    { ENEMY_CRESCENDO, -55, 25, 0, 0 },
    { ENEMY_CRESCENDO, -25, -25, 0, 1 },
};

static const BtlFormEntry sBtlFormCrescendo2C = { ARRAY_COUNT(sBtlFormCrescendo2CSteps), sBtlFormCrescendo2CSteps, 60 };

static const BtlFormStep sBtlFormCrescendo1Steps[] = {
    { ENEMY_CRESCENDO, 64, 0, 0, 0 },
};

static const BtlFormEntry sBtlFormCrescendo1 = { ARRAY_COUNT(sBtlFormCrescendo1Steps), sBtlFormCrescendo1Steps, 60 };

static const BtlFormStep sBtlFormCreeperPlant6Steps[] = {
    { ENEMY_CREEPER_PLANT, 25, -25, 0, 0 },
    { ENEMY_CREEPER_PLANT, 40, 0, 0, 1 },
    { ENEMY_CREEPER_PLANT, 25, 25, 0, 2 },
    { ENEMY_CREEPER_PLANT, -25, 25, 0, 3 },
    { ENEMY_CREEPER_PLANT, -40, 0, 0, 4 },
    { ENEMY_CREEPER_PLANT, -25, -25, 0, 5 },
};

static const BtlFormEntry sBtlFormCreeperPlant6 = { ARRAY_COUNT(sBtlFormCreeperPlant6Steps), sBtlFormCreeperPlant6Steps, 60 };

static const BtlFormStep sBtlFormCreeperPlant5ASteps[] = {
    { ENEMY_CREEPER_PLANT, 25, -25, 0, 0 },
    { ENEMY_CREEPER_PLANT, 40, 0, 0, 1 },
    { ENEMY_CREEPER_PLANT, 55, 25, 0, 2 },
    { ENEMY_CREEPER_PLANT, 65, -12, 0, 3 },
    { ENEMY_CREEPER_PLANT, 85, 12, 0, 4 },
};

const BtlFormEntry gBtlFormCreeperPlant5A = { ARRAY_COUNT(sBtlFormCreeperPlant5ASteps), sBtlFormCreeperPlant5ASteps, 60 };

static const BtlFormStep sBtlFormCreeperPlant5BSteps[] = {
    { ENEMY_CREEPER_PLANT, 25, -25, 0, 0 },
    { ENEMY_CREEPER_PLANT, 55, 25, 0, 1 },
    { ENEMY_CREEPER_PLANT, 90, 0, 0, 2 },
    { ENEMY_CREEPER_PLANT, -65, -12, 0, 3 },
    { ENEMY_CREEPER_PLANT, -85, 12, 0, 4 },
};

static const BtlFormEntry sBtlFormCreeperPlant5B = { ARRAY_COUNT(sBtlFormCreeperPlant5BSteps), sBtlFormCreeperPlant5BSteps, 60 };

static const BtlFormStep sBtlFormCreeperPlant4Steps[] = {
    { ENEMY_CREEPER_PLANT, 25, -25, 0, 0 },
    { ENEMY_CREEPER_PLANT, 55, 25, 0, 1 },
    { ENEMY_CREEPER_PLANT, 65, -12, 0, 2 },
    { ENEMY_CREEPER_PLANT, 85, 12, 0, 3 },
};

static const BtlFormEntry sBtlFormCreeperPlant4 = { ARRAY_COUNT(sBtlFormCreeperPlant4Steps), sBtlFormCreeperPlant4Steps, 60 };

static const BtlFormStep sBtlFormCreeperPlant3ASteps[] = {
    { ENEMY_CREEPER_PLANT, 40, 0, 0, 0 },
    { ENEMY_CREEPER_PLANT, 65, -12, 0, 1 },
    { ENEMY_CREEPER_PLANT, 85, 12, 0, 2 },
};

const BtlFormEntry gBtlFormCreeperPlant3A = { ARRAY_COUNT(sBtlFormCreeperPlant3ASteps), sBtlFormCreeperPlant3ASteps, 60 };

static const BtlFormStep sBtlFormCreeperPlant3BSteps[] = {
    { ENEMY_CREEPER_PLANT, -65, -12, 0, 0 },
    { ENEMY_CREEPER_PLANT, -85, 12, 0, 1 },
    { ENEMY_CREEPER_PLANT, 40, 0, 0, 2 },
};

static const BtlFormEntry sBtlFormCreeperPlant3B = { ARRAY_COUNT(sBtlFormCreeperPlant3BSteps), sBtlFormCreeperPlant3BSteps, 60 };

static const BtlFormStep sBtlFormCreeperPlant2ASteps[] = {
    { ENEMY_CREEPER_PLANT, 65, -12, 0, 0 },
    { ENEMY_CREEPER_PLANT, 85, 12, 0, 1 },
};

static const BtlFormEntry sBtlFormCreeperPlant2A = { ARRAY_COUNT(sBtlFormCreeperPlant2ASteps), sBtlFormCreeperPlant2ASteps, 60 };

static const BtlFormStep sBtlFormCreeperPlant1Steps[] = {
    { ENEMY_CREEPER_PLANT, 64, 0, 0, 0 },
};

static const BtlFormEntry sBtlFormCreeperPlant1 = { ARRAY_COUNT(sBtlFormCreeperPlant1Steps), sBtlFormCreeperPlant1Steps, 60 };

static const BtlFormStep sBtlFormCreeperPlant2BSteps[] = {
    { ENEMY_CREEPER_PLANT, 40, 0, 0, 0 },
    { ENEMY_CREEPER_PLANT, -40, 0, 0, 1 },
};

static const BtlFormEntry sBtlFormCreeperPlant2B = { ARRAY_COUNT(sBtlFormCreeperPlant2BSteps), sBtlFormCreeperPlant2BSteps, 60 };

static const BtlFormStep sBtlFormCreeperPlant2CSteps[] = {
    { ENEMY_CREEPER_PLANT, -65, -12, 0, 0 },
    { ENEMY_CREEPER_PLANT, -85, 12, 0, 1 },
};

static const BtlFormEntry sBtlFormCreeperPlant2C = { ARRAY_COUNT(sBtlFormCreeperPlant2CSteps), sBtlFormCreeperPlant2CSteps, 60 };

static const BtlFormStep sBtlFormCardSoldierSpade3Steps[] = {
    { ENEMY_CARD_SOLDIER_SPADE, 65, -12, 0, 0 },
    { ENEMY_CARD_SOLDIER_SPADE, 85, 12, 0, 1 },
    { ENEMY_CARD_SOLDIER_SPADE, -40, 0, 0, 2 },
};

static const BtlFormEntry sBtlFormCardSoldierSpade3 = { ARRAY_COUNT(sBtlFormCardSoldierSpade3Steps), sBtlFormCardSoldierSpade3Steps, 60 };

static const BtlFormStep sBtlFormCardSoldierSpade2Steps[] = {
    { ENEMY_CARD_SOLDIER_SPADE, -55, 25, 0, 0 },
    { ENEMY_CARD_SOLDIER_SPADE, -25, -25, 0, 1 },
};

static const BtlFormEntry sBtlFormCardSoldierSpade2 = { ARRAY_COUNT(sBtlFormCardSoldierSpade2Steps), sBtlFormCardSoldierSpade2Steps, 60 };

static const BtlFormStep sBtlFormCardSoldierSpade1Steps[] = {
    { ENEMY_CARD_SOLDIER_SPADE, 64, 0, 0, 0 },
};

const BtlFormEntry gBtlFormCardSoldierSpade1 = { ARRAY_COUNT(sBtlFormCardSoldierSpade1Steps), sBtlFormCardSoldierSpade1Steps, 60 };

static const BtlFormStep sBtlFormCardSoldierHeart3Steps[] = {
    { ENEMY_CARD_SOLDIER_HEART, 65, -12, 0, 0 },
    { ENEMY_CARD_SOLDIER_HEART, 85, 12, 0, 1 },
    { ENEMY_CARD_SOLDIER_HEART, 90, 0, 0, 2 },
};

const BtlFormEntry gBtlFormCardSoldierHeart3 = { ARRAY_COUNT(sBtlFormCardSoldierHeart3Steps), sBtlFormCardSoldierHeart3Steps, 60 };

static const BtlFormStep sBtlFormCardSoldierHeart2Steps[] = {
    { ENEMY_CARD_SOLDIER_HEART, 25, -25, 0, 0 },
    { ENEMY_CARD_SOLDIER_HEART, 55, 25, 0, 1 },
};

const BtlFormEntry gBtlFormCardSoldierHeart2 = { ARRAY_COUNT(sBtlFormCardSoldierHeart2Steps), sBtlFormCardSoldierHeart2Steps, 60 };

static const BtlFormStep sBtlFormCardSoldierHeart1Steps[] = {
    { ENEMY_CARD_SOLDIER_HEART, 64, 0, 0, 0 },
};

static const BtlFormEntry sBtlFormCardSoldierHeart1 = { ARRAY_COUNT(sBtlFormCardSoldierHeart1Steps), sBtlFormCardSoldierHeart1Steps, 60 };

static const BtlFormList sBtlFormLists[144] = {
    { 14, &gBtlFormListEntries[0], 256 },
    { 4, &gBtlFormListEntries[14], 256 },
    { 1, &gBtlFormListEntries[18], 256 },
    { 2, &gBtlFormListEntries[19], 256 },
    { 5, &gBtlFormListEntries[21], 256 },
    { 1, &gBtlFormListEntries[26], 256 },
    { 1, &gBtlFormListEntries[27], 256 },
    { 1, &gBtlFormListEntries[28], 256 },
    { 1, &gBtlFormListEntries[29], 256 },
    { 1, &gBtlFormListEntries[30], 256 },
    { 1, &gBtlFormListEntries[31], 256 },
    { 2, &gBtlFormListEntries[32], 256 },
    { 2, &gBtlFormListEntries[34], 266 },
    { 3, &gBtlFormListEntries[36], 256 },
    { 3, &gBtlFormListEntries[39], 256 },
    { 3, &gBtlFormListEntries[42], 256 },
    { 4, &gBtlFormListEntries[45], 256 },
    { 1, &gBtlFormListEntries[49], 256 },
    { 3, &gBtlFormListEntries[50], 256 },
    { 4, &gBtlFormListEntries[53], 256 },
    { 4, &gBtlFormListEntries[57], 256 },
    { 2, &gBtlFormListEntries[61], 256 },
    { 1, &gBtlFormListEntries[63], 256 },
    { 3, &gBtlFormListEntries[64], 256 },
    { 2, &gBtlFormListEntries[67], 256 },
    { 2, &gBtlFormListEntries[69], 256 },
    { 3, &gBtlFormListEntries[71], 256 },
    { 3, &gBtlFormListEntries[74], 256 },
    { 3, &gBtlFormListEntries[77], 256 },
    { 3, &gBtlFormListEntries[80], 256 },
    { 3, &gBtlFormListEntries[83], 256 },
    { 4, &gBtlFormListEntries[86], 256 },
    { 3, &gBtlFormListEntries[90], 256 },
    { 3, &gBtlFormListEntries[93], 256 },
    { 2, &gBtlFormListEntries[96], 256 },
    { 4, &gBtlFormListEntries[98], 256 },
    { 3, &gBtlFormListEntries[102], 256 },
    { 3, &gBtlFormListEntries[105], 256 },
    { 3, &gBtlFormListEntries[108], 256 },
    { 4, &gBtlFormListEntries[111], 256 },
    { 3, &gBtlFormListEntries[115], 256 },
    { 3, &gBtlFormListEntries[118], 256 },
    { 2, &gBtlFormListEntries[121], 256 },
    { 3, &gBtlFormListEntries[123], 256 },
    { 4, &gBtlFormListEntries[126], 256 },
    { 4, &gBtlFormListEntries[130], 256 },
    { 4, &gBtlFormListEntries[134], 256 },
    { 3, &gBtlFormListEntries[138], 256 },
    { 3, &gBtlFormListEntries[141], 256 },
    { 4, &gBtlFormListEntries[144], 256 },
    { 6, &gBtlFormListEntries[148], 256 },
    { 3, &gBtlFormListEntries[154], 256 },
    { 3, &gBtlFormListEntries[157], 256 },
    { 2, &gBtlFormListEntries[160], 256 },
    { 2, &gBtlFormListEntries[162], 256 },
    { 3, &gBtlFormListEntries[164], 256 },
    { 3, &gBtlFormListEntries[167], 256 },
    { 1, &gBtlFormListEntries[170], 256 },
    { 4, &gBtlFormListEntries[171], 256 },
    { 5, &gBtlFormListEntries[175], 256 },
    { 4, &gBtlFormListEntries[180], 256 },
    { 4, &gBtlFormListEntries[184], 256 },
    { 3, &gBtlFormListEntries[188], 256 },
    { 2, &gBtlFormListEntries[191], 256 },
    { 2, &gBtlFormListEntries[193], 256 },
    { 3, &gBtlFormListEntries[195], 256 },
    { 4, &gBtlFormListEntries[198], 256 },
    { 3, &gBtlFormListEntries[202], 256 },
    { 1, &gBtlFormListEntries[205], 256 },
    { 2, &gBtlFormListEntries[206], 256 },
    { 5, &gBtlFormListEntries[208], 256 },
    { 1, &gBtlFormListEntries[213], 64 },
    { 2, &gBtlFormListEntries[214], 128 },
    { 2, &gBtlFormListEntries[216], 256 },
    { 2, &gBtlFormListEntries[218], 256 },
    { 2, &gBtlFormListEntries[220], 256 },
    { 2, &gBtlFormListEntries[222], 256 },
    { 3, &gBtlFormListEntries[224], 256 },
    { 3, &gBtlFormListEntries[227], 256 },
    { 4, &gBtlFormListEntries[230], 256 },
    { 2, &gBtlFormListEntries[234], 256 },
    { 2, &gBtlFormListEntries[236], 256 },
    { 4, &gBtlFormListEntries[238], 256 },
    { 3, &gBtlFormListEntries[242], 256 },
    { 4, &gBtlFormListEntries[245], 256 },
    { 5, &gBtlFormListEntries[249], 256 },
    { 3, &gBtlFormListEntries[254], 256 },
    { 5, &gBtlFormListEntries[257], 256 },
    { 3, &gBtlFormListEntries[262], 256 },
    { 4, &gBtlFormListEntries[265], 256 },
    { 4, &gBtlFormListEntries[269], 256 },
    { 4, &gBtlFormListEntries[273], 256 },
    { 5, &gBtlFormListEntries[277], 256 },
    { 3, &gBtlFormListEntries[282], 256 },
    { 3, &gBtlFormListEntries[285], 256 },
    { 2, &gBtlFormListEntries[288], 256 },
    { 2, &gBtlFormListEntries[290], 256 },
    { 3, &gBtlFormListEntries[292], 256 },
    { 4, &gBtlFormListEntries[295], 256 },
    { 4, &gBtlFormListEntries[299], 256 },
    { 4, &gBtlFormListEntries[303], 256 },
    { 2, &gBtlFormListEntries[307], 256 },
    { 3, &gBtlFormListEntries[309], 256 },
    { 3, &gBtlFormListEntries[312], 256 },
    { 3, &gBtlFormListEntries[315], 256 },
    { 3, &gBtlFormListEntries[318], 256 },
    { 3, &gBtlFormListEntries[321], 256 },
    { 3, &gBtlFormListEntries[324], 256 },
    { 3, &gBtlFormListEntries[327], 256 },
    { 2, &gBtlFormListEntries[330], 256 },
    { 3, &gBtlFormListEntries[332], 256 },
    { 4, &gBtlFormListEntries[335], 256 },
    { 3, &gBtlFormListEntries[339], 256 },
    { 3, &gBtlFormListEntries[342], 256 },
    { 3, &gBtlFormListEntries[345], 256 },
    { 2, &gBtlFormListEntries[348], 256 },
    { 4, &gBtlFormListEntries[350], 256 },
    { 4, &gBtlFormListEntries[354], 256 },
    { 4, &gBtlFormListEntries[358], 256 },
    { 4, &gBtlFormListEntries[362], 256 },
    { 4, &gBtlFormListEntries[366], 256 },
    { 4, &gBtlFormListEntries[370], 256 },
    { 3, &gBtlFormListEntries[374], 256 },
#ifdef VERSION_EU
    { 6, &gBtlFormListEntries[377], 164 },
#else
    { 6, &gBtlFormListEntries[377], 256 },
#endif
    { 5, &gBtlFormListEntries[383], 256 },
    { 3, &gBtlFormListEntries[388], 256 },
#ifdef VERSION_EU
    { 8, &gBtlFormListEntries[391], 256 },
#else
    { 9, &gBtlFormListEntries[391], 256 },
#endif
    { 4, &gBtlFormListEntries[400 - FORMATION_LIST_DROP], 256 },
    { 4, &gBtlFormListEntries[404 - FORMATION_LIST_DROP], 256 },
#ifdef VERSION_EU
    { 8, &gBtlFormListEntries[408 - FORMATION_LIST_DROP], 196 },
#else
    { 8, &gBtlFormListEntries[408 - FORMATION_LIST_DROP], 256 },
#endif
    { 5, &gBtlFormListEntries[416 - FORMATION_LIST_DROP], 256 },
    { 3, &gBtlFormListEntries[421 - FORMATION_LIST_DROP], 256 },
    { 2, &gBtlFormListEntries[424 - FORMATION_LIST_DROP], 256 },
    { 1, &gBtlFormListEntries[426 - FORMATION_LIST_DROP], 256 },
    { 1, &gBtlFormListEntries[427 - FORMATION_LIST_DROP], 256 },
    { 2, &gBtlFormListEntries[428 - FORMATION_LIST_DROP], 256 },
    { 1, &gBtlFormListEntries[430 - FORMATION_LIST_DROP], 256 },
    { 2, &gBtlFormListEntries[431 - FORMATION_LIST_DROP], 256 },
    { 2, &gBtlFormListEntries[433 - FORMATION_LIST_DROP], 256 },
    { 1, &gBtlFormListEntries[435 - FORMATION_LIST_DROP], 256 },
    { 1, &gBtlFormListEntries[436 - FORMATION_LIST_DROP], 256 },
    { 3, &gBtlFormListEntries[437 - FORMATION_LIST_DROP], 256 },
    { 3, &gBtlFormListEntries[440 - FORMATION_LIST_DROP], 256 },
    { 3, &gBtlFormListEntries[443 - FORMATION_LIST_DROP], 256 },
};

const BtlFormEntry* gBtlFormListEntries[] = {
    &sBtlFormShadow8,
    &sBtlFormShadow4D,
    &sBtlFormShadow2F,
    &sBtlFormShadow6A,
    &sBtlFormShadow4C,
    &sBtlFormShadow3F,
    &sBtlFormShadow2C,
    &sBtlFormShadow4C,
    &sBtlFormShadow3E,
    &sBtlFormShadow2D,
    &sBtlFormShadow4D,
    &sBtlFormShadow3C,
    &sBtlFormShadow7,
    &sBtlFormShadow1,
    &sBtlFormCardSoldierSpade3,
    &sBtlFormCardSoldierHeart1,
    &sBtlFormCardSoldierSpade2,
    &sBtlFormCardSoldierHeart1,
    &sBtlFormBarrelSpider3,
    &sBtlFormBarrelSpider3,
    &sBtlFormBarrelSpider2C,
    &sBtlFormBarrelSpider3,
    &sBtlFormBarrelSpider2B,
    &sBtlFormBarrelSpider1A,
    &sBtlFormBarrelSpider2A,
    &sBtlFormBarrelSpider1B,
    &sBtlFormWhiteMushroom1,
    &sBtlFormWhiteMushroom2B,
    &sBtlFormWhiteMushroom4,
    &sBtlFormBlackFungus1,
    &sBtlFormBlackFungus2B,
    &sBtlFormBlackFungus4,
    &sBtlFormShadow4A,
    &sBtlFormLargeBody1A,
    &sBtlFormCreeperPlant2A,
    &sBtlFormSoldier3E,
    &sBtlFormRedNocturne2A,
    &sBtlFormCrescendo2B,
    &sBtlFormLargeBody1A,
    &sBtlFormSoldier3D,
    &sBtlFormCreeperPlant2C,
    &sBtlFormCrescendo2A,
    &sBtlFormShadow2A,
    &sBtlFormLargeBody1A,
    &sBtlFormRedNocturne4,
    &sBtlFormShadow2A,
    &sBtlFormSoldier2D,
    &sBtlFormLargeBody1A,
    &sBtlFormLargeBody1B,
    &sBtlFormCrescendo5,
    &sBtlFormCreeperPlant2B,
    &sBtlFormShadow3F,
    &sBtlFormRedNocturne3B,
    &sBtlFormRedNocturne3B,
    &sBtlFormLargeBody1B,
    &sBtlFormLargeBody1A,
    &sBtlFormShadow3C,
    &sBtlFormRedNocturne4,
    &sBtlFormCrescendo2A,
    &sBtlFormCrescendo2B,
    &sBtlFormSoldier4C,
    &sBtlFormShadow5C,
    &sBtlFormSoldier2B,
    &sBtlFormSoldier6,
    &sBtlFormShadow2B,
    &sBtlFormAirSoldier3B,
    &sBtlFormShadow2F,
    &sBtlFormSoldier2D,
    &sBtlFormAirSoldier3A,
    &sBtlFormAirSoldier4B,
    &sBtlFormAirSoldier2A,
    &sBtlFormShadow3D,
    &sBtlFormSoldier3E,
    &sBtlFormAirSoldier2A,
    &sBtlFormShadow3D,
    &sBtlFormShadow4D,
    &sBtlFormShadow5B,
    &sBtlFormSoldier4B,
    &sBtlFormShadow2F,
    &sBtlFormShadow2E,
    &sBtlFormAirSoldier2B,
    &sBtlFormShadow3C,
    &sBtlFormShadow3D,
    &sBtlFormAirSoldier4A,
    &sBtlFormSoldier2D,
    &sBtlFormShadow3D,
    &sBtlFormShadow2F,
    &sBtlFormDarkball2D,
    &sBtlFormShadow2E,
    &sBtlFormDarkball1A,
    &sBtlFormTornadoStep3B,
    &sBtlFormDarkball1F,
    &sBtlFormDarkball1D,
    &sBtlFormCrescendo3C,
    &sBtlFormDarkball1C,
    &sBtlFormDarkball1E,
    &sBtlFormCreeperPlant4,
    &sBtlFormDarkball2E,
    &sBtlFormTornadoStep2B,
    &sBtlFormCrescendo2B,
    &sBtlFormTornadoStep1,
    &sBtlFormCrescendo1,
    &sBtlFormShadow2C,
    &sBtlFormCreeperPlant6,
    &sBtlFormShadow4C,
    &sBtlFormCreeperPlant4,
    &sBtlFormTornadoStep2C,
    &sBtlFormTornadoStep1,
    &sBtlFormCreeperPlant4,
    &sBtlFormCrescendo2C,
    &sBtlFormTornadoStep1,
    &sBtlFormDarkball2D,
    &sBtlFormShadow5C,
    &sBtlFormDarkball1C,
    &sBtlFormDarkball1E,
    &sBtlFormTornadoStep3C,
    &sBtlFormCrescendo3B,
    &sBtlFormCreeperPlant3B,
    &sBtlFormShadow3A,
    &sBtlFormLargeBody1A,
    &sBtlFormPowerwild2A,
    &sBtlFormBlueRhapsody3,
    &sBtlFormPowerwild3,
    &sBtlFormPowerwild2A,
    &sBtlFormLargeBody1A,
    &sBtlFormPowerwild2B,
    &sBtlFormBlueRhapsody3,
    &sBtlFormBouncywild2A,
    &sBtlFormBlueRhapsody2B,
    &sBtlFormBlueRhapsody1C,
    &sBtlFormPowerwild2A,
    &sBtlFormBouncywild1,
    &sBtlFormPowerwild2A,
    &sBtlFormBouncywild1,
    &sBtlFormLargeBody1A,
    &sBtlFormBouncywild2B,
    &sBtlFormLargeBody1B,
    &sBtlFormBlueRhapsody2A,
    &sBtlFormBouncywild3,
    &sBtlFormLargeBody1A,
    &sBtlFormBlueRhapsody2A,
    &sBtlFormShadow4C,
    &sBtlFormPowerwild3,
    &sBtlFormLargeBody2B,
    &sBtlFormShadow5C,
    &sBtlFormBlueRhapsody2A,
    &sBtlFormLargeBody1A,
    &sBtlFormBlueRhapsody2C,
    &sBtlFormBlueRhapsody4,
    &sBtlFormShadow3D,
    &sBtlFormPowerwild1,
    &sBtlFormPowerwild2A,
    &sBtlFormBouncywild2A,
    &sBtlFormBouncywild2B,
    &sBtlFormShadow4A,
    &sBtlFormGreenRequiem2C,
    &sBtlFormYellowOpera2E,
    &sBtlFormAirSoldier2B,
    &sBtlFormSearchGhost2A,
    &sBtlFormTornadoStep2B,
    &sBtlFormLargeBody1A,
    &sBtlFormTornadoStep3C,
    &sBtlFormYellowOpera4,
    &sBtlFormGreenRequiem4,
    &sBtlFormShadow3B,
    &sBtlFormAirSoldier2B,
    &sBtlFormLargeBody1B,
    &sBtlFormSearchGhost3,
    &sBtlFormYellowOpera3B,
    &sBtlFormYellowOpera2D,
    &sBtlFormTornadoStep5B,
    &sBtlFormLargeBody2B,
    &sBtlFormGreenRequiem4,
    &sBtlFormLargeBody1A,
    &sBtlFormGreenRequiem2E,
    &sBtlFormShadow5D,
    &sBtlFormShadow4D,
    &sBtlFormShadow3D,
    &sBtlFormShadow2F,
    &sBtlFormShadow1,
    &sBtlFormAirSoldier4B,
    &sBtlFormSearchGhost1A,
    &sBtlFormSearchGhost1B,
    &sBtlFormSearchGhost1A,
    &sBtlFormShadow2A,
    &sBtlFormWightKnight1A,
    &sBtlFormShadow2E,
    &sBtlFormWightKnight1B,
    &sBtlFormSearchGhost1A,
    &sBtlFormCreeperPlant3B,
    &sBtlFormGargoyle1B,
    &sBtlFormWightKnight2C,
    &sBtlFormCreeperPlant2B,
    &sBtlFormGargoyle3,
    &sBtlFormSearchGhost2C,
    &sBtlFormShadow4C,
    &sBtlFormCreeperPlant2B,
    &sBtlFormSearchGhost2A,
    &sBtlFormGargoyle2A,
    &sBtlFormWightKnight1B,
    &sBtlFormGargoyle1A,
    &sBtlFormWightKnight1A,
    &sBtlFormShadow5B,
    &sBtlFormGargoyle2B,
    &sBtlFormSearchGhost1B,
    &sBtlFormCreeperPlant5B,
    &sBtlFormCreeperPlant3B,
    &sBtlFormWightKnight2A,
    &sBtlFormGargoyle2A,
    &sBtlFormWightKnight2D,
    &sBtlFormShadow4C,
    &sBtlFormGargoyle2B,
    &sBtlFormWightKnight2A,
    &sBtlFormShadow3D,
    &sBtlFormRedNocturne1A,
    &sBtlFormShadow2B,
    &sBtlFormShadow2B,
    &sBtlFormBlueRhapsody2A,
    &sBtlFormRedNocturne2A,
    &sBtlFormBlueRhapsody2A,
    &sBtlFormSoldier1A,
    &sBtlFormShadow2B,
    &sBtlFormSoldier1C,
    &sBtlFormRedNocturne2A,
    &sBtlFormShadow2C,
    &sBtlFormSoldier1A,
    &sBtlFormSoldier1C,
    &sBtlFormSoldier1A,
    &sBtlFormSoldier1C,
    &sBtlFormBlueRhapsody2A,
    &sBtlFormShadow2B,
    &sBtlFormBlueRhapsody1B,
    &sBtlFormRedNocturne1A,
    &sBtlFormSoldier2C,
    &sBtlFormShadow4C,
    &sBtlFormSoldier2A,
    &sBtlFormSeaNeon4A,
    &sBtlFormDarkball2E,
    &sBtlFormScrewdiver2A,
    &sBtlFormAquatank1A,
    &sBtlFormScrewdiver1B,
    &sBtlFormScrewdiver1A,
    &sBtlFormDarkball2C,
    &sBtlFormDarkball1B,
    &sBtlFormDarkball1A,
    &sBtlFormSearchGhost2A,
    &sBtlFormSeaNeon3A,
    &sBtlFormScrewdiver1A,
    &sBtlFormAquatank1B,
    &sBtlFormDarkball1A,
    &sBtlFormSearchGhost1B,
    &sBtlFormDarkball1A,
    &sBtlFormSearchGhost1B,
    &sBtlFormDarkball1A,
    &sBtlFormSeaNeon6,
    &sBtlFormDarkball1A,
    &sBtlFormDarkball1B,
    &sBtlFormAquatank1A,
    &sBtlFormScrewdiver1C,
    &sBtlFormScrewdiver1D,
    &sBtlFormScrewdiver1E,
    &sBtlFormScrewdiver1F,
    &sBtlFormSeaNeon4B,
    &sBtlFormSearchGhost2B,
    &sBtlFormAquatank1A,
    &sBtlFormScrewdiver2A,
    &sBtlFormDarkball1B,
    &sBtlFormDarkball1A,
    &sBtlFormScrewdiver1B,
    &sBtlFormSeaNeon4A,
    &sBtlFormScrewdiver2B,
    &sBtlFormAquatank1A,
    &sBtlFormScrewdiver1B,
    &sBtlFormShadow2E,
    &sBtlFormBandit1B,
    &sBtlFormFatBandit1B,
    &sBtlFormBandit2A,
    &sBtlFormYellowOpera2B,
    &sBtlFormGreenRequiem2E,
    &sBtlFormFatBandit1B,
    &sBtlFormGreenRequiem2A,
    &sBtlFormYellowOpera2E,
    &sBtlFormShadow3F,
    &sBtlFormAirSoldier3B,
    &sBtlFormShadow3F,
    &sBtlFormAirSoldier4A,
    &sBtlFormGreenRequiem1A,
    &sBtlFormGreenRequiem1A,
    &sBtlFormFatBandit2B,
    &sBtlFormFatBandit1B,
    &sBtlFormBandit4B,
    &sBtlFormGreenRequiem2C,
    &sBtlFormShadow4A,
    &sBtlFormAirSoldier2A,
    &sBtlFormYellowOpera4,
    &sBtlFormShadow3D,
    &sBtlFormAirSoldier2A,
    &sBtlFormBandit2A,
    &sBtlFormFatBandit1B,
    &sBtlFormBandit2A,
    &sBtlFormGreenRequiem3B,
    &sBtlFormYellowOpera3A,
    &sBtlFormBandit2B,
    &sBtlFormBandit4B,
    &sBtlFormFatBandit1A,
    &sBtlFormBandit2A,
    &sBtlFormFatBandit1B,
    &sBtlFormShadow3D,
    &sBtlFormPirate3A,
    &sBtlFormAirPirate2A,
    &sBtlFormDarkball1B,
    &sBtlFormDarkball1A,
    &sBtlFormShadow4B,
    &sBtlFormCrescendo2B,
    &sBtlFormPirate2C,
    &sBtlFormShadow4C,
    &sBtlFormDarkball2F,
    &sBtlFormDarkball1A,
    &sBtlFormAirPirate2B,
    &sBtlFormCrescendo3B,
    &sBtlFormAirPirate1C,
    &sBtlFormPirate3A,
    &sBtlFormDarkball1B,
    &sBtlFormDarkball1A,
    &sBtlFormPirate3A,
    &sBtlFormAirPirate2C,
    &sBtlFormPirate3B,
    &sBtlFormShadow5B,
    &sBtlFormPirate3B,
    &sBtlFormPirate2C,
    &sBtlFormDarkball2D,
    &sBtlFormCrescendo3C,
    &sBtlFormAirPirate2C,
    &sBtlFormPirate3A,
    &sBtlFormAirPirate1A,
    &sBtlFormShadow4D,
    &sBtlFormDarkball1C,
    &sBtlFormDarkball1C,
    &sBtlFormDarkball1E,
    &sBtlFormShadow6A,
    &sBtlFormDefender1,
    &sBtlFormTornadoStep2C,
    &sBtlFormWyvern2,
    &sBtlFormWizard1B,
    &sBtlFormDarkball2D,
    &sBtlFormTornadoStep3A,
    &sBtlFormWyvern1B,
    &sBtlFormWyvern1A,
    &sBtlFormDefender2,
    &sBtlFormWizard2,
    &sBtlFormShadow4C,
    &sBtlFormWizard2,
    &sBtlFormShadow2B,
    &sBtlFormShadow2F,
    &sBtlFormWyvern2,
    &sBtlFormDarkball1B,
    &sBtlFormDarkball1A,
    &sBtlFormDarkball1B,
    &sBtlFormDefender1,
    &sBtlFormWyvern1B,
    &sBtlFormDefender1,
    &sBtlFormWizard1B,
    &sBtlFormDarkball2B,
    &sBtlFormTornadoStep3C,
    &sBtlFormDarkball1C,
    &sBtlFormDarkball1E,
    &sBtlFormShadow5C,
    &sBtlFormDefender1,
    &sBtlFormWizard1B,
    &sBtlFormDefender1,
    &sBtlFormShadow4C,
    &sBtlFormWizard2,
    &sBtlFormShadow4A,
    &sBtlFormDarkball2F,
    &sBtlFormShadow5B,
    &sBtlFormNeoshadow2,
    &sBtlFormNeoshadow1A,
    &sBtlFormDefender1,
    &sBtlFormRedNocturne1B,
    &sBtlFormBlueRhapsody1G,
    &sBtlFormYellowOpera1C,
    &sBtlFormGreenRequiem1D,
    &sBtlFormWizard2,
    &sBtlFormDarkball2C,
    &sBtlFormDarkball1C,
    &sBtlFormDarkball1E,
    &sBtlFormDarkball1F,
    &sBtlFormDarkball2F,
    &sBtlFormWyvern2,
    &sBtlFormDefender2,
    &sBtlFormYellowOpera4,
    &sBtlFormRedNocturne2A,
    &sBtlFormBlueRhapsody2A,
    &sBtlFormYellowOpera2F,
    &sBtlFormGreenRequiem2D,
#ifndef VERSION_EU
    &sBtlFormWizard1A,
#endif
    &sBtlFormGreenRequiem2A,
    &sBtlFormYellowOpera2B,
    &sBtlFormBlueRhapsody2C,
    &sBtlFormRedNocturne2B,
    &sBtlFormWyvern2,
    &sBtlFormNeoshadow1A,
    &sBtlFormNeoshadow1B,
    &sBtlFormDefender1,
    &sBtlFormShadow4C,
    &sBtlFormWizard2,
    &sBtlFormNeoshadow1B,
    &sBtlFormNeoshadow1A,
    &sBtlFormDefender1,
    &sBtlFormRedNocturne1B,
    &sBtlFormBlueRhapsody1G,
    &sBtlFormYellowOpera1C,
    &sBtlFormGreenRequiem1D,
#ifdef VERSION_EU
    &sBtlFormNeoshadow2,
    &sBtlFormWizard1A,
    &sBtlFormWyvern1B,
#else
    &sBtlFormWizard1A,
    &sBtlFormWyvern1B,
    &sBtlFormNeoshadow2,
#endif
    &sBtlFormNeoshadow3B,
    &sBtlFormNeoshadow2,
    &sBtlFormShadow4C,
    &sBtlFormShadow2F,
    &sBtlFormNeoshadow1A,
    &sBtlFormShadow3A,
    &sBtlFormDarkball1A,
    &sBtlFormDarkball1B,
    &sBtlFormDefender1,
    &sBtlFormShadow4C,
    &sBtlFormWyvern2,
    &sBtlFormTornadoStep3A,
    &sBtlFormWyvern1A,
    &sBtlFormWizard1A,
    &sBtlFormWizard2,
    &sBtlFormShadow2C,
    &sBtlFormWizard2,
    &sBtlFormDefender1,
    &sBtlFormWizard1B,
    &sBtlFormDarkball2B,
    &sBtlFormShadow5C,
    &sBtlFormSoldier1A,
    &sBtlFormTornadoStep1,
    &sBtlFormRedNocturne1A,
    &sBtlFormSoldier1A,
    &sBtlFormCrescendo1,
    &sBtlFormRedNocturne1A,
    &sBtlFormSoldier1A,
    &sBtlFormCreeperPlant1,
    &sBtlFormRedNocturne1A,
};

const BtlFormList* gBtlFormListByBattleId[147] = {
    &sBtlFormLists[31],
    &sBtlFormLists[32],
    &sBtlFormLists[33],
    &sBtlFormLists[34],
    &sBtlFormLists[35],
    &sBtlFormLists[36],
    &sBtlFormLists[37],
    &sBtlFormLists[38],
    &sBtlFormLists[39],
    &sBtlFormLists[40],
    &sBtlFormLists[71],
    &sBtlFormLists[72],
    &sBtlFormLists[73],
    &sBtlFormLists[74],
    &sBtlFormLists[75],
    &sBtlFormLists[76],
    &sBtlFormLists[77],
    &sBtlFormLists[78],
    &sBtlFormLists[79],
    &sBtlFormLists[80],
    &sBtlFormLists[11],
    &sBtlFormLists[12],
    &sBtlFormLists[13],
    &sBtlFormLists[14],
    &sBtlFormLists[15],
    &sBtlFormLists[16],
    &sBtlFormLists[17],
    &sBtlFormLists[18],
    &sBtlFormLists[19],
    &sBtlFormLists[20],
    &sBtlFormLists[41],
    &sBtlFormLists[42],
    &sBtlFormLists[43],
    &sBtlFormLists[44],
    &sBtlFormLists[45],
    &sBtlFormLists[46],
    &sBtlFormLists[47],
    &sBtlFormLists[48],
    &sBtlFormLists[49],
    &sBtlFormLists[50],
    &sBtlFormLists[91],
    &sBtlFormLists[92],
    &sBtlFormLists[93],
    &sBtlFormLists[94],
    &sBtlFormLists[95],
    &sBtlFormLists[96],
    &sBtlFormLists[97],
    &sBtlFormLists[98],
    &sBtlFormLists[99],
    &sBtlFormLists[100],
    &sBtlFormLists[81],
    &sBtlFormLists[82],
    &sBtlFormLists[83],
    &sBtlFormLists[84],
    &sBtlFormLists[85],
    &sBtlFormLists[86],
    &sBtlFormLists[87],
    &sBtlFormLists[88],
    &sBtlFormLists[89],
    &sBtlFormLists[90],
    &sBtlFormLists[61],
    &sBtlFormLists[62],
    &sBtlFormLists[63],
    &sBtlFormLists[64],
    &sBtlFormLists[65],
    &sBtlFormLists[66],
    &sBtlFormLists[67],
    &sBtlFormLists[68],
    &sBtlFormLists[69],
    &sBtlFormLists[70],
    &sBtlFormLists[101],
    &sBtlFormLists[102],
    &sBtlFormLists[103],
    &sBtlFormLists[104],
    &sBtlFormLists[105],
    &sBtlFormLists[106],
    &sBtlFormLists[107],
    &sBtlFormLists[108],
    &sBtlFormLists[109],
    &sBtlFormLists[110],
    &sBtlFormLists[51],
    &sBtlFormLists[52],
    &sBtlFormLists[53],
    &sBtlFormLists[54],
    &sBtlFormLists[55],
    &sBtlFormLists[56],
    &sBtlFormLists[57],
    &sBtlFormLists[58],
    &sBtlFormLists[59],
    &sBtlFormLists[60],
    &sBtlFormLists[21],
    &sBtlFormLists[22],
    &sBtlFormLists[23],
    &sBtlFormLists[24],
    &sBtlFormLists[25],
    &sBtlFormLists[26],
    &sBtlFormLists[27],
    &sBtlFormLists[28],
    &sBtlFormLists[29],
    &sBtlFormLists[30],
    &sBtlFormLists[111],
    &sBtlFormLists[112],
    &sBtlFormLists[113],
    &sBtlFormLists[114],
    &sBtlFormLists[115],
    &sBtlFormLists[116],
    &sBtlFormLists[117],
    &sBtlFormLists[118],
    &sBtlFormLists[119],
    &sBtlFormLists[120],
    &sBtlFormLists[121],
    &sBtlFormLists[122],
    &sBtlFormLists[123],
    &sBtlFormLists[124],
    &sBtlFormLists[125],
    &sBtlFormLists[126],
    &sBtlFormLists[127],
    &sBtlFormLists[128],
    &sBtlFormLists[129],
    &sBtlFormLists[130],
    &sBtlFormLists[1],
    &sBtlFormLists[0],
    &sBtlFormLists[63],
    &sBtlFormLists[96],
    &sBtlFormLists[91],
    &sBtlFormLists[2],
    &sBtlFormLists[3],
    &sBtlFormLists[4],
    &sBtlFormLists[5],
    &sBtlFormLists[6],
    &sBtlFormLists[7],
    &sBtlFormLists[8],
    &sBtlFormLists[9],
    &sBtlFormLists[10],
    &sBtlFormLists[131],
    &sBtlFormLists[132],
    &sBtlFormLists[133],
    &sBtlFormLists[134],
    &sBtlFormLists[135],
    &sBtlFormLists[136],
    &sBtlFormLists[137],
    &sBtlFormLists[138],
    &sBtlFormLists[139],
    &sBtlFormLists[140],
    &sBtlFormLists[141],
    &sBtlFormLists[142],
    &sBtlFormLists[143],
};
