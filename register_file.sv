module register_file #(
  parameter int XLEN = 32,
  parameter int REG_COUNT = 32
) (
  input  logic            clk,
  input  logic            rst,
  input  logic            write_enable,
  input  logic [4:0]      rs1_addr,
  input  logic [4:0]      rs2_addr,
  input  logic [4:0]      rd_addr,
  input  logic [XLEN-1:0] write_data,
  input  logic [4:0]      debug_addr,
  output logic [XLEN-1:0] rs1_data,
  output logic [XLEN-1:0] rs2_data,
  output logic [XLEN-1:0] debug_data,
  output logic [XLEN-1:0] x31_data
);

  logic [XLEN-1:0] regs [0:REG_COUNT-1];
  integer idx;

  always_ff @(posedge clk or posedge rst) begin
    if (rst) begin
      for (idx = 0; idx < REG_COUNT; idx++) begin
        regs[idx] <= '0;
      end
    end else if (write_enable && (rd_addr != '0)) begin
      regs[rd_addr] <= write_data;
    end
  end

  assign rs1_data = (rs1_addr == '0) ? '0 : regs[rs1_addr];
  assign rs2_data = (rs2_addr == '0) ? '0 : regs[rs2_addr];
  assign debug_data = (debug_addr == '0) ? '0 : regs[debug_addr];
  assign x31_data = regs[31];

  task automatic dump_regs();
    integer reg_idx;
    begin
      $display("---- Register File Dump ----");
      for (reg_idx = 0; reg_idx < REG_COUNT; reg_idx++) begin
        $display("x%0d = 0x%08h", reg_idx, regs[reg_idx]);
      end
    end
  endtask

endmodule
