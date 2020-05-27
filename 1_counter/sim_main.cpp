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

using namespace std;

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
		
		//cout<< (top->out) <<endl;
		if(top->clk == 1) printf("%d ",top->out);

		if(top->out >= 300){
			break;
		}

    }

    // Final model cleanup
    top->final();

    // Destroy model
    delete top;

    // Fin
    exit(0);
}
