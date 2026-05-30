module control_unit (
  input  logic [6:0] opcode,
  input  logic [2:0] funct3,
  input  logic [6:0] funct7,
  input  logic       funct7_5,
  output riscv_pkg::control_t control,
  output logic       illegal_instr
);
  import riscv_pkg::*;

  always_comb begin
    control = '0;
    illegal_instr = 1'b0;

    unique case (opcode)
      OP_R: begin
        control.reg_write = 1'b1;
        unique case (funct3)
          F3_ADD_SUB: begin
            unique case (funct7)
              7'b0000000: control.alu_op = ALU_ADD;
              7'b0100000: control.alu_op = ALU_SUB;
              7'b0000001: control.alu_op = ALU_MUL;
              default:    illegal_instr = 1'b1;
            endcase
          end
          F3_SLL: begin
            if (funct7 == 7'b0000000) begin
              control.alu_op = ALU_SLL;
            end else begin
              illegal_instr = 1'b1;
            end
          end
          F3_SLT: begin
            if (funct7 == 7'b0000000) begin
              control.alu_op = ALU_SLT;
            end else begin
              illegal_instr = 1'b1;
            end
          end
          F3_SLTU: begin
            if (funct7 == 7'b0000000) begin
              control.alu_op = ALU_SLTU;
            end else begin
              illegal_instr = 1'b1;
            end
          end
          F3_XOR: begin
            if (funct7 == 7'b0000000) begin
              control.alu_op = ALU_XOR;
            end else begin
              illegal_instr = 1'b1;
            end
          end
          F3_SRL_SRA: begin
            if (funct7 == 7'b0100000) begin
              control.alu_op = ALU_SRA;
            end else if (funct7 == 7'b0000000) begin
              control.alu_op = ALU_SRL;
            end else begin
              illegal_instr = 1'b1;
            end
          end
          F3_OR: begin
            if (funct7 == 7'b0000000) begin
              control.alu_op = ALU_OR;
            end else begin
              illegal_instr = 1'b1;
            end
          end
          F3_AND: begin
            if (funct7 == 7'b0000000) begin
              control.alu_op = ALU_AND;
            end else begin
              illegal_instr = 1'b1;
            end
          end
          default:    illegal_instr = 1'b1;
        endcase
      end

      OP_I_ALU: begin
        control.reg_write = 1'b1;
        control.alu_src   = 1'b1;
        unique case (funct3)
          F3_ADD_SUB: control.alu_op = ALU_ADD;
          F3_SLL:     control.alu_op = ALU_SLL;
          F3_SLT:     control.alu_op = ALU_SLT;
          F3_SLTU:    control.alu_op = ALU_SLTU;
          F3_XOR:     control.alu_op = ALU_XOR;
          F3_SRL_SRA: control.alu_op = funct7_5 ? ALU_SRA : ALU_SRL;
          F3_OR:      control.alu_op = ALU_OR;
          F3_AND:     control.alu_op = ALU_AND;
          default:    illegal_instr = 1'b1;
        endcase
      end

      OP_LOAD: begin
        control.reg_write = 1'b1;
        control.alu_src   = 1'b1;
        control.mem_to_reg = MEM2REG_MEM;
        control.mem_read  = 1'b1;
        control.alu_op    = ALU_ADD;
      end

      OP_STORE: begin
        control.alu_src   = 1'b1;
        control.mem_write = 1'b1;
        control.alu_op    = ALU_ADD;
      end

      OP_BRANCH: begin
        control.branch = 1'b1;
        control.alu_op = ALU_SUB;
      end

      OP_JAL: begin
        control.reg_write = 1'b1;
        control.jump      = 1'b1;
        control.mem_to_reg = MEM2REG_PC4;
      end

      OP_JALR: begin
        control.reg_write = 1'b1;
        control.jump      = 1'b1;
        control.jalr      = 1'b1;
        control.mem_to_reg = MEM2REG_PC4;
        control.alu_src   = 1'b1;
      end

      OP_LUI: begin
        control.reg_write = 1'b1;
        control.mem_to_reg = MEM2REG_IMM;
        control.alu_op    = ALU_PASS;
      end

      OP_AUIPC: begin
        control.reg_write = 1'b1;
        control.alu_src   = 1'b1;
        control.alu_op    = ALU_ADD_PC;
      end

      default: begin
        illegal_instr = 1'b1;
      end
    endcase
  end

endmodule
