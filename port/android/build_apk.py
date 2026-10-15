#!/usr/bin/env python3
"""Builds the Android app: ReinoDeCorazones.apk (armeabi-v7a, Android 5.0+).

    python3 port/android/build_apk.py [--out DIR]

Needs (see port/android/README.md): clang/lld 18, llvm-objcopy/strip, a
JDK, dalvik-exchange (dx), aapt, zipalign, apksigner, and in port/deps/android/:
sysroot/ (bionic headers + stub libraries), android.jar (API 33), SDL2/ (source).
Also both ROMs in roms/ and their generated data (build/us/gen, build/eu/gen),
exactly as for the PC package: the engines are built from them, then the
ROM's bytes are taken out again (port/tools/strip_rom.c), so the APK carries
no game data. The player's own copy fills it in on the phone.
"""
import argparse
import os
import shutil
import subprocess
import sys
import zipfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
HERE = ROOT / "port/android"
DEPS = ROOT / "port/deps/android"
B = ROOT / "build/android"
SYSROOT = os.environ.get("ANDROID_SYSROOT", str(DEPS / "sysroot"))
ANDROID_JAR = os.environ.get("ANDROID_JAR", str(DEPS / "android.jar"))  # resources (aapt)
JAVA_JAR = os.environ.get("ANDROID_JAVA_JAR", str(DEPS / "android-36.jar"))  # Java API (javac)
CC = ["clang", "--target=armv7a-linux-androideabi21", f"--sysroot={SYSROOT}", "-march=armv7-a", "-mfpu=vfpv3-d16",
      "-mfloat-abi=softfp", "-mthumb", "-O2", "-fPIC", "-Wall"]
REGIONS = {"usa": ("us", "roms/B8CE.gba"), "eur": ("eu", "roms/B8CP.gba")}
KEYSTORE = DEPS / "reino.keystore"
# The signing key stays private: its password comes from the environment
# (RDC_KEYSTORE_PASS), never from this file. Keep the same key for every
# release, or phones will refuse to update the app.
KEYPASS = os.environ.get("RDC_KEYSTORE_PASS", "")


def run(cmd, **kw):
    print("+", " ".join(str(c) for c in cmd))
    subprocess.check_call([str(c) for c in cmd], **kw)


def build_armv7(args, libdir, motor):
    """32-bit ARM phones: the game compiled for ARM directly (libgame_*.so,
    loaded at a fixed address by libmain.so)."""
    libdir.mkdir(parents=True)
    motor.mkdir(parents=True)
    sdl = B / "sdl"
    if not args.skip_native or not (sdl / "libSDL2.so").exists():
        run([sys.executable, "port/android/build_sdl.py", DEPS / "SDL2", sdl], env=dict(os.environ, ANDROID_ABI="armeabi-v7a"))
    shutil.copy(sdl / "libSDL2.so", libdir)
    run(CC + ["-shared", "-fuse-ld=lld", "-Wl,-z,defs", "-Wl,-soname,libmain.so", "-Wl,-z,max-page-size=16384",
              "-o", libdir / "libmain.so", "port/android/pc_android_main.c", "-ldl", "-llog"])
    for region, (ver, rom) in REGIONS.items():
        if not args.skip_native:
            run([sys.executable, "port/build.py", "--target", "android", "--app", "sdl", "--version", ver])
        bdir = Path("build/pc/android" + ("" if ver == "us" else "-eu"))
        full = B / f"libgame_{region}_full.so"
        run(["llvm-strip", "--strip-all", bdir / "libgame.so", "-o", full])
        run(["build/pc/tools/strip_rom", full, rom, region, libdir / f"libgame_{region}.so", motor / f"{region}.map"])
        full.unlink()


CC64 = ["clang", "--target=aarch64-linux-android21", f"--sysroot={SYSROOT}", "-O2", "-fPIC"]
FRONTEND = ["pc_main_sdl.c", "pc_config.c", "pc_audio_out.c", "pc_video.c", "pc_menu.c", "pc_touch.c",
            "pc_romdata.c"]


