import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SOURCE_EXT = {"sample": "wav", "wave": "pcm", "voicegroup": "inc", "keysplit": "inc", "song": "s"}
BINARY_EXT = {"sample": "bin", "wave": "bin"}
FORMATS = tuple(SOURCE_EXT)
INCLUDED = ("voicegroup", "keysplit", "song")
SEQUENCE_INCLUDE = "m4a_sequence.inc"
VOICE_INCLUDE = "m4a_voice.inc"

LENGTHS = list(range(25)) + [28, 30, 32, 36, 40, 42, 44, 48, 52, 54, 56, 60, 64, 66, 68, 72, 76, 78, 80, 84, 88, 90, 92, 96]
NOTE_NAMES = ("Cn", "Cs", "Dn", "Ds", "En", "Fn", "Fs", "Gn", "Gs", "An", "As", "Bn")
COMMANDS = {0xB1: "FINE", 0xB2: "GOTO", 0xB3: "PATT", 0xB4: "PEND", 0xB5: "REPT", 0xB9: "MEMACC", 0xBA: "PRIO",
            0xBB: "TEMPO", 0xBC: "KEYSH", 0xBD: "VOICE", 0xBE: "VOL", 0xBF: "PAN", 0xC0: "BEND", 0xC1: "BENDR",
            0xC2: "LFOS", 0xC3: "LFODL", 0xC4: "MOD", 0xC5: "MODT", 0xC8: "TUNE", 0xCC: "PORT", 0xCD: "XCMD",
            0xCE: "EOT", 0xCF: "TIE"}
XCMDS = {0x01: "xWAVE", 0x02: "xTYPE", 0x04: "xATTA", 0x05: "xDECA", 0x06: "xSUST", 0x07: "xRELE", 0x08: "xIECV",
         0x09: "xIECL", 0x0A: "xLENG", 0x0B: "xSWEE"}
TRACK_OPS = {0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB9, 0xBA, 0xBB, 0xBC}
ONE_ARG = {0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC8}
CENTERED = {0xBF, 0xC0, 0xC8}
FINE = 0xB1
GOTO = 0xB2
VOICE_TYPES = {0x00: "directsound", 0x08: "directsound_no_resample", 0x10: "directsound_alt",
               0x01: "square_1", 0x09: "square_1_alt", 0x02: "square_2", 0x0A: "square_2_alt",
               0x03: "programmable_wave", 0x0B: "programmable_wave_alt", 0x04: "noise", 0x0C: "noise_alt"}
KEYSPLIT = 0x40
KEYSPLIT_ALL = 0x80
VOICE_SIZE = 12
LOOP_FLAG = 0x4000
PITCH_UNIT = 1024


class M4aError(Exception):
    pass


def u32(data, offset):
    return struct.unpack_from("<I", data, offset)[0]


def note_name(key):
    octave = key // 12 - 2
    return NOTE_NAMES[key % 12] + (f"M{-octave}" if octave < 0 else str(octave))


def op_name(op):
    if 0x80 <= op <= 0xB0:
        return f"W{LENGTHS[op - 0x80]:02d}"
    if op >= 0xD0:
        return f"N{LENGTHS[op - 0xCF]:02d}"
    return COMMANDS[op]


def signed(value):
    return value - 256 if value >= 128 else value


def offset_text(base, delta):
    return f"{base}+{delta}" if delta >= 0 else f"{base}-{-delta}"


class Symbols:
    def __init__(self, by_address, groups, tables):
        self.by_address = by_address
        self.groups = sorted(groups)
        self.tables = tables

    def exact(self, address, what):
        if address not in self.by_address:
            raise M4aError(f"{what} {address:#010x} names no sound asset")
        return self.by_address[address]

    def table(self, address):
        if address not in self.tables:
            raise M4aError(f"keysplit table {address:#010x} names no table")
        return self.tables[address]

    def group_base(self, address):
        for start, symbol in self.groups:
            delta = start - address
            if 0 <= delta < 128 * VOICE_SIZE and delta % VOICE_SIZE == 0:
                return symbol, delta // VOICE_SIZE
        raise M4aError(f"voice group {address:#010x} names no group")


