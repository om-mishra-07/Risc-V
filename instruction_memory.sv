module instruction_memory #(
  parameter int DEPTH = 256,
  parameter INIT_FILE = "tb/programs/fibonacci.hex"
) (
  input  logic [31:0] address,
  output logic [31:0] instruction
);

  localparam int ADDR_W = (DEPTH <= 1) ? 1 : $clog2(DEPTH);
  logic [31:0] memory [0:DEPTH-1];
  logic unused_addr_bits;
  integer idx;

  initial begin
    for (idx = 0; idx < DEPTH; idx++) begin
      memory[idx] = 32'h00000013;
    end
    if (INIT_FILE != "") begin
      $readmemh(INIT_FILE, memory);
    end
  end

  assign instruction = memory[address[ADDR_W+1:2]];
  assign unused_addr_bits = |{address[31:ADDR_W+2], address[1:0]};

  task automatic load_program(input string file_name);
    begin
      $readmemh(file_name, memory);
    end
  endtask

endmodule
