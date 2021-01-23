/**
 * @Author: J.Geier
 * @Date:   2020-04-24T13:19:42+01:00
 * @Filename: aes_ha_drv.c
 * @Last modified by:   
 * @Last modified time: 
 * @Copyright: Copyright (c) 2019
  Institute for Electronic Design Automation, TU Munich

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.

 */

#include "aes_ha_drv.h"
#include "utils.h"
#include "stdint.h"

void (*aes_ha_callback)(void) = 0;

aes_ha_t gAES_HA = {
		(uint16_t*)AES_HA_R_CONTROL,
		(uint16_t*)AES_HA_R_STATUS,
		(uint32_t*)AES_HA_R_PERF_COUNTER,
		(uint32_t*)AES_HA_R_PERF_COUNTER_CPU_LO,
		(uint32_t*)AES_HA_R_PERF_COUNTER_CPU_HI,
		(uint32_t*)AES_HA_R_IO,
		(uint32_t*)AES_HA_R_KEY,
		(uint32_t*)AES_HA_R_IV
};

void aes_ha_start(void){
	*(gAES_HA.control) = (uint16_t)(AES_CTRL_START);
}

void aes_ha_stop(void){
	*(gAES_HA.control) = AES_CTRL_STOP;
}

void aes_ha_clearInterrupt(void){
	uint32_t ctrl = *(gAES_HA.control);
	*(gAES_HA.control) = ctrl & (~AES_CTRL_IP);
}

uint16_t aes_ha_read_status(void){
	return(*(gAES_HA.status));
}

uint32_t aes_ha_read_performancecounter(void){
	return (*(gAES_HA.perf_counter));
}

uint64_t aes_ha_read_CPUperformancecounter(void){
	uint32_t lo, hi;
	lo = *(gAES_HA.perf_counter_cpu_lo);
	hi = *(gAES_HA.perf_counter_cpu_hi);

	return ((uint64_t)hi << 32) | lo;
}

void aes_ha_write128B_Key(const uint8_t* pData){
	for(int i = 0; i < 4; ++i){
		aes_ha_writeWord( *((uint32_t*)(pData+i*4)), i, 0);
	}
}

void aes_ha_write128B_IO(const uint8_t* pData){
	for(int i = 0; i < 4; ++i){
		aes_ha_writeWord( *((uint32_t*)(pData+i*4)), i, 1);
	}
}

void aes_ha_write128B_IV(const uint8_t* pData){
	for(int i = 0; i < 4; ++i){
		aes_ha_writeWord( *((uint32_t*)(pData+i*4)), i, 2);
	}
}

void aes_ha_read128B_IO(uint8_t* pData){
	for(int i = 0; i < 4; ++i){
		aes_ha_readWord( (uint32_t*)(pData+i*4), i, 1);
	}
}

void aes_ha_read128B_Key(uint8_t* pData){
	for(int i = 0; i < 4; ++i){
		aes_ha_readWord( (uint32_t*)(pData+i*4), i, 0);
	}
}

void aes_ha_read128B_IV(uint8_t* pData){
	for(int i = 0; i < 4; ++i){
		aes_ha_readWord( (uint32_t*)(pData+i*4), i, 2);
	}
}
void aes_ha_writeWord(uint32_t dat, uint8_t idx, int io){
	if(idx <= 3){
		switch(io){
            case 0: gAES_HA.key[idx] = dat; break;
            case 1: gAES_HA.io[idx] = dat; break;
            default: gAES_HA.iv[idx] = dat; break;
        }
	}
}

int aes_ha_readWord(uint32_t* pDat, uint8_t idx, int io){
	if(idx <= 3){
        switch(io){
            case 0: *pDat = gAES_HA.key[idx]; break;
            case 1: *pDat = gAES_HA.io[idx]; break;
            default: *pDat = gAES_HA.iv[idx]; break;
        }
        return (0);
	}
	return(-1);
}

void aes_ha_cfg_IrqCallback(void (*fptr)(void)){
	aes_ha_callback = fptr;
}

void aes_ha_handle_IRQ(void){
    if(aes_ha_callback != 0){
    	aes_ha_callback();
    }
}

extern int aes_done;

