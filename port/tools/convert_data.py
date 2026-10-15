#!/usr/bin/env python3
"""Convert the decomp's generated ARM data assembly into host (x86) assembly.

The game data (graphics, maps, songs, text tables) is emitted by tools/assetgen.py
as ARM GNU assembler source that only uses data directives. Most of those
directives mean the same thing on x86, but a few do not:

  ARM GAS            x86 GAS
  .word  (32-bit)    .word  (16-bit)   -> rewritten to .4byte
  .hword (16-bit)    target dependent  -> rewritten to .2byte
  .align N (2^N)     .align N (bytes)  -> rewritten to .p2align N
  .type x, %object   ELF only          -> dropped (COFF/PE has no equivalent)
  .size              ELF only          -> dropped

`.include` directives are expanded inline so the rewrite also applies to the
included song/voicegroup files; macro-only include files are expanded once.

Usage: convert_data.py <input.s> <output.s> <format: elf|coff|wasm> [include dirs...]

wasm (the 64-bit phone build's 32-bit core, see port/wasm/): data symbols
also need a size, so every label gets .type/.size up to the next label.
"""
import re
import sys
from pathlib import Path

INCLUDE_RE = re.compile(r'^\s*\.include\s+"([^"]+)"\s*$')
ALIGN_RE = re.compile(r'^(\s*)\.align(\s+)(.*)$')
DIRECTIVE_SUBS = [
    (re.compile(r'^(\s*)\.word\b'), r'\1.4byte'),
    (re.compile(r'^(\s*)\.hword\b'), r'\1.2byte'),
    (re.compile(r'^(\s*)\.short\b'), r'\1.2byte'),
    (re.compile(r'^(\s*)\.long\b'), r'\1.4byte'),
]
DROP_RE = re.compile(r'^\s*\.(type|size|syntax|thumb|arm|code|thumb_func|end)\b')
SECTION_RE = re.compile(r'^\s*\.section\s+(\.[A-Za-z0-9_.]+)')


def section_line(name, fmt):
    # Everything extracted from the ROM goes into one section, "romdat". The
    # shipped executable carries it empty; at start-up port/pc_romdata.c fills
    # it from the player's own ROM (see port/tools/strip_rom.py). It is
    # writable so it can be filled in place (the GBA could not write it).
    if fmt == "wasm":
        return '\t.section .bss.data_unit,"",@' if name.startswith(".bss") else '\t.section romdat,"",@'
    if not name.startswith(".bss"):
        if fmt == "coff":
            return '\t.section .romdat,"dw"'
        return '\t.section romdat,"aw",%progbits'
    if fmt == "coff":
        if name.startswith(".rodata"):
            return '\t.section .rdata,"dr"'
        if name.startswith(".data"):
            return '\t.section .data,"dw"'
        if name.startswith(".bss"):
            return '\t.section .bss,"bw"'
        return f'\t.section {name},"dr"'
    if name.startswith(".rodata"):
        return '\t.section .rodata,"a"'
    if name.startswith(".data"):
        return '\t.section .data,"aw"'
    return f'\t.section {name}'


def resolve(path, base, include_dirs):
    for d in [base] + include_dirs:
        p = Path(d) / path
        if p.is_file():
            return p
    p = Path(path)
    if p.is_file():
        return p
    sys.exit(f"convert_data: cannot find include {path!r} (from {base})")


def convert(path, fmt, include_dirs, out, seen_macro_files):
    base = path.parent
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        m = INCLUDE_RE.match(line)
        if m:
            inc = resolve(m.group(1), base, include_dirs)
            text = inc.read_text(encoding="utf-8", errors="replace")
            if ".macro" in text:
                key = inc.resolve()
                if key in seen_macro_files:
                    continue
                seen_macro_files.add(key)
            convert(inc, fmt, include_dirs, out, seen_macro_files)
            continue
        if DROP_RE.match(line):
            continue
        m = SECTION_RE.match(line)
        if m:
            out.append(section_line(m.group(1), fmt))
            continue
        m = ALIGN_RE.match(line)
        if m:
            arg = m.group(3).split(",")[0].strip()
            out.append(f"{m.group(1)}.p2align {arg}")
            continue
        for rx, repl in DIRECTIVE_SUBS:
            line = rx.sub(repl, line)
        out.append(line)


