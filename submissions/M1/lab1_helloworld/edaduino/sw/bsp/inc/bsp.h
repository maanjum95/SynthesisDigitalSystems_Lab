#ifndef __BSP_H__
#define __BSP_H__

#include "stdint.h"

#define ETISSVP_LOGGER_ADDR 0xf0000000
#define ETISSVP_LOGGER ((volatile char*)ETISSVP_LOGGER_ADDR)

typedef struct BSP_INIT{

    uint32_t systemtimer_us;
    void (*systemtimer_callback)(void);
    void (*uart_callback)(void);

}bsp_init_t;

void bsp_init(bsp_init_t* _cfg);

#endif /*__BSP_H__*/
