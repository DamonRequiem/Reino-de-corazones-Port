#!/usr/bin/env python3
"""Generate a non-US version's build tree from the US one.

src/ is shared across versions, so every INCLUDE_ASM line in it has to
resolve for each version. This walks config/<version>/funcmap.txt (written
by tools/version_align.py) and emits, at that version's addresses:

  config/<version>/symbols.txt        globals, mapped through the pool words
                                      of instruction-identical function pairs
  asm/<version>/header.s, crt0.s      the pre-code region
  asm/<version>/nonmatchings/<tu>/    one incbin chunk per INCLUDE_ASM in src/
  asm/<version>/data.s, data2.s       the post-code region
  config/<version>/units.txt          the US link order

The chunks are incbins rather than disassembly: their job is to reproduce
the ROM's bytes at an address the link already fixes, and the readable
disassembly to decompile from lives on the US side. A chunk's extent comes
from the next function's address in this version, not from the US size, so
a function that is a different length here still tiles correctly.

A source file that config/us/units.txt does not list joins this version's
link order when it defines functions named <version>_<address> (or listed
in TARGET_REGION_FUNCS); it goes where those addresses fall, and its .rodata and .data come from
TARGET_DATA_ADDR and TARGET_DATA_SIZE.
"""

import argparse
import bisect
import re
import struct
from pathlib import Path

from rom_data_evidence import data_symbol_map, load_evidence
from function_pointer_evidence import literal_pointer_pairs, load_literal_loads, load_function_modes, trace_literal_loads
import assetgen
import baserom
import textgen

ROM_BASE = 0x08000000
CODE_HI = 0x081213C4

VENEER_STUB = bytes((0x78, 0x47, 0xC0, 0x46))
VENEER_SIZE = 8
VENEER_NAMES = ("func_081213C4", "func_081213CC", "func_081213D4")


def veneer_labels(data):
    if len(data) != VENEER_SIZE * len(VENEER_NAMES):
        return None

    for i in range(len(VENEER_NAMES)):
        piece = data[i * VENEER_SIZE:(i + 1) * VENEER_SIZE]

        if piece[:4] != VENEER_STUB or piece[7] != 0xEA:
            return None
    return VENEER_NAMES


def validate_transform_veneers(rom, address, transform):
    size = VENEER_SIZE * len(VENEER_NAMES)
    if address < ROM_BASE or address + size > ROM_BASE + len(rom) or address % 4:
        raise ValueError('transform veneers are outside ROM or misaligned')
    data = rom[address - ROM_BASE:address - ROM_BASE + size]
    if veneer_labels(data) != VENEER_NAMES:
        raise ValueError('transform veneers have an unexpected instruction sequence')
    for index, offset in enumerate((0x134, 0, 0x1BC)):
        branch = struct.unpack_from('<I', data, index * VENEER_SIZE + 4)[0]
        displacement = branch & 0xFFFFFF
        if displacement & 0x800000:
            displacement -= 0x1000000
        target = address + index * VENEER_SIZE + 12 + displacement * 4
        if target != transform + offset:
            raise ValueError('transform veneer branch target differs from the native ARM entry')
    return size


def asset(ver, lo, hi):
    return f"assets/{ver}/{lo:08X}-{hi:08X}.bin"


def link_order(entries):
    order, position, anchor = [], {}, None
    for name, section in entries:
        if section == ".text":
            if name not in position:
                position[name] = len(order)
                order.append(name)
            continue
        if name in position:
            anchor = name
            continue
        index = len(order) if anchor is None else position[anchor] + 1
        order.insert(index, name)
        position = {o: i for i, o in enumerate(order)}
        anchor = name
    return order


def blob_source(ver, lo, hi, data, align=False):
    head = (f'\t.section .rodata\n' + ('\t.balign 4\n' if align else '')
            + f'\t.global data_{lo:08X}\ndata_{lo:08X}:\n')
    names = veneer_labels(data)

    if not names:
        return head + f'\t.incbin "{asset(ver, lo, hi)}"\n'
    body = ""

    for i, name in enumerate(names):
        at = lo + i * VENEER_SIZE
        body += (f'\t.thumb_func\n\t.global {name}\n{name}:\n'
                 f'\t.incbin "{asset(ver, at, at + VENEER_SIZE)}"\n')
    return head + body

TRUSTED = ("named", "xref", "global", "body", "fill", "near", "match")

