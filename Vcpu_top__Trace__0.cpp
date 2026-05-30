// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vcpu_top__Syms.h"


void Vcpu_top___024root__trace_chg_0_sub_0(Vcpu_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vcpu_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root__trace_chg_0\n"); );
    // Body
    Vcpu_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcpu_top___024root*>(voidSelf);
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vcpu_top___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vcpu_top___024root__trace_chg_dtype____0(Vcpu_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar);

void Vcpu_top___024root__trace_chg_0_sub_0(Vcpu_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root__trace_chg_0_sub_0\n"); );
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.cpu_top__DOT__u_imem__DOT__idx),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgIData(oldp+1,(vlSelfRef.cpu_top__DOT__pc_value),32);
        bufp->chgIData(oldp+2,(((IData)(vlSelfRef.cpu_top__DOT__branch_taken)
                                 ? vlSelfRef.cpu_top__DOT__branch_target
                                 : ((IData)(4U) + vlSelfRef.cpu_top__DOT__pc_value))),32);
        bufp->chgIData(oldp+3,(vlSelfRef.cpu_top__DOT__u_immgen__DOT__immediate),32);
        bufp->chgIData(oldp+4,(vlSelfRef.cpu_top__DOT__u_regfile__DOT__rs1_data),32);
        bufp->chgIData(oldp+5,(vlSelfRef.cpu_top__DOT__u_regfile__DOT__rs2_data),32);
        bufp->chgIData(oldp+6,(vlSelfRef.cpu_top__DOT__u_alu__DOT__op_a),32);
        bufp->chgIData(oldp+7,(vlSelfRef.cpu_top__DOT__u_alu__DOT__op_b),32);
        bufp->chgIData(oldp+8,(vlSelfRef.cpu_top__DOT__alu_result),32);
        bufp->chgIData(oldp+9,(vlSelfRef.cpu_top__DOT__mem_read_data),32);
        bufp->chgIData(oldp+10,(vlSelfRef.cpu_top__DOT__u_regfile__DOT__write_data),32);
        bufp->chgIData(oldp+11,(vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[31U]),32);
        bufp->chgBit(oldp+12,(vlSelfRef.cpu_top__DOT__branch_taken));
        bufp->chgIData(oldp+13,(vlSelfRef.cpu_top__DOT__branch_target),32);
        bufp->chgBit(oldp+14,((0U == vlSelfRef.cpu_top__DOT__alu_result)));
        bufp->chgBit(oldp+15,((vlSelfRef.cpu_top__DOT__alu_result 
                               >> 0x0000001fU)));
        bufp->chgBit(oldp+16,(vlSelfRef.cpu_top__DOT__overflow_flag));
        bufp->chgSData(oldp+17,(vlSelfRef.cpu_top__DOT__control),13);
        bufp->chgCData(oldp+18,((0x0000000fU & (IData)(vlSelfRef.cpu_top__DOT__control))),4);
        bufp->chgIData(oldp+19,(vlSelfRef.cpu_top__DOT__u_alu__DOT__op_a),32);
        bufp->chgIData(oldp+20,(vlSelfRef.cpu_top__DOT__u_alu__DOT__op_b),32);
        bufp->chgIData(oldp+21,(vlSelfRef.cpu_top__DOT__alu_result),32);
        bufp->chgBit(oldp+22,((1U & ((IData)(vlSelfRef.cpu_top__DOT__control) 
                                     >> 6U))));
        bufp->chgBit(oldp+23,((1U & ((IData)(vlSelfRef.cpu_top__DOT__control) 
                                     >> 5U))));
        bufp->chgBit(oldp+24,((1U & ((IData)(vlSelfRef.cpu_top__DOT__control) 
                                     >> 4U))));
        bufp->chgBit(oldp+25,(vlSelfRef.cpu_top__DOT__u_branch__DOT__branch_condition));
        bufp->chgBit(oldp+26,((1U & ((IData)(vlSelfRef.cpu_top__DOT__control) 
                                     >> 8U))));
        bufp->chgBit(oldp+27,((1U & ((IData)(vlSelfRef.cpu_top__DOT__control) 
                                     >> 7U))));
        bufp->chgIData(oldp+28,(vlSelfRef.cpu_top__DOT__u_dmem__DOT__idx),32);
        bufp->chgBit(oldp+29,((IData)((0U != (0xfffffc03U 
                                              & vlSelfRef.cpu_top__DOT__pc_value)))));
        Vcpu_top___024root__trace_chg_dtype____0(vlSelf, bufp, 30, vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs);
        bufp->chgIData(oldp+62,(vlSelfRef.cpu_top__DOT__u_regfile__DOT__idx),32);
    }
    bufp->chgBit(oldp+63,(vlSelfRef.clk));
    bufp->chgBit(oldp+64,(vlSelfRef.rst));
    bufp->chgBit(oldp+65,(vlSelfRef.trace_en));
    bufp->chgBit(oldp+66,(vlSelfRef.dump_en));
    bufp->chgCData(oldp+67,(vlSelfRef.debug_reg_sel),5);
    bufp->chgIData(oldp+68,(vlSelfRef.debug_mem_addr),32);
    bufp->chgIData(oldp+69,(vlSelfRef.debug_reg_data),32);
    bufp->chgIData(oldp+70,(vlSelfRef.debug_mem_data),32);
    bufp->chgIData(oldp+71,(vlSelfRef.current_instruction),32);
    bufp->chgBit(oldp+72,(vlSelfRef.done));
    bufp->chgBit(oldp+73,(vlSelfRef.illegal_instr));
    bufp->chgQData(oldp+74,(vlSelfRef.cycle_count),64);
    bufp->chgQData(oldp+76,(vlSelfRef.instr_count),64);
    bufp->chgBit(oldp+78,(((~ (IData)(vlSelfRef.illegal_instr)) 
                           & ((IData)(vlSelfRef.cpu_top__DOT__control) 
                              >> 0x0000000cU))));
    bufp->chgCData(oldp+79,((0x0000007fU & vlSelfRef.current_instruction)),7);
    bufp->chgCData(oldp+80,((7U & (vlSelfRef.current_instruction 
                                   >> 0x0000000cU))),3);
    bufp->chgBit(oldp+81,((1U & (vlSelfRef.current_instruction 
                                 >> 0x0000001eU))));
    bufp->chgCData(oldp+82,((0x0000001fU & (vlSelfRef.current_instruction 
                                            >> 0x0000000fU))),5);
    bufp->chgCData(oldp+83,((0x0000001fU & (vlSelfRef.current_instruction 
                                            >> 0x00000014U))),5);
    bufp->chgCData(oldp+84,((0x0000001fU & (vlSelfRef.current_instruction 
                                            >> 7U))),5);
}

