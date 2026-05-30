module branch_unit (
  input  logic        branch_en,
  input  logic        jump,
  input  logic        jalr,
  input  logic [2:0]  funct3,
  input  logic [31:0] pc,
  input  logic [31:0] immediate,
  input  logic [31:0] rs1_data,
  input  logic [31:0] rs2_data,
  output logic        branch_taken,
  output logic [31:0] target_pc
);
  import riscv_pkg::*;

  logic branch_condition;

  always_comb begin
    branch_condition = 1'b0;
    unique case (funct3)
      F3_BEQ:  branch_condition = (rs1_data == rs2_data);
      F3_BNE:  branch_condition = (rs1_data != rs2_data);
      F3_BLT:  branch_condition = (signed'(rs1_data) < signed'(rs2_data));
      F3_BGE:  branch_condition = (signed'(rs1_data) >= signed'(rs2_data));
      F3_BLTU: branch_condition = (rs1_data < rs2_data);
      F3_BGEU: branch_condition = (rs1_data >= rs2_data);
      default: branch_condition = 1'b0;
    endcase

    if (jump) begin
      branch_taken = 1'b1;
      if (jalr) begin
        target_pc = (rs1_data + immediate) & 32'hfffffffe;
      end else begin
        target_pc = pc + immediate;
      end
    end else if (branch_en && branch_condition) begin
      branch_taken = 1'b1;
      target_pc = pc + immediate;
    end else begin
      branch_taken = 1'b0;
      target_pc = pc + 32'd4;
    end
  end

endmodule
