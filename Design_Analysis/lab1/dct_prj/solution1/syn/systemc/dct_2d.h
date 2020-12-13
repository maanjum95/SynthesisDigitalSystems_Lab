// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _dct_2d_HH_
#define _dct_2d_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "dct_1d2.h"
#include "dct_2d_row_outbuf.h"

namespace ap_rtl {

struct dct_2d : public sc_module {
    // Port declarations 13
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst;
    sc_in< sc_logic > ap_start;
    sc_out< sc_logic > ap_done;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;
    sc_out< sc_lv<6> > in_block_address0;
    sc_out< sc_logic > in_block_ce0;
    sc_in< sc_lv<16> > in_block_q0;
    sc_out< sc_lv<6> > out_block_address0;
    sc_out< sc_logic > out_block_ce0;
    sc_out< sc_logic > out_block_we0;
    sc_out< sc_lv<16> > out_block_d0;


    // Module declarations
    dct_2d(sc_module_name name);
    SC_HAS_PROCESS(dct_2d);

    ~dct_2d();

    sc_trace_file* mVcdFile;

    dct_2d_row_outbuf* row_outbuf_U;
    dct_2d_row_outbuf* col_outbuf_U;
    dct_2d_row_outbuf* col_inbuf_U;
    dct_1d2* grp_dct_1d2_fu_175;
    sc_signal< sc_lv<11> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_lv<4> > i_fu_196_p2;
    sc_signal< sc_lv<4> > i_reg_367;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_lv<4> > j_fu_208_p2;
    sc_signal< sc_lv<4> > j_reg_375;
    sc_signal< sc_logic > ap_CS_fsm_state4;
    sc_signal< sc_lv<8> > zext_ln82_fu_214_p1;
    sc_signal< sc_lv<8> > zext_ln82_reg_380;
    sc_signal< sc_lv<1> > icmp_ln79_fu_202_p2;
    sc_signal< sc_lv<8> > zext_ln81_fu_226_p1;
    sc_signal< sc_lv<8> > zext_ln81_reg_385;
    sc_signal< sc_lv<4> > i_5_fu_236_p2;
    sc_signal< sc_lv<4> > i_5_reg_393;
    sc_signal< sc_logic > ap_CS_fsm_state5;
    sc_signal< sc_lv<1> > icmp_ln81_fu_230_p2;
    sc_signal< sc_lv<8> > add_ln82_1_fu_268_p2;
    sc_signal< sc_lv<8> > add_ln82_1_reg_403;
    sc_signal< sc_lv<4> > i_4_fu_283_p2;
    sc_signal< sc_lv<4> > i_4_reg_411;
    sc_signal< sc_logic > ap_CS_fsm_state7;
    sc_signal< sc_lv<4> > j_2_fu_295_p2;
    sc_signal< sc_lv<4> > j_2_reg_419;
    sc_signal< sc_logic > ap_CS_fsm_state9;
    sc_signal< sc_lv<8> > zext_ln93_fu_301_p1;
    sc_signal< sc_lv<8> > zext_ln93_reg_424;
    sc_signal< sc_lv<1> > icmp_ln90_fu_289_p2;
    sc_signal< sc_lv<8> > zext_ln92_fu_313_p1;
    sc_signal< sc_lv<8> > zext_ln92_reg_429;
    sc_signal< sc_lv<4> > i_6_fu_323_p2;
    sc_signal< sc_lv<4> > i_6_reg_437;
    sc_signal< sc_logic > ap_CS_fsm_state10;
    sc_signal< sc_lv<8> > add_ln93_fu_333_p2;
    sc_signal< sc_lv<8> > add_ln93_reg_442;
    sc_signal< sc_lv<1> > icmp_ln92_fu_317_p2;
    sc_signal< sc_lv<6> > row_outbuf_address0;
    sc_signal< sc_logic > row_outbuf_ce0;
    sc_signal< sc_logic > row_outbuf_we0;
    sc_signal< sc_lv<16> > row_outbuf_q0;
    sc_signal< sc_lv<6> > col_outbuf_address0;
    sc_signal< sc_logic > col_outbuf_ce0;
    sc_signal< sc_logic > col_outbuf_we0;
    sc_signal< sc_lv<16> > col_outbuf_q0;
    sc_signal< sc_lv<6> > col_inbuf_address0;
    sc_signal< sc_logic > col_inbuf_ce0;
    sc_signal< sc_logic > col_inbuf_we0;
    sc_signal< sc_lv<16> > col_inbuf_q0;
    sc_signal< sc_logic > grp_dct_1d2_fu_175_ap_start;
    sc_signal< sc_logic > grp_dct_1d2_fu_175_ap_done;
    sc_signal< sc_logic > grp_dct_1d2_fu_175_ap_idle;
    sc_signal< sc_logic > grp_dct_1d2_fu_175_ap_ready;
    sc_signal< sc_lv<6> > grp_dct_1d2_fu_175_src_address0;
    sc_signal< sc_logic > grp_dct_1d2_fu_175_src_ce0;
    sc_signal< sc_lv<16> > grp_dct_1d2_fu_175_src_q0;
    sc_signal< sc_lv<4> > grp_dct_1d2_fu_175_src_offset;
    sc_signal< sc_lv<6> > grp_dct_1d2_fu_175_dst_address0;
    sc_signal< sc_logic > grp_dct_1d2_fu_175_dst_ce0;
    sc_signal< sc_logic > grp_dct_1d2_fu_175_dst_we0;
    sc_signal< sc_lv<16> > grp_dct_1d2_fu_175_dst_d0;
    sc_signal< sc_lv<4> > grp_dct_1d2_fu_175_dst_offset;
    sc_signal< sc_lv<4> > i_0_reg_107;
    sc_signal< sc_logic > ap_CS_fsm_state3;
    sc_signal< sc_lv<4> > j_0_reg_119;
    sc_signal< sc_lv<1> > icmp_ln74_fu_190_p2;
    sc_signal< sc_lv<4> > i_1_reg_130;
    sc_signal< sc_logic > ap_CS_fsm_state6;
    sc_signal< sc_lv<4> > i_2_reg_141;
    sc_signal< sc_logic > ap_CS_fsm_state8;
    sc_signal< sc_lv<4> > j_1_reg_153;
    sc_signal< sc_lv<1> > icmp_ln85_fu_277_p2;
    sc_signal< sc_lv<4> > i_3_reg_164;
    sc_signal< sc_logic > ap_CS_fsm_state11;
    sc_signal< sc_logic > grp_dct_1d2_fu_175_ap_start_reg;
    sc_signal< sc_lv<64> > zext_ln82_3_fu_263_p1;
    sc_signal< sc_lv<64> > zext_ln82_4_fu_273_p1;
    sc_signal< sc_lv<64> > zext_ln93_4_fu_355_p1;
    sc_signal< sc_lv<64> > zext_ln93_2_fu_360_p1;
    sc_signal< sc_lv<7> > tmp_2_fu_218_p3;
    sc_signal< sc_lv<7> > tmp_3_fu_246_p3;
    sc_signal< sc_lv<8> > zext_ln82_2_fu_254_p1;
    sc_signal< sc_lv<8> > add_ln82_fu_258_p2;
    sc_signal< sc_lv<8> > zext_ln82_1_fu_242_p1;
    sc_signal< sc_lv<7> > tmp_4_fu_305_p3;
    sc_signal< sc_lv<8> > zext_ln93_1_fu_329_p1;
    sc_signal< sc_lv<7> > tmp_5_fu_338_p3;
    sc_signal< sc_lv<8> > zext_ln93_3_fu_346_p1;
    sc_signal< sc_lv<8> > add_ln93_1_fu_350_p2;
    sc_signal< sc_lv<11> > ap_NS_fsm;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<11> ap_ST_fsm_state1;
    static const sc_lv<11> ap_ST_fsm_state2;
    static const sc_lv<11> ap_ST_fsm_state3;
    static const sc_lv<11> ap_ST_fsm_state4;
    static const sc_lv<11> ap_ST_fsm_state5;
    static const sc_lv<11> ap_ST_fsm_state6;
    static const sc_lv<11> ap_ST_fsm_state7;
    static const sc_lv<11> ap_ST_fsm_state8;
    static const sc_lv<11> ap_ST_fsm_state9;
    static const sc_lv<11> ap_ST_fsm_state10;
    static const sc_lv<11> ap_ST_fsm_state11;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<32> ap_const_lv32_1;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<32> ap_const_lv32_4;
    static const sc_lv<32> ap_const_lv32_6;
    static const sc_lv<32> ap_const_lv32_8;
    static const sc_lv<32> ap_const_lv32_9;
    static const sc_lv<4> ap_const_lv4_0;
    static const sc_lv<32> ap_const_lv32_2;
    static const sc_lv<1> ap_const_lv1_1;
    static const sc_lv<32> ap_const_lv32_5;
    static const sc_lv<32> ap_const_lv32_7;
    static const sc_lv<32> ap_const_lv32_A;
    static const sc_lv<4> ap_const_lv4_8;
    static const sc_lv<4> ap_const_lv4_1;
    static const sc_lv<3> ap_const_lv3_0;
    static const bool ap_const_boolean_1;
    // Thread declarations
    void thread_ap_clk_no_reset_();
    void thread_add_ln82_1_fu_268_p2();
    void thread_add_ln82_fu_258_p2();
    void thread_add_ln93_1_fu_350_p2();
    void thread_add_ln93_fu_333_p2();
    void thread_ap_CS_fsm_state1();
    void thread_ap_CS_fsm_state10();
    void thread_ap_CS_fsm_state11();
    void thread_ap_CS_fsm_state2();
    void thread_ap_CS_fsm_state3();
    void thread_ap_CS_fsm_state4();
    void thread_ap_CS_fsm_state5();
    void thread_ap_CS_fsm_state6();
    void thread_ap_CS_fsm_state7();
    void thread_ap_CS_fsm_state8();
    void thread_ap_CS_fsm_state9();
    void thread_ap_done();
    void thread_ap_idle();
    void thread_ap_ready();
    void thread_col_inbuf_address0();
    void thread_col_inbuf_ce0();
    void thread_col_inbuf_we0();
    void thread_col_outbuf_address0();
    void thread_col_outbuf_ce0();
    void thread_col_outbuf_we0();
    void thread_grp_dct_1d2_fu_175_ap_start();
    void thread_grp_dct_1d2_fu_175_dst_offset();
    void thread_grp_dct_1d2_fu_175_src_offset();
    void thread_grp_dct_1d2_fu_175_src_q0();
    void thread_i_4_fu_283_p2();
    void thread_i_5_fu_236_p2();
    void thread_i_6_fu_323_p2();
    void thread_i_fu_196_p2();
    void thread_icmp_ln74_fu_190_p2();
    void thread_icmp_ln79_fu_202_p2();
    void thread_icmp_ln81_fu_230_p2();
    void thread_icmp_ln85_fu_277_p2();
    void thread_icmp_ln90_fu_289_p2();
    void thread_icmp_ln92_fu_317_p2();
    void thread_in_block_address0();
    void thread_in_block_ce0();
    void thread_j_2_fu_295_p2();
    void thread_j_fu_208_p2();
    void thread_out_block_address0();
    void thread_out_block_ce0();
    void thread_out_block_d0();
    void thread_out_block_we0();
    void thread_row_outbuf_address0();
    void thread_row_outbuf_ce0();
    void thread_row_outbuf_we0();
    void thread_tmp_2_fu_218_p3();
    void thread_tmp_3_fu_246_p3();
    void thread_tmp_4_fu_305_p3();
    void thread_tmp_5_fu_338_p3();
    void thread_zext_ln81_fu_226_p1();
    void thread_zext_ln82_1_fu_242_p1();
    void thread_zext_ln82_2_fu_254_p1();
    void thread_zext_ln82_3_fu_263_p1();
    void thread_zext_ln82_4_fu_273_p1();
    void thread_zext_ln82_fu_214_p1();
    void thread_zext_ln92_fu_313_p1();
    void thread_zext_ln93_1_fu_329_p1();
    void thread_zext_ln93_2_fu_360_p1();
    void thread_zext_ln93_3_fu_346_p1();
    void thread_zext_ln93_4_fu_355_p1();
    void thread_zext_ln93_fu_301_p1();
    void thread_ap_NS_fsm();
};

}

using namespace ap_rtl;

#endif