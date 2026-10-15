/*
 * pc_screenshot.c
 * Writes the current 240x160 framebuffer as a 24-bit BMP (no dependencies).
 */
#include <stdio.h>
#include <string.h>
#include "pc_platform.h"

int PcSaveScreenshot(const char* path) {
    const int w = 240, h = 160;
    FILE* f = fopen(path, "wb");
    uint8_t hdr[54] = {'B', 'M'};
    uint32_t rowBytes = w * 3, dataSize = rowBytes * h, fileSize = 54 + dataSize;
    int x, y;

    if (!f)
        return 0;
    memcpy(hdr + 2, &fileSize, 4);
    hdr[10] = 54;
    hdr[14] = 40;
    memcpy(hdr + 18, &w, 4);
    memcpy(hdr + 22, &h, 4);
    hdr[26] = 1;
    hdr[28] = 24;
    memcpy(hdr + 34, &dataSize, 4);
    fwrite(hdr, 1, 54, f);
    for (y = h - 1; y >= 0; y--) {
        for (x = 0; x < w; x++) {
            uint32_t c = gPcFramebuffer[y * w + x];
            uint8_t px[3] = {(uint8_t)c, (uint8_t)(c >> 8), (uint8_t)(c >> 16)};
            fwrite(px, 1, 3, f);
        }
    }
    fclose(f);
    return 1;
}
