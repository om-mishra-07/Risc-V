# Architecture Overview

## Core Datapath

The single-cycle CPU executes one instruction per cycle by combining fetch, decode, execute, memory, and writeback in the same clock period. This keeps the control path easy to understand and makes the design ideal for first-pass verification.

Primary blocks:

- Program Counter: holds the current instruction address and steps by 4 unless a branch or jump redirects execution.
- Instruction Memory: stores 32-bit instructions and is initialized from a `.hex` program image.
- Register File: provides two asynchronous read ports and one synchronous write port. Register `x0` is hardwired to zero.
- Control Unit: decodes `opcode`, `funct3`, and `funct7` into control signals and ALU operations.
- Immediate Generator: reconstructs I, S, B, U, and J immediates with correct sign extension.
- ALU: performs arithmetic, logic, shifting, and comparison operations.
- Branch Unit: resolves branch conditions and computes branch/jump target addresses.
- Data Memory: supports byte, halfword, and word loads/stores.

## Pipelined Datapath

The pipeline version splits work across five stages:

1. IF: fetch instruction from instruction memory.
2. ID: decode instruction, read register file, and generate immediate/control signals.
3. EX: perform ALU work and branch decision.
4. MEM: access data memory for loads and stores.
5. WB: select the final writeback result.

Pipeline registers isolate stage timing and make the design closer to industrial RTL structure.

## Performance Counters

- `cycle_count`: total elapsed cycles.
- `instr_count`: retired instructions or writeback events.
- `stall_count`: hazard-induced bubbles in the pipeline core.
- `flush_count`: wrong-path instructions removed after taken branches or jumps.

## Debug Support

- runtime instruction trace via `$display`
- register dump task inside the register file
- data memory dump task for post-run inspection
- debug ports to read a selected register and memory address from the testbench