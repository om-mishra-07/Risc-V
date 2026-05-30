PROJECT_ROOT := .
RTL_DIR := rtl
PIPE_DIR := rtl/pipeline
TB_DIR := tb
SIM_DIR := sim
WAVE_DIR := waveforms
OBJ_DIR := obj_dir
VERILATOR_SC_DIR := /tmp/riscv_sc_obj
VERILATOR_PIPE_DIR := /tmp/riscv_pipe_obj

RTL_COMMON := \
	$(RTL_DIR)/riscv_pkg.sv \
	$(RTL_DIR)/pc.sv \
	$(RTL_DIR)/alu.sv \
	$(RTL_DIR)/register_file.sv \
	$(RTL_DIR)/control_unit.sv \
	$(RTL_DIR)/instruction_memory.sv \
	$(RTL_DIR)/data_memory.sv \
	$(RTL_DIR)/immediate_generator.sv \
	$(RTL_DIR)/branch_unit.sv

RTL_SC := $(RTL_COMMON) $(RTL_DIR)/cpu_top.sv
RTL_PIPE := $(RTL_COMMON) \
	$(PIPE_DIR)/if_id_reg.sv \
	$(PIPE_DIR)/id_ex_reg.sv \
	$(PIPE_DIR)/ex_mem_reg.sv \
	$(PIPE_DIR)/mem_wb_reg.sv \
	$(PIPE_DIR)/hazard_unit.sv \
	$(PIPE_DIR)/forwarding_unit.sv \
	$(PIPE_DIR)/cpu_pipeline_top.sv

RTL_SC_ABS := $(abspath $(RTL_SC))
RTL_PIPE_ABS := $(abspath $(RTL_PIPE))
MAIN_SC_ABS := $(abspath $(SIM_DIR)/main_sc.cpp)
MAIN_PIPE_ABS := $(abspath $(SIM_DIR)/main_pipe.cpp)

.PHONY: sc pipe lint clean iverilog_sc iverilog_pipe wave_sc wave_pipe vcs_sc vcs_pipe

sc:
	rm -rf $(VERILATOR_SC_DIR)
	verilator -Wall --trace --timing --cc --exe --build --Mdir $(VERILATOR_SC_DIR) --top-module cpu_top $(RTL_SC_ABS) $(MAIN_SC_ABS)
	$(VERILATOR_SC_DIR)/Vcpu_top

pipe:
	rm -rf $(VERILATOR_PIPE_DIR)
	verilator -Wall --trace --timing --cc --exe --build --Mdir $(VERILATOR_PIPE_DIR) --top-module cpu_pipeline_top $(RTL_PIPE_ABS) $(MAIN_PIPE_ABS)
	$(VERILATOR_PIPE_DIR)/Vcpu_pipeline_top

lint:
	verilator --lint-only -Wall --top-module cpu_top $(RTL_SC)
	verilator --lint-only -Wall --top-module cpu_pipeline_top $(RTL_PIPE)

iverilog_sc:
	mkdir -p $(OBJ_DIR)
	iverilog -g2012 -o $(OBJ_DIR)/cpu_tb.out $(RTL_SC) $(TB_DIR)/cpu_tb.sv
	vvp $(OBJ_DIR)/cpu_tb.out

iverilog_pipe:
	mkdir -p $(OBJ_DIR)
	iverilog -g2012 -o $(OBJ_DIR)/cpu_pipeline_tb.out $(RTL_PIPE) $(TB_DIR)/cpu_pipeline_tb.sv
	vvp $(OBJ_DIR)/cpu_pipeline_tb.out

wave_sc:
	gtkwave $(WAVE_DIR)/cpu_wave.vcd

wave_pipe:
	gtkwave $(WAVE_DIR)/cpu_pipeline_wave.vcd

vcs_sc:
	vcs -sverilog -full64 $(RTL_SC) $(TB_DIR)/cpu_tb.sv -o simv_sc && ./simv_sc

vcs_pipe:
	vcs -sverilog -full64 $(RTL_PIPE) $(TB_DIR)/cpu_pipeline_tb.sv -o simv_pipe && ./simv_pipe

clean:
	rm -rf $(OBJ_DIR) $(VERILATOR_SC_DIR) $(VERILATOR_PIPE_DIR) simv_sc simv_pipe csrc ucli.key *.daidir $(WAVE_DIR)/*.vcd