def parse_track(data, base, start, limit, stop_at_fine=False):
    position = start
    running = None
    events = []
    while position < limit:
        at = position
        byte = data[position - base]
        if byte < 0x80:
            if running is None:
                raise M4aError(f"running status without a command at {at:#x}")
            op, explicit = running, False
        else:
            op, explicit = byte, True
            position += 1
            if op >= 0xBD:
                running = op

        def take(count):
            nonlocal position
            if position + count > limit:
                raise M4aError(f"event at {at:#x} runs past {limit:#x}")
            values = list(data[position - base:position - base + count])
            position += count
            return values

        def optional():
            return position < limit and data[position - base] < 0x80

        event = {"at": at, "op": op, "explicit": explicit, "args": []}
        if op >= 0xCF:
            for _ in range(3):
                if not optional():
                    break
                event["args"] += take(1)
        elif 0x80 <= op <= 0xB0 or op in (FINE, 0xB4):
            pass
        elif op in (GOTO, 0xB3):
            event["target"] = u32(bytes(take(4)), 0)
        elif op == 0xB5:
            event["args"] = take(1)
            event["target"] = u32(bytes(take(4)), 0)
        elif op == 0xB9:
            event["args"] = take(3)
            if 6 <= event["args"][0] <= 17:
                event["target"] = u32(bytes(take(4)), 0)
        elif op in ONE_ARG:
            event["args"] = take(1)
        elif op == 0xCC:
            event["args"] = take(2)
        elif op == 0xCD:
            event["args"] = take(1)
            if event["args"][0] == 0x01:
                event["pointer"] = u32(bytes(take(4)), 0)
            elif event["args"][0] in XCMDS:
                event["args"] += take(1)
            else:
                raise M4aError(f"unsupported XCMD {event['args'][0]:#x} at {at:#x}")
        elif op == 0xCE:
            if optional():
                event["args"] = take(1)
        else:
            raise M4aError(f"unsupported command {op:#x} at {at:#x}")
        events.append(event)
        if stop_at_fine and op == FINE:
            return events, position
    if stop_at_fine:
        raise M4aError(f"track at {start:#x} has no FINE before {limit:#x}")
    return events, position


def song_header(data, address):
    found = []
    for count in range(17):
        offset = len(data) - (8 + 4 * count if count else 4)
        if offset < 0 or offset % 4 or data[offset] != count:
            continue
        if count and u32(data, offset + 8) != address or not count and offset:
            continue
        found.append(offset)
    if len(found) != 1:
        raise M4aError(f"song at {address:#010x} has {len(found)} header candidates")
    return found[0]


def song_tracks(name, address, data, header, count):
    starts = [u32(data, header + 8 + 4 * k) for k in range(count)]
    if starts != sorted(starts):
        raise M4aError(f"{name}: tracks are not stored in order")
    tracks = []
    for index, start in enumerate(starts):
        if index + 1 < count:
            events, _end = parse_track(data, address, start, starts[index + 1])
        else:
            events, end = parse_track(data, address, start, address + header, stop_at_fine=True)
            pad = address + header - end
            if pad != (-end) % 4 or any(data[end - address:header]):
                raise M4aError(f"{name}: {pad} bytes lie between the last track and the header")
        tracks.append(events)
    return tracks


def track_labels(name, tracks):
    owner = {}
    for index, events in enumerate(tracks):
        for event in events:
            owner[event["at"]] = index + 1
    kinds = {}
    for events in tracks:
        for event in events:
            if "target" not in event:
                continue
            target = event["target"]
            if target not in owner:
                raise M4aError(f"{name}: the jump at {event['at']:#x} lands inside an event at {target:#x}")
            if event["op"] != GOTO or kinds.get(target) == "pattern":
                kinds[target] = "pattern"
            else:
                kinds[target] = "loop"
    labels = {}
    loops = {}
    patterns = 0
    for target in sorted(kinds):
        track = owner[target]
        if kinds[target] == "pattern":
            labels[target] = f"{name}_{track}_{patterns:03d}"
            patterns += 1
        else:
            loops[track] = loops.get(track, 0) + 1
            labels[target] = f"{name}_{track}_B{loops[track]}"
    return labels


