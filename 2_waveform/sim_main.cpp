// DESCRIPTION: Verilator: Verilog example module
//
// This file ONLY is placed under the Creative Commons Public Domain, for
// any use, without warranty, 2017 by Wilson Snyder.
// SPDX-License-Identifier: CC0-1.0
//======================================================================

// Include common routines
#include <verilated.h>

// Include model header, generated from Verilating "top.v"
#include "Vcnt.h"

// Add basic library
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

//get core number
#include <thread>

// for make vcd file which is wavefrom
#include "verilated_vcd_c.h"

using namespace std;


int module_init(Vcnt* top);

int module_init(Vcnt* top){
	cout<< top->rstn <<endl;
	cout<< top->out <<endl;
	top->rstn = 1;
	top->eval();
	top->rstn = 0;
	top->eval();
	top->rstn = 1;
	top->eval();
	return 0;
}

int main(int argc, char** argv, char** env) {
    // Prevent unused variable warnings
    if (0 && argc && argv && env) {}
	

	// Construct the Verilated model, from Vtop.h generated from Verilating "top.v"
	Vcnt* top = new Vcnt;

	//Set-up wave dump code
	bool chk_waveform = true;
	VerilatedVcdC* wave_fp = NULL;
	int main_time=0;

	if(chk_waveform == true){
		Verilated::traceEverOn(true);

		wave_fp = new VerilatedVcdC;
		top->trace(wave_fp, 999);

		cout<<"waveform file name is top.vcd"<<endl;

		wave_fp->open("./top.vcd");
	}

	int chk=0;

	// module initialize
	chk = module_init(top);
	if(chk != 0){
		cout<<"Error occur!"<<endl;
		return 0;		
	}

    // Simulate until $finish
	cout<<"Start"<<endl;
    while (!Verilated::gotFinish()) {

        // Evaluate model
		top->clk = top->clk ? 0 : 1;
        top->eval();

		wave_fp->dump(main_time);

		main_time++;
		
		//cout<< (top->out) <<endl;
		if(top->clk == 1) printf("%d ",top->out);

		if(top->out >= 300){
			break;
		}

    }

    // Final model cleanup
    top->final();

	if(wave_fp != NULL){
		wave_fp->close();
		delete wave_fp;
	}

    // Destroy model
    delete top;

    // Fin
    exit(0);
}
