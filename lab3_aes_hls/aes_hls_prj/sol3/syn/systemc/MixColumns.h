// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _MixColumns_HH_
#define _MixColumns_HH_

#include "systemc.h"
#include "AESL_pkg.h"


namespace ap_rtl {

struct MixColumns : public sc_module {
    // Port declarations 16
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst;
    sc_in< sc_logic > ap_start;
    sc_out< sc_logic > ap_done;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;
    sc_out< sc_lv<4> > state_address0;
    sc_out< sc_logic > state_ce0;
    sc_out< sc_logic > state_we0;
    sc_out< sc_lv<8> > state_d0;
    sc_in< sc_lv<8> > state_q0;
    sc_out< sc_lv<4> > state_address1;
    sc_out< sc_logic > state_ce1;
    sc_out< sc_logic > state_we1;
    sc_out< sc_lv<8> > state_d1;
    sc_in< sc_lv<8> > state_q1;


    // Module declarations
    MixColumns(sc_module_name name);
    SC_HAS_PROCESS(MixColumns);

    ~MixColumns();

    sc_trace_file* mVcdFile;

    sc_signal< sc_lv<5> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_lv<3> > i_fu_100_p2;
    sc_signal< sc_lv<3> > i_reg_351;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_lv<5> > tmp_fu_106_p3;
    sc_signal< sc_lv<5> > tmp_reg_356;
    sc_signal< sc_lv<1> > icmp_ln317_fu_94_p2;
    sc_signal< sc_lv<4> > state_addr_reg_362;
    sc_signal< sc_lv<4> > state_addr_12_reg_367;
    sc_signal< sc_lv<4> > state_addr_13_reg_372;
    sc_signal< sc_logic > ap_CS_fsm_state3;
    sc_signal< sc_lv<4> > state_addr_14_reg_377;
    sc_signal< sc_lv<8> > t_reg_382;
    sc_signal< sc_lv<8> > state_load_reg_389;
    sc_signal< sc_lv<8> > xor_ln328_1_fu_303_p2;
    sc_signal< sc_lv<8> > xor_ln328_1_reg_396;
    sc_signal< sc_logic > ap_CS_fsm_state4;
    sc_signal< sc_lv<8> > xor_ln331_fu_342_p2;
    sc_signal< sc_lv<8> > xor_ln331_reg_401;
    sc_signal< sc_lv<3> > i_0_reg_83;
    sc_signal< sc_logic > ap_CS_fsm_state5;
    sc_signal< sc_lv<64> > zext_ln318_fu_114_p1;
    sc_signal< sc_lv<64> > tmp_6_fu_125_p3;
    sc_signal< sc_lv<64> > tmp_7_fu_139_p3;
    sc_signal< sc_lv<64> > tmp_8_fu_153_p3;
    sc_signal< sc_lv<8> > xor_ln322_1_fu_211_p2;
    sc_signal< sc_lv<8> > xor_ln325_1_fu_256_p2;
    sc_signal< sc_lv<5> > or_ln319_fu_119_p2;
    sc_signal< sc_lv<5> > or_ln319_1_fu_134_p2;
    sc_signal< sc_lv<5> > or_ln319_2_fu_148_p2;
    sc_signal< sc_lv<8> > Tm_fu_162_p2;
    sc_signal< sc_lv<8> > xor_ln319_1_fu_166_p2;
    sc_signal< sc_lv<1> > tmp_1_fu_184_p3;
    sc_signal< sc_lv<8> > select_ln311_fu_192_p3;
    sc_signal< sc_lv<8> > shl_ln311_fu_178_p2;
    sc_signal< sc_lv<8> > Tmp_fu_172_p2;
    sc_signal< sc_lv<8> > xor_ln322_2_fu_205_p2;
    sc_signal< sc_lv<8> > xor_ln322_fu_200_p2;
    sc_signal< sc_lv<8> > Tm_1_fu_218_p2;
    sc_signal< sc_lv<1> > tmp_2_fu_229_p3;
    sc_signal< sc_lv<8> > select_ln311_1_fu_237_p3;
    sc_signal< sc_lv<8> > shl_ln311_1_fu_223_p2;
    sc_signal< sc_lv<8> > xor_ln325_2_fu_250_p2;
    sc_signal< sc_lv<8> > xor_ln325_fu_245_p2;
    sc_signal< sc_lv<8> > Tm_2_fu_263_p2;
    sc_signal< sc_lv<1> > tmp_3_fu_275_p3;
    sc_signal< sc_lv<8> > select_ln311_2_fu_283_p3;
    sc_signal< sc_lv<8> > shl_ln311_2_fu_269_p2;
    sc_signal< sc_lv<8> > xor_ln328_2_fu_297_p2;
    sc_signal< sc_lv<8> > xor_ln328_fu_291_p2;
    sc_signal< sc_lv<8> > Tm_3_fu_309_p2;
    sc_signal< sc_lv<1> > tmp_4_fu_320_p3;
    sc_signal< sc_lv<8> > shl_ln311_3_fu_314_p2;
    sc_signal< sc_lv<8> > xor_ln331_1_fu_336_p2;
    sc_signal< sc_lv<8> > select_ln311_3_fu_328_p3;
    sc_signal< sc_lv<5> > ap_NS_fsm;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<5> ap_ST_fsm_state1;
    static const sc_lv<5> ap_ST_fsm_state2;
    static const sc_lv<5> ap_ST_fsm_state3;
    static const sc_lv<5> ap_ST_fsm_state4;
    static const sc_lv<5> ap_ST_fsm_state5;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<32> ap_const_lv32_1;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<32> ap_const_lv32_2;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<3> ap_const_lv3_0;
    static const sc_lv<32> ap_const_lv32_4;
    static const sc_lv<3> ap_const_lv3_4;
    static const sc_lv<3> ap_const_lv3_1;
    static const sc_lv<2> ap_const_lv2_0;
    static const sc_lv<5> ap_const_lv5_1;
    static const sc_lv<59> ap_const_lv59_0;
    static const sc_lv<5> ap_const_lv5_2;
    static const sc_lv<5> ap_const_lv5_3;
    static const sc_lv<8> ap_const_lv8_1;
    static const sc_lv<32> ap_const_lv32_7;
    static const sc_lv<8> ap_const_lv8_1B;
    static const sc_lv<8> ap_const_lv8_0;
    static const sc_lv<1> ap_const_lv1_1;
    static const bool ap_const_boolean_1;
    // Thread declarations
    void thread_ap_clk_no_reset_();
    void thread_Tm_1_fu_218_p2();
    void thread_Tm_2_fu_263_p2();
    void thread_Tm_3_fu_309_p2();
    void thread_Tm_fu_162_p2();
    void thread_Tmp_fu_172_p2();
    void thread_ap_CS_fsm_state1();
    void thread_ap_CS_fsm_state2();
    void thread_ap_CS_fsm_state3();
    void thread_ap_CS_fsm_state4();
    void thread_ap_CS_fsm_state5();
    void thread_ap_done();
    void thread_ap_idle();
    void thread_ap_ready();
    void thread_i_fu_100_p2();
    void thread_icmp_ln317_fu_94_p2();
    void thread_or_ln319_1_fu_134_p2();
    void thread_or_ln319_2_fu_148_p2();
    void thread_or_ln319_fu_119_p2();
    void thread_select_ln311_1_fu_237_p3();
    void thread_select_ln311_2_fu_283_p3();
    void thread_select_ln311_3_fu_328_p3();
    void thread_select_ln311_fu_192_p3();
    void thread_shl_ln311_1_fu_223_p2();
    void thread_shl_ln311_2_fu_269_p2();
    void thread_shl_ln311_3_fu_314_p2();
    void thread_shl_ln311_fu_178_p2();
    void thread_state_address0();
    void thread_state_address1();
    void thread_state_ce0();
    void thread_state_ce1();
    void thread_state_d0();
    void thread_state_d1();
    void thread_state_we0();
    void thread_state_we1();
    void thread_tmp_1_fu_184_p3();
    void thread_tmp_2_fu_229_p3();
    void thread_tmp_3_fu_275_p3();
    void thread_tmp_4_fu_320_p3();
    void thread_tmp_6_fu_125_p3();
    void thread_tmp_7_fu_139_p3();
    void thread_tmp_8_fu_153_p3();
    void thread_tmp_fu_106_p3();
    void thread_xor_ln319_1_fu_166_p2();
    void thread_xor_ln322_1_fu_211_p2();
    void thread_xor_ln322_2_fu_205_p2();
    void thread_xor_ln322_fu_200_p2();
    void thread_xor_ln325_1_fu_256_p2();
    void thread_xor_ln325_2_fu_250_p2();
    void thread_xor_ln325_fu_245_p2();
    void thread_xor_ln328_1_fu_303_p2();
    void thread_xor_ln328_2_fu_297_p2();
    void thread_xor_ln328_fu_291_p2();
    void thread_xor_ln331_1_fu_336_p2();
    void thread_xor_ln331_fu_342_p2();
    void thread_zext_ln318_fu_114_p1();
    void thread_ap_NS_fsm();
};

}

using namespace ap_rtl;

#endif
