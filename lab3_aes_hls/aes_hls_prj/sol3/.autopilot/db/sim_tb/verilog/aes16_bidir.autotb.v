// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
 `timescale 1ns/1ps


`define AUTOTB_DUT      aes16_bidir
`define AUTOTB_DUT_INST AESL_inst_aes16_bidir
`define AUTOTB_TOP      apatb_aes16_bidir_top
`define AUTOTB_LAT_RESULT_FILE "aes16_bidir.result.lat.rb"
`define AUTOTB_PER_RESULT_TRANS_FILE "aes16_bidir.performance.result.transaction.xml"
`define AUTOTB_TOP_INST AESL_inst_apatb_aes16_bidir_top
`define AUTOTB_MAX_ALLOW_LATENCY  15000000
`define AUTOTB_CLOCK_PERIOD_DIV2 50.00

`define AESL_DEPTH_key_0 1
`define AESL_DEPTH_key_1 1
`define AESL_DEPTH_key_2 1
`define AESL_DEPTH_key_3 1
`define AESL_DEPTH_inout_0 1
`define AESL_DEPTH_inout_1 1
`define AESL_DEPTH_inout_2 1
`define AESL_DEPTH_inout_3 1
`define AESL_DEPTH_iv_0 1
`define AESL_DEPTH_iv_1 1
`define AESL_DEPTH_iv_2 1
`define AESL_DEPTH_iv_3 1
`define AUTOTB_TVIN_key_0  "./c.aes16_bidir.autotvin_key_0.dat"
`define AUTOTB_TVIN_key_1  "./c.aes16_bidir.autotvin_key_1.dat"
`define AUTOTB_TVIN_key_2  "./c.aes16_bidir.autotvin_key_2.dat"
`define AUTOTB_TVIN_key_3  "./c.aes16_bidir.autotvin_key_3.dat"
`define AUTOTB_TVIN_inout_0  "./c.aes16_bidir.autotvin_inout_0.dat"
`define AUTOTB_TVIN_inout_1  "./c.aes16_bidir.autotvin_inout_1.dat"
`define AUTOTB_TVIN_inout_2  "./c.aes16_bidir.autotvin_inout_2.dat"
`define AUTOTB_TVIN_inout_3  "./c.aes16_bidir.autotvin_inout_3.dat"
`define AUTOTB_TVIN_iv_0  "./c.aes16_bidir.autotvin_iv_0.dat"
`define AUTOTB_TVIN_iv_1  "./c.aes16_bidir.autotvin_iv_1.dat"
`define AUTOTB_TVIN_iv_2  "./c.aes16_bidir.autotvin_iv_2.dat"
`define AUTOTB_TVIN_iv_3  "./c.aes16_bidir.autotvin_iv_3.dat"
`define AUTOTB_TVIN_key_0_out_wrapc  "./rtl.aes16_bidir.autotvin_key_0.dat"
`define AUTOTB_TVIN_key_1_out_wrapc  "./rtl.aes16_bidir.autotvin_key_1.dat"
`define AUTOTB_TVIN_key_2_out_wrapc  "./rtl.aes16_bidir.autotvin_key_2.dat"
`define AUTOTB_TVIN_key_3_out_wrapc  "./rtl.aes16_bidir.autotvin_key_3.dat"
`define AUTOTB_TVIN_inout_0_out_wrapc  "./rtl.aes16_bidir.autotvin_inout_0.dat"
`define AUTOTB_TVIN_inout_1_out_wrapc  "./rtl.aes16_bidir.autotvin_inout_1.dat"
`define AUTOTB_TVIN_inout_2_out_wrapc  "./rtl.aes16_bidir.autotvin_inout_2.dat"
`define AUTOTB_TVIN_inout_3_out_wrapc  "./rtl.aes16_bidir.autotvin_inout_3.dat"
`define AUTOTB_TVIN_iv_0_out_wrapc  "./rtl.aes16_bidir.autotvin_iv_0.dat"
`define AUTOTB_TVIN_iv_1_out_wrapc  "./rtl.aes16_bidir.autotvin_iv_1.dat"
`define AUTOTB_TVIN_iv_2_out_wrapc  "./rtl.aes16_bidir.autotvin_iv_2.dat"
`define AUTOTB_TVIN_iv_3_out_wrapc  "./rtl.aes16_bidir.autotvin_iv_3.dat"
`define AUTOTB_TVOUT_inout_0  "./c.aes16_bidir.autotvout_inout_0.dat"
`define AUTOTB_TVOUT_inout_1  "./c.aes16_bidir.autotvout_inout_1.dat"
`define AUTOTB_TVOUT_inout_2  "./c.aes16_bidir.autotvout_inout_2.dat"
`define AUTOTB_TVOUT_inout_3  "./c.aes16_bidir.autotvout_inout_3.dat"
`define AUTOTB_TVOUT_iv_0  "./c.aes16_bidir.autotvout_iv_0.dat"
`define AUTOTB_TVOUT_iv_1  "./c.aes16_bidir.autotvout_iv_1.dat"
`define AUTOTB_TVOUT_iv_2  "./c.aes16_bidir.autotvout_iv_2.dat"
`define AUTOTB_TVOUT_iv_3  "./c.aes16_bidir.autotvout_iv_3.dat"
`define AUTOTB_TVOUT_inout_0_out_wrapc  "./impl_rtl.aes16_bidir.autotvout_inout_0.dat"
`define AUTOTB_TVOUT_inout_1_out_wrapc  "./impl_rtl.aes16_bidir.autotvout_inout_1.dat"
`define AUTOTB_TVOUT_inout_2_out_wrapc  "./impl_rtl.aes16_bidir.autotvout_inout_2.dat"
`define AUTOTB_TVOUT_inout_3_out_wrapc  "./impl_rtl.aes16_bidir.autotvout_inout_3.dat"
`define AUTOTB_TVOUT_iv_0_out_wrapc  "./impl_rtl.aes16_bidir.autotvout_iv_0.dat"
`define AUTOTB_TVOUT_iv_1_out_wrapc  "./impl_rtl.aes16_bidir.autotvout_iv_1.dat"
`define AUTOTB_TVOUT_iv_2_out_wrapc  "./impl_rtl.aes16_bidir.autotvout_iv_2.dat"
`define AUTOTB_TVOUT_iv_3_out_wrapc  "./impl_rtl.aes16_bidir.autotvout_iv_3.dat"
module `AUTOTB_TOP;

parameter AUTOTB_TRANSACTION_NUM = 2;
parameter PROGRESS_TIMEOUT = 10000000;
parameter LATENCY_ESTIMATION = 983;
parameter LENGTH_key_0 = 1;
parameter LENGTH_key_1 = 1;
parameter LENGTH_key_2 = 1;
parameter LENGTH_key_3 = 1;
parameter LENGTH_inout_0 = 1;
parameter LENGTH_inout_1 = 1;
parameter LENGTH_inout_2 = 1;
parameter LENGTH_inout_3 = 1;
parameter LENGTH_iv_0 = 1;
parameter LENGTH_iv_1 = 1;
parameter LENGTH_iv_2 = 1;
parameter LENGTH_iv_3 = 1;

task read_token;
    input integer fp;
    output reg [151 : 0] token;
    integer ret;
    begin
        token = "";
        ret = 0;
        ret = $fscanf(fp,"%s",token);
    end
endtask

task post_check;
    input integer fp1;
    input integer fp2;
    reg [151 : 0] token1;
    reg [151 : 0] token2;
    reg [151 : 0] golden;
    reg [151 : 0] result;
    integer ret;
    begin
        read_token(fp1, token1);
        read_token(fp2, token2);
        if (token1 != "[[[runtime]]]" || token2 != "[[[runtime]]]") begin
            $display("ERROR: Simulation using HLS TB failed.");
            $finish;
        end
        read_token(fp1, token1);
        read_token(fp2, token2);
        while (token1 != "[[[/runtime]]]" && token2 != "[[[/runtime]]]") begin
            if (token1 != "[[transaction]]" || token2 != "[[transaction]]") begin
                $display("ERROR: Simulation using HLS TB failed.");
                  $finish;
            end
            read_token(fp1, token1);  // skip transaction number
            read_token(fp2, token2);  // skip transaction number
              read_token(fp1, token1);
              read_token(fp2, token2);
            while(token1 != "[[/transaction]]" && token2 != "[[/transaction]]") begin
                ret = $sscanf(token1, "0x%x", golden);
                  if (ret != 1) begin
                      $display("Failed to parse token!");
                    $display("ERROR: Simulation using HLS TB failed.");
                      $finish;
                  end
                ret = $sscanf(token2, "0x%x", result);
                  if (ret != 1) begin
                      $display("Failed to parse token!");
                    $display("ERROR: Simulation using HLS TB failed.");
                      $finish;
                  end
                if(golden != result) begin
                      $display("%x (expected) vs. %x (actual) - mismatch", golden, result);
                    $display("ERROR: Simulation using HLS TB failed.");
                      $finish;
                end
                  read_token(fp1, token1);
                  read_token(fp2, token2);
            end
              read_token(fp1, token1);
              read_token(fp2, token2);
        end
    end
