// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#include "MixColumns.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

const sc_logic MixColumns::ap_const_logic_1 = sc_dt::Log_1;
const sc_logic MixColumns::ap_const_logic_0 = sc_dt::Log_0;
const sc_lv<5> MixColumns::ap_ST_fsm_state1 = "1";
const sc_lv<5> MixColumns::ap_ST_fsm_state2 = "10";
const sc_lv<5> MixColumns::ap_ST_fsm_state3 = "100";
const sc_lv<5> MixColumns::ap_ST_fsm_state4 = "1000";
const sc_lv<5> MixColumns::ap_ST_fsm_state5 = "10000";
const sc_lv<32> MixColumns::ap_const_lv32_0 = "00000000000000000000000000000000";
const sc_lv<32> MixColumns::ap_const_lv32_1 = "1";
const sc_lv<1> MixColumns::ap_const_lv1_0 = "0";
const sc_lv<32> MixColumns::ap_const_lv32_2 = "10";
const sc_lv<32> MixColumns::ap_const_lv32_3 = "11";
const sc_lv<3> MixColumns::ap_const_lv3_0 = "000";
const sc_lv<32> MixColumns::ap_const_lv32_4 = "100";
const sc_lv<3> MixColumns::ap_const_lv3_4 = "100";
const sc_lv<3> MixColumns::ap_const_lv3_1 = "1";
const sc_lv<2> MixColumns::ap_const_lv2_0 = "00";
const sc_lv<5> MixColumns::ap_const_lv5_1 = "1";
const sc_lv<59> MixColumns::ap_const_lv59_0 = "00000000000000000000000000000000000000000000000000000000000";
const sc_lv<5> MixColumns::ap_const_lv5_2 = "10";
const sc_lv<5> MixColumns::ap_const_lv5_3 = "11";
const sc_lv<8> MixColumns::ap_const_lv8_1 = "1";
const sc_lv<32> MixColumns::ap_const_lv32_7 = "111";
const sc_lv<8> MixColumns::ap_const_lv8_1B = "11011";
const sc_lv<8> MixColumns::ap_const_lv8_0 = "00000000";
const sc_lv<1> MixColumns::ap_const_lv1_1 = "1";
const bool MixColumns::ap_const_boolean_1 = true;

