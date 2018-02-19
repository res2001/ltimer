/***************************************************************************//**
  @ingroup ltimer_cm_systick
  @file ports/cm_systick/lclock.c
  Файл содержит реализацию функций для работы с системным счетчиком
  для Cortex-M с использованием системного таймера.

  Порт требует наличие файла chip.h, который включает определение LPC_SYSCLK
  и включать функции CMSIS (используется SysTick_Config).
  Если LPC_SYSCLK не определена, то используется значение из переменной SystemCoreClock

  @author Borisov Alexey <borisov@lcard.ru>
 ******************************************************************************/
#include "lclock.h"
/* файл должен определять LPC_SYSCLK и включать cmsis.h */
#include "chip.h"

#ifndef LPC_SYSCLK
    extern uint32_t SystemCoreClock;
    #define LPC_SYSCLK SystemCoreClock
#endif

volatile t_lclock_ticks lclock_systicks;
static uint8_t f_initialized = 0;


/*************************************************************************
 * инициализация системного таймера
 * ***********************************************************************/
void lclock_init_val(t_lclock_ticks init_val) {
    /* инициализируем счетчик */
    lclock_systicks = init_val;
    SysTick_Config(LPC_SYSCLK / LCLOCK_TICKS_PER_SECOND);
    f_initialized = 1;
}

int lclock_is_initialized(void) {
    return f_initialized;
}

void lclock_disable(void) {
    SysTick->CTRL = 0;
    f_initialized = 0;
}

/* обработка прерывания от системного таймера - обновление числа тиков */
#include "lcspec_interrupt.h"
#if defined ( __ICCARM__ )
void SysTick_Handler(void) {
#else
void SysTick_IRQHandler(void) {
#endif
    lclock_systicks++;
#ifdef LCLOCK_USE_USER_MS_CB
    lclock_user_ms_cb();
#endif
}