TARGET_ANCHORS = {
    "eu": {
        0x08f7f66c: 0x0905984c,
        0x08fbd378: 0x0908282c,
        0x09007134: 0x090b2510,
        0x0902fce8: 0x090c9044,
        0x09ED9BA8: 0x09F57460,
        0x09EE3844: 0x09F6EF64,
        0x09EE1520: 0x09F5C0EC,
        0x0813B67C: 0x08889B50,
        0x08135EFC: 0x088843D0,
        0x09A10A3C: 0x09A60380,
        0x099A2B62: 0x099AF866,
        0x099A36F8: 0x099B167C,
        0x09EF99D0: 0x09F8563C,
        0x09EF99A8: 0x09F85614,
        0x088C56C6: 0x088F0FEA,
        0x09A03CFC: 0x09A42400,
        0x0999E69E: 0x099A9E42,
        0x09EF9858: 0x09F85444,
        0x09EF9830: 0x09F8541C,
        0x08C6A6A4: 0x08C9BD78,
        0x08C6A69A: 0x08C9BD6E,
        0x08C6A878: 0x08C9C274,
        0x09A36EDC: 0x09A89EA0,
        0x09A373DC: 0x09A8A3A0,
        0x09402F78: 0x094DCCE4,
        0x09041E80: 0x090D1DC0,
        0x095152B8: 0x09537B24,
        0x0951534C: 0x09537BB8,
        0x095172B8: 0x09534324,
        0x09517AB8: 0x09534B24,
        0x09519AB8: 0x09538324,
        0x0951A2B8: 0x09538B24,
        0x0951AAB8: 0x09539324,
        0x02034890: 0x02034898,
        0x08C6A51C: 0x08C9C100,
        0x08C6A526: 0x08C9C10A,
        0x08F7CF18: 0x08F8DE14,
        0x0976DB68: 0x0973BA18,
        0x0976DB9C: 0x0973BA4C,
        0x09ED77D4: 0x09F476C8,
        0x09ED82D4: 0x09F481C8,
        0x08130E6C: 0x0887F340,
        0x0976D8A6: 0x097385B0,
        0x0976DBDA: 0x0973BA8A,
        0x092EB78A: 0x093BAE12,
        0x09958124: 0x0994AFB0,
        0x09EE1538: 0x09F5C140,
        0x0951B2B8: 0x09539B24,
        0x09512AB8: 0x09532B24,
        0x095192B8: 0x09537324,
        0x095182B8: 0x09535B24,
        0x09514AB8: 0x09536B24,
        0x090356EC: 0x090CE9FE,
        0x090356F2: 0x090CEA04,
        0x090A4664: 0x09193560,
        0x09EEB000: 0x09F77120,
        0x09EEB008: 0x09F77128,
        0x09D2B334: 0x09D9ABE0,
        0x09EEB03C: 0x09F7715C,
        0x09035730: 0x090CEA44,
        0x096B2664: 0x09677C0C,
        0x09C5CC7C: 0x09CE23B0,
        0x09EFAF60: 0x09F87494,
        0x09EFAF6C: 0x09F874A0,
        0x020354A8: 0x02035938,
        0x020354B0: 0x02035940,
        0x09A324DC: 0x09A854A0,
        0x097DB5F8: 0x097B1D00,
        0x09841798: 0x09815E40,
        0x09A123DC: 0x09A62840,
        0x09A18EBC: 0x09A69320,
        0x09ED9B88: 0x09F49A8C,
        0x09EE78A4: 0x09F72CD8,
        0x09EF4F08: 0x09F802B0,
        0x096AD744: 0x0967818C,
        0x097A28DA: 0x09780322,
        0x09EF6934: 0x09F81FB0,
        0x098A8C66: 0x0988740A,
        0x08B1EB1C: 0x08B4A42C,
        0x08F61B84: 0x08F5C0DC,
        0x08F60B84: 0x08F5B8DC,
        0x08C6A88C: 0x08C9C288,
        0x08C6A54E: 0x08C9C132,
        0x08C6A6B8: 0x08C9BDC0,
        0x08C6A958: 0x08C9C354,
        0x09EE2678: 0x09F5D4C0,
        0x09EE2668: 0x09F5D4B0,
        0x09EEA1EC: 0x09F76024,
        0x099930E8: 0x09999398,
        0x09A3641C: 0x09A88EE0,
        0x09A3691C: 0x09A893E0,
        0x0999FA20: 0x099AB1C4,
        0x099A012C: 0x099AB8D0,
        0x09EF9898: 0x09F85484,
        0x09EF9870: 0x09F8545C,
        0x09EF98B0: 0x09F8549C,
        0x09EF98A0: 0x09F8548C,
        0x091CF5D4: 0x0929EC5C,
        0x096B2124: 0x096776CC,
        0x096F8464: 0x096BF98C,
        0x096F8C64: 0x096C018C,
        0x09EE42C8: 0x09F6F57C,
        0x020354A0: 0x02035930,
        0x020352B8: 0x02035568,
        0x090A7D9A: 0x09198606,
        0x090A6B26: 0x09197392,
        0x09EEB108: 0x09F77298,
        0x09EEB0C4: 0x09F77254,
        0x09EEB14C: 0x09F772DC,
        0x09EEB11C: 0x09F772AC,
        0x090A7F0A: 0x09198776,
        0x090A8FC4: 0x09199830,
        0x09EEB180: 0x09F77310,
        0x09EEB150: 0x09F772E0,
        0x09ED9B78: 0x09F49A7C,
        0x0815A09A: 0x088912C8,
        0x0815A198: 0x088912F0,
        0x0815A0EE: 0x08891318,
        0x0815A152: 0x08891340,
        0x0815A0A0: 0x088912A0,
        0x09613E98: 0x09546D84,
        0x09EE7F60: 0x09F733BC,
        0x09EE7F90: 0x09F733EC,
        0x09035898: 0x090CEB78,
        0x090358D0: 0x090CEBB8,
        0x0951C2B8: 0x0953BB24,
        0x09035874: 0x090CEB3A,
        0x09EE7F48: 0x09F733A4,
        0x09EE7F30: 0x09F7338C,
        0x09EE790C: 0x09F72D6C,
        0x09037FB4: 0x090D1354,
        0x090950F4: 0x0916C228,
        0x09091D36: 0x09168E6A,
        0x095112B8: 0x09531224,
        0x09EE78D4: 0x09F72D58,
        0x09EE78F0: 0x09F72D58,
        0x09EE7914: 0x09F72D74,
        0x09613EB8: 0x09546DA4,
        0x09613ED8: 0x09546DC4,
        0x09613F18: 0x09546E04,
        0x09613F38: 0x09546E24,
        0x09EEA1BC: 0x09F72D30,
        0x0950F2B8: 0x09532624,
        0x099930BC: 0x0999936C,
        0x0999CFC6: 0x099A42AA,
        0x0999D41A: 0x099A46FE,
        0x0999D8A8: 0x099A4B8C,
        0x099FB53C: 0x09A24480,
        0x09A32EDC: 0x09A859A0,
        0x09A333DC: 0x09A85EA0,
        0x09A3399C: 0x09A86460,
        0x09A33E9C: 0x09A86960,
        0x09EF97B0: 0x09F8524C,
        0x09EF97C4: 0x09F85260,
        0x09EF97CC: 0x09F85268,
        0x09EF97DC: 0x09F85278,
        0x08155C54: 0x0887B6AC,
        0x0815600C: 0x0887BA20,
        0x0815631C: 0x0887BCF8,
        0x081564A4: 0x0887BE64,
        0x0815662C: 0x0887BFD0,
        0x081570E4: 0x0887C9C4,
        0x08157694: 0x0887CF0C,
        0x08157B9C: 0x0887D3B8,
        0x08158114: 0x0887D8CC,
        0x081589D4: 0x0887E0EC,
        0x08155B04: 0x0887B574,
        0x081576CC: 0x0887CF40,
        0x0815917C: 0x0887E808,
        0x0815948C: 0x0887EAE0,
        0x081595DC: 0x0887EC18,
        0x08F64384: 0x08F5A8DC,
        0x08F60384: 0x08F610DC,
        0x08F5EB84: 0x08F5E0DC,
        0x08F63384: 0x08F5F8DC,
        0x08F5FB84: 0x08F5F0DC,
        0x08F63B84: 0x08F600DC,
        0x08F64B84: 0x08F5B0DC,
        0x08EE78E4: 0x08EF7E3C,
        0x08C6A530: 0x08C9C114,
        0x08C6A53A: 0x08C9C11E,
        0x095142B8: 0x09535324,
        0x08B25ADE: 0x08B506CE,
        0x09041EB4: 0x090D1DFE,
        0x09041EBA: 0x090D1E04,
        0x09041EEE: 0x090D1E38,
        0x090A44C4: 0x091933C0,
        0x0961A9C8: 0x095DBEA8,
        0x0961A9CC: 0x095DBEAC,
        0x0961A9E8: 0x095DBEC8,
        0x09045188: 0x090D1F98,
        0x090352F4: 0x090CE5E8,
        0x090352FC: 0x090CE5F0,
        0x09511AB8: 0x09531724,
        0x095122B8: 0x09531C24,
        0x08F7DB10: 0x09057CF0,
        0x08F7DB40: 0x09057D20,
        0x08F7DC60: 0x09057E40,
        0x08F7DCF0: 0x09057ED0,
        0x08F7DD20: 0x09057F00,
        0x08F7DD50: 0x09057F30,
        0x08F7DD80: 0x09057F60,
        0x096194B0: 0x095DA8C4,
        0x096193B8: 0x095DA818,
        0x090451A0: 0x090D1FC0,
        0x09EE9190: 0x09F74610,
        0x09045158: 0x090D1F68,
        0x09EE9170: 0x09F745E0,
        0x09041F64: 0x090D1E4C,
        0x09EE8F20: 0x09F743A0,
        0x09041EF8: 0x090D1E40,
        0x09EE8EF0: 0x09F7434C,
        0x09041F48: 0x090D1E4C,
        0x09EE8F08: 0x09F743A0,
        0x09041EA4: 0x090D1DE4,
        0x09EE8E60: 0x09F742BC,
        0x09041E90: 0x090D1DD0,
        0x09EE8E30: 0x09F7428C,
        0x09041E78: 0x090D1DB8,
        0x09EE8008: 0x09F73478,
        0x0903C00C: 0x090D1888,
        0x09041E7F: 0x090D76FB,
        0x0903BFFC: 0x090D1878,
        0x0903BFEC: 0x090D1868,
        0x09EE7D84: 0x09F73238,
        0x09EE79EC: 0x09F72EC0,
        0x090381E8: 0x090D1588,
        0x09EE79B4: 0x09F72E88,
        0x09038024: 0x090D13C4,
        0x09EE7968: 0x09F72E3C,
        0x09037FE4: 0x090D1384,
        0x09EE78D4: 0x09F72D08,
        0x09037F90: 0x090D130C,
        0x09EE7894: 0x09F72CA0,
        0x090362D4: 0x090CF650,
        0x09EE7834: 0x09F72C40,
        0x09036294: 0x090CF638,
        0x09EE781C: 0x09F72C28,
        0x09036230: 0x090CF5D4,
        0x09EE778C: 0x09F72B84,
        0x090361C8: 0x090CF56C,
        0x09EE7698: 0x09F72A90,
        0x0903614C: 0x090CF4F0,
        0x09EE75F0: 0x09F729AC,
        0x090359F0: 0x090CED98,
        0x09EE75D8: 0x09F72994,
        0x090359BC: 0x090CED58,
        0x09EE4BA0: 0x09F6FF20,
        0x090359A0: 0x090CED3C,
        0x09EE4B40: 0x09F6FEC0,
        0x0903596C: 0x090CED08,
        0x09EE4B28: 0x09F6FEA8,
        0x09035738: 0x090CEA4C,
        0x09EE4A68: 0x09F6FD14,
        0x09035348: 0x090CE63C,
        0x09EE4A2C: 0x09F6FCD8,
        0x09035314: 0x090CE608,
        0x09EE49B4: 0x09F6FC60,
        0x09034060: 0x090CD354,
        0x09EE496C: 0x09F6FC18,
    },
    "jp": {
        0x08f7f66c: 0x08f72b74,
        0x08fbd378: 0x08fa6a14,
        0x09007134: 0x08fe380c,
        0x0902fce8: 0x09002fac,
        0x09079EB2: 0x09033FA2,
        0x09080074: 0x0903AE74,
        0x090822F2: 0x0903D494,
        0x09086C1C: 0x09042084,
        0x09087DD2: 0x09043374,
        0x09089C16: 0x090453C8,
        0x0908A958: 0x090461C8,
        0x0908AF32: 0x090467A2,
        0x0813B67C: 0x0813B6F8,
        0x08135EFC: 0x08135F78,
        0x0999E69E: 0x09953126,
        0x09C8D47A: 0x09C678B4,
        0x09C8F1FA: 0x09C68CC6,
        0x09EFBAD4: 0x09ED304C,
        0x0999D9C0: 0x0995248C,
        0x0999D9CA: 0x09952496,
        0x0999D9E6: 0x099524AC,
        0x0999DA1A: 0x099524E0,
        0x0999D41A: 0x09951EE6,
        0x0999D8A8: 0x09952374,
        0x0815A09A: 0x0814EF38,
        0x0815A198: 0x0814EF40,
        0x0815A0EE: 0x0814EF48,
        0x0815A152: 0x0814EF50,
        0x0815A0A0: 0x0814EF2C,
        0x09417438: 0x093CB694,
        0x09418438: 0x093CD694,
        0x09419438: 0x093CF694,
        0x09035808: 0x09008CA4,
        0x09035874: 0x09008D10,
        0x09035898: 0x09008D34,
        0x090358D0: 0x09008D6C,
        0x08EE78E4: 0x08EDADEC,
        0x095142B8: 0x094CBD94,
        0x090352F4: 0x090085B8,
        0x090352FC: 0x090085C0,
        0x0815A066: 0x0814EC80,
        0x0815A0BA: 0x0814EC8C,
        0x0815B1D2: 0x0814EC98,
        0x0815A078: 0x0814ECA4,
        0x0815A0CC: 0x0814ECC0,
        0x0815B1A8: 0x0814EF58,
        0x0815A116: 0x0814EEB8,
        0x0815A158: 0x0814EEC8,
        0x0815A0F4: 0x0814EED8,
        0x0815A130: 0x0814EEF4,
        0x0815A176: 0x0814EF10,
        0x090451A0: 0x09012048,
        0x09EE9190: 0x09EC07D4,
        0x09045158: 0x09012000,
        0x09EE9170: 0x09EC07B4,
        0x09041F64: 0x090105A4,
        0x09EE8F20: 0x09EC0564,
        0x09041F48: 0x09010588,
        0x09EE8F08: 0x09EC054C,
        0x09041EF8: 0x09010538,
        0x09EE8EF0: 0x09EC0534,
        0x09041EA4: 0x090104E4,
        0x09EE8E60: 0x09EC04A4,
        0x09041E90: 0x090104D0,
        0x09EE8E30: 0x09EC0474,
        0x09041E78: 0x090104B8,
        0x09EE8008: 0x09EBF64C,
        0x0903C00C: 0x0900D490,
        0x09EE7F60: 0x09EBF5A4,
        0x0903BFFC: 0x0900D480,
        0x09EE7F48: 0x09EBF58C,
        0x0903BFEC: 0x0900D474,
        0x09EE7D84: 0x09EBF3C8,
        0x09EE79EC: 0x09EBF044,
        0x090381E8: 0x0900B674,
        0x09EE79B4: 0x09EBF00C,
        0x09038024: 0x0900B4B0,
        0x09EE7968: 0x09EBEFC0,
        0x09037FE4: 0x0900B470,
        0x09EE78D4: 0x09EBEF2C,
        0x09037F90: 0x0900B41C,
        0x09EE7894: 0x09EBEEEC,
        0x090362D4: 0x09009760,
        0x09EE7834: 0x09EBEE8C,
        0x09036294: 0x09009738,
        0x09EE781C: 0x09EBEE74,
        0x09036230: 0x090096D4,
        0x09EE778C: 0x09EBEDE4,
        0x090361C8: 0x0900966C,
        0x09EE7698: 0x09EBECF0,
        0x0903614C: 0x090095F0,
        0x09EE75F0: 0x09EBEC48,
        0x090359F0: 0x09008E94,
        0x09EE75D8: 0x09EBEC30,
        0x090359BC: 0x09008E60,
        0x09EE4BA0: 0x09EBC1F8,
        0x090359A0: 0x09008E44,
        0x09EE4B40: 0x09EBC198,
        0x0903596C: 0x09008E10,
        0x09EE4B28: 0x09EBC180,
        0x09035738: 0x09008A20,
        0x09EE4A68: 0x09EBC088,
        0x09035348: 0x0900860C,
        0x09EE4A2C: 0x09EBC04C,
        0x09035314: 0x090085D8,
        0x09EE49B4: 0x09EBBFD4,
        0x09034060: 0x09007324,
        0x09EE496C: 0x09EBBF8C,
    },
}

