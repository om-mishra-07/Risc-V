module data_memory #(
  parameter int DEPTH_BYTES = 4096
) (
  input  logic        clk,
  input  logic        rst,
  input  logic        mem_read,
  input  logic        mem_write,
  input  logic [2:0]  funct3,
  input  logic [31:0] address,
  input  logic [31:0] write_data,
  input  logic [31:0] debug_addr,
  output logic [31:0] read_data,
  output logic [31:0] debug_word
);
  import riscv_pkg::*;

  logic [7:0] memory [0:DEPTH_BYTES-1];
  integer idx;
  always_ff @(posedge clk or posedge rst) begin
    if (rst) begin
      for (idx = 0; idx < DEPTH_BYTES; idx++) begin
        memory[idx] <= '0;
      end
    end else if (mem_write) begin
      unique case (funct3)
        F3_BYTE: begin
          memory[address] <= write_data[7:0];
        end
        F3_HALF: begin
          memory[address]     <= write_data[7:0];
          memory[address + 1] <= write_data[15:8];
        end
        default: begin
          memory[address]     <= write_data[7:0];
          memory[address + 1] <= write_data[15:8];
          memory[address + 2] <= write_data[23:16];
          memory[address + 3] <= write_data[31:24];
        end
      endcase
    end
  end

  always_comb begin
    read_data = '0;
    if (mem_read) begin
      unique case (funct3)
        F3_BYTE:  read_data = {{24{memory[address][7]}}, memory[address]};
        F3_HALF:  read_data = {{16{memory[address + 1][7]}}, memory[address + 1], memory[address]};
        F3_WORD:  read_data = {memory[address + 3], memory[address + 2], memory[address + 1], memory[address]};
        F3_UBYTE: read_data = {24'h0, memory[address]};
        F3_UHALF: read_data = {16'h0, memory[address + 1], memory[address]};
        default:  read_data = '0;
      endcase
    end
  end

  assign debug_word = {memory[debug_addr + 3], memory[debug_addr + 2], memory[debug_addr + 1], memory[debug_addr]};

  task automatic dump_words(input int start_addr, input int word_count);
    integer word_idx;
    begin
      $display("---- Data Memory Dump ----");
      for (word_idx = 0; word_idx < word_count; word_idx++) begin
        $display("mem[0x%08h] = 0x%08h", start_addr + (word_idx * 4),
                 {memory[start_addr + (word_idx * 4) + 3],
                  memory[start_addr + (word_idx * 4) + 2],
                  memory[start_addr + (word_idx * 4) + 1],
                  memory[start_addr + (word_idx * 4)]});
      end
    end
  endtask

endmodule
