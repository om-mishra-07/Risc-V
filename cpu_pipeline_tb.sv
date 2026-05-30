`timescale 1ns/1ps

module cpu_pipeline_tb;
  localparam PROGRAM = "tb/programs/fibonacci.hex";
  localparam int MAX_CYCLES = 300;

  logic clk;
  logic rst;
  logic trace_en;
  logic dump_en;
  logic [4:0] debug_reg_sel;
  logic [31:0] debug_mem_addr;
  logic [31:0] debug_reg_data;
  logic [31:0] debug_mem_data;
  logic [31:0] current_pc;
  logic [31:0] current_instruction;
  logic done;
  logic [63:0] cycle_count;
  logic [63:0] instr_count;
  logic [63:0] stall_count;
  logic [63:0] flush_count;
  int cycles;

  cpu_pipeline_top #(
    .IMEM_INIT_FILE(PROGRAM)
  ) dut (
    .clk               (clk),
    .rst               (rst),
    .trace_en          (trace_en),
    .dump_en           (dump_en),
    .debug_reg_sel     (debug_reg_sel),
    .debug_mem_addr    (debug_mem_addr),
    .debug_reg_data    (debug_reg_data),
    .debug_mem_data    (debug_mem_data),
    .current_pc        (current_pc),
    .current_instruction(current_instruction),
    .done              (done),
    .cycle_count       (cycle_count),
    .instr_count       (instr_count),
    .stall_count       (stall_count),
    .flush_count       (flush_count)
  );

  initial clk = 1'b0;
  always #5 clk = ~clk;

  initial begin
    rst = 1'b1;
    trace_en = 1'b0;
    dump_en = 1'b0;
    debug_reg_sel = 5'd11;
    debug_mem_addr = 32'h00000100;
    cycles = 0;

    $dumpfile("waveforms/cpu_pipeline_wave.vcd");
    $dumpvars(0, cpu_pipeline_tb);

    repeat (4) @(posedge clk);
    rst = 1'b0;

    while (!done && cycles < MAX_CYCLES) begin
      @(posedge clk);
      cycles++;
    end

    dump_en = 1'b1;
    @(posedge clk);
    dump_en = 1'b0;

    if (done && (debug_reg_data == 32'd55) && (debug_mem_data == 32'd55)) begin
      $display("[PASS] Pipeline Fibonacci: x11=%0d mem[0x100]=%0d cycles=%0d instr=%0d stalls=%0d flushes=%0d",
               debug_reg_data, debug_mem_data, cycle_count, instr_count, stall_count, flush_count);
      $finish(0);
    end

    $display("[FAIL] Pipeline result mismatch: done=%0b x11=%0d mem[0x100]=%0d cycles=%0d stalls=%0d flushes=%0d",
             done, debug_reg_data, debug_mem_data, cycle_count, stall_count, flush_count);
    $finish(1);
  end

endmodule