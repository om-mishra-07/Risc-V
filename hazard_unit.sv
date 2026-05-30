module hazard_unit (
  input  logic       id_valid,
  input  logic [4:0] id_rs1,
  input  logic [4:0] id_rs2,
  input  logic       ex_mem_read,
  input  logic [4:0] ex_rd,
  output logic       stall_if,
  output logic       stall_id,
  output logic       flush_ex
);

  always_comb begin
    stall_if = 1'b0;
    stall_id = 1'b0;
    flush_ex = 1'b0;

    if (id_valid && ex_mem_read && (ex_rd != 5'd0) && ((ex_rd == id_rs1) || (ex_rd == id_rs2))) begin
      stall_if = 1'b1;
      stall_id = 1'b1;
      flush_ex = 1'b1;
    end
  end

endmodule
