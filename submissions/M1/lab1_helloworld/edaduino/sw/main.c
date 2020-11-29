///////////////////////////////////////////////////////////////////////////////
/// \file main.c
/// \date 04/23/2020
/// \author JG
/// \brief edaduino target software main file
/// \details mod. 11/04/2020
//////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include "bsp.h"
#include "cust_print.h"
#include "uart_drv.h"

extern uart_t uart0;
  ///> 'holds' peripheral data in form of registers and callback pointers

#define BUF_SIZE 100

/// \brief Custom system timer interrupt handler. Source is the CLINT peripheral
/// configured by the board support package
static void systemtimer_irqhandler(void){
  custom_print_string(ETISSVP_LOGGER, "System timer callback taken\n");
}

volatile int uart_irq_flag = 0; ///< This is the interrupt messaging flag
/// \brief Custom uart interrupt handler. Source is the UART peripheral interrupt
static void uart_irqhandler(void){
  custom_print_string(ETISSVP_LOGGER, "UART interrupt callback taken\n");
  // Task DONE: >>>
  /* Find a way to determine the interrupt type and message the
    wfi_uart() that a "received data available" interrupt was fired */
  if (*(uart0.iir_) & UART_IIR_RECEIVED_DATA_AVAILABLE)
	  uart_irq_flag = 1;
  // <<< Task DONE
}

void wfi_uart(void) {
  // This is a very bad implementation of a "Wait for Interrupt".
  // However, the WFI does the job of syncing up the application with
  // an asynchronous event, such as the UART interrupt. If this software would
  // employ an Operating System (OS) the WFI calling task/thread could
  // instead of blocking execution yield itself to the scheduler,  i.e. let
  // another waiting task resume or take over until the waited for event occurs.
  uart_irq_flag = 0;
  while(!uart_irq_flag){
    asm(""); // forces optimization-agnostic busy wait
  };
}

static bsp_init_t cfg = {
  .systemtimer_us = 100000,
  .systemtimer_callback = systemtimer_irqhandler,
  .uart_callback = uart_irqhandler
};

int main() {
  unsigned char buf[BUF_SIZE]; // This is the input buffer

  bsp_init(&cfg);

  static const char* _s = "From stdio!\n";
  printf("Hello World! %s", _s);
  custom_print_string(ETISSVP_LOGGER, "Hello World! From ETISS!\n");

  // Task DONE: >>>
  /* Enable the "Received Data Available" Interrupt in the Uart IER register */
  uart0.ops_->enable_interrupt(&uart0, UART_IER_RECEIVED_DATA_AVAILABLE);
  // <<< Task DONE

  // UART input mirror
  while(1){
    int i = 0;

    // Task DONE: >>>
    /* Replace the busy poll - wait with the wfi_uart () */
    wfi_uart();
    // <<< Task DONE

    while( *uart0.lsr_ & 0x1 && i < BUF_SIZE) {
      // check the overflow flag, i.e. unread input data
      // break if the read buffer overflows
      buf[i++] = *(uart0.rbr_);
    }
    buf[i] = '\0';
    printf("%s", buf);
  }
}
