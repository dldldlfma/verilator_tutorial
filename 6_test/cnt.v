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
	output reg [15:0] out,
	output chk_3
);

	chk_3_multiple u0(
			.clk(clk),
			.chk_num(out),
			.chk_out(chk_3)
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

module chk_3_multiple(
		input clk,
		input [15:0] chk_num,
		output chk_out
		);

//assign chk_out = (chk_num%3 == 0);

endmodule


