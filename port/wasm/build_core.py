#!/usr/bin/env python3
"""Turns the 32-bit core (build/pc/wasm[-eu]/khcom_core.wasm) into C for a
64-bit native build, without any of the game's data.

    python3 port/wasm/build_core.py CORE.wasm ROM REGION OUT_DIR

Steps:
 1. The core's initialised memory (every data segment: graphics, music,
    text, the game's tables, the port's own constants) is taken out of the
    module into one image, and the module keeps none of it.
 2. port/tools/strip_rom maps that image onto the ROM: OUT_DIR/<region>.map
    records where each byte comes from (or holds the few bytes that are not
    in the ROM). On the phone the player's ROM rebuilds the image.
 3. wasm2c turns the module into C (OUT_DIR/core*.c, core.h, core-impl.h).
 4. The generated C gets the GBA's behaviour where WebAssembly would stop:
      - division by zero gives 0 (like the GBA's libgcc), INT_MIN / -1 gives
        INT_MIN;
      - an access through a garbage pointer at the top of the 32-bit space
        (the BIOS latch 0xE3A02004 read through NULL) lands on the BIOS page
        at address 0, as the PC build's fault handler does;
      - calls through function pointers do not check the function's type
        (the decompiled code mixes prototypes, harmless on the GBA and PC).
"""
import os
import re
import shutil
import struct
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def leb_u(data, i):
    v = shift = 0
    while True:
        b = data[i]
        i += 1
        v |= (b & 0x7F) << shift
        shift += 7
        if not b & 0x80:
            return v, i


def leb_s(data, i):
    v = shift = 0
    while True:
        b = data[i]
        i += 1
        v |= (b & 0x7F) << shift
        shift += 7
        if not b & 0x80:
            if b & 0x40:
                v -= 1 << shift
            return v, i


def enc_u(v):
    out = bytearray()
    while True:
        b = v & 0x7F
        v >>= 7
        if v:
            out.append(b | 0x80)
        else:
            out.append(b)
            return bytes(out)


def strip_data(wasm):
    """Returns (module without data, start address, image bytes)."""
    assert wasm[:8] == b"\0asm\x01\0\0\0"
    out = bytearray(wasm[:8])
    i = 8
    segs = []
    while i < len(wasm):
        sid = wasm[i]
        size, j = leb_u(wasm, i + 1)
        body = wasm[j:j + size]
        if sid == 11:  # data
            n, k = leb_u(body, 0)
            for _ in range(n):
                flags, k = leb_u(body, k)
                if flags != 0:
                    sys.exit("build_core: only active data segments in memory 0 are supported")
                if body[k] != 0x41:  # i32.const
                    sys.exit("build_core: data segment offset is not a constant")
                off, k = leb_s(body, k + 1)
                assert body[k] == 0x0B
                k += 1
                ln, k = leb_u(body, k)
                segs.append((off, body[k:k + ln]))
                k += ln
            body = enc_u(0)
        elif sid == 12:  # data count
            body = enc_u(0)
        elif sid == 0:  # custom: keep function names only (debug info and segment names go)
            nlen, k = leb_u(body, 0)
            if body[k:k + nlen] != b"name":
                i = j + size
                continue
            k += nlen
            kept = bytearray(body[:k])
            while k < len(body):
                sub = body[k]
                sl, m = leb_u(body, k + 1)
                if sub in (0, 1):  # module name, function names
                    kept += body[k:m + sl]
                k = m + sl
            body = bytes(kept)
        out += bytes([sid]) + enc_u(len(body)) + body
        i = j + size
    lo = min(o for o, _ in segs)
    hi = max(o + len(b) for o, b in segs)
    image = bytearray(hi - lo)
    for o, b in segs:
        image[o - lo:o - lo + len(b)] = b
    return bytes(out), lo, bytes(image)


