-- ==============================================================
-- RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
-- Version: 2019.1
-- Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity MixColumns is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    state_address0 : OUT STD_LOGIC_VECTOR (3 downto 0);
    state_ce0 : OUT STD_LOGIC;
    state_we0 : OUT STD_LOGIC;
    state_d0 : OUT STD_LOGIC_VECTOR (7 downto 0);
    state_q0 : IN STD_LOGIC_VECTOR (7 downto 0);
    state_address1 : OUT STD_LOGIC_VECTOR (3 downto 0);
    state_ce1 : OUT STD_LOGIC;
    state_we1 : OUT STD_LOGIC;
    state_d1 : OUT STD_LOGIC_VECTOR (7 downto 0);
    state_q1 : IN STD_LOGIC_VECTOR (7 downto 0) );
end;


architecture behav of MixColumns is 
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (4 downto 0) := "00001";
    constant ap_ST_fsm_state2 : STD_LOGIC_VECTOR (4 downto 0) := "00010";
    constant ap_ST_fsm_state3 : STD_LOGIC_VECTOR (4 downto 0) := "00100";
    constant ap_ST_fsm_state4 : STD_LOGIC_VECTOR (4 downto 0) := "01000";
    constant ap_ST_fsm_state5 : STD_LOGIC_VECTOR (4 downto 0) := "10000";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv32_2 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000010";
    constant ap_const_lv32_3 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000011";
    constant ap_const_lv3_0 : STD_LOGIC_VECTOR (2 downto 0) := "000";
    constant ap_const_lv32_4 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000100";
    constant ap_const_lv3_4 : STD_LOGIC_VECTOR (2 downto 0) := "100";
    constant ap_const_lv3_1 : STD_LOGIC_VECTOR (2 downto 0) := "001";
    constant ap_const_lv2_0 : STD_LOGIC_VECTOR (1 downto 0) := "00";
    constant ap_const_lv5_1 : STD_LOGIC_VECTOR (4 downto 0) := "00001";
    constant ap_const_lv59_0 : STD_LOGIC_VECTOR (58 downto 0) := "00000000000000000000000000000000000000000000000000000000000";
    constant ap_const_lv5_2 : STD_LOGIC_VECTOR (4 downto 0) := "00010";
    constant ap_const_lv5_3 : STD_LOGIC_VECTOR (4 downto 0) := "00011";
    constant ap_const_lv8_1 : STD_LOGIC_VECTOR (7 downto 0) := "00000001";
    constant ap_const_lv32_7 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000111";
    constant ap_const_lv8_1B : STD_LOGIC_VECTOR (7 downto 0) := "00011011";
    constant ap_const_lv8_0 : STD_LOGIC_VECTOR (7 downto 0) := "00000000";
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_boolean_1 : BOOLEAN := true;

    signal ap_CS_fsm : STD_LOGIC_VECTOR (4 downto 0) := "00001";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal i_fu_100_p2 : STD_LOGIC_VECTOR (2 downto 0);
    signal i_reg_351 : STD_LOGIC_VECTOR (2 downto 0);
    signal ap_CS_fsm_state2 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state2 : signal is "none";
    signal tmp_fu_106_p3 : STD_LOGIC_VECTOR (4 downto 0);
    signal tmp_reg_356 : STD_LOGIC_VECTOR (4 downto 0);
    signal icmp_ln317_fu_94_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal state_addr_reg_362 : STD_LOGIC_VECTOR (3 downto 0);
    signal state_addr_12_reg_367 : STD_LOGIC_VECTOR (3 downto 0);
    signal state_addr_13_reg_372 : STD_LOGIC_VECTOR (3 downto 0);
    signal ap_CS_fsm_state3 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state3 : signal is "none";
    signal state_addr_14_reg_377 : STD_LOGIC_VECTOR (3 downto 0);
    signal t_reg_382 : STD_LOGIC_VECTOR (7 downto 0);
    signal state_load_reg_389 : STD_LOGIC_VECTOR (7 downto 0);
    signal xor_ln328_1_fu_303_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal xor_ln328_1_reg_396 : STD_LOGIC_VECTOR (7 downto 0);
    signal ap_CS_fsm_state4 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state4 : signal is "none";
    signal xor_ln331_fu_342_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal xor_ln331_reg_401 : STD_LOGIC_VECTOR (7 downto 0);
    signal i_0_reg_83 : STD_LOGIC_VECTOR (2 downto 0);
    signal ap_CS_fsm_state5 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state5 : signal is "none";
    signal zext_ln318_fu_114_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal tmp_6_fu_125_p3 : STD_LOGIC_VECTOR (63 downto 0);
    signal tmp_7_fu_139_p3 : STD_LOGIC_VECTOR (63 downto 0);
    signal tmp_8_fu_153_p3 : STD_LOGIC_VECTOR (63 downto 0);
    signal xor_ln322_1_fu_211_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal xor_ln325_1_fu_256_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal or_ln319_fu_119_p2 : STD_LOGIC_VECTOR (4 downto 0);
    signal or_ln319_1_fu_134_p2 : STD_LOGIC_VECTOR (4 downto 0);
    signal or_ln319_2_fu_148_p2 : STD_LOGIC_VECTOR (4 downto 0);
    signal Tm_fu_162_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal xor_ln319_1_fu_166_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal tmp_1_fu_184_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal select_ln311_fu_192_p3 : STD_LOGIC_VECTOR (7 downto 0);
    signal shl_ln311_fu_178_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal Tmp_fu_172_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal xor_ln322_2_fu_205_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal xor_ln322_fu_200_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal Tm_1_fu_218_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal tmp_2_fu_229_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal select_ln311_1_fu_237_p3 : STD_LOGIC_VECTOR (7 downto 0);
    signal shl_ln311_1_fu_223_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal xor_ln325_2_fu_250_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal xor_ln325_fu_245_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal Tm_2_fu_263_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal tmp_3_fu_275_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal select_ln311_2_fu_283_p3 : STD_LOGIC_VECTOR (7 downto 0);
    signal shl_ln311_2_fu_269_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal xor_ln328_2_fu_297_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal xor_ln328_fu_291_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal Tm_3_fu_309_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal tmp_4_fu_320_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal shl_ln311_3_fu_314_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal xor_ln331_1_fu_336_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal select_ln311_3_fu_328_p3 : STD_LOGIC_VECTOR (7 downto 0);
    signal ap_NS_fsm : STD_LOGIC_VECTOR (4 downto 0);


