// DESCRIPTION: Verilator: Verilog example module
//
// This file ONLY is placed under the Creative Commons Public Domain, for
// any use, without warranty, 2017 by Wilson Snyder.
// SPDX-License-Identifier: CC0-1.0

// See also the EXAMPLE section in the verilator manpage/document.

`timescale 1ns/1ps

module cnt(
	input clk,
	input rstn,
	output reg [15:0] out
);
	always @(posedge clk, negedge rstn)
	begin
		if(!rstn)
		begin
			out<=0;
		end
		else
		begin
			if(out<300)
			begin
				out<=out+1;
			end
			else
			begin
				out<=0;
			end		
		end
	end
endmodule
