#!/usr/bin/env python3
"""Draws the launcher's artwork (original, no game assets) and pre-renders
its Spanish text with the bundled OFL fonts.

Outputs (committed, so building the launcher needs no Python):
  assets/fondo.png      960x600 background: night sky, moon, distant castle
  assets/atlas.png      sprites: text, buttons, panel, ornaments, cards, stars
  assets/atlas.h        enum + rectangles of every sprite

Usage: python3 port/launcher/make_assets.py
"""
import math
import random
from pathlib import Path

from PIL import Image, ImageDraw, ImageFilter, ImageFont

HERE = Path(__file__).resolve().parent
FONTS = HERE / "fonts"
OUT = HERE / "assets"
W, H = 960, 600

GOLD = (236, 200, 120)
GOLD_LIGHT = (255, 236, 186)
INK = (11, 14, 40)


def font(name, size, weight=None):
    f = ImageFont.truetype(str(FONTS / name), size)
    if weight is not None:
        try:
            f.set_variation_by_axes([weight])
        except OSError:
            pass
    return f


TITLE = font("CinzelDecorative-Bold.ttf", 66)
HEAD = font("Cinzel.ttf", 25, 600)
SMALLCAPS = font("Cinzel.ttf", 17, 500)
BODY = font("CormorantGaramond.ttf", 27, 500)
BODY_SMALL = font("CormorantGaramond.ttf", 21, 500)
BODY_ITALIC = font("CormorantGaramond.ttf", 24, 500)

# id, text, font, style
TEXTS = [
    ("T_TITLE", "Reino de Corazones", TITLE, "title"),
    ("T_SUBTITLE", "Kingdom Hearts: Chain of Memories  ·  port nativo para PC", BODY_ITALIC, "soft"),
    ("T_WELCOME1", "Para comenzar tu viaje, el reino necesita tu copia legítima del juego.", BODY, "plain"),
    ("T_WELCOME2", "Arrastra aquí tu archivo .gba, o pulsa el botón para buscarlo.", BODY, "plain"),
    ("T_CHOOSE", "Elige tu destino", HEAD, "plain"),
    ("B_FIND", "Buscar mi juego", HEAD, "plain"),
    ("B_EXIT", "Salir", HEAD, "plain"),
    ("B_PLAY_EUR", "Jugar  ·  Europa", HEAD, "plain"),
    ("B_PLAY_USA", "Jugar  ·  USA", HEAD, "plain"),
    ("S_PLAY_EUR", "Español, inglés, francés, alemán e italiano", BODY_SMALL, "plain"),
    ("S_PLAY_USA", "En inglés", BODY_SMALL, "plain"),
    ("B_ADD", "Añadir otra versión", HEAD, "plain"),
    ("S_ADD", "USA (B8CE) o Europa (B8CP)", BODY_SMALL, "plain"),
    ("S_ADD_USA", "La versión USA (B8CE)", BODY_SMALL, "plain"),
    ("S_ADD_EUR", "La versión europea (B8CP), con español", BODY_SMALL, "plain"),
    ("B_FOLDER", "Abrir carpeta de partidas", HEAD, "plain"),
    ("S_FOLDER", "Tus partidas, capturas y ajustes", BODY_SMALL, "plain"),
    ("F_SUPPORTED", "VERSIONES COMPATIBLES:  USA (B8CE)  ·  EUROPA (B8CP)", SMALLCAPS, "soft"),
    ("F_PRIVACY", "Tu juego no sale de tu PC: solo se comprueba su huella SHA-1.", BODY_SMALL, "soft"),
    ("F_KEYS", "Flechas o ratón para elegir  ·  Enter para aceptar  ·  Esc para salir", BODY_SMALL, "soft"),
    ("F_VERSION", "v1.1.2", BODY_SMALL, "soft"),
    ("M_CHECKING", "Comprobando tu copia…", BODY, "plain"),
    ("M_OK_EUR", "Copia verificada: Europa (B8CP). ¡Bienvenido al reino!", BODY, "plain"),
    ("M_OK_USA", "Copia verificada: USA (B8CE). ¡Bienvenido al reino!", BODY, "plain"),
    ("M_ALREADY", "Esa versión ya estaba lista para jugar.", BODY, "plain"),
    ("M_BAD", "Ese archivo no es una copia compatible del juego.", BODY, "plain"),
    ("M_BAD_JP", "Es la versión japonesa: por ahora solo se admiten USA y Europa.", BODY, "plain"),
    ("M_NOT_GBA", "Ese archivo no parece un juego de GBA.", BODY, "plain"),
    ("M_ZIP", "Está comprimido: descomprímelo primero y elige el archivo .gba.", BODY, "plain"),
    ("M_READ_ERR", "No se pudo leer ese archivo.", BODY, "plain"),
    ("M_COPY_ERR", "No se pudo guardar la copia en la carpeta «rom».", BODY, "plain"),
    ("M_NO_ENGINE", "Falta el motor en la carpeta «motor». Vuelve a descomprimir el programa.", BODY, "plain"),
    ("M_LAUNCH", "Abriendo el reino…", BODY, "plain"),
    ("M_ENGINE_FAIL", "El juego se cerró con un error. Mira la carpeta «registros».", BODY, "plain"),
]


