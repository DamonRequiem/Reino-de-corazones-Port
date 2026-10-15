#!/usr/bin/env python3
"""Draws the Android on-screen controls (original artwork in the launcher's
style: night-blue enamel, gold rims, playing-card motifs).

Every control has a normal and a pressed look. They are drawn large and
scaled down on the phone, so they stay sharp on any screen.

Outputs (committed): port/res/touch_atlas.png, port/res/touch_atlas.h
Usage: python3 port/launcher/make_touch_assets.py
"""
import math
from pathlib import Path

from PIL import Image, ImageChops, ImageDraw, ImageFilter

import make_assets as A

OUT = Path(__file__).resolve().parents[1] / "res"
S = 4  # supersampling

NAVY_TOP = (34, 36, 92)
NAVY_BOT = (10, 12, 40)
GOLD = A.GOLD
GOLD_LIGHT = A.GOLD_LIGHT


def gradient(size, top, bottom, alpha=255):
    w, h = size
    img = Image.new("RGBA", size)
    d = ImageDraw.Draw(img)
    for y in range(h):
        k = y / max(1, h - 1)
        d.line([(0, y), (w, y)], fill=tuple(int(top[i] * (1 - k) + bottom[i] * k) for i in range(3)) + (alpha,))
    return img


def shaped(mask, fill_img):
    out = fill_img.copy()
    out.putalpha(ImageChops.multiply(fill_img.getchannel("A"), mask))
    return out


def glow_of(mask, color, radius, strength):
    g = mask.filter(ImageFilter.GaussianBlur(radius)).point(lambda v: min(255, int(v * strength)))
    img = Image.new("RGBA", mask.size, color + (0,))
    img.putalpha(g)
    return img


def rim(mask, width, color):
    inner = mask.filter(ImageFilter.MinFilter(width * 2 + 1))
    ring = ImageChops.subtract(mask, inner)
    img = Image.new("RGBA", mask.size, color + (0,))
    img.putalpha(ring)
    return img


def heart(d, cx, cy, r, fill):
    """Card-suit heart centred on (cx, cy), about 2r wide."""
    d.ellipse((cx - r, cy - r * 0.9, cx, cy + r * 0.1), fill=fill)
    d.ellipse((cx, cy - r * 0.9, cx + r, cy + r * 0.1), fill=fill)
    d.polygon([(cx - r * 0.97, cy - r * 0.25), (cx + r * 0.97, cy - r * 0.25), (cx, cy + r * 1.05)], fill=fill)


def letter(text, size, color=(255, 255, 255)):
    f = A.font("CinzelDecorative-Bold.ttf", size)
    l, t, r, b = f.getbbox(text)
    m = Image.new("L", (r - l + 8, b - t + 8), 0)
    ImageDraw.Draw(m).text((4 - l, 4 - t), text, font=f, fill=255)
    return m


def paste_mask_centered(base, m, color, cx, cy, shadow=True):
    x, y = int(cx - m.width / 2), int(cy - m.height / 2)
    if shadow:
        sh = Image.new("RGBA", m.size, (4, 4, 16, 0))
        sh.putalpha(m.filter(ImageFilter.GaussianBlur(3)).point(lambda v: int(v * 0.8)))
        base.alpha_composite(sh, (x + 2, y + 4))
    c = Image.new("RGBA", m.size, color + (0,))
    c.putalpha(m)
    base.alpha_composite(c, (x, y))


def finish(img, size):
    return img.resize(size, Image.LANCZOS)


# ---------------------------------------------------------------- D-pad

def dpad_mask(n):
    m = Image.new("L", (n, n), 0)
    d = ImageDraw.Draw(m)
    arm = n * 0.34
    r = n * 0.07
    c0, c1 = (n - arm) / 2, (n + arm) / 2
    d.rounded_rectangle((c0, n * 0.05, c1, n * 0.95), r, fill=255)
    d.rounded_rectangle((n * 0.05, c0, n * 0.95, c1), r, fill=255)
    return m


