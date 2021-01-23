#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include "encoding.h"

#include "clint_drv.h"
#include "uart_drv.h"
#include "aes_ha_drv.h"

void interrupt_handler(uint32_t cause);
void exception_handler(uint32_t cause);
void default_handler(void)__attribute__((interrupt));;

#endif /*__EXCEPTION_H__*/