MixColumns::MixColumns(sc_module_name name) : sc_module(name), mVcdFile(0) {

    SC_METHOD(thread_ap_clk_no_reset_);
    dont_initialize();
    sensitive << ( ap_clk.pos() );

    SC_METHOD(thread_Tm_1_fu_218_p2);
    sensitive << ( state_q0 );
    sensitive << ( state_load_reg_389 );

    SC_METHOD(thread_Tm_2_fu_263_p2);
    sensitive << ( state_q0 );
    sensitive << ( state_q1 );

    SC_METHOD(thread_Tm_3_fu_309_p2);
    sensitive << ( state_q1 );
    sensitive << ( t_reg_382 );

    SC_METHOD(thread_Tm_fu_162_p2);
    sensitive << ( t_reg_382 );
    sensitive << ( state_load_reg_389 );

    SC_METHOD(thread_Tmp_fu_172_p2);
    sensitive << ( state_q1 );
    sensitive << ( xor_ln319_1_fu_166_p2 );

    SC_METHOD(thread_ap_CS_fsm_state1);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state2);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state3);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state4);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state5);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_done);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( icmp_ln317_fu_94_p2 );

    SC_METHOD(thread_ap_idle);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );

    SC_METHOD(thread_ap_ready);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( icmp_ln317_fu_94_p2 );

    SC_METHOD(thread_i_fu_100_p2);
    sensitive << ( i_0_reg_83 );

    SC_METHOD(thread_icmp_ln317_fu_94_p2);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( i_0_reg_83 );

    SC_METHOD(thread_or_ln319_1_fu_134_p2);
    sensitive << ( tmp_reg_356 );

    SC_METHOD(thread_or_ln319_2_fu_148_p2);
    sensitive << ( tmp_reg_356 );

    SC_METHOD(thread_or_ln319_fu_119_p2);
    sensitive << ( tmp_fu_106_p3 );

    SC_METHOD(thread_select_ln311_1_fu_237_p3);
    sensitive << ( tmp_2_fu_229_p3 );

    SC_METHOD(thread_select_ln311_2_fu_283_p3);
    sensitive << ( tmp_3_fu_275_p3 );

    SC_METHOD(thread_select_ln311_3_fu_328_p3);
    sensitive << ( tmp_4_fu_320_p3 );

    SC_METHOD(thread_select_ln311_fu_192_p3);
    sensitive << ( tmp_1_fu_184_p3 );

    SC_METHOD(thread_shl_ln311_1_fu_223_p2);
    sensitive << ( Tm_1_fu_218_p2 );

    SC_METHOD(thread_shl_ln311_2_fu_269_p2);
    sensitive << ( Tm_2_fu_263_p2 );

    SC_METHOD(thread_shl_ln311_3_fu_314_p2);
    sensitive << ( Tm_3_fu_309_p2 );

    SC_METHOD(thread_shl_ln311_fu_178_p2);
    sensitive << ( Tm_fu_162_p2 );

    SC_METHOD(thread_state_address0);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( state_addr_reg_362 );
    sensitive << ( state_addr_13_reg_372 );
    sensitive << ( ap_CS_fsm_state3 );
    sensitive << ( ap_CS_fsm_state4 );
    sensitive << ( ap_CS_fsm_state5 );
    sensitive << ( zext_ln318_fu_114_p1 );
    sensitive << ( tmp_7_fu_139_p3 );

    SC_METHOD(thread_state_address1);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( state_addr_12_reg_367 );
    sensitive << ( ap_CS_fsm_state3 );
    sensitive << ( state_addr_14_reg_377 );
    sensitive << ( ap_CS_fsm_state4 );
    sensitive << ( ap_CS_fsm_state5 );
    sensitive << ( tmp_6_fu_125_p3 );
    sensitive << ( tmp_8_fu_153_p3 );

    SC_METHOD(thread_state_ce0);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( ap_CS_fsm_state3 );
    sensitive << ( ap_CS_fsm_state4 );
    sensitive << ( ap_CS_fsm_state5 );

    SC_METHOD(thread_state_ce1);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( ap_CS_fsm_state3 );
    sensitive << ( ap_CS_fsm_state4 );
    sensitive << ( ap_CS_fsm_state5 );

    SC_METHOD(thread_state_d0);
    sensitive << ( xor_ln328_1_reg_396 );
    sensitive << ( ap_CS_fsm_state4 );
    sensitive << ( ap_CS_fsm_state5 );
    sensitive << ( xor_ln322_1_fu_211_p2 );

    SC_METHOD(thread_state_d1);
    sensitive << ( ap_CS_fsm_state4 );
    sensitive << ( xor_ln331_reg_401 );
    sensitive << ( ap_CS_fsm_state5 );
    sensitive << ( xor_ln325_1_fu_256_p2 );

    SC_METHOD(thread_state_we0);
    sensitive << ( ap_CS_fsm_state4 );
    sensitive << ( ap_CS_fsm_state5 );

    SC_METHOD(thread_state_we1);
    sensitive << ( ap_CS_fsm_state4 );
    sensitive << ( ap_CS_fsm_state5 );

    SC_METHOD(thread_tmp_1_fu_184_p3);
    sensitive << ( Tm_fu_162_p2 );

    SC_METHOD(thread_tmp_2_fu_229_p3);
    sensitive << ( Tm_1_fu_218_p2 );

    SC_METHOD(thread_tmp_3_fu_275_p3);
    sensitive << ( Tm_2_fu_263_p2 );

    SC_METHOD(thread_tmp_4_fu_320_p3);
    sensitive << ( Tm_3_fu_309_p2 );

    SC_METHOD(thread_tmp_6_fu_125_p3);
    sensitive << ( or_ln319_fu_119_p2 );

    SC_METHOD(thread_tmp_7_fu_139_p3);
    sensitive << ( or_ln319_1_fu_134_p2 );

    SC_METHOD(thread_tmp_8_fu_153_p3);
    sensitive << ( or_ln319_2_fu_148_p2 );

    SC_METHOD(thread_tmp_fu_106_p3);
    sensitive << ( i_0_reg_83 );

    SC_METHOD(thread_xor_ln319_1_fu_166_p2);
    sensitive << ( state_q0 );
    sensitive << ( Tm_fu_162_p2 );

    SC_METHOD(thread_xor_ln322_1_fu_211_p2);
    sensitive << ( xor_ln322_2_fu_205_p2 );
    sensitive << ( xor_ln322_fu_200_p2 );

    SC_METHOD(thread_xor_ln322_2_fu_205_p2);
    sensitive << ( shl_ln311_fu_178_p2 );
    sensitive << ( Tmp_fu_172_p2 );

    SC_METHOD(thread_xor_ln322_fu_200_p2);
    sensitive << ( t_reg_382 );
    sensitive << ( select_ln311_fu_192_p3 );

    SC_METHOD(thread_xor_ln325_1_fu_256_p2);
    sensitive << ( xor_ln325_2_fu_250_p2 );
    sensitive << ( xor_ln325_fu_245_p2 );

    SC_METHOD(thread_xor_ln325_2_fu_250_p2);
    sensitive << ( Tmp_fu_172_p2 );
    sensitive << ( shl_ln311_1_fu_223_p2 );

    SC_METHOD(thread_xor_ln325_fu_245_p2);
    sensitive << ( state_load_reg_389 );
    sensitive << ( select_ln311_1_fu_237_p3 );

    SC_METHOD(thread_xor_ln328_1_fu_303_p2);
    sensitive << ( xor_ln328_2_fu_297_p2 );
    sensitive << ( xor_ln328_fu_291_p2 );

    SC_METHOD(thread_xor_ln328_2_fu_297_p2);
    sensitive << ( Tmp_fu_172_p2 );
    sensitive << ( shl_ln311_2_fu_269_p2 );

    SC_METHOD(thread_xor_ln328_fu_291_p2);
    sensitive << ( state_q0 );
    sensitive << ( select_ln311_2_fu_283_p3 );

    SC_METHOD(thread_xor_ln331_1_fu_336_p2);
    sensitive << ( xor_ln319_1_fu_166_p2 );
    sensitive << ( shl_ln311_3_fu_314_p2 );

    SC_METHOD(thread_xor_ln331_fu_342_p2);
    sensitive << ( xor_ln331_1_fu_336_p2 );
    sensitive << ( select_ln311_3_fu_328_p3 );

    SC_METHOD(thread_zext_ln318_fu_114_p1);
    sensitive << ( tmp_fu_106_p3 );

    SC_METHOD(thread_ap_NS_fsm);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm );
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( icmp_ln317_fu_94_p2 );

    ap_CS_fsm = "00001";
    static int apTFileNum = 0;
    stringstream apTFilenSS;
    apTFilenSS << "MixColumns_sc_trace_" << apTFileNum ++;
    string apTFn = apTFilenSS.str();
    mVcdFile = sc_create_vcd_trace_file(apTFn.c_str());
    mVcdFile->set_time_unit(1, SC_PS);
    if (1) {
#ifdef __HLS_TRACE_LEVEL_PORT_HIER__
    sc_trace(mVcdFile, ap_clk, "(port)ap_clk");
    sc_trace(mVcdFile, ap_rst, "(port)ap_rst");
    sc_trace(mVcdFile, ap_start, "(port)ap_start");
    sc_trace(mVcdFile, ap_done, "(port)ap_done");
    sc_trace(mVcdFile, ap_idle, "(port)ap_idle");
    sc_trace(mVcdFile, ap_ready, "(port)ap_ready");
    sc_trace(mVcdFile, state_address0, "(port)state_address0");
    sc_trace(mVcdFile, state_ce0, "(port)state_ce0");
    sc_trace(mVcdFile, state_we0, "(port)state_we0");
    sc_trace(mVcdFile, state_d0, "(port)state_d0");
    sc_trace(mVcdFile, state_q0, "(port)state_q0");
    sc_trace(mVcdFile, state_address1, "(port)state_address1");
    sc_trace(mVcdFile, state_ce1, "(port)state_ce1");
    sc_trace(mVcdFile, state_we1, "(port)state_we1");
    sc_trace(mVcdFile, state_d1, "(port)state_d1");
    sc_trace(mVcdFile, state_q1, "(port)state_q1");
#endif
#ifdef __HLS_TRACE_LEVEL_INT__
    sc_trace(mVcdFile, ap_CS_fsm, "ap_CS_fsm");
    sc_trace(mVcdFile, ap_CS_fsm_state1, "ap_CS_fsm_state1");
    sc_trace(mVcdFile, i_fu_100_p2, "i_fu_100_p2");
    sc_trace(mVcdFile, i_reg_351, "i_reg_351");
    sc_trace(mVcdFile, ap_CS_fsm_state2, "ap_CS_fsm_state2");
    sc_trace(mVcdFile, tmp_fu_106_p3, "tmp_fu_106_p3");
    sc_trace(mVcdFile, tmp_reg_356, "tmp_reg_356");
    sc_trace(mVcdFile, icmp_ln317_fu_94_p2, "icmp_ln317_fu_94_p2");
    sc_trace(mVcdFile, state_addr_reg_362, "state_addr_reg_362");
    sc_trace(mVcdFile, state_addr_12_reg_367, "state_addr_12_reg_367");
    sc_trace(mVcdFile, state_addr_13_reg_372, "state_addr_13_reg_372");
    sc_trace(mVcdFile, ap_CS_fsm_state3, "ap_CS_fsm_state3");
    sc_trace(mVcdFile, state_addr_14_reg_377, "state_addr_14_reg_377");
    sc_trace(mVcdFile, t_reg_382, "t_reg_382");
    sc_trace(mVcdFile, state_load_reg_389, "state_load_reg_389");
    sc_trace(mVcdFile, xor_ln328_1_fu_303_p2, "xor_ln328_1_fu_303_p2");
    sc_trace(mVcdFile, xor_ln328_1_reg_396, "xor_ln328_1_reg_396");
    sc_trace(mVcdFile, ap_CS_fsm_state4, "ap_CS_fsm_state4");
    sc_trace(mVcdFile, xor_ln331_fu_342_p2, "xor_ln331_fu_342_p2");
    sc_trace(mVcdFile, xor_ln331_reg_401, "xor_ln331_reg_401");
    sc_trace(mVcdFile, i_0_reg_83, "i_0_reg_83");
    sc_trace(mVcdFile, ap_CS_fsm_state5, "ap_CS_fsm_state5");
    sc_trace(mVcdFile, zext_ln318_fu_114_p1, "zext_ln318_fu_114_p1");
    sc_trace(mVcdFile, tmp_6_fu_125_p3, "tmp_6_fu_125_p3");
    sc_trace(mVcdFile, tmp_7_fu_139_p3, "tmp_7_fu_139_p3");
    sc_trace(mVcdFile, tmp_8_fu_153_p3, "tmp_8_fu_153_p3");
    sc_trace(mVcdFile, xor_ln322_1_fu_211_p2, "xor_ln322_1_fu_211_p2");
    sc_trace(mVcdFile, xor_ln325_1_fu_256_p2, "xor_ln325_1_fu_256_p2");
    sc_trace(mVcdFile, or_ln319_fu_119_p2, "or_ln319_fu_119_p2");
    sc_trace(mVcdFile, or_ln319_1_fu_134_p2, "or_ln319_1_fu_134_p2");
    sc_trace(mVcdFile, or_ln319_2_fu_148_p2, "or_ln319_2_fu_148_p2");
    sc_trace(mVcdFile, Tm_fu_162_p2, "Tm_fu_162_p2");
    sc_trace(mVcdFile, xor_ln319_1_fu_166_p2, "xor_ln319_1_fu_166_p2");
    sc_trace(mVcdFile, tmp_1_fu_184_p3, "tmp_1_fu_184_p3");
    sc_trace(mVcdFile, select_ln311_fu_192_p3, "select_ln311_fu_192_p3");
    sc_trace(mVcdFile, shl_ln311_fu_178_p2, "shl_ln311_fu_178_p2");
    sc_trace(mVcdFile, Tmp_fu_172_p2, "Tmp_fu_172_p2");
    sc_trace(mVcdFile, xor_ln322_2_fu_205_p2, "xor_ln322_2_fu_205_p2");
    sc_trace(mVcdFile, xor_ln322_fu_200_p2, "xor_ln322_fu_200_p2");
    sc_trace(mVcdFile, Tm_1_fu_218_p2, "Tm_1_fu_218_p2");
    sc_trace(mVcdFile, tmp_2_fu_229_p3, "tmp_2_fu_229_p3");
    sc_trace(mVcdFile, select_ln311_1_fu_237_p3, "select_ln311_1_fu_237_p3");
    sc_trace(mVcdFile, shl_ln311_1_fu_223_p2, "shl_ln311_1_fu_223_p2");
    sc_trace(mVcdFile, xor_ln325_2_fu_250_p2, "xor_ln325_2_fu_250_p2");
    sc_trace(mVcdFile, xor_ln325_fu_245_p2, "xor_ln325_fu_245_p2");
    sc_trace(mVcdFile, Tm_2_fu_263_p2, "Tm_2_fu_263_p2");
    sc_trace(mVcdFile, tmp_3_fu_275_p3, "tmp_3_fu_275_p3");
    sc_trace(mVcdFile, select_ln311_2_fu_283_p3, "select_ln311_2_fu_283_p3");
    sc_trace(mVcdFile, shl_ln311_2_fu_269_p2, "shl_ln311_2_fu_269_p2");
    sc_trace(mVcdFile, xor_ln328_2_fu_297_p2, "xor_ln328_2_fu_297_p2");
    sc_trace(mVcdFile, xor_ln328_fu_291_p2, "xor_ln328_fu_291_p2");
    sc_trace(mVcdFile, Tm_3_fu_309_p2, "Tm_3_fu_309_p2");
    sc_trace(mVcdFile, tmp_4_fu_320_p3, "tmp_4_fu_320_p3");
    sc_trace(mVcdFile, shl_ln311_3_fu_314_p2, "shl_ln311_3_fu_314_p2");
    sc_trace(mVcdFile, xor_ln331_1_fu_336_p2, "xor_ln331_1_fu_336_p2");
    sc_trace(mVcdFile, select_ln311_3_fu_328_p3, "select_ln311_3_fu_328_p3");
    sc_trace(mVcdFile, ap_NS_fsm, "ap_NS_fsm");
#endif

    }
}

