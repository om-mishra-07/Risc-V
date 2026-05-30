module id_ex_reg (
  input  logic                 clk,
  input  logic                 rst,
  input  logic                 flush,
  input  logic                 valid_in,
  input  riscv_pkg::control_t  ctrl_in,
  input  logic [31:0]          pc_in,
  input  logic [31:0]          rs1_data_in,
  input  logic [31:0]          rs2_data_in,
  input  logic [31:0]          imm_in,
  input  logic [4:0]           rs1_in,
  input  logic [4:0]           rs2_in,
  input  logic [4:0]           rd_in,
  input  logic [2:0]           funct3_in,
  input  logic [6:0]           opcode_in,
  output logic                 valid_out,
  output riscv_pkg::control_t  ctrl_out,
  output logic [31:0]          pc_out,
  output logic [31:0]          rs1_data_out,
  output logic [31:0]          rs2_data_out,
  output logic [31:0]          imm_out,
  output logic [4:0]           rs1_out,
  output logic [4:0]           rs2_out,
  output logic [4:0]           rd_out,
  output logic [2:0]           funct3_out,
  output logic [6:0]           opcode_out
);

  always_ff @(posedge clk or posedge rst) begin
    if (rst || flush) begin
      valid_out     <= 1'b0;
      ctrl_out      <= '0;
      pc_out        <= '0;
      rs1_data_out  <= '0;
      rs2_data_out  <= '0;
      imm_out       <= '0;
      rs1_out       <= '0;
      rs2_out       <= '0;
      rd_out        <= '0;
      funct3_out    <= '0;
      opcode_out    <= '0;
    end else begin
      valid_out     <= valid_in;
      ctrl_out      <= ctrl_in;
      pc_out        <= pc_in;
      rs1_data_out  <= rs1_data_in;
      rs2_data_out  <= rs2_data_in;
      imm_out       <= imm_in;
      rs1_out       <= rs1_in;
      rs2_out       <= rs2_in;
      rd_out        <= rd_in;
      funct3_out    <= funct3_in;
      opcode_out    <= opcode_in;
    end
  end

endmodule
