#!/usr/bin/env python3
import argparse
import os
import sys
import unicodedata
from pathlib import Path

import yaml

YAML_LOADER = getattr(yaml, "CSafeLoader", yaml.SafeLoader)

ROOT = Path(__file__).resolve().parent.parent
POOL_DIR = ROOT / "config" / "text"
CHARMAP_DIR = ROOT / "config" / "charmaps"
VERSIONS = ("us", "jp", "eu")
ROM_BASE = 0x08000000
FIELD_WIDTHS = {"u8": 1, "u16": 2, "u32": 4, "ptr": 4}
DIRECTIVES = {1: ".byte", 2: ".hword", 4: ".4byte"}
SHOWN_SPACES = (" ", "\u3000")
HIDDEN_CATEGORIES = ("Cc", "Cf", "Cs", "Co", "Cn", "Zl", "Zp", "Zs")
BYTES_PER_LINE = 32


class TextError(Exception):
    pass


def load_yaml(path):
    with open(path, encoding="utf-8") as handle:
        return yaml.load(handle, Loader=YAML_LOADER)


def shown(char):
    if char in "{}":
        return False
    return char in SHOWN_SPACES or unicodedata.category(char) not in HIDDEN_CATEGORIES


def aligned(position, align):
    return (position + align - 1) // align * align


class Encoding:
    def __init__(self, name, doc):
        self.name = name
        self.width = doc["width"]
        self.codec = doc.get("codec")
        self.controls = {tag: self.pack(units) for tag, units in doc["controls"].items()}
        if "END" not in self.controls:
            raise TextError(f"{name}: an encoding needs an END control")
        self.sequences = sorted(self.controls.items(), key=lambda item: -len(item[1]))
        self.chars = {}
        self.codes = {}
        for unit, char in (doc.get("chars") or {}).items():
            if not isinstance(char, str) or len(char) != 1 or char in self.codes or not shown(char) or char == "\n":
                raise TextError(f"{name}: {unit:#x} maps to {char!r}, which is not one unique visible character")
            self.chars[unit] = char
            self.codes[char] = self.pack([unit])

    def pack(self, units):
        return b"".join(unit.to_bytes(self.width, "little") for unit in units)

    def escape(self, unit):
        return "{0x%0*X}" % (2 * self.width, unit)

    def codec_char(self, data):
        if not self.codec:
            return None
        try:
            char = data.decode(self.codec)
            if len(char) != 1 or char in self.codes or not shown(char) or char.encode(self.codec) != data:
                return None
        except UnicodeError:
            return None
        return char

    def decode(self, data):
        out = []
        position = 0
        while position < len(data):
            for tag, sequence in self.sequences:
                if data.startswith(sequence, position):
                    out.append("\n" if tag == "NL" else "{%s}" % tag)
                    position += len(sequence)
                    break
            else:
                position = self.decode_char(data, position, out)
        return "".join(out)

    def decode_char(self, data, position, out):
        unit = int.from_bytes(data[position:position + self.width], "little")
        if unit in self.chars:
            out.append(self.chars[unit])
            return position + self.width
        if self.width == 2:
            char = self.codec_char(bytes([unit])) if unit < 0x100 else None
            if char is not None:
                out.append(char)
                return position + 2
        else:
            for size in (2, 1):
                char = self.codec_char(data[position:position + size]) if position + size <= len(data) else None
                if char is not None:
                    out.append(char)
                    return position + size
        out.append(self.escape(unit))
        return position + self.width

    def encode(self, text, where):
        out = bytearray()
        position = 0
        while position < len(text):
            char = text[position]
            if char == "{":
                close = text.find("}", position)
                if close < 0:
                    raise TextError(f"{where}: unclosed {{")
                out += self.tag(text[position + 1:close], where)
                position = close + 1
                continue
            if char == "}":
                raise TextError(f"{where}: }} without {{")
            if char == "\n":
                out += self.tag("NL", where)
            else:
                out += self.char(char, where)
            position += 1
        return bytes(out)

    def tag(self, tag, where):
        if tag in self.controls:
            return self.controls[tag]
        if tag.startswith("0x") and len(tag) == 2 + 2 * self.width:
            try:
                return int(tag, 16).to_bytes(self.width, "little")
            except ValueError:
                pass
        raise TextError(f"{where}: {{{tag}}} is not a control or a {self.width}-byte escape of {self.name}")

    def char(self, char, where):
        if char in self.codes:
            return self.codes[char]
        try:
            data = char.encode(self.codec) if self.codec else b""
        except UnicodeError:
            data = b""
        if data and self.width == 1:
            return data
        if len(data) == 1 and self.width == 2:
            return data + b"\0"
        raise TextError(f"{where}: {char!r} (U+{ord(char):04X}) has no code in {self.name}")

    def terminated(self, data, start):
        end = self.controls["END"]
        position = start
        while position + len(end) <= len(data):
            if data.startswith(end, position):
                return position + len(end)
            position += self.width
        return None