MixColumns::~MixColumns() {
    if (mVcdFile) 
        sc_close_vcd_trace_file(mVcdFile);

}

void MixColumns::thread_ap_clk_no_reset_() {
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_CS_fsm = ap_ST_fsm_state1;
    } else {
        ap_CS_fsm = ap_NS_fsm.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read())) {
        i_0_reg_83 = i_reg_351.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        i_0_reg_83 = ap_const_lv3_0;
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read())) {
        i_reg_351 = i_fu_100_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && esl_seteq<1,1,1>(icmp_ln317_fu_94_p2.read(), ap_const_lv1_0))) {
        state_addr_12_reg_367 =  (sc_lv<4>) (tmp_6_fu_125_p3.read());
        state_addr_reg_362 =  (sc_lv<4>) (zext_ln318_fu_114_p1.read());
        tmp_reg_356 = tmp_fu_106_p3.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read())) {
        state_addr_13_reg_372 =  (sc_lv<4>) (tmp_7_fu_139_p3.read());
        state_addr_14_reg_377 =  (sc_lv<4>) (tmp_8_fu_153_p3.read());
        state_load_reg_389 = state_q1.read();
        t_reg_382 = state_q0.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read())) {
        xor_ln328_1_reg_396 = xor_ln328_1_fu_303_p2.read();
        xor_ln331_reg_401 = xor_ln331_fu_342_p2.read();
    }
}

