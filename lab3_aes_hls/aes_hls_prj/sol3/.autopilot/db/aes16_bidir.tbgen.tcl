set moduleName aes16_bidir
set isTopModule 1
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isFreeRunPipelineModule 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {aes16_bidir}
set C_modelType { void 0 }
set C_modelArgList {
	{ key_0 int 32 regular {pointer 0}  }
	{ key_1 int 32 regular {pointer 0}  }
	{ key_2 int 32 regular {pointer 0}  }
	{ key_3 int 32 regular {pointer 0}  }
	{ inout_0 int 32 regular {pointer 2}  }
	{ inout_1 int 32 regular {pointer 2}  }
	{ inout_2 int 32 regular {pointer 2}  }
	{ inout_3 int 32 regular {pointer 2}  }
	{ iv_0 int 32 regular {pointer 2}  }
	{ iv_1 int 32 regular {pointer 2}  }
	{ iv_2 int 32 regular {pointer 2}  }
	{ iv_3 int 32 regular {pointer 2}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "key_0", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "key","cData": "unsigned int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 2}]}]}]} , 
 	{ "Name" : "key_1", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "key","cData": "unsigned int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 1,"up" : 1,"step" : 2}]}]}]} , 
 	{ "Name" : "key_2", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "key","cData": "unsigned int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 2,"up" : 2,"step" : 2}]}]}]} , 
 	{ "Name" : "key_3", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "key","cData": "unsigned int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 3,"up" : 3,"step" : 2}]}]}]} , 
 	{ "Name" : "inout_0", "interface" : "wire", "bitwidth" : 32, "direction" : "READWRITE", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "inout","cData": "unsigned int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 2}]}]}]} , 
 	{ "Name" : "inout_1", "interface" : "wire", "bitwidth" : 32, "direction" : "READWRITE", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "inout","cData": "unsigned int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 1,"up" : 1,"step" : 2}]}]}]} , 
 	{ "Name" : "inout_2", "interface" : "wire", "bitwidth" : 32, "direction" : "READWRITE", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "inout","cData": "unsigned int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 2,"up" : 2,"step" : 2}]}]}]} , 
 	{ "Name" : "inout_3", "interface" : "wire", "bitwidth" : 32, "direction" : "READWRITE", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "inout","cData": "unsigned int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 3,"up" : 3,"step" : 2}]}]}]} , 
 	{ "Name" : "iv_0", "interface" : "wire", "bitwidth" : 32, "direction" : "READWRITE", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "iv","cData": "unsigned int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 2}]}]}]} , 
 	{ "Name" : "iv_1", "interface" : "wire", "bitwidth" : 32, "direction" : "READWRITE", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "iv","cData": "unsigned int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 1,"up" : 1,"step" : 2}]}]}]} , 
 	{ "Name" : "iv_2", "interface" : "wire", "bitwidth" : 32, "direction" : "READWRITE", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "iv","cData": "unsigned int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 2,"up" : 2,"step" : 2}]}]}]} , 
 	{ "Name" : "iv_3", "interface" : "wire", "bitwidth" : 32, "direction" : "READWRITE", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "iv","cData": "unsigned int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 3,"up" : 3,"step" : 2}]}]}]} ]}
# RTL Port declarations: 
set portNum 34
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ key_0 sc_in sc_lv 32 signal 0 } 
	{ key_1 sc_in sc_lv 32 signal 1 } 
	{ key_2 sc_in sc_lv 32 signal 2 } 
	{ key_3 sc_in sc_lv 32 signal 3 } 
	{ inout_0_i sc_in sc_lv 32 signal 4 } 
	{ inout_0_o sc_out sc_lv 32 signal 4 } 
	{ inout_0_o_ap_vld sc_out sc_logic 1 outvld 4 } 
	{ inout_1_i sc_in sc_lv 32 signal 5 } 
	{ inout_1_o sc_out sc_lv 32 signal 5 } 
	{ inout_1_o_ap_vld sc_out sc_logic 1 outvld 5 } 
	{ inout_2_i sc_in sc_lv 32 signal 6 } 
	{ inout_2_o sc_out sc_lv 32 signal 6 } 
	{ inout_2_o_ap_vld sc_out sc_logic 1 outvld 6 } 
	{ inout_3_i sc_in sc_lv 32 signal 7 } 
	{ inout_3_o sc_out sc_lv 32 signal 7 } 
	{ inout_3_o_ap_vld sc_out sc_logic 1 outvld 7 } 
	{ iv_0_i sc_in sc_lv 32 signal 8 } 
	{ iv_0_o sc_out sc_lv 32 signal 8 } 
	{ iv_0_o_ap_vld sc_out sc_logic 1 outvld 8 } 
	{ iv_1_i sc_in sc_lv 32 signal 9 } 
	{ iv_1_o sc_out sc_lv 32 signal 9 } 
	{ iv_1_o_ap_vld sc_out sc_logic 1 outvld 9 } 
	{ iv_2_i sc_in sc_lv 32 signal 10 } 
	{ iv_2_o sc_out sc_lv 32 signal 10 } 
	{ iv_2_o_ap_vld sc_out sc_logic 1 outvld 10 } 
	{ iv_3_i sc_in sc_lv 32 signal 11 } 
	{ iv_3_o sc_out sc_lv 32 signal 11 } 
	{ iv_3_o_ap_vld sc_out sc_logic 1 outvld 11 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "key_0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "key_0", "role": "default" }} , 
 	{ "name": "key_1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "key_1", "role": "default" }} , 
 	{ "name": "key_2", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "key_2", "role": "default" }} , 
 	{ "name": "key_3", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "key_3", "role": "default" }} , 
 	{ "name": "inout_0_i", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "inout_0", "role": "i" }} , 
 	{ "name": "inout_0_o", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "inout_0", "role": "o" }} , 
 	{ "name": "inout_0_o_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "inout_0", "role": "o_ap_vld" }} , 
 	{ "name": "inout_1_i", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "inout_1", "role": "i" }} , 
 	{ "name": "inout_1_o", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "inout_1", "role": "o" }} , 
 	{ "name": "inout_1_o_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "inout_1", "role": "o_ap_vld" }} , 
 	{ "name": "inout_2_i", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "inout_2", "role": "i" }} , 
 	{ "name": "inout_2_o", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "inout_2", "role": "o" }} , 
 	{ "name": "inout_2_o_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "inout_2", "role": "o_ap_vld" }} , 
 	{ "name": "inout_3_i", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "inout_3", "role": "i" }} , 
 	{ "name": "inout_3_o", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "inout_3", "role": "o" }} , 
 	{ "name": "inout_3_o_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "inout_3", "role": "o_ap_vld" }} , 
 	{ "name": "iv_0_i", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "iv_0", "role": "i" }} , 
 	{ "name": "iv_0_o", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "iv_0", "role": "o" }} , 
 	{ "name": "iv_0_o_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "iv_0", "role": "o_ap_vld" }} , 
 	{ "name": "iv_1_i", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "iv_1", "role": "i" }} , 
 	{ "name": "iv_1_o", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "iv_1", "role": "o" }} , 
 	{ "name": "iv_1_o_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "iv_1", "role": "o_ap_vld" }} , 
 	{ "name": "iv_2_i", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "iv_2", "role": "i" }} , 
 	{ "name": "iv_2_o", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "iv_2", "role": "o" }} , 
 	{ "name": "iv_2_o_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "iv_2", "role": "o_ap_vld" }} , 
 	{ "name": "iv_3_i", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "iv_3", "role": "i" }} , 
 	{ "name": "iv_3_o", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "iv_3", "role": "o" }} , 
 	{ "name": "iv_3_o_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "iv_3", "role": "o_ap_vld" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "8", "16", "17", "18"],
		"CDFG" : "aes16_bidir",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "951", "EstimateLatencyMax" : "983",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"WaitState" : [
			{"State" : "ap_ST_fsm_state4", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_KeyExpansion_fu_394"},
			{"State" : "ap_ST_fsm_state7", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AES_CTR_xcrypt_buffe_fu_402"}],
		"Port" : [
			{"Name" : "key_0", "Type" : "None", "Direction" : "I"},
			{"Name" : "key_1", "Type" : "None", "Direction" : "I"},
			{"Name" : "key_2", "Type" : "None", "Direction" : "I"},
			{"Name" : "key_3", "Type" : "None", "Direction" : "I"},
			{"Name" : "inout_0", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "inout_1", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "inout_2", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "inout_3", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "iv_0", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "iv_1", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "iv_2", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "iv_3", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "sbox", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "6", "SubInstance" : "grp_KeyExpansion_fu_394", "Port" : "sbox"},
					{"ID" : "8", "SubInstance" : "grp_AES_CTR_xcrypt_buffe_fu_402", "Port" : "sbox"}]}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.p_key_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.p_text_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.p_iv_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.ctx_RoundKey_U", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.ctx_Iv_U", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_KeyExpansion_fu_394", "Parent" : "0", "Child" : ["7"],
		"CDFG" : "KeyExpansion",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "88", "EstimateLatencyMax" : "88",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "RoundKey", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "Key", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "sbox", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "7", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_KeyExpansion_fu_394.sbox_U", "Parent" : "6"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_AES_CTR_xcrypt_buffe_fu_402", "Parent" : "0", "Child" : ["9", "10", "11", "12", "14", "15"],
		"CDFG" : "AES_CTR_xcrypt_buffe",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "790", "EstimateLatencyMax" : "822",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"WaitState" : [
			{"State" : "ap_ST_fsm_state7", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_551"},
			{"State" : "ap_ST_fsm_state15", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_551"},
			{"State" : "ap_ST_fsm_state23", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_551"},
			{"State" : "ap_ST_fsm_state31", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_551"},
			{"State" : "ap_ST_fsm_state39", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_551"},
			{"State" : "ap_ST_fsm_state47", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_551"},
			{"State" : "ap_ST_fsm_state55", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_551"},
			{"State" : "ap_ST_fsm_state63", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_551"},
			{"State" : "ap_ST_fsm_state71", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_551"},
			{"State" : "ap_ST_fsm_state79", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_551"},
			{"State" : "ap_ST_fsm_state85", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_551"},
			{"State" : "ap_ST_fsm_state9", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_570"},
			{"State" : "ap_ST_fsm_state17", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_570"},
			{"State" : "ap_ST_fsm_state25", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_570"},
			{"State" : "ap_ST_fsm_state33", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_570"},
			{"State" : "ap_ST_fsm_state41", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_570"},
			{"State" : "ap_ST_fsm_state49", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_570"},
			{"State" : "ap_ST_fsm_state57", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_570"},
			{"State" : "ap_ST_fsm_state65", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_570"},
			{"State" : "ap_ST_fsm_state73", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_570"},
			{"State" : "ap_ST_fsm_state81", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_570"},
			{"State" : "ap_ST_fsm_state11", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_577"},
			{"State" : "ap_ST_fsm_state19", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_577"},
			{"State" : "ap_ST_fsm_state27", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_577"},
			{"State" : "ap_ST_fsm_state35", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_577"},
			{"State" : "ap_ST_fsm_state43", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_577"},
			{"State" : "ap_ST_fsm_state51", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_577"},
			{"State" : "ap_ST_fsm_state59", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_577"},
			{"State" : "ap_ST_fsm_state67", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_577"},
			{"State" : "ap_ST_fsm_state75", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_577"},
			{"State" : "ap_ST_fsm_state83", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_577"},
			{"State" : "ap_ST_fsm_state13", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_582"},
			{"State" : "ap_ST_fsm_state21", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_582"},
			{"State" : "ap_ST_fsm_state29", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_582"},
			{"State" : "ap_ST_fsm_state37", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_582"},
			{"State" : "ap_ST_fsm_state45", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_582"},
			{"State" : "ap_ST_fsm_state53", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_582"},
			{"State" : "ap_ST_fsm_state61", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_582"},
			{"State" : "ap_ST_fsm_state69", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_582"},
			{"State" : "ap_ST_fsm_state77", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_582"}],
		"Port" : [
			{"Name" : "ctx_RoundKey", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "11", "SubInstance" : "grp_AddRoundKey_fu_551", "Port" : "RoundKey"}]},
			{"Name" : "ctx_Iv", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "buf_r", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "sbox", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "12", "SubInstance" : "grp_SubBytes_fu_570", "Port" : "sbox"}]}]},
	{"ID" : "9", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_AES_CTR_xcrypt_buffe_fu_402.buffer_U", "Parent" : "8"},
	{"ID" : "10", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_AES_CTR_xcrypt_buffe_fu_402.x_U", "Parent" : "8"},
	{"ID" : "11", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_AES_CTR_xcrypt_buffe_fu_402.grp_AddRoundKey_fu_551", "Parent" : "8",
		"CDFG" : "AddRoundKey",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "15", "EstimateLatencyMax" : "15",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "round", "Type" : "None", "Direction" : "I"},
			{"Name" : "state", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "RoundKey", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "12", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_AES_CTR_xcrypt_buffe_fu_402.grp_SubBytes_fu_570", "Parent" : "8", "Child" : ["13"],
		"CDFG" : "SubBytes",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "15", "EstimateLatencyMax" : "15",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "state", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "sbox", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "13", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_AES_CTR_xcrypt_buffe_fu_402.grp_SubBytes_fu_570.sbox_U", "Parent" : "12"},
	{"ID" : "14", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_AES_CTR_xcrypt_buffe_fu_402.grp_ShiftRows_fu_577", "Parent" : "8",
		"CDFG" : "ShiftRows",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "11", "EstimateLatencyMax" : "11",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "state", "Type" : "Memory", "Direction" : "IO"}]},
	{"ID" : "15", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_AES_CTR_xcrypt_buffe_fu_402.grp_MixColumns_fu_582", "Parent" : "8",
		"CDFG" : "MixColumns",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "17", "EstimateLatencyMax" : "17",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "state", "Type" : "Memory", "Direction" : "IO"}]},
	{"ID" : "16", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.aes16_bidir_mux_42_32_1_1_U15", "Parent" : "0"},
	{"ID" : "17", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.aes16_bidir_mux_42_32_1_1_U16", "Parent" : "0"},
	{"ID" : "18", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.aes16_bidir_mux_42_32_1_1_U17", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	aes16_bidir {
		key_0 {Type I LastRead 1 FirstWrite -1}
		key_1 {Type I LastRead 1 FirstWrite -1}
		key_2 {Type I LastRead 1 FirstWrite -1}
		key_3 {Type I LastRead 1 FirstWrite -1}
		inout_0 {Type IO LastRead 1 FirstWrite 7}
		inout_1 {Type IO LastRead 1 FirstWrite 7}
		inout_2 {Type IO LastRead 1 FirstWrite 7}
		inout_3 {Type IO LastRead 1 FirstWrite 7}
		iv_0 {Type IO LastRead 1 FirstWrite 7}
		iv_1 {Type IO LastRead 1 FirstWrite 7}
		iv_2 {Type IO LastRead 1 FirstWrite 7}
		iv_3 {Type IO LastRead 1 FirstWrite 7}
		sbox {Type I LastRead -1 FirstWrite -1}}
	KeyExpansion {
		RoundKey {Type O LastRead -1 FirstWrite 1}
		Key {Type I LastRead 8 FirstWrite -1}
		sbox {Type I LastRead -1 FirstWrite -1}}
	AES_CTR_xcrypt_buffe {
		ctx_RoundKey {Type I LastRead 15 FirstWrite -1}
		ctx_Iv {Type IO LastRead 83 FirstWrite 84}
		buf_r {Type IO LastRead 92 FirstWrite 92}
		sbox {Type I LastRead -1 FirstWrite -1}}
	AddRoundKey {
		round {Type I LastRead 7 FirstWrite -1}
		state {Type IO LastRead 8 FirstWrite 8}
		RoundKey {Type I LastRead 15 FirstWrite -1}}
	SubBytes {
		state {Type IO LastRead 8 FirstWrite 8}
		sbox {Type I LastRead -1 FirstWrite -1}}
	ShiftRows {
		state {Type IO LastRead 6 FirstWrite 6}}
	MixColumns {
		state {Type IO LastRead 3 FirstWrite 3}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "951", "Max" : "983"}
	, {"Name" : "Interval", "Min" : "952", "Max" : "984"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	key_0 { ap_none {  { key_0 in_data 0 32 } } }
	key_1 { ap_none {  { key_1 in_data 0 32 } } }
	key_2 { ap_none {  { key_2 in_data 0 32 } } }
	key_3 { ap_none {  { key_3 in_data 0 32 } } }
	inout_0 { ap_ovld {  { inout_0_i in_data 0 32 }  { inout_0_o out_data 1 32 }  { inout_0_o_ap_vld out_vld 1 1 } } }
	inout_1 { ap_ovld {  { inout_1_i in_data 0 32 }  { inout_1_o out_data 1 32 }  { inout_1_o_ap_vld out_vld 1 1 } } }
	inout_2 { ap_ovld {  { inout_2_i in_data 0 32 }  { inout_2_o out_data 1 32 }  { inout_2_o_ap_vld out_vld 1 1 } } }
	inout_3 { ap_ovld {  { inout_3_i in_data 0 32 }  { inout_3_o out_data 1 32 }  { inout_3_o_ap_vld out_vld 1 1 } } }
	iv_0 { ap_ovld {  { iv_0_i in_data 0 32 }  { iv_0_o out_data 1 32 }  { iv_0_o_ap_vld out_vld 1 1 } } }
	iv_1 { ap_ovld {  { iv_1_i in_data 0 32 }  { iv_1_o out_data 1 32 }  { iv_1_o_ap_vld out_vld 1 1 } } }
	iv_2 { ap_ovld {  { iv_2_i in_data 0 32 }  { iv_2_o out_data 1 32 }  { iv_2_o_ap_vld out_vld 1 1 } } }
	iv_3 { ap_ovld {  { iv_3_i in_data 0 32 }  { iv_3_o out_data 1 32 }  { iv_3_o_ap_vld out_vld 1 1 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