def arg_text(name, op, value):
    if op == 0xBE:
        return f"{value}*{name}_mvl/mxv"
    if op == 0xBB:
        return f"{value * 2}*{name}_tbs/2"
    if op == 0xBC:
        return offset_text(f"{name}_key", signed(value))
    if op in CENTERED:
        return offset_text("c_v", value - 0x40)
    return str(value)


def note_args(args):
    texts = [note_name(args[0])] if args else []
    if len(args) > 1:
        texts.append(f"v{args[1]:03d}")
    if len(args) > 2:
        texts.append(f"gtp{args[2]}" if 1 <= args[2] <= 3 else str(args[2]))
    return texts


def render_event(name, event, labels, symbols):
    op = event["op"]
    args = event["args"]
    if op >= 0xCF:
        texts = note_args(args)
    elif op == 0xCE:
        texts = [note_name(value) for value in args]
    elif op == 0xCD:
        texts = [XCMDS[args[0]]] + [str(value) for value in args[1:]]
    else:
        texts = [arg_text(name, op, value) for value in args]
    tabs = "\t" if op in TRACK_OPS or 0x80 <= op <= 0xB0 else "\t\t"
    if not event["explicit"]:
        body = "        " + " , ".join(texts)
    elif texts:
        body = f"{op_name(op):<6}, " + " , ".join(texts)
    else:
        body = op_name(op)
    lines = [f"\t.byte{tabs}{body}"]
    if "target" in event:
        lines.append(f"\t .word\t{labels[event['target']]}")
    if "pointer" in event:
        lines.append(f"\t .word\t{symbols.exact(event['pointer'], 'wave')}")
    return lines


def song_values(name, data, header, symbols):
    count, _blocks, priority, reverb = data[header:header + 4]
    values = []
    if count:
        tone = u32(data, header + 4)
        values.append(("grp", symbols.by_address.get(tone, f"{tone:#010x}")))
    values += [("pri", str(priority)),
               ("rev", offset_text("reverb_set", reverb - 0x80) if reverb & 0x80 else str(reverb)),
               ("mvl", "127"), ("key", "0"), ("tbs", "1")]
    return [f'\t.include "{SEQUENCE_INCLUDE}"', ""] + [f"\t.equ\t{name}_{key}, {value}" for key, value in values]


def song_trailer(name, data, header):
    count, blocks = data[header:header + 2]
    lines = ["", "\t.align\t2", f"{name}:", f"\t.byte\t{count}", f"\t.byte\t{blocks}", f"\t.byte\t{name}_pri",
             f"\t.byte\t{name}_rev"]
    if count:
        lines.append(f"\t.word\t{name}_grp")
        lines += [f"\t.word\t{name}_{index + 1}" for index in range(count)]
    return lines


def raw_tracks(name, address, data, header):
    starts = {}
    for index in range(data[header]):
        offset = u32(data, header + 8 + 4 * index) - address
        if not 0 <= offset < header:
            raise M4aError(f"{name}: track {index + 1} starts outside the song")
        starts.setdefault(offset, []).append(f"{name}_{index + 1}:")
    lines = []
    cuts = sorted(set(range(0, header, 16)) | set(starts)) + [header]
    for begin, end in zip(cuts, cuts[1:]):
        lines += starts.get(begin, [])
        lines.append("\t.byte " + ", ".join(f"{value:#04x}" for value in data[begin:end]))
    return lines


def decode_song(name, address, data, symbols):
    header = song_header(data, address)
    lines = song_values(name, data, header, symbols)
    lines += ["", "\t.section .rodata", f"\t.global\t{name}", "\t.align\t2"]
    try:
        tracks = song_tracks(name, address, data, header, data[header])
        labels = track_labels(name, tracks)
        body = []
        for index, events in enumerate(tracks):
            body += ["", f"{name}_{index + 1}:"]
            for event in events:
                if event["at"] in labels:
                    body.append(f"{labels[event['at']]}:")
                body += render_event(name, event, labels, symbols)
    except M4aError:
        body = [""] + raw_tracks(name, address, data, header)
    return "\n".join(lines + body + song_trailer(name, data, header)) + "\n"


