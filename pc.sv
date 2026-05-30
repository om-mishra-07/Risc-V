module pc #(
  parameter int XLEN = 32,
  parameter logic [XLEN-1:0] RESET_PC = '0
) (
  input  logic            clk,
  input  logic            rst,
  input  logic            stall,
  input  logic [XLEN-1:0] pc_next,
  output logic [XLEN-1:0] pc_out
);

  always_ff @(posedge clk or posedge rst) begin
    if (rst) begin
      pc_out <= RESET_PC;
    end else if (!stall) begin
      pc_out <= pc_next;
    end
  end

endmodule
