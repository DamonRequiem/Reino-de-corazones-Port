#!/usr/bin/env python3
"""Pre-renders the in-game options menu (Esc): Spanish text with the bundled
OFL fonts, arrows and row highlight. Same look as the launcher.

Outputs (committed): port/res/menu_atlas.png, port/res/menu_atlas.h
Usage: python3 port/launcher/make_menu_assets.py
"""
from pathlib import Path

from PIL import Image, ImageDraw, ImageFilter

import make_assets as A

OUT = Path(__file__).resolve().parents[1] / "res"

TITLE = A.font("CinzelDecorative-Bold.ttf", 48)
LABEL = A.font("Cinzel.ttf", 21, 600)
VALUE = A.font("CormorantGaramond.ttf", 25, 600)
HELP = A.font("CormorantGaramond.ttf", 21, 500)
SMALL = A.font("CormorantGaramond.ttf", 19, 500)

TEXTS = [
    ("M_TITLE", "Pausa", TITLE, "title"),
    # labels
    ("L_CONTINUE", "Continuar", LABEL, "plain"),
    ("L_FPS", "Cuadros por segundo", LABEL, "plain"),
    ("L_SCALE", "Resolución", LABEL, "plain"),
    ("L_FILTER", "Filtro", LABEL, "plain"),
    ("L_COLORS", "Colores de GBA", LABEL, "plain"),
    ("L_GHOST", "Estela de pantalla LCD", LABEL, "plain"),
    ("L_FULL", "Pantalla completa", LABEL, "plain"),
    ("L_VSYNC", "Sincronía vertical", LABEL, "plain"),
    ("L_VOLUME", "Volumen", LABEL, "plain"),
    ("L_SAVE", "Guardar estado", LABEL, "plain"),
    ("L_LOAD", "Cargar estado", LABEL, "plain"),
    ("L_QUIT", "Salir al menú principal", LABEL, "plain"),
    ("L_QUIT_ALONE", "Salir del juego", LABEL, "plain"),
    # values
    ("V_30", "30", VALUE, "plain"),
    ("V_60", "60", VALUE, "plain"),
    ("V_120", "120", VALUE, "plain"),
    ("V_S1", "1x  ·  240 × 160", VALUE, "plain"),
    ("V_S2", "2x  ·  480 × 320", VALUE, "plain"),
    ("V_S3", "3x  ·  720 × 480", VALUE, "plain"),
    ("V_S4", "4x  ·  960 × 640", VALUE, "plain"),
    ("V_S5", "5x  ·  1200 × 800", VALUE, "plain"),
    ("V_F0", "Original", VALUE, "plain"),
    ("V_F1", "Suave", VALUE, "plain"),
    ("V_F2", "Píxel limpio", VALUE, "plain"),
    ("V_F3", "Bordes suaves", VALUE, "plain"),
    ("V_F4", "Pantalla LCD de GBA", VALUE, "plain"),
    ("V_F5", "Televisor CRT", VALUE, "plain"),
    ("V_NO", "No", VALUE, "plain"),
    ("V_YES", "Sí", VALUE, "plain"),
] + [(f"V_VOL{v}", f"{v} %", VALUE, "plain") for v in range(0, 101, 10)] + [
    # help line for the selected row
    ("H_CONTINUE", "Vuelve a la partida.", HELP, "plain"),
    ("H_FPS", "30 ahorra energía  ·  60 es la velocidad de la consola  ·  120 suaviza en monitores de 120 Hz.", HELP, "plain"),
    ("H_FPS_60HZ", "Tu monitor es de 60 Hz: con 120 se verá igual que con 60.", HELP, "plain"),
    ("H_SCALE", "Tamaño de la imagen del juego. En pantalla completa ocupa toda la pantalla.", HELP, "plain"),
    ("H_F0", "Píxeles nítidos, tal como los dibuja la consola.", HELP, "plain"),
    ("H_F1", "Imagen suavizada, sin bordes de píxel.", HELP, "plain"),
    ("H_F2", "Píxeles nítidos que se ven limpios a cualquier tamaño de ventana.", HELP, "plain"),
    ("H_F3", "Redondea las escaleras de los bordes sin emborronar (Scale2x / Scale3x).", HELP, "plain"),
    ("H_F4", "Imita la pantalla de la Game Boy Advance, con su rejilla entre píxeles.", HELP, "plain"),
    ("H_F5", "Imita un televisor antiguo, con sus líneas.", HELP, "plain"),
    ("H_COLORS", "Colores más suaves, como en la pantalla original de la consola, que no tenía luz.", HELP, "plain"),
    ("H_GHOST", "Mezcla cada cuadro con el anterior, como la pantalla original.", HELP, "plain"),
    ("H_FULL", "Pantalla completa (también F11 o Alt+Enter).", HELP, "plain"),
    ("H_VSYNC", "Sincroniza con el monitor para evitar tirones y cortes en la imagen.", HELP, "plain"),
    ("H_VOLUME", "Volumen del juego (F9 lo silencia).", HELP, "plain"),
    ("H_SAVE", "Guarda la partida tal como está en este momento (también F5).", HELP, "plain"),
    ("H_LOAD", "Vuelve al último estado guardado (también F8).", HELP, "plain"),
    ("H_QUIT", "Cierra el juego y vuelve al menú de Reino de Corazones.", HELP, "plain"),
    ("H_QUIT_ALONE", "Cierra el juego.", HELP, "plain"),
    ("M_KEYS", "Flechas: elegir y cambiar  ·  Enter: aceptar  ·  Esc: volver al juego", SMALL, "soft"),
    # Android (touch screen)
    ("L_TOPACITY", "Botones en pantalla", LABEL, "plain"),
    ("L_TSIZE", "Tamaño de los botones", LABEL, "plain"),
    ("L_VIBRATION", "Vibración", LABEL, "plain"),
    ("V_TSMALL", "Pequeños", VALUE, "plain"),
    ("V_TNORMAL", "Normales", VALUE, "plain"),
    ("V_TLARGE", "Grandes", VALUE, "plain"),
    ("H_TOPACITY", "Opacidad de los botones táctiles. Con 0 % se ocultan (para jugar con mando).", HELP, "plain"),
    ("H_TSIZE", "Tamaño de los botones táctiles.", HELP, "plain"),
    ("H_VIBRATION", "Vibra un instante al pulsar un botón táctil.", HELP, "plain"),
    ("H_FPS_T", "30 ahorra batería  ·  60 es la velocidad de la consola  ·  120 suaviza en pantallas de 120 Hz.", HELP, "plain"),
    ("H_FPS_60HZ_T", "Tu pantalla es de 60 Hz: con 120 se verá igual que con 60.", HELP, "plain"),
    ("H_VOLUME_T", "Volumen del juego.", HELP, "plain"),
    ("H_SAVE_T", "Guarda la partida tal como está en este momento.", HELP, "plain"),
    ("H_LOAD_T", "Vuelve al último estado guardado.", HELP, "plain"),
    ("H_QUIT_T", "Cierra el juego y vuelve al menú de Reino de Corazones (tu partida guardada no se pierde).", HELP, "plain"),
    ("L_ASPECT", "Forma de la pantalla", LABEL, "plain"),
    ("V_ASPECT0", "Original  ·  3:2", VALUE, "plain"),
    ("V_ASPECT1", "4:3", VALUE, "plain"),
    ("V_ASPECT2", "Panorámica  ·  16:9", VALUE, "plain"),
    ("V_ASPECT3", "Completa", VALUE, "plain"),
    ("H_ASPECT0", "Como en la GBA. A los lados, el castillo de corazones.", HELP, "plain"),
    ("H_ASPECT1", "Más cuadrada, como un televisor antiguo. A los lados, el castillo de corazones.", HELP, "plain"),
    ("H_ASPECT2", "Algo más ancha: estira la imagen con suavidad, sin deformar los píxeles.", HELP, "plain"),
    ("H_ASPECT3", "Ocupa toda la pantalla del teléfono (la imagen se estira a lo ancho).", HELP, "plain"),
    ("L_FFSPEED", "Modo rápido", LABEL, "plain"),
    ("V_FF2", "x2", VALUE, "plain"),
    ("V_FF3", "x3", VALUE, "plain"),
    ("V_FF4", "x4", VALUE, "plain"),
    ("H_FFSPEED", "Velocidad del botón de avance rápido. La música se acelera igual.", HELP, "plain"),
    ("L_STICK", "Control de movimiento", LABEL, "plain"),
    ("V_STICK0", "Joystick flotante", VALUE, "plain"),
    ("V_STICK1", "Joystick fijo", VALUE, "plain"),
    ("V_STICK2", "Cruceta", VALUE, "plain"),
    ("H_STICK0", "El joystick aparece donde pongas el dedo, en todo el lado izquierdo.", HELP, "plain"),
    ("H_STICK1", "El joystick se queda en su sitio; tócalo para moverte.", HELP, "plain"),
    ("H_STICK2", "Cruceta clásica de cuatro direcciones (y diagonales).", HELP, "plain"),
    ("M_TOUCH", "Toca una opción  ·  toca a los lados del valor para cambiarlo  ·  Atrás: volver al juego", SMALL, "soft"),
]


