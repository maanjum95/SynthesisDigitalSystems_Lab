// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

module MixColumns (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        state_address0,
        state_ce0,
        state_we0,
        state_d0,
        state_q0,
        state_address1,
        state_ce1,
        state_we1,
        state_d1,
        state_q1
);

parameter    ap_ST_fsm_state1 = 5'd1;
parameter    ap_ST_fsm_state2 = 5'd2;
parameter    ap_ST_fsm_state3 = 5'd4;
parameter    ap_ST_fsm_state4 = 5'd8;
parameter    ap_ST_fsm_state5 = 5'd16;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
output  [3:0] state_address0;
output   state_ce0;
output   state_we0;
output  [7:0] state_d0;
input  [7:0] state_q0;
output  [3:0] state_address1;
output   state_ce1;
output   state_we1;
output  [7:0] state_d1;
input  [7:0] state_q1;

reg ap_done;
reg ap_idle;
reg ap_ready;
reg[3:0] state_address0;
reg state_ce0;
reg state_we0;
reg[7:0] state_d0;
reg[3:0] state_address1;
reg state_ce1;
reg state_we1;
reg[7:0] state_d1;

(* fsm_encoding = "none" *) reg   [4:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
wire   [2:0] i_fu_100_p2;
reg   [2:0] i_reg_351;
wire    ap_CS_fsm_state2;
wire   [4:0] tmp_fu_106_p3;
reg   [4:0] tmp_reg_356;
wire   [0:0] icmp_ln317_fu_94_p2;
reg   [3:0] state_addr_reg_362;
reg   [3:0] state_addr_12_reg_367;
reg   [3:0] state_addr_13_reg_372;
wire    ap_CS_fsm_state3;
reg   [3:0] state_addr_14_reg_377;
reg   [7:0] t_reg_382;
reg   [7:0] state_load_reg_389;
wire   [7:0] xor_ln328_1_fu_303_p2;
reg   [7:0] xor_ln328_1_reg_396;
wire    ap_CS_fsm_state4;
wire   [7:0] xor_ln331_fu_342_p2;
reg   [7:0] xor_ln331_reg_401;
reg   [2:0] i_0_reg_83;
wire    ap_CS_fsm_state5;
wire   [63:0] zext_ln318_fu_114_p1;
wire   [63:0] tmp_6_fu_125_p3;
wire   [63:0] tmp_7_fu_139_p3;
wire   [63:0] tmp_8_fu_153_p3;
wire   [7:0] xor_ln322_1_fu_211_p2;
wire   [7:0] xor_ln325_1_fu_256_p2;
wire   [4:0] or_ln319_fu_119_p2;
wire   [4:0] or_ln319_1_fu_134_p2;
wire   [4:0] or_ln319_2_fu_148_p2;
wire   [7:0] Tm_fu_162_p2;
wire   [7:0] xor_ln319_1_fu_166_p2;
wire   [0:0] tmp_1_fu_184_p3;
wire   [7:0] select_ln311_fu_192_p3;
wire   [7:0] shl_ln311_fu_178_p2;
wire   [7:0] Tmp_fu_172_p2;
wire   [7:0] xor_ln322_2_fu_205_p2;
wire   [7:0] xor_ln322_fu_200_p2;
wire   [7:0] Tm_1_fu_218_p2;
wire   [0:0] tmp_2_fu_229_p3;
wire   [7:0] select_ln311_1_fu_237_p3;
wire   [7:0] shl_ln311_1_fu_223_p2;
wire   [7:0] xor_ln325_2_fu_250_p2;
wire   [7:0] xor_ln325_fu_245_p2;
wire   [7:0] Tm_2_fu_263_p2;
wire   [0:0] tmp_3_fu_275_p3;
wire   [7:0] select_ln311_2_fu_283_p3;
wire   [7:0] shl_ln311_2_fu_269_p2;
wire   [7:0] xor_ln328_2_fu_297_p2;
wire   [7:0] xor_ln328_fu_291_p2;
wire   [7:0] Tm_3_fu_309_p2;
wire   [0:0] tmp_4_fu_320_p3;
wire   [7:0] shl_ln311_3_fu_314_p2;
wire   [7:0] xor_ln331_1_fu_336_p2;
wire   [7:0] select_ln311_3_fu_328_p3;
reg   [4:0] ap_NS_fsm;

// power-on initialization
initial begin
#0 ap_CS_fsm = 5'd1;
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state5)) begin
        i_0_reg_83 <= i_reg_351;
    end else if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
        i_0_reg_83 <= 3'd0;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        i_reg_351 <= i_fu_100_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln317_fu_94_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        state_addr_12_reg_367[3 : 2] <= tmp_6_fu_125_p3[3 : 2];
        state_addr_reg_362[3 : 2] <= zext_ln318_fu_114_p1[3 : 2];
        tmp_reg_356[4 : 2] <= tmp_fu_106_p3[4 : 2];
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        state_addr_13_reg_372[3 : 2] <= tmp_7_fu_139_p3[3 : 2];
        state_addr_14_reg_377[3 : 2] <= tmp_8_fu_153_p3[3 : 2];
        state_load_reg_389 <= state_q1;
        t_reg_382 <= state_q0;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state4)) begin
        xor_ln328_1_reg_396 <= xor_ln328_1_fu_303_p2;
        xor_ln331_reg_401 <= xor_ln331_fu_342_p2;
    end