PATCHES = [
    # Calls through function pointers: no type check.
    ("""#define CHECK_CALL_INDIRECT(table, ft, x)                \\
  (LIKELY((x) < table.size && table.data[x].func &&      \\
          func_types_eq(ft, table.data[x].func_type)) || \\
   TRAP(CALL_INDIRECT))""",
     """#define CHECK_CALL_INDIRECT(table, ft, x)           \\
  (LIKELY((x) < table.size && table.data[x].func) || \\
   TRAP(CALL_INDIRECT)) /* Reino de Corazones: no type check */"""),
    # Division: the GBA's results instead of traps.
    ("""#define DIV_S(ut, min, x, y)                                      \\
  ((UNLIKELY((y) == 0))                                           \\
       ? TRAP(DIV_BY_ZERO)                                        \\
       : (UNLIKELY((x) == min && (y) == -1)) ? TRAP(INT_OVERFLOW) \\
                                             : (ut)((x) / (y)))""",
     """#define DIV_S(ut, min, x, y)                             \\
  ((UNLIKELY((y) == 0))                                  \\
       ? (ut)0                                           \\
       : (UNLIKELY((x) == min && (y) == -1)) ? (ut)(x)   \\
                                             : (ut)((x) / (y)))"""),
    ("""#define REM_S(ut, min, x, y) \\
  ((UNLIKELY((y) == 0))      \\
       ? TRAP(DIV_BY_ZERO)   \\""",
     """#define REM_S(ut, min, x, y) \\
  ((UNLIKELY((y) == 0))      \\
       ? (ut)0               \\"""),
    ("""#define DIVREM_U(op, x, y) \\
  ((UNLIKELY((y) == 0)) ? TRAP(DIV_BY_ZERO) : ((x)op(y)))""",
     """#define DIVREM_U(op, x, y) \\
  ((UNLIKELY((y) == 0)) ? 0 : ((x)op(y)))"""),
    # Garbage pointers at the top of the address space -> the BIOS page.
    ("""#define DEFINE_LOAD(name, t1, t2, t3, force_read)          \\
  static inline t3 name(wasm_rt_memory_t* mem, u64 addr) { \\
    MEMCHECK(mem, addr, t1);                               \\""",
     """#define RDC_FIX_ADDR(addr) \\
  if (UNLIKELY((addr) >= 0xE0000000u)) (addr) &= 0xFFF;
#define DEFINE_LOAD(name, t1, t2, t3, force_read)          \\
  static inline t3 name(wasm_rt_memory_t* mem, u64 addr) { \\
    RDC_FIX_ADDR(addr)                                     \\
    MEMCHECK(mem, addr, t1);                               \\"""),
    ("""#define DEFINE_STORE(name, t1, t2)                                     \\
  static inline void name(wasm_rt_memory_t* mem, u64 addr, t2 value) { \\
    MEMCHECK(mem, addr, t1);                                           \\
    t1 wrapped = (t1)value;                                            \\
    wasm_rt_memcpy(&mem->data[addr], &wrapped, sizeof(t1));            \\""",
     """#define DEFINE_STORE(name, t1, t2)                                     \\
  static inline void name(wasm_rt_memory_t* mem, u64 addr, t2 value) { \\
    RDC_FIX_ADDR(addr)                                                 \\
    MEMCHECK(mem, addr, t1);                                           \\
    t1 wrapped = (t1)value;                                            \\
    wasm_rt_memcpy(&mem->data[addr], &wrapped, sizeof(t1));            \\"""),
]


def main():
    if len(sys.argv) != 5:
        sys.exit(__doc__)
    core, rom, region, out = Path(sys.argv[1]), sys.argv[2], sys.argv[3], Path(sys.argv[4])
    if out.exists():
        shutil.rmtree(out)
    out.mkdir(parents=True)
    module, lo, image = strip_data(core.read_bytes())
    (out / "core_nodata.wasm").write_bytes(module)
    # strip_rom's raw mode: the file is the image, at address `lo` in the core.
    raw = out / "image.bin"
    raw.write_bytes(image)
    tool = ROOT / "build/pc/tools/strip_rom"
    subprocess.check_call(["gcc", "-O2", f"-I{ROOT}/port", f"-I{ROOT}/port/include", "-o", tool,
                           ROOT / "port/tools/strip_rom.c"])
    subprocess.check_call([tool, raw, rom, region, out / "image.stripped", out / f"{region}.map"])
    raw.unlink()
    (out / "image.stripped").unlink()
    print(f"core data: {len(image)} bytes at 0x{lo:X}")

    subprocess.check_call(["wasm2c", "-n", "core", "--num-outputs", "8", out / "core_nodata.wasm",
                           "-o", out / "core.c"])
    impl = out / "core-impl.h"
    text = impl.read_text()
    for old, new in PATCHES:
        if old not in text:
            sys.exit(f"build_core: wasm2c output changed, patch not applied:\n{old[:120]}")
        text = text.replace(old, new)
    impl.write_text(text)
    (out / "core_nodata.wasm").unlink()
    print(f"core C in {out}")


if __name__ == "__main__":
    main()