def arrow(direction):
    s, k = 22, 4
    big = Image.new("RGBA", (s * k, s * k), (0, 0, 0, 0))
    d = ImageDraw.Draw(big)
    if direction < 0:
        pts = [(16 * k, 3 * k), (5 * k, 11 * k), (16 * k, 19 * k)]
    else:
        pts = [(6 * k, 3 * k), (17 * k, 11 * k), (6 * k, 19 * k)]
    d.polygon(pts, fill=(255, 255, 255, 255))
    return big.resize((s, s), Image.LANCZOS)


def row_highlight():
    w, h = 680, 36
    img = Image.new("RGBA", (w, h), (0, 0, 0, 0))
    d = ImageDraw.Draw(img)
    for x in range(w):
        k = 1 - abs(x - w / 2) / (w / 2)
        a = int(110 * min(1, k * 2.2))
        d.line([(x, 2), (x, h - 3)], fill=(120, 96, 200, a))
    d.line([(20, 1), (w - 20, 1)], fill=A.GOLD + (150,))
    d.line([(20, h - 2), (w - 20, h - 2)], fill=A.GOLD + (150,))
    return img


def menu_panel():
    return A.rounded((760, 590), 22, (8, 10, 32, 228), (220, 190, 120, 200), 2, glow=(120, 100, 220, 120))


