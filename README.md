# RV32I RISC-V CPU Project

Professional SystemVerilog RISC-V CPU project for ASIC RTL, computer architecture, and verification portfolios. The repository includes a synthesizable single-cycle RV32I core, a pipeline-ready 5-stage version with hazard handling, self-checking testbenches, and simulator flows for Verilator, Icarus Verilog, and VCS.

## Features

- RV32I integer ISA support for arithmetic, logical, load/store, branch, immediate, JAL, and JALR instructions
- Clean modular RTL split into PC, ALU, register file, memories, decode, immediate generation, and branch logic
- Single-cycle reference core for easy bring-up and architectural understanding
- 5-stage pipeline with IF/ID, ID/EX, EX/MEM, MEM/WB registers
- Load-use hazard detection and EX/MEM + MEM/WB forwarding
- Performance counters for cycles, retired instructions, stalls, and flushes
- Debug visibility with instruction tracing, register dump support, and memory inspection
- Self-checking Fibonacci demonstration that writes `55` to `x11` and `mem[0x100]`

## Directory Structure

```text
riscV/
├── rtl/                  # synthesizable RTL modules
├── tb/                   # SystemVerilog self-checking testbenches
├── sim/                  # Verilator C++ harnesses
├── scripts/              # helper scripts and GTKWave setup
├── docs/                 # architecture and setup notes
├── waveforms/            # generated VCD files
├── Makefile
└── run.sh
```

## Architecture Snapshot

```text
               +----------------------+
 PC ---------->| Instruction Memory   |---- instruction ----+
 ^             +----------------------+                     |
 |                                                         v
 |        +----------------------+      +-----------------------+
 |        | Branch / Jump Unit   |<-----| Control + Immediate   |
 |        +----------------------+      +-----------------------+
 |                    ^                             |
 |                    |                             v
 |             +-------------+          +----------------------+
 |             | Register    |--------->| ALU                  |
 |             | File        |<---------| Writeback Mux        |
 |             +-------------+          +----------------------+
 |                                                  |
 +--------------------------------------------------v
                                            +---------------+
                                            | Data Memory   |
                                            +---------------+
```

## Quick Start

```bash
chmod +x run.sh scripts/assemble.py
chmod +x demo.sh
./run.sh lint
./run.sh sc
./run.sh pipe
./run.sh trace_sc
./run.sh trace_pipe
./demo.sh
```

If you prefer Icarus Verilog:

```bash
./run.sh iverilog_sc
./run.sh iverilog_pipe
```

## Validated Demo Output

Single-cycle flow:

```text
[PASS] Verilator single-cycle run complete. x11=55 mem[0x100]=55 cycles=61
```

Pipeline flow:

```text
[PASS] Verilator pipeline run complete. x11=55 mem[0x100]=55 cycles=85 stalls=0 flushes=11
```

Icarus Verilog also passes the same Fibonacci demo in both single-cycle and pipeline modes.

## Trace Demo

The repo includes trace-enabled demo modes that print instruction-by-instruction execution.

```bash
./run.sh trace_sc
./run.sh trace_pipe
./demo.sh
```

`./demo.sh` runs both trace modes and prints a short curated excerpt suitable for a live portfolio demo.

## Visual Dashboard

The repository includes a browser dashboard for trace and performance summary visualization.

```bash
./demo.sh
python3 -m http.server 8000
```

Then open:

```text
http://localhost:8000/dashboard/
```

The dashboard loads log files from `demo_logs/` and shows:

- side-by-side KPI cards for single-cycle and pipeline runs
- PC progression timeline for both flows
- register writeback frequency bars
- recent trace rows with branch, stall, and flush indicators

Single-cycle trace excerpt:

```text
[SC-TRACE] pc=0x00000000 instr=0x00000093 rd=x1 wb=0x00000000 branch=0 target=0x00000004 z=1 n=0 ov=0
[SC-TRACE] pc=0x00000004 instr=0x00100113 rd=x2 wb=0x00000001 branch=0 target=0x00000008 z=0 n=0 ov=0
[SC-TRACE] pc=0x00000014 instr=0x002085b3 rd=x11 wb=0x00000037 branch=0 target=0x00000018 z=0 n=0 ov=0
[SC-TRACE] pc=0x00000028 instr=0x10b02023 rd=x0 wb=0x00000100 branch=0 target=0x0000002c z=0 n=0 ov=0
```

Pipeline trace excerpt:

```text
[PIPE-TRACE] pc=0x00000014 rd=x11 wb=0x00000001 stall=0 flush=0 z=0 n=0 ov=0
[PIPE-TRACE] pc=0x0000001c rd=x2 wb=0x00000001 stall=0 flush=1 z=1 n=0 ov=0
[PIPE-TRACE] pc=0x00000014 rd=x11 wb=0x00000037 stall=0 flush=0 z=0 n=0 ov=0
[PIPE-TRACE] pc=0x0000002c rd=x31 wb=0x00000001 stall=0 flush=0 z=1 n=0 ov=0
```

This is a good live demo for interviews because it shows the PC progression, writeback results, branch redirects, and the final completion signal.

## Resume Value

This repo demonstrates:

- modular synthesizable RTL design
- architectural tradeoff awareness through single-cycle versus pipelined implementations
- hazard handling and verification thinking
- simulator bring-up, waveform capture, and debug instrumentation
- project organization suitable for public GitHub presentation

See the docs folder for deeper explanation of the architecture and instruction flow.