begin




    ap_CS_fsm_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_CS_fsm <= ap_ST_fsm_state1;
            else
                ap_CS_fsm <= ap_NS_fsm;
            end if;
        end if;
    end process;


    i_0_reg_83_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state5)) then 
                i_0_reg_83 <= i_reg_351;
            elsif (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then 
                i_0_reg_83 <= ap_const_lv3_0;
            end if; 
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state2)) then
                i_reg_351 <= i_fu_100_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln317_fu_94_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2))) then
                    state_addr_12_reg_367(3 downto 2) <= tmp_6_fu_125_p3(4 - 1 downto 0)(3 downto 2);
                    state_addr_reg_362(3 downto 2) <= zext_ln318_fu_114_p1(4 - 1 downto 0)(3 downto 2);
                    tmp_reg_356(4 downto 2) <= tmp_fu_106_p3(4 downto 2);
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state3)) then
                    state_addr_13_reg_372(3 downto 2) <= tmp_7_fu_139_p3(4 - 1 downto 0)(3 downto 2);
                    state_addr_14_reg_377(3 downto 2) <= tmp_8_fu_153_p3(4 - 1 downto 0)(3 downto 2);
                state_load_reg_389 <= state_q1;
                t_reg_382 <= state_q0;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state4)) then
                xor_ln328_1_reg_396 <= xor_ln328_1_fu_303_p2;
                xor_ln331_reg_401 <= xor_ln331_fu_342_p2;
            end if;
        end if;
    end process;
    tmp_reg_356(1 downto 0) <= "00";
    state_addr_reg_362(1 downto 0) <= "00";
    state_addr_12_reg_367(1 downto 0) <= "01";
    state_addr_13_reg_372(1 downto 0) <= "10";
    state_addr_14_reg_377(1 downto 0) <= "11";

    ap_NS_fsm_assign_proc : process (ap_start, ap_CS_fsm, ap_CS_fsm_state1, ap_CS_fsm_state2, icmp_ln317_fu_94_p2)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_state1 => 
                if (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state1;
                end if;
            when ap_ST_fsm_state2 => 
                if (((icmp_ln317_fu_94_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then
                    ap_NS_fsm <= ap_ST_fsm_state1;
                else
                    ap_NS_fsm <= ap_ST_fsm_state3;
                end if;
            when ap_ST_fsm_state3 => 
                ap_NS_fsm <= ap_ST_fsm_state4;
            when ap_ST_fsm_state4 => 
                ap_NS_fsm <= ap_ST_fsm_state5;
            when ap_ST_fsm_state5 => 
                ap_NS_fsm <= ap_ST_fsm_state2;
            when others =>  
                ap_NS_fsm <= "XXXXX";
        end case;
    end process;
    Tm_1_fu_218_p2 <= (state_q0 xor state_load_reg_389);
    Tm_2_fu_263_p2 <= (state_q1 xor state_q0);
    Tm_3_fu_309_p2 <= (t_reg_382 xor state_q1);
    Tm_fu_162_p2 <= (t_reg_382 xor state_load_reg_389);
    Tmp_fu_172_p2 <= (xor_ln319_1_fu_166_p2 xor state_q1);
    ap_CS_fsm_state1 <= ap_CS_fsm(0);
    ap_CS_fsm_state2 <= ap_CS_fsm(1);
    ap_CS_fsm_state3 <= ap_CS_fsm(2);
    ap_CS_fsm_state4 <= ap_CS_fsm(3);
    ap_CS_fsm_state5 <= ap_CS_fsm(4);

    ap_done_assign_proc : process(ap_start, ap_CS_fsm_state1, ap_CS_fsm_state2, icmp_ln317_fu_94_p2)
    begin
        if ((((icmp_ln317_fu_94_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((ap_start = ap_const_logic_0) and (ap_const_logic_1 = ap_CS_fsm_state1)))) then 
            ap_done <= ap_const_logic_1;
        else 
            ap_done <= ap_const_logic_0;
        end if; 
    end process;


    ap_idle_assign_proc : process(ap_start, ap_CS_fsm_state1)
    begin
        if (((ap_start = ap_const_logic_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            ap_idle <= ap_const_logic_1;
        else 
            ap_idle <= ap_const_logic_0;
        end if; 
    end process;


    ap_ready_assign_proc : process(ap_CS_fsm_state2, icmp_ln317_fu_94_p2)
    begin
        if (((icmp_ln317_fu_94_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;

    i_fu_100_p2 <= std_logic_vector(unsigned(i_0_reg_83) + unsigned(ap_const_lv3_1));
    icmp_ln317_fu_94_p2 <= "1" when (i_0_reg_83 = ap_const_lv3_4) else "0";
    or_ln319_1_fu_134_p2 <= (tmp_reg_356 or ap_const_lv5_2);
    or_ln319_2_fu_148_p2 <= (tmp_reg_356 or ap_const_lv5_3);
    or_ln319_fu_119_p2 <= (tmp_fu_106_p3 or ap_const_lv5_1);
    select_ln311_1_fu_237_p3 <= 
        ap_const_lv8_1B when (tmp_2_fu_229_p3(0) = '1') else 
        ap_const_lv8_0;
    select_ln311_2_fu_283_p3 <= 
        ap_const_lv8_1B when (tmp_3_fu_275_p3(0) = '1') else 
        ap_const_lv8_0;
    select_ln311_3_fu_328_p3 <= 
        ap_const_lv8_1B when (tmp_4_fu_320_p3(0) = '1') else 
        ap_const_lv8_0;
    select_ln311_fu_192_p3 <= 
        ap_const_lv8_1B when (tmp_1_fu_184_p3(0) = '1') else 
        ap_const_lv8_0;
    shl_ln311_1_fu_223_p2 <= std_logic_vector(shift_left(unsigned(Tm_1_fu_218_p2),to_integer(unsigned('0' & ap_const_lv8_1(8-1 downto 0)))));
    shl_ln311_2_fu_269_p2 <= std_logic_vector(shift_left(unsigned(Tm_2_fu_263_p2),to_integer(unsigned('0' & ap_const_lv8_1(8-1 downto 0)))));
    shl_ln311_3_fu_314_p2 <= std_logic_vector(shift_left(unsigned(Tm_3_fu_309_p2),to_integer(unsigned('0' & ap_const_lv8_1(8-1 downto 0)))));
    shl_ln311_fu_178_p2 <= std_logic_vector(shift_left(unsigned(Tm_fu_162_p2),to_integer(unsigned('0' & ap_const_lv8_1(8-1 downto 0)))));

    state_address0_assign_proc : process(ap_CS_fsm_state2, state_addr_reg_362, state_addr_13_reg_372, ap_CS_fsm_state3, ap_CS_fsm_state4, ap_CS_fsm_state5, zext_ln318_fu_114_p1, tmp_7_fu_139_p3)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state5)) then 
            state_address0 <= state_addr_13_reg_372;
        elsif ((ap_const_logic_1 = ap_CS_fsm_state4)) then 
            state_address0 <= state_addr_reg_362;
        elsif ((ap_const_logic_1 = ap_CS_fsm_state3)) then 
            state_address0 <= tmp_7_fu_139_p3(4 - 1 downto 0);
        elsif ((ap_const_logic_1 = ap_CS_fsm_state2)) then 
            state_address0 <= zext_ln318_fu_114_p1(4 - 1 downto 0);
        else 
            state_address0 <= "XXXX";
        end if; 
    end process;


    state_address1_assign_proc : process(ap_CS_fsm_state2, state_addr_12_reg_367, ap_CS_fsm_state3, state_addr_14_reg_377, ap_CS_fsm_state4, ap_CS_fsm_state5, tmp_6_fu_125_p3, tmp_8_fu_153_p3)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state5)) then 
            state_address1 <= state_addr_14_reg_377;
        elsif ((ap_const_logic_1 = ap_CS_fsm_state4)) then 
            state_address1 <= state_addr_12_reg_367;
        elsif ((ap_const_logic_1 = ap_CS_fsm_state3)) then 
            state_address1 <= tmp_8_fu_153_p3(4 - 1 downto 0);
        elsif ((ap_const_logic_1 = ap_CS_fsm_state2)) then 
            state_address1 <= tmp_6_fu_125_p3(4 - 1 downto 0);
        else 
            state_address1 <= "XXXX";
        end if; 
    end process;


    state_ce0_assign_proc : process(ap_CS_fsm_state2, ap_CS_fsm_state3, ap_CS_fsm_state4, ap_CS_fsm_state5)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state5) or (ap_const_logic_1 = ap_CS_fsm_state4) or (ap_const_logic_1 = ap_CS_fsm_state3) or (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            state_ce0 <= ap_const_logic_1;
        else 
            state_ce0 <= ap_const_logic_0;
        end if; 
    end process;


    state_ce1_assign_proc : process(ap_CS_fsm_state2, ap_CS_fsm_state3, ap_CS_fsm_state4, ap_CS_fsm_state5)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state5) or (ap_const_logic_1 = ap_CS_fsm_state4) or (ap_const_logic_1 = ap_CS_fsm_state3) or (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            state_ce1 <= ap_const_logic_1;
        else 
            state_ce1 <= ap_const_logic_0;
        end if; 
    end process;


    state_d0_assign_proc : process(xor_ln328_1_reg_396, ap_CS_fsm_state4, ap_CS_fsm_state5, xor_ln322_1_fu_211_p2)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state5)) then 
            state_d0 <= xor_ln328_1_reg_396;
        elsif ((ap_const_logic_1 = ap_CS_fsm_state4)) then 
            state_d0 <= xor_ln322_1_fu_211_p2;
        else 
            state_d0 <= "XXXXXXXX";
        end if; 
    end process;


    state_d1_assign_proc : process(ap_CS_fsm_state4, xor_ln331_reg_401, ap_CS_fsm_state5, xor_ln325_1_fu_256_p2)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state5)) then 
            state_d1 <= xor_ln331_reg_401;
        elsif ((ap_const_logic_1 = ap_CS_fsm_state4)) then 
            state_d1 <= xor_ln325_1_fu_256_p2;
        else 
            state_d1 <= "XXXXXXXX";
        end if; 
    end process;


    state_we0_assign_proc : process(ap_CS_fsm_state4, ap_CS_fsm_state5)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state5) or (ap_const_logic_1 = ap_CS_fsm_state4))) then 
            state_we0 <= ap_const_logic_1;
        else 
            state_we0 <= ap_const_logic_0;
        end if; 
    end process;


    state_we1_assign_proc : process(ap_CS_fsm_state4, ap_CS_fsm_state5)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state5) or (ap_const_logic_1 = ap_CS_fsm_state4))) then 
            state_we1 <= ap_const_logic_1;
        else 
            state_we1 <= ap_const_logic_0;
        end if; 
    end process;

    tmp_1_fu_184_p3 <= Tm_fu_162_p2(7 downto 7);
    tmp_2_fu_229_p3 <= Tm_1_fu_218_p2(7 downto 7);
    tmp_3_fu_275_p3 <= Tm_2_fu_263_p2(7 downto 7);
    tmp_4_fu_320_p3 <= Tm_3_fu_309_p2(7 downto 7);
    tmp_6_fu_125_p3 <= (ap_const_lv59_0 & or_ln319_fu_119_p2);
    tmp_7_fu_139_p3 <= (ap_const_lv59_0 & or_ln319_1_fu_134_p2);
    tmp_8_fu_153_p3 <= (ap_const_lv59_0 & or_ln319_2_fu_148_p2);
    tmp_fu_106_p3 <= (i_0_reg_83 & ap_const_lv2_0);
    xor_ln319_1_fu_166_p2 <= (state_q0 xor Tm_fu_162_p2);
    xor_ln322_1_fu_211_p2 <= (xor_ln322_fu_200_p2 xor xor_ln322_2_fu_205_p2);
    xor_ln322_2_fu_205_p2 <= (shl_ln311_fu_178_p2 xor Tmp_fu_172_p2);
    xor_ln322_fu_200_p2 <= (t_reg_382 xor select_ln311_fu_192_p3);
    xor_ln325_1_fu_256_p2 <= (xor_ln325_fu_245_p2 xor xor_ln325_2_fu_250_p2);
    xor_ln325_2_fu_250_p2 <= (shl_ln311_1_fu_223_p2 xor Tmp_fu_172_p2);
    xor_ln325_fu_245_p2 <= (state_load_reg_389 xor select_ln311_1_fu_237_p3);
    xor_ln328_1_fu_303_p2 <= (xor_ln328_fu_291_p2 xor xor_ln328_2_fu_297_p2);
    xor_ln328_2_fu_297_p2 <= (shl_ln311_2_fu_269_p2 xor Tmp_fu_172_p2);
    xor_ln328_fu_291_p2 <= (state_q0 xor select_ln311_2_fu_283_p3);
    xor_ln331_1_fu_336_p2 <= (xor_ln319_1_fu_166_p2 xor shl_ln311_3_fu_314_p2);
    xor_ln331_fu_342_p2 <= (xor_ln331_1_fu_336_p2 xor select_ln311_3_fu_328_p3);
    zext_ln318_fu_114_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(tmp_fu_106_p3),64));
end behav;