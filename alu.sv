module alu #(
  parameter int XLEN = 32
) (
  input  logic [XLEN-1:0] op_a,
  input  logic [XLEN-1:0] op_b,
  input  logic [3:0]      alu_op,
  output logic [XLEN-1:0] result,
  output logic            zero,
  output logic            negative,
  output logic            overflow
);
  import riscv_pkg::*;

  logic signed [XLEN-1:0] op_a_signed;
  logic signed [XLEN-1:0] op_b_signed;
  logic signed [XLEN-1:0] result_signed;

  assign op_a_signed = signed'(op_a);
  assign op_b_signed = signed'(op_b);

  always_comb begin
    overflow = 1'b0;
    unique case (alu_op)
      ALU_ADD: begin
        result = op_a + op_b;
        overflow = (~(op_a[XLEN-1] ^ op_b[XLEN-1])) & (result[XLEN-1] ^ op_a[XLEN-1]);
      end
      ALU_SUB: begin
        result = op_a - op_b;
        overflow = ((op_a[XLEN-1] ^ op_b[XLEN-1])) & (result[XLEN-1] ^ op_a[XLEN-1]);
      end
      ALU_AND:    result = op_a & op_b;
      ALU_OR:     result = op_a | op_b;
      ALU_XOR:    result = op_a ^ op_b;
      ALU_SLL:    result = op_a << op_b[4:0];
      ALU_SRL:    result = op_a >> op_b[4:0];
      ALU_SLT:    result = {{(XLEN-1){1'b0}}, (op_a_signed < op_b_signed)};
      ALU_SLTU:   result = {{(XLEN-1){1'b0}}, (op_a < op_b)};
      ALU_SRA:    result = XLEN'(op_a_signed >>> op_b[4:0]);
      ALU_PASS:   result = op_a;
      ALU_ADD_PC: result = op_a + op_b;
      ALU_MUL:    result = op_a * op_b;
      default:    result = '0;
    endcase
  end

  assign result_signed = signed'(result);
  assign zero = (result == '0);
  assign negative = result_signed[XLEN-1];

endmodule
