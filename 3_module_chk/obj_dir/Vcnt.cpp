// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcnt.h for the primary calling header

#include "Vcnt.h"
#include "Vcnt__Syms.h"

//==========

VL_CTOR_IMP(Vcnt) {
    Vcnt__Syms* __restrict vlSymsp = __VlSymsp = new Vcnt__Syms(this, name());
    Vcnt* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vcnt::__Vconfigure(Vcnt__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-9);
    Verilated::timeprecision(-12);
}

Vcnt::~Vcnt() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vcnt::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcnt::eval\n"); );
    Vcnt__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vcnt* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("cnt.v", 11, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vcnt::_eval_initial_loop(Vcnt__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("cnt.v", 11, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vcnt::_sequent__TOP__1(Vcnt__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcnt::_sequent__TOP__1\n"); );
    Vcnt* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->out = ((IData)(vlTOPp->rstn) ? ((0x12cU 
                                             > (IData)(vlTOPp->out))
                                             ? (0xffffU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlTOPp->out)))
                                             : 0U) : 0U);
    vlTOPp->chk_3 = (0U == VL_MODDIV_III(32, (IData)(vlTOPp->out), (IData)(3U)));
}

void Vcnt::_settle__TOP__2(Vcnt__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcnt::_settle__TOP__2\n"); );
    Vcnt* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->chk_3 = (0U == VL_MODDIV_III(32, (IData)(vlTOPp->out), (IData)(3U)));
}

void Vcnt::_eval(Vcnt__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcnt::_eval\n"); );
    Vcnt* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->rstn)) & (IData)(vlTOPp->__Vclklast__TOP__rstn)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rstn = vlTOPp->rstn;
}

void Vcnt::_eval_initial(Vcnt__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcnt::_eval_initial\n"); );
    Vcnt* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rstn = vlTOPp->rstn;
}

void Vcnt::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcnt::final\n"); );
    // Variables
    Vcnt__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vcnt* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vcnt::_eval_settle(Vcnt__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcnt::_eval_settle\n"); );
    Vcnt* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData Vcnt::_change_request(Vcnt__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcnt::_change_request\n"); );
    Vcnt* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vcnt::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcnt::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rstn & 0xfeU))) {
        Verilated::overWidthError("rstn");}
}
#endif  // VL_DEBUG

void Vcnt::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcnt::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rstn = VL_RAND_RESET_I(1);
    out = VL_RAND_RESET_I(16);
    chk_3 = VL_RAND_RESET_I(1);
    __Vm_traceActivity = 0;
}