void MixColumns::thread_Tm_1_fu_218_p2() {
    Tm_1_fu_218_p2 = (state_q0.read() ^ state_load_reg_389.read());
}

void MixColumns::thread_Tm_2_fu_263_p2() {
    Tm_2_fu_263_p2 = (state_q1.read() ^ state_q0.read());
}

void MixColumns::thread_Tm_3_fu_309_p2() {
    Tm_3_fu_309_p2 = (state_q1.read() ^ t_reg_382.read());
}

void MixColumns::thread_Tm_fu_162_p2() {
    Tm_fu_162_p2 = (state_load_reg_389.read() ^ t_reg_382.read());
}

void MixColumns::thread_Tmp_fu_172_p2() {
    Tmp_fu_172_p2 = (state_q1.read() ^ xor_ln319_1_fu_166_p2.read());
}

void MixColumns::thread_ap_CS_fsm_state1() {
    ap_CS_fsm_state1 = ap_CS_fsm.read()[0];
}

void MixColumns::thread_ap_CS_fsm_state2() {
    ap_CS_fsm_state2 = ap_CS_fsm.read()[1];
}

void MixColumns::thread_ap_CS_fsm_state3() {
    ap_CS_fsm_state3 = ap_CS_fsm.read()[2];
}

void MixColumns::thread_ap_CS_fsm_state4() {
    ap_CS_fsm_state4 = ap_CS_fsm.read()[3];
}