def text_sprite(text, f, style):
    pad = 18 if style == "title" else 6
    l, t, r, b = f.getbbox(text)
    w, h = r - l + pad * 2, b - t + pad * 2
    mask = Image.new("L", (w, h), 0)
    ImageDraw.Draw(mask).text((pad - l, pad - t), text, font=f, fill=255)
    img = Image.new("RGBA", (w, h), (0, 0, 0, 0))
    if style == "title":
        # Gold-to-white gradient letters with a warm glow.
        glow = mask.filter(ImageFilter.GaussianBlur(9))
        g = Image.new("RGBA", (w, h), GOLD + (0,))
        g.putalpha(glow.point(lambda v: int(v * 0.85)))
        img = Image.alpha_composite(img, g)
        grad = Image.new("RGBA", (w, h))
        gd = ImageDraw.Draw(grad)
        for y in range(h):
            k = y / max(1, h - 1)
            c = tuple(int(GOLD_LIGHT[i] * (1 - k) + GOLD[i] * k) for i in range(3))
            gd.line([(0, y), (w, y)], fill=c + (255,))
        grad.putalpha(mask)
        shadow = Image.new("RGBA", (w, h), (20, 10, 40, 0))
        shadow.putalpha(mask.filter(ImageFilter.GaussianBlur(2)).point(lambda v: int(v * 0.7)))
        img = Image.alpha_composite(img, shadow.transform((w, h), Image.AFFINE, (1, 0, -2, 0, 1, -3)))
        img = Image.alpha_composite(img, grad)
    else:
        # White letters (tinted at run time) with a soft dark shadow.
        shadow = Image.new("RGBA", (w, h), (5, 5, 20, 0))
        shadow.putalpha(mask.filter(ImageFilter.GaussianBlur(2)).point(lambda v: int(v * 0.8)))
        img = Image.alpha_composite(img, shadow.transform((w, h), Image.AFFINE, (1, 0, -1, 0, 1, -2)))
        white = Image.new("RGBA", (w, h), (255, 255, 255, 0))
        white.putalpha(mask)
        img = Image.alpha_composite(img, white)
    return img


def rounded(size, radius, fill, outline=None, width=2, glow=None):
    w, h = size
    m = 16 if glow else 0
    img = Image.new("RGBA", (w + m * 2, h + m * 2), (0, 0, 0, 0))
    if glow:
        g = Image.new("L", img.size, 0)
        ImageDraw.Draw(g).rounded_rectangle((m, m, m + w - 1, m + h - 1), radius, fill=255)
        g = g.filter(ImageFilter.GaussianBlur(9)).point(lambda v: int(v * glow[3] / 255))
        gl = Image.new("RGBA", img.size, glow[:3] + (0,))
        gl.putalpha(g)
        img = Image.alpha_composite(img, gl)
    d = ImageDraw.Draw(img)
    d.rounded_rectangle((m, m, m + w - 1, m + h - 1), radius, fill=fill, outline=outline, width=width)
    return img


