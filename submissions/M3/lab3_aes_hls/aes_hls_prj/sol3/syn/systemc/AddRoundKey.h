// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _AddRoundKey_HH_
#define _AddRoundKey_HH_

#include "systemc.h"
#include "AESL_pkg.h"


namespace ap_rtl {

struct AddRoundKey : public sc_module {
    // Port declarations 23
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst;
    sc_in< sc_logic > ap_start;
    sc_out< sc_logic > ap_done;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;
    sc_in< sc_lv<5> > round;
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
    sc_out< sc_lv<8> > RoundKey_address0;
    sc_out< sc_logic > RoundKey_ce0;
    sc_in< sc_lv<8> > RoundKey_q0;
    sc_out< sc_lv<8> > RoundKey_address1;
    sc_out< sc_logic > RoundKey_ce1;
    sc_in< sc_lv<8> > RoundKey_q1;


    // Module declarations
    AddRoundKey(sc_module_name name);
    SC_HAS_PROCESS(AddRoundKey);

    ~AddRoundKey();

    sc_trace_file* mVcdFile;

    sc_signal< sc_lv<16> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_lv<8> > reg_370;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_logic > ap_CS_fsm_state9;
    sc_signal< sc_lv<8> > reg_374;
    sc_signal< sc_lv<4> > state_addr_reg_632;
    sc_signal< sc_lv<4> > state_addr_16_reg_637;
    sc_signal< sc_lv<4> > state_addr_17_reg_642;
    sc_signal< sc_lv<4> > state_addr_18_reg_647;
    sc_signal< sc_lv<4> > state_addr_19_reg_652;
    sc_signal< sc_logic > ap_CS_fsm_state3;
    sc_signal< sc_lv<4> > state_addr_20_reg_657;
    sc_signal< sc_lv<8> > state_load_22_reg_662;
    sc_signal< sc_lv<8> > state_load_23_reg_667;
    sc_signal< sc_lv<4> > state_addr_21_reg_672;
    sc_signal< sc_logic > ap_CS_fsm_state4;
    sc_signal< sc_lv<4> > state_addr_22_reg_677;
    sc_signal< sc_lv<8> > state_load_24_reg_682;
    sc_signal< sc_lv<8> > state_load_25_reg_687;
    sc_signal< sc_lv<4> > state_addr_23_reg_692;
    sc_signal< sc_logic > ap_CS_fsm_state5;
    sc_signal< sc_lv<4> > state_addr_24_reg_697;
    sc_signal< sc_lv<8> > state_load_26_reg_702;
    sc_signal< sc_lv<8> > state_load_27_reg_707;
    sc_signal< sc_lv<4> > state_addr_25_reg_712;
    sc_signal< sc_logic > ap_CS_fsm_state6;
    sc_signal< sc_lv<4> > state_addr_26_reg_717;
    sc_signal< sc_lv<8> > state_load_28_reg_722;
    sc_signal< sc_lv<8> > state_load_29_reg_727;
    sc_signal< sc_lv<4> > state_addr_27_reg_732;
    sc_signal< sc_logic > ap_CS_fsm_state7;
    sc_signal< sc_lv<4> > state_addr_28_reg_737;
    sc_signal< sc_lv<8> > state_load_30_reg_742;
    sc_signal< sc_lv<8> > state_load_31_reg_747;
    sc_signal< sc_lv<4> > state_addr_29_reg_752;
    sc_signal< sc_logic > ap_CS_fsm_state8;
    sc_signal< sc_lv<4> > state_addr_30_reg_757;
    sc_signal< sc_lv<8> > shl_ln_fu_396_p3;
    sc_signal< sc_lv<8> > shl_ln_reg_762;
    sc_signal< sc_lv<8> > state_load_32_reg_790;
    sc_signal< sc_lv<8> > state_load_33_reg_795;
    sc_signal< sc_logic > ap_CS_fsm_state10;
    sc_signal< sc_logic > ap_CS_fsm_state11;
    sc_signal< sc_logic > ap_CS_fsm_state12;
    sc_signal< sc_logic > ap_CS_fsm_state13;
    sc_signal< sc_logic > ap_CS_fsm_state14;
    sc_signal< sc_logic > ap_CS_fsm_state15;
    sc_signal< sc_lv<64> > zext_ln265_fu_404_p1;
    sc_signal< sc_lv<64> > zext_ln265_1_fu_415_p1;
    sc_signal< sc_lv<64> > zext_ln265_2_fu_425_p1;
    sc_signal< sc_lv<64> > zext_ln265_3_fu_435_p1;
    sc_signal< sc_lv<64> > zext_ln265_4_fu_457_p1;
    sc_signal< sc_lv<64> > zext_ln265_5_fu_467_p1;
    sc_signal< sc_lv<64> > zext_ln265_6_fu_489_p1;
    sc_signal< sc_lv<64> > zext_ln265_7_fu_499_p1;
    sc_signal< sc_lv<64> > zext_ln265_8_fu_521_p1;
    sc_signal< sc_lv<64> > zext_ln265_9_fu_531_p1;
    sc_signal< sc_lv<64> > zext_ln265_10_fu_553_p1;
    sc_signal< sc_lv<64> > zext_ln265_11_fu_563_p1;
    sc_signal< sc_lv<64> > zext_ln265_12_fu_585_p1;
    sc_signal< sc_lv<64> > zext_ln265_13_fu_595_p1;
    sc_signal< sc_lv<64> > zext_ln265_14_fu_617_p1;
    sc_signal< sc_lv<64> > zext_ln265_15_fu_627_p1;
    sc_signal< sc_lv<8> > grp_fu_378_p2;
    sc_signal< sc_lv<8> > grp_fu_385_p2;
    sc_signal< sc_lv<8> > xor_ln265_2_fu_440_p2;
    sc_signal< sc_lv<8> > xor_ln265_3_fu_446_p2;
    sc_signal< sc_lv<8> > xor_ln265_4_fu_472_p2;
    sc_signal< sc_lv<8> > xor_ln265_5_fu_478_p2;
    sc_signal< sc_lv<8> > xor_ln265_6_fu_504_p2;
    sc_signal< sc_lv<8> > xor_ln265_7_fu_510_p2;
    sc_signal< sc_lv<8> > xor_ln265_8_fu_536_p2;
    sc_signal< sc_lv<8> > xor_ln265_9_fu_542_p2;
    sc_signal< sc_lv<8> > xor_ln265_10_fu_568_p2;
    sc_signal< sc_lv<8> > xor_ln265_11_fu_574_p2;
    sc_signal< sc_lv<8> > xor_ln265_12_fu_600_p2;
    sc_signal< sc_lv<8> > xor_ln265_13_fu_606_p2;
    sc_signal< sc_logic > ap_CS_fsm_state16;
    sc_signal< sc_lv<4> > trunc_ln265_fu_392_p1;
    sc_signal< sc_lv<8> > or_ln265_fu_409_p2;
    sc_signal< sc_lv<8> > or_ln265_1_fu_420_p2;
    sc_signal< sc_lv<8> > or_ln265_2_fu_430_p2;
    sc_signal< sc_lv<8> > or_ln265_3_fu_452_p2;
    sc_signal< sc_lv<8> > or_ln265_4_fu_462_p2;
    sc_signal< sc_lv<8> > or_ln265_5_fu_484_p2;
    sc_signal< sc_lv<8> > or_ln265_6_fu_494_p2;
    sc_signal< sc_lv<8> > or_ln265_7_fu_516_p2;
    sc_signal< sc_lv<8> > or_ln265_8_fu_526_p2;
    sc_signal< sc_lv<8> > or_ln265_9_fu_548_p2;
    sc_signal< sc_lv<8> > or_ln265_10_fu_558_p2;
    sc_signal< sc_lv<8> > or_ln265_11_fu_580_p2;
    sc_signal< sc_lv<8> > or_ln265_12_fu_590_p2;
    sc_signal< sc_lv<8> > or_ln265_13_fu_612_p2;
    sc_signal< sc_lv<8> > or_ln265_14_fu_622_p2;
    sc_signal< sc_lv<16> > ap_NS_fsm;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<16> ap_ST_fsm_state1;
    static const sc_lv<16> ap_ST_fsm_state2;
    static const sc_lv<16> ap_ST_fsm_state3;
    static const sc_lv<16> ap_ST_fsm_state4;
    static const sc_lv<16> ap_ST_fsm_state5;
    static const sc_lv<16> ap_ST_fsm_state6;
    static const sc_lv<16> ap_ST_fsm_state7;
    static const sc_lv<16> ap_ST_fsm_state8;
    static const sc_lv<16> ap_ST_fsm_state9;
    static const sc_lv<16> ap_ST_fsm_state10;
    static const sc_lv<16> ap_ST_fsm_state11;
    static const sc_lv<16> ap_ST_fsm_state12;
    static const sc_lv<16> ap_ST_fsm_state13;
    static const sc_lv<16> ap_ST_fsm_state14;
    static const sc_lv<16> ap_ST_fsm_state15;
    static const sc_lv<16> ap_ST_fsm_state16;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<32> ap_const_lv32_1;
    static const sc_lv<32> ap_const_lv32_8;
    static const sc_lv<32> ap_const_lv32_2;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<32> ap_const_lv32_4;
    static const sc_lv<32> ap_const_lv32_5;
    static const sc_lv<32> ap_const_lv32_6;
    static const sc_lv<32> ap_const_lv32_7;
    static const sc_lv<32> ap_const_lv32_9;
    static const sc_lv<32> ap_const_lv32_A;
    static const sc_lv<32> ap_const_lv32_B;
    static const sc_lv<32> ap_const_lv32_C;
    static const sc_lv<32> ap_const_lv32_D;
    static const sc_lv<32> ap_const_lv32_E;
    static const sc_lv<64> ap_const_lv64_0;
    static const sc_lv<64> ap_const_lv64_1;
    static const sc_lv<64> ap_const_lv64_2;
    static const sc_lv<64> ap_const_lv64_3;
    static const sc_lv<64> ap_const_lv64_4;
    static const sc_lv<64> ap_const_lv64_5;
    static const sc_lv<64> ap_const_lv64_6;
    static const sc_lv<64> ap_const_lv64_7;
    static const sc_lv<64> ap_const_lv64_8;
    static const sc_lv<64> ap_const_lv64_9;
    static const sc_lv<64> ap_const_lv64_A;
    static const sc_lv<64> ap_const_lv64_B;
    static const sc_lv<64> ap_const_lv64_C;
    static const sc_lv<64> ap_const_lv64_D;
    static const sc_lv<64> ap_const_lv64_E;
    static const sc_lv<64> ap_const_lv64_F;
    static const sc_lv<32> ap_const_lv32_F;
    static const sc_lv<4> ap_const_lv4_0;
    static const sc_lv<8> ap_const_lv8_1;
    static const sc_lv<8> ap_const_lv8_2;
    static const sc_lv<8> ap_const_lv8_3;
    static const sc_lv<8> ap_const_lv8_4;
    static const sc_lv<8> ap_const_lv8_5;
    static const sc_lv<8> ap_const_lv8_6;
    static const sc_lv<8> ap_const_lv8_7;
    static const sc_lv<8> ap_const_lv8_8;
    static const sc_lv<8> ap_const_lv8_9;
    static const sc_lv<8> ap_const_lv8_A;
    static const sc_lv<8> ap_const_lv8_B;
    static const sc_lv<8> ap_const_lv8_C;
    static const sc_lv<8> ap_const_lv8_D;
    static const sc_lv<8> ap_const_lv8_E;
    static const sc_lv<8> ap_const_lv8_F;
    static const bool ap_const_boolean_1;
    // Thread declarations
    void thread_ap_clk_no_reset_();
    void thread_RoundKey_address0();
    void thread_RoundKey_address1();
    void thread_RoundKey_ce0();
    void thread_RoundKey_ce1();
    void thread_ap_CS_fsm_state1();
    void thread_ap_CS_fsm_state10();
    void thread_ap_CS_fsm_state11();
    void thread_ap_CS_fsm_state12();
    void thread_ap_CS_fsm_state13();
    void thread_ap_CS_fsm_state14();
    void thread_ap_CS_fsm_state15();
    void thread_ap_CS_fsm_state16();
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
    void thread_grp_fu_378_p2();
    void thread_grp_fu_385_p2();
    void thread_or_ln265_10_fu_558_p2();
    void thread_or_ln265_11_fu_580_p2();
    void thread_or_ln265_12_fu_590_p2();
    void thread_or_ln265_13_fu_612_p2();
    void thread_or_ln265_14_fu_622_p2();
    void thread_or_ln265_1_fu_420_p2();
    void thread_or_ln265_2_fu_430_p2();
    void thread_or_ln265_3_fu_452_p2();
    void thread_or_ln265_4_fu_462_p2();
    void thread_or_ln265_5_fu_484_p2();
    void thread_or_ln265_6_fu_494_p2();
    void thread_or_ln265_7_fu_516_p2();
    void thread_or_ln265_8_fu_526_p2();
    void thread_or_ln265_9_fu_548_p2();
    void thread_or_ln265_fu_409_p2();
    void thread_shl_ln_fu_396_p3();
    void thread_state_addr_16_reg_637();
    void thread_state_addr_17_reg_642();
    void thread_state_addr_18_reg_647();
    void thread_state_addr_19_reg_652();
    void thread_state_addr_20_reg_657();
    void thread_state_addr_21_reg_672();
    void thread_state_addr_22_reg_677();
    void thread_state_addr_23_reg_692();
    void thread_state_addr_24_reg_697();
    void thread_state_addr_25_reg_712();
    void thread_state_addr_26_reg_717();
    void thread_state_addr_27_reg_732();
    void thread_state_addr_28_reg_737();
    void thread_state_addr_29_reg_752();
    void thread_state_addr_30_reg_757();
    void thread_state_addr_reg_632();
    void thread_state_address0();
    void thread_state_address1();
    void thread_state_ce0();
    void thread_state_ce1();
    void thread_state_d0();
    void thread_state_d1();
    void thread_state_we0();
    void thread_state_we1();
    void thread_trunc_ln265_fu_392_p1();
    void thread_xor_ln265_10_fu_568_p2();
    void thread_xor_ln265_11_fu_574_p2();
    void thread_xor_ln265_12_fu_600_p2();
    void thread_xor_ln265_13_fu_606_p2();
    void thread_xor_ln265_2_fu_440_p2();
    void thread_xor_ln265_3_fu_446_p2();
    void thread_xor_ln265_4_fu_472_p2();
    void thread_xor_ln265_5_fu_478_p2();
    void thread_xor_ln265_6_fu_504_p2();
    void thread_xor_ln265_7_fu_510_p2();
    void thread_xor_ln265_8_fu_536_p2();
    void thread_xor_ln265_9_fu_542_p2();
    void thread_zext_ln265_10_fu_553_p1();
    void thread_zext_ln265_11_fu_563_p1();
    void thread_zext_ln265_12_fu_585_p1();
    void thread_zext_ln265_13_fu_595_p1();
    void thread_zext_ln265_14_fu_617_p1();
    void thread_zext_ln265_15_fu_627_p1();
    void thread_zext_ln265_1_fu_415_p1();
    void thread_zext_ln265_2_fu_425_p1();
    void thread_zext_ln265_3_fu_435_p1();
    void thread_zext_ln265_4_fu_457_p1();
    void thread_zext_ln265_5_fu_467_p1();
    void thread_zext_ln265_6_fu_489_p1();
    void thread_zext_ln265_7_fu_499_p1();
    void thread_zext_ln265_8_fu_521_p1();
    void thread_zext_ln265_9_fu_531_p1();
    void thread_zext_ln265_fu_404_p1();
    void thread_ap_NS_fsm();
};

}

using namespace ap_rtl;

#endif
