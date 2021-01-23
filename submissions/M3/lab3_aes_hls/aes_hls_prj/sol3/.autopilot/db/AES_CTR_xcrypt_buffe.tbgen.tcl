set moduleName AES_CTR_xcrypt_buffe
set isTopModule 0
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
set C_modelName {AES_CTR_xcrypt_buffe}
set C_modelType { void 0 }
set C_modelArgList {
	{ ctx_RoundKey int 8 regular {array 176 { 1 1 } 1 1 }  }
	{ ctx_Iv int 8 regular {array 16 { 2 3 } 1 1 }  }
	{ buf_r int 8 regular {array 16 { 2 2 } 1 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "ctx_RoundKey", "interface" : "memory", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "ctx_Iv", "interface" : "memory", "bitwidth" : 8, "direction" : "READWRITE"} , 
 	{ "Name" : "buf_r", "interface" : "memory", "bitwidth" : 8, "direction" : "READWRITE"} ]}
# RTL Port declarations: 
set portNum 27
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ ctx_RoundKey_address0 sc_out sc_lv 8 signal 0 } 
	{ ctx_RoundKey_ce0 sc_out sc_logic 1 signal 0 } 
	{ ctx_RoundKey_q0 sc_in sc_lv 8 signal 0 } 
	{ ctx_RoundKey_address1 sc_out sc_lv 8 signal 0 } 
	{ ctx_RoundKey_ce1 sc_out sc_logic 1 signal 0 } 
	{ ctx_RoundKey_q1 sc_in sc_lv 8 signal 0 } 
	{ ctx_Iv_address0 sc_out sc_lv 4 signal 1 } 
	{ ctx_Iv_ce0 sc_out sc_logic 1 signal 1 } 
	{ ctx_Iv_we0 sc_out sc_logic 1 signal 1 } 
	{ ctx_Iv_d0 sc_out sc_lv 8 signal 1 } 
	{ ctx_Iv_q0 sc_in sc_lv 8 signal 1 } 
	{ buf_r_address0 sc_out sc_lv 4 signal 2 } 
	{ buf_r_ce0 sc_out sc_logic 1 signal 2 } 
	{ buf_r_we0 sc_out sc_logic 1 signal 2 } 
	{ buf_r_d0 sc_out sc_lv 8 signal 2 } 
	{ buf_r_q0 sc_in sc_lv 8 signal 2 } 
	{ buf_r_address1 sc_out sc_lv 4 signal 2 } 
	{ buf_r_ce1 sc_out sc_logic 1 signal 2 } 
	{ buf_r_we1 sc_out sc_logic 1 signal 2 } 
	{ buf_r_d1 sc_out sc_lv 8 signal 2 } 
	{ buf_r_q1 sc_in sc_lv 8 signal 2 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "ctx_RoundKey_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "ctx_RoundKey", "role": "address0" }} , 
 	{ "name": "ctx_RoundKey_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctx_RoundKey", "role": "ce0" }} , 
 	{ "name": "ctx_RoundKey_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "ctx_RoundKey", "role": "q0" }} , 
 	{ "name": "ctx_RoundKey_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "ctx_RoundKey", "role": "address1" }} , 
 	{ "name": "ctx_RoundKey_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctx_RoundKey", "role": "ce1" }} , 
 	{ "name": "ctx_RoundKey_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "ctx_RoundKey", "role": "q1" }} , 
 	{ "name": "ctx_Iv_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "ctx_Iv", "role": "address0" }} , 
 	{ "name": "ctx_Iv_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctx_Iv", "role": "ce0" }} , 
 	{ "name": "ctx_Iv_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctx_Iv", "role": "we0" }} , 
 	{ "name": "ctx_Iv_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "ctx_Iv", "role": "d0" }} , 
 	{ "name": "ctx_Iv_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "ctx_Iv", "role": "q0" }} , 
 	{ "name": "buf_r_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "buf_r", "role": "address0" }} , 
 	{ "name": "buf_r_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buf_r", "role": "ce0" }} , 
 	{ "name": "buf_r_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buf_r", "role": "we0" }} , 
 	{ "name": "buf_r_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "buf_r", "role": "d0" }} , 
 	{ "name": "buf_r_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "buf_r", "role": "q0" }} , 
 	{ "name": "buf_r_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "buf_r", "role": "address1" }} , 
 	{ "name": "buf_r_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buf_r", "role": "ce1" }} , 
 	{ "name": "buf_r_we1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buf_r", "role": "we1" }} , 
 	{ "name": "buf_r_d1", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "buf_r", "role": "d1" }} , 
 	{ "name": "buf_r_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "buf_r", "role": "q1" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "6", "7"],
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
					{"ID" : "3", "SubInstance" : "grp_AddRoundKey_fu_551", "Port" : "RoundKey"}]},
			{"Name" : "ctx_Iv", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "buf_r", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "sbox", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "4", "SubInstance" : "grp_SubBytes_fu_570", "Port" : "sbox"}]}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.buffer_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.x_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_AddRoundKey_fu_551", "Parent" : "0",
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
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_SubBytes_fu_570", "Parent" : "0", "Child" : ["5"],
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
	{"ID" : "5", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_SubBytes_fu_570.sbox_U", "Parent" : "4"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_ShiftRows_fu_577", "Parent" : "0",
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
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_MixColumns_fu_582", "Parent" : "0",
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
			{"Name" : "state", "Type" : "Memory", "Direction" : "IO"}]}]}


set ArgLastReadFirstWriteLatency {
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
	{"Name" : "Latency", "Min" : "790", "Max" : "822"}
	, {"Name" : "Interval", "Min" : "790", "Max" : "822"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	ctx_RoundKey { ap_memory {  { ctx_RoundKey_address0 mem_address 1 8 }  { ctx_RoundKey_ce0 mem_ce 1 1 }  { ctx_RoundKey_q0 mem_dout 0 8 }  { ctx_RoundKey_address1 MemPortADDR2 1 8 }  { ctx_RoundKey_ce1 MemPortCE2 1 1 }  { ctx_RoundKey_q1 MemPortDOUT2 0 8 } } }
	ctx_Iv { ap_memory {  { ctx_Iv_address0 mem_address 1 4 }  { ctx_Iv_ce0 mem_ce 1 1 }  { ctx_Iv_we0 mem_we 1 1 }  { ctx_Iv_d0 mem_din 1 8 }  { ctx_Iv_q0 mem_dout 0 8 } } }
	buf_r { ap_memory {  { buf_r_address0 mem_address 1 4 }  { buf_r_ce0 mem_ce 1 1 }  { buf_r_we0 mem_we 1 1 }  { buf_r_d0 mem_din 1 8 }  { buf_r_q0 mem_dout 0 8 }  { buf_r_address1 MemPortADDR2 1 4 }  { buf_r_ce1 MemPortCE2 1 1 }  { buf_r_we1 MemPortWE2 1 1 }  { buf_r_d1 MemPortDIN2 1 8 }  { buf_r_q1 MemPortDOUT2 0 8 } } }
}
