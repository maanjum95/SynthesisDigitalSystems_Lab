// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
`timescale 1 ns / 1 ps
module KeyExpansion_sbox_rom (
addr0, ce0, q0, addr1, ce1, q1, clk);

parameter DWIDTH = 8;
parameter AWIDTH = 8;
parameter MEM_SIZE = 256;

input[AWIDTH-1:0] addr0;
input ce0;
output reg[DWIDTH-1:0] q0;
input[AWIDTH-1:0] addr1;
input ce1;
output reg[DWIDTH-1:0] q1;
input clk;

reg [DWIDTH-1:0] ram[0:MEM_SIZE-1];

initial begin
ram[0] = 8'h63;
ram[1] = 8'h7C;
ram[2] = 8'h77;
ram[3] = 8'h7B;
ram[4] = 8'hF2;
ram[5] = 8'h6B;
ram[6] = 8'h6F;
ram[7] = 8'hC5;
ram[8] = 8'h30;
ram[9] = 8'h01;
ram[10] = 8'h67;
ram[11] = 8'h2B;
ram[12] = 8'hFE;
ram[13] = 8'hD7;
ram[14] = 8'hAB;
ram[15] = 8'h76;
ram[16] = 8'hCA;
ram[17] = 8'h82;
ram[18] = 8'hC9;
ram[19] = 8'h7D;
ram[20] = 8'hFA;
ram[21] = 8'h59;
ram[22] = 8'h47;
ram[23] = 8'hF0;
ram[24] = 8'hAD;
ram[25] = 8'hD4;
ram[26] = 8'hA2;
ram[27] = 8'hAF;
ram[28] = 8'h9C;
ram[29] = 8'hA4;
ram[30] = 8'h72;
ram[31] = 8'hC0;
ram[32] = 8'hB7;
ram[33] = 8'hFD;
ram[34] = 8'h93;
ram[35] = 8'h26;
ram[36] = 8'h36;
ram[37] = 8'h3F;
ram[38] = 8'hF7;
ram[39] = 8'hCC;
ram[40] = 8'h34;
ram[41] = 8'hA5;
ram[42] = 8'hE5;
ram[43] = 8'hF1;
ram[44] = 8'h71;
ram[45] = 8'hD8;
ram[46] = 8'h31;
ram[47] = 8'h15;
ram[48] = 8'h04;
ram[49] = 8'hC7;
ram[50] = 8'h23;
ram[51] = 8'hC3;
ram[52] = 8'h18;
ram[53] = 8'h96;
ram[54] = 8'h05;
ram[55] = 8'h9A;
ram[56] = 8'h07;
ram[57] = 8'h12;
ram[58] = 8'h80;
ram[59] = 8'hE2;
ram[60] = 8'hEB;
ram[61] = 8'h27;
ram[62] = 8'hB2;
ram[63] = 8'h75;
ram[64] = 8'h09;
ram[65] = 8'h83;
ram[66] = 8'h2C;
ram[67] = 8'h1A;
ram[68] = 8'h1B;
ram[69] = 8'h6E;
ram[70] = 8'h5A;
ram[71] = 8'hA0;
ram[72] = 8'h52;
ram[73] = 8'h3B;
ram[74] = 8'hD6;
ram[75] = 8'hB3;
ram[76] = 8'h29;
ram[77] = 8'hE3;
ram[78] = 8'h2F;
ram[79] = 8'h84;
ram[80] = 8'h53;
ram[81] = 8'hD1;
ram[82] = 8'h00;
ram[83] = 8'hED;
ram[84] = 8'h20;
ram[85] = 8'hFC;
ram[86] = 8'hB1;
ram[87] = 8'h5B;
ram[88] = 8'h6A;
ram[89] = 8'hCB;
ram[90] = 8'hBE;
ram[91] = 8'h39;
ram[92] = 8'h4A;
ram[93] = 8'h4C;
ram[94] = 8'h58;
ram[95] = 8'hCF;
ram[96] = 8'hD0;
ram[97] = 8'hEF;
ram[98] = 8'hAA;
ram[99] = 8'hFB;
ram[100] = 8'h43;
ram[101] = 8'h4D;
ram[102] = 8'h33;
ram[103] = 8'h85;
ram[104] = 8'h45;
ram[105] = 8'hF9;
ram[106] = 8'h02;
ram[107] = 8'h7F;
ram[108] = 8'h50;
ram[109] = 8'h3C;
ram[110] = 8'h9F;
ram[111] = 8'hA8;
ram[112] = 8'h51;
ram[113] = 8'hA3;
ram[114] = 8'h40;
ram[115] = 8'h8F;
ram[116] = 8'h92;
ram[117] = 8'h9D;
ram[118] = 8'h38;
ram[119] = 8'hF5;
ram[120] = 8'hBC;
ram[121] = 8'hB6;
ram[122] = 8'hDA;
ram[123] = 8'h21;
ram[124] = 8'h10;
ram[125] = 8'hFF;
ram[126] = 8'hF3;
ram[127] = 8'hD2;
ram[128] = 8'hCD;
ram[129] = 8'h0C;
ram[130] = 8'h13;
ram[131] = 8'hEC;
ram[132] = 8'h5F;
ram[133] = 8'h97;
ram[134] = 8'h44;
ram[135] = 8'h17;
ram[136] = 8'hC4;
ram[137] = 8'hA7;
ram[138] = 8'h7E;
ram[139] = 8'h3D;
ram[140] = 8'h64;
ram[141] = 8'h5D;
ram[142] = 8'h19;
ram[143] = 8'h73;
ram[144] = 8'h60;
ram[145] = 8'h81;
ram[146] = 8'h4F;
ram[147] = 8'hDC;
ram[148] = 8'h22;
ram[149] = 8'h2A;
ram[150] = 8'h90;
ram[151] = 8'h88;
ram[152] = 8'h46;
ram[153] = 8'hEE;
ram[154] = 8'hB8;
ram[155] = 8'h14;
ram[156] = 8'hDE;
ram[157] = 8'h5E;
ram[158] = 8'h0B;
ram[159] = 8'hDB;
ram[160] = 8'hE0;
ram[161] = 8'h32;
ram[162] = 8'h3A;
ram[163] = 8'h0A;
ram[164] = 8'h49;
ram[165] = 8'h06;
ram[166] = 8'h24;
ram[167] = 8'h5C;
ram[168] = 8'hC2;
ram[169] = 8'hD3;
ram[170] = 8'hAC;
ram[171] = 8'h62;
ram[172] = 8'h91;
ram[173] = 8'h95;
ram[174] = 8'hE4;
ram[175] = 8'h79;
ram[176] = 8'hE7;
ram[177] = 8'hC8;
ram[178] = 8'h37;
ram[179] = 8'h6D;
ram[180] = 8'h8D;
ram[181] = 8'hD5;
ram[182] = 8'h4E;
ram[183] = 8'hA9;
ram[184] = 8'h6C;
ram[185] = 8'h56;
ram[186] = 8'hF4;
ram[187] = 8'hEA;
ram[188] = 8'h65;
ram[189] = 8'h7A;
ram[190] = 8'hAE;
ram[191] = 8'h08;
ram[192] = 8'hBA;
ram[193] = 8'h78;
ram[194] = 8'h25;
ram[195] = 8'h2E;
ram[196] = 8'h1C;
ram[197] = 8'hA6;
ram[198] = 8'hB4;
ram[199] = 8'hC6;
ram[200] = 8'hE8;
ram[201] = 8'hDD;
ram[202] = 8'h74;
ram[203] = 8'h1F;
ram[204] = 8'h4B;
ram[205] = 8'hBD;
ram[206] = 8'h8B;
ram[207] = 8'h8A;
ram[208] = 8'h70;
ram[209] = 8'h3E;
ram[210] = 8'hB5;
ram[211] = 8'h66;
ram[212] = 8'h48;
ram[213] = 8'h03;
ram[214] = 8'hF6;
ram[215] = 8'h0E;
ram[216] = 8'h61;
ram[217] = 8'h35;
ram[218] = 8'h57;
ram[219] = 8'hB9;
ram[220] = 8'h86;
ram[221] = 8'hC1;
ram[222] = 8'h1D;
ram[223] = 8'h9E;
ram[224] = 8'hE1;
ram[225] = 8'hF8;
ram[226] = 8'h98;
ram[227] = 8'h11;
ram[228] = 8'h69;
ram[229] = 8'hD9;
ram[230] = 8'h8E;
ram[231] = 8'h94;
ram[232] = 8'h9B;
ram[233] = 8'h1E;
ram[234] = 8'h87;
ram[235] = 8'hE9;
ram[236] = 8'hCE;
ram[237] = 8'h55;
ram[238] = 8'h28;
ram[239] = 8'hDF;
ram[240] = 8'h8C;
ram[241] = 8'hA1;
ram[242] = 8'h89;
ram[243] = 8'h0D;
ram[244] = 8'hBF;
ram[245] = 8'hE6;
ram[246] = 8'h42;
ram[247] = 8'h68;
ram[248] = 8'h41;
ram[249] = 8'h99;
ram[250] = 8'h2D;
ram[251] = 8'h0F;
ram[252] = 8'hB0;
ram[253] = 8'h54;
ram[254] = 8'hBB;
ram[255] = 8'h16;
end



always @(posedge clk)  
begin 
    if (ce0) 
    begin
        q0 <= ram[addr0];
    end
end



always @(posedge clk)  
begin 
    if (ce1) 
    begin
        q1 <= ram[addr1];
    end
end



endmodule

`timescale 1 ns / 1 ps
module KeyExpansion_sbox(
    reset,
    clk,
    address0,
    ce0,
    q0,
    address1,
    ce1,
    q1);

parameter DataWidth = 32'd8;
parameter AddressRange = 32'd256;
parameter AddressWidth = 32'd8;
input reset;
input clk;
input[AddressWidth - 1:0] address0;
input ce0;
output[DataWidth - 1:0] q0;
input[AddressWidth - 1:0] address1;
input ce1;
output[DataWidth - 1:0] q1;



KeyExpansion_sbox_rom KeyExpansion_sbox_rom_U(
    .clk( clk ),
    .addr0( address0 ),
    .ce0( ce0 ),
    .q0( q0 ),
    .addr1( address1 ),
    .ce1( ce1 ),
    .q1( q1 ));

endmodule

