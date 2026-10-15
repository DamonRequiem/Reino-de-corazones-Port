#ifndef GUARD_BTL_EFFECT_H
#define GUARD_BTL_EFFECT_H

#include "battle_actor_types.h"
#include "types.h"

enum SpellTier {
    SPELL_TIER_BASE,
    SPELL_TIER_RA,
    SPELL_TIER_GA,
    SPELL_TIER_DARK
};

u8 BgFxIsActive();
void BgFxSetPosition(s32 x, s32 y, s32 z);

void BgFxInit(u16 colorMode, u16 bg);
void BgFxFree();
void BgFxUpdate();
void BgFxStartCure(u16 tier, s32 x, s32 y, s32 z);
void BgFxStartFire(u16 tier, s32 x, s32 y, s32 z, s32 targetX, s32 targetY, s32 targetZ, u8 flip, s32 attack);
void BgFxStartFireAtPlayer(s32 x, s32 y, s32 z, u8 flip, s32 unused, s32 attack, u16 timer);
void BgFxStartBlizzard(u16 tier, s32 x, s32 y, s32 z, s32 targetX, s32 targetY, s32 targetZ, u8 flip, s32 attack);
void BgFxStartFlash(s32 x, s32 y, s32 z);
void BgFxStartThunderHit(s32 x, s32 y, s32 z);
void BgFxStartPotion(s32 x, s32 y, s32 z);
void BgFxStartWideThunder(u16 tier, s32 x, s32 y, s32 z, s32 groundZ, s32 attack);
void BgFxStartEnemyDeath(s32 x, s32 y, s32 z, s32 scale);
void BgFxStartDarkDeath(s32 x, s32 y, s32 z, s32 scale);
void BgFxStartEnemySpawn(s32 x, s32 y, s32 z, s32 scale);
void BgFxStartDarkDeathBlend(s32 x, s32 y, s32 scale, u16 target2, u16 target1);
void BgFxStartExplosion(s32 x, s32 y, s32 z);
void BgFxGetPosition(s32* x, s32* y, s32* z);
void BgFxStartSummon(s32 x, s32 y, s32 z);
void BgFxStartFriendHit(s32 x, s32 y, s32 z);
void BgFxStartActorThunder(BtlObj* actor);
void BgFxStartDsdEnergy(s32 x, s32 y, s32 z, s32 scale, s32 steps, s32 spinSpeed);
void BgFxAddPosition(s32 dx, s32 dy, s32 dz);
void BgFxSignalEnd(u8 bit);
void BgFxSetTarget(s32 x, s32 y, s32 z);
void BgFxSetAngle(u8 angle);
void BgFxSetScale(s32 scaleX, s32 scaleY);
void BgFxStartGroundImpact(s32 x, s32 y);
void BgFxStartStop(u16 tier, s32 x, s32 y, s32 z, s32 attack);
void BgFxStartCharaDefeat(s32 x, s32 y);
void BgFxStartHumDefeat(s32 x, s32 y);
void BgFxStartBossDeath(s32 x, s32 y);
void BgFxStartCharaDefeatEnd(s32 x, s32 y);
void BgFxStartGravity(u16 tier, s32 x, s32 y, s32 z, s32 targetX, s32 targetY, s32 targetZ, u8 flip, s32 attack);
void BgFxStartGravityStrike(s32 x, s32 y, s32 z, s32 attack);
void BgFxStartShockwave(s32 x, s32 y, u8 flip);
void BgFxStartGas(s32 x, s32 y, s32 z, u8 facingLeft);
void BgFxStartBoogieKaihuku(s32 x, s32 y, s32 z, s32 scale);
void BgFxStartBossDeathFlash();
void BgFxStartPcShot(s32 x, s32 y, s32 z, s32 targetX, s32 targetY, s32 targetZ, s32 attack, u16 steps, s32 targetScale);
void BgFxStartThunderStrike(s32 x, s32 y, s32 z, s32 attack);
void BgFxStartThunder(u16 tier, s32 x, s32 y, s32 z, s32 targetX, s32 targetY, s32 targetZ, s32 attack);
void BgFxStartDumboSplash(u16 level, s32 x, s32 y, s32 z, u8 flip, s32 attack);
void BgFxStartTrinityLimit(s32 x, s32 y, s32 z);
void BgFxStartTrinityLimitCharge(s32 x, s32 y, s32 z);
void BgFxStartTrinityLimitBlast(s32 x, s32 y, s32 z);
void BgFxStartRagnarokCharge(s32 x, s32 y, s32 z);
void BgFxStartSync(s32 x, s32 y, s32 z);
void BgFxStartStunImpact(s32 x, s32 y, s32 z);
void BgFxStartZantetsuken(s32 x, s32 y, s32 z, u8 facingRight);
void BgFxStartUrsulaBeam(s32 x, s32 y, s32 z, u8 facingLeft, s32 targetScale, u16 steps);
void BgFxStartAnsemRush(s32 x, s32 y, s32 z, u8 flip);
void BgFxStartJfMajinBeam(s32 x, s32 y, s32 z, s32 scaleY, u8 angle, u16 steps);
void BgFxStartFireBurst(s32 x, s32 y, s32 z, s32 targetX, s32 targetY, s32 targetZ, u8 flip, s32 attack);
void BgFxStartFireExplosion(s32 x, s32 y, s32 z);
void BgFxStartXmas(u16 steps);
void BgFxStartVixenIceFall(u16 steps);
void BgFxStartFlame(s32 x, s32 y, s32 z, s32 scale);
void BgFxStartFrost(s32 x, s32 y, s32 z, s32 scale);
void BgFxStartUrsulaThunder(s32 x, s32 y, s32 z);
void BgFxStartHoly(s32 x, s32 y, s32 z, s32 attack);
void BgFxStartTornado(s32 x, s32 y, s32 z, s32 attack, u8 flip);
void BgFxStartBind(s32 x, s32 attack);
void BgFxStartMahluxiaGround(s32 x, s32 y, s32 z, s32 attack);
void BgFxStartLexceusGround(s32 x, s32 y, s32 z, s32 attack);
void BgFxStartHanabira(s32 x, s32 y, s32 z, s32 attack);
void BgFxStartKama(s32 x, s32 y, s32 z, s32 dx, s32 attack);
void BgFxStartLaxeneBeam(s32 x, s32 y, s32 z, u8 flip, s32 attack);
void BgFxStartRikuLimit(s32 x, s32 y, s32 z, u8 angle);
void BgFxStartDragonFire(s32 x, s32 y, s32 z, s32 scale);
void BgFxStartAero(u16 tier, s32 x, s32 y, s32 z, s32 attack);
void BgFxStartRikuDarkModeFlash(s32 x, s32 y, s32 z);
void BgFxStartLstCtr(s32 x, s32 y, s32 z, s32 scale);
void BgFxStartLstCtrFlipped(s32 x, s32 y, s32 z, s32 scale);
void BgFxStartDsdTransition(s32 x, s32 y, s32 z, s32 scale);
void BgFxStartRikuDarkMode(s32 x, s32 y, s32 z);
void BgFxStartRikuLimitFinish(s32 x, s32 y, s32 z);
void BgFxStartRikuDiveHit(s32 x, s32 y, s32 z);

#endif
