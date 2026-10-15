#!/usr/bin/env python3
"""Download the official SDL2 MinGW development package into port/deps/.

Only needed when cross-compiling the Windows build from Linux. On Windows with
MSYS2, install it with:  pacman -S mingw-w64-i686-SDL2
"""
import tarfile
import urllib.request
from pathlib import Path

VERSION = "2.32.8"
URL = f"https://github.com/libsdl-org/SDL/releases/download/release-{VERSION}/SDL2-devel-{VERSION}-mingw.tar.gz"
DEST = Path(__file__).resolve().parents[1] / "deps"


def main():
    target = DEST / f"SDL2-{VERSION}"
    if (target / "i686-w64-mingw32/include/SDL2/SDL.h").exists():
        print(f"SDL2 {VERSION} already present in {target}")
        return
    DEST.mkdir(parents=True, exist_ok=True)
    archive = DEST / f"SDL2-devel-{VERSION}-mingw.tar.gz"
    print(f"downloading {URL}")
    urllib.request.urlretrieve(URL, archive)
    with tarfile.open(archive) as t:
        t.extractall(DEST, filter="data")
    archive.unlink()
    print(f"SDL2 {VERSION} installed in {target}")


if __name__ == "__main__":
    main()
