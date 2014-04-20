/***************************************************************************//**
  @ingroup timer_cm4_systick
  @file ports/cm4_systick/clock.c
  Файл содержит реализацию функций для работы с системным счетчиком
  для Cortex-M4 с использованием системного таймера.

  Порт требует наличие файла chip.h, который включает определение LPC_SYSCLK
  и включать функции CMSIS (используется SysTick_Config).
  Если LPC_SYSCLK не определена, то используется значение из переменной SystemCoreClock

  @date 27.01.2014
  @author Borisov Alexey <borisov@lcard.ru>
 ******************************************************************************/
#include "clock.h"
/* файл должен определять LPC_SYSCLK и включать cmsis.h */
#include "chip.h"

#ifndef LPC_SYSCLK
    extern uint32_t SystemCoreClock;
    #define LPC_SYSCLK SystemCoreClock
#endif

static volatile t_clock f_systicks;
static uint8_t f_initialized = 0;


/*************************************************************************
 * инициализация системного таймера
 * ***********************************************************************/
void clock_init_val(t_clock init_val) {
    /* инициализруем счетчик */
    f_systicks = init_val;
    SysTick_Config(LPC_SYSCLK / CLOCK_CONF_SECOND);
    f_initialized = 1;
}

int clock_is_initialized(void) {
    return f_initialized;
}

/* получить кол-во системных тиков из статичиской переменной */
t_clock clock_time(void) {
    return f_systicks;
}

/* обработка прерывания от системного таймера - обновление числа тиков */
#if defined ( __ICCARM__ )
void SysTick_Handler(void) {
#else
void SysTick_IRQHandler(void) {
#endif
    f_systicks++;
}

