///////////////////////////////////////////////////////////////////////////////
/// \file uart_drv.c
/// \date 11/03/2020
/// \author JG (johannes.geier@tum.de)
/// \brief uart driver source. Incomplete - for showcase only
//////////////////////////////////////////////////////////////////////////////

#include "uart_drv.h"

void uart__set_dlab(uart_t* handle) {
	*(handle->lcr_) |= 0x80;
}

void uart__reset_dlab(uart_t* handle) {
	*(handle->lcr_) &= ~(0x80);
}

void uart__set_IERbit(uart_t* handle, uint8_t nbit) {
	handle->ops_->reset_dlab(handle);
	*(handle->ier_) |= (0x1 << nbit);
}

void uart__reset_IERbit(uart_t* handle, uint8_t nbit) {
	handle->ops_->reset_dlab(handle);
	*(handle->ier_) &= ~(0x1 << nbit);
}

void uart__set_irq_callback(uart_t* handle, void (*fptr)(void)){
	handle->irq_callback = fptr;
}

void uart__enable_interrupt(uart_t* handle, ier_bits_t interrupt){
	handle->ops_->set_IERbit(handle, interrupt);
}

void uart__disable_interrupt(uart_t* handle, ier_bits_t interrupt){
	handle->ops_->reset_IERbit(handle, interrupt);
}