endtask

reg AESL_clock;
reg rst;
reg start;
reg ce;
reg tb_continue;
wire AESL_start;
wire AESL_reset;
wire AESL_ce;
wire AESL_ready;
wire AESL_idle;
wire AESL_continue;
wire AESL_done;
reg AESL_done_delay = 0;
reg AESL_done_delay2 = 0;
reg AESL_ready_delay = 0;
wire ready;
wire ready_wire;
wire ap_start;
wire ap_done;
wire ap_idle;
wire ap_ready;
wire [31 : 0] key_0;
wire [31 : 0] key_1;
wire [31 : 0] key_2;
wire [31 : 0] key_3;
wire [31 : 0] inout_0_i;
wire [31 : 0] inout_0_o;
wire  inout_0_o_ap_vld;
wire [31 : 0] inout_1_i;
wire [31 : 0] inout_1_o;
wire  inout_1_o_ap_vld;
wire [31 : 0] inout_2_i;
wire [31 : 0] inout_2_o;
wire  inout_2_o_ap_vld;
wire [31 : 0] inout_3_i;
wire [31 : 0] inout_3_o;
wire  inout_3_o_ap_vld;
wire [31 : 0] iv_0_i;
wire [31 : 0] iv_0_o;
wire  iv_0_o_ap_vld;
wire [31 : 0] iv_1_i;
wire [31 : 0] iv_1_o;
wire  iv_1_o_ap_vld;
wire [31 : 0] iv_2_i;
wire [31 : 0] iv_2_o;
wire  iv_2_o_ap_vld;
wire [31 : 0] iv_3_i;
wire [31 : 0] iv_3_o;
wire  iv_3_o_ap_vld;
integer done_cnt = 0;
integer AESL_ready_cnt = 0;
integer ready_cnt = 0;
reg ready_initial;
reg ready_initial_n;
reg ready_last_n;
reg ready_delay_last_n;
reg done_delay_last_n;
reg interface_done = 0;

wire ap_clk;
wire ap_rst;
wire ap_rst_n;

`AUTOTB_DUT `AUTOTB_DUT_INST(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .ap_start(ap_start),
    .ap_done(ap_done),
    .ap_idle(ap_idle),
    .ap_ready(ap_ready),
    .key_0(key_0),
    .key_1(key_1),
    .key_2(key_2),
    .key_3(key_3),
    .inout_0_i(inout_0_i),
    .inout_0_o(inout_0_o),
    .inout_0_o_ap_vld(inout_0_o_ap_vld),
    .inout_1_i(inout_1_i),
    .inout_1_o(inout_1_o),
    .inout_1_o_ap_vld(inout_1_o_ap_vld),
    .inout_2_i(inout_2_i),
    .inout_2_o(inout_2_o),
    .inout_2_o_ap_vld(inout_2_o_ap_vld),
    .inout_3_i(inout_3_i),
    .inout_3_o(inout_3_o),
    .inout_3_o_ap_vld(inout_3_o_ap_vld),
    .iv_0_i(iv_0_i),
    .iv_0_o(iv_0_o),
    .iv_0_o_ap_vld(iv_0_o_ap_vld),
    .iv_1_i(iv_1_i),
    .iv_1_o(iv_1_o),
    .iv_1_o_ap_vld(iv_1_o_ap_vld),
    .iv_2_i(iv_2_i),
    .iv_2_o(iv_2_o),
    .iv_2_o_ap_vld(iv_2_o_ap_vld),
    .iv_3_i(iv_3_i),
    .iv_3_o(iv_3_o),
    .iv_3_o_ap_vld(iv_3_o_ap_vld));

// Assignment for control signal
assign ap_clk = AESL_clock;
assign ap_rst = AESL_reset;
assign ap_rst_n = ~AESL_reset;
assign AESL_reset = rst;
assign ap_start = AESL_start;
assign AESL_start = start;
assign AESL_done = ap_done;
assign AESL_idle = ap_idle;
assign AESL_ready = ap_ready;
assign AESL_ce = ce;
assign AESL_continue = tb_continue;
    always @(posedge AESL_clock) begin
        if (AESL_reset) begin
        end else begin
            if (AESL_done !== 1 && AESL_done !== 0) begin
                $display("ERROR: Control signal AESL_done is invalid!");
                $finish;
            end
        end
    end
    always @(posedge AESL_clock) begin
        if (AESL_reset) begin
        end else begin
            if (AESL_ready !== 1 && AESL_ready !== 0) begin
                $display("ERROR: Control signal AESL_ready is invalid!");
                $finish;
            end
        end
    end
// The signal of port key_0
reg [31: 0] AESL_REG_key_0 = 0;
assign key_0 = AESL_REG_key_0;
initial begin : read_file_process_key_0
    integer fp;
    integer err;
    integer ret;
    integer proc_rand;
    reg [151  : 0] token;
    integer i;
    reg transaction_finish;
    integer transaction_idx;
    transaction_idx = 0;
    wait(AESL_reset === 0);
    fp = $fopen(`AUTOTB_TVIN_key_0,"r");
    if(fp == 0) begin       // Failed to open file
        $display("Failed to open file \"%s\"!", `AUTOTB_TVIN_key_0);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    if (token != "[[[runtime]]]") begin
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    while (token != "[[[/runtime]]]") begin
        if (token != "[[transaction]]") begin
            $display("ERROR: Simulation using HLS TB failed.");
              $finish;
        end
        read_token(fp, token);  // skip transaction number
          read_token(fp, token);
            # 0.2;
            while(ready_wire !== 1) begin
                @(posedge AESL_clock);
                # 0.2;
            end
        if(token != "[[/transaction]]") begin
            ret = $sscanf(token, "0x%x", AESL_REG_key_0);
              if (ret != 1) begin
                  $display("Failed to parse token!");
                $display("ERROR: Simulation using HLS TB failed.");
                  $finish;
              end
            @(posedge AESL_clock);
              read_token(fp, token);
        end
          read_token(fp, token);
    end
    $fclose(fp);
end


// The signal of port key_1
reg [31: 0] AESL_REG_key_1 = 0;
assign key_1 = AESL_REG_key_1;
initial begin : read_file_process_key_1
    integer fp;
    integer err;
    integer ret;
    integer proc_rand;
    reg [151  : 0] token;
    integer i;
    reg transaction_finish;
    integer transaction_idx;
    transaction_idx = 0;
    wait(AESL_reset === 0);
    fp = $fopen(`AUTOTB_TVIN_key_1,"r");
    if(fp == 0) begin       // Failed to open file
        $display("Failed to open file \"%s\"!", `AUTOTB_TVIN_key_1);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    if (token != "[[[runtime]]]") begin
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    while (token != "[[[/runtime]]]") begin
        if (token != "[[transaction]]") begin
            $display("ERROR: Simulation using HLS TB failed.");
              $finish;
        end
        read_token(fp, token);  // skip transaction number
          read_token(fp, token);
            # 0.2;
            while(ready_wire !== 1) begin
                @(posedge AESL_clock);
                # 0.2;
            end
        if(token != "[[/transaction]]") begin
            ret = $sscanf(token, "0x%x", AESL_REG_key_1);
              if (ret != 1) begin
                  $display("Failed to parse token!");
                $display("ERROR: Simulation using HLS TB failed.");
                  $finish;
              end
            @(posedge AESL_clock);
              read_token(fp, token);
        end
          read_token(fp, token);
    end
    $fclose(fp);
end


