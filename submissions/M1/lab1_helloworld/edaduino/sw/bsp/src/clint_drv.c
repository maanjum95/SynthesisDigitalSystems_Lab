#include "clint_drv.h"
#include "utils.h"


void (*tip_callback)(void) = 0;

void clint_cfg_timecompare_us(const uint32_t period_us){
    uint64_t compare = ((uint64_t)period_us*1000)/CLINT_TIMER_PERIOD_NS;
    clint_cfg_timecompare(compare);
}

void clint_cfg_timecompare(uint64_t compare){
    uint32_t * mtimecmplo = (uint32_t*)(CLINT_MTIMECMPLO);
    uint32_t * mtimecmphi = (uint32_t*)(CLINT_MTIMECMPHI);
    
    *mtimecmplo = (uint32_t)compare;
    *mtimecmphi = (uint32_t)(compare >> 32);
}

void clint_cfg_callback_tip(void (*fptr)(void)){
    tip_callback = fptr;
}

void clint_handle_SIP(void){
    // unused
}

void clint_handle_TIP(void){
    uint32_t * mtimelo = (uint32_t*)(CLINT_MTIMELO);
    uint32_t * mtimehi = (uint32_t*)(CLINT_MTIMEHI);
    
    *mtimelo = 0;
    *mtimehi = 0;
    
    if(tip_callback != 0){
      tip_callback();  
    }
}