void MixColumns::thread_ap_CS_fsm_state5() {
    ap_CS_fsm_state5 = ap_CS_fsm.read()[4];
}

void MixColumns::thread_ap_done() {
    if (((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
          esl_seteq<1,1,1>(icmp_ln317_fu_94_p2.read(), ap_const_lv1_1)))) {
        ap_done = ap_const_logic_1;
    } else {
        ap_done = ap_const_logic_0;
    }
}

void MixColumns::thread_ap_idle() {
    if ((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()))) {
        ap_idle = ap_const_logic_1;
    } else {
        ap_idle = ap_const_logic_0;
    }
}

void MixColumns::thread_ap_ready() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
         esl_seteq<1,1,1>(icmp_ln317_fu_94_p2.read(), ap_const_lv1_1))) {
        ap_ready = ap_const_logic_1;
    } else {
        ap_ready = ap_const_logic_0;
    }
}

void MixColumns::thread_i_fu_100_p2() {
    i_fu_100_p2 = (!i_0_reg_83.read().is_01() || !ap_const_lv3_1.is_01())? sc_lv<3>(): (sc_biguint<3>(i_0_reg_83.read()) + sc_biguint<3>(ap_const_lv3_1));
}

void MixColumns::thread_icmp_ln317_fu_94_p2() {
    icmp_ln317_fu_94_p2 = (!i_0_reg_83.read().is_01() || !ap_const_lv3_4.is_01())? sc_lv<1>(): sc_lv<1>(i_0_reg_83.read() == ap_const_lv3_4);
}