// The signal of port key_2
reg [31: 0] AESL_REG_key_2 = 0;
assign key_2 = AESL_REG_key_2;
initial begin : read_file_process_key_2
    integer fp;
    integer err;
    integer ret;
    integer proc_rand;
    reg [151  : 0] token;
    integer i;
    reg transaction_finish;
    integer transaction_idx;
    transaction_idx = 0;
    wait(AESL_reset === 0);
    fp = $fopen(`AUTOTB_TVIN_key_2,"r");
    if(fp == 0) begin       // Failed to open file
        $display("Failed to open file \"%s\"!", `AUTOTB_TVIN_key_2);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    if (token != "[[[runtime]]]") begin
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    while (token != "[[[/runtime]]]") begin
        if (token != "[[transaction]]") begin
            $display("ERROR: Simulation using HLS TB failed.");
              $finish;
        end
        read_token(fp, token);  // skip transaction number
          read_token(fp, token);
            # 0.2;
            while(ready_wire !== 1) begin
                @(posedge AESL_clock);
                # 0.2;
            end
        if(token != "[[/transaction]]") begin
            ret = $sscanf(token, "0x%x", AESL_REG_key_2);
              if (ret != 1) begin
                  $display("Failed to parse token!");
                $display("ERROR: Simulation using HLS TB failed.");
                  $finish;
              end
            @(posedge AESL_clock);
              read_token(fp, token);
        end
          read_token(fp, token);
    end
    $fclose(fp);
end


// The signal of port key_3
reg [31: 0] AESL_REG_key_3 = 0;
assign key_3 = AESL_REG_key_3;
initial begin : read_file_process_key_3
    integer fp;
    integer err;
    integer ret;
    integer proc_rand;
    reg [151  : 0] token;
    integer i;
    reg transaction_finish;
    integer transaction_idx;
    transaction_idx = 0;
    wait(AESL_reset === 0);
    fp = $fopen(`AUTOTB_TVIN_key_3,"r");
    if(fp == 0) begin       // Failed to open file
        $display("Failed to open file \"%s\"!", `AUTOTB_TVIN_key_3);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    if (token != "[[[runtime]]]") begin
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    while (token != "[[[/runtime]]]") begin
        if (token != "[[transaction]]") begin
            $display("ERROR: Simulation using HLS TB failed.");
              $finish;
        end
        read_token(fp, token);  // skip transaction number
          read_token(fp, token);
            # 0.2;
            while(ready_wire !== 1) begin
                @(posedge AESL_clock);
                # 0.2;
            end
        if(token != "[[/transaction]]") begin
            ret = $sscanf(token, "0x%x", AESL_REG_key_3);
              if (ret != 1) begin
                  $display("Failed to parse token!");
                $display("ERROR: Simulation using HLS TB failed.");
                  $finish;
              end
            @(posedge AESL_clock);
              read_token(fp, token);
        end
          read_token(fp, token);
    end
    $fclose(fp);
end


// The signal of port inout_0_i
reg [31: 0] AESL_REG_inout_0_i = 0;
assign inout_0_i = AESL_REG_inout_0_i;
always @(posedge AESL_clock)
begin
    if(inout_0_o_ap_vld === 1)
        AESL_REG_inout_0_i <= inout_0_o;
end

initial begin : read_file_process_inout_0
    integer fp;
    integer err;
    integer ret;
    integer proc_rand;
    reg [151  : 0] token;
    integer i;
    reg transaction_finish;
    integer transaction_idx;
    transaction_idx = 0;
    wait(AESL_reset === 0);
    fp = $fopen(`AUTOTB_TVIN_inout_0,"r");
    if(fp == 0) begin       // Failed to open file
        $display("Failed to open file \"%s\"!", `AUTOTB_TVIN_inout_0);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    if (token != "[[[runtime]]]") begin
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    while (token != "[[[/runtime]]]") begin
        if (token != "[[transaction]]") begin
            $display("ERROR: Simulation using HLS TB failed.");
              $finish;
        end
        read_token(fp, token);  // skip transaction number
          read_token(fp, token);
            # 0.2;
            while(ready_wire !== 1) begin
                @(posedge AESL_clock);
                # 0.2;
            end
        if(token != "[[/transaction]]") begin
            ret = $sscanf(token, "0x%x", AESL_REG_inout_0_i);
              if (ret != 1) begin
                  $display("Failed to parse token!");
                $display("ERROR: Simulation using HLS TB failed.");
                  $finish;
              end
            @(posedge AESL_clock);
              read_token(fp, token);
        end
          read_token(fp, token);
    end
    $fclose(fp);
end

reg AESL_REG_inout_0_o_ap_vld = 0;
// The signal of port inout_0_o
reg [31: 0] AESL_REG_inout_0_o = 0;
always @(posedge AESL_clock)
begin
    if(AESL_reset)
        AESL_REG_inout_0_o = 0; 
    else if(inout_0_o_ap_vld) begin
        AESL_REG_inout_0_o <= inout_0_o;
        AESL_REG_inout_0_o_ap_vld <= 1;
    end
end 

initial begin : write_file_process_inout_0
    integer fp;
    integer fp_size;
    integer err;
    integer ret;
    integer i;
    integer hls_stream_size;
    integer proc_rand;
    integer inout_0_count;
    reg [151:0] token;
    integer transaction_idx;
    reg [8 * 5:1] str;
    wait(AESL_reset === 0);
    fp = $fopen(`AUTOTB_TVOUT_inout_0_out_wrapc,"w");
    if(fp == 0) begin       // Failed to open file
        $display("Failed to open file \"%s\"!", `AUTOTB_TVOUT_inout_0_out_wrapc);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    $fdisplay(fp,"[[[runtime]]]");
    transaction_idx = 0;
    while (transaction_idx != AUTOTB_TRANSACTION_NUM) begin
        @(posedge AESL_clock);
          while(AESL_done !== 1) begin
              @(posedge AESL_clock);
          end
        # 0.4;
        $fdisplay(fp,"[[transaction]] %d", transaction_idx);
        if(AESL_REG_inout_0_o_ap_vld)  begin
          $fdisplay(fp,"0x%x", AESL_REG_inout_0_o);
        AESL_REG_inout_0_o_ap_vld = 0;
        end
    transaction_idx = transaction_idx + 1;
      $fdisplay(fp,"[[/transaction]]");
    end
    $fdisplay(fp,"[[[/runtime]]]");
    $fclose(fp);
end


// The signal of port inout_1_i
reg [31: 0] AESL_REG_inout_1_i = 0;
assign inout_1_i = AESL_REG_inout_1_i;
always @(posedge AESL_clock)
begin
    if(inout_1_o_ap_vld === 1)
        AESL_REG_inout_1_i <= inout_1_o;
end

initial begin : read_file_process_inout_1
    integer fp;
    integer err;
    integer ret;
    integer proc_rand;
    reg [151  : 0] token;
    integer i;
    reg transaction_finish;
    integer transaction_idx;
    transaction_idx = 0;
    wait(AESL_reset === 0);
    fp = $fopen(`AUTOTB_TVIN_inout_1,"r");
    if(fp == 0) begin       // Failed to open file
        $display("Failed to open file \"%s\"!", `AUTOTB_TVIN_inout_1);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    if (token != "[[[runtime]]]") begin
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    while (token != "[[[/runtime]]]") begin
        if (token != "[[transaction]]") begin
            $display("ERROR: Simulation using HLS TB failed.");
              $finish;
        end
        read_token(fp, token);  // skip transaction number
          read_token(fp, token);
            # 0.2;
            while(ready_wire !== 1) begin
                @(posedge AESL_clock);
                # 0.2;
            end
        if(token != "[[/transaction]]") begin
            ret = $sscanf(token, "0x%x", AESL_REG_inout_1_i);
              if (ret != 1) begin
                  $display("Failed to parse token!");
                $display("ERROR: Simulation using HLS TB failed.");
                  $finish;
              end
            @(posedge AESL_clock);
              read_token(fp, token);
        end
          read_token(fp, token);
    end
    $fclose(fp);
end

reg AESL_REG_inout_1_o_ap_vld = 0;
// The signal of port inout_1_o
reg [31: 0] AESL_REG_inout_1_o = 0;
always @(posedge AESL_clock)
begin
    if(AESL_reset)
        AESL_REG_inout_1_o = 0; 
    else if(inout_1_o_ap_vld) begin
        AESL_REG_inout_1_o <= inout_1_o;
        AESL_REG_inout_1_o_ap_vld <= 1;
    end
end 