TARGET_ONLY_SYMBOLS = {
    "eu": {
        "gHadesBSmallCardPalette": 0x95468e4,
        "gRikuBSmallCardPalette": 0x9546924,
        "gRikuCSmallCardPalette": 0x9546924,
        "gRikuDSmallCardPalette": 0x9546924,
        "gAxelBSmallCardPalette": 0x9546964,
        "gLarxeneBSmallCardPalette": 0x95469a4,
        "gLarxeneCSmallCardPalette": 0x95469a4,
        "gBHpgagEFrame0": 0x08b4fb78,
        "gBHpgagEFrame1": 0x08b4fb82,
        "gBHpgagEFrame2": 0x08b4fb92,
        "gBHpgagEFrame3": 0x08b4fba2,
        "gBHpgagEFrame4": 0x08b4fbb2,
        "gBHpgagEFrame5": 0x08b4fbc2,
        "gBHpgagEFrame6": 0x08b4fbd8,
        "gBHpgagEFrame7": 0x08b4fbee,
        "gBHpgagEFrame8": 0x08b4fbf8,
        "gBHpgagEFrame9": 0x08b4fc02,
        "gBHpgagEFrame10": 0x08b4fc0c,
        "gBHpgagEFrame11": 0x08b4fc22,
        "gBHpgagEFrame12": 0x08b4fc38,
        "gBHpgagEFrame13": 0x08b4fc4e,
        "gBHpgagEAnim0": 0x08b4fc58,
        "gBHpgagEAnim1": 0x08b4fc62,
        "gBHpgagEAnim2": 0x08b4fc6c,
        "gBHpgagEAnim3": 0x08b4fc76,
        "gBHpgagEAnim4": 0x08b4fc80,
        "gSioChgCardHighlightTiles": 0x095ef388,
        "gSioChgCardBgPalettes": 0x096c934c,
        "gSioChgCardHighlightPalette": 0x096c942c,
        "gStatusNewMarkFrame0": 0x09780840,
        "gStatusNewMarkTiles": 0x0978085e,
    },
}

TARGET_EXTRA_LABELS = {
    "eu": [0x080059F4, 0x08005A1C, 0x08005ADC, 0x0805E968, 0x0805E9AC, 0x080C2740, 0x080DA830,
           0x080DA848, 0x080DA860, 0x080ABA38, 0x080ABA7C,
           0x0805E9F0, 0x0805EA44, 0x0805EC60, 0x0805ECE4],
}

