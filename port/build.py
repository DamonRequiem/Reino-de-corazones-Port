#!/usr/bin/env python3
"""Build the PC port of Kingdom Hearts: Chain of Memories.

Generates a ninja file that compiles the decompiled game (src/), the game data
(converted from the generated ARM data assembly) and the PC hardware layer
(port/) with a host compiler, then builds it.

Prerequisites (once, from the repository root):
    python3 tools/extract_assets.py us      # needs roms/B8CE.gba
    python3 configure.py && ninja <gen targets>   # see port/README.md

Usage:
    python3 port/build.py [--target linux32|win32] [--app sdl|headless] [--clean]
"""
import argparse
import os
import re
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import ninja_syntax  # noqa: E402  (shipped with the decomp)

VERSION = "us"  # game version being built: "us" (B8CE) or "eu" (B8CP); set by --version

# Units that only exist for the GBA ROM image or are replaced by port/.
REPLACED_ASM = {
    "header.s",            # ROM header
    "crt0.s",              # ARM startup + IRQ dispatcher   -> port/pc_intr.c, pc_main_*.c
    "libagbsyscall.s",     # BIOS calls                     -> port/pc_bios.c
    "m4a_1.s",             # m4a sound engine core          -> port/pc_m4a.c
    "movie_codec.s",       # cutscene codecs                -> port/pc_movie_codec.c
    "transform.s",         # audio codec transform          -> port/pc_transform.c
    "transform_veneers.s",
}

TARGETS = {
    "linux32": {
        "cc": "gcc", "as": "as", "objcopy": None, "exe": "", "windres": None,
        "cflags": ["-m32", "-fno-pie"], "asflags": ["--32"], "ldflags": ["-m32", "-no-pie"], "libs": ["-lm"],
        "datafmt": "elf",
    },
    "win32": {
        "cc": "i686-w64-mingw32-gcc", "as": "i686-w64-mingw32-as", "objcopy": "i686-w64-mingw32-objcopy",
        "windres": "i686-w64-mingw32-windres",
        "exe": ".exe",
        "cflags": ["-mno-ms-bitfields"], "asflags": [],
        # Fixed image base: quick-save files hold pointers into the exe's memory.
        "ldflags": ["-static", "-static-libgcc", "-Wl,--disable-dynamicbase"], "libs": ["-lm"],
        "datafmt": "coff",
    },
    # 32-bit ARM Linux (glibc): test build of the ARM code path, run with qemu-arm.
    # Same compiler and code generation as the Android build (armeabi-v7a).
    "linuxarm": {
        "cc": "clang --target=arm-linux-gnueabihf -march=armv7-a -mfpu=vfpv3-d16 -marm",
        "as": "clang --target=arm-linux-gnueabihf -c -x assembler", "objcopy": "llvm-objcopy", "exe": "",
        "windres": None, "cflags": ["-fno-pie"], "asflags": [], "ldflags": ["-fuse-ld=lld", "-static"],
        "libs": ["-lm"], "datafmt": "elf",
    },
    # The same as a shared library loaded at a run-time address, like on
    # Android: tests the ROM-data relocation (port/tools/so_runner.c runs it).
    "linuxarmso": {
        "cc": "clang --target=arm-linux-gnueabihf -march=armv7-a -mfpu=vfpv3-d16 -marm",
        "as": "clang --target=arm-linux-gnueabihf -c -x assembler", "objcopy": "llvm-objcopy", "exe": ".so",
        "windres": None, "cflags": ["-fPIC", "-DPC_ROMDATA_RELOC"], "asflags": [],
        "ldflags": ["-fuse-ld=lld", "-shared", "-Wl,-Bsymbolic", "-Wl,-z,defs", "-Wl,-z,now"], "libs": ["-lm", "-ldl"],
        "datafmt": "elf",
    },
    # The game as a 32-bit core for 64-bit-only phones (port/wasm/): wasm32,
    # turned into C by wasm2c and compiled natively for arm64 by the app build.
    "wasm": {
        "cc": "clang --target=wasm32-wasip1 --sysroot=$wasisysroot", "as": "clang --target=wasm32 -c -x assembler",
        "objcopy": None, "exe": ".wasm", "windres": None, "cflags": [], "asflags": [],
        "ldflags": ["-mexec-model=reactor", "-Wl,--global-base=65536", "-Wl,-z,stack-size=1048576",
                    "-Wl,--initial-memory=67108864", "-Wl,--max-memory=268435456"],
        "libs": ["-lm"], "datafmt": "wasm",
    },
    # Android armeabi-v7a: the game is libgame.so, loaded by the app (port/android/).
    # Needs the sysroot from port/android/toolchain.md (ANDROID_SYSROOT).
    "android": {
        "cc": "clang --target=armv7a-linux-androideabi21 --sysroot=$sysroot -march=armv7-a -mfpu=vfpv3-d16 "
              "-mfloat-abi=softfp -marm",
        "as": "clang --target=armv7a-linux-androideabi21 -c -x assembler", "objcopy": "llvm-objcopy",
        "exe": ".so", "windres": None, "cflags": ["-fPIC"], "asflags": [],
        "ldflags": ["-fuse-ld=lld", "-shared", "-Wl,-z,defs", "-Wl,-soname,libgame.so", "-Wl,-Bsymbolic",
                    "-Wl,--hash-style=both", "-Wl,-z,max-page-size=16384"],
        "libs": ["-lm", "-ldl", "-llog", "-landroid"], "datafmt": "elf",
    },
}

