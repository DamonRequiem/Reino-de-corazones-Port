#!/usr/bin/env python3
"""Artwork for the Android app (original, same style as the PC launcher):
launcher icons from port/res/rdc.ico, the menu background and the floating
cards (port/launcher/make_assets.py).

Outputs (committed): port/android/res/mipmap-*/ic_launcher.png,
                     port/android/art/{fondo,card0,card1,card2,twinkle}.png
Usage: python3 port/android/make_android_assets.py
"""
import sys
from pathlib import Path

from PIL import Image

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / "launcher"))
import make_assets as A  # noqa: E402

ICON_SIZES = {"mdpi": 48, "hdpi": 72, "xhdpi": 96, "xxhdpi": 144, "xxxhdpi": 192}


def backdrop():
    """The game's surroundings on a wide phone screen: the launcher's night
    sky, with the castle on the left edge and the moon on the right, so they
    show beside the picture whatever its shape."""
    W, H = 1920, 864
    src = A.background().convert("RGB")  # 960x600
    k = H / src.height
    left = src.crop((0, 0, 420, src.height)).resize((int(420 * k), H), Image.LANCZOS)
    right = src.crop((620, 0, 960, src.height)).resize((int(340 * k), H), Image.LANCZOS)
    tile = src.crop((420, 0, 620, src.height)).resize((int(200 * k), H), Image.LANCZOS)
    out = Image.new("RGB", (W, H))
    x = left.width - 1
    while x < W - right.width:  # repeat the sky, never stretch its stars
        out.paste(tile, (x, 0))
        x += tile.width
    out.paste(left, (0, 0))
    out.paste(right, (W - right.width, 0))
    # A little darker, so the game stands out.
    return Image.blend(out, Image.new("RGB", (W, H), (4, 4, 14)), 0.18)


def main():
    ico = Image.open(HERE.parent / "res/rdc.ico")
    ico.size = (256, 256)
    big = ico.convert("RGBA")
    for dpi, px in ICON_SIZES.items():
        d = HERE / "res" / f"mipmap-{dpi}"
        d.mkdir(parents=True, exist_ok=True)
        big.resize((px, px), Image.LANCZOS).save(d / "ic_launcher.png", optimize=True)
    art = HERE / "art"
    art.mkdir(exist_ok=True)
    A.background().save(art / "fondo.png", optimize=True)
    for k in range(3):
        A.card(k).save(art / f"card{k}.png", optimize=True)
    A.twinkle().save(art / "twinkle.png", optimize=True)
    backdrop().save(art / "borde.jpg", quality=90)
    print("android art written")


if __name__ == "__main__":
    main()