def button(selected):
    w, h = 470, 66
    if selected:
        img = rounded((w, h), 14, (58, 44, 96, 235), GOLD, 3, glow=(255, 214, 140, 200))
        # Inner highlight line.
        d = ImageDraw.Draw(img)
        d.rounded_rectangle((16 + 5, 16 + 5, 16 + w - 6, 16 + h - 6), 10, outline=(255, 240, 200, 90), width=1)
        return img
    return rounded((w, h), 14, (14, 18, 52, 200), (150, 160, 220, 150), 2, glow=(0, 0, 0, 1))


def panel():
    return rounded((700, 210), 20, (10, 12, 38, 222), (220, 190, 120, 190), 2, glow=(120, 100, 220, 120))


def ornament():
    w, h = 460, 24
    img = Image.new("RGBA", (w, h), (0, 0, 0, 0))
    d = ImageDraw.Draw(img)
    cy = h // 2
    for x in range(w):
        k = 1 - abs(x - w / 2) / (w / 2)
        d.point((x, cy), fill=GOLD + (int(230 * k ** 0.6),))
    cx = w // 2
    d.polygon([(cx, cy - 9), (cx + 9, cy), (cx, cy + 9), (cx - 9, cy)], fill=GOLD_LIGHT + (255,), outline=GOLD + (255,))
    for s in (-1, 1):
        d.ellipse((cx + s * 22 - 3, cy - 3, cx + s * 22 + 3, cy + 3), fill=GOLD + (230,))
        d.polygon([(cx + s * 40, cy - 4), (cx + s * 44, cy), (cx + s * 40, cy + 4), (cx + s * 36, cy)], fill=GOLD + (200,))
    return img


def star_points(cx, cy, r1, r2, n=5, rot=-math.pi / 2):
    pts = []
    for i in range(n * 2):
        a = rot + i * math.pi / n
        r = r1 if i % 2 == 0 else r2
        pts.append((cx + r * math.cos(a), cy + r * math.sin(a)))
    return pts


def card(kind):
    """A floating playing card (original design): star, moon or diamond."""
    w, h, s = 76, 106, 3  # drawn 3x then reduced for smooth edges
    big = Image.new("RGBA", (w * s, h * s), (0, 0, 0, 0))
    d = ImageDraw.Draw(big)
    d.rounded_rectangle((0, 0, w * s - 1, h * s - 1), 10 * s, fill=(244, 240, 255, 255), outline=GOLD + (255,), width=3 * s)
    d.rounded_rectangle((7 * s, 7 * s, (w - 7) * s, (h - 7) * s), 6 * s, outline=(150, 130, 210, 255), width=2 * s)
    cx, cy = w * s // 2, h * s // 2
    if kind == 0:
        d.polygon(star_points(cx, cy, 22 * s, 9 * s), fill=GOLD + (255,), outline=(170, 120, 40, 255))
    elif kind == 1:
        d.ellipse((cx - 20 * s, cy - 20 * s, cx + 20 * s, cy + 20 * s), fill=(120, 110, 200, 255))
        d.ellipse((cx - 10 * s, cy - 24 * s, cx + 26 * s, cy + 16 * s), fill=(244, 240, 255, 255))
    else:
        d.polygon([(cx, cy - 26 * s), (cx + 17 * s, cy), (cx, cy + 26 * s), (cx - 17 * s, cy)], fill=(110, 170, 230, 255),
                  outline=(60, 90, 160, 255))
    return big.resize((w, h), Image.LANCZOS)


def twinkle():
    s = 32
    img = Image.new("RGBA", (s, s), (0, 0, 0, 0))
    core = Image.new("L", (s, s), 0)
    d = ImageDraw.Draw(core)
    d.ellipse((s / 2 - 3, s / 2 - 3, s / 2 + 3, s / 2 + 3), fill=255)
    d.line((s / 2, 2, s / 2, s - 2), fill=150)
    d.line((2, s / 2, s - 2, s / 2), fill=150)
    core = core.filter(ImageFilter.GaussianBlur(1.2))
    img.putalpha(core)
    white = Image.new("RGBA", (s, s), (255, 255, 255, 0))
    white.putalpha(core)
    return white


