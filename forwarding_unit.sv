module forwarding_unit (
  input  logic       ex_valid,
  input  logic [4:0] ex_rs1,
  input  logic [4:0] ex_rs2,
  input  logic       mem_reg_write,
  input  logic [4:0] mem_rd,
  input  logic       wb_reg_write,
  input  logic [4:0] wb_rd,
  output logic [1:0] forward_a,
  output logic [1:0] forward_b
);

  always_comb begin
    forward_a = 2'b00;
    forward_b = 2'b00;

    if (ex_valid && mem_reg_write && (mem_rd != 5'd0) && (mem_rd == ex_rs1)) begin
      forward_a = 2'b10;
    end else if (ex_valid && wb_reg_write && (wb_rd != 5'd0) && (wb_rd == ex_rs1)) begin
      forward_a = 2'b01;
    end

    if (ex_valid && mem_reg_write && (mem_rd != 5'd0) && (mem_rd == ex_rs2)) begin
      forward_b = 2'b10;
    end else if (ex_valid && wb_reg_write && (wb_rd != 5'd0) && (wb_rd == ex_rs2)) begin
      forward_b = 2'b01;
    end
  end

endmodule