def dpad(pressed_dir=None):
    n = 300 * S
    mask = dpad_mask(n)
    img = Image.new("RGBA", (n, n), (0, 0, 0, 0))
    img.alpha_composite(glow_of(mask, (0, 0, 0), 10 * S, 0.7))
    img.alpha_composite(shaped(mask, gradient((n, n), NAVY_TOP, NAVY_BOT, 235)))
    # bevel: light from the top
    inner = mask.filter(ImageFilter.MinFilter(9 * S + 1))
    bevel = ImageChops.subtract(mask, inner.transform(inner.size, Image.AFFINE, (1, 0, 0, 0, 1, 4 * S)))
    hl = Image.new("RGBA", (n, n), (200, 190, 255, 0))
    hl.putalpha(bevel.point(lambda v: int(v * 0.35)))
    img.alpha_composite(hl)
    img.alpha_composite(rim(mask, 3 * S, GOLD))
    d = ImageDraw.Draw(img)
    c = n / 2
    # arrows
    for k in range(4):
        a = -math.pi / 2 + k * math.pi / 2
        tip = (c + math.cos(a) * n * 0.38, c + math.sin(a) * n * 0.38)
        base_c = (c + math.cos(a) * n * 0.27, c + math.sin(a) * n * 0.27)
        px, py = -math.sin(a) * n * 0.07, math.cos(a) * n * 0.07
        col = GOLD_LIGHT + (255,) if pressed_dir == k else GOLD + (230,)
        d.polygon([tip, (base_c[0] + px, base_c[1] + py), (base_c[0] - px, base_c[1] - py)], fill=col)
    # centre: a small heart in a ring
    d.ellipse((c - n * 0.085, c - n * 0.085, c + n * 0.085, c + n * 0.085), outline=GOLD + (200,), width=2 * S)
    heart(d, c, c + n * 0.01, n * 0.045, GOLD + (220,))
    return finish(img, (300, 300))


def dpad_highlight():
    """Glow over the 'up' arm; rotated at run time for the other directions."""
    n = 300 * S
    m = Image.new("L", (n, n), 0)
    d = ImageDraw.Draw(m)
    arm = n * 0.34
    d.rounded_rectangle(((n - arm) / 2, n * 0.05, (n + arm) / 2, n * 0.5), n * 0.07, fill=255)
    img = Image.new("RGBA", (n, n), (0, 0, 0, 0))
    img.alpha_composite(glow_of(m, (255, 220, 150), 12 * S, 1.0))
    fill = Image.new("RGBA", (n, n), (255, 230, 170, 0))
    fill.putalpha(m.point(lambda v: int(v * 0.35)))
    img.alpha_composite(fill)
    return finish(img, (300, 300))


# ---------------------------------------------------------------- round buttons

def keyblade_icon(n):
    """An original key-sword for the Kingdom of Hearts: a heart-shaped guard
    around the grip, a long blade and a key's teeth at the tip."""
    m = Image.new("L", (n, n), 0)
    d = ImageDraw.Draw(m)
    c = n / 2
    bw = n * 0.10
    # blade (drawn upright, turned at the end)
    d.rounded_rectangle((c - bw / 2, n * 0.04, c + bw / 2, n * 0.60), bw * 0.3, fill=255)
    # the key bit: two teeth near the tip
    d.rectangle((c + bw / 2 - 2, n * 0.04, c + n * 0.20, n * 0.12), fill=255)
    d.rectangle((c + n * 0.10, n * 0.12, c + n * 0.20, n * 0.20), fill=255)
    d.rectangle((c + bw / 2 - 2, n * 0.20, c + n * 0.13, n * 0.25), fill=255)
    # heart-shaped guard (outline)
    outer = Image.new("L", (n, n), 0)
    heart(ImageDraw.Draw(outer), c, n * 0.70, n * 0.19, 255)
    inner = Image.new("L", (n, n), 0)
    heart(ImageDraw.Draw(inner), c, n * 0.69, n * 0.12, 255)
    m = ImageChops.lighter(m, ImageChops.subtract(outer, inner))
    d = ImageDraw.Draw(m)
    # grip through the heart, and a small heart pommel
    d.rectangle((c - bw * 0.42, n * 0.58, c + bw * 0.42, n * 0.88), fill=255)
    heart(d, c, n * 0.92, n * 0.06, 255)
    return m.rotate(-40, resample=Image.BICUBIC, center=(c, c))


