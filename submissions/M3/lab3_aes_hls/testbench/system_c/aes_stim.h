#ifndef _AES_STIM_H_
#define _AES_STIM_H_

#include "systemc.h"
#include <iostream>

union dat_t{
    uint8_t _b[16];
    uint32_t _w[4];
};


SC_MODULE(aes_stim)
{
    sc_in<bool> clk;
    sc_in<bool> done;
    
    sc_out<bool> rst;
    sc_out<bool> start;
    
    sc_out<uint32_t> key_0;
    sc_out<uint32_t> key_1;
    sc_out<uint32_t> key_2;
    sc_out<uint32_t> key_3;
    
    sc_out<uint32_t> out_0;
    sc_out<uint32_t> out_1;
    sc_out<uint32_t> out_2;
    sc_out<uint32_t> out_3;
    
    sc_in<bool> inout_0_o_ap_vld;
    sc_in<bool> inout_1_o_ap_vld;
    sc_in<bool> inout_2_o_ap_vld;
    sc_in<bool> inout_3_o_ap_vld;
    
    sc_in<uint32_t> in_0;
    sc_in<uint32_t> in_1;
    sc_in<uint32_t> in_2;
    sc_in<uint32_t> in_3;

    sc_out<uint32_t> iv_out_0;
    sc_out<uint32_t> iv_out_1;
    sc_out<uint32_t> iv_out_2;
    sc_out<uint32_t> iv_out_3;
    sc_in<uint32_t> iv_in_0;
    sc_in<uint32_t> iv_in_1;
    sc_in<uint32_t> iv_in_2;
    sc_in<uint32_t> iv_in_3;
    sc_in<bool> iv_0_o_ap_vld;
    sc_in<bool> iv_1_o_ap_vld;
    sc_in<bool> iv_2_o_ap_vld;
    sc_in<bool> iv_3_o_ap_vld;
    
    dat_t* key;
    dat_t* ptx;
    dat_t* encr;
    dat_t* decr;
    dat_t* iv;
    dat_t publickey;
    
    bool decrypt{false};
    
    void init(dat_t* _key, dat_t* _ptx, dat_t* _encr, dat_t* _decr, dat_t* _iv){
        key = _key;
        ptx = _ptx;
        encr = _encr;
        decr = _decr;
        iv = _iv;
        
        rst.write(true);
        start.write(false);
        
        key_0.write(0);
        key_1.write(0);
        key_2.write(0);
        key_3.write(0);
        
        out_0.write(0);
        out_1.write(0);
        out_2.write(0);
        out_3.write(0);  
        
        iv_out_0.write(0);
        iv_out_1.write(0);
        iv_out_2.write(0);
        iv_out_3.write(0);
        for(int i = 0; i< 4; ++i)publickey._w[i] = iv->_w[i];
    }
    
    void stimgen(void){
        wait(); //----------------------------
        rst.write(false);
        wait(); //----------------------------
        start.write(true);
        
        key_0.write((*(key))._w[0]);
        key_1.write((*(key))._w[1]);
        key_2.write((*(key))._w[2]);
        key_3.write((*(key))._w[3]);
        
        out_0.write((*(ptx))._w[0]);
        out_1.write((*(ptx))._w[1]);
        out_2.write((*(ptx))._w[2]);
        out_3.write((*(ptx))._w[3]);  
        
        iv_out_0.write(publickey._w[0]);
        iv_out_1.write(publickey._w[1]);
        iv_out_2.write(publickey._w[2]);
        iv_out_3.write(publickey._w[3]);
        
        wait(); //----------------------------
        start.write(false);
        wait(); //----------------------------
        do{wait();}while(done.read() == false);        
        start.write(false);
        decrypt = true;
        iv_out_0.write(publickey._w[0]);
        iv_out_1.write(publickey._w[1]);
        iv_out_2.write(publickey._w[2]);
        iv_out_3.write(publickey._w[3]);
        wait(); //----------------------------
        start.write(true);        
        out_0.write((*(encr))._w[0]);
        out_1.write((*(encr))._w[1]);
        out_2.write((*(encr))._w[2]);
        out_3.write((*(encr))._w[3]);
        wait(); //----------------------------
        do{wait();}while(done.read() == false);
        start.write(false);
        wait(); //----------------------------
        sc_stop();
    }
    
    void storeres(void){
        while(true){
        if(decrypt){
            if(inout_0_o_ap_vld.read())(*(decr))._w[0] = in_0.read();
            if(inout_1_o_ap_vld.read())(*(decr))._w[1] = in_1.read();
            if(inout_2_o_ap_vld.read())(*(decr))._w[2] = in_2.read();
            if(inout_3_o_ap_vld.read())(*(decr))._w[3] = in_3.read();
        } else {
            if(inout_0_o_ap_vld.read())(*(encr))._w[0] = in_0.read();
            if(inout_1_o_ap_vld.read())(*(encr))._w[1] = in_1.read();
            if(inout_2_o_ap_vld.read())(*(encr))._w[2] = in_2.read();
            if(inout_3_o_ap_vld.read())(*(encr))._w[3] = in_3.read();
        }
        printf("Monitor: 0x%08x%08x%08x%08x\n", in_0.read(),in_1.read(),in_2.read(),in_3.read());
        wait();
        }
    }
    void storeiv(void){
        while(true){
            if(iv_0_o_ap_vld.read())(*(iv))._w[0] = iv_in_0.read();
            if(iv_1_o_ap_vld.read())(*(iv))._w[1] = iv_in_1.read();
            if(iv_2_o_ap_vld.read())(*(iv))._w[2] = iv_in_2.read();
            if(iv_3_o_ap_vld.read())(*(iv))._w[3] = iv_in_3.read();
            wait();
        }
    }
    SC_CTOR(aes_stim){
        SC_THREAD(stimgen);
        sensitive << clk.pos();
        dont_initialize();
        SC_THREAD(storeres);
        sensitive << inout_0_o_ap_vld.pos() << inout_1_o_ap_vld.pos() << inout_2_o_ap_vld.pos() << inout_3_o_ap_vld.pos();        
        SC_THREAD(storeiv);
        sensitive << iv_0_o_ap_vld.pos() << iv_1_o_ap_vld.pos() << iv_2_o_ap_vld.pos() << iv_3_o_ap_vld.pos();
        dont_initialize();
    }
        
};

 /*  
SC_MODULE(aes_mon)
{
    sc_in<bool> clk;
    
    sc_in<bool> ap_done;
    sc_in<bool> ap_idle;
    sc_in<bool> ap_ready;
        
    sc_in<bool> cryptdir;
    
    sc_in<bool> inout_0_o_ap_vld;
    sc_in<bool> inout_1_o_ap_vld;
    sc_in<bool> inout_2_o_ap_vld;
    sc_in<bool> inout_3_o_ap_vld;
    
    sc_in<uint32_t> text_0;
    sc_in<uint32_t> text_1;
    sc_in<uint32_t> text_2;
    sc_in<uint32_t> text_3;

    int clk_cnt;
    
    dat_t enc;
    uint64_t encryptend_clkcnt;
    dat_t dec;
    uint64_t decryptend_clkcnt;
    
    dat_t* key;
    dat_t* ptx;
    
    void init(dat_t* key, dat_t* ptx){
        key = key;
        ptx = ptx; 
    }
    
    void logtext(const int w, const uint32_t word){
        if(cryptdir.read()){
            enc._w[w] = word;
        }
        else{
            dec._w[w] = word;
        }
    }
 
    void monitor(void){
        clk_cnt++;
        std::cout << clk_cnt << std::endl; 
        
        if(ap_done.read()){
        printf("Monitor: %d clk - TEXT: 0x%08x%08x%08x%08x\n", clk_cnt, text_0.read(),text_1.read(),text_2.read(),text_3.read());
        //if(inout_0_o_ap_vld.read()){
          logtext(0, text_0.read());            
        //}
        //if(inout_1_o_ap_vld.read()){
          logtext(1, text_1.read());
        //}
        //if(inout_2_o_ap_vld.read()){
          logtext(2, text_2.read());
        //}
        //if(inout_3_o_ap_vld.read()){
          logtext(3, text_3.read());
        //}
        }  
        if(ap_done.pos()){
            if(cryptdir.read()){
                decryptend_clkcnt = clk_cnt - clkstart;            
            }
            else{
                encryptend_clkcnt = clk_cnt - clkstart;
            }
        }
        if(ap_ready.neg() or ap_idle.neg()){
            clkstart = clk;
        
    }
    
    SC_CTOR(aes_mon): 
    clk_cnt(),
    encryptend_clkcnt(),
    decryptend_clkcnt()
            {
        SC_THREAD(monitor);
        sensitive << clk.pos();
        sensitive << ap_done.pos();
        sensitive << ap_ready.pos();  
        //sensitive << inout_0_o_ap_vld;  
        //sensitive << inout_1_o_ap_vld;  
        //sensitive << inout_2_o_ap_vld;  
        //sensitive << inout_3_o_ap_vld;  
 
        //sensitive << ap_ready.neg();
        //sensitive << ap_idle.neg();
        
        //SC_THREAD(clk_monitor);
        //sensitive << clk.pos();
        //dont_initialize();
    }
        
};
*/

#endif //_AES_STIM_H_