initial begin : write_file_process_inout_1
    integer fp;
    integer fp_size;
    integer err;
    integer ret;
    integer i;
    integer hls_stream_size;
    integer proc_rand;
    integer inout_1_count;
    reg [151:0] token;
    integer transaction_idx;
    reg [8 * 5:1] str;
    wait(AESL_reset === 0);
    fp = $fopen(`AUTOTB_TVOUT_inout_1_out_wrapc,"w");
    if(fp == 0) begin       // Failed to open file
        $display("Failed to open file \"%s\"!", `AUTOTB_TVOUT_inout_1_out_wrapc);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    $fdisplay(fp,"[[[runtime]]]");
    transaction_idx = 0;
    while (transaction_idx != AUTOTB_TRANSACTION_NUM) begin
        @(posedge AESL_clock);
          while(AESL_done !== 1) begin
              @(posedge AESL_clock);
          end
        # 0.4;
        $fdisplay(fp,"[[transaction]] %d", transaction_idx);
        if(AESL_REG_inout_1_o_ap_vld)  begin
          $fdisplay(fp,"0x%x", AESL_REG_inout_1_o);
        AESL_REG_inout_1_o_ap_vld = 0;
        end
    transaction_idx = transaction_idx + 1;
      $fdisplay(fp,"[[/transaction]]");
    end
    $fdisplay(fp,"[[[/runtime]]]");
    $fclose(fp);
end


// The signal of port inout_2_i
reg [31: 0] AESL_REG_inout_2_i = 0;
assign inout_2_i = AESL_REG_inout_2_i;
always @(posedge AESL_clock)
begin
    if(inout_2_o_ap_vld === 1)
        AESL_REG_inout_2_i <= inout_2_o;
end

initial begin : read_file_process_inout_2
    integer fp;
    integer err;
    integer ret;
    integer proc_rand;
    reg [151  : 0] token;
    integer i;
    reg transaction_finish;
    integer transaction_idx;
    transaction_idx = 0;
    wait(AESL_reset === 0);
    fp = $fopen(`AUTOTB_TVIN_inout_2,"r");
    if(fp == 0) begin       // Failed to open file
        $display("Failed to open file \"%s\"!", `AUTOTB_TVIN_inout_2);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    if (token != "[[[runtime]]]") begin
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    while (token != "[[[/runtime]]]") begin
        if (token != "[[transaction]]") begin
            $display("ERROR: Simulation using HLS TB failed.");
              $finish;
        end
        read_token(fp, token);  // skip transaction number
          read_token(fp, token);
            # 0.2;
            while(ready_wire !== 1) begin
                @(posedge AESL_clock);
                # 0.2;
            end
        if(token != "[[/transaction]]") begin
            ret = $sscanf(token, "0x%x", AESL_REG_inout_2_i);
              if (ret != 1) begin
                  $display("Failed to parse token!");
                $display("ERROR: Simulation using HLS TB failed.");
                  $finish;
              end
            @(posedge AESL_clock);
              read_token(fp, token);
        end
          read_token(fp, token);
    end
    $fclose(fp);
end

reg AESL_REG_inout_2_o_ap_vld = 0;
// The signal of port inout_2_o
reg [31: 0] AESL_REG_inout_2_o = 0;
always @(posedge AESL_clock)
begin
    if(AESL_reset)
        AESL_REG_inout_2_o = 0; 
    else if(inout_2_o_ap_vld) begin
        AESL_REG_inout_2_o <= inout_2_o;
        AESL_REG_inout_2_o_ap_vld <= 1;
    end
end 

initial begin : write_file_process_inout_2
    integer fp;
    integer fp_size;
    integer err;
    integer ret;
    integer i;
    integer hls_stream_size;
    integer proc_rand;
    integer inout_2_count;
    reg [151:0] token;
    integer transaction_idx;
    reg [8 * 5:1] str;
    wait(AESL_reset === 0);
    fp = $fopen(`AUTOTB_TVOUT_inout_2_out_wrapc,"w");
    if(fp == 0) begin       // Failed to open file
        $display("Failed to open file \"%s\"!", `AUTOTB_TVOUT_inout_2_out_wrapc);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    $fdisplay(fp,"[[[runtime]]]");
    transaction_idx = 0;
    while (transaction_idx != AUTOTB_TRANSACTION_NUM) begin
        @(posedge AESL_clock);
          while(AESL_done !== 1) begin
              @(posedge AESL_clock);
          end
        # 0.4;
        $fdisplay(fp,"[[transaction]] %d", transaction_idx);
        if(AESL_REG_inout_2_o_ap_vld)  begin
          $fdisplay(fp,"0x%x", AESL_REG_inout_2_o);
        AESL_REG_inout_2_o_ap_vld = 0;
        end
    transaction_idx = transaction_idx + 1;
      $fdisplay(fp,"[[/transaction]]");
    end
    $fdisplay(fp,"[[[/runtime]]]");
    $fclose(fp);
end


// The signal of port inout_3_i
reg [31: 0] AESL_REG_inout_3_i = 0;
assign inout_3_i = AESL_REG_inout_3_i;
always @(posedge AESL_clock)
begin
    if(inout_3_o_ap_vld === 1)
        AESL_REG_inout_3_i <= inout_3_o;
end

initial begin : read_file_process_inout_3
    integer fp;
    integer err;
    integer ret;
    integer proc_rand;
    reg [151  : 0] token;
    integer i;
    reg transaction_finish;
    integer transaction_idx;
    transaction_idx = 0;
    wait(AESL_reset === 0);
    fp = $fopen(`AUTOTB_TVIN_inout_3,"r");
    if(fp == 0) begin       // Failed to open file
        $display("Failed to open file \"%s\"!", `AUTOTB_TVIN_inout_3);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    if (token != "[[[runtime]]]") begin
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    while (token != "[[[/runtime]]]") begin
        if (token != "[[transaction]]") begin
            $display("ERROR: Simulation using HLS TB failed.");
              $finish;
        end
        read_token(fp, token);  // skip transaction number
          read_token(fp, token);
            # 0.2;
            while(ready_wire !== 1) begin
                @(posedge AESL_clock);
                # 0.2;
            end
        if(token != "[[/transaction]]") begin
            ret = $sscanf(token, "0x%x", AESL_REG_inout_3_i);
              if (ret != 1) begin
                  $display("Failed to parse token!");
                $display("ERROR: Simulation using HLS TB failed.");
                  $finish;
              end
            @(posedge AESL_clock);
              read_token(fp, token);
        end
          read_token(fp, token);
    end
    $fclose(fp);
end

reg AESL_REG_inout_3_o_ap_vld = 0;
// The signal of port inout_3_o
reg [31: 0] AESL_REG_inout_3_o = 0;
always @(posedge AESL_clock)
begin
    if(AESL_reset)
        AESL_REG_inout_3_o = 0; 
    else if(inout_3_o_ap_vld) begin
        AESL_REG_inout_3_o <= inout_3_o;
        AESL_REG_inout_3_o_ap_vld <= 1;
    end
end 

initial begin : write_file_process_inout_3
    integer fp;
    integer fp_size;
    integer err;
    integer ret;
    integer i;
    integer hls_stream_size;
    integer proc_rand;
    integer inout_3_count;
    reg [151:0] token;
    integer transaction_idx;
    reg [8 * 5:1] str;
    wait(AESL_reset === 0);
    fp = $fopen(`AUTOTB_TVOUT_inout_3_out_wrapc,"w");
    if(fp == 0) begin       // Failed to open file
        $display("Failed to open file \"%s\"!", `AUTOTB_TVOUT_inout_3_out_wrapc);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    $fdisplay(fp,"[[[runtime]]]");
    transaction_idx = 0;
    while (transaction_idx != AUTOTB_TRANSACTION_NUM) begin
        @(posedge AESL_clock);
          while(AESL_done !== 1) begin
              @(posedge AESL_clock);
          end
        # 0.4;
        $fdisplay(fp,"[[transaction]] %d", transaction_idx);
        if(AESL_REG_inout_3_o_ap_vld)  begin
          $fdisplay(fp,"0x%x", AESL_REG_inout_3_o);
        AESL_REG_inout_3_o_ap_vld = 0;
        end
    transaction_idx = transaction_idx + 1;
      $fdisplay(fp,"[[/transaction]]");
    end
    $fdisplay(fp,"[[[/runtime]]]");
    $fclose(fp);
end


// The signal of port iv_0_i
reg [31: 0] AESL_REG_iv_0_i = 0;
assign iv_0_i = AESL_REG_iv_0_i;
always @(posedge AESL_clock)
begin
    if(iv_0_o_ap_vld === 1)
        AESL_REG_iv_0_i <= iv_0_o;
