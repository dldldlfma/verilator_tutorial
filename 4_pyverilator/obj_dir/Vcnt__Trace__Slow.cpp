// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcnt__Syms.h"


//======================

void Vcnt::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vcnt::traceInit, &Vcnt::traceFull, &Vcnt::traceChg, this);
}
void Vcnt::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vcnt* t = (Vcnt*)userthis;
    Vcnt__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vcnt::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vcnt* t = (Vcnt*)userthis;
    Vcnt__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vcnt::traceInitThis(Vcnt__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcnt* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    if (false && vcdp) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vcnt::traceFullThis(Vcnt__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcnt* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    if (false && vcdp) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vcnt::traceInitThis__1(Vcnt__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcnt* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (false && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+2,"clk", false,-1);
        vcdp->declBit(c+3,"rstn", false,-1);
        vcdp->declBus(c+4,"out", false,-1, 15,0);
        vcdp->declBit(c+5,"chk_3", false,-1);
        vcdp->declBit(c+2,"cnt clk", false,-1);
        vcdp->declBit(c+3,"cnt rstn", false,-1);
        vcdp->declBus(c+4,"cnt out", false,-1, 15,0);
        vcdp->declBit(c+5,"cnt chk_3", false,-1);
        vcdp->declBus(c+1,"cnt mem", false,-1, 15,0);
        vcdp->declBit(c+2,"cnt u0 clk", false,-1);
        vcdp->declBus(c+4,"cnt u0 chk_num", false,-1, 15,0);
        vcdp->declBit(c+5,"cnt u0 chk_out", false,-1);
    }
}

void Vcnt::traceFullThis__1(Vcnt__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcnt* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* oldp = vcdp->oldp(code+1);
    if (false && vcdp && oldp) {}  // Prevent unused
    // Body
    {
        vcdp->fullSData(oldp+0,(vlTOPp->cnt__DOT__mem),16);
        vcdp->fullBit(oldp+1,(vlTOPp->clk));
        vcdp->fullBit(oldp+2,(vlTOPp->rstn));
        vcdp->fullSData(oldp+3,(vlTOPp->out),16);
        vcdp->fullBit(oldp+4,(vlTOPp->chk_3));
    }
}
