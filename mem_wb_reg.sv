module mem_wb_reg (
  input  logic                 clk,
  input  logic                 rst,
  input  logic                 valid_in,
  input  riscv_pkg::control_t  ctrl_in,
  input  logic [31:0]          pc4_in,
  input  logic [31:0]          imm_in,
  input  logic [31:0]          mem_data_in,
  input  logic [31:0]          alu_result_in,
  input  logic [4:0]           rd_in,
  output logic                 valid_out,
  output riscv_pkg::control_t  ctrl_out,
  output logic [31:0]          pc4_out,
  output logic [31:0]          imm_out,
  output logic [31:0]          mem_data_out,
  output logic [31:0]          alu_result_out,
  output logic [4:0]           rd_out
);

  always_ff @(posedge clk or posedge rst) begin
    if (rst) begin
      valid_out      <= 1'b0;
      ctrl_out       <= '0;
      pc4_out        <= '0;
      imm_out        <= '0;
      mem_data_out   <= '0;
      alu_result_out <= '0;
      rd_out         <= '0;
    end else begin
      valid_out      <= valid_in;
      ctrl_out       <= ctrl_in;
      pc4_out        <= pc4_in;
      imm_out        <= imm_in;
      mem_data_out   <= mem_data_in;
      alu_result_out <= alu_result_in;
      rd_out         <= rd_in;
    end
  end

endmodule
