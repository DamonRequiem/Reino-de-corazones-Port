#ifndef GUARD_MODE_TITLE_H
#define GUARD_MODE_TITLE_H

void TitleShowLogo(u16 frames);
void TitleFinishIntro();
void TitleFadeOut();
void TitleExitToChoice();
u8 IsTitleLogoShown();
u8 IsTitleIntroDone();

extern s32 gTitleBgScale;
extern s32 gTitleBgX;
extern s32 gTitleBgY;

#endif /* GUARD_MODE_TITLE_H */
