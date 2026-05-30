// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vcpu_top.h for the primary calling header

#ifndef VERILATED_VCPU_TOP___024ROOT_H_
#define VERILATED_VCPU_TOP___024ROOT_H_  // guard

#include "verilated.h"


class Vcpu_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vcpu_top___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(trace_en,0,0);
    VL_IN8(dump_en,0,0);
    VL_IN8(debug_reg_sel,4,0);
    VL_OUT8(done,0,0);
    VL_OUT8(illegal_instr,0,0);
    CData/*0:0*/ cpu_top__DOT__branch_taken;
    CData/*0:0*/ cpu_top__DOT__overflow_flag;
    CData/*0:0*/ cpu_top__DOT__u_branch__DOT__branch_condition;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VicoPhaseResult;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    SData/*12:0*/ cpu_top__DOT__control;
    VL_IN(debug_mem_addr,31,0);
    VL_OUT(debug_reg_data,31,0);
    VL_OUT(debug_mem_data,31,0);
    VL_OUT(current_pc,31,0);
    VL_OUT(current_instruction,31,0);
    IData/*31:0*/ cpu_top__DOT__pc_value;
    IData/*31:0*/ cpu_top__DOT__alu_result;
    IData/*31:0*/ cpu_top__DOT__mem_read_data;
    IData/*31:0*/ cpu_top__DOT__branch_target;
    IData/*31:0*/ cpu_top__DOT__u_pc__DOT__pc_next;
    IData/*31:0*/ cpu_top__DOT__u_imem__DOT__idx;
    IData/*31:0*/ cpu_top__DOT__u_immgen__DOT__immediate;
    IData/*31:0*/ cpu_top__DOT__u_regfile__DOT__write_data;
    IData/*31:0*/ cpu_top__DOT__u_regfile__DOT__rs1_data;
    IData/*31:0*/ cpu_top__DOT__u_regfile__DOT__rs2_data;
    IData/*31:0*/ cpu_top__DOT__u_regfile__DOT__idx;
    IData/*31:0*/ cpu_top__DOT__u_alu__DOT__op_a;
    IData/*31:0*/ cpu_top__DOT__u_alu__DOT__op_b;
    IData/*31:0*/ cpu_top__DOT__u_dmem__DOT__idx;
    IData/*31:0*/ __VactIterCount;
    VL_OUT64(cycle_count,63,0);
    VL_OUT64(instr_count,63,0);
    VlUnpacked<IData/*31:0*/, 256> cpu_top__DOT__u_imem__DOT__memory;
    VlUnpacked<IData/*31:0*/, 32> cpu_top__DOT__u_regfile__DOT__regs;
    VlUnpacked<CData/*7:0*/, 4096> cpu_top__DOT__u_dmem__DOT__memory;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlNBACommitQueue<VlUnpacked<CData/*7:0*/, 4096>, false, CData/*7:0*/, 1> __VdlyCommitQueuecpu_top__DOT__u_dmem__DOT__memory;

    // INTERNAL VARIABLES
    Vcpu_top__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vcpu_top___024root(Vcpu_top__Syms* symsp, const char* namep);
    ~Vcpu_top___024root();
    VL_UNCOPYABLE(Vcpu_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
