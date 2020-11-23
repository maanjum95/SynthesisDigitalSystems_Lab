#include "cust_print.h"
#include "exception.h"
#include "utils.h"
#include "bsp.h"


extern uart_t uart0;
extern void clint_handle_TIP(void);
extern void clint_handle_SIP(void);

enum{
	EXCEPTION_IRQ_CAUSE_MSIP 	= (0x1 << MIP_MSIP),
	EXCEPTION_IRQ_CAUSE_MTIP 	= (0x1 << MIP_MTIP),
	EXCEPTION_IRQ_CAUSE_UART 	= UART_IRQ_LINE
}INTERUPT_LINES;

void interrupt_handler(const uint32_t cause){
    volatile uint32_t _mip = 0;
    #ifdef IRQ_DEBUG
        custom_print_string(ETISSVP_LOGGER, "> Interrupt caught: ");
        custom_print_hex_int32(ETISSVP_LOGGER, cause);
        custom_print_string(ETISSVP_LOGGER, "\n");
    #endif

    csrr(mip, _mip);

    #ifdef IRQ_DEBUG
        custom_print_string(ETISSVP_LOGGER, "> MIP IRQ enter: ");
        custom_print_hex_int32(ETISSVP_LOGGER, _mip);
        custom_print_string(ETISSVP_LOGGER, "\n");
    #endif

    if(_mip & MIP_MSIP){ // MSIP - CLINT: Interprocess/Software interrupt
        _mip = _mip & ~(MIP_MTIP);
        csrw(mip, _mip);
        clint_handle_SIP();
    }
    if(_mip & MIP_MTIP){ // MTIP - CLINT: Timer interrupt
        _mip = _mip & ~(MIP_MTIP);
        csrw(mip, _mip);
        clint_handle_TIP();
    }
    if(cause == EXCEPTION_IRQ_CAUSE_UART){
        if(uart0.irq_callback != 0){
					uart0.irq_callback();
				}
    }
    csrr(mip, _mip);
    #ifdef IRQ_DEBUG
        custom_print_string(ETISSVP_LOGGER, "< MIP IRQ leave: ");
        custom_print_hex_int32(ETISSVP_LOGGER, _mip);
        custom_print_string(ETISSVP_LOGGER, "\n");
    #endif
}


void exception_handler(const uint32_t cause){
    #ifdef IRQ_DEBUG
        custom_print_string(ETISSVP_LOGGER, "> Exception caught: ");
        custom_print_hex_int32(ETISSVP_LOGGER, cause);
        custom_print_string(ETISSVP_LOGGER, "\n");
    #endif
}

void default_handler(void) {
    static const uint32_t MCAUSE_INTMASK = 0x80000000;
    uint32_t _mcause;

    csrr(mcause, _mcause);
    if(_mcause & MCAUSE_INTMASK){
        interrupt_handler(_mcause & (~MCAUSE_INTMASK));
    }else{
        exception_handler(_mcause);
    }
}
