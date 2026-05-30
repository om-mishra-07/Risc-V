// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vcpu_top__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vcpu_top::Vcpu_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vcpu_top__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , trace_en{vlSymsp->TOP.trace_en}
    , dump_en{vlSymsp->TOP.dump_en}
    , debug_reg_sel{vlSymsp->TOP.debug_reg_sel}
    , done{vlSymsp->TOP.done}
    , illegal_instr{vlSymsp->TOP.illegal_instr}
    , debug_mem_addr{vlSymsp->TOP.debug_mem_addr}
    , debug_reg_data{vlSymsp->TOP.debug_reg_data}
    , debug_mem_data{vlSymsp->TOP.debug_mem_data}
    , current_pc{vlSymsp->TOP.current_pc}
    , current_instruction{vlSymsp->TOP.current_instruction}
    , cycle_count{vlSymsp->TOP.cycle_count}
    , instr_count{vlSymsp->TOP.instr_count}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vcpu_top::Vcpu_top(const char* _vcname__)
    : Vcpu_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vcpu_top::~Vcpu_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vcpu_top___024root___eval_debug_assertions(Vcpu_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vcpu_top___024root___eval_static(Vcpu_top___024root* vlSelf);
void Vcpu_top___024root___eval_initial(Vcpu_top___024root* vlSelf);
void Vcpu_top___024root___eval_settle(Vcpu_top___024root* vlSelf);
void Vcpu_top___024root___eval(Vcpu_top___024root* vlSelf);

void Vcpu_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcpu_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vcpu_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vcpu_top___024root___eval_static(&(vlSymsp->TOP));
        Vcpu_top___024root___eval_initial(&(vlSymsp->TOP));
        Vcpu_top___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vcpu_top___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vcpu_top::eventsPending() { return false; }

uint64_t Vcpu_top::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vcpu_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vcpu_top___024root___eval_final(Vcpu_top___024root* vlSelf);

VL_ATTR_COLD void Vcpu_top::final() {
    contextp()->executingFinal(true);
    Vcpu_top___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vcpu_top::hierName() const { return vlSymsp->name(); }
const char* Vcpu_top::modelName() const { return "Vcpu_top"; }
unsigned Vcpu_top::threads() const { return 1; }
void Vcpu_top::prepareClone() const { contextp()->prepareClone(); }
void Vcpu_top::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vcpu_top::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false}};
};

//============================================================
// Trace configuration

void Vcpu_top___024root__trace_decl_types(VerilatedVcd* tracep);

void Vcpu_top___024root__trace_init_top(Vcpu_top___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vcpu_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcpu_top___024root*>(voidSelf);
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    Vcpu_top___024root__trace_decl_types(tracep);
    Vcpu_top___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vcpu_top___024root__trace_register(Vcpu_top___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vcpu_top::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vcpu_top::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP), name(), false, 125);
    Vcpu_top___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
