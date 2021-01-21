/**
 * @Author: J.Geier
 * @Date:   2020-04-24T13:19:42+01:00
 * @Filename: aes_ha_drv.h
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



#ifndef __AES_HA_H__
#define __AES_HA_H__

#include "edaduino.h"
#include "utils.h"
#include "stdint.h"

#define AES_HA_OFFSET_CS		    	0x0000
#define AES_HA_OFFSET_CONTROL    		0x0000
#define AES_HA_OFFSET_STATUS    		0x0002

#define AES_HA_OFFSET_PERF_COUNTER 		0x0004
#define AES_HA_OFFSET_PERF_COUNTER_CPU_LO	0x0008
#define AES_HA_OFFSET_PERF_COUNTER_CPU_HI	0x000C

#define AES_HA_OFFSET_IO_BYTES_3_0     	0x0100
#define AES_HA_OFFSET_IO_BYTES_7_4     	0x0104
#define AES_HA_OFFSET_IO_BYTES_11_8    	0x0108
#define AES_HA_OFFSET_IO_BYTES_15_12   	0x010C
#define AES_HA_OFFSET_KEY_BYTES_3_0     0x0200
#define AES_HA_OFFSET_KEY_BYTES_7_4     0x0204
#define AES_HA_OFFSET_KEY_BYTES_11_8    0x0208
#define AES_HA_OFFSET_KEY_BYTES_15_12   0x020C
#define AES_HA_OFFSET_IV_BYTES_3_0      0x0300
#define AES_HA_OFFSET_IV_BYTES_7_4      0x0304
#define AES_HA_OFFSET_IV_BYTES_11_8     0x0308
#define AES_HA_OFFSET_IV_BYTES_15_12    0x030C

#define AES_HA_R_CS		    	   		(AES_HA_BASE_ADDR + AES_HA_OFFSET_CS)
#define AES_HA_R_CONTROL    	   		(AES_HA_BASE_ADDR + AES_HA_OFFSET_CONTROL)
#define AES_HA_R_STATUS      	   		(AES_HA_BASE_ADDR + AES_HA_OFFSET_STATUS)

#define AES_HA_R_PERF_COUNTER			(AES_HA_BASE_ADDR + AES_HA_OFFSET_PERF_COUNTER)

#define AES_HA_R_PERF_COUNTER_CPU_LO		(AES_HA_BASE_ADDR + AES_HA_OFFSET_PERF_COUNTER_CPU_LO)
#define AES_HA_R_PERF_COUNTER_CPU_HI		(AES_HA_BASE_ADDR + AES_HA_OFFSET_PERF_COUNTER_CPU_HI)

#define AES_HA_R_IO_BYTES_3_0         	(AES_HA_BASE_ADDR + AES_HA_OFFSET_IO_BYTES_3_0)
#define AES_HA_R_IO_BYTES_7_4         	(AES_HA_BASE_ADDR + AES_HA_OFFSET_IO_BYTES_7_4)
#define AES_HA_R_IO_BYTES_11_8        	(AES_HA_BASE_ADDR + AES_HA_OFFSET_IO_BYTES_11_8)
#define AES_HA_R_IO_BYTES_15_12       	(AES_HA_BASE_ADDR + AES_HA_OFFSET_IO_BYTES_15_12)
#define AES_HA_R_IO AES_HA_R_IO_BYTES_3_0

#define AES_HA_R_KEY_BYTES_3_0         	(AES_HA_BASE_ADDR + AES_HA_OFFSET_KEY_BYTES_3_0)
#define AES_HA_R_KEY_BYTES_7_4         	(AES_HA_BASE_ADDR + AES_HA_OFFSET_KEY_BYTES_7_4)
#define AES_HA_R_KEY_BYTES_11_8        	(AES_HA_BASE_ADDR + AES_HA_OFFSET_KEY_BYTES_11_8)
#define AES_HA_R_KEY_BYTES_15_12       	(AES_HA_BASE_ADDR + AES_HA_OFFSET_KEY_BYTES_15_12)
#define AES_HA_R_KEY AES_HA_R_KEY_BYTES_3_0

#define AES_HA_R_IV_BYTES_3_0         	(AES_HA_BASE_ADDR + AES_HA_OFFSET_IV_BYTES_3_0)
#define AES_HA_R_IV_BYTES_7_4         	(AES_HA_BASE_ADDR + AES_HA_OFFSET_IV_BYTES_7_4)
#define AES_HA_R_IV_BYTES_11_8        	(AES_HA_BASE_ADDR + AES_HA_OFFSET_IV_BYTES_11_8)
#define AES_HA_R_IV_BYTES_15_12       	(AES_HA_BASE_ADDR + AES_HA_OFFSET_IV_BYTES_15_12)
#define AES_HA_R_IV AES_HA_R_IV_BYTES_3_0

#define AES_HA_CLK_PERIOD_PS 10 //pico seconds from fixed RTC frequency 32.768kHz

#define AES_HA_IRQ_LINE 21

///////////////////////////////////////////////////////////////////////////
// \brief AES HA Control structure containing memory mapped register fields.
typedef struct AES_HA{
	uint16_t* control;			//<< Control input register. Can be written with encoding (aes_ha_control_t).
	uint16_t* status;			//<< Hold the target's status. Can be decoded with aes_fsm_state_t
	uint32_t* perf_counter; 	//<< Holds the target's clock cycle counter. Idle value: (cycle'@done - cycle'@start) of last operation
	uint32_t* perf_counter_cpu_lo; //<< Holds the cpu's clock cycle count. Low word. beware of overflow
	uint32_t* perf_counter_cpu_hi; //<< Holds the cpu's clock cycle count. High word. beware of overflow
	uint32_t* io; 				//<< AES In/out registers
	uint32_t* key; 				//<< AES Key (private key)
	uint32_t* iv;               //<< AES IV (public key)
}aes_ha_t;

typedef enum{
	AES_CTRL_STOP  = 0x0,
	AES_CTRL_START = 0x1,
	AES_CTRL_IP    = 0x2,
} aes_ha_control_t;

typedef enum {
	  AES_FSM_IDLE = 0,
	  AES_FSM_START = 1,
	  AES_FSM_PROC = 2,
	  AES_DONE = 4
}aes_fsm_state_t;

/* CONTROL functions */
///////////////////////////////////////////////////////////////////////////
// \brief Set control register start
void aes_ha_start(void);