end

initial begin : read_file_process_iv_0
    integer fp;
    integer err;
    integer ret;
    integer proc_rand;
    reg [151  : 0] token;
    integer i;
    reg transaction_finish;
    integer transaction_idx;
    transaction_idx = 0;
    wait(AESL_reset === 0);
    fp = $fopen(`AUTOTB_TVIN_iv_0,"r");
    if(fp == 0) begin       // Failed to open file
        $display("Failed to open file \"%s\"!", `AUTOTB_TVIN_iv_0);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    if (token != "[[[runtime]]]") begin
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    while (token != "[[[/runtime]]]") begin
        if (token != "[[transaction]]") begin
            $display("ERROR: Simulation using HLS TB failed.");
              $finish;
        end
        read_token(fp, token);  // skip transaction number
          read_token(fp, token);
            # 0.2;
            while(ready_wire !== 1) begin
                @(posedge AESL_clock);
                # 0.2;
            end
        if(token != "[[/transaction]]") begin
            ret = $sscanf(token, "0x%x", AESL_REG_iv_0_i);
              if (ret != 1) begin
                  $display("Failed to parse token!");
                $display("ERROR: Simulation using HLS TB failed.");
                  $finish;
              end
            @(posedge AESL_clock);
              read_token(fp, token);
        end
          read_token(fp, token);
    end
    $fclose(fp);
end

reg AESL_REG_iv_0_o_ap_vld = 0;
// The signal of port iv_0_o
reg [31: 0] AESL_REG_iv_0_o = 0;
always @(posedge AESL_clock)
begin
    if(AESL_reset)
        AESL_REG_iv_0_o = 0; 
    else if(iv_0_o_ap_vld) begin
        AESL_REG_iv_0_o <= iv_0_o;
        AESL_REG_iv_0_o_ap_vld <= 1;
    end
end 

initial begin : write_file_process_iv_0
    integer fp;
    integer fp_size;
    integer err;
    integer ret;
    integer i;
    integer hls_stream_size;
    integer proc_rand;
    integer iv_0_count;
    reg [151:0] token;
    integer transaction_idx;
    reg [8 * 5:1] str;
    wait(AESL_reset === 0);
    fp = $fopen(`AUTOTB_TVOUT_iv_0_out_wrapc,"w");
    if(fp == 0) begin       // Failed to open file
        $display("Failed to open file \"%s\"!", `AUTOTB_TVOUT_iv_0_out_wrapc);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    $fdisplay(fp,"[[[runtime]]]");
    transaction_idx = 0;
    while (transaction_idx != AUTOTB_TRANSACTION_NUM) begin
        @(posedge AESL_clock);
          while(AESL_done !== 1) begin
              @(posedge AESL_clock);
          end
        # 0.4;
        $fdisplay(fp,"[[transaction]] %d", transaction_idx);
        if(AESL_REG_iv_0_o_ap_vld)  begin
          $fdisplay(fp,"0x%x", AESL_REG_iv_0_o);
        AESL_REG_iv_0_o_ap_vld = 0;
        end
    transaction_idx = transaction_idx + 1;
      $fdisplay(fp,"[[/transaction]]");
    end
    $fdisplay(fp,"[[[/runtime]]]");
    $fclose(fp);
end


// The signal of port iv_1_i
reg [31: 0] AESL_REG_iv_1_i = 0;
assign iv_1_i = AESL_REG_iv_1_i;
always @(posedge AESL_clock)
begin
    if(iv_1_o_ap_vld === 1)
        AESL_REG_iv_1_i <= iv_1_o;
end

initial begin : read_file_process_iv_1
    integer fp;
    integer err;
    integer ret;
    integer proc_rand;
    reg [151  : 0] token;
    integer i;
    reg transaction_finish;
    integer transaction_idx;
    transaction_idx = 0;
    wait(AESL_reset === 0);
    fp = $fopen(`AUTOTB_TVIN_iv_1,"r");
    if(fp == 0) begin       // Failed to open file
        $display("Failed to open file \"%s\"!", `AUTOTB_TVIN_iv_1);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    if (token != "[[[runtime]]]") begin
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    while (token != "[[[/runtime]]]") begin
        if (token != "[[transaction]]") begin
            $display("ERROR: Simulation using HLS TB failed.");
              $finish;
        end
        read_token(fp, token);  // skip transaction number
          read_token(fp, token);
            # 0.2;
            while(ready_wire !== 1) begin
                @(posedge AESL_clock);
                # 0.2;
            end
        if(token != "[[/transaction]]") begin
            ret = $sscanf(token, "0x%x", AESL_REG_iv_1_i);
              if (ret != 1) begin
                  $display("Failed to parse token!");
                $display("ERROR: Simulation using HLS TB failed.");
                  $finish;
              end
            @(posedge AESL_clock);
              read_token(fp, token);
        end
          read_token(fp, token);
    end
    $fclose(fp);
end

reg AESL_REG_iv_1_o_ap_vld = 0;
// The signal of port iv_1_o
reg [31: 0] AESL_REG_iv_1_o = 0;
always @(posedge AESL_clock)
begin
    if(AESL_reset)
        AESL_REG_iv_1_o = 0; 
    else if(iv_1_o_ap_vld) begin
        AESL_REG_iv_1_o <= iv_1_o;
        AESL_REG_iv_1_o_ap_vld <= 1;
    end
end 

initial begin : write_file_process_iv_1
    integer fp;
    integer fp_size;
    integer err;
    integer ret;
    integer i;
    integer hls_stream_size;
    integer proc_rand;
    integer iv_1_count;
    reg [151:0] token;
    integer transaction_idx;
    reg [8 * 5:1] str;
    wait(AESL_reset === 0);
    fp = $fopen(`AUTOTB_TVOUT_iv_1_out_wrapc,"w");
    if(fp == 0) begin       // Failed to open file
        $display("Failed to open file \"%s\"!", `AUTOTB_TVOUT_iv_1_out_wrapc);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    $fdisplay(fp,"[[[runtime]]]");
    transaction_idx = 0;
    while (transaction_idx != AUTOTB_TRANSACTION_NUM) begin
        @(posedge AESL_clock);
          while(AESL_done !== 1) begin
              @(posedge AESL_clock);
          end
        # 0.4;
        $fdisplay(fp,"[[transaction]] %d", transaction_idx);
        if(AESL_REG_iv_1_o_ap_vld)  begin
          $fdisplay(fp,"0x%x", AESL_REG_iv_1_o);
        AESL_REG_iv_1_o_ap_vld = 0;
        end
    transaction_idx = transaction_idx + 1;
      $fdisplay(fp,"[[/transaction]]");
    end
    $fdisplay(fp,"[[[/runtime]]]");
    $fclose(fp);
end


// The signal of port iv_2_i
reg [31: 0] AESL_REG_iv_2_i = 0;
assign iv_2_i = AESL_REG_iv_2_i;
always @(posedge AESL_clock)
begin
    if(iv_2_o_ap_vld === 1)
        AESL_REG_iv_2_i <= iv_2_o;
end

initial begin : read_file_process_iv_2
    integer fp;
    integer err;
    integer ret;
    integer proc_rand;
    reg [151  : 0] token;
    integer i;
    reg transaction_finish;
    integer transaction_idx;
    transaction_idx = 0;
    wait(AESL_reset === 0);
    fp = $fopen(`AUTOTB_TVIN_iv_2,"r");
    if(fp == 0) begin       // Failed to open file
        $display("Failed to open file \"%s\"!", `AUTOTB_TVIN_iv_2);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    if (token != "[[[runtime]]]") begin
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    while (token != "[[[/runtime]]]") begin
        if (token != "[[transaction]]") begin
            $display("ERROR: Simulation using HLS TB failed.");
              $finish;
        end
        read_token(fp, token);  // skip transaction number
          read_token(fp, token);
            # 0.2;
            while(ready_wire !== 1) begin
                @(posedge AESL_clock);
                # 0.2;
            end
        if(token != "[[/transaction]]") begin
            ret = $sscanf(token, "0x%x", AESL_REG_iv_2_i);
              if (ret != 1) begin
                  $display("Failed to parse token!");
                $display("ERROR: Simulation using HLS TB failed.");
                  $finish;
              end
            @(posedge AESL_clock);
              read_token(fp, token);
        end
          read_token(fp, token);
    end
    $fclose(fp);
end