def voice_line(voice, symbols):
    kind = voice[0]
    pointer = u32(voice, 4)
    if kind == KEYSPLIT and not any(voice[1:4]):
        return f"\tvoice_keysplit {symbols.exact(pointer, 'voice group')}, {symbols.table(u32(voice, 8))}"
    if kind == KEYSPLIT_ALL and not any(voice[1:4]) and not u32(voice, 8):
        group, note = symbols.group_base(pointer)
        return f"\tvoice_keysplit_all {group}" + (f", {note}" if note else "")
    family = kind & 0x07
    fixed = {0: voice[2:3], 3: voice[2:3], 1: voice[2:3] + voice[6:8], 2: voice[2:3] + voice[5:8],
             4: voice[2:3] + voice[5:8]}
    if kind not in VOICE_TYPES or any(fixed[family]) or voice[3] == 0x80 or 0 < voice[3] < 0x80:
        return "\t.byte " + ", ".join(str(value) for value in voice)
    head = f"\tvoice_{VOICE_TYPES[kind]} {voice[1]}, {voice[3] & 0x7F}"
    envelope = ", ".join(str(value) for value in voice[8:12])
    if family == 0:
        return f"{head}, {symbols.exact(pointer, 'sample')}, {envelope}"
    if family == 3:
        return f"{head}, {symbols.exact(pointer, 'wave')}, {envelope}"
    if family == 1:
        return f"{head}, {voice[4]}, {voice[5]}, {envelope}"
    return f"{head}, {voice[4]}, {envelope}"


def decode_voicegroup(name, data, symbols):
    if len(data) % VOICE_SIZE:
        raise M4aError(f"{name}: {len(data)} bytes is not a whole number of voices")
    lines = [f"\t.global {name}", f"{name}:"]
    lines += [voice_line(data[offset:offset + VOICE_SIZE], symbols) for offset in range(0, len(data), VOICE_SIZE)]
    return "\n".join(lines) + "\n"


def decode_keysplit(name, data, note):
    lines = [f"\tkeysplit {name}, {note}"]
    position = 0
    while position < len(data):
        end = position
        while end < len(data) and data[end] == data[position]:
            end += 1
        lines.append(f"\tsplit {data[position]}, {note + end}")
        position = end
    return "\n".join(lines) + "\n"


def keysplit_notes(voices, tables):
    starts = sorted(tables)
    notes = {}
    for address, data in voices:
        for offset in range(0, len(data) - len(data) % VOICE_SIZE, VOICE_SIZE):
            if data[offset] != KEYSPLIT:
                continue
            pointer = u32(data, offset + 8)
            following = [start for start in starts if start >= pointer]
            if not following or following[0] - pointer >= 128:
                raise M4aError(f"the keysplit voice at {address + offset:#010x} points at no table")
            if notes.setdefault(following[0], following[0] - pointer) != following[0] - pointer:
                raise M4aError(f"keysplit table {following[0]:#010x} is used with two start notes")
    return notes


def flip(pcm):
    return bytes(value ^ 0x80 for value in pcm)


def riff_chunk(tag, body):
    return tag + struct.pack("<I", len(body)) + body + (b"\0" if len(body) % 2 else b"")


