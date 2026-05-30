package riscv_pkg;
  localparam logic [6:0] OP_R      = 7'b0110011;
  localparam logic [6:0] OP_I_ALU  = 7'b0010011;
  localparam logic [6:0] OP_LOAD   = 7'b0000011;
  localparam logic [6:0] OP_STORE  = 7'b0100011;
  localparam logic [6:0] OP_BRANCH = 7'b1100011;
  localparam logic [6:0] OP_LUI    = 7'b0110111;
  localparam logic [6:0] OP_AUIPC  = 7'b0010111;
  localparam logic [6:0] OP_JAL    = 7'b1101111;
  localparam logic [6:0] OP_JALR   = 7'b1100111;
  localparam logic [6:0] OP_SYSTEM = 7'b1110011;

  localparam logic [2:0] F3_ADD_SUB = 3'b000;
  localparam logic [2:0] F3_SLL     = 3'b001;
  localparam logic [2:0] F3_SLT     = 3'b010;
  localparam logic [2:0] F3_SLTU    = 3'b011;
  localparam logic [2:0] F3_XOR     = 3'b100;
  localparam logic [2:0] F3_SRL_SRA = 3'b101;
  localparam logic [2:0] F3_OR      = 3'b110;
  localparam logic [2:0] F3_AND     = 3'b111;

  localparam logic [2:0] F3_BEQ  = 3'b000;
  localparam logic [2:0] F3_BNE  = 3'b001;
  localparam logic [2:0] F3_BLT  = 3'b100;
  localparam logic [2:0] F3_BGE  = 3'b101;
  localparam logic [2:0] F3_BLTU = 3'b110;
  localparam logic [2:0] F3_BGEU = 3'b111;

  localparam logic [2:0] F3_BYTE  = 3'b000;
  localparam logic [2:0] F3_HALF  = 3'b001;
  localparam logic [2:0] F3_WORD  = 3'b010;
  localparam logic [2:0] F3_UBYTE = 3'b100;
  localparam logic [2:0] F3_UHALF = 3'b101;

  localparam logic [3:0] ALU_ADD  = 4'h0;
  localparam logic [3:0] ALU_SUB  = 4'h1;
  localparam logic [3:0] ALU_AND  = 4'h2;
  localparam logic [3:0] ALU_OR   = 4'h3;
  localparam logic [3:0] ALU_XOR  = 4'h4;
  localparam logic [3:0] ALU_SLL  = 4'h5;
  localparam logic [3:0] ALU_SRL  = 4'h6;
  localparam logic [3:0] ALU_SLT  = 4'h7;
  localparam logic [3:0] ALU_SLTU = 4'h8;
  localparam logic [3:0] ALU_SRA  = 4'h9;
  localparam logic [3:0] ALU_PASS = 4'hA;
  localparam logic [3:0] ALU_ADD_PC = 4'hB;
  localparam logic [3:0] ALU_MUL  = 4'hC;

  localparam logic [1:0] MEM2REG_ALU = 2'b00;
  localparam logic [1:0] MEM2REG_MEM = 2'b01;
  localparam logic [1:0] MEM2REG_PC4 = 2'b10;
  localparam logic [1:0] MEM2REG_IMM = 2'b11;

  typedef struct packed {
    logic       reg_write;
    logic       alu_src;
    logic [1:0] mem_to_reg;
    logic       mem_read;
    logic       mem_write;
    logic       branch;
    logic       jump;
    logic       jalr;
    logic [3:0] alu_op;
  } control_t;

  typedef struct packed {
    logic       valid;
    logic [1:0] state;
    logic [31:0] tag;
  } bp_entry_t;

endpackage