void MixColumns::thread_or_ln319_1_fu_134_p2() {
    or_ln319_1_fu_134_p2 = (tmp_reg_356.read() | ap_const_lv5_2);
}

void MixColumns::thread_or_ln319_2_fu_148_p2() {
    or_ln319_2_fu_148_p2 = (tmp_reg_356.read() | ap_const_lv5_3);
}

void MixColumns::thread_or_ln319_fu_119_p2() {
    or_ln319_fu_119_p2 = (tmp_fu_106_p3.read() | ap_const_lv5_1);
}

void MixColumns::thread_select_ln311_1_fu_237_p3() {
    select_ln311_1_fu_237_p3 = (!tmp_2_fu_229_p3.read()[0].is_01())? sc_lv<8>(): ((tmp_2_fu_229_p3.read()[0].to_bool())? ap_const_lv8_1B: ap_const_lv8_0);
}

void MixColumns::thread_select_ln311_2_fu_283_p3() {
    select_ln311_2_fu_283_p3 = (!tmp_3_fu_275_p3.read()[0].is_01())? sc_lv<8>(): ((tmp_3_fu_275_p3.read()[0].to_bool())? ap_const_lv8_1B: ap_const_lv8_0);
}

void MixColumns::thread_select_ln311_3_fu_328_p3() {
    select_ln311_3_fu_328_p3 = (!tmp_4_fu_320_p3.read()[0].is_01())? sc_lv<8>(): ((tmp_4_fu_320_p3.read()[0].to_bool())? ap_const_lv8_1B: ap_const_lv8_0);
}

void MixColumns::thread_select_ln311_fu_192_p3() {
    select_ln311_fu_192_p3 = (!tmp_1_fu_184_p3.read()[0].is_01())? sc_lv<8>(): ((tmp_1_fu_184_p3.read()[0].to_bool())? ap_const_lv8_1B: ap_const_lv8_0);
}