///////////////////////////////////////////////////////////////////////////
// \brief Set control register stop bit
void aes_ha_stop(void);

///////////////////////////////////////////////////////////////////////////
// \brief Clear interrupt flag
void aes_ha_clearInterrupt(void);

///////////////////////////////////////////////////////////////////////////
// \brief Read status register
// \return Status register bitfield
uint16_t aes_ha_read_status(void);

///////////////////////////////////////////////////////////////////////////
// \brief Read the performance counter register of the AES HA
// \return Returns 32 bit value of target performance counter
uint32_t aes_ha_read_performancecounter(void);

///////////////////////////////////////////////////////////////////////////
// \brief Read the performance counter register of the CPU, i.e. CPU clock cycles
// \return Returns 32 bit value of target performance counter
uint64_t aes_ha_read_CPUperformancecounter(void);

/* IN-/OUTPUT */
///////////////////////////////////////////////////////////////////////////
// \brief Write 128 Bit Key to HA Register
// \param pData Pointer to input data
void aes_ha_write128B_Key(const uint8_t* pData);

///////////////////////////////////////////////////////////////////////////
// \brief Write 128 Bit IO to HA Register
// \param pData Pointer to input data
void aes_ha_write128B_IO(const uint8_t* pData);

///////////////////////////////////////////////////////////////////////////
// \brief Read 128 Bit IO from HA Register
// \param pData Pointer to output data
void aes_ha_read128B_IO(uint8_t* pData);

///////////////////////////////////////////////////////////////////////////
// \brief Read 128 Bit Kex from HA Register
// \param pData Pointer to output data
void aes_ha_read128B_Key(uint8_t* pData);

///////////////////////////////////////////////////////////////////////////
// \brief Read 128 Bit IV from HA Register
// \param pData Pointer to output data
void aes_ha_read128B_IV(uint8_t* pData);

///////////////////////////////////////////////////////////////////////////
// \brief Write 128 Bit IV to HA Register
// \param pData Pointer to input data
void aes_ha_write128B_IV(const uint8_t* pData);

///////////////////////////////////////////////////////////////////////////
// \brief Write In-/Out Register word-wise (32 bit)
// \param dat Datum to write
// \param idx Index of Byte to write
void aes_ha_writeWord(uint32_t dat, uint8_t idx, int io);

///////////////////////////////////////////////////////////////////////////
// \brief Read In-/Out Register word-wise (32 bit)
// \param idx Index of Word to write
// \param pDat Pointer to storage of read Word
// \return -1 if Index invalid, 1 if read success
int aes_ha_readWord(uint32_t* pDat, uint8_t idx, int io);

// CONFIGURATIONS
///////////////////////////////////////////////////////////////////////////
// \brief Configure custom interrupt callback function
// \param fptr Function Pointer: Function must not have parameters or return value, e.g. void foo(void);
void aes_ha_cfg_IrqCallback(void (*fptr)(void));

///////////////////////////////////////////////////////////////////////////
// \brief Default interrupt handler. Does stuff and calls custom handler (if configured)
void aes_ha_handle_IRQ(void);


void aes_ha_IOREG_test(volatile char* log);
int aes_ha_Func_test(volatile char* log);
#endif /*__AES_HA_H__*/
