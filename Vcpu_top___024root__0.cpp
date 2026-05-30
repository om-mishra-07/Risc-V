// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu_top.h for the primary calling header

#include "Vcpu_top__pch.h"

void Vcpu_top___024root___eval_triggers_vec__ico(Vcpu_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___eval_triggers_vec__ico\n"); );
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
}

bool Vcpu_top___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vcpu_top___024root___ico_sequent__TOP__0(Vcpu_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___ico_sequent__TOP__0\n"); );
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_reg_data = (vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs
                                [vlSelfRef.debug_reg_sel] 
                                & (- (IData)((0U != (IData)(vlSelfRef.debug_reg_sel)))));
    vlSelfRef.debug_mem_data = (((((IData)(vlSelfRef.cpu_top__DOT__u_dmem__DOT__memory
                                           [(0x00000fffU 
                                             & ((IData)(3U) 
                                                + vlSelfRef.debug_mem_addr))]) 
                                   << 8U) | vlSelfRef.cpu_top__DOT__u_dmem__DOT__memory
                                  [(0x00000fffU & ((IData)(2U) 
                                                   + vlSelfRef.debug_mem_addr))]) 
                                 << 0x00000010U) | 
                                (((IData)(vlSelfRef.cpu_top__DOT__u_dmem__DOT__memory
                                          [(0x00000fffU 
                                            & ((IData)(1U) 
                                               + vlSelfRef.debug_mem_addr))]) 
                                  << 8U) | vlSelfRef.cpu_top__DOT__u_dmem__DOT__memory
                                 [(0x00000fffU & vlSelfRef.debug_mem_addr)]));
}

