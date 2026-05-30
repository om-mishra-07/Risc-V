module cpu_pipeline_top #(
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
  output logic [63:0] cycle_count,
  output logic [63:0] instr_count,
  output logic [63:0] stall_count,
  output logic [63:0] flush_count
);
  import riscv_pkg::*;

  /* verilator lint_off UNUSEDSIGNAL */
  logic        bp_last_valid;
  logic [1:0]  bp_last_state;
  logic [31:0] bp_last_tag;
  /* verilator lint_on UNUSEDSIGNAL */

  logic [31:0] if_pc;
  logic [31:0] if_pc_next;
  logic [31:0] if_instruction;
  logic        if_valid;

  logic        if_id_valid;
  logic [31:0] if_id_pc;
  logic [31:0] if_id_instruction;

  control_t    id_control;
  logic        id_illegal;
  logic [31:0] id_immediate;
  logic [31:0] id_rs1_data;
  logic [31:0] id_rs2_data;
  logic [31:0] x31_data;
  logic [4:0]  id_rs1_addr;
  logic [4:0]  id_rs2_addr;
  logic [4:0]  id_rd_addr;
  logic [2:0]  id_funct3;
  logic [6:0]  id_funct7;
  logic        id_funct7_5;
  logic [6:0]  id_opcode;

  logic        hazard_stall_if;
  logic        hazard_stall_id;
  logic        hazard_flush_ex;

  logic        id_ex_valid;
  control_t    id_ex_control;
  logic [31:0] id_ex_pc;
  logic [31:0] id_ex_rs1_data;
  logic [31:0] id_ex_rs2_data;
  logic [31:0] id_ex_imm;
  logic [4:0]  id_ex_rs1;
  logic [4:0]  id_ex_rs2;
  logic [4:0]  id_ex_rd;
  logic [2:0]  id_ex_funct3;
  logic [6:0]  id_ex_opcode;

  logic [1:0]  forward_a;
  logic [1:0]  forward_b;
  logic [31:0] ex_forwarded_rs1;
  logic [31:0] ex_forwarded_rs2;
  logic [31:0] ex_alu_a;
  logic [31:0] ex_alu_b;
  logic [31:0] ex_alu_result;
  logic [31:0] ex_store_data;
  logic        ex_zero;
  logic        ex_negative;
  logic        ex_overflow;
  logic        ex_branch_taken;
  logic [31:0] ex_branch_target;

  logic        ex_mem_valid;
  control_t    ex_mem_control;
  logic [31:0] ex_mem_pc4;
  logic [31:0] ex_mem_imm;
  logic [31:0] ex_mem_alu_result;
  logic [31:0] ex_mem_store_data;
  logic [4:0]  ex_mem_rd;
  logic [2:0]  ex_mem_funct3;
  logic [31:0] mem_read_data;

  logic        mem_wb_valid;
  /* verilator lint_off UNUSEDSIGNAL */
  control_t    mem_wb_control;
  /* verilator lint_on UNUSEDSIGNAL */
  logic [31:0] mem_wb_pc4;
  logic [31:0] mem_wb_imm;
  logic [31:0] mem_wb_mem_data;
  logic [31:0] mem_wb_alu_result;
  logic [4:0]  mem_wb_rd;
  logic [31:0] wb_write_data;
  logic        wb_write_enable;

  assign if_valid = 1'b1;
  assign id_opcode = if_id_instruction[6:0];
  assign id_rd_addr = if_id_instruction[11:7];
  assign id_funct3 = if_id_instruction[14:12];
  assign id_rs1_addr = if_id_instruction[19:15];
  assign id_rs2_addr = if_id_instruction[24:20];
  assign id_funct7 = if_id_instruction[31:25];
  assign id_funct7_5 = if_id_instruction[30];

  pc u_pc (
    .clk    (clk),
    .rst    (rst),
    .stall  (hazard_stall_if),
    .pc_next(if_pc_next),
    .pc_out (if_pc)
  );

  instruction_memory #(
    .INIT_FILE(IMEM_INIT_FILE)
  ) u_imem (
    .address    (if_pc),
    .instruction(if_instruction)
  );

  if_id_reg u_if_id (
    .clk      (clk),
    .rst      (rst),
    .stall    (hazard_stall_id),
    .flush    (ex_branch_taken),
    .valid_in (if_valid),
    .pc_in    (if_pc),
    .instr_in (if_instruction),
    .valid_out(if_id_valid),
    .pc_out   (if_id_pc),
    .instr_out(if_id_instruction)
  );

  control_unit u_control (
    .opcode       (id_opcode),
    .funct3       (id_funct3),
    .funct7       (id_funct7),
    .funct7_5     (id_funct7_5),
    .control      (id_control),
    .illegal_instr(id_illegal)
  );

  immediate_generator u_immgen (
    .instruction(if_id_instruction),
    .immediate  (id_immediate)
  );

  register_file u_regfile (
    .clk         (clk),
    .rst         (rst),
    .write_enable(wb_write_enable),
    .rs1_addr    (id_rs1_addr),
    .rs2_addr    (id_rs2_addr),
    .rd_addr     (mem_wb_rd),
    .write_data  (wb_write_data),
    .debug_addr  (debug_reg_sel),
    .rs1_data    (id_rs1_data),
    .rs2_data    (id_rs2_data),
    .debug_data  (debug_reg_data),
    .x31_data    (x31_data)
  );

  hazard_unit u_hazard (
    .id_valid   (if_id_valid),
    .id_rs1     (id_rs1_addr),
    .id_rs2     (id_rs2_addr),
    .ex_mem_read(id_ex_control.mem_read),
    .ex_rd      (id_ex_rd),
    .stall_if   (hazard_stall_if),
    .stall_id   (hazard_stall_id),
    .flush_ex   (hazard_flush_ex)
  );

  id_ex_reg u_id_ex (
    .clk         (clk),
    .rst         (rst),
    .flush       (hazard_flush_ex | ex_branch_taken),
    .valid_in    (if_id_valid & ~id_illegal),
    .ctrl_in     (id_control),
    .pc_in       (if_id_pc),
    .rs1_data_in (id_rs1_data),
    .rs2_data_in (id_rs2_data),
    .imm_in      (id_immediate),
    .rs1_in      (id_rs1_addr),
    .rs2_in      (id_rs2_addr),
    .rd_in       (id_rd_addr),
    .funct3_in   (id_funct3),
    .opcode_in   (id_opcode),
    .valid_out   (id_ex_valid),
    .ctrl_out    (id_ex_control),
    .pc_out      (id_ex_pc),
    .rs1_data_out(id_ex_rs1_data),
    .rs2_data_out(id_ex_rs2_data),
    .imm_out     (id_ex_imm),
    .rs1_out     (id_ex_rs1),
    .rs2_out     (id_ex_rs2),
    .rd_out      (id_ex_rd),
    .funct3_out  (id_ex_funct3),
    .opcode_out  (id_ex_opcode)
  );

  forwarding_unit u_forward (
    .ex_valid      (id_ex_valid),
    .ex_rs1        (id_ex_rs1),
    .ex_rs2        (id_ex_rs2),
    .mem_reg_write (ex_mem_control.reg_write & ex_mem_valid),
    .mem_rd        (ex_mem_rd),
    .wb_reg_write  (mem_wb_control.reg_write & mem_wb_valid),
    .wb_rd         (mem_wb_rd),
    .forward_a     (forward_a),
    .forward_b     (forward_b)
  );

  always_comb begin
    unique case (forward_a)
      2'b10: ex_forwarded_rs1 = ex_mem_alu_result;
      2'b01: ex_forwarded_rs1 = wb_write_data;
      default: ex_forwarded_rs1 = id_ex_rs1_data;
    endcase

    unique case (forward_b)
      2'b10: ex_forwarded_rs2 = ex_mem_alu_result;
      2'b01: ex_forwarded_rs2 = wb_write_data;
      default: ex_forwarded_rs2 = id_ex_rs2_data;
    endcase

    unique case (id_ex_opcode)
      OP_LUI:   ex_alu_a = id_ex_imm;
      OP_AUIPC: ex_alu_a = id_ex_pc;
      default:  ex_alu_a = ex_forwarded_rs1;
    endcase

    if (id_ex_opcode == OP_LUI) begin
      ex_alu_b = 32'h0;
    end else begin
      ex_alu_b = id_ex_control.alu_src ? id_ex_imm : ex_forwarded_rs2;
    end

    ex_store_data = ex_forwarded_rs2;
  end

  alu u_alu (
    .op_a     (ex_alu_a),
    .op_b     (ex_alu_b),
    .alu_op   (id_ex_control.alu_op),
    .result   (ex_alu_result),
    .zero     (ex_zero),
    .negative (ex_negative),
    .overflow (ex_overflow)
  );

  branch_unit u_branch (
    .branch_en   (id_ex_control.branch),
    .jump        (id_ex_control.jump),
    .jalr        (id_ex_control.jalr),
    .funct3      (id_ex_funct3),
    .pc          (id_ex_pc),
    .immediate   (id_ex_imm),
    .rs1_data    (ex_forwarded_rs1),
    .rs2_data    (ex_forwarded_rs2),
    .branch_taken(ex_branch_taken),
    .target_pc   (ex_branch_target)
  );

  assign if_pc_next = ex_branch_taken ? ex_branch_target : (if_pc + 32'd4);

  ex_mem_reg u_ex_mem (
    .clk             (clk),
    .rst             (rst),
    .flush           (1'b0),
    .valid_in        (id_ex_valid),
    .ctrl_in         (id_ex_control),
    .pc4_in          (id_ex_pc + 32'd4),
    .imm_in          (id_ex_imm),
    .alu_result_in   (ex_alu_result),
    .store_data_in   (ex_store_data),
    .rd_in           (id_ex_rd),
    .funct3_in       (id_ex_funct3),
    .valid_out       (ex_mem_valid),
    .ctrl_out        (ex_mem_control),
    .pc4_out         (ex_mem_pc4),
    .imm_out         (ex_mem_imm),
    .alu_result_out  (ex_mem_alu_result),
    .store_data_out  (ex_mem_store_data),
    .rd_out          (ex_mem_rd),
    .funct3_out      (ex_mem_funct3)
  );

  data_memory u_dmem (
    .clk       (clk),
    .rst       (rst),
    .mem_read  (ex_mem_control.mem_read & ex_mem_valid),
    .mem_write (ex_mem_control.mem_write & ex_mem_valid),
    .funct3    (ex_mem_funct3),
    .address   (ex_mem_alu_result),
    .write_data(ex_mem_store_data),
    .debug_addr(debug_mem_addr),
    .read_data (mem_read_data),
    .debug_word(debug_mem_data)
  );

  mem_wb_reg u_mem_wb (
    .clk          (clk),
    .rst          (rst),
    .valid_in     (ex_mem_valid),
    .ctrl_in      (ex_mem_control),
    .pc4_in       (ex_mem_pc4),
    .imm_in       (ex_mem_imm),
    .mem_data_in  (mem_read_data),
    .alu_result_in(ex_mem_alu_result),
    .rd_in        (ex_mem_rd),
    .valid_out    (mem_wb_valid),
    .ctrl_out     (mem_wb_control),
    .pc4_out      (mem_wb_pc4),
    .imm_out      (mem_wb_imm),
    .mem_data_out (mem_wb_mem_data),
    .alu_result_out(mem_wb_alu_result),
    .rd_out       (mem_wb_rd)
  );

  always_comb begin
    unique case (mem_wb_control.mem_to_reg)
      MEM2REG_ALU: wb_write_data = mem_wb_alu_result;
      MEM2REG_MEM: wb_write_data = mem_wb_mem_data;
      MEM2REG_PC4: wb_write_data = mem_wb_pc4;
      MEM2REG_IMM: wb_write_data = mem_wb_imm;
      default:     wb_write_data = mem_wb_alu_result;
    endcase
  end

  assign wb_write_enable   = mem_wb_valid & mem_wb_control.reg_write;
  assign current_pc        = if_pc;
  assign current_instruction = if_instruction;
  assign done              = (x31_data == 32'd1);

  always_ff @(posedge clk or posedge rst) begin
    if (rst) begin
      cycle_count <= '0;
      instr_count <= '0;
      stall_count <= '0;
      flush_count <= '0;
      bp_last_valid <= 1'b0;
      bp_last_state <= 2'b00;
      bp_last_tag   <= 32'h00000000;
    end else begin
      cycle_count <= cycle_count + 64'd1;
      if (wb_write_enable) begin
        instr_count <= instr_count + 64'd1;
      end
      if (hazard_stall_if) begin
        stall_count <= stall_count + 64'd1;
      end
      if (ex_branch_taken) begin
        flush_count <= flush_count + 64'd1;
      end

      bp_last_valid <= 1'b1;
      bp_last_tag   <= if_pc;
      bp_last_state <= ex_branch_taken ? 2'b10 : 2'b01;

`ifndef SYNTHESIS
      if (trace_en && wb_write_enable) begin
        $display("[PIPE-TRACE] pc=0x%08h rd=x%0d wb=0x%08h stall=%0b flush=%0b z=%0b n=%0b ov=%0b",
                 mem_wb_pc4 - 32'd4, mem_wb_rd, wb_write_data, hazard_stall_if, ex_branch_taken,
                 ex_zero, ex_negative, ex_overflow);
      end
      if (dump_en) begin
        u_regfile.dump_regs();
        u_dmem.dump_words(32'h100, 4);
      end
`endif
    end
  end

endmodule