def jumper_icon(n):
    """An original figure in mid-jump: arms up, knees tucked, motion lines."""
    m = Image.new("L", (n, n), 0)
    d = ImageDraw.Draw(m)
    c = n / 2
    w = max(2, int(n * 0.07))
    hx, hy = c + n * 0.03, n * 0.22
    d.ellipse((hx - n * 0.085, hy - n * 0.085, hx + n * 0.085, hy + n * 0.085), fill=255)
    neck = (c + n * 0.01, n * 0.32)
    hip = (c - n * 0.04, n * 0.55)
    d.line([neck, hip], fill=255, width=int(w * 1.5))
    # arms raised in a V
    d.line([(c + n * 0.0, n * 0.35), (c - n * 0.17, n * 0.16)], fill=255, width=w)
    d.line([(c + n * 0.02, n * 0.35), (c + n * 0.22, n * 0.24)], fill=255, width=w)
    # legs tucked: thigh forward, shin back
    knee1, foot1 = (c + n * 0.12, n * 0.62), (c + n * 0.02, n * 0.76)
    knee2, foot2 = (c - n * 0.02, n * 0.68), (c - n * 0.17, n * 0.74)
    d.line([hip, knee1, foot1], fill=255, width=w, joint="curve")
    d.line([hip, knee2, foot2], fill=255, width=w, joint="curve")
    for i, r in enumerate((0.12, 0.08)):
        y = n * (0.85 + i * 0.05)
        d.arc((c - n * r * 2, y - n * 0.04, c + n * r * 2, y + n * 0.04), 200, 340, fill=255, width=max(1, w // 2))
    return m


def cards_icon(n):
    """Three stacked playing cards, a heart on the front one."""
    img = Image.new("L", (n, n), 0)
    for k, ang in enumerate((-18, -6, 8)):
        card = Image.new("L", (n, n), 0)
        d = ImageDraw.Draw(card)
        cw, ch = n * 0.36, n * 0.50
        x0, y0 = n / 2 - cw / 2, n / 2 - ch / 2
        d.rounded_rectangle((x0, y0, x0 + cw, y0 + ch), n * 0.04, fill=255)
        d.rounded_rectangle((x0 + n * 0.025, y0 + n * 0.025, x0 + cw - n * 0.025, y0 + ch - n * 0.025), n * 0.03,
                            fill=0 if k < 2 else 0)
        if k == 2:
            heart(d, n / 2, n / 2, n * 0.08, 255)
        card = card.rotate(-ang, resample=Image.BICUBIC, center=(n / 2, n * 0.62))
        card = card.transform(card.size, Image.AFFINE, (1, 0, -(k - 1) * n * 0.07, 0, 1, (k - 1) * n * 0.02))
        # later cards cover earlier ones
        cover = card.point(lambda v: 255 if v > 0 else 0)
        filled = Image.new("L", (n, n), 0)
        ImageDraw.Draw(filled)
        img = ImageChops.subtract(img, cover.filter(ImageFilter.MaxFilter(3)))
        solid = Image.new("L", (n, n), 0)
        sd = ImageDraw.Draw(solid)
        img = ImageChops.lighter(img, card)
    return img


def gem_icon_button(icon, top, bottom, pressed):
    n = 170 * S
    pad = 12 * S
    mask = Image.new("L", (n, n), 0)
    ImageDraw.Draw(mask).ellipse((pad, pad, n - pad, n - pad), fill=255)
    img = Image.new("RGBA", (n, n), (0, 0, 0, 0))
    if pressed:
        img.alpha_composite(glow_of(mask, (255, 214, 140), 10 * S, 1.2))
        top = tuple(min(255, int(v * 1.35 + 30)) for v in top)
        bottom = tuple(min(255, int(v * 1.35 + 20)) for v in bottom)
    else:
        img.alpha_composite(glow_of(mask, (0, 0, 0), 8 * S, 0.7))
    img.alpha_composite(shaped(mask, gradient((n, n), top, bottom, 240)))
    gl = Image.new("L", (n, n), 0)
    ImageDraw.Draw(gl).ellipse((n * 0.24, n * 0.13, n * 0.76, n * 0.45), fill=255)
    gl = ImageChops.multiply(gl.filter(ImageFilter.GaussianBlur(6 * S)), mask)
    white = Image.new("RGBA", (n, n), (255, 255, 255, 0))
    white.putalpha(gl.point(lambda v: int(v * 0.30)))
    img.alpha_composite(white)
    img.alpha_composite(rim(mask, 4 * S, GOLD_LIGHT if pressed else GOLD))
    inner = mask.filter(ImageFilter.MinFilter(15 * S + 1))
    img.alpha_composite(rim(inner, 1 * S, (255, 240, 210)))
    ic = icon(int(n * 0.74))
    canvas = Image.new("L", (n, n), 0)
    canvas.paste(ic, (int(n * 0.13), int(n * 0.13)))
    paste_mask_centered(img, canvas, GOLD_LIGHT, n / 2, n / 2)
    return finish(img, (170, 170))


def stick_base():
    n = 260 * S
    p = 8 * S
    mask = Image.new("L", (n, n), 0)
    ImageDraw.Draw(mask).ellipse((p, p, n - p, n - p), fill=255)
    img = Image.new("RGBA", (n, n), (0, 0, 0, 0))
    img.alpha_composite(glow_of(mask, (0, 0, 0), 9 * S, 0.6))
    img.alpha_composite(shaped(mask, gradient((n, n), (28, 30, 80), (8, 10, 34), 200)))
    img.alpha_composite(rim(mask, 3 * S, GOLD))
    inner = Image.new("L", (n, n), 0)
    ImageDraw.Draw(inner).ellipse((n * 0.2, n * 0.2, n * 0.8, n * 0.8), outline=255, width=2 * S)
    ring = Image.new("RGBA", (n, n), (180, 170, 240, 0))
    ring.putalpha(inner.point(lambda v: int(v * 0.45)))
    img.alpha_composite(ring)
    d = ImageDraw.Draw(img)
    c = n / 2
    for k in range(4):
        a = -math.pi / 2 + k * math.pi / 2
        tip = (c + math.cos(a) * n * 0.44, c + math.sin(a) * n * 0.44)
        bc = (c + math.cos(a) * n * 0.37, c + math.sin(a) * n * 0.37)
        px, py = -math.sin(a) * n * 0.05, math.cos(a) * n * 0.05
        d.polygon([tip, (bc[0] + px, bc[1] + py), (bc[0] - px, bc[1] - py)], fill=GOLD + (220,))
    return finish(img, (260, 260))


def stick_knob(pressed):
    n = 140 * S
    p = 8 * S
    mask = Image.new("L", (n, n), 0)
    ImageDraw.Draw(mask).ellipse((p, p, n - p, n - p), fill=255)
    img = Image.new("RGBA", (n, n), (0, 0, 0, 0))
    img.alpha_composite(glow_of(mask, (255, 214, 140) if pressed else (0, 0, 0), 8 * S, 1.1 if pressed else 0.7))
    top, bot = ((96, 84, 180), (30, 26, 90)) if pressed else ((64, 60, 140), (16, 16, 56))
    img.alpha_composite(shaped(mask, gradient((n, n), top, bot, 245)))
    gl = Image.new("L", (n, n), 0)
    ImageDraw.Draw(gl).ellipse((n * 0.25, n * 0.14, n * 0.75, n * 0.45), fill=255)
    gl = ImageChops.multiply(gl.filter(ImageFilter.GaussianBlur(5 * S)), mask)
    white = Image.new("RGBA", (n, n), (255, 255, 255, 0))
    white.putalpha(gl.point(lambda v: int(v * 0.35)))
    img.alpha_composite(white)
    img.alpha_composite(rim(mask, 4 * S, GOLD_LIGHT if pressed else GOLD))
    d = ImageDraw.Draw(img)
    heart(d, n / 2, n / 2 + n * 0.02, n * 0.12, GOLD_LIGHT + (235,))
    return finish(img, (140, 140))


def small_button(kind, pressed):
    """L / R arrows and the L+R cards button: rounded card-like tiles."""
    w, h = 130 * S, 110 * S
    p = 7 * S
    mask = Image.new("L", (w, h), 0)
    ImageDraw.Draw(mask).rounded_rectangle((p, p, w - p, h - p), 24 * S, fill=255)
    img = Image.new("RGBA", (w, h), (0, 0, 0, 0))
    img.alpha_composite(glow_of(mask, (255, 214, 140) if pressed else (0, 0, 0), 7 * S, 1.1 if pressed else 0.6))
    top = (78, 66, 150) if pressed else NAVY_TOP
    img.alpha_composite(shaped(mask, gradient((w, h), top, NAVY_BOT, 228)))
    img.alpha_composite(rim(mask, 3 * S, GOLD_LIGHT if pressed else GOLD))
    d = ImageDraw.Draw(img)
    cx, cy = w / 2, h / 2
    col = GOLD_LIGHT + (255,)
    if kind in ("left", "right"):
        s = -1 if kind == "left" else 1
        for dx in (-0.09, 0.07):
            x0 = cx + s * dx * w
            d.polygon([(x0 - s * w * 0.11, cy - h * 0.25), (x0 + s * w * 0.11, cy), (x0 - s * w * 0.11, cy + h * 0.25)],
                      fill=col)
    else:
        ic = cards_icon(int(h * 0.92))
        canvas = Image.new("L", (w, h), 0)
        canvas.paste(ic, (int(cx - ic.width / 2), int(cy - ic.height / 2)))
        paste_mask_centered(img, canvas, GOLD_LIGHT, w / 2, h / 2)
    return finish(img, (130, 110))


def bend(img, sag):
    """Bends a plate into a gentle arch: its ends drop by `sag` pixels (the
    hollow side, facing down, wraps around the game's card deck)."""
    w, h = img.size
    out = Image.new("RGBA", (w, h + sag), (0, 0, 0, 0))
    for x in range(w):
        dx = (x - (w - 1) / 2) / ((w - 1) / 2)
        off = sag * dx * dx
        col = img.crop((x, 0, x + 1, h))
        y0 = int(off)
        fr = off - y0
        # sub-pixel shift: blend the column at two offsets
        a = Image.new("RGBA", (1, h + sag), (0, 0, 0, 0))
        a.paste(col, (0, y0))
        b = Image.new("RGBA", (1, h + sag), (0, 0, 0, 0))
        b.paste(col, (0, min(y0 + 1, sag)))
        out.paste(Image.blend(a, b, fr), (x, 0))
    return out


PLATE_SAG = {"left": 17, "right": 17}  # same arch for both: they sit on one circle (pc_touch.c)


def arrow_plate(kind, pressed):
    """L / R: wide plates shaped like an arrow (the tip points the way the
    cards turn), gently curved, laid in a fan around the game's card deck.
    Both share the same curve, that of the circle they sit on."""
    w, h = 220 * S, 130 * S
    p = 8 * S
    s = -1 if kind == "left" else 1
    neck = 0.30  # where the tip starts, from the outer end
    def X(f):  # f from 0 (inner end) to 1 (outer tip)
        return w / 2 + s * (f - 0.5) * (w - 2 * p)
    pts = [(X(0), p), (X(1 - neck), p), (X(1), h / 2), (X(1 - neck), h - p), (X(0), h - p)]
    mask = Image.new("L", (w, h), 0)
    ImageDraw.Draw(mask).polygon(pts, fill=255)
    # round the corners
    mask = mask.filter(ImageFilter.GaussianBlur(9 * S)).point(lambda v: 255 if v > 128 else 0)
    mask = mask.filter(ImageFilter.GaussianBlur(S))
    img = Image.new("RGBA", (w, h), (0, 0, 0, 0))
    img.alpha_composite(glow_of(mask, (255, 214, 140) if pressed else (0, 0, 0), 8 * S, 1.1 if pressed else 0.6))
    top = (78, 66, 150) if pressed else NAVY_TOP
    img.alpha_composite(shaped(mask, gradient((w, h), top, NAVY_BOT, 228)))
    img.alpha_composite(rim(mask, 3 * S, GOLD_LIGHT if pressed else GOLD))
    # a thin inner line, like a card's border
    inner = mask.filter(ImageFilter.MinFilter(14 * S + 1))
    img.alpha_composite(rim(inner, 1 * S, (GOLD[0], GOLD[1], GOLD[2])))
    sag = PLATE_SAG[kind]
    img = bend(finish(img, (220 * 2, 130 * 2)), sag * 2)  # bent at 2x, then scaled
    # the arrows on top, unbent, where the plate sits at that point
    d = ImageDraw.Draw(img)
    col = GOLD_LIGHT + (255,)
    W, H = 440, 260
    cxf = W / 2 + s * (0.47 - 0.5) * (W - 32)
    dxn = (cxf - (W - 1) / 2) / ((W - 1) / 2)
    cy = H / 2 + sag * 2 * dxn * dxn
    for dx in (-0.075, 0.075):
        x0 = cxf + s * dx * W
        d.polygon([(x0 - s * W * 0.07, cy - H * 0.24), (x0 + s * W * 0.07, cy), (x0 - s * W * 0.07, cy + H * 0.24)],
                  fill=col)
    return finish(img, (220, 130 + sag))


def gem_button(text, top, bottom, pressed):
    n = 170 * S
    pad = 12 * S
    mask = Image.new("L", (n, n), 0)
    ImageDraw.Draw(mask).ellipse((pad, pad, n - pad, n - pad), fill=255)
    img = Image.new("RGBA", (n, n), (0, 0, 0, 0))
    if pressed:
        img.alpha_composite(glow_of(mask, (255, 214, 140), 10 * S, 1.2))
        top = tuple(min(255, int(v * 1.35 + 30)) for v in top)
        bottom = tuple(min(255, int(v * 1.35 + 20)) for v in bottom)
    else:
        img.alpha_composite(glow_of(mask, (0, 0, 0), 8 * S, 0.7))
    img.alpha_composite(shaped(mask, gradient((n, n), top, bottom, 240)))
    # glossy highlight
    gl = Image.new("L", (n, n), 0)
    ImageDraw.Draw(gl).ellipse((n * 0.24, n * 0.13, n * 0.76, n * 0.45), fill=255)
    gl = ImageChops.multiply(gl.filter(ImageFilter.GaussianBlur(6 * S)), mask)
    white = Image.new("RGBA", (n, n), (255, 255, 255, 0))
    white.putalpha(gl.point(lambda v: int(v * 0.32)))
    img.alpha_composite(white)
    img.alpha_composite(rim(mask, 4 * S, GOLD_LIGHT if pressed else GOLD))
    inner = mask.filter(ImageFilter.MinFilter(15 * S + 1))
    img.alpha_composite(rim(inner, 1 * S, (255, 240, 210)))
    paste_mask_centered(img, letter(text, 74 * S), (255, 250, 236), n / 2, n / 2 + 2 * S)
    return finish(img, (170, 170))


def round_icon(kind, pressed):
    n = 120 * S
    pad = 8 * S
    mask = Image.new("L", (n, n), 0)
    ImageDraw.Draw(mask).ellipse((pad, pad, n - pad, n - pad), fill=255)
    img = Image.new("RGBA", (n, n), (0, 0, 0, 0))
    img.alpha_composite(glow_of(mask, (255, 214, 140) if pressed else (0, 0, 0), 7 * S, 1.0 if pressed else 0.6))
    top = (70, 62, 140) if pressed else NAVY_TOP
    img.alpha_composite(shaped(mask, gradient((n, n), top, NAVY_BOT, 230)))
    img.alpha_composite(rim(mask, 3 * S, GOLD_LIGHT if pressed else GOLD))
    d = ImageDraw.Draw(img)
    c = n / 2
    col = GOLD_LIGHT + (255,)
    if kind == "menu":
        heart(d, c, c - n * 0.02, n * 0.17, col)
        for i in (-1, 1):
            d.ellipse((c + i * n * 0.29 - 3 * S, c - 3 * S, c + i * n * 0.29 + 3 * S, c + 3 * S), fill=GOLD + (220,))
    else:  # fast forward: two chevrons
        for dx in (-0.12, 0.10):
            x0 = c + dx * n
            d.polygon([(x0 - n * 0.1, c - n * 0.17), (x0 + n * 0.12, c), (x0 - n * 0.1, c + n * 0.17)], fill=col)
    return finish(img, (120, 120))


# ---------------------------------------------------------------- shoulders and pills

def shoulder(text, right, pressed):
    w, h = 250 * S, 104 * S
    mask = Image.new("L", (w, h), 0)
    d = ImageDraw.Draw(mask)
    p = 8 * S
    d.rounded_rectangle((p, p, w - p, h - p), 26 * S, fill=255)
    # a card's bevelled corner on the outer top side
    big = 60 * S
    corner = Image.new("L", (w, h), 0)
    cd = ImageDraw.Draw(corner)
    if right:
        cd.rounded_rectangle((w - p - big * 2, p, w - p, p + big * 2), big, fill=255)
    else:
        cd.rounded_rectangle((p, p, p + big * 2, p + big * 2), big, fill=255)
    mask = ImageChops.lighter(mask, ImageChops.multiply(corner, mask))
    img = Image.new("RGBA", (w, h), (0, 0, 0, 0))
    img.alpha_composite(glow_of(mask, (255, 214, 140) if pressed else (0, 0, 0), 8 * S, 1.1 if pressed else 0.6))
    top = (78, 66, 150) if pressed else NAVY_TOP
    img.alpha_composite(shaped(mask, gradient((w, h), top, NAVY_BOT, 232)))
    img.alpha_composite(rim(mask, 3 * S, GOLD_LIGHT if pressed else GOLD))
    inner = mask.filter(ImageFilter.MinFilter(13 * S + 1))
    img.alpha_composite(rim(inner, 1 * S, (180, 170, 240)))
    paste_mask_centered(img, letter(text, 54 * S), (255, 248, 230), w / 2, h / 2 + 2 * S)
    dd = ImageDraw.Draw(img)
    for sx in (w * 0.27, w * 0.73):
        cy = h / 2
        dd.polygon([(sx, cy - 8 * S), (sx + 6 * S, cy), (sx, cy + 8 * S), (sx - 6 * S, cy)], fill=GOLD + (210,))
    return finish(img, (250, 104))


def pill(text, pressed):
    w, h = 200 * S, 64 * S
    p = 6 * S
    mask = Image.new("L", (w, h), 0)
    ImageDraw.Draw(mask).rounded_rectangle((p, p, w - p, h - p), (h - 2 * p) // 2, fill=255)
    img = Image.new("RGBA", (w, h), (0, 0, 0, 0))
    img.alpha_composite(glow_of(mask, (255, 214, 140) if pressed else (0, 0, 0), 6 * S, 1.1 if pressed else 0.6))
    top = (78, 66, 150) if pressed else NAVY_TOP
    img.alpha_composite(shaped(mask, gradient((w, h), top, NAVY_BOT, 228)))
    img.alpha_composite(rim(mask, 2 * S, GOLD_LIGHT if pressed else GOLD))
    f = A.font("Cinzel.ttf", 28 * S, 700)
    l, t, r, b = f.getbbox(text)
    m = Image.new("L", (r - l + 8, b - t + 8), 0)
    ImageDraw.Draw(m).text((4 - l, 4 - t), text, font=f, fill=255)
    paste_mask_centered(img, m, (255, 246, 226), w / 2, h / 2 + 1 * S)
    return finish(img, (200, 64))


def main():
    items = [
        ("T_STICK", stick_base()),
        ("T_KNOB", stick_knob(False)),
        ("T_KNOB_ON", stick_knob(True)),
        ("T_A", gem_icon_button(keyblade_icon, (196, 54, 96), (92, 14, 52), False)),
        ("T_A_ON", gem_icon_button(keyblade_icon, (196, 54, 96), (92, 14, 52), True)),
        ("T_B", gem_icon_button(jumper_icon, (60, 92, 200), (18, 28, 92), False)),
        ("T_B_ON", gem_icon_button(jumper_icon, (60, 92, 200), (18, 28, 92), True)),
        ("T_L", arrow_plate("left", False)),
        ("T_L_ON", arrow_plate("left", True)),
        ("T_R", arrow_plate("right", False)),
        ("T_R_ON", arrow_plate("right", True)),
        ("T_LR", small_button("cards", False)),
        ("T_LR_ON", small_button("cards", True)),
        ("T_START", pill("START", False)),
        ("T_START_ON", pill("START", True)),
        ("T_SELECT", pill("SELECT", False)),
        ("T_SELECT_ON", pill("SELECT", True)),
        ("T_MENU", round_icon("menu", False)),
        ("T_MENU_ON", round_icon("menu", True)),
        ("T_FAST", round_icon("fast", False)),
        ("T_FAST_ON", round_icon("fast", True)),
    ]
    atlas, placed = A.pack(items)
    atlas.save(OUT / "touch_atlas.png", optimize=True)
    order = [n for n, _ in items]
    rect = {n: (x, y, im.width, im.height) for n, im, x, y in placed}
    with open(OUT / "touch_atlas.h", "w") as h:
        h.write("/* Generated by port/launcher/make_touch_assets.py: sprites in touch_atlas.png. */\n")
        h.write("enum {\n" + "".join(f"    {n},\n" for n in order) + "    TOUCH_SPRITE_COUNT\n};\n")
        h.write("static const SDL_Rect kTouchSprites[TOUCH_SPRITE_COUNT] = {\n")
        h.write("".join(f"    {{{r[0]}, {r[1]}, {r[2]}, {r[3]}}}, /* {n} */\n" for n in order for r in [rect[n]]))
        h.write("};\n")
    print(f"touch atlas {atlas.size}, {len(order)} sprites")


if __name__ == "__main__":
    main()