def load_charmap(version):
    path = CHARMAP_DIR / f"{version}.yaml"
    return {name: Encoding(f"{version}/{name}", doc) for name, doc in load_yaml(path).items()}


class Unit:
    def __init__(self, pool, version, kind, spec, entries):
        self.pool = pool
        self.version = version
        self.kind = kind
        self.spec = spec
        self.entries = entries
        self.form = spec.get("form", "array")
        required = ("name", "start", "end", "encoding") + (("stride", "size") if self.form == "macro" else ("align", "ctype"))
        for key in required:
            if key not in spec:
                raise TextError(f"{pool.name}: {version} {kind} {spec.get('name')} has no {key}")
        self.name = spec["name"]
        self.start = spec["start"]
        self.end = spec["end"]
        self.align = spec.get("align", 1)
        self.ctype = spec.get("ctype")
        self.header = spec.get("header")
        self.count = spec.get("count")
        self.stride = spec.get("stride")
        self.size = spec.get("size")
        if self.form not in ("array", "string", "macro") or self.count not in (None, "exact", "slot"):
            raise TextError(f"{pool.name}: {version} {self.name} has an unknown form or count")
        if self.form != "macro" and (self.stride is not None or self.size is not None):
            raise TextError(f"{pool.name}: {version} {self.name} only takes a stride and size when it writes macros")

    def encoding(self, charmap):
        name = self.spec["encoding"]
        if name not in charmap:
            raise TextError(f"{self.pool.name}: config/charmaps/{self.version}.yaml has no encoding {name}")
        return charmap[name]

    def entry_align(self, entry):
        if "record" in entry:
            return self.pool.fields(entry["record"])[2]
        return entry.get("align", self.align)

    def layout(self, data_of):
        if self.stride is not None:
            placed = []
            for index, entry in enumerate(self.entries):
                start = self.start + index * self.stride
                if len(data_of(entry, start)) > self.size:
                    raise TextError(f"{self.pool.name}: {entry['name']} is longer than its {self.size}-byte field")
                placed.append((entry, start, self.size))
            return placed, (placed[-1][1] + self.size if placed else self.start)
        position = self.start
        placed = []
        for entry in self.entries:
            start = aligned(position, self.entry_align(entry))
            size = self.pool.fields(entry["record"])[1] if "record" in entry else len(data_of(entry, start))
            placed.append((entry, start, size))
            position = start + size
        return placed, position


