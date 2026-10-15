#!/usr/bin/env python3
"""Extract and generate the game data the PC port needs, from your own ROM.

This replaces the asset steps of the GBA build (which also require the 2001-era
ARM toolchain) with only what the PC port uses:

  1. recognises the ROM by its SHA-1: USA (B8CE) or Europe (B8CP),
  2. builds gbagfx (graphics converter) if missing,
  3. extracts graphics, music and text from the ROM into assets/<version>/,
  4. generates the data sources into build/<version>/gen/.

Usage (from the repository root):
    python3 port/tools/prepare_data.py [path/to/rom.gba]
"""
import hashlib
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
# version -> (ROM file name, SHA-1, name)
ROMS = {
    "us": ("B8CE.gba", "10729bd884f8fdca7a310b6d606c52e46657aa48", "USA"),
    "eu": ("B8CP.gba", "8db73586cdb11b3795907edebf43228dbcd3e6b2", "Europe"),
}


def run(cmd):
    print("+", " ".join(str(c) for c in cmd), flush=True)
    subprocess.run([str(c) for c in cmd], cwd=ROOT, check=True)


def main():
    if len(sys.argv) > 1:
        src = Path(sys.argv[1]).resolve()
        digest = hashlib.sha1(src.read_bytes()).hexdigest()
        match = [v for v, r in ROMS.items() if r[1] == digest]
        if not match:
            sys.exit(f"error: {src.name} has SHA-1 {digest}: not the USA (B8CE) or European (B8CP) release")
        VERSION = match[0]
        rom = ROOT / "roms" / ROMS[VERSION][0]
        rom.parent.mkdir(exist_ok=True)
        if src != rom.resolve():
            shutil.copyfile(src, rom)
    else:
        found = [v for v, r in ROMS.items() if (ROOT / "roms" / r[0]).is_file()]
        if not found:
            sys.exit("error: put your ROM in roms/ (B8CE.gba or B8CP.gba) or pass its path as an argument")
        VERSION = found[0]
        rom = ROOT / "roms" / ROMS[VERSION][0]
        digest = hashlib.sha1(rom.read_bytes()).hexdigest()
        if digest != ROMS[VERSION][1]:
            sys.exit(f"error: {rom.name} has SHA-1 {digest}, expected {ROMS[VERSION][1]}")
    print(f"ROM OK: Kingdom Hearts - Chain of Memories ({ROMS[VERSION][2]}), SHA-1 {digest}")

    if not (ROOT / "tools/gbagfx/gbagfx").exists() and not (ROOT / "tools/gbagfx/gbagfx.exe").exists():
        run(["sh", "tools/fetch_gbagfx.sh"])

    py = sys.executable
    run([py, "tools/extract_assets.py", VERSION])

    for manifest in sorted((ROOT / "config/assets").glob("*.yaml")):
        run([py, "tools/assetgen.py", VERSION, manifest.relative_to(ROOT)])
    for manifest in sorted((ROOT / "config/text").glob("*.yaml")):
        run([py, "tools/textgen.py", VERSION, manifest.relative_to(ROOT)])

    count = len(list((ROOT / f"build/{VERSION}/gen").glob("*.s")))
    print(f"done: {count} data sources in build/{VERSION}/gen")


if __name__ == "__main__":
    main()