def build_arm64(args, libdir, motor):
    """64-bit phones (many cannot run 32-bit code at all): the game as a
    32-bit core (port/wasm/), its C compiled natively for arm64."""
    from concurrent.futures import ThreadPoolExecutor
    libdir.mkdir(parents=True)
    motor.mkdir(parents=True)
    sdl = B / "sdl-arm64"
    if not args.skip_native or not (sdl / "libSDL2.so").exists():
        run([sys.executable, "port/android/build_sdl.py", DEPS / "SDL2", sdl], env=dict(os.environ, ANDROID_ABI="arm64-v8a"))
    shutil.copy(sdl / "libSDL2.so", libdir)
    run(CC64 + ["-Wall", "-shared", "-fuse-ld=lld", "-Wl,-z,defs", "-Wl,-soname,libmain.so",
                "-Wl,-z,max-page-size=16384", "-o", libdir / "libmain.so", "port/android/pc_android_main.c", "-ldl",
                "-llog"])
    for region, (ver, rom) in REGIONS.items():
        core = B / f"core-{region}"
        objs = B / f"arm64-{region}"
        if not args.skip_native or not (core / "core.h").exists():
            run([sys.executable, "port/build.py", "--target", "wasm", "--app", "core", "--version", ver])
            wasm = Path("build/pc/wasm" + ("" if ver == "us" else "-eu")) / "khcom_core.wasm"
            run([sys.executable, "port/wasm/build_core.py", wasm, rom, region, core])
        shutil.copy(core / f"{region}.map", motor / f"{region}.map")
        if objs.exists():
            shutil.rmtree(objs)
        objs.mkdir(parents=True)
        cflags = CC64 + ["-w", "-DPC_SPLIT_CORE", "-Iport", "-Iport/include", f"-I{core}", "-Iport/wasm/rt",
                         f"-I{sdl}/include"]
        srcs = sorted(core.glob("core_*.c")) + [Path("port/wasm/rt/wasm-rt-impl.c"),
                                                Path("port/wasm/rt/wasm-rt-exceptions-impl.c"),
                                                Path("port/wasm/pc_core_host.c")] + [Path("port") / f for f in FRONTEND]

        def cc(src):
            obj = objs / (src.stem + ".o")
            subprocess.check_call([str(c) for c in cflags + ["-c", src, "-o", obj]])
            return obj

        with ThreadPoolExecutor(os.cpu_count()) as ex:
            built = list(ex.map(cc, srcs))
        run(CC64 + ["-shared", "-fuse-ld=lld", "-Wl,-z,defs", f"-Wl,-soname,libgame_{region}.so",
                    "-Wl,-z,max-page-size=16384", "-Wl,--gc-sections", "-o", libdir / f"libgame_{region}.so"] +
            built + [f"-L{sdl}", "-lSDL2", "-lm", "-ldl", "-llog", "-landroid"])
        run(["llvm-strip", "--strip-all", libdir / f"libgame_{region}.so"])


COMPILE_SDK = 36  # the Android version the app is built for (see patch_compile_sdk)