class Pool:
    def __init__(self, path):
        self.path = Path(path)
        doc = load_yaml(self.path)
        if "pool" not in doc:
            raise TextError(f"{self.path}: missing pool")
        self.name = doc["pool"]
        if self.name != self.path.stem:
            raise TextError(f"{self.path}: pool {self.name} must be named after its file")
        self.objects = doc.get("objects", {})
        self.types = doc.get("types", {})
        self.listed = doc.get("entries", [])
        self.formats = doc.get("formats", {})
        self.fragment_specs = doc.get("fragments", {})
        self.alias_specs = doc.get("aliases", {})
        for version in list(self.objects) + list(self.fragment_specs) + list(self.alias_specs):
            if version not in VERSIONS:
                raise TextError(f"{self.name}: unknown version {version}")

    def object(self, version):
        return self.objects.get(version)

    def parse_entries(self, items):
        return [{"name": item} if isinstance(item, str) else item for item in items]

    def object_entries(self, version):
        if isinstance(self.listed, dict):
            items = self.listed.get(version, [])
        else:
            items = [item for item in self.listed if isinstance(item, str) or version in item.get("versions", VERSIONS)]
        return self.parse_entries(items)

    def fragments(self, version):
        out = []
        for spec in self.fragment_specs.get(version, []):
            merged = dict(self.formats.get(spec.get("format"), {})) if "format" in spec else {}
            merged.update({key: value for key, value in spec.items() if key not in ("format", "entries")})
            out.append(Unit(self, version, "fragment", merged, self.parse_entries(spec.get("entries", []))))
        return out

    def units(self, version):
        units = []
        if self.object(version) is not None:
            units.append(Unit(self, version, "object", self.object(version), self.object_entries(version)))
        units += self.fragments(version)
        names = set()
        for unit in units:
            for entry in unit.entries:
                if not entry["name"].isascii() or not entry["name"].isidentifier():
                    raise TextError(f"{self.name}: {entry['name']!r} is not a symbol name")
                if entry["name"] in names:
                    raise TextError(f"{self.name}: {version} lists {entry['name']} twice")
                names.add(entry["name"])
        return units

    def entries(self, version):
        return [entry for unit in self.units(version) for entry in unit.entries]

    def aliases(self, version):
        aliases = self.alias_specs.get(version) or {}
        if not isinstance(aliases, dict):
            raise TextError(f"{self.name}: {version} aliases must map each alias to an entry")
        names = {entry["name"] for entry in self.entries(version)} if aliases else set()
        for alias, target in aliases.items():
            if not isinstance(alias, str) or not alias.isascii() or not alias.isidentifier():
                raise TextError(f"{self.name}: alias {alias!r} is not a symbol name")
            if alias in names:
                raise TextError(f"{self.name}: {version} alias {alias} is also an entry")
            if target not in names:
                raise TextError(f"{self.name}: {version} alias {alias} names {target}, which is not a {version} entry")
        return aliases

    def texts(self, version):
        return [entry for entry in self.entries(version) if "record" not in entry]

    def present(self, version):
        return self.object(version) is not None or bool(self.fragment_specs.get(version))

    def source(self, version):
        return ROOT / "assets" / version / "text" / f"{self.name}.txt"

    def header(self, version):
        return ROOT / "build" / version / "gen" / f"{self.name}.h"

    def generated(self, version):
        obj = self.object(version)
        return None if obj is None else ROOT / "build" / version / "gen" / obj["name"]

    def fragment_paths(self, version):
        return [ROOT / "build" / version / "gen" / unit.name for unit in self.fragments(version)]

    def outputs(self, version):
        paths = [self.header(version)]
        if self.generated(version) is not None:
            paths.append(self.generated(version))
        return paths + self.fragment_paths(version)

    def fields(self, record):
        if record not in self.types:
            raise TextError(f"{self.name}: unknown record type {record}")
        offset, align, out = 0, 1, []
        for field in self.types[record]["fields"]:
            width = FIELD_WIDTHS[field["type"]]
            offset = aligned(offset, width)
            out.append((field, width, offset))
            offset += width * field.get("count", 1)
            align = max(align, width)
        return out, aligned(offset, align), align


def load_pools(directory=POOL_DIR):
    return [Pool(path) for path in sorted(Path(directory).glob("*.yaml"))]


def write_if_changed(path, content):
    path = Path(path)
    data = content if isinstance(content, bytes) else content.encode("utf-8")
    if path.exists() and path.read_bytes() == data:
        return False
    path.parent.mkdir(parents=True, exist_ok=True)
    tmp = path.with_name(path.name + ".tmp")
    tmp.write_bytes(data)
    os.replace(tmp, path)
    return True


def parse_source(pool, version, text):
    entries = {}
    lines = text.split("\n")
    index = 0
    while index < len(lines):
        line = lines[index]
        index += 1
        if not line.strip() or line.startswith("#"):
            continue
        if not line.startswith("@") or not line[1:].isidentifier():
            raise TextError(f"{pool.source(version)}:{index}: expected an @entry line")
        name, first = line[1:], index
        body = []
        while True:
            if index >= len(lines):
                raise TextError(f"{pool.source(version)}:{first}: {name} has no {{END}}")
            line = lines[index]
            index += 1
            cut = line.find("{END}")
            if cut < 0:
                body.append(line)
                continue
            if line[cut + 5:].strip():
                raise TextError(f"{pool.source(version)}:{index}: text after {{END}}")
            body.append(line[:cut + 5])
            break
        if name in entries:
            raise TextError(f"{pool.source(version)}:{first}: {name} appears twice")
        entries[name] = ("\n".join(body), first)
    return entries


def read_source(pool, version, charmap):
    path = pool.source(version)
    if not path.exists():
        raise TextError(f"{path.relative_to(ROOT)} is missing; run python3 tools/extract_assets.py {version}")
    parsed = parse_source(pool, version, path.read_text(encoding="utf-8").replace("\r\n", "\n"))
    wanted = [entry["name"] for entry in pool.texts(version)]
    missing = [name for name in wanted if name not in parsed]
    extra = sorted(set(parsed) - set(wanted))
    if missing or extra:
        raise TextError(f"{path.relative_to(ROOT)}: entries differ from config/text/{pool.name}.yaml"
                        f" (missing {missing[:3]}, unknown {extra[:3]})")
    encoded = {}
    for unit in pool.units(version):
        encoding = unit.encoding(charmap)
        for entry in unit.entries:
            if "record" not in entry:
                text, line = parsed[entry["name"]]
                encoded[entry["name"]] = encoding.encode(text, f"{path.relative_to(ROOT)}:{line}")
    return encoded