void Vcpu_top___024root___eval_ico(Vcpu_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___eval_ico\n"); );
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vcpu_top___024root___ico_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcpu_top___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vcpu_top___024root___eval_phase__ico(Vcpu_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___eval_phase__ico\n"); );
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vcpu_top___024root___eval_triggers_vec__ico(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vcpu_top___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vcpu_top___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vcpu_top___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vcpu_top___024root___eval_triggers_vec__act(Vcpu_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___eval_triggers_vec__act\n"); );
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((((IData)(vlSelfRef.rst) 
                                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst__0))) 
                                                      << 1U) 
                                                     | ((IData)(vlSelfRef.clk) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
}

bool Vcpu_top___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vcpu_top___024root___nba_sequent__TOP__0(Vcpu_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___nba_sequent__TOP__0\n"); );
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vtask_cpu_top__DOT__u_dmem__DOT__dump_words__1__start_addr;
    __Vtask_cpu_top__DOT__u_dmem__DOT__dump_words__1__start_addr = 0;
    IData/*31:0*/ __Vtask_cpu_top__DOT__u_dmem__DOT__dump_words__1__word_count;
    __Vtask_cpu_top__DOT__u_dmem__DOT__dump_words__1__word_count = 0;
    IData/*31:0*/ __Vtask_cpu_top__DOT__u_dmem__DOT__dump_words__1__word_idx;
    __Vtask_cpu_top__DOT__u_dmem__DOT__dump_words__1__word_idx = 0;
    IData/*31:0*/ __VdfgRegularize_hebeb780c_0_2;
    __VdfgRegularize_hebeb780c_0_2 = 0;
    IData/*31:0*/ __VdfgRegularize_hebeb780c_0_7;
    __VdfgRegularize_hebeb780c_0_7 = 0;
    IData/*31:0*/ __VdfgRegularize_hebeb780c_0_8;
    __VdfgRegularize_hebeb780c_0_8 = 0;
    QData/*63:0*/ __Vdly__cycle_count;
    __Vdly__cycle_count = 0;
    QData/*63:0*/ __Vdly__instr_count;
    __Vdly__instr_count = 0;
    CData/*0:0*/ __VdlySet__cpu_top__DOT__u_regfile__DOT__regs__v0;
    __VdlySet__cpu_top__DOT__u_regfile__DOT__regs__v0 = 0;
    IData/*31:0*/ __VdlyVal__cpu_top__DOT__u_regfile__DOT__regs__v32;
    __VdlyVal__cpu_top__DOT__u_regfile__DOT__regs__v32 = 0;
    CData/*4:0*/ __VdlyDim0__cpu_top__DOT__u_regfile__DOT__regs__v32;
    __VdlyDim0__cpu_top__DOT__u_regfile__DOT__regs__v32 = 0;
    CData/*0:0*/ __VdlySet__cpu_top__DOT__u_regfile__DOT__regs__v32;
    __VdlySet__cpu_top__DOT__u_regfile__DOT__regs__v32 = 0;
    SData/*11:0*/ __VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v0;
    __VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v0 = 0;
    CData/*7:0*/ __VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v1;
    __VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v1 = 0;
    SData/*11:0*/ __VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v1;
    __VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v1 = 0;
    CData/*7:0*/ __VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v2;
    __VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v2 = 0;
    SData/*11:0*/ __VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v2;
    __VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v2 = 0;
    CData/*7:0*/ __VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v3;
    __VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v3 = 0;
    SData/*11:0*/ __VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v3;
    __VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v3 = 0;
    CData/*7:0*/ __VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v4;
    __VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v4 = 0;
    SData/*11:0*/ __VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v4;
    __VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v4 = 0;
    CData/*7:0*/ __VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v5;
    __VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v5 = 0;
    SData/*11:0*/ __VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v5;
    __VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v5 = 0;
    CData/*7:0*/ __VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v6;
    __VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v6 = 0;
    SData/*11:0*/ __VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v6;
    __VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v6 = 0;
    CData/*7:0*/ __VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v7;
    __VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v7 = 0;
    SData/*11:0*/ __VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v7;
    __VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v7 = 0;
    // Body
    __VdlySet__cpu_top__DOT__u_regfile__DOT__regs__v0 = 0U;
    __VdlySet__cpu_top__DOT__u_regfile__DOT__regs__v32 = 0U;
    __Vdly__cycle_count = vlSelfRef.cycle_count;
    __Vdly__instr_count = vlSelfRef.instr_count;
    if (vlSelfRef.rst) {
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__idx = 0x00000020U;
    }
    if (vlSelfRef.rst) {
        vlSelfRef.cpu_top__DOT__u_dmem__DOT__idx = 0U;
        while (VL_GTS_III(32, 0x00001000U, vlSelfRef.cpu_top__DOT__u_dmem__DOT__idx)) {
            __VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v0 
                = (0x00000fffU & vlSelfRef.cpu_top__DOT__u_dmem__DOT__idx);
            vlSelfRef.__VdlyCommitQueuecpu_top__DOT__u_dmem__DOT__memory.enqueue(0U, (IData)(__VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v0));
            vlSelfRef.cpu_top__DOT__u_dmem__DOT__idx 
                = ((IData)(1U) + vlSelfRef.cpu_top__DOT__u_dmem__DOT__idx);
        }
    } else if ((0x00000080U & (IData)(vlSelfRef.cpu_top__DOT__control))) {
        if ((1U & (~ VL_ONEHOT_I((((1U == (7U & (vlSelfRef.current_instruction 
                                                 >> 0x0000000cU))) 
                                   << 1U) | (0U == 
                                             (7U & 
                                              (vlSelfRef.current_instruction 
                                               >> 0x0000000cU)))))))) {
            if ((0U != (((1U == (7U & (vlSelfRef.current_instruction 
                                       >> 0x0000000cU))) 
                         << 1U) | (0U == (7U & (vlSelfRef.current_instruction 
                                                >> 0x0000000cU)))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: data_memory.sv:25: Assertion failed in %m: unique case, but multiple matches found for '3'h%X'\n",4, 'M',vlSymsp->name(),"cpu_top.u_dmem", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',3,(7U & (vlSelfRef.current_instruction 
                                                >> 0x0000000cU)));
                    VL_STOP_MT("rtl/data_memory.sv", 25, "");
                }
            }
        }
        if ((0U == (7U & (vlSelfRef.current_instruction 
                          >> 0x0000000cU)))) {
            __VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v1 
                = (0x000000ffU & vlSelfRef.cpu_top__DOT__u_regfile__DOT__rs2_data);
            __VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v1 
                = (0x00000fffU & vlSelfRef.cpu_top__DOT__alu_result);
            vlSelfRef.__VdlyCommitQueuecpu_top__DOT__u_dmem__DOT__memory.enqueue(__VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v1, (IData)(__VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v1));
        } else if ((1U == (7U & (vlSelfRef.current_instruction 
                                 >> 0x0000000cU)))) {
            __VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v2 
                = (0x000000ffU & vlSelfRef.cpu_top__DOT__u_regfile__DOT__rs2_data);
            __VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v2 
                = (0x00000fffU & vlSelfRef.cpu_top__DOT__alu_result);
            vlSelfRef.__VdlyCommitQueuecpu_top__DOT__u_dmem__DOT__memory.enqueue(__VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v2, (IData)(__VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v2));
            __VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v3 
                = (0x000000ffU & (vlSelfRef.cpu_top__DOT__u_regfile__DOT__rs2_data 
                                  >> 8U));
            __VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v3 
                = (0x00000fffU & ((IData)(1U) + vlSelfRef.cpu_top__DOT__alu_result));
            vlSelfRef.__VdlyCommitQueuecpu_top__DOT__u_dmem__DOT__memory.enqueue(__VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v3, (IData)(__VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v3));
        } else {
            __VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v4 
                = (0x000000ffU & vlSelfRef.cpu_top__DOT__u_regfile__DOT__rs2_data);
            __VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v4 
                = (0x00000fffU & vlSelfRef.cpu_top__DOT__alu_result);
            vlSelfRef.__VdlyCommitQueuecpu_top__DOT__u_dmem__DOT__memory.enqueue(__VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v4, (IData)(__VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v4));
            __VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v5 
                = (0x000000ffU & (vlSelfRef.cpu_top__DOT__u_regfile__DOT__rs2_data 
                                  >> 8U));
            __VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v5 
                = (0x00000fffU & ((IData)(1U) + vlSelfRef.cpu_top__DOT__alu_result));
            vlSelfRef.__VdlyCommitQueuecpu_top__DOT__u_dmem__DOT__memory.enqueue(__VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v5, (IData)(__VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v5));
            __VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v6 
                = (0x000000ffU & (vlSelfRef.cpu_top__DOT__u_regfile__DOT__rs2_data 
                                  >> 0x10U));
            __VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v6 
                = (0x00000fffU & ((IData)(2U) + vlSelfRef.cpu_top__DOT__alu_result));
            vlSelfRef.__VdlyCommitQueuecpu_top__DOT__u_dmem__DOT__memory.enqueue(__VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v6, (IData)(__VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v6));
            __VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v7 
                = (vlSelfRef.cpu_top__DOT__u_regfile__DOT__rs2_data 
                   >> 0x18U);
            __VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v7 
                = (0x00000fffU & ((IData)(3U) + vlSelfRef.cpu_top__DOT__alu_result));
            vlSelfRef.__VdlyCommitQueuecpu_top__DOT__u_dmem__DOT__memory.enqueue(__VdlyVal__cpu_top__DOT__u_dmem__DOT__memory__v7, (IData)(__VdlyDim0__cpu_top__DOT__u_dmem__DOT__memory__v7));
        }
    }
    if (vlSelfRef.rst) {
        __VdlySet__cpu_top__DOT__u_regfile__DOT__regs__v0 = 1U;
    } else if ((((~ (IData)(vlSelfRef.illegal_instr)) 
                 & ((IData)(vlSelfRef.cpu_top__DOT__control) 
                    >> 0x0000000cU)) & (0U != (0x0000001fU 
                                               & (vlSelfRef.current_instruction 
                                                  >> 7U))))) {
        __VdlyVal__cpu_top__DOT__u_regfile__DOT__regs__v32 
            = vlSelfRef.cpu_top__DOT__u_regfile__DOT__write_data;
        __VdlyDim0__cpu_top__DOT__u_regfile__DOT__regs__v32 
            = (0x0000001fU & (vlSelfRef.current_instruction 
                              >> 7U));
        __VdlySet__cpu_top__DOT__u_regfile__DOT__regs__v32 = 1U;
    }
    if (vlSelfRef.rst) {
        __Vdly__cycle_count = 0ULL;
        __Vdly__instr_count = 0ULL;
    } else {
        __Vdly__cycle_count = (1ULL + vlSelfRef.cycle_count);
        if (((~ (IData)(vlSelfRef.illegal_instr)) & 
             (0x00000013U != vlSelfRef.current_instruction))) {
            __Vdly__instr_count = (1ULL + vlSelfRef.instr_count);
        }
        if (VL_UNLIKELY((((IData)(vlSelfRef.trace_en) 
                          & (~ (IData)(vlSelfRef.illegal_instr)))))) {
            VL_WRITEF_NX("[SC-TRACE] pc=0x%08h instr=0x%08h rd=x%0d wb=0x%08h branch=%0b target=0x%08h z=%0b n=%0b ov=%0b\n",9
                         , '#',32,vlSelfRef.cpu_top__DOT__pc_value
                         , '#',32,vlSelfRef.current_instruction
                         , '#',5,(0x0000001fU & (vlSelfRef.current_instruction 
                                                 >> 7U))
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__write_data
                         , '#',1,(IData)(vlSelfRef.cpu_top__DOT__branch_taken)
                         , '#',32,vlSelfRef.cpu_top__DOT__branch_target
                         , '#',1,(0U == vlSelfRef.cpu_top__DOT__alu_result)
                         , '#',1,(vlSelfRef.cpu_top__DOT__alu_result 
                                  >> 0x0000001fU), '#',1,(IData)(vlSelfRef.cpu_top__DOT__overflow_flag));
        }
        if (VL_UNLIKELY((vlSelfRef.dump_en))) {
            VL_WRITEF_NX("---- Register File Dump ----\nx0 = 0x%08h\nx1 = 0x%08h\nx2 = 0x%08h\nx3 = 0x%08h\nx4 = 0x%08h\nx5 = 0x%08h\nx6 = 0x%08h\nx7 = 0x%08h\nx8 = 0x%08h\nx9 = 0x%08h\nx10 = 0x%08h\nx11 = 0x%08h\nx12 = 0x%08h\nx13 = 0x%08h\nx14 = 0x%08h\nx15 = 0x%08h\nx16 = 0x%08h\nx17 = 0x%08h\nx18 = 0x%08h\nx19 = 0x%08h\nx20 = 0x%08h\nx21 = 0x%08h\nx22 = 0x%08h\nx23 = 0x%08h\nx24 = 0x%08h\nx25 = 0x%08h\nx26 = 0x%08h\nx27 = 0x%08h\nx28 = 0x%08h\nx29 = 0x%08h\nx30 = 0x%08h\nx31 = 0x%08h\n",32
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[0U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[1U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[2U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[3U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[4U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[5U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[6U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[7U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[8U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[9U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[10U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[11U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[12U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[13U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[14U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[15U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[16U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[17U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[18U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[19U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[20U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[21U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[22U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[23U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[24U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[25U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[26U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[27U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[28U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[29U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[30U]
                         , '#',32,vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[31U]);
            __Vtask_cpu_top__DOT__u_dmem__DOT__dump_words__1__word_count = 4U;
            __Vtask_cpu_top__DOT__u_dmem__DOT__dump_words__1__start_addr = 0x00000100U;
            VL_WRITEF_NX("---- Data Memory Dump ----\n",0);
            __Vtask_cpu_top__DOT__u_dmem__DOT__dump_words__1__word_idx = 0U;
            while (VL_LTS_III(32, __Vtask_cpu_top__DOT__u_dmem__DOT__dump_words__1__word_idx, __Vtask_cpu_top__DOT__u_dmem__DOT__dump_words__1__word_count)) {
                VL_WRITEF_NX("mem[0x%08h] = 0x%08h\n",2
                             , '~',32,(__Vtask_cpu_top__DOT__u_dmem__DOT__dump_words__1__start_addr 
                                       + VL_MULS_III(32, (IData)(4U), __Vtask_cpu_top__DOT__u_dmem__DOT__dump_words__1__word_idx))
                             , '#',32,(((((IData)(vlSelfRef.cpu_top__DOT__u_dmem__DOT__memory
                                                  [
                                                  (0x00000fffU 
                                                   & ((IData)(3U) 
                                                      + 
                                                      (__Vtask_cpu_top__DOT__u_dmem__DOT__dump_words__1__start_addr 
                                                       + 
                                                       VL_MULS_III(32, (IData)(4U), __Vtask_cpu_top__DOT__u_dmem__DOT__dump_words__1__word_idx))))]) 
                                          << 8U) | vlSelfRef.cpu_top__DOT__u_dmem__DOT__memory
                                         [(0x00000fffU 
                                           & ((IData)(2U) 
                                              + (__Vtask_cpu_top__DOT__u_dmem__DOT__dump_words__1__start_addr 
                                                 + 
                                                 VL_MULS_III(32, (IData)(4U), __Vtask_cpu_top__DOT__u_dmem__DOT__dump_words__1__word_idx))))]) 
                                        << 0x00000010U) 
                                       | (((IData)(vlSelfRef.cpu_top__DOT__u_dmem__DOT__memory
                                                   [
                                                   (0x00000fffU 
                                                    & ((IData)(1U) 
                                                       + 
                                                       (__Vtask_cpu_top__DOT__u_dmem__DOT__dump_words__1__start_addr 
                                                        + 
                                                        VL_MULS_III(32, (IData)(4U), __Vtask_cpu_top__DOT__u_dmem__DOT__dump_words__1__word_idx))))]) 
                                           << 8U) | vlSelfRef.cpu_top__DOT__u_dmem__DOT__memory
                                          [(0x00000fffU 
                                            & (__Vtask_cpu_top__DOT__u_dmem__DOT__dump_words__1__start_addr 
                                               + VL_MULS_III(32, (IData)(4U), __Vtask_cpu_top__DOT__u_dmem__DOT__dump_words__1__word_idx)))])));
                __Vtask_cpu_top__DOT__u_dmem__DOT__dump_words__1__word_idx 
                    = ((IData)(1U) + __Vtask_cpu_top__DOT__u_dmem__DOT__dump_words__1__word_idx);
            }
        }
    }
    vlSelfRef.cycle_count = __Vdly__cycle_count;
    vlSelfRef.instr_count = __Vdly__instr_count;
    vlSelfRef.__VdlyCommitQueuecpu_top__DOT__u_dmem__DOT__memory.commit(vlSelfRef.cpu_top__DOT__u_dmem__DOT__memory);
    vlSelfRef.cpu_top__DOT__pc_value = ((IData)(vlSelfRef.rst)
                                         ? 0U : vlSelfRef.cpu_top__DOT__u_pc__DOT__pc_next);
    if (__VdlySet__cpu_top__DOT__u_regfile__DOT__regs__v0) {
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[0U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[1U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[2U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[3U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[4U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[5U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[6U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[7U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[8U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[9U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[10U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[11U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[12U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[13U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[14U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[15U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[16U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[17U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[18U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[19U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[20U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[21U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[22U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[23U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[24U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[25U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[26U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[27U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[28U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[29U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[30U] = 0U;
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[31U] = 0U;
    }
    if (__VdlySet__cpu_top__DOT__u_regfile__DOT__regs__v32) {
        vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[__VdlyDim0__cpu_top__DOT__u_regfile__DOT__regs__v32] 
            = __VdlyVal__cpu_top__DOT__u_regfile__DOT__regs__v32;
    }
    vlSelfRef.debug_mem_data = (((((IData)(vlSelfRef.cpu_top__DOT__u_dmem__DOT__memory
                                           [(0x00000fffU 
                                             & ((IData)(3U) 
                                                + vlSelfRef.debug_mem_addr))]) 
                                   << 8U) | vlSelfRef.cpu_top__DOT__u_dmem__DOT__memory
                                  [(0x00000fffU & ((IData)(2U) 
                                                   + vlSelfRef.debug_mem_addr))]) 
                                 << 0x00000010U) | 
                                (((IData)(vlSelfRef.cpu_top__DOT__u_dmem__DOT__memory
                                          [(0x00000fffU 
                                            & ((IData)(1U) 
                                               + vlSelfRef.debug_mem_addr))]) 
                                  << 8U) | vlSelfRef.cpu_top__DOT__u_dmem__DOT__memory
                                 [(0x00000fffU & vlSelfRef.debug_mem_addr)]));
    vlSelfRef.done = (1U == vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[31U]);
    vlSelfRef.debug_reg_data = (vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs
                                [vlSelfRef.debug_reg_sel] 
                                & (- (IData)((0U != (IData)(vlSelfRef.debug_reg_sel)))));
    vlSelfRef.current_pc = vlSelfRef.cpu_top__DOT__pc_value;
    vlSelfRef.current_instruction = vlSelfRef.cpu_top__DOT__u_imem__DOT__memory
        [(0x000000ffU & (vlSelfRef.cpu_top__DOT__pc_value 
                         >> 2U))];
    if ((1U & (~ VL_ONEHOT_I((((0x17U == (0x0000007fU 
                                          & vlSelfRef.current_instruction)) 
                               << 1U) | (0x37U == (0x0000007fU 
                                                   & vlSelfRef.current_instruction))))))) {
        if ((0U != (((0x17U == (0x0000007fU & vlSelfRef.current_instruction)) 
                     << 1U) | (0x37U == (0x0000007fU 
                                         & vlSelfRef.current_instruction))))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: cpu_top.sv:99: Assertion failed in %m: unique case, but multiple matches found for '7'h%X'\n",4, 'M',vlSymsp->name(),"cpu_top", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(0x0000007fU & vlSelfRef.current_instruction));
                VL_STOP_MT("rtl/cpu_top.sv", 99, "");
            }
        }
    }
    vlSelfRef.illegal_instr = 0U;
    vlSelfRef.cpu_top__DOT__u_regfile__DOT__rs1_data 
        = (vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs
           [(0x0000001fU & (vlSelfRef.current_instruction 
                            >> 0x0000000fU))] & (- (IData)(
                                                           (0U 
                                                            != 
                                                            (0x0000001fU 
                                                             & (vlSelfRef.current_instruction 
                                                                >> 0x0000000fU))))));
    vlSelfRef.cpu_top__DOT__u_regfile__DOT__rs2_data 
        = (vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs
           [(0x0000001fU & (vlSelfRef.current_instruction 
                            >> 0x00000014U))] & (- (IData)(
                                                           (0U 
                                                            != 
                                                            (0x0000001fU 
                                                             & (vlSelfRef.current_instruction 
                                                                >> 0x00000014U))))));
    __VdfgRegularize_hebeb780c_0_7 = (0xfffff000U & 
                                      (vlSelfRef.current_instruction 
                                       & (- (IData)(
                                                    (3U 
                                                     == 
                                                     (3U 
                                                      & vlSelfRef.current_instruction))))));
    vlSelfRef.cpu_top__DOT__control = 0U;
    __VdfgRegularize_hebeb780c_0_2 = ((((- (IData)(
                                                   (vlSelfRef.current_instruction 
                                                    >> 0x0000001fU))) 
                                        << 0x0000000cU) 
                                       | (vlSelfRef.current_instruction 
                                          >> 0x00000014U)) 
                                      & (- (IData)(
                                                   (3U 
                                                    == 
                                                    (3U 
                                                     & vlSelfRef.current_instruction)))));
    __VdfgRegularize_hebeb780c_0_8 = (__VdfgRegularize_hebeb780c_0_2 
                                      & ((- (IData)(
                                                    (1U 
                                                     & (~ 
                                                        (vlSelfRef.current_instruction 
                                                         >> 3U))))) 
                                         & (- (IData)(
                                                      (1U 
                                                       & (~ 
                                                          (vlSelfRef.current_instruction 
                                                           >> 2U)))))));
    if ((0x00000040U & vlSelfRef.current_instruction)) {
        if ((0x00000020U & vlSelfRef.current_instruction)) {
            if ((0x00000010U & vlSelfRef.current_instruction)) {
                vlSelfRef.illegal_instr = 1U;
            } else if ((8U & vlSelfRef.current_instruction)) {
                if ((4U & vlSelfRef.current_instruction)) {
                    if ((2U & vlSelfRef.current_instruction)) {
                        if ((1U & (~ vlSelfRef.current_instruction))) {
                            vlSelfRef.illegal_instr = 1U;
                        }
                    } else {
                        vlSelfRef.illegal_instr = 1U;
                    }
                } else {
                    vlSelfRef.illegal_instr = 1U;
                }
            } else if ((4U & vlSelfRef.current_instruction)) {
                if ((2U & vlSelfRef.current_instruction)) {
                    if ((1U & (~ vlSelfRef.current_instruction))) {
                        vlSelfRef.illegal_instr = 1U;
                    }
                } else {
                    vlSelfRef.illegal_instr = 1U;
                }
            } else if ((2U & vlSelfRef.current_instruction)) {
                if ((1U & (~ vlSelfRef.current_instruction))) {
                    vlSelfRef.illegal_instr = 1U;
                }
            } else {
                vlSelfRef.illegal_instr = 1U;
            }
            if ((1U & (~ (vlSelfRef.current_instruction 
                          >> 4U)))) {
                if ((8U & vlSelfRef.current_instruction)) {
                    if ((4U & vlSelfRef.current_instruction)) {
                        if ((2U & vlSelfRef.current_instruction)) {
                            if ((1U & vlSelfRef.current_instruction)) {
                                vlSelfRef.cpu_top__DOT__control 
                                    = (0x00001000U 
                                       | (IData)(vlSelfRef.cpu_top__DOT__control));
                                vlSelfRef.cpu_top__DOT__control 
                                    = (0x00000020U 
                                       | (IData)(vlSelfRef.cpu_top__DOT__control));
                                vlSelfRef.cpu_top__DOT__control 
                                    = (0x00000400U 
                                       | (0x19ffU & (IData)(vlSelfRef.cpu_top__DOT__control)));
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.current_instruction)) {
                    if ((2U & vlSelfRef.current_instruction)) {
                        if ((1U & vlSelfRef.current_instruction)) {
                            vlSelfRef.cpu_top__DOT__control 
                                = (0x00001000U | (IData)(vlSelfRef.cpu_top__DOT__control));
                            vlSelfRef.cpu_top__DOT__control 
                                = (0x00000030U | (IData)(vlSelfRef.cpu_top__DOT__control));
                            vlSelfRef.cpu_top__DOT__control 
                                = (0x00000c00U | (0x11ffU 
                                                  & (IData)(vlSelfRef.cpu_top__DOT__control)));
                        }
                    }
                } else if ((2U & vlSelfRef.current_instruction)) {
                    if ((1U & vlSelfRef.current_instruction)) {
                        vlSelfRef.cpu_top__DOT__control 
                            = (0x00000040U | (IData)(vlSelfRef.cpu_top__DOT__control));
                        vlSelfRef.cpu_top__DOT__control 
                            = (1U | (0x1ff0U & (IData)(vlSelfRef.cpu_top__DOT__control)));
                    }
                }
            }
        } else {
            vlSelfRef.illegal_instr = 1U;
        }
        vlSelfRef.cpu_top__DOT__u_immgen__DOT__immediate 
            = (((0x00000010U & vlSelfRef.current_instruction)
                 ? __VdfgRegularize_hebeb780c_0_8 : 
                ((8U & vlSelfRef.current_instruction)
                  ? (((((0x00000ffeU & ((- (IData)(
                                                   (vlSelfRef.current_instruction 
                                                    >> 0x0000001fU))) 
                                        << 1U)) | (vlSelfRef.current_instruction 
                                                   >> 0x0000001fU)) 
                       << 0x00000014U) | ((((0x000001feU 
                                             & (vlSelfRef.current_instruction 
                                                >> 0x0000000bU)) 
                                            | (1U & 
                                               (vlSelfRef.current_instruction 
                                                >> 0x00000014U))) 
                                           << 0x0000000bU) 
                                          | (0x000007feU 
                                             & (vlSelfRef.current_instruction 
                                                >> 0x00000014U)))) 
                     & (- (IData)((7U == (7U & vlSelfRef.current_instruction)))))
                  : ((4U & vlSelfRef.current_instruction)
                      ? __VdfgRegularize_hebeb780c_0_2
                      : ((((- (IData)((vlSelfRef.current_instruction 
                                       >> 0x0000001fU))) 
                           << 0x0000000dU) | ((((2U 
                                                 & (vlSelfRef.current_instruction 
                                                    >> 0x0000001eU)) 
                                                | (1U 
                                                   & (vlSelfRef.current_instruction 
                                                      >> 7U))) 
                                               << 0x0000000bU) 
                                              | ((0x000007e0U 
                                                  & (vlSelfRef.current_instruction 
                                                     >> 0x00000014U)) 
                                                 | (0x0000001eU 
                                                    & (vlSelfRef.current_instruction 
                                                       >> 7U))))) 
                         & (- (IData)((3U == (3U & vlSelfRef.current_instruction)))))))) 
               & (- (IData)((1U & (vlSelfRef.current_instruction 
                                   >> 5U)))));
    } else if ((0x00000020U & vlSelfRef.current_instruction)) {
        if ((0x00000010U & vlSelfRef.current_instruction)) {
            if ((8U & vlSelfRef.current_instruction)) {
                vlSelfRef.illegal_instr = 1U;
            } else if ((4U & vlSelfRef.current_instruction)) {
                if ((2U & vlSelfRef.current_instruction)) {
                    if ((1U & (~ vlSelfRef.current_instruction))) {
                        vlSelfRef.illegal_instr = 1U;
                    }
                } else {
                    vlSelfRef.illegal_instr = 1U;
                }
            } else if ((2U & vlSelfRef.current_instruction)) {
                if ((1U & (~ vlSelfRef.current_instruction))) {
                    vlSelfRef.illegal_instr = 1U;
                }
            } else {
                vlSelfRef.illegal_instr = 1U;
            }
            if ((1U & (~ (vlSelfRef.current_instruction 
                          >> 3U)))) {
                if ((4U & vlSelfRef.current_instruction)) {
                    if ((2U & vlSelfRef.current_instruction)) {
                        if ((1U & vlSelfRef.current_instruction)) {
                            vlSelfRef.cpu_top__DOT__control 
                                = (0x00001000U | (IData)(vlSelfRef.cpu_top__DOT__control));
                            vlSelfRef.cpu_top__DOT__control 
                                = (0x00000600U | (IData)(vlSelfRef.cpu_top__DOT__control));
                            vlSelfRef.cpu_top__DOT__control 
                                = (0x0000000aU | (0x1ff0U 
                                                  & (IData)(vlSelfRef.cpu_top__DOT__control)));
                        }
                    }
                } else if ((2U & vlSelfRef.current_instruction)) {
                    if ((1U & vlSelfRef.current_instruction)) {
                        vlSelfRef.cpu_top__DOT__control 
                            = (0x00001000U | (IData)(vlSelfRef.cpu_top__DOT__control));
                        vlSelfRef.cpu_top__DOT__control 
                            = ((0x1ff0U & (IData)(vlSelfRef.cpu_top__DOT__control)) 
                               | ((0x00004000U & vlSelfRef.current_instruction)
                                   ? ((0x00002000U 
                                       & vlSelfRef.current_instruction)
                                       ? ((0x00001000U 
                                           & vlSelfRef.current_instruction)
                                           ? 2U : 3U)
                                       : ((0x00001000U 
                                           & vlSelfRef.current_instruction)
                                           ? ((0x40000000U 
                                               & vlSelfRef.current_instruction)
                                               ? 9U
                                               : 6U)
                                           : 4U)) : 
                                  ((0x00002000U & vlSelfRef.current_instruction)
                                    ? ((0x00001000U 
                                        & vlSelfRef.current_instruction)
                                        ? 8U : 7U) : 
                                   ((0x00001000U & vlSelfRef.current_instruction)
                                     ? 5U : ((0x40000000U 
                                              & vlSelfRef.current_instruction)
                                              ? 1U : 0U)))));
                    }
                }
            }
            vlSelfRef.cpu_top__DOT__u_immgen__DOT__immediate 
                = ((- (IData)((IData)((4U == (0x0000000cU 
                                              & vlSelfRef.current_instruction))))) 
                   & __VdfgRegularize_hebeb780c_0_7);
        } else {
            if ((8U & vlSelfRef.current_instruction)) {
                vlSelfRef.illegal_instr = 1U;
            } else if ((4U & vlSelfRef.current_instruction)) {
                vlSelfRef.illegal_instr = 1U;
            } else if ((2U & vlSelfRef.current_instruction)) {
                if ((1U & (~ vlSelfRef.current_instruction))) {
                    vlSelfRef.illegal_instr = 1U;
                }
            } else {
                vlSelfRef.illegal_instr = 1U;
            }
            if ((1U & (~ (vlSelfRef.current_instruction 
                          >> 3U)))) {
                if ((1U & (~ (vlSelfRef.current_instruction 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.current_instruction)) {
                        if ((1U & vlSelfRef.current_instruction)) {
                            vlSelfRef.cpu_top__DOT__control 
                                = (0x00000800U | (IData)(vlSelfRef.cpu_top__DOT__control));
                            vlSelfRef.cpu_top__DOT__control 
                                = (0x00000080U | (IData)(vlSelfRef.cpu_top__DOT__control));
                            vlSelfRef.cpu_top__DOT__control 
                                = (0x1ff0U & (IData)(vlSelfRef.cpu_top__DOT__control));
                        }
                    }
                }
            }
            vlSelfRef.cpu_top__DOT__u_immgen__DOT__immediate 
                = ((((- (IData)((vlSelfRef.current_instruction 
                                 >> 0x0000001fU))) 
                     << 0x0000000cU) | ((0x00000fe0U 
                                         & (vlSelfRef.current_instruction 
                                            >> 0x00000014U)) 
                                        | (0x0000001fU 
                                           & (vlSelfRef.current_instruction 
                                              >> 7U)))) 
                   & (- (IData)((IData)((3U == (0x0000000fU 
                                                & vlSelfRef.current_instruction))))));
        }
    } else if ((0x00000010U & vlSelfRef.current_instruction)) {
        if ((8U & vlSelfRef.current_instruction)) {
            vlSelfRef.illegal_instr = 1U;
        } else if ((4U & vlSelfRef.current_instruction)) {
            if ((2U & vlSelfRef.current_instruction)) {
                if ((1U & (~ vlSelfRef.current_instruction))) {
                    vlSelfRef.illegal_instr = 1U;
                }
            } else {
                vlSelfRef.illegal_instr = 1U;
            }
        } else if ((2U & vlSelfRef.current_instruction)) {
            if ((1U & (~ vlSelfRef.current_instruction))) {
                vlSelfRef.illegal_instr = 1U;
            }
        } else {
            vlSelfRef.illegal_instr = 1U;
        }
        if ((1U & (~ (vlSelfRef.current_instruction 
                      >> 3U)))) {
            if ((4U & vlSelfRef.current_instruction)) {
                if ((2U & vlSelfRef.current_instruction)) {
                    if ((1U & vlSelfRef.current_instruction)) {
                        vlSelfRef.cpu_top__DOT__control 
                            = (0x00001800U | (IData)(vlSelfRef.cpu_top__DOT__control));
                        vlSelfRef.cpu_top__DOT__control 
                            = (0x0000000bU | (0x1ff0U 
                                              & (IData)(vlSelfRef.cpu_top__DOT__control)));
                    }
                }
            } else if ((2U & vlSelfRef.current_instruction)) {
                if ((1U & vlSelfRef.current_instruction)) {
                    vlSelfRef.cpu_top__DOT__control 
                        = (0x00001800U | (IData)(vlSelfRef.cpu_top__DOT__control));
                    vlSelfRef.cpu_top__DOT__control 
                        = ((0x1ff0U & (IData)(vlSelfRef.cpu_top__DOT__control)) 
                           | ((0x00004000U & vlSelfRef.current_instruction)
                               ? ((0x00002000U & vlSelfRef.current_instruction)
                                   ? ((0x00001000U 
                                       & vlSelfRef.current_instruction)
                                       ? 2U : 3U) : 
                                  ((0x00001000U & vlSelfRef.current_instruction)
                                    ? ((0x40000000U 
                                        & vlSelfRef.current_instruction)
                                        ? 9U : 6U) : 4U))
                               : ((0x00002000U & vlSelfRef.current_instruction)
                                   ? ((0x00001000U 
                                       & vlSelfRef.current_instruction)
                                       ? 8U : 7U) : 
                                  ((0x00001000U & vlSelfRef.current_instruction)
                                    ? 5U : 0U))));
                }
            }
        }
        vlSelfRef.cpu_top__DOT__u_immgen__DOT__immediate 
            = (((4U & vlSelfRef.current_instruction)
                 ? __VdfgRegularize_hebeb780c_0_7 : __VdfgRegularize_hebeb780c_0_2) 
               & (- (IData)((1U & (~ (vlSelfRef.current_instruction 
                                      >> 3U))))));
    } else {
        if ((8U & vlSelfRef.current_instruction)) {
            vlSelfRef.illegal_instr = 1U;
        } else if ((4U & vlSelfRef.current_instruction)) {
            vlSelfRef.illegal_instr = 1U;
        } else if ((2U & vlSelfRef.current_instruction)) {
            if ((1U & (~ vlSelfRef.current_instruction))) {
                vlSelfRef.illegal_instr = 1U;
            }
        } else {
            vlSelfRef.illegal_instr = 1U;
        }
        if ((1U & (~ (vlSelfRef.current_instruction 
                      >> 3U)))) {
            if ((1U & (~ (vlSelfRef.current_instruction 
                          >> 2U)))) {
                if ((2U & vlSelfRef.current_instruction)) {
                    if ((1U & vlSelfRef.current_instruction)) {
                        vlSelfRef.cpu_top__DOT__control 
                            = (0x00001b00U | (0x00ffU 
                                              & (IData)(vlSelfRef.cpu_top__DOT__control)));
                        vlSelfRef.cpu_top__DOT__control 
                            = (0x1ff0U & (IData)(vlSelfRef.cpu_top__DOT__control));
                    }
                }
            }
        }
        vlSelfRef.cpu_top__DOT__u_immgen__DOT__immediate 
            = __VdfgRegularize_hebeb780c_0_8;
    }
    vlSelfRef.cpu_top__DOT__u_branch__DOT__branch_condition 
        = ((0x00004000U & vlSelfRef.current_instruction)
            ? ((0x00002000U & vlSelfRef.current_instruction)
                ? ((0x00001000U & vlSelfRef.current_instruction)
                    ? (vlSelfRef.cpu_top__DOT__u_regfile__DOT__rs1_data 
                       >= vlSelfRef.cpu_top__DOT__u_regfile__DOT__rs2_data)
                    : (vlSelfRef.cpu_top__DOT__u_regfile__DOT__rs1_data 
                       < vlSelfRef.cpu_top__DOT__u_regfile__DOT__rs2_data))
                : ((0x00001000U & vlSelfRef.current_instruction)
                    ? VL_GTES_III(32, vlSelfRef.cpu_top__DOT__u_regfile__DOT__rs1_data, vlSelfRef.cpu_top__DOT__u_regfile__DOT__rs2_data)
                    : VL_LTS_III(32, vlSelfRef.cpu_top__DOT__u_regfile__DOT__rs1_data, vlSelfRef.cpu_top__DOT__u_regfile__DOT__rs2_data)))
            : ((1U & (~ (vlSelfRef.current_instruction 
                         >> 0x0000000dU))) && ((0x00001000U 
                                                & vlSelfRef.current_instruction)
                                                ? (vlSelfRef.cpu_top__DOT__u_regfile__DOT__rs1_data 
                                                   != vlSelfRef.cpu_top__DOT__u_regfile__DOT__rs2_data)
                                                : (vlSelfRef.cpu_top__DOT__u_regfile__DOT__rs1_data 
                                                   == vlSelfRef.cpu_top__DOT__u_regfile__DOT__rs2_data))));
    if ((0x00000020U & (IData)(vlSelfRef.cpu_top__DOT__control))) {
        vlSelfRef.cpu_top__DOT__branch_taken = 1U;
        vlSelfRef.cpu_top__DOT__branch_target = ((0x00000010U 
                                                  & (IData)(vlSelfRef.cpu_top__DOT__control))
                                                  ? 
                                                 (0xfffffffeU 
                                                  & (vlSelfRef.cpu_top__DOT__u_regfile__DOT__rs1_data 
                                                     + vlSelfRef.cpu_top__DOT__u_immgen__DOT__immediate))
                                                  : 
                                                 (vlSelfRef.cpu_top__DOT__pc_value 
                                                  + vlSelfRef.cpu_top__DOT__u_immgen__DOT__immediate));
    } else if ((((IData)(vlSelfRef.cpu_top__DOT__control) 
                 >> 6U) & (IData)(vlSelfRef.cpu_top__DOT__u_branch__DOT__branch_condition))) {
        vlSelfRef.cpu_top__DOT__branch_taken = 1U;
        vlSelfRef.cpu_top__DOT__branch_target = (vlSelfRef.cpu_top__DOT__pc_value 
                                                 + vlSelfRef.cpu_top__DOT__u_immgen__DOT__immediate);
    } else {
        vlSelfRef.cpu_top__DOT__branch_taken = 0U;
        vlSelfRef.cpu_top__DOT__branch_target = ((IData)(4U) 
                                                 + vlSelfRef.cpu_top__DOT__pc_value);
    }
    vlSelfRef.cpu_top__DOT__u_alu__DOT__op_a = ((0x37U 
                                                 == 
                                                 (0x0000007fU 
                                                  & vlSelfRef.current_instruction))
                                                 ? vlSelfRef.cpu_top__DOT__u_immgen__DOT__immediate
                                                 : 
                                                ((0x17U 
                                                  == 
                                                  (0x0000007fU 
                                                   & vlSelfRef.current_instruction))
                                                  ? vlSelfRef.cpu_top__DOT__pc_value
                                                  : vlSelfRef.cpu_top__DOT__u_regfile__DOT__rs1_data));
    vlSelfRef.cpu_top__DOT__u_alu__DOT__op_b = (((0x00000800U 
                                                  & (IData)(vlSelfRef.cpu_top__DOT__control))
                                                  ? vlSelfRef.cpu_top__DOT__u_immgen__DOT__immediate
                                                  : vlSelfRef.cpu_top__DOT__u_regfile__DOT__rs2_data) 
                                                & (- (IData)(
                                                             (0x37U 
                                                              != 
                                                              (0x0000007fU 
                                                               & vlSelfRef.current_instruction)))));
    vlSelfRef.cpu_top__DOT__u_pc__DOT__pc_next = ((IData)(vlSelfRef.cpu_top__DOT__branch_taken)
                                                   ? vlSelfRef.cpu_top__DOT__branch_target
                                                   : 
                                                  ((IData)(4U) 
                                                   + vlSelfRef.cpu_top__DOT__pc_value));
    vlSelfRef.cpu_top__DOT__overflow_flag = 0U;
    if ((8U & (IData)(vlSelfRef.cpu_top__DOT__control))) {
        vlSelfRef.cpu_top__DOT__alu_result = ((4U & (IData)(vlSelfRef.cpu_top__DOT__control))
                                               ? 0U
                                               : ((2U 
                                                   & (IData)(vlSelfRef.cpu_top__DOT__control))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.cpu_top__DOT__control))
                                                    ? 
                                                   (vlSelfRef.cpu_top__DOT__u_alu__DOT__op_a 
                                                    + vlSelfRef.cpu_top__DOT__u_alu__DOT__op_b)
                                                    : vlSelfRef.cpu_top__DOT__u_alu__DOT__op_a)
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.cpu_top__DOT__control))
                                                    ? 
                                                   VL_SHIFTRS_III(32,32,5, vlSelfRef.cpu_top__DOT__u_alu__DOT__op_a, 
                                                                  (0x0000001fU 
                                                                   & vlSelfRef.cpu_top__DOT__u_alu__DOT__op_b))
                                                    : 
                                                   (vlSelfRef.cpu_top__DOT__u_alu__DOT__op_a 
                                                    < vlSelfRef.cpu_top__DOT__u_alu__DOT__op_b))));
    } else if ((4U & (IData)(vlSelfRef.cpu_top__DOT__control))) {
        vlSelfRef.cpu_top__DOT__alu_result = ((2U & (IData)(vlSelfRef.cpu_top__DOT__control))
                                               ? ((1U 
                                                   & (IData)(vlSelfRef.cpu_top__DOT__control))
                                                   ? 
                                                  VL_LTS_III(32, vlSelfRef.cpu_top__DOT__u_alu__DOT__op_a, vlSelfRef.cpu_top__DOT__u_alu__DOT__op_b)
                                                   : 
                                                  (vlSelfRef.cpu_top__DOT__u_alu__DOT__op_a 
                                                   >> 
                                                   (0x0000001fU 
                                                    & vlSelfRef.cpu_top__DOT__u_alu__DOT__op_b)))
                                               : ((1U 
                                                   & (IData)(vlSelfRef.cpu_top__DOT__control))
                                                   ? 
                                                  (vlSelfRef.cpu_top__DOT__u_alu__DOT__op_a 
                                                   << 
                                                   (0x0000001fU 
                                                    & vlSelfRef.cpu_top__DOT__u_alu__DOT__op_b))
                                                   : 
                                                  (vlSelfRef.cpu_top__DOT__u_alu__DOT__op_a 
                                                   ^ vlSelfRef.cpu_top__DOT__u_alu__DOT__op_b)));
    } else if ((2U & (IData)(vlSelfRef.cpu_top__DOT__control))) {
        vlSelfRef.cpu_top__DOT__alu_result = ((1U & (IData)(vlSelfRef.cpu_top__DOT__control))
                                               ? (vlSelfRef.cpu_top__DOT__u_alu__DOT__op_a 
                                                  | vlSelfRef.cpu_top__DOT__u_alu__DOT__op_b)
                                               : (vlSelfRef.cpu_top__DOT__u_alu__DOT__op_a 
                                                  & vlSelfRef.cpu_top__DOT__u_alu__DOT__op_b));
    } else if ((1U & (IData)(vlSelfRef.cpu_top__DOT__control))) {
        vlSelfRef.cpu_top__DOT__alu_result = (vlSelfRef.cpu_top__DOT__u_alu__DOT__op_a 
                                              - vlSelfRef.cpu_top__DOT__u_alu__DOT__op_b);
        vlSelfRef.cpu_top__DOT__overflow_flag = (((vlSelfRef.cpu_top__DOT__u_alu__DOT__op_a 
                                                   ^ vlSelfRef.cpu_top__DOT__u_alu__DOT__op_b) 
                                                  & (vlSelfRef.cpu_top__DOT__alu_result 
                                                     ^ vlSelfRef.cpu_top__DOT__u_alu__DOT__op_a)) 
                                                 >> 0x1fU);
    } else {
        vlSelfRef.cpu_top__DOT__alu_result = (vlSelfRef.cpu_top__DOT__u_alu__DOT__op_a 
                                              + vlSelfRef.cpu_top__DOT__u_alu__DOT__op_b);
        vlSelfRef.cpu_top__DOT__overflow_flag = (1U 
                                                 & ((~ 
                                                     ((vlSelfRef.cpu_top__DOT__u_alu__DOT__op_a 
                                                       ^ vlSelfRef.cpu_top__DOT__u_alu__DOT__op_b) 
                                                      >> 0x1fU)) 
                                                    & ((vlSelfRef.cpu_top__DOT__alu_result 
                                                        ^ vlSelfRef.cpu_top__DOT__u_alu__DOT__op_a) 
                                                       >> 0x1fU)));
    }
    vlSelfRef.cpu_top__DOT__mem_read_data = 0U;
    if ((0x00000100U & (IData)(vlSelfRef.cpu_top__DOT__control))) {
        vlSelfRef.cpu_top__DOT__mem_read_data = ((0x00004000U 
                                                  & vlSelfRef.current_instruction)
                                                  ? 
                                                 ((0x00002000U 
                                                   & vlSelfRef.current_instruction)
                                                   ? 0U
                                                   : 
                                                  ((0x00001000U 
                                                    & vlSelfRef.current_instruction)
                                                    ? 
                                                   ((vlSelfRef.cpu_top__DOT__u_dmem__DOT__memory
                                                     [
                                                     (0x00000fffU 
                                                      & ((IData)(1U) 
                                                         + vlSelfRef.cpu_top__DOT__alu_result))] 
                                                     << 8U) 
                                                    | vlSelfRef.cpu_top__DOT__u_dmem__DOT__memory
                                                    [
                                                    (0x00000fffU 
                                                     & vlSelfRef.cpu_top__DOT__alu_result)])
                                                    : vlSelfRef.cpu_top__DOT__u_dmem__DOT__memory
                                                   [
                                                   (0x00000fffU 
                                                    & vlSelfRef.cpu_top__DOT__alu_result)]))
                                                  : 
                                                 ((0x00002000U 
                                                   & vlSelfRef.current_instruction)
                                                   ? 
                                                  ((0x00001000U 
                                                    & vlSelfRef.current_instruction)
                                                    ? 0U
                                                    : 
                                                   (((((IData)(vlSelfRef.cpu_top__DOT__u_dmem__DOT__memory
                                                               [
                                                               (0x00000fffU 
                                                                & ((IData)(3U) 
                                                                   + vlSelfRef.cpu_top__DOT__alu_result))]) 
                                                       << 8U) 
                                                      | vlSelfRef.cpu_top__DOT__u_dmem__DOT__memory
                                                      [
                                                      (0x00000fffU 
                                                       & ((IData)(2U) 
                                                          + vlSelfRef.cpu_top__DOT__alu_result))]) 
                                                     << 0x00000010U) 
                                                    | (((IData)(vlSelfRef.cpu_top__DOT__u_dmem__DOT__memory
                                                                [
                                                                (0x00000fffU 
                                                                 & ((IData)(1U) 
                                                                    + vlSelfRef.cpu_top__DOT__alu_result))]) 
                                                        << 8U) 
                                                       | vlSelfRef.cpu_top__DOT__u_dmem__DOT__memory
                                                       [
                                                       (0x00000fffU 
                                                        & vlSelfRef.cpu_top__DOT__alu_result)])))
                                                   : 
                                                  ((0x00001000U 
                                                    & vlSelfRef.current_instruction)
                                                    ? 
                                                   (((- (IData)(
                                                                (1U 
                                                                 & (vlSelfRef.cpu_top__DOT__u_dmem__DOT__memory
                                                                    [
                                                                    (0x00000fffU 
                                                                     & ((IData)(1U) 
                                                                        + vlSelfRef.cpu_top__DOT__alu_result))] 
                                                                    >> 7U)))) 
                                                     << 0x00000010U) 
                                                    | (((IData)(vlSelfRef.cpu_top__DOT__u_dmem__DOT__memory
                                                                [
                                                                (0x00000fffU 
                                                                 & ((IData)(1U) 
                                                                    + vlSelfRef.cpu_top__DOT__alu_result))]) 
                                                        << 8U) 
                                                       | vlSelfRef.cpu_top__DOT__u_dmem__DOT__memory
                                                       [
                                                       (0x00000fffU 
                                                        & vlSelfRef.cpu_top__DOT__alu_result)]))
                                                    : 
                                                   (((- (IData)(
                                                                (1U 
                                                                 & (vlSelfRef.cpu_top__DOT__u_dmem__DOT__memory
                                                                    [
                                                                    (0x00000fffU 
                                                                     & vlSelfRef.cpu_top__DOT__alu_result)] 
                                                                    >> 7U)))) 
                                                     << 8U) 
                                                    | vlSelfRef.cpu_top__DOT__u_dmem__DOT__memory
                                                    [
                                                    (0x00000fffU 
                                                     & vlSelfRef.cpu_top__DOT__alu_result)]))));
    }
    vlSelfRef.cpu_top__DOT__u_regfile__DOT__write_data 
        = ((0x00000400U & (IData)(vlSelfRef.cpu_top__DOT__control))
            ? ((0x00000200U & (IData)(vlSelfRef.cpu_top__DOT__control))
                ? vlSelfRef.cpu_top__DOT__u_immgen__DOT__immediate
                : ((IData)(4U) + vlSelfRef.cpu_top__DOT__pc_value))
            : ((0x00000200U & (IData)(vlSelfRef.cpu_top__DOT__control))
                ? vlSelfRef.cpu_top__DOT__mem_read_data
                : vlSelfRef.cpu_top__DOT__alu_result));
}

void Vcpu_top___024root___eval_nba(Vcpu_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___eval_nba\n"); );
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vcpu_top___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

void Vcpu_top___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcpu_top___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vcpu_top___024root___eval_phase__act(Vcpu_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___eval_phase__act\n"); );
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vcpu_top___024root___eval_triggers_vec__act(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vcpu_top___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vcpu_top___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vcpu_top___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vcpu_top___024root___eval_phase__nba(Vcpu_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___eval_phase__nba\n"); );
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vcpu_top___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vcpu_top___024root___eval_nba(vlSelf);
        Vcpu_top___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vcpu_top___024root___eval(Vcpu_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___eval\n"); );
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vcpu_top___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("rtl/cpu_top.sv", 1, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vcpu_top___024root___eval_phase__ico(vlSelf);
        vlSelfRef.__VicoFirstIteration = 0U;
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vcpu_top___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("rtl/cpu_top.sv", 1, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vcpu_top___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("rtl/cpu_top.sv", 1, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vcpu_top___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vcpu_top___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vcpu_top___024root___eval_debug_assertions(Vcpu_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___eval_debug_assertions\n"); );
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");
    }
    if (VL_UNLIKELY(((vlSelfRef.trace_en & 0xfeU)))) {
        Verilated::overWidthError("trace_en");
    }
    if (VL_UNLIKELY(((vlSelfRef.dump_en & 0xfeU)))) {
        Verilated::overWidthError("dump_en");
    }
    if (VL_UNLIKELY(((vlSelfRef.debug_reg_sel & 0xe0U)))) {
        Verilated::overWidthError("debug_reg_sel");
    }
}
#endif  // VL_DEBUG