TARGET_FUNC_SIZE = {
    "jp": {
        "UpdateDeckMenuStartSlideOut": 0xbc,
        "mode_sioError_0": 0x10c,
        "DrawTextSlotsUnsorted": 156,
        "DeckErrorCpInit": 260,
        "task_title_logo_2": 196,
    },
    "eu": {
        "UpdateDeckMenuOpenAddMode": 632,
        "UpdateDeckMenuOpenRemoveMode": 596,
        "CountNonSpaceChars": 32,
        "ResetGameState": 60,
        "task_btl_escape_0": 224,
        "event_seq_3": 76,
        "ContinueModeUpdate": 68,
        "DeckErrorCpInit": 260,
        "UpdateDeckMenuOpenCommands": 136,
        "ScrollGridUp": 228,
        "GetCardAtCursor": 88,
        "SetDeckMenuHandAnim": 164,
        "LoadCardNameText": 180,
        "LoadCardDescriptionText": 76,
        "ShowDeckCardPreview": 468,
        "RemoveCursorCardFromDeck": 152,
        "CheckCardDeletable": 276,
        "IsCardAtCursor": 92,
        "IsCardAt": 80,
        "FindCardInDirection": 220,
        "StockNameSora_0": 252,
        "StockNameRiku_0": 252,
        "LoadRikuCardDescriptionText": 76,
        "SioBtlOptionRecvSettings": 308,
        "mode_sio_btl_option_0": 0x1c4,
        "Deck_Yes_No_0": 0x178,
        "Deck_Clear_0": 0x174,
        "WORLDSELECT_0": 0x94,
        "Mode_Premire_0": 0x9c,
        "LVUP_EFFECT_2": 0x80,
        "LVUP_EFFECT_0": 0x1cc,
        "UpdateRikuDeckMenuLoadBgs": 0x104,
        "UpdateRikuDeckMenuLoadDeckInfo": 0x174,
        "UpdateDeckMenuCloseKeyboard": 0x8c,
        "DrawDeckCardCount": 0xe0,
        "DrawDeckCpCost": 0x1fc,
        "DrawRikuDeckCardCount": 0xc8,
        "UpdateDeckMenuSlideIn": 0x11c,
        "UpdateDeckMenuCloseRemoveMode": 0x194,
        "UpdateDeckMenuOpenDeleteMode": 0x130,
        "UpdateDeckMenuCloseDeleteMode": 0x1a0,
        "DeckMenuDestroy": 0xe8,
        "UpdateDeckMenuFadeOut": 0x30,
        "UpdateDeckMenuSlideOut": 0x8c,
        "DrawCardDescription": 0x44,
        "DrawDeckNames": 0x290,
        "UpdateDeckMenuStartSlideOut": 0xd4,
        "LookupStockPairName": 0x2e0,
        "mode_sioError_0": 0x15c,
        "mode_jiminy_0": 0x4a8,
        "LayoutMsgGlyphsPage": 0x174,
        "LayoutMsgGlyphs": 0x150,
        "mode_sio_btl_option_2": 0x14c,
        "SioBtlOptionSyncDeckNames": 0x164,
        "SioBtlOptionRecvWorld": 0x90,
        "WLogoInitWorldSelect": 192,
        "LoadGameMenuExit": 148,
        "MapMenuInitConfirm": 208,
        "MapSaveInput": 352,
        "GetFloorName": 52,
        "WorldWarpLoadCurrentName": 56,
        "MsTopHandleInput": 492,
        "MsTopDraw": 760,
        "mode_worldinspect_1": 388,
        "WorldWarpDraw": 0x390,
        "TitleMenuDrawNewGame": 232,
        "TitleMenuDrawSingle": 148,
        "task_title_lumichange_2": 152,
        "TitleMenuDrawBasic": 288,
        "TitleMenuDrawFull": 232,
        "task_title_menu_2": 232,
        "task_title_lumichange_0": 264,
        "task_title_menu_0": 672,
        "task_title_obj_0": 700,
        "ModeUpdate": 328,
        "task_bos_lst_0": 1044,
    },
}

TARGET_FUNC_ADDR = {
    "eu": {
        "GetBgMapX": 0x08005600,
        "GetBgMapY": 0x08005620,
    },
}

TARGET_DATA_SIZE = {
    "eu": {
        ("mode_sio.c", ".rodata"): 0x92,
        ("sroll_b_secn.c", ".rodata"): 0x162,
        ("mode_worldselect.c", ".rodata"): 0x189,
        ("mode_jiminy.c", ".rodata"): 0x4338,
        ("mode_chkobj.c", ".data"): 0x9A90,
        ("mode_sio.c", ".data"): 0x214,
        ("mode_lang.c", ".rodata"): 0xa,
        ("mode_movie.c", ".rodata"): 0x14CF,
        ("formation_data.c", ".data"): 0x940,
        ("mode_debug.c", ".rodata"): 0x1F4,
        ("mode_chkobj.c", ".rodata"): 0x6350,
        ("mode_chksnd.c", ".rodata"): 0x20E8,
        ("mode_dummy.c", ".rodata"): 0x19C,
        ("event_index_data.c", ".data"): 0x924,
        ("events.c", ".rodata"): 0x6f7f8,
        ("mode_textcheck.c", ".data"): 0x10,
        ("mode_deckexchange.c", ".data"): 0x240,
        ("card_deckexchange.c", ".rodata"): 0,
        ("card_deckexchange.c", ".data"): 0,
        ("card_deckmenu2_riku.c", ".data"): 0x54,
        ("card_msgwin.c", ".data"): 0xE14,
        ("card_deck_equip.c", ".data"): 0xBC,
        ("card_stock_info.c", ".data"): 0x4E4,
        ("card_level_up.c", ".data"): 0x90,
        ("card_lvup_logo.c", ".data"): 0xf0,
        ("mode_premire.c", ".data"): 0x68,
        ("card_friend_card.c", ".data"): 0xA4,
        ("card_prize_card_init.c", ".data"): 0xE4,
        ("card_worldselect.c", ".rodata"): 0x38,
        ("card_worldselect.c", ".data"): 0x2A74,
        ("card_deckmenu2.c", ".data"): 0x194,
        ("mode_lang.c", ".data"): 0x10,
        ("jiminy_data.c", ".data"): 0xd994,
        ("mode_test.c", ".rodata"): 0,
        ("mode_test.c", ".data"): 0,
        ("frd_pooh.c", ".rodata"): 0x12e,
        ("frd_pooh.c", ".data"): 0x18,
        ("card_catalog.c", ".rodata"): 0xc984,
        ("continue_ui.c", ".data"): 0x44,
        ("card_stock_info.c", ".rodata"): 0x2D2,
        ("mode_sio_dbg.c", ".data"): 0x40,
        ("mode_allmap.c", ".data"): 0x38,
        ("allmap.c", ".data"): 0xb8,
        ("title.c", ".data"): 0x9c,
        ("status.c", ".rodata"): 0x137,
        ("status.c", ".data"): 0x198,
        ("mode_worldselect.c", ".data"): 0xD8,
        ("mode_ms_top.c", ".data"): 0x74,
        ("mode_ms.c", ".data"): 0x4c,
        ("ms_charge.c", ".data"): 0x60,
        ("mode_mapinspect.c", ".rodata"): 0x24,
        ("mode_mapinspect.c", ".data"): 0xc4,
        ("mode_staffroll.c", ".data"): 0xb60,
        ("mode_chkmov.c", ".rodata"): 0x84,
        ("jiminy_inline_text_data.c", ".rodata"): 0x1c4,
        ("localized_names_eu.c", ".rodata"): 0x7fec,
        ("mode_chkmov.c", ".data"): 0x10,
        ("card_catalog.c", ".data"): 0x150,
        ("msg_localized_data.c", ".data"): 0x1075c,
        ("card_deckmenu2.c", ".rodata"): 0x510,
        ("card_prize_card_init.c", ".rodata"): 0x7ad,
        ("card_name.c", ".rodata"): 0x34,
        ("card_level_up.c", ".rodata"): 0x65,
        ("card_deckmenu2_riku.c", ".rodata"): 0x56,
        ("mode_deckexchange.c", ".rodata"): 0xa,
        ("mode_textcheck.c", ".rodata"): 0xf,
        ("mode_sio_dbg.c", ".rodata"): 0x185,
    },
    "jp": {
        ("sroll_b_secn.c", ".rodata"): 0x192,
        ("events.c", ".rodata"): 0x90438,
        ("event_index_data.c", ".data"): 0x93C,
        ("card_stock_info.c", ".data"): 0x548,
        ("card_deckmenu2.c", ".data"): 0xF8,
        ("jiminy_data.c", ".data"): 0x23d4,
        ("card_stock_info.c", ".rodata"): 0x1a62,
        ("mode_staffroll.c", ".data"): 0xba0,
        ("mode_jiminy.c", ".rodata"): 0x48a8,
        ("card_deckmenu2.c", ".rodata"): 0x646,
        ("card_name.c", ".rodata"): 0x44,
        ("card_lvup_msg.c", ".rodata"): 0x9,
        ("mode_movie.c", ".rodata"): 0x393,
    },
}