# Common flags. The decompiled code was written for a 2001-era compiler, so the
# modern optimizer must not exploit undefined behaviour it may contain.
GAME_CFLAGS = [
    "-std=gnu89", "-O2", "-g",
    "-fno-strict-aliasing", "-fwrapv", "-fno-delete-null-pointer-checks", "-fno-common",
    "-w",
    "-DPLATFORM_PC",
]
PORT_CFLAGS = ["-std=gnu11", "-O2", "-g", "-Wall", "-Wextra", "-Wno-unused-parameter"]

APPS = {
    "sdl": ["pc_main_sdl.c", "pc_config.c", "pc_win32_diag.c", "pc_audio_out.c", "pc_video.c", "pc_menu.c",
            "pc_touch.c"],  # the game in a window (needs SDL2); on Android, the app's libgame.so
    "headless": ["pc_main_headless.c"],  # no window: automated tests and screenshots
    "core": ["pc_core.c"],  # the 32-bit core for 64-bit phones (--target wasm)
    "launcher": [],  # ReinoDeCorazones.exe: the menu that asks for the ROM (port/launcher/)
}

# Libraries a static SDL2 needs on Windows.
SDL_WIN_STATIC_LIBS = ["-lmingw32", "-lSDL2main", "-lSDL2", "-lm", "-ldinput8", "-ldxguid", "-ldxerr8", "-luser32",
                       "-lgdi32", "-lwinmm", "-limm32", "-lole32", "-loleaut32", "-lshell32", "-lsetupapi",
                       "-lversion", "-luuid", "-ladvapi32", "-lcfgmgr32"]


def sdl_flags(target, sdl_dir):
    """Compiler and linker flags for SDL2 on the given target."""
    if target == "android":
        # port/android/build_sdl.py + build_apk.py make libSDL2.so here.
        d = Path(sdl_dir or "build/android/sdl")
        if not (d / "libSDL2.so").exists():
            sys.exit(f"error: {d}/libSDL2.so missing; run python3 port/android/build_apk.py")
        return [f"-I{d}/include"], [f"-L{d}", "-lSDL2"]
    if target == "win32":
        candidates = [Path(sdl_dir)] if sdl_dir else sorted(Path("port/deps").glob("SDL2-*/i686-w64-mingw32"))
        for d in candidates:
            if (d / "include/SDL2/SDL.h").exists():
                return [f"-I{d}/include/SDL2", "-Dmain=SDL_main"], [f"-L{d}/lib"] + SDL_WIN_STATIC_LIBS + ["-mwindows"]
    # pkg-config: MSYS2 (pacman -S mingw-w64-i686-SDL2) or a system install.
    try:
        cflags = subprocess.check_output(["pkg-config", "--cflags", "sdl2"], text=True).split()
        libs = subprocess.check_output(["pkg-config", "--libs", "--static", "sdl2"], text=True).split()
        if target == "win32":
            libs.append("-mwindows")
        return cflags, libs
    except (OSError, subprocess.CalledProcessError):
        sys.exit("error: SDL2 not found. Run python3 port/tools/fetch_sdl2.py, or install SDL2 "
                 "(MSYS2: pacman -S mingw-w64-i686-SDL2)")
