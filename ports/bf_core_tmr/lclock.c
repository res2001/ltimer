/***************************************************************************//**
  @ingroup ltimer_bf_core_tmr
  @file ports/bf_core_tmr/lclock.c
  Файл содержит реализацию функций для работы с системным счетчиком
  для процессора BlackFin

  @author Borisov Alexey <borisov@lcard.ru>
 ******************************************************************************/
#include "lclock.h"
/* файл должен определять LPC_SYSCLK и включать cmsis.h */
#include "chip.h"

volatile t_lclock_ticks lclock_systicks;
static uint8_t f_initialized = 0;
ISR(lclock_isr);

/*************************************************************************
 * инициализация системного таймера
 * ***********************************************************************/
void lclock_init_val(t_lclock_ticks init_val) {
    /* инициализируем счетчик */
    lclock_systicks = init_val;
    REGISTER_ISR(6, lclock_isr);

    *pTCNTL = BITM_TCNTL_AUTORLD | BITM_TCNTL_PWR;
    *pTPERIOD = CHIP_CLKF_CCLK/LCLOCK_TICKS_PER_SECOND;
    *pTSCALE = 0;
    *pTCNTL |= BITM_TCNTL_EN;

    f_initialized = 1;
}

int lclock_is_initialized(void) {
    return f_initialized;
}

void lclock_disable(void) {
    *pTCNTL = 0;
    f_initialized = 0;
}

ISR(lclock_isr) {
    lclock_systicks++;
#ifdef LCLOCK_USE_USER_MS_CB
    lclock_user_ms_cb();
#endif
}
