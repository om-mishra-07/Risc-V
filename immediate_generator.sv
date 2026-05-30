module immediate_generator (
  input  logic [31:0] instruction,
  output logic [31:0] immediate
);
  import riscv_pkg::*;

  logic [6:0] opcode;

  assign opcode = instruction[6:0];

  always_comb begin
    unique case (opcode)
      OP_I_ALU, OP_LOAD, OP_JALR, OP_SYSTEM:
        immediate = {{20{instruction[31]}}, instruction[31:20]};
      OP_STORE:
        immediate = {{20{instruction[31]}}, instruction[31:25], instruction[11:7]};
      OP_BRANCH:
        immediate = {{19{instruction[31]}}, instruction[31], instruction[7], instruction[30:25], instruction[11:8], 1'b0};
      OP_LUI, OP_AUIPC:
        immediate = {instruction[31:12], 12'h000};
      OP_JAL:
        immediate = {{11{instruction[31]}}, instruction[31], instruction[19:12], instruction[20], instruction[30:21], 1'b0};
      default:
        immediate = 32'h00000000;
    endcase
  end

endmodule