TARGET_DATA_ADDR = {
    "jp": {
        ("monsgage.c", ".rodata"): 0x0814fc14,
        ("btl_pop_cb.c", ".rodata"): 0x0814fc24,
        ("btl_exp.c", ".rodata"): 0x0814fc34,
        ("btl_vslockon.c", ".rodata"): 0x0814fc44,
        ("btl_hpoth.c", ".rodata"): 0x0814fc58,
        ("tutorial.c", ".rodata"): 0x0814fc68,
        ("mode_movie.c", ".rodata"): 0x0885df78,
        ("card_stock_info.c", ".rodata"): 0x0900ba1c,
        ("mode_staffroll.c", ".rodata"): 0x09a06558,
        ("sroll_b_crtn.c", ".rodata"): 0x09a09398,
        ("sroll_c_char.c", ".rodata"): 0x09a093ac,
        ("sroll_tmr.c", ".rodata"): 0x09a093c0,
        ("card_deckmenu2.c", ".rodata"): 0x090087ac,
        ("card_name.c", ".rodata"): 0x09009748,
        ("card_level_up.c", ".rodata"): 0x0900b438,
        ("card_lvup_msg.c", ".rodata"): 0x0900d480,
        ("card_deck_equip.c", ".rodata"): 0x0900d48c,
        ("mode_deckexchange.c", ".rodata"): 0x09010598,
        ("mode_sio_dbg.c", ".rodata"): 0x095d3420,
        ("mode_battle.c", ".rodata"): 0x081266a0,
    },
    "eu": {
        ("mode_chkmov.c", ".rodata"): 0x0812f680,
        ("mode_worldselect.c", ".data"): 0x09f847d4,
        ("mode_allmap.c", ".data"): 0x09f800a4,
        ("mode_movie.c", ".rodata"): 0x0883de0c,
        ("jiminy_inline_text_data.c", ".rodata"): 0x0888e310,
        ("localized_names_eu.c", ".rodata"): 0x0888e4d4,
        ("monsgage.c", ".rodata"): 0x088964c0,
        ("btl_pop_cb.c", ".rodata"): 0x088964d0,
        ("btl_exp.c", ".rodata"): 0x088964e0,
        ("btl_vslockon.c", ".rodata"): 0x088964f0,
        ("btl_hpoth.c", ".rodata"): 0x08896504,
        ("tutorial.c", ".rodata"): 0x08896514,
        ("mode_test.c", ".rodata"): 0x08896524,
        ("frd_pooh.c", ".rodata"): 0x08896524,
        ("lockon.c", ".rodata"): 0x08f7f15c,
        ("event_message.c", ".rodata"): 0x090cb778,
        ("card_stock_info.c", ".rodata"): 0x090d15a0,
        ("mode_wlogo.c", ".rodata"): 0x095da8ac,
        ("mode_pooh.c", ".rodata"): 0x096c934c,
        ("mode_mapinspect.c", ".rodata"): 0x09999a50,
        ("ms_shop_hosi.c", ".rodata"): 0x09999a74,
        ("mode_backupstat.c", ".rodata"): 0x09999a88,
        ("mode_staffroll.c", ".rodata"): 0x09aaf400,
        ("sroll_b_crtn.c", ".rodata"): 0x09ab2210,
        ("sroll_c_char.c", ".rodata"): 0x09ab2224,
        ("sroll_tmr.c", ".rodata"): 0x09ab2238,
        ("mode_lang.c", ".data"): 0x09f3ea64,
        ("mode_battle.c", ".data"): 0x09f3ea74,
        ("mode_chkmov.c", ".data"): 0x09f49a6c,
        ("jiminy_data.c", ".data"): 0x09f49abc,
        ("mode_test.c", ".data"): 0x09f59130,
        ("frd_pooh.c", ".data"): 0x09f59130,
        ("card_catalog.c", ".data"): 0x09f5d564,
        ("continue_ui.c", ".data"): 0x09f5d7e4,
        ("msg_localized_data.c", ".data"): 0x09f5d828,
        ("mode_ms_top.c", ".data"): 0x09f84ee8,
        ("ms_charge.c", ".data"): 0x09f84fa8,
        ("mode_mapinspect.c", ".data"): 0x09f85008,
        ("card_deckmenu2.c", ".rodata"): 0x090ce7dc,
        ("card_name.c", ".rodata"): 0x090cf648,
        ("card_level_up.c", ".rodata"): 0x090d1328,
        ("card_deck_equip.c", ".rodata"): 0x090d1884,
        ("card_deckmenu2_riku.c", ".rodata"): 0x090d1df4,
        ("mode_deckexchange.c", ".rodata"): 0x090d1e4c,
        ("mode_textcheck.c", ".rodata"): 0x090d1fb0,
        ("mode_textcheck.c", ".data"): 0x09f74600,
        ("mode_sio_dbg.c", ".rodata"): 0x095dbd58,
        ("mode_lang.c", ".rodata"): 0x08125240,
        ("mode_battle.c", ".rodata"): 0x0812524c,
    },
}

TARGET_BLOB_REGIONS = {
    "eu": (
        (0x09F49910, "rodata_registrations"),
    ),
}

INCLUDE_ASM_RE = re.compile(r'INCLUDE_ASM\("([^"]+)/([^"/]+)\.s"\)')

THUMB = """.syntax unified
	.text
{align}\t.global {name}
\t.thumb
\t.thumb_func
\t.type {name}, %function
{name}:
\t.incbin "{asset}"
.syntax divided
"""

DATA = """.syntax unified
	.text
{align}\t.global {name}
{name}:
\t.incbin "{asset}"
.syntax divided
"""

PART = """{align}	.global {name}
	.thumb
	.thumb_func
	.type {name}, %function
{name}:
	.incbin "{asset}"
"""

EMPTY = """.syntax unified
	.text
\t.global {name}
\t.thumb
\t.thumb_func
\t.type {name}, %function
{name}:
.syntax divided
"""


def mask(b):
    out = bytearray(b)
    for k in range(0, len(b) - 1, 2):
        h = struct.unpack_from("<H", b, k)[0]
        if 0xF000 <= h <= 0xFFFF:
            struct.pack_into("<H", out, k, 0)
    for k in range(0, len(b) - 3, 4):
        w = struct.unpack_from("<I", b, k)[0]
        if (w >> 24) in (0x08, 0x09, 0x02, 0x03):
            struct.pack_into("<I", out, k, 0)
    return bytes(out)


def near_identical(a, b):
    diff = sum(1 for k in range(0, len(a) - 1, 2) if a[k:k + 2] != b[k:k + 2])
    return diff <= 8 and diff * 64 <= len(a)


VERSION_IF_RE = re.compile(r"#\s*(ifdef|ifndef|if|else|elif|endif)\b(.*)")


def version_cond(rest, ver):
    tag = f"VERSION_{ver.upper()}"
    expr = re.sub(r"defined\s*\(\s*(\w+)\s*\)", r"\1", rest)
    expr = re.sub(r"defined\s+(\w+)", r"\1", expr)
    expr = expr.replace("||", " or ").replace("&&", " and ")
    expr = re.sub(r"!(?!=)", " not ", expr)
    expr = re.sub(r"\b[A-Za-z_]\w*\b",
                  lambda m: "True" if m.group(0) == tag else
                  m.group(0) if m.group(0) in ("and", "or", "not", "True", "False") else "False",
                  expr)
    try:
        return bool(eval(expr, {"__builtins__": {}}, {}))
    except Exception:
        return tag in rest


def active_lines(path, ver):
    """Source lines this version actually compiles.

    A function that only diverges in one version is guarded against that
    version alone, so the same line is C for one build and asm for another.
    Only VERSION_* conditions are interpreted; anything else stays active.
    """
    tag = f"VERSION_{ver.upper()}"
    stack = []
    for line in Path(path).read_text().splitlines():
        m = VERSION_IF_RE.match(line.strip())
        if m:
            kind, rest = m.group(1), m.group(2)
            if kind in ("ifdef", "ifndef", "if", "elif"):
                versioned = "VERSION_" in rest
                if not versioned:
                    frame = (False, True)
                elif kind == "ifndef":
                    frame = (True, tag not in rest)
                elif kind == "ifdef":
                    frame = (True, tag in rest)
                else:
                    frame = (True, version_cond(rest, ver))
                if kind == "elif" and stack:
                    stack[-1] = frame
                else:
                    stack.append(frame)
            elif kind == "else":
                if stack:
                    versioned, state = stack[-1]
                    stack[-1] = (versioned, not state if versioned else True)
            elif kind == "endif":
                if stack:
                    stack.pop()
            continue
        if all(state for _versioned, state in stack):
            yield line


def active_includes(path, ver):
    out = []
    for line in active_lines(path, ver):
        m = INCLUDE_ASM_RE.search(line)
        if m:
            out.append((m.group(1), m.group(2)))
    return out


# Region-only functions that were named after decompilation, so their names no longer
# carry their address: name -> address in that version. Matched like <version>_<address>
# definitions in the active #ifdef branch; names defined only in assembly (syscall
# stubs) are added to the rows directly.
TARGET_REGION_FUNCS = {
    "eu": {
        "ClearSystemMemory": 0x08000334,
        "DoSoftReset": 0x0800115C,
        "LoadBgTilesLz77": 0x080059D4,
        "mode_lang_0": 0x08009CD0,
        "mode_chkmov_0": 0x0800C76C,
        "HandleRikuTutorialCardInput": 0x08013190,
        "GetLocalizedString": 0x0805E924,
        "FrdPoohApplyGravity": 0x08060C44,
        "GetTextSlotsMaxLineWidth": 0x0806629C,
        "Mode_textcheck_0": 0x080AB9FC,
        "Mode_textcheck_1": 0x080ABA38,
        "Mode_textcheck_2": 0x080ABA7C,
        "SioExchangeLoopback": 0x080C24D8,
        "SioRandomPartnerSend": 0x080C273C,
        "BosUrsulaBubbleAnimChange": 0x080DA80C,
        "BosLstAnyBitScaling": 0x0810BA1C,
        "BosLstBitIsScaling": 0x0810F08C,
        "LZ77UnCompVram": 0x08116B04,
    },
}


