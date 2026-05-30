// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu_top.h for the primary calling header

#include "Vcpu_top__pch.h"

VL_ATTR_COLD void Vcpu_top___024root___eval_static(Vcpu_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___eval_static\n"); );
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
}

VL_ATTR_COLD void Vcpu_top___024root___eval_initial__TOP(Vcpu_top___024root* vlSelf);
VL_ATTR_COLD void Vcpu_top___024root____Vm_traceActivitySetAll(Vcpu_top___024root* vlSelf);

VL_ATTR_COLD void Vcpu_top___024root___eval_initial(Vcpu_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___eval_initial\n"); );
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vcpu_top___024root___eval_initial__TOP(vlSelf);
    Vcpu_top___024root____Vm_traceActivitySetAll(vlSelf);
}

VL_ATTR_COLD void Vcpu_top___024root___eval_initial__TOP(Vcpu_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___eval_initial__TOP\n"); );
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cpu_top__DOT__u_imem__DOT__idx = 0U;
    while (VL_GTS_III(32, 0x00000100U, vlSelfRef.cpu_top__DOT__u_imem__DOT__idx)) {
        vlSelfRef.cpu_top__DOT__u_imem__DOT__memory[(0x000000ffU 
                                                     & vlSelfRef.cpu_top__DOT__u_imem__DOT__idx)] = 0x00000013U;
        vlSelfRef.cpu_top__DOT__u_imem__DOT__idx = 
            ((IData)(1U) + vlSelfRef.cpu_top__DOT__u_imem__DOT__idx);
    }
    VL_READMEM_N(true, 32, 256, 0, "tb/programs/fibonacci.hex"s
                 ,  &(vlSelfRef.cpu_top__DOT__u_imem__DOT__memory)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vcpu_top___024root___eval_final(Vcpu_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___eval_final\n"); );
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcpu_top___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vcpu_top___024root___eval_phase__stl(Vcpu_top___024root* vlSelf);

VL_ATTR_COLD void Vcpu_top___024root___eval_settle(Vcpu_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___eval_settle\n"); );
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vcpu_top___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("rtl/cpu_top.sv", 1, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vcpu_top___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void Vcpu_top___024root___eval_triggers_vec__stl(Vcpu_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___eval_triggers_vec__stl\n"); );
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool Vcpu_top___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcpu_top___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vcpu_top___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vcpu_top___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void Vcpu_top___024root___stl_sequent__TOP__0(Vcpu_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___stl_sequent__TOP__0\n"); );
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VdfgRegularize_hebeb780c_0_2;
    __VdfgRegularize_hebeb780c_0_2 = 0;
    IData/*31:0*/ __VdfgRegularize_hebeb780c_0_7;
    __VdfgRegularize_hebeb780c_0_7 = 0;
    IData/*31:0*/ __VdfgRegularize_hebeb780c_0_8;
    __VdfgRegularize_hebeb780c_0_8 = 0;
    // Body
    vlSelfRef.current_pc = vlSelfRef.cpu_top__DOT__pc_value;
    vlSelfRef.done = (1U == vlSelfRef.cpu_top__DOT__u_regfile__DOT__regs[31U]);
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

VL_ATTR_COLD void Vcpu_top___024root___eval_stl(Vcpu_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___eval_stl\n"); );
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vcpu_top___024root___stl_sequent__TOP__0(vlSelf);
        Vcpu_top___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD bool Vcpu_top___024root___eval_phase__stl(Vcpu_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___eval_phase__stl\n"); );
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vcpu_top___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vcpu_top___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vcpu_top___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vcpu_top___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vcpu_top___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcpu_top___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vcpu_top___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vcpu_top___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcpu_top___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vcpu_top___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge rst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vcpu_top___024root____Vm_traceActivitySetAll(Vcpu_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root____Vm_traceActivitySetAll\n"); );
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
}

VL_ATTR_COLD void Vcpu_top___024root___ctor_var_reset(Vcpu_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___ctor_var_reset\n"); );
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    vlSelf->trace_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11264829231473181110ull);
    vlSelf->dump_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16498917106003865071ull);
    vlSelf->debug_reg_sel = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4351353104227700034ull);
    vlSelf->debug_mem_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18168658026817720631ull);
    vlSelf->debug_reg_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5935281208463159607ull);
    vlSelf->debug_mem_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14020191466538687913ull);
    vlSelf->current_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15397944574740657099ull);
    vlSelf->current_instruction = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10984701081294471239ull);
    vlSelf->done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10296494685231209730ull);
    vlSelf->illegal_instr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12045999000215415863ull);
    vlSelf->cycle_count = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 812857792956672393ull);
    vlSelf->instr_count = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 7966963620822421759ull);
    vlSelf->cpu_top__DOT__pc_value = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7324733526916694125ull);
    vlSelf->cpu_top__DOT__alu_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7842045025179981151ull);
    vlSelf->cpu_top__DOT__mem_read_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15539237501625122025ull);
    vlSelf->cpu_top__DOT__branch_taken = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5870245560599680268ull);
    vlSelf->cpu_top__DOT__branch_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10931168599543251773ull);
    vlSelf->cpu_top__DOT__overflow_flag = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12504648497207485036ull);
    vlSelf->cpu_top__DOT__control = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 8982289802257456651ull);
    vlSelf->cpu_top__DOT__u_pc__DOT__pc_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16979688932896713898ull);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->cpu_top__DOT__u_imem__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12343529338412110252ull);
    }
    vlSelf->cpu_top__DOT__u_imem__DOT__idx = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5235335543628489972ull);
    vlSelf->cpu_top__DOT__u_immgen__DOT__immediate = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6692673945020079811ull);
    vlSelf->cpu_top__DOT__u_regfile__DOT__write_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17752536009893358862ull);
    vlSelf->cpu_top__DOT__u_regfile__DOT__rs1_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13788285281633261071ull);
    vlSelf->cpu_top__DOT__u_regfile__DOT__rs2_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4948295526591918208ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->cpu_top__DOT__u_regfile__DOT__regs[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14462117570397774468ull);
    }
    vlSelf->cpu_top__DOT__u_regfile__DOT__idx = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17663138337543844951ull);
    vlSelf->cpu_top__DOT__u_alu__DOT__op_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8542115977624215911ull);
    vlSelf->cpu_top__DOT__u_alu__DOT__op_b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12381307955586110675ull);
    vlSelf->cpu_top__DOT__u_branch__DOT__branch_condition = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14801684657827712902ull);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->cpu_top__DOT__u_dmem__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16881314996894956700ull);
    }
    vlSelf->cpu_top__DOT__u_dmem__DOT__idx = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3937054230203556999ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