void MixColumns::thread_shl_ln311_1_fu_223_p2() {
    shl_ln311_1_fu_223_p2 = (!ap_const_lv8_1.is_01())? sc_lv<8>(): Tm_1_fu_218_p2.read() << (unsigned short)ap_const_lv8_1.to_uint();
}

void MixColumns::thread_shl_ln311_2_fu_269_p2() {
    shl_ln311_2_fu_269_p2 = (!ap_const_lv8_1.is_01())? sc_lv<8>(): Tm_2_fu_263_p2.read() << (unsigned short)ap_const_lv8_1.to_uint();
}

void MixColumns::thread_shl_ln311_3_fu_314_p2() {
    shl_ln311_3_fu_314_p2 = (!ap_const_lv8_1.is_01())? sc_lv<8>(): Tm_3_fu_309_p2.read() << (unsigned short)ap_const_lv8_1.to_uint();
}

void MixColumns::thread_shl_ln311_fu_178_p2() {
    shl_ln311_fu_178_p2 = (!ap_const_lv8_1.is_01())? sc_lv<8>(): Tm_fu_162_p2.read() << (unsigned short)ap_const_lv8_1.to_uint();
}

void MixColumns::thread_state_address0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read())) {
        state_address0 = state_addr_13_reg_372.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read())) {
        state_address0 = state_addr_reg_362.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read())) {
        state_address0 =  (sc_lv<4>) (tmp_7_fu_139_p3.read());
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read())) {
        state_address0 =  (sc_lv<4>) (zext_ln318_fu_114_p1.read());
    } else {
        state_address0 = "XXXX";
    }
}

void MixColumns::thread_state_address1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read())) {
        state_address1 = state_addr_14_reg_377.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read())) {
        state_address1 = state_addr_12_reg_367.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read())) {
        state_address1 =  (sc_lv<4>) (tmp_8_fu_153_p3.read());
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read())) {
        state_address1 =  (sc_lv<4>) (tmp_6_fu_125_p3.read());
    } else {
        state_address1 = "XXXX";
    }
}

void MixColumns::thread_state_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read()))) {
        state_ce0 = ap_const_logic_1;
    } else {
        state_ce0 = ap_const_logic_0;
    }
}

void MixColumns::thread_state_ce1() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read()))) {
        state_ce1 = ap_const_logic_1;
    } else {
        state_ce1 = ap_const_logic_0;
    }
}

void MixColumns::thread_state_d0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read())) {
        state_d0 = xor_ln328_1_reg_396.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read())) {
        state_d0 = xor_ln322_1_fu_211_p2.read();
    } else {
        state_d0 =  (sc_lv<8>) ("XXXXXXXX");
    }
}

void MixColumns::thread_state_d1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read())) {
        state_d1 = xor_ln331_reg_401.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read())) {
        state_d1 = xor_ln325_1_fu_256_p2.read();
    } else {
        state_d1 =  (sc_lv<8>) ("XXXXXXXX");
    }
}

void MixColumns::thread_state_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read()))) {
        state_we0 = ap_const_logic_1;
    } else {
        state_we0 = ap_const_logic_0;
    }
}

void MixColumns::thread_state_we1() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read()))) {
        state_we1 = ap_const_logic_1;
    } else {
        state_we1 = ap_const_logic_0;
    }
}

void MixColumns::thread_tmp_1_fu_184_p3() {
    tmp_1_fu_184_p3 = Tm_fu_162_p2.read().range(7, 7);
}

void MixColumns::thread_tmp_2_fu_229_p3() {
    tmp_2_fu_229_p3 = Tm_1_fu_218_p2.read().range(7, 7);
}

void MixColumns::thread_tmp_3_fu_275_p3() {
    tmp_3_fu_275_p3 = Tm_2_fu_263_p2.read().range(7, 7);
}

void MixColumns::thread_tmp_4_fu_320_p3() {
    tmp_4_fu_320_p3 = Tm_3_fu_309_p2.read().range(7, 7);
}

void MixColumns::thread_tmp_6_fu_125_p3() {
    tmp_6_fu_125_p3 = esl_concat<59,5>(ap_const_lv59_0, or_ln319_fu_119_p2.read());
}

void MixColumns::thread_tmp_7_fu_139_p3() {
    tmp_7_fu_139_p3 = esl_concat<59,5>(ap_const_lv59_0, or_ln319_1_fu_134_p2.read());
}