def active_definitions(path, ver):
    pat = re.compile(r"^[A-Za-z_][A-Za-z0-9_* ]*\b((?:func_)?" + ver + r"_([0-9A-Fa-f]{8}))\(.*\)\s*\{")
    named = TARGET_REGION_FUNCS.get(ver, {})
    definition = re.compile(r"^[A-Za-z_][A-Za-z0-9_* ]*\b(\w+)\(.*\)\s*\{")
    out = []
    for line in active_lines(path, ver):
        m = pat.match(line)
        if m:
            out.append((m.group(1), int(m.group(2), 16)))
            continue
        m = definition.match(line)
        if m and m.group(1) in named:
            out.append((m.group(1), named[m.group(1)]))
    return out


def load_rows(ver):
    rows = load_funcmap(f"config/{ver}/funcmap.txt")
    for r in rows:
        at = TARGET_FUNC_ADDR.get(ver, {}).get(r[0])
        if at is not None:
            r[3] = at
            if r[4] == "absent":
                r[4] = "entry"
    found = set()
    for f in sorted(Path("src").rglob("*.c"), key=lambda path: path.name):
        for name, at in active_definitions(f, ver):
            rows.append([name, 0, 0, at, "named"])
            found.add(name)
    for name, at in TARGET_REGION_FUNCS.get(ver, {}).items():
        if name not in found:
            rows.append([name, 0, 0, at, "named"])
    return rows


def load_funcmap(path):
    rows = []
    for line in Path(path).read_text().splitlines():
        nm, ua, sz, va, how = line.split("\t")
        rows.append([nm, int(ua, 16), int(sz), None if va == "-" else int(va, 16), how])
    return rows


def complete(rows, code_end, flexible, unit_of=None, clean=None, fixed=None):
    unit_of = unit_of or {}
    clean = clean or (lambda r: True)
    fixed = fixed or {}
    n = len(rows)
    i = 0
    while i < n:
        if rows[i][3] is not None or rows[i][4] == "absent":
            i += 1
            continue
        j = i
        while j < n and rows[j][3] is None and rows[j][4] != "absent":
            j += 1
        prev = next((rows[k] for k in range(i - 1, -1, -1)
                     if rows[k][3] is not None), None)
        nxt = next((rows[k] for k in range(j, n) if rows[k][3] is not None), None)
        if prev is None:
            i = j
            continue
        begin = prev[3] + fixed.get(prev[0], prev[2])
        stop = nxt[3] if nxt is not None else code_end
        want = sum(rows[k][2] for k in range(i, j))
        span = max(0, stop - begin)
        if span == 0:
            for k in range(i, j):
                rows[k][4] = "absent"
            i = j
            continue
        for k in range(i, j):
            rows[k][3] = begin
            share = rows[k][2] if want == 0 else round(span * rows[k][2] / want / 4) * 4
            begin = min(begin + max(0, share), stop)
        i = j

    present = sorted((r for r in rows if r[3] is not None and r[4] != "absent"),
                     key=lambda r: r[3])
    size, start = {}, {}
    pos = present[0][3] if present else 0
    for k, r in enumerate(present):
        nxt = present[k + 1][3] if k + 1 < len(present) else code_end
        if r[0] in flexible:
            if r[4] in TRUSTED or (k and r[3] > pos and clean(present[k - 1])
                                   and r[4] != "-" and unit_of.get(r[0])
                                   != unit_of.get(present[k - 1][0])):
                pos = r[3]
            start[id(r)] = pos
            size[id(r)] = max(0, nxt - pos)
            pos = nxt
        elif r[2] == 0:
            start[id(r)] = r[3]
            size[id(r)] = max(0, nxt - r[3])
            pos = nxt
        else:
            nk = present[k + 1][4] if k + 1 < len(present) else None
            tsz = fixed.get(r[0], r[2])

            if (r[0] not in fixed
                    and nxt > r[3] and nk in TRUSTED
                    and r[4] in TRUSTED
                    and not clean(r)):
                tsz = nxt - r[3]
            start[id(r)] = r[3]
            size[id(r)] = tsz
            pos = r[3] + tsz
    for r in rows:
        r[3] = start.get(id(r), r[3] if r[3] is not None else 0)
        r.append(size.get(id(r), 0))
    return rows


def symbol_map(rows, us, ot, literal_loads, function_modes=None):
    function_modes = function_modes or {}
    pairs = {}
    for nm, ua, sz, va, how, vsz in rows:
        if va is None or vsz != sz or sz == 0:
            continue
        a = us[ua - ROM_BASE:ua - ROM_BASE + sz]
        b = ot[va - ROM_BASE:va - ROM_BASE + sz]
        if len(b) != sz or not near_identical(mask(a), mask(b)):
            continue
        loads = literal_loads
        if ua in function_modes:
            loads = literal_loads | trace_literal_loads(us, ua, sz, function_modes[ua])
        for w1, w2 in literal_pointer_pairs(us, ot, ua, va, sz, loads):
            pairs.setdefault(w1, {})
            pairs[w1][w2] = pairs[w1].get(w2, 0) + 1
    res = {}
    tied = {}
    for k, v in pairs.items():
        best = sorted(v.items(), key=lambda x: -x[1])
        if len(best) == 1 or best[0][1] > 2 * best[1][1]:
            res[k] = best[0][0]
        else:
            tied[k] = [w for w, _n in best]
    keys = sorted(res)
    for k, cands in tied.items():
        i = bisect.bisect_left(keys, k)
        near = [keys[j] for j in (i - 1, i) if 0 <= j < len(keys)]
        if not near:
            continue
        deltas = {res[n] - n for n in near}
        pick = [w for w in cands if w - k in deltas]
        if len(pick) == 1:
            res[k] = pick[0]
    return res


def translator(res, provenance=None):
    keys = sorted(res)
    provenance = provenance or {}

    def tr(a):
        if a < 0x02000000 or a >= 0x0E000000:
            return a, "const"
        if a in res:
            return res[a], "data" if a in provenance else "exact"
        i = bisect.bisect_left(keys, a)
        lo = keys[i - 1] if i > 0 else None
        hi = keys[i] if i < len(keys) else None
        if lo is None and hi is None:
            return None, "unknown"
        if lo is None:
            return a + res[hi] - hi, "interp"
        if hi is None or (res[lo] - lo) == (res[hi] - hi):
            return a + res[lo] - lo, "interp"
        return a + res[lo] - lo, "interp?"

    return tr


def regional_symbols(lines, tr, target_only=None):
    target_only = target_only or {}
    out, uncertain = [], []
    for line in lines:
        stripped = line.split("#")[0].strip()
        if not stripped:
            out.append(line)
            continue
        nm, a = (x.strip() for x in stripped.split("="))
        b, how = tr(int(a, 16))
        if b is None:
            b, how = int(a, 16), "unknown"
        if how in ("interp?", "unknown"):
            uncertain.append((nm, how))
        out.append(f"{nm} = {b:#010x}")
    for nm, a in target_only.items():
        out.append(f"{nm} = {a:#010x}")
    return out, uncertain


