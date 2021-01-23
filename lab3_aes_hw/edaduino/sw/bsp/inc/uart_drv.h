///////////////////////////////////////////////////////////////////////////////
/// \file uart_drv.h
/// \date 11/03/2020
/// \author JG (johannes.geier@tum.de)
/// \brief uart driver header. Incomplete - for showcase only
//////////////////////////////////////////////////////////////////////////////

#ifndef __UART_DRV_H__
#define __UART_DRV_H__

#include "edaduino.h"
#include "uart.h"
#include "stdint.h"

typedef enum IER_BITS{
	UART_IER_RECEIVED_DATA_AVAILABLE = 0,
	UART_IER_TRANSMITTER_HOLDING_REG_EMPTY = 1,
	UART_IER_LINE_STATUS_REG_CHANGE = 2,
	UART_IER_MODEM_STATUS_REG_CHANGE = 3,
#ifdef T16750
	UART_IER_SLEEP_MODE = 4,
	UART_IER_LOW_POWERMODE = 5,
#endif
}ier_bits_t;

typedef enum IIR_CODE{
	UART_IIR_NO_INTERRUPT_PENDING = 0x01,
	UART_IIR_MODEM_STATUS_CHANGE = 0x00,
	UART_IIR_TRANSMITTER_HOLDING_REG_EMPTY = 0x02,
	UART_IIR_RECEIVED_DATA_AVAILABLE = 0x04,
	UART_IIR_LINE_STATUS_REG_CHANGE = 0x06,
#ifdef T16550
	UART_IIR_LINE_STATUS_REG_CHANGE = 0x08,
	UART_IIR_UNUSABLE_FIFO = 0x80,
#endif
#ifdef T16750
	UART_IIR_64BFIFO_ENABLED = 0x20,
	UART_IIR_FIFO_ENABLED = 0xC0,
#endif
}iir_codes_t;

typedef struct Uart_ops uart_ops_t;

/// \brief Uart control object. Holds states and registers
typedef struct Uart{
/* Registers */
	const uint8_t* rbr_; 	///< Receiver Buffer Register (make sure LCR.DLAB=0 before access) [RO]
	uint32_t* const thr_; ///< Transmitter Holding Register (make sure LCR.DLAB=0 before access) [WO]
	uint32_t* const dll_; ///< Divisor Latch (LSByte) Register (make sure LCR.DLAB=1 before access) [RW]
	uint32_t* const ier_; ///< Interrupt Enable Register (make sure LCR.DLAB=0 before access) [RW]
	uint32_t* const dlm_; ///< Divisor Latch (MSByte) Register (make sure LCR.DLAB=1 before access) [RW]
	uint32_t* const iir_;	///< Interrupt Identification Register [RO]
	uint32_t* const fcr_;	///< FIFO Control Register [WO]
	uint32_t* const lcr_; ///< Line Control Register [RW]
	uint32_t* const mcr_; ///< Modem Control Register [RW]
	uint32_t* const lsr_; ///< Line Status Register [RO]
	uint32_t* const msr_; ///< Modem Status Register [RO]
	uint32_t* const scr_; ///< Scratch [RW]

/* callbacks */
	void (*irq_callback)(void);	///< Function pointer to custom interrupt callback

/* pseudo member methods... yes this is obviously a poor man's object oriented class programming in C*/
	uart_ops_t* ops_; 				///< Member methods in form of
} uart_t;

/// \brief Uart control object. Holds functions that act on a Uart object
typedef struct Uart_ops{
	void (*set_dlab)(uart_t* handle);
		///< Change configuration mode to LCR.DLAB=1, alters access for certain register addresses
  void (*reset_dlab)(uart_t* handle);
		///< Change configuration mode to standard LCR.DLAB=1
	void (*set_IERbit)(uart_t* handle, uint8_t nbit);
		///< Enable an Interrupt class by setting the respective bit in the UART interrupt enable register
	void (*reset_IERbit)(uart_t* handle, uint8_t nbit);
		///< Disable an Interrupt class by resetting the respective bit in the UART interrupt enable register
	void (*set_irq_callback)(uart_t* handle, void (*fptr)(void));
		///< Set a custom UART interrupt callback
	void (*enable_interrupt)(uart_t* handle, ier_bits_t interrupt);
		///< Enable a specific UART interrupt
	void (*disable_interrupt)(uart_t* handle, ier_bits_t interrupt);
		///< Disable a specific UART interrupt
} uart_ops_t;

