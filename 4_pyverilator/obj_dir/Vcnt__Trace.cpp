// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcnt__Syms.h"


//======================

void Vcnt::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vcnt* t = (Vcnt*)userthis;
    Vcnt__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vcnt::traceChgThis(Vcnt__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcnt* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    if (false && vcdp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vcnt::traceChgThis__2(Vcnt__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcnt* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* oldp = vcdp->oldp(code+1);
    if (false && vcdp && oldp) {}  // Prevent unused
    // Body
    {
        vcdp->chgSData(oldp+0,(vlTOPp->cnt__DOT__mem),16);
    }
}

void Vcnt::traceChgThis__3(Vcnt__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcnt* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* oldp = vcdp->oldp(code+2);
    if (false && vcdp && oldp) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(oldp+0,(vlTOPp->clk));
        vcdp->chgBit(oldp+1,(vlTOPp->rstn));
        vcdp->chgSData(oldp+2,(vlTOPp->out),16);
        vcdp->chgBit(oldp+3,(vlTOPp->chk_3));
    }
}