end

always @ (*) begin
    if ((((icmp_ln317_fu_94_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2)) | ((ap_start == 1'b0) & (1'b1 == ap_CS_fsm_state1)))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = 1'b0;
    end
end

always @ (*) begin
    if (((ap_start == 1'b0) & (1'b1 == ap_CS_fsm_state1))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((icmp_ln317_fu_94_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state5)) begin
        state_address0 = state_addr_13_reg_372;
    end else if ((1'b1 == ap_CS_fsm_state4)) begin
        state_address0 = state_addr_reg_362;
    end else if ((1'b1 == ap_CS_fsm_state3)) begin
        state_address0 = tmp_7_fu_139_p3;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        state_address0 = zext_ln318_fu_114_p1;
    end else begin
        state_address0 = 'bx;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state5)) begin
        state_address1 = state_addr_14_reg_377;
    end else if ((1'b1 == ap_CS_fsm_state4)) begin
        state_address1 = state_addr_12_reg_367;
    end else if ((1'b1 == ap_CS_fsm_state3)) begin
        state_address1 = tmp_8_fu_153_p3;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        state_address1 = tmp_6_fu_125_p3;
    end else begin
        state_address1 = 'bx;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state5) | (1'b1 == ap_CS_fsm_state4) | (1'b1 == ap_CS_fsm_state3) | (1'b1 == ap_CS_fsm_state2))) begin
        state_ce0 = 1'b1;
    end else begin
        state_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state5) | (1'b1 == ap_CS_fsm_state4) | (1'b1 == ap_CS_fsm_state3) | (1'b1 == ap_CS_fsm_state2))) begin
        state_ce1 = 1'b1;
    end else begin
        state_ce1 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state5)) begin
        state_d0 = xor_ln328_1_reg_396;
    end else if ((1'b1 == ap_CS_fsm_state4)) begin
        state_d0 = xor_ln322_1_fu_211_p2;
    end else begin
        state_d0 = 'bx;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state5)) begin
        state_d1 = xor_ln331_reg_401;
    end else if ((1'b1 == ap_CS_fsm_state4)) begin
        state_d1 = xor_ln325_1_fu_256_p2;
    end else begin
        state_d1 = 'bx;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state5) | (1'b1 == ap_CS_fsm_state4))) begin
        state_we0 = 1'b1;
    end else begin
        state_we0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state5) | (1'b1 == ap_CS_fsm_state4))) begin
        state_we1 = 1'b1;
    end else begin
        state_we1 = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            if (((icmp_ln317_fu_94_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state3;
            end
        end
        ap_ST_fsm_state3 : begin
            ap_NS_fsm = ap_ST_fsm_state4;
        end
        ap_ST_fsm_state4 : begin
            ap_NS_fsm = ap_ST_fsm_state5;
        end
        ap_ST_fsm_state5 : begin
            ap_NS_fsm = ap_ST_fsm_state2;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign Tm_1_fu_218_p2 = (state_q0 ^ state_load_reg_389);

assign Tm_2_fu_263_p2 = (state_q1 ^ state_q0);

assign Tm_3_fu_309_p2 = (t_reg_382 ^ state_q1);

assign Tm_fu_162_p2 = (t_reg_382 ^ state_load_reg_389);

assign Tmp_fu_172_p2 = (xor_ln319_1_fu_166_p2 ^ state_q1);

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_state3 = ap_CS_fsm[32'd2];

assign ap_CS_fsm_state4 = ap_CS_fsm[32'd3];

assign ap_CS_fsm_state5 = ap_CS_fsm[32'd4];

assign i_fu_100_p2 = (i_0_reg_83 + 3'd1);

assign icmp_ln317_fu_94_p2 = ((i_0_reg_83 == 3'd4) ? 1'b1 : 1'b0);

assign or_ln319_1_fu_134_p2 = (tmp_reg_356 | 5'd2);

assign or_ln319_2_fu_148_p2 = (tmp_reg_356 | 5'd3);

assign or_ln319_fu_119_p2 = (tmp_fu_106_p3 | 5'd1);

assign select_ln311_1_fu_237_p3 = ((tmp_2_fu_229_p3[0:0] === 1'b1) ? 8'd27 : 8'd0);

assign select_ln311_2_fu_283_p3 = ((tmp_3_fu_275_p3[0:0] === 1'b1) ? 8'd27 : 8'd0);

assign select_ln311_3_fu_328_p3 = ((tmp_4_fu_320_p3[0:0] === 1'b1) ? 8'd27 : 8'd0);

assign select_ln311_fu_192_p3 = ((tmp_1_fu_184_p3[0:0] === 1'b1) ? 8'd27 : 8'd0);

assign shl_ln311_1_fu_223_p2 = Tm_1_fu_218_p2 << 8'd1;

assign shl_ln311_2_fu_269_p2 = Tm_2_fu_263_p2 << 8'd1;

assign shl_ln311_3_fu_314_p2 = Tm_3_fu_309_p2 << 8'd1;

assign shl_ln311_fu_178_p2 = Tm_fu_162_p2 << 8'd1;

assign tmp_1_fu_184_p3 = Tm_fu_162_p2[32'd7];

assign tmp_2_fu_229_p3 = Tm_1_fu_218_p2[32'd7];

assign tmp_3_fu_275_p3 = Tm_2_fu_263_p2[32'd7];

assign tmp_4_fu_320_p3 = Tm_3_fu_309_p2[32'd7];

assign tmp_6_fu_125_p3 = {{59'd0}, {or_ln319_fu_119_p2}};

assign tmp_7_fu_139_p3 = {{59'd0}, {or_ln319_1_fu_134_p2}};

assign tmp_8_fu_153_p3 = {{59'd0}, {or_ln319_2_fu_148_p2}};

assign tmp_fu_106_p3 = {{i_0_reg_83}, {2'd0}};

assign xor_ln319_1_fu_166_p2 = (state_q0 ^ Tm_fu_162_p2);

assign xor_ln322_1_fu_211_p2 = (xor_ln322_fu_200_p2 ^ xor_ln322_2_fu_205_p2);

assign xor_ln322_2_fu_205_p2 = (shl_ln311_fu_178_p2 ^ Tmp_fu_172_p2);

assign xor_ln322_fu_200_p2 = (t_reg_382 ^ select_ln311_fu_192_p3);

assign xor_ln325_1_fu_256_p2 = (xor_ln325_fu_245_p2 ^ xor_ln325_2_fu_250_p2);

assign xor_ln325_2_fu_250_p2 = (shl_ln311_1_fu_223_p2 ^ Tmp_fu_172_p2);

assign xor_ln325_fu_245_p2 = (state_load_reg_389 ^ select_ln311_1_fu_237_p3);

assign xor_ln328_1_fu_303_p2 = (xor_ln328_fu_291_p2 ^ xor_ln328_2_fu_297_p2);

assign xor_ln328_2_fu_297_p2 = (shl_ln311_2_fu_269_p2 ^ Tmp_fu_172_p2);

assign xor_ln328_fu_291_p2 = (state_q0 ^ select_ln311_2_fu_283_p3);

assign xor_ln331_1_fu_336_p2 = (xor_ln319_1_fu_166_p2 ^ shl_ln311_3_fu_314_p2);

assign xor_ln331_fu_342_p2 = (xor_ln331_1_fu_336_p2 ^ select_ln311_3_fu_328_p3);

assign zext_ln318_fu_114_p1 = tmp_fu_106_p3;

always @ (posedge ap_clk) begin
    tmp_reg_356[1:0] <= 2'b00;
    state_addr_reg_362[1:0] <= 2'b00;
    state_addr_12_reg_367[1:0] <= 2'b01;
    state_addr_13_reg_372[1:0] <= 2'b10;
    state_addr_14_reg_377[1:0] <= 2'b11;
end

endmodule //MixColumns
