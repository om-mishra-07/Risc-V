# Pipeline Notes

## Stage Responsibilities

IF fetches the next instruction using the current PC. ID decodes the instruction and reads operands. EX calculates the ALU result or branch decision. MEM services loads and stores. WB commits results back to the register file.

## Hazard Detection

The `hazard_unit` handles the classic load-use case. If the instruction in ID depends on a destination register currently being loaded in EX, the unit stalls fetch and decode while injecting a bubble into ID/EX.

## Forwarding

The `forwarding_unit` selects the newest available operand value:

- `2'b10`: forward from EX/MEM
- `2'b01`: forward from MEM/WB
- `2'b00`: use register values stored in ID/EX

This prevents unnecessary stalls for common ALU dependency chains.

## Branch Handling

Branches are resolved in EX. The current implementation uses an always-not-taken policy and includes a small branch predictor placeholder table to show how future work could attach prediction metadata without rewriting the rest of the pipeline.

## Expected Behavior

- ALU dependency chains should execute without extra bubbles due to forwarding.
- Load-use dependencies should incur one stall.
- Taken branches and jumps flush younger instructions and increment `flush_count`.