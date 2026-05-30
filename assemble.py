#!/usr/bin/env python3
"""Minimal RV32I(+M subset) assembler for demo programs in this repository.

Supported mnemonics: add, sub, mul, and, or, xor, sll, srl, slt, addi,
slli, lw, lb, lh, sw, beq, jal.
"""

from __future__ import annotations

import argparse
from pathlib import Path


REG_MAP = {f"x{i}": i for i in range(32)}


def reg(name: str) -> int:
    return REG_MAP[name.strip()]


def enc_r(f7: int, rs2: int, rs1: int, f3: int, rd: int, opc: int = 0x33) -> int:
    return (f7 << 25) | (rs2 << 20) | (rs1 << 15) | (f3 << 12) | (rd << 7) | opc


def enc_i(imm: int, rs1: int, f3: int, rd: int, opc: int = 0x13) -> int:
    imm &= 0xFFF
    return (imm << 20) | (rs1 << 15) | (f3 << 12) | (rd << 7) | opc


def enc_s(imm: int, rs2: int, rs1: int, f3: int, opc: int = 0x23) -> int:
    imm &= 0xFFF
    return ((imm >> 5) << 25) | (rs2 << 20) | (rs1 << 15) | (f3 << 12) | ((imm & 0x1F) << 7) | opc


def enc_b(imm: int, rs2: int, rs1: int, f3: int, opc: int = 0x63) -> int:
    imm &= 0x1FFF
    return (((imm >> 12) & 1) << 31) | (((imm >> 5) & 0x3F) << 25) | (rs2 << 20) | (rs1 << 15) | \
           (f3 << 12) | (((imm >> 1) & 0xF) << 8) | (((imm >> 11) & 1) << 7) | opc


def enc_j(imm: int, rd: int, opc: int = 0x6F) -> int:
    imm &= 0x1FFFFF
    return (((imm >> 20) & 1) << 31) | (((imm >> 1) & 0x3FF) << 21) | (((imm >> 11) & 1) << 20) | \
           (((imm >> 12) & 0xFF) << 12) | (rd << 7) | opc


def parse_mem_operand(token: str) -> tuple[int, int]:
    imm_str, reg_str = token.split("(")
    return int(imm_str, 0), reg(reg_str.rstrip(")"))


def assemble_line(line: str, labels: dict[str, int], pc: int) -> int:
    text = line.replace(",", " ").split()
    mnemonic = text[0]

    if mnemonic == "addi":
      return enc_i(int(text[3], 0), reg(text[2]), 0b000, reg(text[1]))
    if mnemonic == "slli":
      return enc_i(int(text[3], 0), reg(text[2]), 0b001, reg(text[1]))
    if mnemonic == "lw":
      imm, rs1 = parse_mem_operand(text[2])
      return enc_i(imm, rs1, 0b010, reg(text[1]), 0x03)
    if mnemonic == "lb":
      imm, rs1 = parse_mem_operand(text[2])
      return enc_i(imm, rs1, 0b000, reg(text[1]), 0x03)
    if mnemonic == "lh":
      imm, rs1 = parse_mem_operand(text[2])
      return enc_i(imm, rs1, 0b001, reg(text[1]), 0x03)
    if mnemonic == "sw":
      imm, rs1 = parse_mem_operand(text[2])
      return enc_s(imm, reg(text[1]), rs1, 0b010)
    if mnemonic == "beq":
      target = labels[text[3]]
      return enc_b(target - pc, reg(text[2]), reg(text[1]), 0b000)
    if mnemonic == "jal":
      target = labels[text[2]]
      return enc_j(target - pc, reg(text[1]))

    r_ops = {
        "add": (0x00, 0b000),
        "sub": (0x20, 0b000),
      "mul": (0x01, 0b000),
        "and": (0x00, 0b111),
        "or":  (0x00, 0b110),
        "xor": (0x00, 0b100),
        "sll": (0x00, 0b001),
        "srl": (0x00, 0b101),
        "slt": (0x00, 0b010),
    }
    if mnemonic in r_ops:
      f7, f3 = r_ops[mnemonic]
      return enc_r(f7, reg(text[3]), reg(text[2]), f3, reg(text[1]))

    raise ValueError(f"Unsupported instruction: {line}")


def assemble(source: str) -> list[int]:
    raw_lines = []
    labels: dict[str, int] = {}
    pc = 0

    for original in source.splitlines():
      line = original.split("#", 1)[0].strip()
      if not line:
        continue
      if line.endswith(":"):
        labels[line[:-1]] = pc
        continue
      raw_lines.append((pc, line))
      pc += 4

    return [assemble_line(line, labels, pc) for pc, line in raw_lines]


def main() -> None:
    parser = argparse.ArgumentParser(description="Assemble a small subset of RV32I into a .hex file")
    parser.add_argument("input", type=Path)
    parser.add_argument("output", type=Path)
    args = parser.parse_args()

    machine_words = assemble(args.input.read_text())
    args.output.write_text("\n".join(f"{word:08x}" for word in machine_words) + "\n")


if __name__ == "__main__":
    main()