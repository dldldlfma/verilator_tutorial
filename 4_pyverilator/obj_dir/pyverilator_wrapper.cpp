#include <cstddef>
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vcnt.h"
    
// pyverilator defined values
// first declare variables as extern
extern const char* _pyverilator_module_name;
extern const uint32_t _pyverilator_num_inputs;
extern const char* _pyverilator_inputs[];
extern const uint32_t _pyverilator_input_widths[];
extern const uint32_t _pyverilator_num_outputs;
extern const char* _pyverilator_outputs[];
extern const uint32_t _pyverilator_output_widths[];
extern const uint32_t _pyverilator_num_internal_signals;
extern const char* _pyverilator_internal_signals[];
extern const uint32_t _pyverilator_internal_signal_widths[];
extern const uint32_t _pyverilator_num_rules;
extern const char* _pyverilator_rules[];
extern const char* _pyverilator_json_data;
// now initialize the variables
const char* _pyverilator_module_name = "Vcnt";
const uint32_t _pyverilator_num_inputs = 2;
const char* _pyverilator_inputs[] = {"clk","rstn"};
const uint32_t _pyverilator_input_widths[] = {1,1};

const uint32_t _pyverilator_num_outputs = 2;
const char* _pyverilator_outputs[] = {"chk_3","out"};
const uint32_t _pyverilator_output_widths[] = {1,16};

const uint32_t _pyverilator_num_internal_signals = 0;
const char* _pyverilator_internal_signals[] = {};
const uint32_t _pyverilator_internal_signal_widths[] = {};

const char* _pyverilator_json_data = "null";

// this is required by verilator for verilog designs using $time
// main_time is incremented in eval
double main_time = 0;
    
double sc_time_stamp() {
return main_time;
}
// function definitions
// helper functions for basic verilator tasks
extern "C" { //Open an extern C closed in the footer
Vcnt* construct() {
    Verilated::commandArgs(0, (const char**) nullptr);
    Verilated::traceEverOn(true);
    Vcnt* top = new Vcnt();
    return top;
}
int eval(Vcnt* top) {
    top->eval();
    main_time++;
    return 0;
}
int destruct(Vcnt* top) {
    if (top != nullptr) {
        delete top;
        top = nullptr;
    }
    return 0;
}
VerilatedVcdC* start_vcd_trace(Vcnt* top, const char* filename) {
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open(filename);
    return tfp;
}
int add_to_vcd_trace(VerilatedVcdC* tfp, int time) {
    tfp->dump(time);
    return 0;
}
int flush_vcd_trace(VerilatedVcdC* tfp) {
    tfp->flush();
    return 0;
}
int stop_vcd_trace(VerilatedVcdC* tfp) {
    tfp->close();
    return 0;
}
uint32_t get_chk_3(Vcnt* top){return top->chk_3;}
uint32_t get_out(Vcnt* top){return top->out;}
uint32_t get_clk(Vcnt* top){return top->clk;}
uint32_t get_rstn(Vcnt* top){return top->rstn;}
int set_clk(Vcnt* top, uint32_t new_value){ top->clk = new_value; return 0;}
int set_rstn(Vcnt* top, uint32_t new_value){ top->rstn = new_value; return 0;}
}