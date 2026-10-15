#!/usr/bin/env python3
"""Builds the "Reino de Corazones" program folder, ready to share.

    ReinoDeCorazones/
      ReinoDeCorazones.exe          menu: asks for the player's ROM, starts the game
      motor/rdc-usa.exe, .map       engine for the USA version (B8CE)
      motor/rdc-eur.exe, .map       engine for the European version (B8CP)
      rom/ partidas/ config/ capturas/ registros/
      LEEME.txt, licencias/

The engines contain none of the game's data: port/tools/strip_rom.c removes
it and writes the .map table the engine uses to rebuild it from the
player's own ROM. Your ROMs are only read here to compute that table.

usage: python3 port/tools/package.py [--no-build] [--out DIR]
       (needs roms/B8CE.gba and/or roms/B8CP.gba)
"""
import argparse
import shutil
import subprocess
import sys
import zipfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
REGIONS = [("us", "usa", "B8CE.gba", "build/pc/win32"), ("eu", "eur", "B8CP.gba", "build/pc/win32-eu")]
STRIP = "i686-w64-mingw32-strip"


def run(cmd, **kw):
    print("+", " ".join(str(c) for c in cmd), flush=True)
    subprocess.run([str(c) for c in cmd], cwd=ROOT, check=True, **kw)


def crlf(text):
    return text.replace("\r\n", "\n").replace("\n", "\r\n").encode("utf-8-sig")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--no-build", action="store_true")
    ap.add_argument("--out", default="dist")
    args = ap.parse_args()
    out = ROOT / args.out
    prog = out / "ReinoDeCorazones"
    strip = STRIP if shutil.which(STRIP) else "strip"

    regions = [r for r in REGIONS if (ROOT / "roms" / r[2]).is_file()]
    if not regions:
        sys.exit("error: put roms/B8CE.gba and/or roms/B8CP.gba first")
    if not args.no_build:
        py = sys.executable
        run([py, "port/build.py", "--target", "win32", "--app", "launcher"])
        for ver, _, _, _ in regions:
            run([py, "port/build.py", "--target", "win32", "--version", ver])

    tools = ROOT / "build/pc/tools"
    tools.mkdir(parents=True, exist_ok=True)
    run(["cc", "-O2", "-o", tools / "strip_rom", "port/tools/strip_rom.c"])

    if prog.exists():
        shutil.rmtree(prog)
    for d in ["motor", "rom", "partidas", "config", "capturas", "registros", "licencias"]:
        (prog / d).mkdir(parents=True)

    run([strip, "-o", prog / "ReinoDeCorazones.exe", "build/pc/launcher/ReinoDeCorazones.exe"])
    for ver, rid, rom, bdir in regions:
        tmp = tools / f"rdc-{rid}-full.exe"
        run([strip, "-o", tmp, f"{bdir}/khcom.exe"])
        run([tools / "strip_rom", tmp, f"roms/{rom}", rid, prog / f"motor/rdc-{rid}.exe", prog / f"motor/rdc-{rid}.map"])
        tmp.unlink()

    (prog / "LEEME.txt").write_bytes(crlf((ROOT / "port/launcher/LEEME.txt").read_text(encoding="utf-8")))
    (prog / "rom/COLOCA_AQUI_TU_JUEGO.txt").write_bytes(crlf(
        "Aqui se guarda la copia de tu juego (.gba) que elijas en el menu.\n"
        "Tambien puedes copiar tu archivo .gba en esta carpeta: el menu lo reconoce solo.\n"))
    lic = prog / "licencias"
    shutil.copy(ROOT / "port/deps/SDL2-2.32.8/LICENSE.txt", lic / "SDL2.txt")
    for f in (ROOT / "port/launcher/fonts").glob("OFL-*.txt"):
        shutil.copy(f, lic / f.name)
    (lic / "LEEME.txt").write_bytes(crlf(
        "Reino de Corazones usa:\n"
        "- SDL2 (licencia zlib): SDL2.txt\n"
        "- Fuentes Cinzel, Cinzel Decorative y Cormorant Garamond (SIL Open Font License): OFL-*.txt\n"
        "- stb_image (dominio publico)\n"
        "- La descompilacion de Kingdom Hearts: Chain of Memories (github.com/Pheenoh/khcom, CC0)\n\n"
        "Kingdom Hearts es una marca de Disney y Square Enix. Este programa no incluye ningun dato\n"
        "del juego: necesita tu propia copia legitima.\n"))

    zpath = out / "ReinoDeCorazones.zip"
    with zipfile.ZipFile(zpath, "w", zipfile.ZIP_DEFLATED, compresslevel=9) as z:
        for p in sorted(prog.rglob("*")):
            arc = p.relative_to(out).as_posix() + ("/" if p.is_dir() else "")
            if p.is_dir():
                z.writestr(arc, "")
            else:
                z.write(p, arc)
    print(f"done: {zpath} ({zpath.stat().st_size // 1024} KiB)")


if __name__ == "__main__":
    main()
