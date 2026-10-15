/*
 * pc_video.h
 * Image filters for the window (port/pc_video.c).
 */
#ifndef PC_VIDEO_H
#define PC_VIDEO_H

#include <stdint.h>

enum {
    PC_FILTER_ORIGINAL, /* sharp pixels */
    PC_FILTER_SMOOTH,   /* bilinear */
    PC_FILTER_CLEAN,    /* sharp enlargement, smoothed between screen pixels */
    PC_FILTER_EDGES,    /* Scale2x / Scale3x */
    PC_FILTER_LCD,      /* GBA screen grid */
    PC_FILTER_CRT,      /* television scanlines */
    PC_FILTER_COUNT
};

typedef struct {
    int filter;
    int scale;     /* 1..5 */
    int gbaColors; /* GBA screen colours */
    int ghosting;  /* mix with the previous frame, like the LCD */
} PcVideoSettings;

/* Filters the current frame (gPcFramebuffer). Returns the image, its size,
 * and whether the graphics card should smooth it when stretching. */
const uint32_t* PcVideoFilter(const PcVideoSettings* s, int* outW, int* outH, int* smooth);
void PcVideoBlend(const uint32_t* a, const uint32_t* b, uint32_t* out, int pixels);
void PcVideoResetHistory(void);

#endif