def patch_compile_sdk(apk, level):
    """Marks the binary manifest as compiled for `level`. The resource
    packager here only reads platforms up to API 33, but the Java code is
    built against `level` and targetSdkVersion matches it; Play Protect
    warns about apps that look built for an old Android, so the manifest's
    compileSdkVersion / platformBuildVersionCode (and their names) must say
    so too. Integers are patched in place; the version names ("13") are
    strings of the same length, also patched in place."""
    import struct
    names = {"compileSdkVersion", "platformBuildVersionCode", "compileSdkVersionCodename", "platformBuildVersionName"}
    newname = {33: "13", 34: "14", 35: "15", 36: "16", 37: "17"}[level]
    with zipfile.ZipFile(apk) as z:
        entries = [(i, z.read(i.filename)) for i in z.infolist()]
    out = []
    for info, data in entries:
        if info.filename == "AndroidManifest.xml":
            b = bytearray(data)
            # string pool: first chunk after the 8-byte XML header
            pos = 8
            ctype, hsize, csize = struct.unpack_from("<HHI", b, pos)
            assert ctype == 0x0001
            count, styles, flags, sstart, _ = struct.unpack_from("<IIIII", b, pos + 8)
            utf8 = flags & (1 << 8)
            offs = struct.unpack_from("<%dI" % count, b, pos + hsize)
            def string(i):
                o = pos + sstart + offs[i]
                if utf8:
                    n = b[o + 1] if b[o + 1] < 0x80 else None
                    o += 2
                    return b[o:o + n].decode(), o, 1
                n = struct.unpack_from("<H", b, o)[0]
                return b[o + 2:o + 2 + n * 2].decode("utf-16le"), o + 2, 2
            strs = [string(i) for i in range(count)]
            want = {i for i, (t, _, _) in enumerate(strs) if t in names}
            pos += csize
            patched = 0
            while pos < len(b):
                ctype, hsize, csize = struct.unpack_from("<HHI", b, pos)
                if ctype == 0x0102:  # start element
                    ns, nm, astart, asize, acount = struct.unpack_from("<IIHHH", b, pos + 16)
                    if strs[nm][0] == "manifest":
                        for k in range(acount):
                            a = pos + 16 + astart + k * asize
                            ans, aname, araw, vsize, vres, vtype, vdata = struct.unpack_from("<IIIHBBI", b, a)
                            if aname not in want:
                                continue
                            if vtype == 0x10:  # int
                                struct.pack_into("<I", b, a + 16, level)
                                patched += 1
                            elif vtype == 0x03:  # string
                                t, o, w = strs[vdata]
                                assert len(t) == len(newname), t
                                enc = newname.encode("utf-16le" if w == 2 else "utf-8")
                                b[o:o + len(enc)] = enc
                                patched += 1
                pos += csize
            print(f"manifest: compileSdk set to {level} ({patched} fields)")
            data = bytes(b)
        out.append((info, data))
    with zipfile.ZipFile(apk, "w") as z:
        for info, data in out:
            z.writestr(info, data)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default=str(ROOT / "dist"))
    ap.add_argument("--skip-native", action="store_true", help="reuse the native libraries already built")
    args = ap.parse_args()
    os.chdir(ROOT)
    stage = B / "stage"
    if stage.exists():
        shutil.rmtree(stage)
    assets = stage / "assets"

    # --- native code ---
    run(["gcc", "-O2", "-Iport", "-Iport/include", "-o", "build/pc/tools/strip_rom", "port/tools/strip_rom.c"])
    build_armv7(args, stage / "lib/armeabi-v7a", assets / "motor/armeabi-v7a")
    build_arm64(args, stage / "lib/arm64-v8a", assets / "motor/arm64-v8a")

    # --- assets: artwork, fonts ---
    shutil.copytree(HERE / "art", assets / "art")
    (assets / "fonts").mkdir()
    for f in ["Cinzel.ttf", "CinzelDecorative-Bold.ttf", "CormorantGaramond.ttf"]:
        shutil.copy(ROOT / "port/launcher/fonts" / f, assets / "fonts")
    shutil.copy(ROOT / "port/res/menu_atlas.png", assets)
    shutil.copy(ROOT / "port/res/touch_atlas.png", assets)

    # --- Java ---
    classes = B / "classes"
    if classes.exists():
        shutil.rmtree(classes)
    classes.mkdir(parents=True)
    srcs = sorted(str(p) for p in (HERE / "java").rglob("*.java"))
    run(["javac", "-nowarn", "-encoding", "UTF-8", "-source", "8", "-target", "8", "-bootclasspath", JAVA_JAR,
         "-d", classes] + srcs)
    run(["dalvik-exchange", "--dex", "--min-sdk-version=21", f"--output={stage / 'classes.dex'}", classes])

    # --- package, align, sign ---
    unsigned = B / "unsigned.apk"
    run(["aapt", "package", "-f", "-M", HERE / "AndroidManifest.xml", "-S", HERE / "res", "-A", assets,
         "-I", ANDROID_JAR, "-F", unsigned])
    patch_compile_sdk(unsigned, COMPILE_SDK)
    with zipfile.ZipFile(unsigned, "a") as z:
        z.write(stage / "classes.dex", "classes.dex")
        for so in sorted((stage / "lib").rglob("*.so")):
            z.write(so, str(so.relative_to(stage)), compress_type=zipfile.ZIP_DEFLATED)
    aligned = B / "aligned.apk"
    run(["zipalign", "-f", "-p", "4", unsigned, aligned])
    if not KEYPASS:
        sys.exit("set RDC_KEYSTORE_PASS to the signing key's password (see port/android/README.md)")
    if not KEYSTORE.exists():
        run(["keytool", "-genkeypair", "-keystore", KEYSTORE, "-storepass", KEYPASS, "-keypass", KEYPASS,
             "-alias", "reino", "-keyalg", "RSA", "-keysize", "2048", "-validity", "10000",
             "-dname", "CN=Reino de Corazones, O=Proyecto no oficial"])
    out = Path(args.out)
    out.mkdir(parents=True, exist_ok=True)
    apk = out / "ReinoDeCorazones.apk"
    run(["apksigner", "sign", "--ks", KEYSTORE, "--ks-pass", f"pass:{KEYPASS}", "--ks-key-alias", "reino",
         "--min-sdk-version", "21", "--out", apk, aligned])
    run(["apksigner", "verify", "--min-sdk-version", "21", apk])
    print(f"{apk}  ({apk.stat().st_size / 1e6:.1f} MB)")


if __name__ == "__main__":
    main()