reg AESL_REG_iv_2_o_ap_vld = 0;
// The signal of port iv_2_o
reg [31: 0] AESL_REG_iv_2_o = 0;
always @(posedge AESL_clock)
begin
    if(AESL_reset)
        AESL_REG_iv_2_o = 0; 
    else if(iv_2_o_ap_vld) begin
        AESL_REG_iv_2_o <= iv_2_o;
        AESL_REG_iv_2_o_ap_vld <= 1;
    end
end 

initial begin : write_file_process_iv_2
    integer fp;
    integer fp_size;
    integer err;
    integer ret;
    integer i;
    integer hls_stream_size;
    integer proc_rand;
    integer iv_2_count;
    reg [151:0] token;
    integer transaction_idx;
    reg [8 * 5:1] str;
    wait(AESL_reset === 0);
    fp = $fopen(`AUTOTB_TVOUT_iv_2_out_wrapc,"w");
    if(fp == 0) begin       // Failed to open file
        $display("Failed to open file \"%s\"!", `AUTOTB_TVOUT_iv_2_out_wrapc);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    $fdisplay(fp,"[[[runtime]]]");
    transaction_idx = 0;
    while (transaction_idx != AUTOTB_TRANSACTION_NUM) begin
        @(posedge AESL_clock);
          while(AESL_done !== 1) begin
              @(posedge AESL_clock);
          end
        # 0.4;
        $fdisplay(fp,"[[transaction]] %d", transaction_idx);
        if(AESL_REG_iv_2_o_ap_vld)  begin
          $fdisplay(fp,"0x%x", AESL_REG_iv_2_o);
        AESL_REG_iv_2_o_ap_vld = 0;
        end
    transaction_idx = transaction_idx + 1;
      $fdisplay(fp,"[[/transaction]]");
    end
    $fdisplay(fp,"[[[/runtime]]]");
    $fclose(fp);
end


// The signal of port iv_3_i
reg [31: 0] AESL_REG_iv_3_i = 0;
assign iv_3_i = AESL_REG_iv_3_i;
always @(posedge AESL_clock)
begin
    if(iv_3_o_ap_vld === 1)
        AESL_REG_iv_3_i <= iv_3_o;
end

initial begin : read_file_process_iv_3
    integer fp;
    integer err;
    integer ret;
    integer proc_rand;
    reg [151  : 0] token;
    integer i;
    reg transaction_finish;
    integer transaction_idx;
    transaction_idx = 0;
    wait(AESL_reset === 0);
    fp = $fopen(`AUTOTB_TVIN_iv_3,"r");
    if(fp == 0) begin       // Failed to open file
        $display("Failed to open file \"%s\"!", `AUTOTB_TVIN_iv_3);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    if (token != "[[[runtime]]]") begin
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    while (token != "[[[/runtime]]]") begin
        if (token != "[[transaction]]") begin
            $display("ERROR: Simulation using HLS TB failed.");
              $finish;
        end
        read_token(fp, token);  // skip transaction number
          read_token(fp, token);
            # 0.2;
            while(ready_wire !== 1) begin
                @(posedge AESL_clock);
                # 0.2;
            end
        if(token != "[[/transaction]]") begin
            ret = $sscanf(token, "0x%x", AESL_REG_iv_3_i);
              if (ret != 1) begin
                  $display("Failed to parse token!");
                $display("ERROR: Simulation using HLS TB failed.");
                  $finish;
              end
            @(posedge AESL_clock);
              read_token(fp, token);
        end
          read_token(fp, token);
    end
    $fclose(fp);
end

reg AESL_REG_iv_3_o_ap_vld = 0;
// The signal of port iv_3_o
reg [31: 0] AESL_REG_iv_3_o = 0;
always @(posedge AESL_clock)
begin
    if(AESL_reset)
        AESL_REG_iv_3_o = 0; 
    else if(iv_3_o_ap_vld) begin
        AESL_REG_iv_3_o <= iv_3_o;
        AESL_REG_iv_3_o_ap_vld <= 1;
    end
end 

initial begin : write_file_process_iv_3
    integer fp;
    integer fp_size;
    integer err;
    integer ret;
    integer i;
    integer hls_stream_size;
    integer proc_rand;
    integer iv_3_count;
    reg [151:0] token;
    integer transaction_idx;
    reg [8 * 5:1] str;
    wait(AESL_reset === 0);
    fp = $fopen(`AUTOTB_TVOUT_iv_3_out_wrapc,"w");
    if(fp == 0) begin       // Failed to open file
        $display("Failed to open file \"%s\"!", `AUTOTB_TVOUT_iv_3_out_wrapc);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    $fdisplay(fp,"[[[runtime]]]");
    transaction_idx = 0;
    while (transaction_idx != AUTOTB_TRANSACTION_NUM) begin
        @(posedge AESL_clock);
          while(AESL_done !== 1) begin
              @(posedge AESL_clock);
          end
        # 0.4;
        $fdisplay(fp,"[[transaction]] %d", transaction_idx);
        if(AESL_REG_iv_3_o_ap_vld)  begin
          $fdisplay(fp,"0x%x", AESL_REG_iv_3_o);
        AESL_REG_iv_3_o_ap_vld = 0;
        end
    transaction_idx = transaction_idx + 1;
      $fdisplay(fp,"[[/transaction]]");
    end
    $fdisplay(fp,"[[[/runtime]]]");
    $fclose(fp);
end


initial begin : generate_AESL_ready_cnt_proc
    AESL_ready_cnt = 0;
    wait(AESL_reset === 0);
    while(AESL_ready_cnt != AUTOTB_TRANSACTION_NUM) begin
        while(AESL_ready !== 1) begin
            @(posedge AESL_clock);
            # 0.4;
        end
        @(negedge AESL_clock);
        AESL_ready_cnt = AESL_ready_cnt + 1;
        @(posedge AESL_clock);
        # 0.4;
    end