void Vcpu_top___024root__trace_chg_dtype____0(Vcpu_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root__trace_chg_dtype____0\n"); );
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[0]),32);
    bufp->chgIData(oldp+1,(__VdtypeVar[1]),32);
    bufp->chgIData(oldp+2,(__VdtypeVar[2]),32);
    bufp->chgIData(oldp+3,(__VdtypeVar[3]),32);
    bufp->chgIData(oldp+4,(__VdtypeVar[4]),32);
    bufp->chgIData(oldp+5,(__VdtypeVar[5]),32);
    bufp->chgIData(oldp+6,(__VdtypeVar[6]),32);
    bufp->chgIData(oldp+7,(__VdtypeVar[7]),32);
    bufp->chgIData(oldp+8,(__VdtypeVar[8]),32);
    bufp->chgIData(oldp+9,(__VdtypeVar[9]),32);
    bufp->chgIData(oldp+10,(__VdtypeVar[10]),32);
    bufp->chgIData(oldp+11,(__VdtypeVar[11]),32);
    bufp->chgIData(oldp+12,(__VdtypeVar[12]),32);
    bufp->chgIData(oldp+13,(__VdtypeVar[13]),32);
    bufp->chgIData(oldp+14,(__VdtypeVar[14]),32);
    bufp->chgIData(oldp+15,(__VdtypeVar[15]),32);
    bufp->chgIData(oldp+16,(__VdtypeVar[16]),32);
    bufp->chgIData(oldp+17,(__VdtypeVar[17]),32);
    bufp->chgIData(oldp+18,(__VdtypeVar[18]),32);
    bufp->chgIData(oldp+19,(__VdtypeVar[19]),32);
    bufp->chgIData(oldp+20,(__VdtypeVar[20]),32);
    bufp->chgIData(oldp+21,(__VdtypeVar[21]),32);
    bufp->chgIData(oldp+22,(__VdtypeVar[22]),32);
    bufp->chgIData(oldp+23,(__VdtypeVar[23]),32);
    bufp->chgIData(oldp+24,(__VdtypeVar[24]),32);
    bufp->chgIData(oldp+25,(__VdtypeVar[25]),32);
    bufp->chgIData(oldp+26,(__VdtypeVar[26]),32);
    bufp->chgIData(oldp+27,(__VdtypeVar[27]),32);
    bufp->chgIData(oldp+28,(__VdtypeVar[28]),32);
    bufp->chgIData(oldp+29,(__VdtypeVar[29]),32);
    bufp->chgIData(oldp+30,(__VdtypeVar[30]),32);
    bufp->chgIData(oldp+31,(__VdtypeVar[31]),32);
}

void Vcpu_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root__trace_cleanup\n"); );
    // Body
    Vcpu_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcpu_top___024root*>(voidSelf);
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
