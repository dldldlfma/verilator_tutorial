module connection_test (
    input wire i_clock,
    input wire i_resetn,
    output wire        o_test_0_valid,
    input  wire        i_test_0_ready,
    output wire [31:0] o_test_0_wdata,
    input  wire [31:0] i_test_0_rdata,

    output wire        o_test_2_valid,
    output wire [31:0] o_test_2_wdata,
    input  wire [31:0] i_test_2_rdata,

    output wire [15:0] o_test_3_wdata,
    input  wire [15:0] i_test_3_rdata
);

//-----------------------------------------------------------------------------
// Test 0 - port - @mark
//-----------------------------------------------------------------------------
master u_master_0 (
    .i_clk      (i_clock),
    .i_rstn     (i_resetn),
    .o_valid    (o_test_0_valid),
    .i_ready    (i_test_0_ready),
    .o_data     (o_test_0_wdata),
    .i_data     (i_test_0_rdata)
);

//-----------------------------------------------------------------------------
// Test 1 - internal - @mark
//-----------------------------------------------------------------------------
wire        test_1_valid;
wire        test_1_ready;
wire [31:0] test_1_wdata;
wire [31:0] test_1_rdata;

master u_master_1 (
    .i_clk      (i_clock),
    .i_rstn     (i_resetn),
    .o_valid    (test_1_valid),
    .i_ready    (test_1_ready),
    .o_data     (test_1_wdata),
    .i_data     (test_1_rdata)
);

slave u_slave_1 (
    .i_clk      (i_clock),
    .i_rstn     (i_resetn),
    .i_valid    (test_1_valid),
    .o_ready    (test_1_ready),
    .i_data     (test_1_wdata ),
    .o_data     (test_1_rdata )
);

//-----------------------------------------------------------------------------
// Test 2 - port+internal, open - @mark
//-----------------------------------------------------------------------------
wire        test_2_valid;
wire        test_2_ready;
wire [31:0] test_2_wdata;
wire [31:0] test_2_rdata;

master u_master_2 (
    .i_clk      (i_clock),
    .i_rstn     (i_resetn),
    .o_valid    (o_test_2_valid), // port+internal (output)
    .i_ready    (),               // open (input)
    .o_data     (o_test_2_wdata),
    .i_data     (i_test_2_rdata)  // port+internal (input)
);

slave u_slave_2 (
    .i_clk      (i_clock),
    .i_rstn     (i_resetn),
    .i_valid    (o_test_2_valid), // port+internal (output)
    .o_ready    (),               // open (output)
    .i_data     (o_test_2_wdata),
    .o_data     (/*i_test_2_rdata*/) // port+internal (input)
);

//-----------------------------------------------------------------------------
// Test 3 - concatenation - @mark
//-----------------------------------------------------------------------------
wire [15:0] tmp;
master u_master_3 (
    .i_clk      (i_clock),
    .i_rstn     (i_resetn),
    .o_valid    (),
    .i_ready    (),
    .o_data     ({o_test_3_wdata[15:8],tmp,o_test_3_wdata[7:0]}),
    .i_data     ({2{i_test_3_rdata}})  // port+internal (input)
);

slave u_slave_3 (
    .i_clk      (i_clock),
    .i_rstn     (i_resetn),
    .i_valid    (), // port+internal (output)
    .o_ready    (),               // open (output)
    .i_data     ({o_test_3_wdata[15:8],i_test_3_rdata[15:0],o_test_3_wdata[7:0]}),
    .o_data     () // port+internal (input)
);



endmodule


module master (
    input          i_clk,
    input          i_rstn,
    output         o_valid,
    input          i_ready,
    output  [31:0] o_data,
    input   [31:0] i_data
);

endmodule

module slave (
    input          i_clk,
    input          i_rstn,
    input          i_valid,
    output         o_ready,
    input   [31:0] i_data,
    output  [31:0] o_data
);

endmodule