def background():
    rnd = random.Random(1999)
    img = Image.new("RGB", (W, H))
    d = ImageDraw.Draw(img)
    top, mid, bot = (6, 8, 26), (24, 20, 66), (52, 34, 86)
    for y in range(H):
        k = y / (H - 1)
        if k < 0.55:
            t = k / 0.55
            c = tuple(int(top[i] * (1 - t) + mid[i] * t) for i in range(3))
        else:
            t = (k - 0.55) / 0.45
            c = tuple(int(mid[i] * (1 - t) + bot[i] * t) for i in range(3))
        d.line([(0, y), (W, y)], fill=c)
    img = img.convert("RGBA")

    # Moon with a wide soft halo.
    mx, my, mr = 872, 300, 40
    halo = Image.new("L", (W, H), 0)
    ImageDraw.Draw(halo).ellipse((mx - 150, my - 150, mx + 150, my + 150), fill=110)
    halo = halo.filter(ImageFilter.GaussianBlur(60))
    hl = Image.new("RGBA", (W, H), (190, 180, 255, 0))
    hl.putalpha(halo)
    img = Image.alpha_composite(img, hl)
    moon = Image.new("RGBA", (W, H), (0, 0, 0, 0))
    md = ImageDraw.Draw(moon)
    md.ellipse((mx - mr, my - mr, mx + mr, my + mr), fill=(250, 246, 255, 255))
    for _ in range(7):  # faint maria
        rx, ry, rr = mx + rnd.randint(-26, 20), my + rnd.randint(-24, 22), rnd.randint(5, 12)
        md.ellipse((rx - rr, ry - rr, rx + rr, ry + rr), fill=(236, 233, 250, 255))
    moon = moon.filter(ImageFilter.GaussianBlur(1.6))
    img = Image.alpha_composite(img, moon)

    # Star field.
    stars = Image.new("RGBA", (W, H), (0, 0, 0, 0))
    sd = ImageDraw.Draw(stars)
    for _ in range(420):
        x, y = rnd.randint(0, W - 1), int(rnd.random() ** 1.6 * H * 0.8)
        b = rnd.randint(60, 230)
        r = 1 if rnd.random() < 0.85 else 2
        sd.ellipse((x - r / 2, y - r / 2, x + r / 2, y + r / 2), fill=(255, 255, 255, b))
    img = Image.alpha_composite(img, stars)

    # Distant castle on a hill: a generic fairy-tale silhouette, misty.
    castle = Image.new("RGBA", (W, H), (0, 0, 0, 0))
    cd = ImageDraw.Draw(castle)
    hill = (34, 28, 72, 255)
    cd.ellipse((-160, 470, 420, 780), fill=hill)
    cd.ellipse((260, 520, 900, 840), fill=(30, 24, 64, 255))
    cd.ellipse((620, 500, 1240, 840), fill=(30, 24, 64, 255))
    col = (66, 58, 122, 255)
    cx, base = 150, 496
    # (x offset, width, wall height, spire height)
    towers = [(-120, 22, 70, 46), (-82, 28, 110, 62), (-40, 30, 150, 80), (0, 36, 205, 120),
              (42, 30, 140, 76), (84, 26, 100, 58), (118, 20, 64, 40)]
    cd.rectangle((cx - 130, base - 52, cx + 128, base + 10), fill=col)
    for dx, w, hgt, sp in towers:
        x = cx + dx
        cd.rectangle((x - w // 2, base - hgt, x + w // 2, base), fill=col)
        cd.polygon([(x - w // 2 - 4, base - hgt), (x + w // 2 + 4, base - hgt), (x, base - hgt - sp)], fill=col)
        cd.line((x, base - hgt - sp, x, base - hgt - sp - 10), fill=col, width=2)
    # Moon-side rim light on the towers.
    rim = Image.new("RGBA", (W, H), (0, 0, 0, 0))
    rd = ImageDraw.Draw(rim)
    for dx, w, hgt, sp in towers:
        x = cx + dx
        rd.line((x + w // 2, base - hgt, x + w // 2, base), fill=(150, 140, 220, 160), width=2)
        rd.line((x + w // 2 + 4, base - hgt, x, base - hgt - sp), fill=(150, 140, 220, 130), width=2)
    castle = Image.alpha_composite(castle, rim)
    win = Image.new("RGBA", (W, H), (0, 0, 0, 0))
    wd = ImageDraw.Draw(win)
    for dx, w, hgt, sp in towers:
        x = cx + dx
        for k in range(max(1, hgt // 55)):
            wy = base - hgt + 16 + k * 34
            wd.rounded_rectangle((x - 3, wy, x + 3, wy + 9), 3, fill=(255, 214, 140, 240))
    castle = Image.alpha_composite(castle, win)
    castle = castle.filter(ImageFilter.GaussianBlur(0.7))
    img = Image.alpha_composite(img, castle)
    img = Image.alpha_composite(img, win.filter(ImageFilter.GaussianBlur(6)))

    # Mist banks.
    mist = Image.new("L", (W, H), 0)
    md = ImageDraw.Draw(mist)
    for _ in range(26):
        x, y = rnd.randint(-100, W), rnd.randint(470, 610)
        md.ellipse((x, y, x + rnd.randint(180, 360), y + rnd.randint(40, 80)), fill=rnd.randint(60, 120))
    mist = mist.filter(ImageFilter.GaussianBlur(24))
    ml = Image.new("RGBA", (W, H), (150, 140, 210, 0))
    ml.putalpha(mist)
    img = Image.alpha_composite(img, ml)

    # Vignette.
    vig = Image.new("L", (W, H), 0)
    ImageDraw.Draw(vig).ellipse((-160, -140, W + 160, H + 140), fill=255)
    vig = vig.filter(ImageFilter.GaussianBlur(90))
    dark = Image.new("RGBA", (W, H), (3, 3, 12, 255))
    dark.putalpha(vig.point(lambda v: int((255 - v) * 0.75)))
    img = Image.alpha_composite(img, dark)
    return img.convert("RGB")


def pack(items):
    """Shelf packing into a 1024-wide atlas."""
    aw = 1024
    items = sorted(items, key=lambda it: -it[1].height)
    x = y = shelf = 0
    placed = []
    for name, im in items:
        if x + im.width > aw:
            x, y, shelf = 0, y + shelf + 2, 0
        placed.append((name, im, x, y))
        x += im.width + 2
        shelf = max(shelf, im.height)
    ah = y + shelf
    atlas = Image.new("RGBA", (aw, ah), (0, 0, 0, 0))
    for name, im, px, py in placed:
        atlas.paste(im, (px, py))
    return atlas, placed


def main():
    OUT.mkdir(exist_ok=True)
    background().save(OUT / "fondo.png", optimize=True)
    items = [(tid, text_sprite(t, f, st)) for tid, t, f, st in TEXTS]
    items += [("G_BUTTON", button(False)), ("G_BUTTON_SEL", button(True)), ("G_PANEL", panel()),
              ("G_ORNAMENT", ornament()), ("G_CARD0", card(0)), ("G_CARD1", card(1)), ("G_CARD2", card(2)),
              ("G_TWINKLE", twinkle())]
    atlas, placed = pack(items)
    atlas.save(OUT / "atlas.png", optimize=True)
    order = [tid for tid, *_ in TEXTS] + ["G_BUTTON", "G_BUTTON_SEL", "G_PANEL", "G_ORNAMENT", "G_CARD0", "G_CARD1",
                                         "G_CARD2", "G_TWINKLE"]
    rect = {n: (x, y, im.width, im.height) for n, im, x, y in placed}
    with open(OUT / "atlas.h", "w") as h:
        h.write("/* Generated by make_assets.py: sprites in atlas.png. */\n")
        h.write("enum {\n" + "".join(f"    {n},\n" for n in order) + "    SPRITE_COUNT\n};\n")
        h.write("static const SDL_Rect kSprites[SPRITE_COUNT] = {\n")
        h.write("".join(f"    {{{r[0]}, {r[1]}, {r[2]}, {r[3]}}}, /* {n} */\n" for n in order for r in [rect[n]]))
        h.write("};\n")
    print(f"atlas {atlas.size}, {len(order)} sprites")


if __name__ == "__main__":
    main()