void uart__set_dlab(uart_t* handle);
void uart__reset_dlab(uart_t* handle);
void uart__set_IERbit(uart_t* handle, uint8_t nbit);
void uart__reset_IERbit(uart_t* handle, uint8_t nbit);
void uart__set_irq_callback(uart_t* handle, void (*fptr)(void));
void uart__enable_interrupt(uart_t* handle, ier_bits_t interrupt);
void uart__disable_interrupt(uart_t* handle, ier_bits_t interrupt);

#define UART_IRQ_LINE 16

#define UART_OFFSET_RBR 0*0x4   // LCR.DLAB=0: Read
#define UART_OFFSET_THR 0*0x4   // LCR.DLAB=0: Write
#define UART_OFFSET_DLL 0*0x4   // LCR.DLAB=1: R/W DLL
#define UART_OFFSET_IER 1*0x4   // LCR.DLAB=0: R/W
#define UART_OFFSET_DLM 1*0x4   // LCR.DLAB=1: R/W
#define UART_OFFSET_IIR 2*0x4   // Read
#define UART_OFFSET_FCR 2*0x4   // Write
#define UART_OFFSET_LCR 3*0x4   // R/W MSB (7) - 1:DLL/DLM 0:RBR/THR/IER
#define UART_OFFSET_MCR 4*0x4   // R/W
#define UART_OFFSET_LSR 5*0x4   // R/W
#define UART_OFFSET_MSR 6*0x4   // R/W
#define UART_OFFSET_SCR 7*0x4   // R/W

/* Constructors for UART handles*/
#define UART_CREATE_INSTANCE(VAR_NAME, UART_METHODS_HANDLE_PTR, BASE_ADDR) \
uart_t VAR_NAME = { \
	.rbr_ = (void*)(BASE_ADDR + UART_OFFSET_RBR), \
	.thr_ = (void*)(BASE_ADDR + UART_OFFSET_THR), \
	.dll_ = (void*)(BASE_ADDR + UART_OFFSET_DLL), \
	.ier_ = (void*)(BASE_ADDR + UART_OFFSET_IER), \
	.dlm_ = (void*)(BASE_ADDR + UART_OFFSET_DLM), \
	.iir_ = (void*)(BASE_ADDR + UART_OFFSET_IIR), \
	.fcr_ = (void*)(BASE_ADDR + UART_OFFSET_FCR), \
	.lcr_ = (void*)(BASE_ADDR + UART_OFFSET_LCR), \
	.mcr_ = (void*)(BASE_ADDR + UART_OFFSET_MCR), \
	.lsr_ = (void*)(BASE_ADDR + UART_OFFSET_LSR), \
	.msr_ = (void*)(BASE_ADDR + UART_OFFSET_MSR), \
	.scr_ = (void*)(BASE_ADDR + UART_OFFSET_SCR), \
	.irq_callback = 0, \
	.ops_ = UART_METHODS_HANDLE_PTR \
}

#define UART_CREATE_METHODS_HANDLE(VAR_NAME) \
uart_ops_t VAR_NAME = { \
	.set_dlab = uart__set_dlab, \
	.reset_dlab = uart__reset_dlab, \
	.set_IERbit = uart__set_IERbit, \
	.reset_IERbit = uart__reset_IERbit, \
	.set_irq_callback = uart__set_irq_callback, \
	.enable_interrupt = uart__enable_interrupt, \
	.disable_interrupt = uart__disable_interrupt, \
}


#endif /*__UART_DRV_H__*/
