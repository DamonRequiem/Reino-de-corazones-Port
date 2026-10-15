#!/usr/bin/env python3
"""Draws port/res/rdc.ico, the Reino de Corazones icon: two playing cards,
the front one with a heart suit (original artwork, no game assets).
Usage: make_icon.py out.ico [preview.png]"""
import math
import sys
from PIL import Image, ImageDraw

S = 1024  # drawn large, reduced for smooth edges
im = Image.new("RGBA", (S, S), (0, 0, 0, 0))
d = ImageDraw.Draw(im)
k = S / 256


def r(*v):
    return tuple(int(x * k) for x in v)


# Back card: deep blue with a gold frame and a small star.
d.rounded_rectangle(r(78, 18, 232, 232), int(22 * k), fill=(30, 36, 96, 255), outline=(232, 196, 112, 255), width=int(8 * k))
d.rounded_rectangle(r(96, 36, 214, 214), int(12 * k), outline=(120, 110, 200, 255), width=int(4 * k))
cx, cy = 155 * k, 70 * k
d.polygon([(cx + 18 * k * math.cos(-math.pi / 2 + i * math.pi / 5) * (1 if i % 2 == 0 else 0.42),
            cy + 18 * k * math.sin(-math.pi / 2 + i * math.pi / 5) * (1 if i % 2 == 0 else 0.42)) for i in range(10)],
          fill=(240, 206, 120, 255))
# Front card: ivory with a heart suit.
d.rounded_rectangle(r(24, 40, 178, 252), int(22 * k), fill=(250, 247, 240, 255), outline=(40, 34, 70, 255), width=int(8 * k))
d.rounded_rectangle(r(44, 60, 158, 232), int(12 * k), outline=(214, 176, 90, 255), width=int(5 * k))
hx, hy, hs = 101 * k, 150 * k, 50 * k
pts = []
for i in range(200):
    t = i / 200 * 2 * math.pi
    x = 16 * math.sin(t) ** 3
    y = 13 * math.cos(t) - 5 * math.cos(2 * t) - 2 * math.cos(3 * t) - math.cos(4 * t)
    pts.append((hx + x * hs / 17, hy - y * hs / 17))
d.polygon(pts, fill=(204, 34, 62, 255), outline=(130, 16, 40, 255))
icon = im.resize((256, 256), Image.LANCZOS)
icon.save(sys.argv[1], sizes=[(16, 16), (24, 24), (32, 32), (48, 48), (64, 64), (128, 128), (256, 256)])
if len(sys.argv) > 2:
    icon.save(sys.argv[2])