def decode_sample(name, data):
    if len(data) < 17:
        raise M4aError(f"{name}: {len(data)} bytes is too short for a sample")
    kind, status, pitch, loop, size = struct.unpack_from("<HHIII", data, 0)
    if kind:
        raise M4aError(f"{name}: sample type {kind} is not supported")
    if status not in (0, LOOP_FLAG):
        raise M4aError(f"{name}: sample status {status:#x} is not supported")
    if len(data) != 16 + size + 1:
        raise M4aError(f"{name}: {len(data)} bytes hold a {size}-sample header")
    pcm = data[16:16 + size]
    looped = status == LOOP_FLAG
    if looped and loop >= size or not looped and loop:
        raise M4aError(f"{name}: loop start {loop} does not fit the sample")
    if data[-1] != (pcm[loop] if looped else 0):
        raise M4aError(f"{name}: the byte after the samples is not the loop sample")
    rate = max(1, (pitch + PITCH_UNIT // 2) // PITCH_UNIT)
    body = riff_chunk(b"fmt ", struct.pack("<HHIIHH", 1, 1, rate, rate, 1, 8))
    if looped:
        body += riff_chunk(b"smpl", struct.pack("<9I", 0, 0, 1000000000 // rate, 60, 0, 0, 0, 1, 0)
                           + struct.pack("<6I", 0, 0, loop, size - 1, 0, 0))
    if rate * PITCH_UNIT != pitch:
        body += riff_chunk(b"agbp", struct.pack("<I", pitch))
    body += riff_chunk(b"data", flip(pcm))
    return b"RIFF" + struct.pack("<I", 4 + len(body)) + b"WAVE" + body


def riff_chunks(wav):
    if len(wav) < 12 or wav[:4] != b"RIFF" or wav[8:12] != b"WAVE":
        raise M4aError("not a RIFF WAVE file")
    chunks = {}
    position = 12
    while position + 8 <= len(wav):
        size = u32(wav, position + 4)
        chunks[wav[position:position + 4]] = wav[position + 8:position + 8 + size]
        position += 8 + size + (size & 1)
    return chunks


def encode_sample(wav):
    chunks = riff_chunks(wav)
    if b"fmt " not in chunks or b"data" not in chunks:
        raise M4aError("a sample needs fmt and data chunks")
    fmt, channels, rate, _byte_rate, _align, bits = struct.unpack_from("<HHIIHH", chunks[b"fmt "], 0)
    if (fmt, channels, bits) != (1, 1, 8):
        raise M4aError("a sample must be 8-bit mono PCM")
    pcm = flip(chunks[b"data"])
    pitch = u32(chunks[b"agbp"], 0) if b"agbp" in chunks else rate * PITCH_UNIT
    loop = None
    if b"smpl" in chunks:
        smpl = chunks[b"smpl"]
        if u32(smpl, 28) != 1:
            raise M4aError("a sample holds one loop at most")
        start, end = struct.unpack_from("<2I", smpl, 44)
        if end != len(pcm) - 1 or start >= len(pcm):
            raise M4aError("a sample loop must end at the last sample")
        loop = start
    header = struct.pack("<HHIII", 0, LOOP_FLAG if loop is not None else 0, pitch, loop or 0, len(pcm))
    return header + pcm + bytes([pcm[loop] if loop is not None else 0])


def encode(fmt, source):
    return encode_sample(source) if fmt == "sample" else source


def includes(entries, source):
    formats = {entry.get("format") for entry in entries}
    out = []
    if formats & {"voicegroup", "keysplit"}:
        out.append(ROOT / "include" / VOICE_INCLUDE)
    if "song" in formats:
        out.append(ROOT / "include" / SEQUENCE_INCLUDE)
    return out + [source(entry) for entry in entries if entry.get("format") in INCLUDED]


def prelude(entries):
    if any(entry.get("format") in ("voicegroup", "keysplit") for entry in entries):
        return [f'\t.include "{VOICE_INCLUDE}"']
    return []


class Context:
    def __init__(self, manifests, version, rom_bytes):
        by_address = {}
        groups = []
        tables = {}
        voices = []
        for manifest in manifests:
            for entry in manifest.entries:
                fmt = entry.get("format")
                if version not in entry or fmt in ("sprite_sheet", "song"):
                    continue
                address = entry[version]["address"]
                symbol = manifest.symbol(entry, version)
                if fmt == "keysplit":
                    tables[address] = symbol
                    continue
                by_address[address] = symbol
                if fmt == "voicegroup":
                    groups.append((address, symbol))
                    voices.append((address, rom_bytes(entry)))
        self.notes = keysplit_notes(voices, tables)
        self.symbols = Symbols(by_address, groups,
                               {address - self.notes.get(address, 0): symbol for address, symbol in tables.items()})

    def decode(self, entry, symbol, address, data):
        fmt = entry["format"]
        if fmt == "sample":
            source = decode_sample(symbol, data)
            if encode_sample(source) != data:
                raise M4aError(f"{symbol}: the sample does not re-encode to the ROM bytes")
            return source
        if fmt == "wave":
            return data
        if fmt == "voicegroup":
            return decode_voicegroup(symbol, data, self.symbols).encode()
        if fmt == "keysplit":
            return decode_keysplit(symbol, data, self.notes.get(address, 0)).encode()
        return decode_song(symbol, address, data, self.symbols).encode()
