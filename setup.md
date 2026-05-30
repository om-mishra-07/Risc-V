# Setup and Simulation

## Recommended Tools

- Verilator for linting and high-speed simulation
- GTKWave for VCD viewing
- Icarus Verilog for a lightweight pure-Verilog testbench flow

## macOS Install

```bash
brew install verilator gtkwave icarus-verilog
```

## Simulation Commands

```bash
./run.sh lint
./run.sh sc
./run.sh pipe
./run.sh trace_sc
./run.sh trace_pipe
./run.sh iverilog_sc
./run.sh iverilog_pipe
```

## Output Files

- `waveforms/cpu_wave.vcd`: single-cycle testbench waveform dump
- `waveforms/cpu_pipeline_wave.vcd`: pipelined core waveform dump

## GTKWave

```bash
make wave_sc
make wave_pipe
```

## What To Look For

- PC increments by 4 between sequential instructions.
- The branch at the Fibonacci loop redirects control back to the loop body.
- Register `x11` eventually becomes `55`.
- Data memory location `0x100` stores `0x00000037`.
- `x31` becomes `1` to signal test completion.
- The trace modes show branch flushes in the pipelined core and explicit writeback values in both cores.