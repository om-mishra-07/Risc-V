module cpu_top #(
  parameter IMEM_INIT_FILE = "tb/programs/fibonacci.hex"
) (
  input  logic        clk,
  input  logic        rst,
  input  logic        trace_en,
  input  logic        dump_en,
  input  logic [4:0]  debug_reg_sel,
  input  logic [31:0] debug_mem_addr,
  output logic [31:0] debug_reg_data,
  output logic [31:0] debug_mem_data,
  output logic [31:0] current_pc,
  output logic [31:0] current_instruction,
  output logic        done,
  output logic        illegal_instr,
  output logic [63:0] cycle_count,
  output logic [63:0] instr_count
);
  import riscv_pkg::*;

  logic [31:0] pc_value;
  logic [31:0] pc_next;
  logic [31:0] instruction;
  logic [31:0] immediate;
  logic [31:0] rs1_data;
  logic [31:0] rs2_data;
  logic [31:0] alu_operand_a;
  logic [31:0] alu_operand_b;
  logic [31:0] alu_result;
  logic [31:0] mem_read_data;
  logic [31:0] writeback_data;
  logic [31:0] x31_data;
  logic        branch_taken;
  logic [31:0] branch_target;
  logic        zero_flag;
  logic        negative_flag;
  logic        overflow_flag;
  logic        reg_write_enable;
  control_t    control;

  logic [6:0] opcode;
  logic [2:0] funct3;
  logic [6:0] funct7;
  logic       funct7_5;
  logic [4:0] rs1_addr;
  logic [4:0] rs2_addr;
  logic [4:0] rd_addr;

  assign opcode   = instruction[6:0];
  assign rd_addr  = instruction[11:7];
  assign funct3   = instruction[14:12];
  assign rs1_addr = instruction[19:15];
  assign rs2_addr = instruction[24:20];
  assign funct7   = instruction[31:25];
  assign funct7_5 = instruction[30];

  pc u_pc (
    .clk    (clk),
    .rst    (rst),
    .stall  (1'b0),
    .pc_next(pc_next),
    .pc_out (pc_value)
  );

  instruction_memory #(
    .INIT_FILE(IMEM_INIT_FILE)
  ) u_imem (
    .address    (pc_value),
    .instruction(instruction)
  );

  immediate_generator u_immgen (
    .instruction(instruction),
    .immediate  (immediate)
  );

  control_unit u_control (
    .opcode       (opcode),
    .funct3       (funct3),
    .funct7       (funct7),
    .funct7_5     (funct7_5),
    .control      (control),
    .illegal_instr(illegal_instr)
  );

  register_file u_regfile (
    .clk         (clk),
    .rst         (rst),
    .write_enable(reg_write_enable),
    .rs1_addr    (rs1_addr),
    .rs2_addr    (rs2_addr),
    .rd_addr     (rd_addr),
    .write_data  (writeback_data),
    .debug_addr  (debug_reg_sel),
    .rs1_data    (rs1_data),
    .rs2_data    (rs2_data),
    .debug_data  (debug_reg_data),
    .x31_data    (x31_data)
  );

  always_comb begin
    unique case (opcode)
      OP_LUI:   alu_operand_a = immediate;
      OP_AUIPC: alu_operand_a = pc_value;
      default:  alu_operand_a = rs1_data;
    endcase

    if (opcode == OP_LUI) begin
      alu_operand_b = 32'h0;
    end else begin
      alu_operand_b = control.alu_src ? immediate : rs2_data;
    end
  end

  alu u_alu (
    .op_a     (alu_operand_a),
    .op_b     (alu_operand_b),
    .alu_op   (control.alu_op),
    .result   (alu_result),
    .zero     (zero_flag),
    .negative (negative_flag),
    .overflow (overflow_flag)
  );

  branch_unit u_branch (
    .branch_en   (control.branch),
    .jump        (control.jump),
    .jalr        (control.jalr),
    .funct3      (funct3),
    .pc          (pc_value),
    .immediate   (immediate),
    .rs1_data    (rs1_data),
    .rs2_data    (rs2_data),
    .branch_taken(branch_taken),
    .target_pc   (branch_target)
  );

  data_memory u_dmem (
    .clk       (clk),
    .rst       (rst),
    .mem_read  (control.mem_read),
    .mem_write (control.mem_write),
    .funct3    (funct3),
    .address   (alu_result),
    .write_data(rs2_data),
    .debug_addr(debug_mem_addr),
    .read_data (mem_read_data),
    .debug_word(debug_mem_data)
  );

  always_comb begin
    unique case (control.mem_to_reg)
      MEM2REG_ALU: writeback_data = alu_result;
      MEM2REG_MEM: writeback_data = mem_read_data;
      MEM2REG_PC4: writeback_data = pc_value + 32'd4;
      MEM2REG_IMM: writeback_data = immediate;
      default:     writeback_data = alu_result;
    endcase
  end

  assign reg_write_enable   = control.reg_write & ~illegal_instr;
  assign pc_next            = branch_taken ? branch_target : (pc_value + 32'd4);
  assign current_pc         = pc_value;
  assign current_instruction = instruction;
  assign done               = (x31_data == 32'd1);

  always_ff @(posedge clk or posedge rst) begin
    if (rst) begin
      cycle_count <= '0;
      instr_count <= '0;
    end else begin
      cycle_count <= cycle_count + 64'd1;
      if (!illegal_instr && (instruction != 32'h00000013)) begin
        instr_count <= instr_count + 64'd1;
      end
`ifndef SYNTHESIS
      if (trace_en && !illegal_instr) begin
        $display("[SC-TRACE] pc=0x%08h instr=0x%08h rd=x%0d wb=0x%08h branch=%0b target=0x%08h z=%0b n=%0b ov=%0b",
                 pc_value, instruction, rd_addr, writeback_data, branch_taken, branch_target,
                 zero_flag, negative_flag, overflow_flag);
      end
      if (dump_en) begin
        u_regfile.dump_regs();
        u_dmem.dump_words(32'h100, 4);
      end
`endif
    end
  end

endmodule