def main():
    p = argparse.ArgumentParser()
    p.add_argument("version")
    p.add_argument("code")
    p.add_argument("-q", "--quiet", action="store_true")
    args = p.parse_args()
    ver = args.version

    us = baserom.read("us", purpose="gen_version.py")
    ot = baserom.read(ver, purpose="gen_version.py")
    literal_loads = load_literal_loads("build/us/com_us.elf", ROM_BASE, CODE_HI)
    function_modes = load_function_modes("build/us/com_us.elf", ROM_BASE, CODE_HI)
    rows = load_rows(ver)

    owner = {}
    cur = None
    for line in Path("build/us/com_us.map").read_text().splitlines():
        m = re.match(r"^ \.text +0x0*8[0-9a-f]{6} +0x[0-9a-f]+ (\S+)$", line)
        if m:
            cur = m.group(1)
            continue
        if cur is None or "=" in line:
            continue
        m = re.match(r"^ +0x0*8[0-9a-f]{6} +(\S+)$", line)
        if m:
            owner.setdefault(m.group(1), cur)

    flexible = set()
    for f in sorted(Path("src").rglob("*.c"), key=lambda path: path.name):
        for tu, name in active_includes(f, ver):
            flexible.add(name)
        for name, at in active_definitions(f, ver):
            owner[name] = f"build/us/src/{f.stem}.o"

    def identical(r):
        a = us[r[1] - ROM_BASE:r[1] - ROM_BASE + r[2]]
        b = ot[r[3] - ROM_BASE:r[3] - ROM_BASE + r[2]]
        return mask(a) == mask(b)

    def clean(r):
        return r[0] in flexible or identical(r)

    anchors = TARGET_ANCHORS.get(ver, {})
    fixed = TARGET_FUNC_SIZE.get(ver, {})

    provisional = [r for r in rows if r[3] is not None]
    guess_end = provisional[-1][3] + (CODE_HI - provisional[-1][1])
    rows = complete(rows, guess_end, flexible, owner, clean, fixed)
    res = symbol_map(rows, us, ot, literal_loads, function_modes)
    res.update(anchors)
    tr = translator(res)

    code_end, how_end = tr(CODE_HI)
    if code_end != guess_end:
        rows = load_rows(ver)
        rows = complete(rows, code_end, flexible, owner, clean, fixed)
        res = symbol_map(rows, us, ot, literal_loads, function_modes)
        res.update(anchors)
        tr = translator(res)
    evidence = load_evidence("config/rom_data_evidence.yaml")
    data, provenance = data_symbol_map(evidence, ver, us, ot, res, CODE_HI, code_end)
    res.update(data)
    tr = translator(res, provenance)
    print(f"{ver}: code region {rows[0][3]:#x} .. {code_end:#x} ({how_end})")
    if data:
        print(f"  data pointer evidence: {len(data)} directly derived targets")

    present = sorted((r for r in rows if r[5]), key=lambda r: r[3])
    gaps = {}
    for a, b in zip(present, present[1:]):
        end = a[3] + a[5]
        if b[3] <= end:
            continue
        kind = "boundary" if owner.get(a[0]) != owner.get(b[0]) else "inside"
        word = struct.unpack_from("<I", ot, end - ROM_BASE)[0]
        if b[3] - end == 4 and (word >> 24) in (0x02, 0x03, 0x08, 0x09):
            kind = "pool"
        gaps[end] = (b[3] - end, kind, a, b, clean(a))

    out, uncertain = regional_symbols(
        Path("config/us/symbols.txt").read_text().splitlines(), tr,
        TARGET_ONLY_SYMBOLS.get(ver, {}))
    Path(f"config/{ver}/symbols.txt").write_text("\n".join(out) + "\n")
    print(f"  symbols.txt: {len(out)} lines, {len(uncertain)} uncertain")

    byname = {r[0]: r for r in rows}
    asm_root = Path(f"asm/{ver}/nonmatchings")
    wrote = missing = absent = 0
    kept = set()
    filled = set()
    for src in sorted(Path("src").rglob("*.c"), key=lambda path: path.name):
        for tu, name in active_includes(src, ver):
            m = re.fullmatch(f"{ver}_([0-9A-Fa-f]{{8}})", name)
            if m:
                at = int(m.group(1), 16)
                gap = gaps.get(at)
                d = asm_root / tu
                d.mkdir(parents=True, exist_ok=True)
                if gap is None:
                    (d / f"{name}.s").write_text(EMPTY.format(name=name))
                else:
                    filled.add(at)
                    cuts = ([at]
                            + [x for x in TARGET_EXTRA_LABELS.get(ver, [])
                               if at < x < at + gap[0]]
                            + [at + gap[0]])
                    body = "".join(
                        PART.format(name=name if lo == at else f"{ver}_{lo:08X}",
                                    asset=asset(ver, lo, hi),
                                    align="\t.align 2, 0\n" if lo % 4 == 0 else "")
                        for lo, hi in zip(cuts, cuts[1:]) if hi > lo)
                    (d / f"{name}.s").write_text(
                        ".syntax unified\n\t.text\n" + body + ".syntax divided\n")
                kept.add(d / f"{name}.s")
                wrote += 1
                continue
            r = byname.get(name)
            if r is None:
                missing += 1
                print(f"  missing layout for {tu}/{name}")
                continue
            if r[5] == 0:
                absent += 1
            usasm = Path(f"asm/us/nonmatchings/{tu}/{name}.s")
            d = asm_root / tu
            d.mkdir(parents=True, exist_ok=True)
            if (usasm.exists() and r[5] != 0
                    and ".include \"asm/" in usasm.read_text()):
                (d / f"{name}.s").write_text(usasm.read_text())
            else:
                tmpl = DATA if usasm.exists() and ".thumb_func" not in usasm.read_text() else THUMB
                if r[5] == 0:
                    tmpl = EMPTY
                (d / f"{name}.s").write_text(
                    tmpl.format(name=name, asset=asset(ver, r[3], r[3] + r[5]),
                                align="\t.align 2, 0\n" if r[3] % 4 == 0 and r[5] else ""))
            kept.add(d / f"{name}.s")
            wrote += 1
    stale = 0
    for old in asm_root.glob("*/*.s"):
        if old not in kept:
            old.unlink()
            stale += 1
    for d in asm_root.glob("*"):
        if d.is_dir() and not any(d.iterdir()):
            d.rmdir()
    print(f"  chunks: {wrote} written ({absent} empty), {missing} missing"
          + (f", {stale} stale removed" if stale else ""))

    Path(f"asm/{ver}").mkdir(parents=True, exist_ok=True)

    fillers = []
    extra_labels = TARGET_EXTRA_LABELS.get(ver, [])
    slack = 0
    for at, (size, kind, a, b, clean) in sorted(gaps.items()):
        unit = owner.get(a[0], "?").rsplit("/", 1)[-1][:-2]
        if kind == "boundary" and clean:
            nm = f"{ver}_{at:08X}.s"
            cuts = [at] + [x for x in extra_labels if at < x < at + size] + [at + size]
            body = "".join(
                PART.format(name=f"{ver}_{lo:08X}", asset=asset(ver, lo, hi),
                            align="\t.align 2, 0\n" if lo % 4 == 0 else "")
                for lo, hi in zip(cuts, cuts[1:]) if hi > lo)
            Path(f"asm/{ver}/{nm}").write_text(
                ".syntax unified\n\t.text\n" + body + ".syntax divided\n")
            fillers.append((at, nm))
            print(f"  filler {nm}: {size:#x} bytes after {a[0]} ({unit})")
        elif at in filled:
            pass
        elif kind == "pool":
            print(f"  gap {size:#x} at {at:#x} inside {unit} after {a[0]}: a pool word,"
                  f" so {a[0]} is longer in {ver}")
        elif clean:
            print(f"  gap {size:#x} at {at:#x} inside {unit} after {a[0]} before {b[0]}:"
                  f" needs INCLUDE_ASM(\"{unit}/{ver}_{at:08X}.s\")")
        else:
            slack += size
    if slack:
        print(f"  slack after divergent functions: {slack:#x} bytes")
    fresh = {nm for _at, nm in fillers}
    for old in Path(f"asm/{ver}").glob(f"{ver}_*.s"):
        if old.name not in fresh:
            old.unlink()

    def unit_key(name):
        if name.startswith("@"):
            arch, member = name[1:].split(":")
            obj = f"build/us/lib/{arch}/{member}"
        elif name.endswith(".c"):
            obj = f"build/us/src/{name[:-2]}.o"
        elif name.endswith(".s"):
            obj = f"build/us/asm/{name[:-2]}.o"
        else:
            return None
        named = sorted(r[3] for r in rows
                       if owner.get(r[0]) == obj and r[5] and r[4] == "named")
        addrs = named or sorted(r[3] for r in rows
                                if owner.get(r[0]) == obj and r[5])
        if not addrs and any(owner.get(r[0]) == obj for r in rows):
            return "absent"
        return addrs[len(addrs) // 2] if addrs else None

    placed = re.compile(r"^ (\.[\w.]+)? +0x([0-9a-f]+) +0x([0-9a-f]+) build/us/src/(\S+)\.o$")
    spans, sections = {}, {}
    pending = None
    for line in Path("build/us/com_us.map").read_text().splitlines():
        m = re.fullmatch(r" (\.[\w.]+)", line)
        if m:
            pending = m.group(1)
            continue
        m = placed.match(line)
        if not m or not int(m.group(3), 16):
            continue
        section = m.group(1) or pending
        pending = None
        unit = m.group(4) + ".c"
        sections.setdefault(unit, set()).add(section)
        if section in (".rodata", ".data"):
            spans[(unit, section)] = (int(m.group(2), 16), int(m.group(3), 16))

    def data_only(nm):
        placed_in = sections.get(nm, set())
        return bool(placed_in) and placed_in <= {".rodata", ".data"}

    us_units = [line.split()[0] for line in Path("config/us/units.txt").read_text().splitlines()
                if line.strip() and not line.startswith("#")]
    manifests = [manifest for manifest in assetgen.load_manifests()
                 if any(obj["name"] in us_units for obj in manifest.objects.get("us", []))
                 or (not manifest.objects.get("us") and manifest.objects.get(ver))]
    generated = {obj["name"] for manifest in manifests for objects in manifest.objects.values() for obj in objects}
    text_pools = [pool for pool in textgen.load_pools()
                  if pool.object("us") and pool.object("us")["name"] in us_units
                  or not pool.object("us") and pool.object(ver)]
    generated |= {obj["name"] for pool in text_pools for obj in pool.objects.values()}
    head, body, cdata, blobs, placed = [], [], [], [], set()
    for manifest in manifests:
        for obj in manifest.objects.get(ver, []):
            cdata.append((obj["start"], obj["end"] - obj["start"], f"{obj['name']}(.rodata)"))
            if "data_start" in obj:
                cdata.append((obj["data_start"], obj["data_end"] - obj["data_start"], f"{obj['name']}(.data)"))
    for pool in text_pools:
        obj = pool.object(ver)
        if obj is not None:
            cdata.append((obj["start"], obj["end"] - obj["start"], f"{obj['name']}(.rodata)"))
    for line in Path("config/us/units.txt").read_text().splitlines():
        t = line.strip()
        if not t or t.startswith("#"):
            head.append(line)
            continue
        nm = t.split()[0]
        if nm in generated:
            continue
        if nm == "transform_veneers.s":
            size = validate_transform_veneers(ot, code_end, byname["func_08109AAC"][3])
            cdata.append((code_end, size, "transform_veneers.s(.text)"))
            continue
        if nm.endswith(".s") and (Path("asm/us") / nm).exists():
            blobs.append(nm)
            continue
        if nm.endswith(".c"):
            for sec in (".rodata", ".data"):
                key = nm, sec
                if key not in spans:
                    continue
                lo, size = spans[key]
                here = TARGET_DATA_ADDR.get(ver, {}).get(key)
                if here is None:
                    here, _ = tr(lo)
                size = TARGET_DATA_SIZE.get(ver, {}).get(key, size)
                cdata.append((here, size, f"{nm}({sec})"))
                placed.add(key)
            if data_only(nm):
                continue
        key = unit_key(nm)
        if key is None and nm.endswith(".s"):
            head.append(line)
            continue
        body.append((key, line))
    for key, here in TARGET_DATA_ADDR.get(ver, {}).items():
        if key not in placed:
            cdata.append((here, TARGET_DATA_SIZE.get(ver, {})[key], f"{key[0]}({key[1]})"))
    own = []
    for src in sorted(Path("src").rglob("*.c"), key=lambda path: path.name):
        key = None if src.name in us_units else unit_key(src.name)
        if isinstance(key, int):
            own.append((key, src.name))
            print(f"  unit added: {src.name}")
    dropped = [l for k, l in body if k == "absent"]
    for l in dropped:
        print(f"  unit dropped: {l}")
    body = [(k, l) for k, l in body if k != "absent"]
    body += [(at, nm) for at, nm in fillers]

    def rank(kl):
        return kl[0] is None, kl[0] or 0

    ranked = sorted(body, key=rank)
    moved = [l for (k, l), (k2, l2) in zip(body, ranked) if l != l2]
    if moved:
        print(f"  units reordered: {len(moved)}")
    ordered = [l for k, l in sorted(ranked + own, key=rank)]

    pad = len(ot)

    while pad > 0 and ot[pad - 1] == 0xFF:
        pad -= 1
    found = []
    incbin = re.compile(r'\.incbin\s+"assets/us/([0-9A-F]{8})-([0-9A-F]{8})\.bin"')
    for nm in blobs:
        src = Path("asm/us") / nm
        m = incbin.search(src.read_text())
        if not m:
            raise SystemExit(f"error: {src} is a US data unit with no assets/us incbin to anchor its offset")
        off = int(m.group(1), 16) - ROM_BASE
        base = nm[:-2]

        if base.startswith(("asset_us_", "padding_us_")):
            continue
        pat = us[off:off + 64]
        i = ot.find(pat)
        how = "content"

        if i < 0 or ot.find(pat, i + 1) >= 0:
            i, how = tr(ROM_BASE + off)[0], "interp"

            if i is None:
                continue
            i -= ROM_BASE
        found.append((ROM_BASE + i, base, how))
    found.extend((address, name, "explicit")
                 for address, name in TARGET_BLOB_REGIONS.get(ver, ()))
    regions = []
    last = None

    for here, base, how in sorted(found, key=lambda item: (item[0], item[2] != "explicit", item[1])):
        if last is not None and here <= last:
            print(f"  data region {base} dropped, not monotone ({how})")
            continue
        last = here
        if regions and base == regions[-1][1]:
            continue
        regions.append((here, base))

    used = {}
    blob_names = set()
    reserved = {f"{base}.s" for _here, base in regions}

    def stem(line):
        return line.split()[0].split("(")[0].rsplit(".", 1)[0]

    def blob(lo, hi, after=None, before=None):
        out = []
        cuts = [a for a, _n in regions if lo < a < hi]
        for a, b in zip([lo] + cuts, cuts + [hi]):
            if a >= b:
                continue
            k = bisect.bisect_right([x[0] for x in regions], a) - 1
            base = regions[k][1] if k >= 0 else "data"
            used[base] = used.get(base, 0) + 1
            nm = f"{base}.s"
            if used[base] > 1:
                names = []
                if b == hi and before:
                    names.append(f"{stem(before)}_rodata.s")
                if a == lo and after:
                    names.append(f"{stem(after)}_tail.s")
                names = [n for n in names if n not in blob_names and n not in reserved]
                if not names:
                    raise ValueError(f"no name for the {ver} blob at {a:#x} after {base}")
                nm = names[0]
            if nm in blob_names:
                raise ValueError(f"duplicate regional blob filename: {nm}")
            blob_names.add(nm)
            out.append((nm, a, b))
        return out

    tail, bounds = [], []
    pos = code_end
    prev = None
    for lo, size, line in sorted(cdata):
        if pos < lo < pos + 4 and lo % 4 == 0 and not any(ot[pos - ROM_BASE:lo - ROM_BASE]):
            pos = lo
        if lo > pos:
            for nm, a, b in blob(pos, lo, prev, line):
                bounds.append((nm, a, b))
                tail.append(f"{nm}(.rodata)")
            pos = lo
        tail.append(line)
        prev = line
        pos += size
    for nm, a, b in blob(pos, ROM_BASE + pad, prev):
        bounds.append((nm, a, b))
        tail.append(f"{nm}(.rodata)")
    aligned, kept = set(), []
    for k, (nm, a, b) in enumerate(bounds):
        after = bounds[k + 1] if k + 1 < len(bounds) else None
        if (after is not None and after[1] == b and b - a < 4 and b % 4 == 0
                and not any(ot[a - ROM_BASE:b - ROM_BASE])):
            aligned.add(after[0])
            tail.remove(f"{nm}(.rodata)")
            continue
        kept.append((nm, a, b))
    bounds = kept
    entries, line_of = [], {}
    for line in head + ordered + tail:
        t = line.strip()
        if not t or t.startswith("#"):
            continue
        nm, section = t.split()[0], ".text"
        if nm.endswith(")"):
            nm, _, spec = nm.partition("(")
            section = spec[:-1]
        else:
            line_of[nm] = t
        entries.append((nm, section))
    units = [line_of.get(nm, nm) for nm in link_order(entries)]

    for nm, lo, hi in bounds:
        Path(f"asm/{ver}/{nm}").write_text(
            blob_source(ver, lo, hi, ot[lo - ROM_BASE:hi - ROM_BASE], nm in aligned))
    fresh = {nm for nm, _lo, _hi in bounds}
    for old in Path(f"asm/{ver}").glob("*.s"):
        if old.name not in fresh and ".global data_" in old.read_text():
            old.unlink()
    if not any(Path(f"asm/{ver}").iterdir()):
        Path(f"asm/{ver}").rmdir()
    if bounds:
        print("  " + "  ".join(f"{nm} {lo:#x}..{hi:#x}" for nm, lo, hi in bounds))

    Path(f"config/{ver}/units.txt").write_text("\n".join(units) + "\n")
    print(f"  units.txt: {len(units)} entries")
    if not args.quiet:
        for nm, how in uncertain:
            print(f"    {how:9s} {nm}")


if __name__ == "__main__":
    main()