end

    event next_trigger_ready_cnt;
    
    initial begin : gen_ready_cnt
        ready_cnt = 0;
        wait (AESL_reset === 0);
        forever begin
            @ (posedge AESL_clock);
            if (ready == 1) begin
                if (ready_cnt < AUTOTB_TRANSACTION_NUM) begin
                    ready_cnt = ready_cnt + 1;
                end
            end
            -> next_trigger_ready_cnt;
        end
    end
    
    wire all_finish = (done_cnt == AUTOTB_TRANSACTION_NUM);
    
    // done_cnt
    always @ (posedge AESL_clock) begin
        if (AESL_reset) begin
            done_cnt <= 0;
        end else begin
            if (AESL_done == 1) begin
                if (done_cnt < AUTOTB_TRANSACTION_NUM) begin
                    done_cnt <= done_cnt + 1;
                end
            end
        end
    end
    
    initial begin : finish_simulation
        integer fp1;
        integer fp2;
        wait (all_finish == 1);
        // last transaction is saved at negedge right after last done
        @ (posedge AESL_clock);
        @ (posedge AESL_clock);
        @ (posedge AESL_clock);
        @ (posedge AESL_clock);
    fp1 = $fopen("./rtl.aes16_bidir.autotvout_inout_0.dat", "r");
    fp2 = $fopen("./impl_rtl.aes16_bidir.autotvout_inout_0.dat", "r");
    if(fp1 == 0)        // Failed to open file
        $display("Failed to open file \"./rtl.aes16_bidir.autotvout_inout_0.dat\"!");
    else if(fp2 == 0)
        $display("Failed to open file \"./impl_rtl.aes16_bidir.autotvout_inout_0.dat\"!");
    else begin
        $display("Comparing rtl.aes16_bidir.autotvout_inout_0.dat with impl_rtl.aes16_bidir.autotvout_inout_0.dat");
        post_check(fp1, fp2);
    end
    $fclose(fp1);
    $fclose(fp2);
    fp1 = $fopen("./rtl.aes16_bidir.autotvout_inout_1.dat", "r");
    fp2 = $fopen("./impl_rtl.aes16_bidir.autotvout_inout_1.dat", "r");
    if(fp1 == 0)        // Failed to open file
        $display("Failed to open file \"./rtl.aes16_bidir.autotvout_inout_1.dat\"!");
    else if(fp2 == 0)
        $display("Failed to open file \"./impl_rtl.aes16_bidir.autotvout_inout_1.dat\"!");
    else begin
        $display("Comparing rtl.aes16_bidir.autotvout_inout_1.dat with impl_rtl.aes16_bidir.autotvout_inout_1.dat");
        post_check(fp1, fp2);
    end
    $fclose(fp1);
    $fclose(fp2);
    fp1 = $fopen("./rtl.aes16_bidir.autotvout_inout_2.dat", "r");
    fp2 = $fopen("./impl_rtl.aes16_bidir.autotvout_inout_2.dat", "r");
    if(fp1 == 0)        // Failed to open file
        $display("Failed to open file \"./rtl.aes16_bidir.autotvout_inout_2.dat\"!");
    else if(fp2 == 0)
        $display("Failed to open file \"./impl_rtl.aes16_bidir.autotvout_inout_2.dat\"!");
    else begin
        $display("Comparing rtl.aes16_bidir.autotvout_inout_2.dat with impl_rtl.aes16_bidir.autotvout_inout_2.dat");
        post_check(fp1, fp2);
    end
    $fclose(fp1);
    $fclose(fp2);
    fp1 = $fopen("./rtl.aes16_bidir.autotvout_inout_3.dat", "r");
    fp2 = $fopen("./impl_rtl.aes16_bidir.autotvout_inout_3.dat", "r");
    if(fp1 == 0)        // Failed to open file
        $display("Failed to open file \"./rtl.aes16_bidir.autotvout_inout_3.dat\"!");
    else if(fp2 == 0)
        $display("Failed to open file \"./impl_rtl.aes16_bidir.autotvout_inout_3.dat\"!");
    else begin
        $display("Comparing rtl.aes16_bidir.autotvout_inout_3.dat with impl_rtl.aes16_bidir.autotvout_inout_3.dat");
        post_check(fp1, fp2);
    end
    $fclose(fp1);
    $fclose(fp2);
    fp1 = $fopen("./rtl.aes16_bidir.autotvout_iv_0.dat", "r");
    fp2 = $fopen("./impl_rtl.aes16_bidir.autotvout_iv_0.dat", "r");
    if(fp1 == 0)        // Failed to open file
        $display("Failed to open file \"./rtl.aes16_bidir.autotvout_iv_0.dat\"!");
    else if(fp2 == 0)
        $display("Failed to open file \"./impl_rtl.aes16_bidir.autotvout_iv_0.dat\"!");
    else begin
        $display("Comparing rtl.aes16_bidir.autotvout_iv_0.dat with impl_rtl.aes16_bidir.autotvout_iv_0.dat");
        post_check(fp1, fp2);
    end
    $fclose(fp1);
    $fclose(fp2);
    fp1 = $fopen("./rtl.aes16_bidir.autotvout_iv_1.dat", "r");
    fp2 = $fopen("./impl_rtl.aes16_bidir.autotvout_iv_1.dat", "r");
    if(fp1 == 0)        // Failed to open file
        $display("Failed to open file \"./rtl.aes16_bidir.autotvout_iv_1.dat\"!");
    else if(fp2 == 0)
        $display("Failed to open file \"./impl_rtl.aes16_bidir.autotvout_iv_1.dat\"!");
    else begin
        $display("Comparing rtl.aes16_bidir.autotvout_iv_1.dat with impl_rtl.aes16_bidir.autotvout_iv_1.dat");
        post_check(fp1, fp2);
    end
    $fclose(fp1);
    $fclose(fp2);
    fp1 = $fopen("./rtl.aes16_bidir.autotvout_iv_2.dat", "r");
    fp2 = $fopen("./impl_rtl.aes16_bidir.autotvout_iv_2.dat", "r");
    if(fp1 == 0)        // Failed to open file
        $display("Failed to open file \"./rtl.aes16_bidir.autotvout_iv_2.dat\"!");
    else if(fp2 == 0)
        $display("Failed to open file \"./impl_rtl.aes16_bidir.autotvout_iv_2.dat\"!");
    else begin
        $display("Comparing rtl.aes16_bidir.autotvout_iv_2.dat with impl_rtl.aes16_bidir.autotvout_iv_2.dat");
        post_check(fp1, fp2);
    end
    $fclose(fp1);
    $fclose(fp2);
    fp1 = $fopen("./rtl.aes16_bidir.autotvout_iv_3.dat", "r");
    fp2 = $fopen("./impl_rtl.aes16_bidir.autotvout_iv_3.dat", "r");
    if(fp1 == 0)        // Failed to open file
        $display("Failed to open file \"./rtl.aes16_bidir.autotvout_iv_3.dat\"!");
    else if(fp2 == 0)
        $display("Failed to open file \"./impl_rtl.aes16_bidir.autotvout_iv_3.dat\"!");
    else begin
        $display("Comparing rtl.aes16_bidir.autotvout_iv_3.dat with impl_rtl.aes16_bidir.autotvout_iv_3.dat");
        post_check(fp1, fp2);
    end
    $fclose(fp1);
    $fclose(fp2);
        $display("Simulation Passed.");
        $finish;
    end
    
initial begin
    AESL_clock = 0;
    forever #`AUTOTB_CLOCK_PERIOD_DIV2 AESL_clock = ~AESL_clock;
end


reg end_key_0;
reg [31:0] size_key_0;
reg [31:0] size_key_0_backup;
reg end_key_1;
reg [31:0] size_key_1;
reg [31:0] size_key_1_backup;
reg end_key_2;
reg [31:0] size_key_2;
reg [31:0] size_key_2_backup;
reg end_key_3;
reg [31:0] size_key_3;
reg [31:0] size_key_3_backup;
reg end_inout_0;
reg [31:0] size_inout_0;
reg [31:0] size_inout_0_backup;
reg end_inout_1;
reg [31:0] size_inout_1;
reg [31:0] size_inout_1_backup;
reg end_inout_2;
reg [31:0] size_inout_2;
reg [31:0] size_inout_2_backup;
reg end_inout_3;
reg [31:0] size_inout_3;
reg [31:0] size_inout_3_backup;
reg end_iv_0;
reg [31:0] size_iv_0;
reg [31:0] size_iv_0_backup;
reg end_iv_1;
reg [31:0] size_iv_1;
reg [31:0] size_iv_1_backup;
reg end_iv_2;
reg [31:0] size_iv_2;
reg [31:0] size_iv_2_backup;
reg end_iv_3;
reg [31:0] size_iv_3;
reg [31:0] size_iv_3_backup;

initial begin : initial_process
    integer proc_rand;
    rst = 1;
    # 100;
    repeat(3) @ (posedge AESL_clock);
    rst = 0;
end
initial begin : start_process
    integer proc_rand;
    reg [31:0] start_cnt;
    ce = 1;
    start = 0;
    start_cnt = 0;
    wait (AESL_reset === 0);
    @ (posedge AESL_clock);
    #0 start = 1;
    start_cnt = start_cnt + 1;
    forever begin
        @ (posedge AESL_clock);
        if (start_cnt >= AUTOTB_TRANSACTION_NUM) begin
            // keep pushing garbage in
            #0 start = 1;
        end
        if (AESL_ready) begin
            start_cnt = start_cnt + 1;
        end
    end
end

always @(AESL_done)
begin
    tb_continue = AESL_done;
end

initial begin : ready_initial_process
    ready_initial = 0;
    wait (AESL_start === 1);
    ready_initial = 1;
    @(posedge AESL_clock);
    ready_initial = 0;
end

always @(posedge AESL_clock)
begin
    if(AESL_reset)
      AESL_ready_delay = 0;
  else
      AESL_ready_delay = AESL_ready;
end
initial begin : ready_last_n_process
  ready_last_n = 1;
  wait(ready_cnt == AUTOTB_TRANSACTION_NUM)
  @(posedge AESL_clock);
  ready_last_n <= 0;
end

always @(posedge AESL_clock)
begin
    if(AESL_reset)
      ready_delay_last_n = 0;
  else
      ready_delay_last_n <= ready_last_n;
end
assign ready = (ready_initial | AESL_ready_delay);
assign ready_wire = ready_initial | AESL_ready_delay;
initial begin : done_delay_last_n_process
  done_delay_last_n = 1;
  while(done_cnt < AUTOTB_TRANSACTION_NUM)
      @(posedge AESL_clock);
  # 0.1;
  done_delay_last_n = 0;
end

always @(posedge AESL_clock)
begin
    if(AESL_reset)
  begin
      AESL_done_delay <= 0;
      AESL_done_delay2 <= 0;
  end
  else begin
      AESL_done_delay <= AESL_done & done_delay_last_n;
      AESL_done_delay2 <= AESL_done_delay;
  end
