// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _Cipher_HH_
#define _Cipher_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "AddRoundKey.h"
#include "Cipher_sbox.h"

namespace ap_rtl {

struct Cipher : public sc_module {
    // Port declarations 19
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
    sc_out< sc_lv<8> > RoundKey_address0;
    sc_out< sc_logic > RoundKey_ce0;
    sc_in< sc_lv<8> > RoundKey_q0;


    // Module declarations
    Cipher(sc_module_name name);
    SC_HAS_PROCESS(Cipher);

    ~Cipher();

    sc_trace_file* mVcdFile;

    Cipher_sbox* sbox_U;
    AddRoundKey* grp_AddRoundKey_fu_274;
    sc_signal< sc_lv<25> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_lv<8> > sbox_address0;
    sc_signal< sc_logic > sbox_ce0;
    sc_signal< sc_lv<8> > sbox_q0;
    sc_signal< sc_lv<8> > reg_286;
    sc_signal< sc_logic > ap_CS_fsm_state8;
    sc_signal< sc_logic > ap_CS_fsm_state20;
    sc_signal< sc_lv<8> > reg_291;
    sc_signal< sc_logic > ap_CS_fsm_state13;
    sc_signal< sc_lv<8> > reg_298;
    sc_signal< sc_logic > ap_CS_fsm_state9;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_logic > grp_AddRoundKey_fu_274_ap_ready;
    sc_signal< sc_logic > grp_AddRoundKey_fu_274_ap_done;
    sc_signal< sc_lv<3> > i_fu_311_p2;
    sc_signal< sc_lv<3> > i_reg_695;
    sc_signal< sc_logic > ap_CS_fsm_state4;
    sc_signal< sc_lv<6> > zext_ln275_fu_317_p1;
    sc_signal< sc_lv<6> > zext_ln275_reg_700;
    sc_signal< sc_lv<1> > icmp_ln274_fu_305_p2;
    sc_signal< sc_lv<3> > j_fu_327_p2;
    sc_signal< sc_lv<3> > j_reg_708;
    sc_signal< sc_logic > ap_CS_fsm_state5;
    sc_signal< sc_lv<4> > state_addr_12_reg_713;
    sc_signal< sc_lv<1> > icmp_ln275_fu_321_p2;
    sc_signal< sc_logic > ap_CS_fsm_state6;
    sc_signal< sc_lv<8> > state_load_2_reg_724;
    sc_signal< sc_lv<8> > temp_1_reg_729;
    sc_signal< sc_logic > ap_CS_fsm_state10;
    sc_signal< sc_lv<8> > state_load_4_reg_734;
    sc_signal< sc_lv<8> > temp_2_reg_739;
    sc_signal< sc_logic > ap_CS_fsm_state11;
    sc_signal< sc_lv<8> > state_load_6_reg_744;
    sc_signal< sc_lv<8> > temp_3_reg_749;
    sc_signal< sc_logic > ap_CS_fsm_state12;
    sc_signal< sc_lv<8> > state_load_8_reg_754;
    sc_signal< sc_lv<3> > i_4_fu_372_p2;
    sc_signal< sc_lv<3> > i_4_reg_765;
    sc_signal< sc_logic > ap_CS_fsm_state19;
    sc_signal< sc_lv<5> > tmp_6_fu_378_p3;
    sc_signal< sc_lv<5> > tmp_6_reg_770;
    sc_signal< sc_lv<1> > icmp_ln317_fu_366_p2;
    sc_signal< sc_lv<4> > state_addr_13_reg_776;
    sc_signal< sc_lv<4> > state_addr_14_reg_781;
    sc_signal< sc_lv<8> > round_fu_406_p2;
    sc_signal< sc_lv<8> > round_reg_786;
    sc_signal< sc_lv<4> > state_addr_15_reg_791;
    sc_signal< sc_lv<4> > state_addr_16_reg_796;
    sc_signal< sc_lv<8> > xor_ln328_1_fu_586_p2;
    sc_signal< sc_lv<8> > xor_ln328_1_reg_801;
    sc_signal< sc_logic > ap_CS_fsm_state21;
    sc_signal< sc_lv<8> > xor_ln331_fu_626_p2;
    sc_signal< sc_lv<8> > xor_ln331_reg_806;
    sc_signal< sc_logic > grp_AddRoundKey_fu_274_ap_start;
    sc_signal< sc_logic > grp_AddRoundKey_fu_274_ap_idle;
    sc_signal< sc_lv<8> > grp_AddRoundKey_fu_274_round;
    sc_signal< sc_lv<4> > grp_AddRoundKey_fu_274_state_address0;
    sc_signal< sc_logic > grp_AddRoundKey_fu_274_state_ce0;
    sc_signal< sc_logic > grp_AddRoundKey_fu_274_state_we0;
    sc_signal< sc_lv<8> > grp_AddRoundKey_fu_274_state_d0;
    sc_signal< sc_lv<8> > grp_AddRoundKey_fu_274_RoundKey_address0;
    sc_signal< sc_logic > grp_AddRoundKey_fu_274_RoundKey_ce0;
    sc_signal< sc_lv<8> > round_0_reg_229;
    sc_signal< sc_logic > ap_CS_fsm_state23;
    sc_signal< sc_lv<3> > i_0_i_reg_241;
    sc_signal< sc_logic > ap_CS_fsm_state3;
    sc_signal< sc_lv<3> > j_0_i_reg_252;
    sc_signal< sc_logic > ap_CS_fsm_state7;
    sc_signal< sc_lv<3> > i_0_i3_reg_263;
    sc_signal< sc_logic > ap_CS_fsm_state22;
    sc_signal< sc_logic > ap_CS_fsm_state18;
    sc_signal< sc_lv<1> > icmp_ln435_fu_360_p2;
    sc_signal< sc_logic > grp_AddRoundKey_fu_274_ap_start_reg;
    sc_signal< sc_logic > ap_CS_fsm_state24;
    sc_signal< sc_logic > ap_CS_fsm_state25;
    sc_signal< sc_lv<64> > zext_ln276_1_fu_350_p1;
    sc_signal< sc_lv<64> > zext_ln276_2_fu_355_p1;
    sc_signal< sc_lv<64> > zext_ln318_fu_386_p1;
    sc_signal< sc_lv<64> > tmp_7_fu_397_p3;
    sc_signal< sc_lv<64> > tmp_8_fu_417_p3;
    sc_signal< sc_lv<64> > tmp_9_fu_431_p3;
    sc_signal< sc_logic > ap_CS_fsm_state14;
    sc_signal< sc_logic > ap_CS_fsm_state15;
    sc_signal< sc_logic > ap_CS_fsm_state16;
    sc_signal< sc_logic > ap_CS_fsm_state17;
    sc_signal< sc_lv<8> > xor_ln322_1_fu_492_p2;
    sc_signal< sc_lv<8> > xor_ln325_1_fu_539_p2;
    sc_signal< sc_lv<5> > tmp_fu_333_p3;
    sc_signal< sc_lv<6> > zext_ln276_fu_341_p1;
    sc_signal< sc_lv<6> > add_ln276_fu_345_p2;
    sc_signal< sc_lv<5> > or_ln319_fu_391_p2;
    sc_signal< sc_lv<5> > or_ln319_1_fu_412_p2;
    sc_signal< sc_lv<5> > or_ln319_2_fu_426_p2;
    sc_signal< sc_lv<8> > Tm_fu_440_p2;
    sc_signal< sc_lv<8> > xor_ln319_1_fu_446_p2;
    sc_signal< sc_lv<1> > tmp_1_fu_464_p3;
    sc_signal< sc_lv<8> > select_ln311_fu_472_p3;
    sc_signal< sc_lv<8> > shl_ln311_fu_458_p2;
    sc_signal< sc_lv<8> > Tmp_fu_452_p2;
    sc_signal< sc_lv<8> > xor_ln322_2_fu_486_p2;
    sc_signal< sc_lv<8> > xor_ln322_fu_480_p2;
    sc_signal< sc_lv<8> > Tm_1_fu_499_p2;
    sc_signal< sc_lv<1> > tmp_2_fu_511_p3;
    sc_signal< sc_lv<8> > select_ln311_1_fu_519_p3;
    sc_signal< sc_lv<8> > shl_ln311_1_fu_505_p2;
    sc_signal< sc_lv<8> > xor_ln325_2_fu_533_p2;
    sc_signal< sc_lv<8> > xor_ln325_fu_527_p2;
    sc_signal< sc_lv<8> > Tm_2_fu_546_p2;
    sc_signal< sc_lv<1> > tmp_3_fu_558_p3;
    sc_signal< sc_lv<8> > select_ln311_2_fu_566_p3;
    sc_signal< sc_lv<8> > shl_ln311_2_fu_552_p2;
    sc_signal< sc_lv<8> > xor_ln328_2_fu_580_p2;
    sc_signal< sc_lv<8> > xor_ln328_fu_574_p2;
    sc_signal< sc_lv<8> > Tm_3_fu_592_p2;
    sc_signal< sc_lv<1> > tmp_4_fu_604_p3;
    sc_signal< sc_lv<8> > shl_ln311_3_fu_598_p2;
    sc_signal< sc_lv<8> > xor_ln331_1_fu_620_p2;
    sc_signal< sc_lv<8> > select_ln311_3_fu_612_p3;
    sc_signal< sc_lv<25> > ap_NS_fsm;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<25> ap_ST_fsm_state1;
    static const sc_lv<25> ap_ST_fsm_state2;
    static const sc_lv<25> ap_ST_fsm_state3;
    static const sc_lv<25> ap_ST_fsm_state4;
    static const sc_lv<25> ap_ST_fsm_state5;
    static const sc_lv<25> ap_ST_fsm_state6;
    static const sc_lv<25> ap_ST_fsm_state7;
    static const sc_lv<25> ap_ST_fsm_state8;
    static const sc_lv<25> ap_ST_fsm_state9;
    static const sc_lv<25> ap_ST_fsm_state10;
    static const sc_lv<25> ap_ST_fsm_state11;
    static const sc_lv<25> ap_ST_fsm_state12;
    static const sc_lv<25> ap_ST_fsm_state13;
    static const sc_lv<25> ap_ST_fsm_state14;
    static const sc_lv<25> ap_ST_fsm_state15;
    static const sc_lv<25> ap_ST_fsm_state16;
    static const sc_lv<25> ap_ST_fsm_state17;
    static const sc_lv<25> ap_ST_fsm_state18;
    static const sc_lv<25> ap_ST_fsm_state19;
    static const sc_lv<25> ap_ST_fsm_state20;
    static const sc_lv<25> ap_ST_fsm_state21;
    static const sc_lv<25> ap_ST_fsm_state22;
    static const sc_lv<25> ap_ST_fsm_state23;
    static const sc_lv<25> ap_ST_fsm_state24;
    static const sc_lv<25> ap_ST_fsm_state25;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<32> ap_const_lv32_7;
    static const sc_lv<32> ap_const_lv32_13;
    static const sc_lv<32> ap_const_lv32_C;
    static const sc_lv<32> ap_const_lv32_8;
    static const sc_lv<32> ap_const_lv32_1;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<32> ap_const_lv32_4;
    static const sc_lv<32> ap_const_lv32_5;
    static const sc_lv<32> ap_const_lv32_9;
    static const sc_lv<32> ap_const_lv32_A;
    static const sc_lv<32> ap_const_lv32_B;
    static const sc_lv<32> ap_const_lv32_12;
    static const sc_lv<1> ap_const_lv1_1;
    static const sc_lv<32> ap_const_lv32_14;
    static const sc_lv<8> ap_const_lv8_1;
    static const sc_lv<32> ap_const_lv32_16;
    static const sc_lv<3> ap_const_lv3_0;
    static const sc_lv<32> ap_const_lv32_2;
    static const sc_lv<32> ap_const_lv32_6;
    static const sc_lv<32> ap_const_lv32_15;
    static const sc_lv<32> ap_const_lv32_11;
    static const sc_lv<32> ap_const_lv32_17;
    static const sc_lv<8> ap_const_lv8_0;
    static const sc_lv<8> ap_const_lv8_A;
    static const sc_lv<32> ap_const_lv32_18;
    static const sc_lv<64> ap_const_lv64_1;
    static const sc_lv<64> ap_const_lv64_5;
    static const sc_lv<64> ap_const_lv64_9;
    static const sc_lv<64> ap_const_lv64_D;
    static const sc_lv<64> ap_const_lv64_2;
    static const sc_lv<64> ap_const_lv64_A;
    static const sc_lv<64> ap_const_lv64_6;
    static const sc_lv<64> ap_const_lv64_E;
    static const sc_lv<64> ap_const_lv64_3;
    static const sc_lv<64> ap_const_lv64_F;
    static const sc_lv<64> ap_const_lv64_B;
    static const sc_lv<64> ap_const_lv64_7;
    static const sc_lv<32> ap_const_lv32_D;
    static const sc_lv<32> ap_const_lv32_E;
    static const sc_lv<32> ap_const_lv32_F;
    static const sc_lv<32> ap_const_lv32_10;
    static const sc_lv<3> ap_const_lv3_4;
    static const sc_lv<3> ap_const_lv3_1;
    static const sc_lv<2> ap_const_lv2_0;
    static const sc_lv<5> ap_const_lv5_1;
    static const sc_lv<59> ap_const_lv59_0;
    static const sc_lv<5> ap_const_lv5_2;
    static const sc_lv<5> ap_const_lv5_3;
    static const sc_lv<8> ap_const_lv8_1B;
    static const bool ap_const_boolean_1;
    // Thread declarations
    void thread_ap_clk_no_reset_();
    void thread_RoundKey_address0();
    void thread_RoundKey_ce0();
    void thread_Tm_1_fu_499_p2();
    void thread_Tm_2_fu_546_p2();
    void thread_Tm_3_fu_592_p2();
    void thread_Tm_fu_440_p2();
    void thread_Tmp_fu_452_p2();
    void thread_add_ln276_fu_345_p2();
    void thread_ap_CS_fsm_state1();
    void thread_ap_CS_fsm_state10();
    void thread_ap_CS_fsm_state11();
    void thread_ap_CS_fsm_state12();
    void thread_ap_CS_fsm_state13();
    void thread_ap_CS_fsm_state14();
    void thread_ap_CS_fsm_state15();
    void thread_ap_CS_fsm_state16();
    void thread_ap_CS_fsm_state17();
    void thread_ap_CS_fsm_state18();
    void thread_ap_CS_fsm_state19();
    void thread_ap_CS_fsm_state2();
    void thread_ap_CS_fsm_state20();
    void thread_ap_CS_fsm_state21();
    void thread_ap_CS_fsm_state22();
    void thread_ap_CS_fsm_state23();
    void thread_ap_CS_fsm_state24();
    void thread_ap_CS_fsm_state25();
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
    void thread_grp_AddRoundKey_fu_274_ap_start();
    void thread_grp_AddRoundKey_fu_274_round();
    void thread_i_4_fu_372_p2();
    void thread_i_fu_311_p2();
    void thread_icmp_ln274_fu_305_p2();
    void thread_icmp_ln275_fu_321_p2();
    void thread_icmp_ln317_fu_366_p2();
    void thread_icmp_ln435_fu_360_p2();
    void thread_j_fu_327_p2();
    void thread_or_ln319_1_fu_412_p2();
    void thread_or_ln319_2_fu_426_p2();
    void thread_or_ln319_fu_391_p2();
    void thread_round_fu_406_p2();
    void thread_sbox_address0();
    void thread_sbox_ce0();
    void thread_select_ln311_1_fu_519_p3();
    void thread_select_ln311_2_fu_566_p3();
    void thread_select_ln311_3_fu_612_p3();
    void thread_select_ln311_fu_472_p3();
    void thread_shl_ln311_1_fu_505_p2();
    void thread_shl_ln311_2_fu_552_p2();
    void thread_shl_ln311_3_fu_598_p2();
    void thread_shl_ln311_fu_458_p2();
    void thread_state_address0();
    void thread_state_address1();
    void thread_state_ce0();
    void thread_state_ce1();
    void thread_state_d0();
    void thread_state_d1();
    void thread_state_we0();
    void thread_state_we1();
    void thread_tmp_1_fu_464_p3();
    void thread_tmp_2_fu_511_p3();
    void thread_tmp_3_fu_558_p3();
    void thread_tmp_4_fu_604_p3();
    void thread_tmp_6_fu_378_p3();
    void thread_tmp_7_fu_397_p3();
    void thread_tmp_8_fu_417_p3();
    void thread_tmp_9_fu_431_p3();
    void thread_tmp_fu_333_p3();
    void thread_xor_ln319_1_fu_446_p2();
    void thread_xor_ln322_1_fu_492_p2();
    void thread_xor_ln322_2_fu_486_p2();
    void thread_xor_ln322_fu_480_p2();
    void thread_xor_ln325_1_fu_539_p2();
    void thread_xor_ln325_2_fu_533_p2();
    void thread_xor_ln325_fu_527_p2();
    void thread_xor_ln328_1_fu_586_p2();
    void thread_xor_ln328_2_fu_580_p2();
    void thread_xor_ln328_fu_574_p2();
    void thread_xor_ln331_1_fu_620_p2();
    void thread_xor_ln331_fu_626_p2();
    void thread_zext_ln275_fu_317_p1();
    void thread_zext_ln276_1_fu_350_p1();
    void thread_zext_ln276_2_fu_355_p1();
    void thread_zext_ln276_fu_341_p1();
    void thread_zext_ln318_fu_386_p1();
    void thread_ap_NS_fsm();
};

}

using namespace ap_rtl;

#endif
