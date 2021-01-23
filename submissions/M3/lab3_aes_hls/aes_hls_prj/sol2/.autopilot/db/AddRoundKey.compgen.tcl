# This script segment is generated automatically by AutoPilot

# clear list
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_begin
    cg_default_interface_gen_bundle_begin
    AESL_LIB_XILADAPTER::native_axis_begin
}

# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 36 \
    name RoundKey \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename RoundKey \
    op interface \
    ports { RoundKey_address0 { O 8 vector } RoundKey_ce0 { O 1 bit } RoundKey_q0 { I 8 vector } RoundKey_address1 { O 8 vector } RoundKey_ce1 { O 1 bit } RoundKey_q1 { I 8 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'RoundKey'"
}
}


# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 19 \
    name round \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_round \
    op interface \
    ports { round { I 5 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 20 \
    name state_0_0_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_state_0_0_read \
    op interface \
    ports { state_0_0_read { I 8 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 21 \
    name state_0_1_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_state_0_1_read \
    op interface \
    ports { state_0_1_read { I 8 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 22 \
    name state_0_2_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_state_0_2_read \
    op interface \
    ports { state_0_2_read { I 8 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 23 \
    name state_0_3_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_state_0_3_read \
    op interface \
    ports { state_0_3_read { I 8 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 24 \
    name state_1_0_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_state_1_0_read \
    op interface \
    ports { state_1_0_read { I 8 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 25 \
    name state_1_1_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_state_1_1_read \
    op interface \
    ports { state_1_1_read { I 8 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 26 \
    name state_1_2_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_state_1_2_read \
    op interface \
    ports { state_1_2_read { I 8 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 27 \
    name state_1_3_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_state_1_3_read \
    op interface \
    ports { state_1_3_read { I 8 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 28 \
    name state_2_0_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_state_2_0_read \
    op interface \
    ports { state_2_0_read { I 8 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 29 \
    name state_2_1_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_state_2_1_read \
    op interface \
    ports { state_2_1_read { I 8 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 30 \
    name state_2_2_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_state_2_2_read \
    op interface \
    ports { state_2_2_read { I 8 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 31 \
    name state_2_3_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_state_2_3_read \
    op interface \
    ports { state_2_3_read { I 8 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 32 \
    name state_3_0_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_state_3_0_read \
    op interface \
    ports { state_3_0_read { I 8 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 33 \
    name state_3_1_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_state_3_1_read \
    op interface \
    ports { state_3_1_read { I 8 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 34 \
    name state_3_2_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_state_3_2_read \
    op interface \
    ports { state_3_2_read { I 8 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 35 \
    name state_3_3_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_state_3_3_read \
    op interface \
    ports { state_3_3_read { I 8 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id -1 \
    name ap_ctrl \
    type ap_ctrl \
    reset_level 1 \
    sync_rst true \
    corename ap_ctrl \
    op interface \
    ports { ap_start { I 1 bit } ap_ready { O 1 bit } ap_done { O 1 bit } ap_idle { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id -2 \
    name ap_return \
    type ap_return \
    reset_level 1 \
    sync_rst true \
    corename ap_return \
    op interface \
    ports { ap_return { O 1 vector } } \
} "
}


# Adapter definition:
set PortName ap_clk
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_clock] == "cg_default_interface_gen_clock"} {
eval "cg_default_interface_gen_clock { \
    id -3 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_clk \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-113\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}


# Adapter definition:
set PortName ap_rst
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_reset] == "cg_default_interface_gen_reset"} {
eval "cg_default_interface_gen_reset { \
    id -4 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_rst \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-114\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}


# Adapter definition:
set PortName ap_ce
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_ce] == "cg_default_interface_gen_ce"} {
eval "cg_default_interface_gen_ce { \
    id -5 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_ce \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-113\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}



# merge
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_end
    cg_default_interface_gen_bundle_end
    AESL_LIB_XILADAPTER::native_axis_end
}