def record_values(pool, entry):
    fields, _size, _align = pool.fields(entry["record"])
    out = []
    for field, width, offset in fields:
        count = field.get("count", 1)
        values = entry.get(field["name"], [0] * count if count > 1 else 0)
        values = values if isinstance(values, list) else [values]
        if len(values) != count:
            raise TextError(f"{pool.name}: {entry['name']}.{field['name']} needs {count} values")
        out.append((field, width, offset, values))
    return out


def natural_align(unit, encoding):
    return 4 if unit.form == "string" else encoding.width


def decode_unit(unit, encoding, rom):
    pool, version = unit.pool, unit.version

    def rom_at(address, size):
        return rom[address - ROM_BASE:address - ROM_BASE + size]

    def found(entry, start):
        if "record" in entry:
            return b""
        end = encoding.terminated(rom, start - ROM_BASE)
        if end is None or end + ROM_BASE > unit.end:
            raise TextError(f"{pool.name}: {version} {entry['name']} runs past the end of {unit.name}")
        return rom[start - ROM_BASE:end]

    if unit.kind == "fragment" and unit.form != "macro" and unit.count != "slot" and unit.align != natural_align(unit, encoding):
        raise TextError(f"{pool.name}: {version} {unit.name} aligns its entries to {unit.align}, which C only does"
                        f" for {natural_align(unit, encoding)}-aligned {unit.form} definitions")
    placed, position = unit.layout(found)
    cursor = unit.start
    texts = []
    for entry, start, size in placed:
        if unit.stride is None and any(rom_at(cursor, start - cursor)):
            raise TextError(f"{pool.name}: {version} padding before {entry['name']} is not zero")
        data = rom_at(start, size)
        if "record" in entry:
            check_record(pool, version, entry, data)
        else:
            data = found(entry, start)
            if any(rom_at(start + len(data), size - len(data))):
                raise TextError(f"{pool.name}: {version} {entry['name']} holds data past its terminator")
            text = encoding.decode(data)
            where = f"{pool.name}: {version} {entry['name']}"
            if encoding.encode(text, where) != data:
                raise TextError(f"{where} does not re-encode to the ROM bytes")
            texts.append((entry["name"], text))
        cursor = start + size
    if not position <= unit.end < position + 4 or any(rom_at(position, unit.end - position)):
        raise TextError(f"{pool.name}: {version} entries of {unit.name} end at {position:#x}, not {unit.end:#x}")
    return texts


def decode(version, rom):
    charmap = load_charmap(version)
    checked = written = 0
    for pool in load_pools():
        if not pool.present(version):
            continue
        texts = []
        for unit in pool.units(version):
            texts += decode_unit(unit, unit.encoding(charmap), rom)
        source = "\n".join(f"@{name}\n{text}\n" for name, text in texts)
        reparsed = parse_source(pool, version, source)
        if [(name, reparsed[name][0]) for name, _text in texts] != texts:
            raise TextError(f"{pool.name}: {version} source does not parse back to its entries")
        checked += 1
        written += write_if_changed(pool.source(version), source)
    return checked, written


def check_record(pool, version, entry, data):
    for field, width, offset, values in record_values(pool, entry):
        if field["type"] == "ptr":
            continue
        for index, value in enumerate(values):
            at = offset + index * width
            if int.from_bytes(data[at:at + width], "little") != value:
                raise TextError(f"{pool.name}: {version} {entry['name']}.{field['name']} differs from the ROM")


def byte_lines(data):
    return [f"\t.byte {','.join(str(b) for b in data[i:i + BYTES_PER_LINE])}" for i in range(0, len(data), BYTES_PER_LINE)]


def record_lines(pool, entry):
    lines, position = [], 0
    for field, width, offset, values in record_values(pool, entry):
        if offset > position:
            lines += byte_lines(bytes(offset - position))
        lines.append(f"\t{DIRECTIVES[width]} {', '.join(str(value) for value in values)}")
        position = offset + width * len(values)
    size = pool.fields(entry["record"])[1]
    if size > position:
        lines += byte_lines(bytes(size - position))
    return lines