def main():
    items = [(tid, A.text_sprite(t, f, st)) for tid, t, f, st in TEXTS]
    items += [("G_LEFT", arrow(-1)), ("G_RIGHT", arrow(1)), ("G_ROW", row_highlight()), ("G_MPANEL", menu_panel()),
              ("G_MORNAMENT", A.ornament())]
    atlas, placed = A.pack(items)
    atlas.save(OUT / "menu_atlas.png", optimize=True)
    order = [n for n, _ in items]
    rect = {n: (x, y, im.width, im.height) for n, im, x, y in placed}
    with open(OUT / "menu_atlas.h", "w") as h:
        h.write("/* Generated by port/launcher/make_menu_assets.py: sprites in menu_atlas.png. */\n")
        h.write("enum {\n" + "".join(f"    {n},\n" for n in order) + "    MENU_SPRITE_COUNT\n};\n")
        h.write("static const SDL_Rect kMenuSprites[MENU_SPRITE_COUNT] = {\n")
        h.write("".join(f"    {{{r[0]}, {r[1]}, {r[2]}, {r[3]}}}, /* {n} */\n" for n in order for r in [rect[n]]))
        h.write("};\n")
    print(f"menu atlas {atlas.size}, {len(order)} sprites")


if __name__ == "__main__":
    main()