LABEL_RE = re.compile(r'^([A-Za-z_][A-Za-z0-9_.$]*):\s*$')


EQU_RE = re.compile(r'^\s*\.(?:equ|set)\s+([A-Za-z_][A-Za-z0-9_]*)\s*,\s*(.*?)\s*$')
WORD_RE = re.compile(r'(?<![\\.\w])([A-Za-z_][A-Za-z0-9_]*)\b')
KEYSPLIT_RE = re.compile(r'^\s*keysplit\s+([A-Za-z_]\w*)\s*,\s*(\S+)\s*$')
SPLIT_RE = re.compile(r'^\s*split\s+([^,]+),\s*(\S+)\s*$')


def wasm_local_constants(lines):
    """WebAssembly objects cannot hold absolute symbols, and the assembler
    keeps a symbol (not a number) for a constant that is redefined. So the
    constants (.equ/.set NAME, value) are worked out here and written as
    plain numbers, and the m4a keysplit tables (whose symbols sit before the
    table by its first note) are laid out here too."""
    values = {}
    keysplits = {}
    for ln in lines:
        m = KEYSPLIT_RE.match(ln)
        if m:
            keysplits[m.group(1)] = int(m.group(2), 0)

    def subst(text):
        return WORD_RE.sub(lambda m: str(values[m.group(1)]) if m.group(1) in values else
                           (f"({m.group(1)}__ks-{keysplits[m.group(1)]})" if m.group(1) in keysplits
                            else m.group(1)), text)

    out, cur = [], 0
    for ln in lines:
        m = EQU_RE.match(ln)
        if m:
            expr = subst(m.group(2))
            try:
                values[m.group(1)] = int(eval(expr, {"__builtins__": {}}))
            except Exception:
                values[m.group(1)] = f"({expr})"
            continue
        m = KEYSPLIT_RE.match(ln)
        if m:
            out.append(f"{m.group(1)}__ks:")
            cur = int(m.group(2), 0)
            continue
        m = SPLIT_RE.match(ln)
        if m:
            end = int(m.group(2), 0)
            out.append(f"\t.fill {end - cur}, 1, {subst(m.group(1).strip())}")
            cur = end
            continue
        if re.match(r'^\s*\.glob(a)?l\s+(\w+)', ln) and re.match(r'^\s*\.glob(a)?l\s+(\w+)', ln).group(2) in keysplits:
            continue
        out.append(subst(ln) if not ln.lstrip().startswith(".macro") else ln)
    return out


def wasm_functypes(lines):
    """Data that holds a C function's address must declare the function's
    WebAssembly signature (port/wasm/data_functions.txt)."""
    table = {}
    for ln in (Path(__file__).resolve().parents[1] / "wasm/data_functions.txt").read_text().splitlines():
        if ln.strip() and not ln.startswith("#"):
            name, sig = ln.split(None, 1)
            table[name] = sig
    used = set()
    for ln in lines:
        if ".4byte" in ln:
            used.update(w for w in WORD_RE.findall(ln) if w in table)
    return [f"\t.functype {n} {table[n]}" for n in sorted(used)] + lines


def wasm_sizes(lines):
    """Gives every data label a .type and a .size reaching the next label."""
    out, open_label, n = [], None, 0

    def close():
        nonlocal open_label, n
        if open_label:
            out.append(f".Lsz{n}:")
            out.append(f"\t.size {open_label}, .Lsz{n}-{open_label}")
            n += 1
            open_label = None

    for line in lines:
        m = LABEL_RE.match(line)
        if m or line.lstrip().startswith(".section"):
            close()
        if m:
            out.append(f"\t.type {m.group(1)},@object")
            open_label = m.group(1)
        out.append(line)
    close()
    return out


def main():
    if len(sys.argv) < 4:
        sys.exit(__doc__)
    src, dst, fmt = Path(sys.argv[1]), Path(sys.argv[2]), sys.argv[3]
    include_dirs = sys.argv[4:]
    out = []
    convert(src, fmt, include_dirs, out, set())
    if fmt == "elf":
        out.append('\t.section .note.GNU-stack,"",%progbits')
    if fmt == "wasm":
        out = wasm_functypes(wasm_sizes(wasm_local_constants(out)))
    dst.parent.mkdir(parents=True, exist_ok=True)
    dst.write_text("\n".join(out) + "\n")


if __name__ == "__main__":
    main()
