BUILD_DIR?=build
INSTALL_DIR?=$(BUILD_DIR)/installed

VERILATOR_ROOT?=/usr/local/labs/SDS/current/common/tools/verilator/share/verilator
SOL?=sol1

CC=gcc
CXX=g++
LD=c++

EXE=cc_aes_test
SC_EXE=sc_aes_test

OBJFILES=$(BUILD_DIR)/aes_test.o $(BUILD_DIR)/top_aes.o $(BUILD_DIR)/aes.o

RTL_DIR=aes_hls_prj/$(SOL)/syn/verilog
TOP=aes16_bidir

SYSTEMC_LIBDIR=$(SYSTEMC)/lib
SYSTEMC_INCLUDE=$(SYSTEMC)/include

#MODEL_CFLAGS=-O3 -g3 -std=gnu++17
MODEL_CFLAGS=-O3 -g3 -std=c++17

all:  clean $(BUILD_DIR) test vrtl sc_test install

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/aes.o: c_src/aes.c
	$(CC) -g -o $@ -c $^

$(BUILD_DIR)/top_aes.o: hls/top_aes.c
	$(CC) -g -Ic_src -I. -Ihls -o $@ -c $^
	
$(BUILD_DIR)/aes_test.o: testbench/aes_test.c
	$(CC) -g -Ic_src -I. -Ihls -o $@ -c $^		
	
$(BUILD_DIR)/$(EXE): $(OBJFILES)
	$(CXX) -g -Ic_src -I. -Ihls $^ -o $@ 

	
test: $(BUILD_DIR) $(BUILD_DIR)/$(EXE)
	@echo  "##############################################################"
	@echo  "#                         C TEST                             #"
	$(BUILD_DIR)/$(EXE)
	@echo  "##############################################################"
	
shared: $(BUILD_DIR)/libV$(TOP).so

$(RTL_DIR).patched: $(RTL_DIR)
	@echo "Patching RTL files ... $(TOP)"
	mkdir -p $(RTL_DIR).patched
	cp -r $(RTL_DIR)/* $(RTL_DIR).patched/
	python3 scripts/patch_romreaders.py -dir $(RTL_DIR).patched -abs 1
	
vrtl: $(BUILD_DIR) $(RTL_DIR).patched
	@echo  "##############################################################"
	@echo  "#                          RTL                               #"
	@echo "Building the (Verilator)RTL model... $(TOP)"
	mkdir -p $(BUILD_DIR)/vrtl
	${VERILATOR_ROOT}/../../bin/verilator_bin --sc -O3 --top-module $(TOP) \
		-CFLAGS "$(MODEL_CFLAGS) -fPIC" \
		+define+VERILATOR \
		--unroll-count 256 \
		-Werror-PINMISSING \
		-Wno-fatal \
		-Wno-PINCONNECTEMPTY \
		-Wno-ASSIGNDLY \
		-Wno-DECLFILENAME \
		-Wno-UNUSED \
		-Wno-UNOPTFLAT \
		-Wno-style \
		-Wno-CASEINCOMPLETE \
		-Wno-LITENDIAN \
		-Wno-UNOPT \
		-Wno-WIDTH \
		-Wno-BLKANDNBLK \
		$(RTL_DIR).patched/*.v \
		--Mdir $(BUILD_DIR)/vrtl
	@echo  "... Done: RTL model $(TOP)"
	@echo  "##############################################################"

$(BUILD_DIR)/vrtl/V$(TOP).h: vrtl	
	
$(BUILD_DIR)/libV$(TOP).so: $(BUILD_DIR)/vrtl/V$(TOP)__ALL.a $(BUILD_DIR)/vrtl/verilated.o
	$(CXX) -shared -o $@ -Wl,--whole-archive $^ -Wl,--no-whole-archive
	
$(BUILD_DIR)/vrtl/V$(TOP)__ALL.a: $(BUILD_DIR)/vrtl/V$(TOP).h
	make -j4 -C $(BUILD_DIR)/vrtl -f V$(TOP).mk V$(TOP)__ALL.a SYSTEMC_INCLUDE=$(SYSTEMC_INCLUDE) SYTEMC_LIBDIR=$(SYSTEMC_LIBDIR) SYSTEMC=$(SYSTEMC)

$(BUILD_DIR)/vrtl/verilated.o: $(BUILD_DIR)/vrtl/V$(TOP).h
	make -j4 -C $(BUILD_DIR)/vrtl -f V$(TOP).mk verilated.o SYSTEMC_INCLUDE=$(SYSTEMC_INCLUDE) SYTEMC_LIBDIR=$(SYSTEMC_LIBDIR) SYSTEMC=$(SYSTEMC)

$(BUILD_DIR)/sc_aes_test.o: testbench/system_c/sc_aes_test.cpp
	$(CXX) $(MODEL_CFLAGS) -I$(BUILD_DIR)/vrtl -I$(SYSTEMC)/include -I$(VERILATOR_ROOT)/include -I$(VERILATOR_ROOT)/share/verilator/include -c $^ -o $@
	
$(BUILD_DIR)/$(SC_EXE): $(BUILD_DIR)/libV$(TOP).so $(BUILD_DIR)/sc_aes_test.o
	$(CXX) $(MODEL_CFLAGS) $(BUILD_DIR)/sc_aes_test.o -o $@ -L$(SYSTEMC)/lib -lsystemc -Wl,-rpath=$(BUILD_DIR) -L$(BUILD_DIR) -lV$(TOP)

sc_test: vrtl $(BUILD_DIR)/$(SC_EXE)
	@echo  "##############################################################"
	@echo  "#                       VRTL TEST                            #"
	$(BUILD_DIR)/$(SC_EXE)
	@echo  "##############################################################"

$(INSTALL_DIR): $(BUILD_DIR)
	mkdir -p $(INSTALL_DIR)
	mkdir -p $(INSTALL_DIR)/lib
	mkdir -p $(INSTALL_DIR)/include
	
install: $(INSTALL_DIR) $(BUILD_DIR)/libV$(TOP).so $(BUILD_DIR)/vrtl/V$(TOP).h
	@echo  "##############################################################"
	@echo  "#                         INSTALL                            #"
	cp $(BUILD_DIR)/vrtl/*.h $(INSTALL_DIR)/include
	cp $(BUILD_DIR)/libV$(TOP).so $(INSTALL_DIR)/lib
	@echo  "##############################################################"
	
clean:
	rm -r -f $(BUILD_DIR) $(RTL_DIR).patched $(INSTALL_DIR) log/ ./*.dat *.vcd
	


