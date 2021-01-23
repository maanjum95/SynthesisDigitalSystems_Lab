#include "Vaes16_bidir.h"
#include "aes_stim.h"
#include "systemc.h"
#include "stdio.h"
#include <cstdlib>

dat_t key = {
    (uint8_t)0x2b, (uint8_t)0x7e, (uint8_t)0x15, (uint8_t)0x16,
    (uint8_t)0x28, (uint8_t)0xae, (uint8_t)0xd2, (uint8_t)0xa6,
    (uint8_t)0xab, (uint8_t)0xf7, (uint8_t)0x15, (uint8_t)0x88,
    (uint8_t)0x09, (uint8_t)0xcf, (uint8_t)0x4f, (uint8_t)0x3c};
      //{0x16157e2b, 0xa6d2ae28, 0x8815f7ab, 0x3c4fcf09};
dat_t ptx = {
    (uint8_t)0x6b, (uint8_t)0xc1, (uint8_t)0xbe, (uint8_t)0xe2,
    (uint8_t)0x2e, (uint8_t)0x40, (uint8_t)0x9f, (uint8_t)0x96,
    (uint8_t)0xe9, (uint8_t)0x3d, (uint8_t)0x7e, (uint8_t)0x11,
    (uint8_t)0x73, (uint8_t)0x93, (uint8_t)0x17, (uint8_t)0x2a};
    
dat_t iv = {
    (uint8_t)0x55, (uint8_t)0x55, (uint8_t)0x55, (uint8_t)0x55,
    (uint8_t)0x55, (uint8_t)0x55, (uint8_t)0x55, (uint8_t)0x55,
    (uint8_t)0x00, (uint8_t)0x00, (uint8_t)0x00, (uint8_t)0x00,
    (uint8_t)0x00, (uint8_t)0x00, (uint8_t)0x00, (uint8_t)0x00};
    
dat_t encr ={};
dat_t decr ={};
//{0x16157e2b, 0xa6d2ae28, 0x8815f7ab, 0x3c4fcf09};