end
always @(posedge AESL_clock)
begin
    if(AESL_reset)
      interface_done = 0;
  else begin
      # 0.01;
      if(ready === 1 && ready_cnt > 0 && ready_cnt < AUTOTB_TRANSACTION_NUM)
          interface_done = 1;
      else if(AESL_done_delay === 1 && done_cnt == AUTOTB_TRANSACTION_NUM)
          interface_done = 1;
      else
          interface_done = 0;
  end
end

////////////////////////////////////////////
// progress and performance
////////////////////////////////////////////

task wait_start();
    while (~AESL_start) begin
        @ (posedge AESL_clock);
    end
endtask

reg [31:0] clk_cnt = 0;
reg AESL_ready_p1;
reg AESL_start_p1;

always @ (posedge AESL_clock) begin
    clk_cnt <= clk_cnt + 1;
    AESL_ready_p1 <= AESL_ready;
    AESL_start_p1 <= AESL_start;
end

reg [31:0] start_timestamp [0:AUTOTB_TRANSACTION_NUM - 1];
reg [31:0] start_cnt;
reg [31:0] ready_timestamp [0:AUTOTB_TRANSACTION_NUM - 1];
reg [31:0] ap_ready_cnt;
reg [31:0] finish_timestamp [0:AUTOTB_TRANSACTION_NUM - 1];
reg [31:0] finish_cnt;
event report_progress;

initial begin
    start_cnt = 0;
    finish_cnt = 0;
    ap_ready_cnt = 0;
    wait (AESL_reset == 0);
    wait_start();
    start_timestamp[start_cnt] = clk_cnt;
    start_cnt = start_cnt + 1;
    if (AESL_done) begin
        finish_timestamp[finish_cnt] = clk_cnt;
        finish_cnt = finish_cnt + 1;
    end
    -> report_progress;
    forever begin
        @ (posedge AESL_clock);
        if (start_cnt < AUTOTB_TRANSACTION_NUM) begin
            if ((AESL_start && AESL_ready_p1)||(AESL_start && ~AESL_start_p1)) begin
                start_timestamp[start_cnt] = clk_cnt;
                start_cnt = start_cnt + 1;
            end
        end
        if (ap_ready_cnt < AUTOTB_TRANSACTION_NUM) begin
            if (AESL_start_p1 && AESL_ready_p1) begin
                ready_timestamp[ap_ready_cnt] = clk_cnt;
                ap_ready_cnt = ap_ready_cnt + 1;
            end
        end
        if (finish_cnt < AUTOTB_TRANSACTION_NUM) begin
            if (AESL_done) begin
                finish_timestamp[finish_cnt] = clk_cnt;
                finish_cnt = finish_cnt + 1;
            end
        end
        -> report_progress;
    end
end

reg [31:0] progress_timeout;

initial begin : simulation_progress
    real intra_progress;
    wait (AESL_reset == 0);
    progress_timeout = PROGRESS_TIMEOUT;
    $display("////////////////////////////////////////////////////////////////////////////////////");
    $display("// Inter-Transaction Progress: Completed Transaction / Total Transaction");
    $display("// Intra-Transaction Progress: Measured Latency / Latency Estimation * 100%%");
    $display("//");
    $display("// RTL Simulation : \"Inter-Transaction Progress\" [\"Intra-Transaction Progress\"] @ \"Simulation Time\"");
    $display("////////////////////////////////////////////////////////////////////////////////////");
    print_progress();
    while (finish_cnt < AUTOTB_TRANSACTION_NUM) begin
        @ (report_progress);
        if (finish_cnt < AUTOTB_TRANSACTION_NUM) begin
            if (AESL_done) begin
                print_progress();
                progress_timeout = PROGRESS_TIMEOUT;
            end else begin
                if (progress_timeout == 0) begin
                    print_progress();
                    progress_timeout = PROGRESS_TIMEOUT;
                end else begin
                    progress_timeout = progress_timeout - 1;
                end
            end
        end
    end
    print_progress();
    $display("////////////////////////////////////////////////////////////////////////////////////");
    calculate_performance();
end

task get_intra_progress(output real intra_progress);
    begin
        if (start_cnt > finish_cnt) begin
            intra_progress = clk_cnt - start_timestamp[finish_cnt];
        end else if(finish_cnt > 0) begin
            intra_progress = LATENCY_ESTIMATION;
        end else begin
            intra_progress = 0;
        end
        intra_progress = intra_progress / LATENCY_ESTIMATION;
    end
endtask

task print_progress();
    real intra_progress;
    begin
        if (LATENCY_ESTIMATION > 0) begin
            get_intra_progress(intra_progress);
            $display("// RTL Simulation : %0d / %0d [%2.2f%%] @ \"%0t\"", finish_cnt, AUTOTB_TRANSACTION_NUM, intra_progress * 100, $time);
        end else begin
            $display("// RTL Simulation : %0d / %0d [n/a] @ \"%0t\"", finish_cnt, AUTOTB_TRANSACTION_NUM, $time);
        end
    end
endtask

task calculate_performance();
    integer i;
    integer fp;
    reg [31:0] latency [0:AUTOTB_TRANSACTION_NUM - 1];
    reg [31:0] latency_min;
    reg [31:0] latency_max;
    reg [31:0] latency_total;
    reg [31:0] latency_average;
    reg [31:0] interval [0:AUTOTB_TRANSACTION_NUM - 2];
    reg [31:0] interval_min;
    reg [31:0] interval_max;
    reg [31:0] interval_total;
    reg [31:0] interval_average;
    begin
        latency_min = -1;
        latency_max = 0;
        latency_total = 0;
        interval_min = -1;
        interval_max = 0;
        interval_total = 0;

        for (i = 0; i < AUTOTB_TRANSACTION_NUM; i = i + 1) begin
            // calculate latency
            latency[i] = finish_timestamp[i] - start_timestamp[i];
            if (latency[i] > latency_max) latency_max = latency[i];
            if (latency[i] < latency_min) latency_min = latency[i];
            latency_total = latency_total + latency[i];
            // calculate interval
            if (AUTOTB_TRANSACTION_NUM == 1) begin
                interval[i] = 0;
                interval_max = 0;
                interval_min = 0;
                interval_total = 0;
            end else if (i < AUTOTB_TRANSACTION_NUM - 1) begin
                interval[i] = finish_timestamp[i] - start_timestamp[i]+1;
                if (interval[i] > interval_max) interval_max = interval[i];
                if (interval[i] < interval_min) interval_min = interval[i];
                interval_total = interval_total + interval[i];
            end
        end

        latency_average = latency_total / AUTOTB_TRANSACTION_NUM;
        if (AUTOTB_TRANSACTION_NUM == 1) begin
            interval_average = 0;
        end else begin
            interval_average = interval_total / (AUTOTB_TRANSACTION_NUM - 1);
        end

        fp = $fopen(`AUTOTB_LAT_RESULT_FILE, "w");

        $fdisplay(fp, "$MAX_LATENCY = \"%0d\"", latency_max);
        $fdisplay(fp, "$MIN_LATENCY = \"%0d\"", latency_min);
        $fdisplay(fp, "$AVER_LATENCY = \"%0d\"", latency_average);
        $fdisplay(fp, "$MAX_THROUGHPUT = \"%0d\"", interval_max);
        $fdisplay(fp, "$MIN_THROUGHPUT = \"%0d\"", interval_min);
        $fdisplay(fp, "$AVER_THROUGHPUT = \"%0d\"", interval_average);

        $fclose(fp);

        fp = $fopen(`AUTOTB_PER_RESULT_TRANS_FILE, "w");

        $fdisplay(fp, "%20s%16s%16s", "", "latency", "interval");
        if (AUTOTB_TRANSACTION_NUM == 1) begin
            i = 0;
            $fdisplay(fp, "transaction%8d:%16d%16d", i, latency[i], interval[i]);
        end else begin
            for (i = 0; i < AUTOTB_TRANSACTION_NUM; i = i + 1) begin
                if (i < AUTOTB_TRANSACTION_NUM - 1) begin
                    $fdisplay(fp, "transaction%8d:%16d%16d", i, latency[i], interval[i]);
                end else begin
                    $fdisplay(fp, "transaction%8d:%16d               x", i, latency[i]);
                end
            end
        end

        $fclose(fp);
    end
endtask


////////////////////////////////////////////
// Dependence Check
////////////////////////////////////////////

`ifndef POST_SYN

`endif

endmodule
