set moduleName aes16_bidir
set isTopModule 1
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isFreeRunPipelineModule 0
set isPipelined 1
set pipeline_type function
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
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "5"],
		"CDFG" : "aes16_bidir",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "Aligned", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "204",
		"VariableLatency" : "0", "ExactLatency" : "212", "EstimateLatencyMin" : "212", "EstimateLatencyMax" : "212",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
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
					{"ID" : "5", "SubInstance" : "grp_AES_CTR_xcrypt_buffe_fu_395", "Port" : "sbox"},
					{"ID" : "3", "SubInstance" : "grp_KeyExpansion_fu_371", "Port" : "sbox"}]}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.ctx_RoundKey_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.ctx_Iv_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_KeyExpansion_fu_371", "Parent" : "0", "Child" : ["4"],
		"CDFG" : "KeyExpansion",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "88",
		"VariableLatency" : "0", "ExactLatency" : "87", "EstimateLatencyMin" : "87", "EstimateLatencyMax" : "87",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "RoundKey", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "Key_0_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "Key_1_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "Key_2_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "Key_3_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "Key_4_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "Key_5_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "Key_6_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "Key_7_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "Key_8_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "Key_9_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "Key_10_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "Key_11_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "Key_12_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "Key_13_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "Key_14_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "Key_15_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "sbox", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "4", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_KeyExpansion_fu_371.sbox_U", "Parent" : "3"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_AES_CTR_xcrypt_buffe_fu_395", "Parent" : "0", "Child" : ["6"],
		"CDFG" : "AES_CTR_xcrypt_buffe",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "Aligned", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "108",
		"VariableLatency" : "0", "ExactLatency" : "115", "EstimateLatencyMin" : "115", "EstimateLatencyMax" : "115",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "ctx_RoundKey", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "6", "SubInstance" : "grp_Cipher_fu_480", "Port" : "RoundKey"}]},
			{"Name" : "ctx_Iv", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "buf_0_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "buf_1_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "buf_2_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "buf_3_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "buf_4_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "buf_5_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "buf_6_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "buf_7_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "buf_8_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "buf_9_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "buf_10_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "buf_11_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "buf_12_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "buf_13_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "buf_14_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "buf_15_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "sbox", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "6", "SubInstance" : "grp_Cipher_fu_480", "Port" : "sbox"}]}]},
	{"ID" : "6", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_AES_CTR_xcrypt_buffe_fu_395.grp_Cipher_fu_480", "Parent" : "5", "Child" : ["7", "8", "9", "11"],
		"CDFG" : "Cipher",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "108",
		"VariableLatency" : "0", "ExactLatency" : "107", "EstimateLatencyMin" : "107", "EstimateLatencyMax" : "107",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "state_0_0_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_0_1_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_0_2_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_0_3_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_1_0_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_1_1_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_1_2_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_1_3_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_2_0_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_2_1_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_2_2_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_2_3_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_3_0_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_3_1_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_3_2_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_3_3_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "RoundKey", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "8", "SubInstance" : "grp_AddRoundKey_fu_184", "Port" : "RoundKey"}]},
			{"Name" : "sbox", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "9", "SubInstance" : "grp_SubBytes_fu_234", "Port" : "sbox"}]}]},
	{"ID" : "7", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_AES_CTR_xcrypt_buffe_fu_395.grp_Cipher_fu_480.grp_MixColumns_fu_164", "Parent" : "6",
		"CDFG" : "MixColumns",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "0", "ap_start" : "0", "ap_ready" : "1", "ap_done" : "0", "ap_continue" : "0", "ap_idle" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "1",
		"VariableLatency" : "0", "ExactLatency" : "0", "EstimateLatencyMin" : "0", "EstimateLatencyMax" : "0",
		"Combinational" : "1",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "state_0_0_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_0_1_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_0_2_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_0_3_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_1_0_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_1_1_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_1_2_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_1_3_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_2_0_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_2_1_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_2_2_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_2_3_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_3_0_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_3_1_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_3_2_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_3_3_read", "Type" : "None", "Direction" : "I"}]},
	{"ID" : "8", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_AES_CTR_xcrypt_buffe_fu_395.grp_Cipher_fu_480.grp_AddRoundKey_fu_184", "Parent" : "6",
		"CDFG" : "AddRoundKey",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "Aligned", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "8",
		"VariableLatency" : "0", "ExactLatency" : "8", "EstimateLatencyMin" : "8", "EstimateLatencyMax" : "8",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "1",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "round", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_0_0_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_0_1_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_0_2_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_0_3_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_1_0_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_1_1_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_1_2_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_1_3_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_2_0_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_2_1_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_2_2_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_2_3_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_3_0_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_3_1_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_3_2_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_3_3_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "RoundKey", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "9", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_AES_CTR_xcrypt_buffe_fu_395.grp_Cipher_fu_480.grp_SubBytes_fu_234", "Parent" : "6", "Child" : ["10"],
		"CDFG" : "SubBytes",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "Aligned", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "1",
		"VariableLatency" : "0", "ExactLatency" : "1", "EstimateLatencyMin" : "1", "EstimateLatencyMax" : "1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "1",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "state_0_0_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_0_1_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_0_2_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_0_3_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_1_0_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_1_1_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_1_2_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_1_3_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_2_0_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_2_1_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_2_2_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_2_3_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_3_0_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_3_1_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_3_2_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_3_3_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "sbox", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "10", "Level" : "4", "Path" : "`AUTOTB_DUT_INST.grp_AES_CTR_xcrypt_buffe_fu_395.grp_Cipher_fu_480.grp_SubBytes_fu_234.sbox_U", "Parent" : "9"},
	{"ID" : "11", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_AES_CTR_xcrypt_buffe_fu_395.grp_Cipher_fu_480.grp_ShiftRows_fu_256", "Parent" : "6",
		"CDFG" : "ShiftRows",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "0", "ap_start" : "0", "ap_ready" : "1", "ap_done" : "0", "ap_continue" : "0", "ap_idle" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "1",
		"VariableLatency" : "0", "ExactLatency" : "0", "EstimateLatencyMin" : "0", "EstimateLatencyMax" : "0",
		"Combinational" : "1",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "state_0_1_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_0_2_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_0_3_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_1_1_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_1_2_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_1_3_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_2_1_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_2_2_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_2_3_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_3_1_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_3_2_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "state_3_3_read", "Type" : "None", "Direction" : "I"}]}]}


set ArgLastReadFirstWriteLatency {
	aes16_bidir {
		key_0 {Type I LastRead 0 FirstWrite -1}
		key_1 {Type I LastRead 0 FirstWrite -1}
		key_2 {Type I LastRead 0 FirstWrite -1}
		key_3 {Type I LastRead 0 FirstWrite -1}
		inout_0 {Type IO LastRead 88 FirstWrite 203}
		inout_1 {Type IO LastRead 88 FirstWrite 203}
		inout_2 {Type IO LastRead 88 FirstWrite 203}
		inout_3 {Type IO LastRead 88 FirstWrite 203}
		iv_0 {Type IO LastRead 9 FirstWrite 212}
		iv_1 {Type IO LastRead 8 FirstWrite 211}
		iv_2 {Type IO LastRead 12 FirstWrite 212}
		iv_3 {Type IO LastRead 14 FirstWrite 212}
		sbox {Type I LastRead -1 FirstWrite -1}}
	KeyExpansion {
		RoundKey {Type O LastRead -1 FirstWrite 0}
		Key_0_read {Type I LastRead 0 FirstWrite -1}
		Key_1_read {Type I LastRead 0 FirstWrite -1}
		Key_2_read {Type I LastRead 1 FirstWrite -1}
		Key_3_read {Type I LastRead 1 FirstWrite -1}
		Key_4_read {Type I LastRead 2 FirstWrite -1}
		Key_5_read {Type I LastRead 2 FirstWrite -1}
		Key_6_read {Type I LastRead 3 FirstWrite -1}
		Key_7_read {Type I LastRead 3 FirstWrite -1}
		Key_8_read {Type I LastRead 4 FirstWrite -1}
		Key_9_read {Type I LastRead 4 FirstWrite -1}
		Key_10_read {Type I LastRead 5 FirstWrite -1}
		Key_11_read {Type I LastRead 5 FirstWrite -1}
		Key_12_read {Type I LastRead 3 FirstWrite -1}
		Key_13_read {Type I LastRead 0 FirstWrite -1}
		Key_14_read {Type I LastRead 1 FirstWrite -1}
		Key_15_read {Type I LastRead 2 FirstWrite -1}
		sbox {Type I LastRead -1 FirstWrite -1}}
	AES_CTR_xcrypt_buffe {
		ctx_RoundKey {Type I LastRead 8 FirstWrite -1}
		ctx_Iv {Type IO LastRead 8 FirstWrite 8}
		buf_0_read {Type I LastRead 107 FirstWrite -1}
		buf_1_read {Type I LastRead 107 FirstWrite -1}
		buf_2_read {Type I LastRead 107 FirstWrite -1}
		buf_3_read {Type I LastRead 107 FirstWrite -1}
		buf_4_read {Type I LastRead 107 FirstWrite -1}
		buf_5_read {Type I LastRead 107 FirstWrite -1}
		buf_6_read {Type I LastRead 107 FirstWrite -1}
		buf_7_read {Type I LastRead 107 FirstWrite -1}
		buf_8_read {Type I LastRead 107 FirstWrite -1}
		buf_9_read {Type I LastRead 107 FirstWrite -1}
		buf_10_read {Type I LastRead 107 FirstWrite -1}
		buf_11_read {Type I LastRead 107 FirstWrite -1}
		buf_12_read {Type I LastRead 107 FirstWrite -1}
		buf_13_read {Type I LastRead 107 FirstWrite -1}
		buf_14_read {Type I LastRead 107 FirstWrite -1}
		buf_15_read {Type I LastRead 107 FirstWrite -1}
		sbox {Type I LastRead -1 FirstWrite -1}}
	Cipher {
		state_0_0_read {Type I LastRead 0 FirstWrite -1}
		state_0_1_read {Type I LastRead 0 FirstWrite -1}
		state_0_2_read {Type I LastRead 0 FirstWrite -1}
		state_0_3_read {Type I LastRead 0 FirstWrite -1}
		state_1_0_read {Type I LastRead 0 FirstWrite -1}
		state_1_1_read {Type I LastRead 0 FirstWrite -1}
		state_1_2_read {Type I LastRead 0 FirstWrite -1}
		state_1_3_read {Type I LastRead 0 FirstWrite -1}
		state_2_0_read {Type I LastRead 0 FirstWrite -1}
		state_2_1_read {Type I LastRead 0 FirstWrite -1}
		state_2_2_read {Type I LastRead 0 FirstWrite -1}
		state_2_3_read {Type I LastRead 0 FirstWrite -1}
		state_3_0_read {Type I LastRead 0 FirstWrite -1}
		state_3_1_read {Type I LastRead 0 FirstWrite -1}
		state_3_2_read {Type I LastRead 0 FirstWrite -1}
		state_3_3_read {Type I LastRead 0 FirstWrite -1}
		RoundKey {Type I LastRead 8 FirstWrite -1}
		sbox {Type I LastRead -1 FirstWrite -1}}
	MixColumns {
		state_0_0_read {Type I LastRead 0 FirstWrite -1}
		state_0_1_read {Type I LastRead 0 FirstWrite -1}
		state_0_2_read {Type I LastRead 0 FirstWrite -1}
		state_0_3_read {Type I LastRead 0 FirstWrite -1}
		state_1_0_read {Type I LastRead 0 FirstWrite -1}
		state_1_1_read {Type I LastRead 0 FirstWrite -1}
		state_1_2_read {Type I LastRead 0 FirstWrite -1}
		state_1_3_read {Type I LastRead 0 FirstWrite -1}
		state_2_0_read {Type I LastRead 0 FirstWrite -1}
		state_2_1_read {Type I LastRead 0 FirstWrite -1}
		state_2_2_read {Type I LastRead 0 FirstWrite -1}
		state_2_3_read {Type I LastRead 0 FirstWrite -1}
		state_3_0_read {Type I LastRead 0 FirstWrite -1}
		state_3_1_read {Type I LastRead 0 FirstWrite -1}
		state_3_2_read {Type I LastRead 0 FirstWrite -1}
		state_3_3_read {Type I LastRead 0 FirstWrite -1}}
	AddRoundKey {
		round {Type I LastRead 0 FirstWrite -1}
		state_0_0_read {Type I LastRead 7 FirstWrite -1}
		state_0_1_read {Type I LastRead 7 FirstWrite -1}
		state_0_2_read {Type I LastRead 7 FirstWrite -1}
		state_0_3_read {Type I LastRead 7 FirstWrite -1}
		state_1_0_read {Type I LastRead 7 FirstWrite -1}
		state_1_1_read {Type I LastRead 7 FirstWrite -1}
		state_1_2_read {Type I LastRead 7 FirstWrite -1}
		state_1_3_read {Type I LastRead 7 FirstWrite -1}
		state_2_0_read {Type I LastRead 7 FirstWrite -1}
		state_2_1_read {Type I LastRead 7 FirstWrite -1}
		state_2_2_read {Type I LastRead 7 FirstWrite -1}
		state_2_3_read {Type I LastRead 7 FirstWrite -1}
		state_3_0_read {Type I LastRead 7 FirstWrite -1}
		state_3_1_read {Type I LastRead 7 FirstWrite -1}
		state_3_2_read {Type I LastRead 7 FirstWrite -1}
		state_3_3_read {Type I LastRead 7 FirstWrite -1}
		RoundKey {Type I LastRead 8 FirstWrite -1}}
	SubBytes {
		state_0_0_read {Type I LastRead 0 FirstWrite -1}
		state_0_1_read {Type I LastRead 0 FirstWrite -1}
		state_0_2_read {Type I LastRead 0 FirstWrite -1}
		state_0_3_read {Type I LastRead 0 FirstWrite -1}
		state_1_0_read {Type I LastRead 0 FirstWrite -1}
		state_1_1_read {Type I LastRead 0 FirstWrite -1}
		state_1_2_read {Type I LastRead 0 FirstWrite -1}
		state_1_3_read {Type I LastRead 0 FirstWrite -1}
		state_2_0_read {Type I LastRead 0 FirstWrite -1}
		state_2_1_read {Type I LastRead 0 FirstWrite -1}
		state_2_2_read {Type I LastRead 0 FirstWrite -1}
		state_2_3_read {Type I LastRead 0 FirstWrite -1}
		state_3_0_read {Type I LastRead 0 FirstWrite -1}
		state_3_1_read {Type I LastRead 0 FirstWrite -1}
		state_3_2_read {Type I LastRead 0 FirstWrite -1}
		state_3_3_read {Type I LastRead 0 FirstWrite -1}
		sbox {Type I LastRead -1 FirstWrite -1}}
	ShiftRows {
		state_0_1_read {Type I LastRead 0 FirstWrite -1}
		state_0_2_read {Type I LastRead 0 FirstWrite -1}
		state_0_3_read {Type I LastRead 0 FirstWrite -1}
		state_1_1_read {Type I LastRead 0 FirstWrite -1}
		state_1_2_read {Type I LastRead 0 FirstWrite -1}
		state_1_3_read {Type I LastRead 0 FirstWrite -1}
		state_2_1_read {Type I LastRead 0 FirstWrite -1}
		state_2_2_read {Type I LastRead 0 FirstWrite -1}
		state_2_3_read {Type I LastRead 0 FirstWrite -1}
		state_3_1_read {Type I LastRead 0 FirstWrite -1}
		state_3_2_read {Type I LastRead 0 FirstWrite -1}
		state_3_3_read {Type I LastRead 0 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "212", "Max" : "212"}
	, {"Name" : "Interval", "Min" : "204", "Max" : "204"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
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