int aes_ha_Func_test(volatile char* log){
	uint8_t key[16]
	    = {
	      0x2b, 0x7e, 0x15, 0x16,
	      0x28, 0xae, 0xd2, 0xa6,
	      0xab, 0xf7, 0x15, 0x88,
	      0x09, 0xcf, 0x4f, 0x3c};

	uint8_t plain_text[16]
	    = {
	      0x6b, 0xc1, 0xbe, 0xe2,
	      0x2e, 0x40, 0x9f, 0x96,
	      0xe9, 0x3d, 0x7e, 0x11,
	      0x73, 0x93, 0x17, 0x2a};

	uint8_t iv[16]
		= {
		  0x00, 0x00, 0x00, 0x00,
		  0x00, 0x00, 0x00, 0x00,
		  0x00, 0x00, 0x00, 0x00,
		  0x00, 0x00, 0x00, 0x00,
		};

	uint8_t d_i[16];
	uint8_t d_e[16];
	uint8_t d_d[16];

	aes_ha_write128B_Key(key);

	/* Encrypt */
	aes_ha_write128B_IV(iv);
	aes_ha_write128B_IO(plain_text);
	aes_ha_read128B_IO(d_i);
	aes_done = 0;
	aes_ha_start();
	while(!aes_done);
	aes_ha_read128B_IO(d_e);

	/* Decrypt */
	aes_ha_write128B_IV(iv);
	// aes_ha_write128B_IO(d_e); // optional: IO register still holds encrypted text at this point
	aes_done = 0;
	aes_ha_start();
	while(!aes_done);
	aes_ha_read128B_IO(d_d);

	for(int i = 0; i< 16; ++i) if(d_i[i] != d_d[i]) return (-1);
	return (1);
}

void aes_ha_IOREG_test(volatile char* log){
    uint8_t c[16] = {
      (uint8_t)0x2b, (uint8_t)0x7e, (uint8_t)0x15, (uint8_t)0x16,
      (uint8_t)0x28, (uint8_t)0xae, (uint8_t)0xd2, (uint8_t)0xa6,
      (uint8_t)0xab, (uint8_t)0xf7, (uint8_t)0x15, (uint8_t)0x88,
      (uint8_t)0x09, (uint8_t)0xcf, (uint8_t)0x4f, (uint8_t)0x3c};
    int failed;
    uint8_t read[16] = {};

	// Word Write - Word Read
    for (int io = 0; io < 2; ++io){
		failed = 0;
		for(int i = 0; i< 4; i++){
			aes_ha_writeWord(*( (uint32_t*)&(c[i*4])), i, io);
		}
		for(int i = 0; i< 4; i++){
			aes_ha_readWord((uint32_t*) &read[i*4], i, io);
		}
		for(int i = 0; i<16; i++){
			if(read[i] != c[i])failed = 1;
		}
		if(failed){
			 custom_print_string(log, "AES I/F WW-WR test: Failed!\n");
		}else{
			 custom_print_string(log, "AES I/F WW-WR test: Passed!\n");
		}
    }
	// 128Bit Write - 128 BitWord Read

    failed = 0;
    aes_ha_write128B_IO(c);
    aes_ha_read128B_IO(read);
	for(int i = 0; i<16; i++){
		if(read[i] != c[i])failed = 1;
	}
	if(failed){
		 custom_print_string(log, "AES I/F 128 IO test: Failed!\n");
	}else{
		 custom_print_string(log, "AES I/F 128 IO test: Passed!\n");
	}

    failed = 0;
    aes_ha_write128B_Key(c);
    aes_ha_read128B_Key(read);
	for(int i = 0; i<16; i++){
		if(read[i] != c[i])failed = 1;
	}
	if(failed){
		 custom_print_string(log, "AES I/F 128 Key test: Failed!\n");
	}else{
		 custom_print_string(log, "AES I/F 128 Key test: Passed!\n");
	}
	
    failed = 0;
    aes_ha_write128B_IV(c);
    aes_ha_read128B_IV(read);
	for(int i = 0; i<16; i++){
		if(read[i] != c[i])failed = 1;
	}
	if(failed){
		 custom_print_string(log, "AES I/F 128 IV test: Failed!\n");
	}else{
		 custom_print_string(log, "AES I/F 128 IV test: Passed!\n");
	}

}