def emit_object(unit, encoded, path):
    lines = ["\t.section .rodata"]
    if unit.start % 4 == 0:
        lines.append("\t.balign 4")
    elif unit.start % 2 == 0:
        lines.append("\t.balign 2")
    placed, position = unit.layout(lambda entry, _start: encoded[entry["name"]])
    cursor = unit.start
    for entry, start, size in placed:
        if start > cursor:
            lines += byte_lines(bytes(start - cursor))
        name = entry["name"]
        lines += [f"\t.global {name}", f"\t.type {name}, %object", f"{name}:"]
        lines += record_lines(unit.pool, entry) if "record" in entry else byte_lines(encoded[name])
        lines.append(f"\t.size {name}, .-{name}")
        cursor = start + size
    if 0 < unit.end - position < 4:
        lines += byte_lines(bytes(unit.end - position))
    write_if_changed(path, "\n".join(lines) + "\n")


def c_values(values, per_line):
    return [f"    {', '.join(str(value) for value in values[i:i + per_line])}," for i in range(0, len(values), per_line)]


def c_record(pool, entry):
    record = entry["record"]
    ctype = pool.types[record].get("ctype", f"const {record}")
    parts = []
    for _field, _width, _offset, values in record_values(pool, entry):
        text = ", ".join(str(value) for value in values)
        parts.append(f"{{ {text} }}" if len(values) > 1 else text)
    return [f"{ctype} {entry['name']} = {{ {', '.join(parts)} }};", ""]


def c_text(unit, entry, data, slot, width):
    units = [int.from_bytes(data[i:i + width], "little") for i in range(0, len(data), width)]
    if unit.count == "slot":
        count = str(slot // width)
    elif unit.count == "exact":
        count = str(len(units))
    else:
        count = ""
    head = f"{entry.get('ctype', unit.ctype)} {entry['name']}[{count}] = "
    if unit.form == "macro":
        head = f"#define {entry['name']} "
    if unit.form in ("string", "macro"):
        if width != 1 or units[-1] != 0 or 0 in units[:-1]:
            raise TextError(f"{unit.pool.name}: {entry['name']} cannot be written as a C string")
        body = "".join(f"\\{value:03o}" for value in units[:-1])
        return [f'{head}"{body}"' + ("" if unit.form == "macro" else ";"), ""]
    return [head + "{"] + c_values(units, 16) + ["};", ""]


def emit_fragment(unit, encoded, path, width):
    placed, position = unit.layout(lambda entry, _start: encoded[entry["name"]])
    lines = []
    for index, (entry, start, size) in enumerate(placed):
        if "record" in entry:
            lines += c_record(unit.pool, entry)
            continue
        slot = (placed[index + 1][1] if index + 1 < len(placed) else unit.end) - start
        lines += c_text(unit, entry, encoded[entry["name"]], slot, width)
    write_if_changed(path, "\n".join(lines).rstrip("\n") + "\n")


def emit_header(pool, version, path):
    guard = f"GUARD_GEN_{pool.name.upper()}_H"
    lines = [f"#ifndef {guard}", f"#define {guard}", "", '#include "types.h"']
    units = pool.units(version)
    headers = []
    for unit in units:
        if unit.header and unit.header not in headers:
            headers.append(unit.header)
    lines += [f'#include "{header}"' for header in headers]
    declared = [(entry.get("ctype", unit.ctype), entry["name"]) for unit in units for entry in unit.entries
                if "record" not in entry and unit.form != "macro" and entry.get("declare", True)]
    if declared:
        lines.append("")
        lines += [f"extern {ctype} {name}[];" for ctype, name in declared]
    aliases = pool.aliases(version)
    if aliases:
        lines.append("")
        lines += [f"#define {alias} {target}" for alias, target in aliases.items()]
    lines += ["", "#endif"]
    write_if_changed(path, "\n".join(lines) + "\n")


def generate(version, manifest):
    pool = Pool(manifest)
    if pool.present(version):
        charmap = load_charmap(version)
        encoded = read_source(pool, version, charmap)
        for unit in pool.units(version):
            if unit.kind == "object":
                emit_object(unit, encoded, pool.generated(version))
            else:
                emit_fragment(unit, encoded, ROOT / "build" / version / "gen" / unit.name, unit.encoding(charmap).width)
    emit_header(pool, version, pool.header(version))


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("version", choices=VERSIONS)
    parser.add_argument("manifest")
    args = parser.parse_args()
    try:
        generate(args.version, args.manifest)
    except TextError as error:
        sys.exit(f"error: {error}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
