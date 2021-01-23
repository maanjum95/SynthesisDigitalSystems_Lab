
set TopModule "aes16_bidir"
set ClockPeriod 10
set ClockList ap_clk
set HasVivadoClockPeriod 0
set CombLogicFlag 0
set PipelineFlag 1
set DataflowTaskPipelineFlag 1
set TrivialPipelineFlag 0
set noPortSwitchingFlag 1
set FloatingPointFlag 0
set FftOrFirFlag 0
set NbRWValue 0
set intNbAccess 0
set NewDSPMapping 1
set HasDSPModule 0
set ResetLevelFlag 1
set ResetStyle control
set ResetSyncFlag 1
set ResetRegisterFlag 0
set ResetVariableFlag 0
set FsmEncStyle onehot
set MaxFanout 0
set RtlPrefix {}
set ExtraCCFlags {}
set ExtraCLdFlags {}
set SynCheckOptions {}
set PresynOptions {}
set PreprocOptions {}
set SchedOptions {}
set BindOptions {}
set RtlGenOptions {}
set RtlWriterOptions {}
set CbcGenFlag {}
set CasGenFlag {}
set CasMonitorFlag {}
set AutoSimOptions {}
set ExportMCPathFlag 0
set SCTraceFileName mytrace
set SCTraceFileFormat vcd
set SCTraceOption all
set TargetInfo xc7s15:-ftgb196:-2
set SourceFiles {sc {} c {../../hls/top_aes.c ../../c_src/aes.c}}
set SourceFlags {sc {} c {{} {}}}
set DirectiveFile /nas/ei/share/TUEIEDA/LabSDS/SS20/ge29noy/labsds/aes_hls/aes_hls_prj/sol2/sol2.directive
set TBFiles {verilog {../../testbench/aes_test.c ../../testbench/out.gold.dat} bc {../../testbench/aes_test.c ../../testbench/out.gold.dat} sc {../../testbench/aes_test.c ../../testbench/out.gold.dat} vhdl {../../testbench/aes_test.c ../../testbench/out.gold.dat} c {} cas {../../testbench/aes_test.c ../../testbench/out.gold.dat}}
set SpecLanguage C
set TVInFiles {bc {} c {} sc {} cas {} vhdl {} verilog {}}
set TVOutFiles {bc {} c {} sc {} cas {} vhdl {} verilog {}}
set TBTops {verilog {} bc {} sc {} vhdl {} c {} cas {}}
set TBInstNames {verilog {} bc {} sc {} vhdl {} c {} cas {}}
set XDCFiles {}
set ExtraGlobalOptions {"area_timing" 1 "clock_gate" 1 "impl_flow" map "power_gate" 0}
set TBTVFileNotFound {}
set AppFile ../vivado_hls.app
set ApsFile sol2.aps
set AvePath ../..
set DefaultPlatform DefaultPlatform
set multiClockList {}
set SCPortClockMap {}
set intNbAccess 0
set PlatformFiles {{DefaultPlatform {xilinx/spartan7/spartan7 xilinx/spartan7/spartan7_fpv6}}}
set HPFPO 0
