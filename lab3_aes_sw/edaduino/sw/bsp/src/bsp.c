#include "bsp.h"

#include "cust_print.h"
#include "exception.h"
#include "clint_drv.h"
#include "aes_ha_drv.h"
#include "uart_drv.h"

/* This is the UART's function object. Use this for any number of Uart instances */
UART_CREATE_METHODS_HANDLE(uart_ops);

/* This is a specific Uart instance (=object). The 2nd argument is the UART function
 object. */
UART_CREATE_INSTANCE(uart0, &uart_ops, UART_BASE_ADDR);

void bsp_init(bsp_init_t* _cfg)
{
    /* Setup for default interrupt handling */
    csrw(mtvec, default_handler);
    /* Enable all machine interrupts */
    uint32_t _mie = -1;
    csrw(mie, _mie);
    csrr(mie, _mie);

    clint_cfg_timecompare_us(_cfg->systemtimer_us);
    clint_cfg_callback_tip(_cfg->systemtimer_callback);

    uart0.ops_->set_irq_callback(&uart0, _cfg->uart_callback);

    aes_ha_cfg_IrqCallback(_cfg->aes_ha_callback);
}


uint64_t get_CpuCycles(void){
	return(aes_ha_read_CPUperformancecounter());
}
