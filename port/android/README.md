# Reino de Corazones for Android (arm64-v8a + armeabi-v7a)

The same game code as the PC port, wrapped in a small Java app. One APK works
on Mali, Adreno (Snapdragon), PowerVR and any GPU with OpenGL ES 2.0,
Android 5.0 (API 21) and later.

- **armeabi-v7a**: the game compiled for 32-bit ARM (`--target android`).
- **arm64-v8a** (and 64-bit-only phones): the decompiled code assumes 32-bit
  pointers, also inside its data tables, so it is compiled as a 32-bit *core*
  (`--target wasm --app core`, wasm32 memory model) and `port/wasm/build_core.py`
  turns that into C with wasm2c, which is compiled natively for arm64 together
  with the frontend (`-DPC_SPLIT_CORE`, `port/wasm/pc_core_host.c`). No
  interpreter is involved. The core's whole data image is rebuilt from the
  player's ROM (map: `assets/motor/arm64-v8a/*.map`); quick-save states are
  address-independent there.
  `port/wasm/core_headless.c` runs it like `khcom_headless`: on x86-64 and on
  aarch64 (qemu) it gives the same frames as the native build.

## Pieces

| File | What it is |
|------|------------|
| `lib/<abi>/libSDL2.so` | SDL 2.32 (`build_sdl.py`): window, GLES2 renderer, audio via AudioTrack, input |
| `libmain.so` (`pc_android_main.c`) | SDL_main: loads the game at a fixed address so quick-save states survive restarts |
| `libgame_usa.so`, `libgame_eur.so` | the game (`port/build.py --target android --app sdl`), ROM data stripped |
| `assets/motor/*.map` | where each byte of the stripped data sits in the ROM (`port/tools/strip_rom.c`) |
| `java/com/reinodecorazones` | `LauncherActivity` (asks for the ROM, SHA-1 check), `GameActivity` (SDLActivity, process `:game`) |
| `java/org/libsdl/app` | SDL's Java side, without lambdas (old `dx`) and without HIDAPI |

On-screen controls: `port/pc_touch.c`, artwork `port/launcher/make_touch_assets.py`.
Test the phone layout on a PC: `python3 port/build.py --target win32 --app sdl --touch-test`
(the mouse acts as a finger).

## Toolchain (no Android SDK/NDK download needed)

`port/deps/android/` holds:

- `sysroot/` — bionic headers (AOSP `bionic/libc/include`, kernel uapi), NDK
  headers (frameworks/native `include/android`, `liblog`, Khronos EGL/GLES,
  JDK `jni.h`), stub libraries for API 21 generated from bionic's `*.map.txt`
  (`libc libm libdl liblog libandroid libEGL libGLESv2`), `crtbegin_so.o`/
  `crtend_so.o`, and compiler-rt builtins (+ `emutls`) as `libgcc.a`.
- `android.jar` (API 33), `SDL2/` (SDL 2.32.8 source).

Tools: clang/lld 18, llvm-objcopy/strip/ar, JDK, `dalvik-exchange` (dx),
`aapt`, `zipalign`, `apksigner` (Ubuntu packages). Then:

    RDC_KEYSTORE_PASS=<your password> python3 port/android/build_apk.py --out dist

The signing key is `port/deps/android/reino.keystore` (created on the first
build if missing). It is private: never commit it. Keep it, since updates must be
signed with the same key.

## Verified without a phone

- `--target linuxarm` (qemu-arm): same frames and sound as x86 for 30000 frames.
- `--target linuxarmso` + `port/tools/so_runner.c`: the stripped, position-
  independent library rebuilt from the ROM and relocated matches x86 too.
