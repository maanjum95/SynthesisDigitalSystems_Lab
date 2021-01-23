set moduleName KeyExpansion
set isTopModule 0
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isFreeRunPipelineModule 0
set isPipelined 0
set pipeline_type function
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {KeyExpansion}
set C_modelType { void 0 }
set C_modelArgList {
	{ RoundKey int 8 regular {array 176 { 0 0 } 0 1 }  }
	{ Key_0_read int 8 regular  }
	{ Key_1_read int 8 regular  }
	{ Key_2_read int 8 regular  }
	{ Key_3_read int 8 regular  }
	{ Key_4_read int 8 regular  }
	{ Key_5_read int 8 regular  }
	{ Key_6_read int 8 regular  }
	{ Key_7_read int 8 regular  }
	{ Key_8_read int 8 regular  }
	{ Key_9_read int 8 regular  }
	{ Key_10_read int 8 regular  }
	{ Key_11_read int 8 regular  }
	{ Key_12_read int 8 regular  }
	{ Key_13_read int 8 regular  }
	{ Key_14_read int 8 regular  }
	{ Key_15_read int 8 regular  }
}
set C_modelArgMapList {[ 
	{ "Name" : "RoundKey", "interface" : "memory", "bitwidth" : 8, "direction" : "WRITEONLY"} , 
 	{ "Name" : "Key_0_read", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "Key_1_read", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "Key_2_read", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "Key_3_read", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "Key_4_read", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "Key_5_read", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "Key_6_read", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "Key_7_read", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "Key_8_read", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "Key_9_read", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "Key_10_read", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "Key_11_read", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "Key_12_read", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "Key_13_read", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "Key_14_read", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "Key_15_read", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY"} ]}
# RTL Port declarations: 
set portNum 30
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ RoundKey_address0 sc_out sc_lv 8 signal 0 } 
	{ RoundKey_ce0 sc_out sc_logic 1 signal 0 } 
	{ RoundKey_we0 sc_out sc_logic 1 signal 0 } 
	{ RoundKey_d0 sc_out sc_lv 8 signal 0 } 
	{ RoundKey_address1 sc_out sc_lv 8 signal 0 } 
	{ RoundKey_ce1 sc_out sc_logic 1 signal 0 } 
	{ RoundKey_we1 sc_out sc_logic 1 signal 0 } 
	{ RoundKey_d1 sc_out sc_lv 8 signal 0 } 
	{ Key_0_read sc_in sc_lv 8 signal 1 } 
	{ Key_1_read sc_in sc_lv 8 signal 2 } 
	{ Key_2_read sc_in sc_lv 8 signal 3 } 
	{ Key_3_read sc_in sc_lv 8 signal 4 } 
	{ Key_4_read sc_in sc_lv 8 signal 5 } 
	{ Key_5_read sc_in sc_lv 8 signal 6 } 
	{ Key_6_read sc_in sc_lv 8 signal 7 } 
	{ Key_7_read sc_in sc_lv 8 signal 8 } 
	{ Key_8_read sc_in sc_lv 8 signal 9 } 
	{ Key_9_read sc_in sc_lv 8 signal 10 } 
	{ Key_10_read sc_in sc_lv 8 signal 11 } 
	{ Key_11_read sc_in sc_lv 8 signal 12 } 
	{ Key_12_read sc_in sc_lv 8 signal 13 } 
	{ Key_13_read sc_in sc_lv 8 signal 14 } 
	{ Key_14_read sc_in sc_lv 8 signal 15 } 
	{ Key_15_read sc_in sc_lv 8 signal 16 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "RoundKey_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "RoundKey", "role": "address0" }} , 
 	{ "name": "RoundKey_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "RoundKey", "role": "ce0" }} , 
 	{ "name": "RoundKey_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "RoundKey", "role": "we0" }} , 
 	{ "name": "RoundKey_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "RoundKey", "role": "d0" }} , 
 	{ "name": "RoundKey_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "RoundKey", "role": "address1" }} , 
 	{ "name": "RoundKey_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "RoundKey", "role": "ce1" }} , 
 	{ "name": "RoundKey_we1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "RoundKey", "role": "we1" }} , 
 	{ "name": "RoundKey_d1", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "RoundKey", "role": "d1" }} , 
 	{ "name": "Key_0_read", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "Key_0_read", "role": "default" }} , 
 	{ "name": "Key_1_read", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "Key_1_read", "role": "default" }} , 
 	{ "name": "Key_2_read", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "Key_2_read", "role": "default" }} , 
 	{ "name": "Key_3_read", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "Key_3_read", "role": "default" }} , 
 	{ "name": "Key_4_read", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "Key_4_read", "role": "default" }} , 
 	{ "name": "Key_5_read", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "Key_5_read", "role": "default" }} , 
 	{ "name": "Key_6_read", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "Key_6_read", "role": "default" }} , 
 	{ "name": "Key_7_read", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "Key_7_read", "role": "default" }} , 
 	{ "name": "Key_8_read", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "Key_8_read", "role": "default" }} , 
 	{ "name": "Key_9_read", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "Key_9_read", "role": "default" }} , 
 	{ "name": "Key_10_read", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "Key_10_read", "role": "default" }} , 
 	{ "name": "Key_11_read", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "Key_11_read", "role": "default" }} , 
 	{ "name": "Key_12_read", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "Key_12_read", "role": "default" }} , 
 	{ "name": "Key_13_read", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "Key_13_read", "role": "default" }} , 
 	{ "name": "Key_14_read", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "Key_14_read", "role": "default" }} , 
 	{ "name": "Key_15_read", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "Key_15_read", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1"],
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
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.sbox_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
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
		sbox {Type I LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "87", "Max" : "87"}
	, {"Name" : "Interval", "Min" : "88", "Max" : "88"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	RoundKey { ap_memory {  { RoundKey_address0 mem_address 1 8 }  { RoundKey_ce0 mem_ce 1 1 }  { RoundKey_we0 mem_we 1 1 }  { RoundKey_d0 mem_din 1 8 }  { RoundKey_address1 MemPortADDR2 1 8 }  { RoundKey_ce1 MemPortCE2 1 1 }  { RoundKey_we1 MemPortWE2 1 1 }  { RoundKey_d1 MemPortDIN2 1 8 } } }
	Key_0_read { ap_none {  { Key_0_read in_data 0 8 } } }
	Key_1_read { ap_none {  { Key_1_read in_data 0 8 } } }
	Key_2_read { ap_none {  { Key_2_read in_data 0 8 } } }
	Key_3_read { ap_none {  { Key_3_read in_data 0 8 } } }
	Key_4_read { ap_none {  { Key_4_read in_data 0 8 } } }
	Key_5_read { ap_none {  { Key_5_read in_data 0 8 } } }
	Key_6_read { ap_none {  { Key_6_read in_data 0 8 } } }
	Key_7_read { ap_none {  { Key_7_read in_data 0 8 } } }
	Key_8_read { ap_none {  { Key_8_read in_data 0 8 } } }
	Key_9_read { ap_none {  { Key_9_read in_data 0 8 } } }
	Key_10_read { ap_none {  { Key_10_read in_data 0 8 } } }
	Key_11_read { ap_none {  { Key_11_read in_data 0 8 } } }
	Key_12_read { ap_none {  { Key_12_read in_data 0 8 } } }
	Key_13_read { ap_none {  { Key_13_read in_data 0 8 } } }
	Key_14_read { ap_none {  { Key_14_read in_data 0 8 } } }
	Key_15_read { ap_none {  { Key_15_read in_data 0 8 } } }
}
