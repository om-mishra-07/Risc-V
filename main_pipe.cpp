#include "Vcpu_pipeline_top.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

#include <cstdlib>
#include <cstring>

int main(int argc, char** argv) {
  Verilated::commandArgs(argc, argv);
  Verilated::traceEverOn(true);

  bool trace_en = false;
  vluint64_t max_cycles = 400;

  for (int arg_idx = 1; arg_idx < argc; ++arg_idx) {
    if (std::strcmp(argv[arg_idx], "--trace-en") == 0) {
      trace_en = true;
    } else if (std::strncmp(argv[arg_idx], "--max-cycles=", 13) == 0) {
      max_cycles = static_cast<vluint64_t>(std::strtoull(argv[arg_idx] + 13, nullptr, 10));
    }
  }

  auto* dut = new Vcpu_pipeline_top;
  auto* trace = new VerilatedVcdC;
  dut->trace(trace, 5);
  trace->open("waveforms/cpu_pipeline_wave.vcd");

  dut->clk = 0;
  dut->rst = 1;
  dut->trace_en = trace_en;
  dut->dump_en = 0;
  dut->debug_reg_sel = 11;
  dut->debug_mem_addr = 0x100;

  vluint64_t sim_time = 0;

  while (!Verilated::gotFinish() && (sim_time / 10) < max_cycles) {
    if (sim_time == 40) {
      dut->rst = 0;
    }

    dut->clk = !dut->clk;
    dut->eval();
    trace->dump(sim_time);

    if (dut->done) {
      dut->dump_en = 1;
      dut->eval();
      break;
    }

    sim_time += 5;
  }

  if (dut->done && dut->debug_reg_data == 55 && dut->debug_mem_data == 55) {
    VL_PRINTF("[PASS] Verilator pipeline run complete. x11=%u mem[0x100]=%u cycles=%llu stalls=%llu flushes=%llu\n",
              dut->debug_reg_data, dut->debug_mem_data,
              static_cast<unsigned long long>(dut->cycle_count),
              static_cast<unsigned long long>(dut->stall_count),
              static_cast<unsigned long long>(dut->flush_count));
  } else {
    VL_PRINTF("[FAIL] Verilator pipeline run mismatch. done=%u x11=%u mem[0x100]=%u cycles=%llu\n",
              dut->done, dut->debug_reg_data, dut->debug_mem_data,
              static_cast<unsigned long long>(dut->cycle_count));
  }

  trace->close();
  delete trace;
  delete dut;
  return 0;
}