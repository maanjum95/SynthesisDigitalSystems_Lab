#ifndef __CLINT_DRV_H__
#define __CLINT_DRV_H__

#include "edaduino.h"
#include "utils.h"
#include "stdint.h"

#define CLINT_MTIMECMPLO_OFFSET    0x4000
#define CLINT_MTIMECMPHI_OFFSET    (0x4000 + 4)
#define CLINT_MTIMELO_OFFSET       0xBFF8
#define CLINT_MTIMEHI_OFFSET       (0xBFF8 + 4)

#define CLINT_MTIMECMPLO        (CLINT_BASE_ADDR + CLINT_MTIMECMPLO_OFFSET)
#define CLINT_MTIMECMPHI        (CLINT_BASE_ADDR + CLINT_MTIMECMPHI_OFFSET)

#define CLINT_MTIMELO           (CLINT_BASE_ADDR + CLINT_MTIMELO_OFFSET)
#define CLINT_MTIMEHI           (CLINT_BASE_ADDR + CLINT_MTIMEHI_OFFSET)

#define CLINT_TIMER_PERIOD_NS 30518
//#30517578 //pico seconds from fixed RTC frequency 32.768kHz
 
void clint_cfg_timecompare_us(const uint32_t period_us);

void clint_cfg_timecompare(uint64_t compare);

void clint_cfg_callback_tip(void (*fptr)(void));

void clint_handle_SIP(void);

void clint_handle_TIP(void);

#endif /*__CLINT_DRV_H__*/
