#ifndef __EDADUINO_H__
#define __EDADUINO_H__

#define EDADUINO_BASE_ADDR             0x0 //=Debug base

#define UART_BASE_ADDR                (0x10000000) //<< UART 
#define AES_HA_BASE_ADDR              (0x10001000) //<< AES_HA
#define TIMER_BASE_ADDR               (0x18000000) //<< TIMER
#define CLINT_BASE_ADDR               (0x02000000) //<< CLINT

/** Instruction RAM */
#define INSTR_RAM_BASE_ADDR           ( 0x00       ) //<< ROM 
#define INSTR_RAM_START_ADDR          ( 0x80       ) //<< BOOTADDR 

#define ROM_BASE_ADDR                 ( 0x0     ) //<< ROM 

/** Data RAM */
#define DATA_RAM_BASE_ADDR            (0x0000080000) //<< RAM 

/** Registers and pointers */
#define REGP(x) ((volatile unsigned int*)(x))
#define REG(x) (*((volatile unsigned int*)(x)))
#define REGP_8(x) (((volatile uint8_t*)(x)))

#endif /*__EDADUINO_H__*/