void MixColumns::thread_tmp_8_fu_153_p3() {
    tmp_8_fu_153_p3 = esl_concat<59,5>(ap_const_lv59_0, or_ln319_2_fu_148_p2.read());
}

void MixColumns::thread_tmp_fu_106_p3() {
    tmp_fu_106_p3 = esl_concat<3,2>(i_0_reg_83.read(), ap_const_lv2_0);
}

void MixColumns::thread_xor_ln319_1_fu_166_p2() {
    xor_ln319_1_fu_166_p2 = (state_q0.read() ^ Tm_fu_162_p2.read());
}

void MixColumns::thread_xor_ln322_1_fu_211_p2() {
    xor_ln322_1_fu_211_p2 = (xor_ln322_2_fu_205_p2.read() ^ xor_ln322_fu_200_p2.read());
}

void MixColumns::thread_xor_ln322_2_fu_205_p2() {
    xor_ln322_2_fu_205_p2 = (shl_ln311_fu_178_p2.read() ^ Tmp_fu_172_p2.read());
}

void MixColumns::thread_xor_ln322_fu_200_p2() {
    xor_ln322_fu_200_p2 = (t_reg_382.read() ^ select_ln311_fu_192_p3.read());
}

void MixColumns::thread_xor_ln325_1_fu_256_p2() {
    xor_ln325_1_fu_256_p2 = (xor_ln325_2_fu_250_p2.read() ^ xor_ln325_fu_245_p2.read());
}

void MixColumns::thread_xor_ln325_2_fu_250_p2() {
    xor_ln325_2_fu_250_p2 = (shl_ln311_1_fu_223_p2.read() ^ Tmp_fu_172_p2.read());
}

void MixColumns::thread_xor_ln325_fu_245_p2() {
    xor_ln325_fu_245_p2 = (state_load_reg_389.read() ^ select_ln311_1_fu_237_p3.read());
}

void MixColumns::thread_xor_ln328_1_fu_303_p2() {
    xor_ln328_1_fu_303_p2 = (xor_ln328_2_fu_297_p2.read() ^ xor_ln328_fu_291_p2.read());
}

void MixColumns::thread_xor_ln328_2_fu_297_p2() {
    xor_ln328_2_fu_297_p2 = (shl_ln311_2_fu_269_p2.read() ^ Tmp_fu_172_p2.read());
}

void MixColumns::thread_xor_ln328_fu_291_p2() {
    xor_ln328_fu_291_p2 = (state_q0.read() ^ select_ln311_2_fu_283_p3.read());
}

void MixColumns::thread_xor_ln331_1_fu_336_p2() {
    xor_ln331_1_fu_336_p2 = (shl_ln311_3_fu_314_p2.read() ^ xor_ln319_1_fu_166_p2.read());
}

void MixColumns::thread_xor_ln331_fu_342_p2() {
    xor_ln331_fu_342_p2 = (xor_ln331_1_fu_336_p2.read() ^ select_ln311_3_fu_328_p3.read());
}

void MixColumns::thread_zext_ln318_fu_114_p1() {
    zext_ln318_fu_114_p1 = esl_zext<64,5>(tmp_fu_106_p3.read());
}

void MixColumns::thread_ap_NS_fsm() {
    switch (ap_CS_fsm.read().to_uint64()) {
        case 1 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
                ap_NS_fsm = ap_ST_fsm_state2;
            } else {
                ap_NS_fsm = ap_ST_fsm_state1;
            }
            break;
        case 2 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && esl_seteq<1,1,1>(icmp_ln317_fu_94_p2.read(), ap_const_lv1_1))) {
                ap_NS_fsm = ap_ST_fsm_state1;
            } else {
                ap_NS_fsm = ap_ST_fsm_state3;
            }
            break;
        case 4 : 
            ap_NS_fsm = ap_ST_fsm_state4;
            break;
        case 8 : 
            ap_NS_fsm = ap_ST_fsm_state5;
            break;
        case 16 : 
            ap_NS_fsm = ap_ST_fsm_state2;
            break;
        default : 
            ap_NS_fsm =  (sc_lv<5>) ("XXXXX");
            break;
    }
}

}

