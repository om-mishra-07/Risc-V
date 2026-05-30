# Instruction Flow Examples

## ADDI x1, x0, 10

Single-cycle:

1. PC fetches the instruction from instruction memory.
2. Control decodes an I-type ALU operation.
3. Immediate generator produces `10`.
4. ALU adds `x0` and the immediate.
5. Writeback stores the result into `x1`.

Pipeline:

1. IF fetches the instruction.
2. ID reads `x0`, decodes `addi`, and builds the immediate.
3. EX computes `0 + 10`.
4. MEM passes the ALU result through.
5. WB writes `10` into `x1`.

## LW x3, 512(x0)

1. Decode marks the instruction as a load and selects immediate addressing.
2. EX computes the byte address `0x200`.
3. MEM reads the data memory and applies sign/zero extension according to `funct3`.
4. WB writes the loaded value into `x3`.

## BEQ x10, x3, done

1. Decode marks the instruction as a branch and generates the B-type offset.
2. EX compares the forwarded versions of `x10` and `x3`.
3. If equal, the branch unit selects `pc + imm` as the next PC.
4. In the pipeline core, IF/ID is flushed and `flush_count` increments.