int sc_main(int argc, char** argv) {
    FILE         *fp;
    Verilated::commandArgs(argc, argv);
    
    //Clock
    sc_clock clk ("TestClock", 10, SC_NS, 0.5);
    //sc_clock clk; //("TestClock", 10, SC_NS,0.5, 1, SC_NS);
    //sc_clock clk ("my_clock",1,0.5);
    
    //Nets
    sc_signal<bool> ap_rst;
    sc_signal<bool> ap_start;
    sc_signal<bool> ap_done;
    sc_signal<bool> ap_idle;
    sc_signal<bool> ap_ready;
    sc_signal<bool> inout_0_o_ap_vld;
    sc_signal<bool> inout_1_o_ap_vld;
    sc_signal<bool> inout_2_o_ap_vld;
    sc_signal<bool> inout_3_o_ap_vld;
    sc_signal<uint32_t> key_0;
    sc_signal<uint32_t> key_1;
    sc_signal<uint32_t> key_2;
    sc_signal<uint32_t> key_3;
    sc_signal<uint32_t> inout_0_i;
    sc_signal<uint32_t> inout_0_o;
    sc_signal<uint32_t> inout_1_i;
    sc_signal<uint32_t> inout_1_o;
    sc_signal<uint32_t> inout_2_i;
    sc_signal<uint32_t> inout_2_o;
    sc_signal<uint32_t> inout_3_i;
    sc_signal<uint32_t> inout_3_o;
    sc_signal<uint32_t> iv_0_i;
    sc_signal<uint32_t> iv_1_i;
    sc_signal<uint32_t> iv_2_i;
    sc_signal<uint32_t> iv_3_i;
    sc_signal<uint32_t> iv_0_o;
    sc_signal<uint32_t> iv_1_o;
    sc_signal<uint32_t> iv_2_o;
    sc_signal<uint32_t> iv_3_o;
    sc_signal<bool> iv_0_o_ap_vld;
    sc_signal<bool> iv_1_o_ap_vld;
    sc_signal<bool> iv_2_o_ap_vld;
    sc_signal<bool> iv_3_o_ap_vld;
    
    Vaes16_bidir* DUT = new Vaes16_bidir("aes16top");
    //Mapping DUT
    DUT->ap_clk(clk);
    DUT->ap_rst(ap_rst);
    DUT->ap_start(ap_start);
    DUT->ap_done(ap_done);
    DUT->ap_idle(ap_idle);
    DUT->ap_ready(ap_ready);
    
    DUT->inout_0_o_ap_vld(inout_0_o_ap_vld);
    DUT->inout_1_o_ap_vld(inout_1_o_ap_vld);
    DUT->inout_2_o_ap_vld(inout_2_o_ap_vld);
    DUT->inout_3_o_ap_vld(inout_3_o_ap_vld);
    
    DUT->key_0(key_0);
    DUT->key_1(key_1);
    DUT->key_2(key_2);
    DUT->key_3(key_3);
    
    DUT->inout_0_i(inout_0_i);
    DUT->inout_1_i(inout_1_i);
    DUT->inout_2_i(inout_2_i);
    DUT->inout_3_i(inout_3_i);
    DUT->inout_0_o(inout_0_o);
    DUT->inout_1_o(inout_1_o);
    DUT->inout_2_o(inout_2_o);
    DUT->inout_3_o(inout_3_o);
    
    DUT->iv_0_i(iv_0_i);
    DUT->iv_1_i(iv_1_i);
    DUT->iv_2_i(iv_2_i);
    DUT->iv_3_i(iv_3_i);
    DUT->iv_0_o(iv_0_o);
    DUT->iv_1_o(iv_1_o);
    DUT->iv_2_o(iv_2_o);
    DUT->iv_3_o(iv_3_o);
    
    DUT->iv_0_o_ap_vld(iv_0_o_ap_vld);
    DUT->iv_1_o_ap_vld(iv_1_o_ap_vld);
    DUT->iv_2_o_ap_vld(iv_2_o_ap_vld);
    DUT->iv_3_o_ap_vld(iv_3_o_ap_vld);
    
    aes_stim Stim1("Stimulus");
    Stim1.clk(clk);
    Stim1.done(ap_done);
    Stim1.rst(ap_rst);
    Stim1.start(ap_start);
    Stim1.key_0(key_0);
    Stim1.key_1(key_1);
    Stim1.key_2(key_2);
    Stim1.key_3(key_3);
    Stim1.out_0(inout_0_i);
    Stim1.out_1(inout_1_i);
    Stim1.out_2(inout_2_i);
    Stim1.out_3(inout_3_i);
    Stim1.in_0(inout_0_o);
    Stim1.in_1(inout_1_o);
    Stim1.in_2(inout_2_o);
    Stim1.in_3(inout_3_o);
    Stim1.inout_0_o_ap_vld(inout_0_o_ap_vld);
    Stim1.inout_1_o_ap_vld(inout_1_o_ap_vld);
    Stim1.inout_2_o_ap_vld(inout_2_o_ap_vld);
    Stim1.inout_3_o_ap_vld(inout_3_o_ap_vld);
    Stim1.iv_out_0(iv_0_i);
    Stim1.iv_out_1(iv_1_i);
    Stim1.iv_out_2(iv_2_i);
    Stim1.iv_out_3(iv_3_i);
    Stim1.iv_in_0(iv_0_o);
    Stim1.iv_in_1(iv_1_o);
    Stim1.iv_in_2(iv_2_o);
    Stim1.iv_in_3(iv_3_o);
    Stim1.iv_0_o_ap_vld(iv_0_o_ap_vld);
    Stim1.iv_1_o_ap_vld(iv_1_o_ap_vld);
    Stim1.iv_2_o_ap_vld(iv_2_o_ap_vld);
    Stim1.iv_3_o_ap_vld(iv_3_o_ap_vld);
    Stim1.init(&key, &ptx, &encr, &decr, &iv);
    
    sc_trace_file *wf = sc_create_vcd_trace_file("aes");
    sc_trace(wf, clk, "clock");
    sc_trace(wf, ap_rst, "reset");
    sc_trace(wf, ap_start, "start");
    sc_trace(wf, ap_done, "done");
    sc_trace(wf, ap_idle, "idle");
    sc_trace(wf, ap_ready, "ready");
    
    sc_trace(wf, key_0, "k0");
    sc_trace(wf, key_1, "k1");
    sc_trace(wf, key_2, "k2");
    sc_trace(wf, key_3, "k3");
    
    sc_trace(wf, inout_0_i, "in0");
    sc_trace(wf, inout_1_i, "in1");
    sc_trace(wf, inout_2_i, "in2");
    sc_trace(wf, inout_3_i, "in3");
    
    sc_trace(wf, iv_0_i, "iv_0_i");
    sc_trace(wf, iv_1_i, "iv_1_i");
    sc_trace(wf, iv_2_i, "iv_2_i");
    sc_trace(wf, iv_3_i, "iv_3_i");

    sc_trace(wf, iv_0_o, "iv_0_o");
    sc_trace(wf, iv_1_o, "iv_1_o");
    sc_trace(wf, iv_2_o, "iv_2_o");
    sc_trace(wf, iv_3_o, "iv_3_o");
    
    sc_trace(wf, iv_0_o_ap_vld, "iv_0_vld");
    sc_trace(wf, iv_1_o_ap_vld, "iv_1_vld");
    sc_trace(wf, iv_2_o_ap_vld, "iv_2_vld");
    sc_trace(wf, iv_3_o_ap_vld, "iv_3_vld");
    
    sc_trace(wf, inout_0_o, "out0");
    sc_trace(wf, inout_1_o, "out1");
    sc_trace(wf, inout_2_o, "out2");
    sc_trace(wf, inout_3_o, "out3");
    
    sc_trace(wf, inout_0_o_ap_vld, "ovld0");
    sc_trace(wf, inout_1_o_ap_vld, "ovld1");
    sc_trace(wf, inout_2_o_ap_vld, "ovld2");
    sc_trace(wf, inout_3_o_ap_vld, "ovld3");
    
    sc_start(0, SC_NS);    // First time called will init scheduler
    sc_start(1, SC_NS);    // Increment simulation by 1 time unit
    sc_start();     // Run the simulation till sc_stop is encountered
                    // sc_start() is terminated and return to next startment after
                    // encountering sc_stop()
    std::cout<<"Closing VCD File"<<endl;
    sc_close_vcd_trace_file(wf);
    
    fp=fopen("out.dat","w");
    fprintf(fp,"KEY: 0x");
    for(int i = 0; i < sizeof(key._b); i++){
        fprintf(fp,"%02hhx", key._b[i]);
    }
    fprintf(fp,"\nD_i: 0x");
    for(int i = 0; i < sizeof(ptx._b); i++){
        fprintf(fp,"%02hhx", ptx._b[i]);
    }
    fprintf(fp,"\nD_e: 0x");
    for(int i = 0; i < sizeof(encr._b); i++){
        fprintf(fp,"%02hhx", encr._b[i]);
    }
    fprintf(fp,"\nD_d: 0x");
    for(int i = 0; i < sizeof(decr._b); i++){
        fprintf(fp,"%02hhx", decr._b[i]);
    }
    fclose(fp);
    
//    for(int i = 0; i < sizeof(decr._b); i++){
//        printf("%02hhx", iv._b[i]);
//    }
    
    system("cat out.dat");
    printf("\n\n");
    
    printf ("Comparing against output data ...\n");
    if (system("diff -w out.dat out.gold.dat")) {
        if(system("diff -w out.dat testbench/out.gold.dat")){
            fprintf(stdout, "*******************************************\n");
            fprintf(stdout, "FAIL: Output DOES NOT match the golden output\n");
            fprintf(stdout, "*******************************************\n");
        }else{
            for(int i = 0; i< sizeof(ptx._b); i++)if(ptx._b[i]!=decr._b[i])return (0); 
            fprintf(stdout, "*******************************************\n");
            fprintf(stdout, "PASS: The output matches the golden output!\n");
            fprintf(stdout, "*******************************************\n");
            return 0;
        }
        return 1;
    } else {
        for(int i = 0; i< sizeof(ptx._b); i++)if(ptx._b[i]!=decr._b[i])return (0); 
        fprintf(stdout, "*******************************************\n");
        fprintf(stdout, "PASS: The output matches the golden output!\n");
        fprintf(stdout, "*******************************************\n");
        return 0;
    }
    
    delete(DUT);
    return(0);

}
