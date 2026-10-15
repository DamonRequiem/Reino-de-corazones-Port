#!/usr/bin/env python3
"""Builds SDL2 as a static library for Android armeabi-v7a (libSDL2.a).

    python3 port/android/build_sdl.py SDL2-2.x.y/ OUT_DIR

Uses the same clang + sysroot as the game (ANDROID_SYSROOT). SDL's Android
backend talks to the Java side (SDLActivity) for audio (AudioTrack), input and
the window; OpenSL ES, AAudio, HIDAPI and Vulkan are left out, so the game only
needs the system libraries every Android 5.0+ phone has.
"""
import os, re, shutil, subprocess, sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SYSROOT = os.environ.get("ANDROID_SYSROOT", str(ROOT / "port/deps/android/sysroot"))
ABI_FLAGS = {
    "armeabi-v7a": ["--target=armv7a-linux-androideabi21", "-march=armv7-a", "-mfpu=vfpv3-d16",
                    "-mfloat-abi=softfp", "-mthumb"],
    "arm64-v8a": ["--target=aarch64-linux-android21"],
}
ABI = os.environ.get("ANDROID_ABI", "armeabi-v7a")
CC = ["clang"] + ABI_FLAGS[ABI] + [f"--sysroot={SYSROOT}", "-O2", "-fPIC", "-ffunction-sections",
                                   "-fdata-sections", "-DGL_GLEXT_PROTOTYPES", "-w"]
NCC = len(ABI_FLAGS[ABI]) + 2  # compiler, target flags, sysroot

DIRS = ["", "audio", "audio/android", "audio/dummy", "atomic", "core/android", "cpuinfo", "dynapi", "events", "file",
        "haptic", "haptic/android", "joystick", "joystick/android", "joystick/virtual", "loadso/dlopen", "locale",
        "locale/android", "misc", "misc/android", "power", "power/android", "filesystem/android", "sensor",
        "sensor/android", "render", "render/opengles2", "render/software", "stdlib", "thread",
        "thread/pthread", "timer", "timer/unix", "video", "video/android", "video/yuv2rgb", "libm"]


def patch_config(src_inc, out_inc):
    shutil.copytree(src_inc, out_inc, dirs_exist_ok=True)
    p = out_inc / "SDL_config_android.h"
    s = p.read_text()
    for d in ["SDL_AUDIO_DRIVER_OPENSLES", "SDL_AUDIO_DRIVER_AAUDIO", "SDL_JOYSTICK_HIDAPI", "SDL_VIDEO_RENDER_OGL_ES"]:
        s = re.sub(rf"#define {d}\s+1\b", f"/* {d}: not used by Reino de Corazones */", s)
    s = re.sub(r"#if defined\(__ARM_ARCH\) && __ARM_ARCH < 7\n#define SDL_VIDEO_VULKAN 0\n#else\n#define SDL_VIDEO_VULKAN 1\n#endif",
               "#define SDL_VIDEO_VULKAN 0", s)
    s = s.replace("#endif /* SDL_config_android_h_ */",
                  "#define SDL_HIDAPI_DISABLED 1\n#define HAVE_GETAUXVAL 1\n#endif /* SDL_config_android_h_ */")
    p.write_text(s)


def main():
    sdl, out = Path(sys.argv[1]).resolve(), Path(sys.argv[2]).resolve()
    inc = out / "include"
    patch_config(sdl / "include", inc)
    srcs = []
    for d in DIRS:
        srcs += sorted((sdl / "src" / d).glob("*.c"))
    objdir = out / "obj"
    objdir.mkdir(parents=True, exist_ok=True)

    def build(src):
        rel = src.relative_to(sdl / "src")
        obj = objdir / (str(rel).replace("/", "_")[:-2] + ".o")
        if obj.exists() and obj.stat().st_mtime > src.stat().st_mtime:
            return obj, None
        r = subprocess.run(CC + [f"-I{inc}", f"-I{sdl}/src", "-c", str(src), "-o", str(obj)], capture_output=True,
                           text=True)
        return obj, (r.stderr if r.returncode else None)

    with ThreadPoolExecutor(os.cpu_count()) as ex:
        results = list(ex.map(build, srcs))
    errs = [e for _, e in results if e]
    for e in errs:
        print(e)
    if errs:
        sys.exit(f"{len(errs)} SDL files failed")
    lib = out / "libSDL2.a"
    if lib.exists():
        lib.unlink()
    subprocess.check_call(["llvm-ar", "rcs", str(lib)] + [str(o) for o, _ in results])
    # The shared library the app loads first (its JNI functions talk to SDLActivity).
    so = out / "libSDL2.so"
    subprocess.check_call(CC[:NCC] + ["-shared", "-fuse-ld=lld", "-Wl,-z,defs", "-Wl,-soname,libSDL2.so",
                                    "-Wl,--gc-sections", "-Wl,-z,max-page-size=16384", "-o", str(so),
                                    "-Wl,--whole-archive", str(lib), "-Wl,--no-whole-archive",
                                    "-ldl", "-llog", "-landroid", "-lGLESv2", "-lEGL", "-lm"])
    print(f"{so} ({len(results)} files)")


if __name__ == "__main__":
    main()
