/***************************************************************************//**
  @ingroup ltimer_lpc17xx_rit
  @file ports/lpc17xx_rit/lclock.c
  Файл содержит реализацию функций для работы с системным счетчиком
  в LPC17xx с использованием RIT.
   @author Borisov Alexey <borisov@lcard.ru>
 ******************************************************************************/
#include "lclock.h"
#include "LPC17xx.h"
#include "iolpc17XX.h"
#include "system_LPC17xx.h"


static volatile t_lclock_ticks lclock_systicks;
static uint8_t f_initialized = 0;


/*************************************************************************
 * инициализация системного таймера
 * использует для этого RIT
 * ***********************************************************************/
void lclock_init_val(t_lclock_ticks init_val) {
    /* инициализируем счетчик */
    lclock_systicks = init_val;

    /* подаем питание на RIT */
    LPC_SC->PCONP |= LPC_SC_PCONP_PCRIT_Msk;

    /* останавливаем счетчик (на случай если был запущен) и иницилизируем его */
    LPC_RIT->RICTRL =0;
    LPC_RIT->RICOUNTER = 0;
    LPC_RIT->RICOMPVAL = SystemCoreClock / (4 * 1000);
    LPC_RIT->RIMASK = 0x0;

    LPC_RIT->RICTRL = LPC_RIT_RICTRL_RITENCLR_Msk | LPC_RIT_RICTRL_RITEN_Msk
            | LPC_RIT_RICTRL_RITENBR_Msk;

    /* разрешаем прерывания */
    NVIC_EnableIRQ(RIT_IRQn);


    f_initialized = 1;
}

int lclock_is_initialized(void) {
    return f_initialized;
}


t_lclock_ticks lclock_get_ticks(void) {
    return lclock_systicks;
}

void lclock_disable(void) {
    NVIC_DisableIRQ(RIT_IRQn);
    LPC_RIT->RICTRL = 0;
    f_initialized = 0;
}


/* обработка прерывания от RIT - обновление числа тиков */
#include "lcspec_interrupt.h"
void RIT_IRQHandler(void) {
    LPC_RIT->RICTRL |= LPC_RIT_RICTRL_RITINT_Msk;
    lclock_systicks++;
}