PORT_COMMON = ["pc_memory.c", "pc_bios.c", "pc_dma.c", "pc_intr.c", "pc_frame.c",
               "pc_render.c", "pc_screenshot.c", "pc_divzero.c", "pc_softreset.c", "pc_save.c", "pc_fault.c", "pc_state.c", "pc_apu.c", "pc_romdata.c"]
# Port files that use the game's headers and types (built with the game flags).
PORT_GAME = ["pc_m4a.c", "pc_transform.c", "pc_movie_codec.c"]


def game_include_dirs():
    inc = ROOT / "include"
    dirs = ["include"] + sorted(f"include/{p.name}" for p in inc.iterdir() if p.is_dir() and p.name != "gba")
    return dirs + [".", f"build/{VERSION}/gen"]


def read_units():
    units = []
    for line in (ROOT / f"config/{VERSION}/units.txt").read_text().splitlines():
        line = line.strip()
        if not line or line.startswith("#"):
            continue
        units.append(line.split()[0])
    return units


def build_launcher(tgt, args):
    """ReinoDeCorazones.exe: one C file plus its resources (Windows only)."""
    if args.target != "win32":
        sys.exit("error: the launcher is a Windows program (--target win32)")
    if not shutil.which(tgt["cc"]) and shutil.which("gcc"):
        tgt.update(cc="gcc", windres="windres")
    out = Path("build/pc/launcher")
    out.mkdir(parents=True, exist_ok=True)
    cflags, libs = sdl_flags("win32", args.sdl_dir)
    windres = tgt["windres"] if shutil.which(tgt["windres"]) else "windres"
    cmds = [
        [windres, "-O", "coff", "-I", "port/launcher", "port/launcher/launcher.rc", str(out / "launcher_res.o")],
        [tgt["cc"], "-std=gnu11", "-O2", "-Wall", "-Wno-unused-function", *cflags, "-c", "port/launcher/launcher.c",
         "-o", str(out / "launcher.o")],
        [tgt["cc"], "-static", "-static-libgcc", "-o", str(out / "ReinoDeCorazones.exe"), str(out / "launcher.o"),
         str(out / "launcher_res.o"), *libs, "-lcomdlg32"],
    ]
    for c in cmds:
        print("+", " ".join(c))
        if subprocess.call(c) != 0:
            sys.exit(1)
    return 0


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--target", choices=TARGETS, default="linux32")
    ap.add_argument("--app", choices=APPS, default=None,
                    help="default: sdl for win32, headless for linux32")
    ap.add_argument("--sdl-dir", help="SDL2 MinGW directory (i686-w64-mingw32)")
    ap.add_argument("--version", choices=["us", "eu"], default="us", help="game version (default: us)")
    ap.add_argument("--clean", action="store_true")
    ap.add_argument("--asan", action="store_true",
                    help="linux32 test build with AddressSanitizer (finds out-of-bounds accesses)")
    ap.add_argument("--touch-test", action="store_true",
                    help="desktop build with the phone's on-screen controls (the mouse is a finger)")
    ap.add_argument("-j", "--jobs", type=int, default=0)
    args = ap.parse_args()

    os.chdir(ROOT)
    global VERSION
    VERSION = args.version
    if args.app is None:
        args.app = "sdl" if args.target == "win32" else "headless"
    tgt = dict(TARGETS[args.target])
    if args.target == "android":
        sysroot = os.environ.get("ANDROID_SYSROOT", str(ROOT / "port/deps/android/sysroot"))
        tgt["cc"] = tgt["cc"].replace("$sysroot", sysroot)
    if args.target == "wasm":
        wasi = os.environ.get("WASI_SYSROOT", str(ROOT / "port/deps/wasm/wasi-sysroot"))
        tgt["cc"] = tgt["cc"].replace("$wasisysroot", wasi)
        if args.app is None:
            args.app = "core"
    if args.app == "launcher":
        return build_launcher(tgt, args)
    if args.target == "win32" and not shutil.which(tgt["cc"]) and shutil.which("gcc"):
        # Building on Windows itself (MSYS2 "MINGW32" shell): the tools have plain names.
        tgt.update(cc="gcc", objcopy="objcopy")
        tgt["as"] = "as"
    bdir = f"build/pc/{args.target}" + ("" if VERSION == "us" else "-" + VERSION) + ("-asan" if args.asan else "") + \
        ("-touch" if args.touch_test else "")
    if args.touch_test:
        tgt["cflags"] = tgt["cflags"] + ["-DPC_FORCE_TOUCH"]
    if args.asan:
        if args.target != "linux32":
            sys.exit("error: --asan is only supported for linux32")
        san = ["-fsanitize=address", "-fno-omit-frame-pointer"]
        tgt["cflags"] = tgt["cflags"] + san + ["-DPC_ASAN"]
        tgt["ldflags"] = tgt["ldflags"] + san
    gen = Path(f"build/{VERSION}/gen")
    if not gen.is_dir() or not any(gen.glob("*.s")):
        sys.exit("error: generated data is missing; see port/README.md (asset generation step)")
    if args.clean and Path(bdir).exists():
        shutil.rmtree(bdir)
    Path(bdir).mkdir(parents=True, exist_ok=True)

    c_sources = {p.name: p for p in Path("src").rglob("*.c")}
    game_c, data_s, skipped = [], [], []
    for name in read_units():
        if name.startswith("@"):
            skipped.append(name)          # agbcc libgcc/libc members -> host runtime
        elif name.endswith(".c"):
            if name not in c_sources:
                sys.exit(f"error: unit {name} not found under src/")
            game_c.append(c_sources[name])
        elif name in REPLACED_ASM:
            skipped.append(name)
        elif (gen / name).exists():
            data_s.append(gen / name)
        else:
            sys.exit(f"error: unit {name} is neither C, generated data, nor a known replaced asm file")

    app_cflags, app_libs = sdl_flags(args.target, args.sdl_dir) if args.app == "sdl" else ([], [])
    # The game's headers include "malloc.h", which Android's <stdlib.h> also
    # includes (as <malloc.h>): there they may only answer quoted includes.
    inc_opt = "-iquote " if args.target == "android" else "-I"
    inc_flags = " ".join(f"{inc_opt}{d}" for d in game_include_dirs())
    out = Path(bdir) / f"build_{args.app}.ninja"
    with out.open("w") as f:
        n = ninja_syntax.Writer(f, width=120)
        n.variable("cc", tgt["cc"])
        n.variable("as", tgt["as"])
        n.variable("game_cflags", " ".join(tgt["cflags"] + GAME_CFLAGS + [f"-DVERSION_{VERSION.upper()}"]) + " " + inc_flags)
        n.variable("port_cflags", " ".join(tgt["cflags"] + PORT_CFLAGS) + " -Iport/include")
        n.variable("asflags", " ".join(tgt["asflags"] + (["--divide"] if tgt["as"] in ("as", "i686-w64-mingw32-as") else []) + ["-I."]))
        n.variable("ldflags", " ".join(tgt["ldflags"]))
        n.variable("libs", " ".join(tgt["libs"]))
        n.variable("app_cflags", " ".join(app_cflags))
        n.variable("app_libs", " ".join(app_libs))
        n.newline()
        n.rule("cc_game", "$cc $game_cflags -MMD -MF $out.d -c $in -o $out", depfile="$out.d", deps="gcc",
               description="CC $in")
        # The game's own constant tables (dialogue, decks, animation frames...)
        # are ROM content too: move them into "romdat" with the extracted data,
        # so the shipped engine can leave them out (port/tools/strip_rom.c).
        oc = tgt["objcopy"] or "objcopy"
        if tgt["datafmt"] == "coff":
            ren = ("--rename-section .rdata=.romdat,alloc,load,contents,data "
                   "--rename-section .data=.romdatw,alloc,load,contents,data")
        else:
            ren = " ".join(f"--rename-section {s}=romdat,alloc,load,contents,data"
                           for s in [".rodata", ".rodata.str1.1", ".rodata.str1.4", ".rodata.cst4", ".rodata.cst8",
                                     ".rodata.cst16", ".data.rel.ro", ".data.rel.ro.local"])
            ren += " " + " ".join(f"--rename-section {s}=romdatw,alloc,load,contents,data"
                                  for s in [".data", ".data.rel", ".data.rel.local"])
        n.rule("cc_game_rom", f"$cc $game_cflags -MMD -MF $out.d -c $in -o $out.tmp && {oc} {ren} $out.tmp $out",
               depfile="$out.d", deps="gcc", description="CC $in")
        n.rule("cc_port", "$cc $port_cflags -MMD -MF $out.d -c $in -o $out", depfile="$out.d", deps="gcc",
               description="CC $in")
        n.rule("convert", f"python3 port/tools/convert_data.py $in $out {tgt['datafmt']} . include build/{VERSION}/gen",
               description="DATA $in")
        if tgt["datafmt"] == "coff":
            # 32-bit Windows prefixes C symbols with '_'; give the data the same names.
            n.rule("as_data", f"$as $asflags -o $out.raw $in && {tgt['objcopy']} --prefix-symbols=_ $out.raw $out",
                   description="AS $in")
        else:
            n.rule("as_data", "$as $asflags -o $out $in", description="AS $in")
        n.rule("cc_app", "$cc $port_cflags $app_cflags -MMD -MF $out.d -c $in -o $out", depfile="$out.d",
               deps="gcc", description="CC $in")
        n.rule("link", "$cc $ldflags -o $out @$out.rsp $app_libs $libs", rspfile="$out.rsp", rspfile_content="$in",
               description="LINK $out")
        n.newline()

        # pc_game_begin/end bracket the game's globals (see port/pc_game_begin.c).
        objs = [f"{bdir}/port/pc_game_begin.o"]
        n.build(objs[0], "cc_port", "port/pc_game_begin.c")
        port_game = [Path("port") / n for n in PORT_GAME]
        if args.app == "headless":
            port_game.append(Path("port/pc_selftest_game.c"))
        for src in game_c + port_game:
            obj = f"{bdir}/game/{src.with_suffix('.o')}"
            n.build(obj, "cc_game_rom" if src in game_c and tgt["datafmt"] != "wasm" else "cc_game", str(src))
            objs.append(obj)
        for src in data_s:
            conv = f"{bdir}/data/{src.stem}.s"
            # The converter inlines .include files, so rebuild when any asset changes.
            n.build(conv, "convert", str(src), implicit=["port/tools/convert_data.py", f"assets/{VERSION}/.stamp"])
            obj = f"{bdir}/data/{src.stem}.o"
            n.build(obj, "as_data", conv)
            objs.append(obj)
        n.build(f"{bdir}/port/pc_game_end.o", "cc_port", "port/pc_game_end.c")
        objs.append(f"{bdir}/port/pc_game_end.o")
        common = PORT_COMMON
        if args.target == "wasm":
            # Division by zero and stray pointers are handled where the core is
            # turned into C (port/wasm/build_core.py); the ROM data is filled in
            # by the frontend.
            common = [n for n in PORT_COMMON if n not in ("pc_divzero.c", "pc_fault.c", "pc_romdata.c")]
        for name in common:
            obj = f"{bdir}/port/{Path(name).with_suffix('.o')}"
            n.build(obj, "cc_port", f"port/{name}")
            objs.append(obj)
        for name in APPS[args.app]:
            obj = f"{bdir}/port/{Path(name).with_suffix('.o')}"
            n.build(obj, "cc_app", f"port/{name}")
            objs.append(obj)

        if args.app == "sdl" and tgt["windres"]:
            # Icon, version information and manifest (port/res/).
            windres = tgt["windres"] if shutil.which(tgt["windres"]) else "windres"
            n.rule("rc", f"{windres} -O coff -I port/res $in $out", description="RC $in")
            obj = f"{bdir}/port/khcom_res.o"
            n.build(obj, "rc", "port/res/khcom.rc", implicit=["port/res/rdc.ico", "port/res/khcom.manifest", "port/res/menu_atlas.png"])
            objs.append(obj)

        if args.target == "android":
            exe = f"{bdir}/lib{'game' if args.app == 'sdl' else 'game_' + args.app}.so"
        else:
            exe = f"{bdir}/{'khcom' if args.app == 'sdl' else 'khcom_' + args.app}{tgt['exe']}"
        n.build(exe, "link", objs)
        n.default(exe)

    print(f"{len(game_c)} C units, {len(data_s)} data units, skipped {len(skipped)} GBA-only units")
    cmd = ["ninja", "-f", str(out)]
    if args.jobs:
        cmd += ["-j", str(args.jobs)]
    sys.exit(subprocess.call(cmd))


if __name__ == "__main__":
    main()
