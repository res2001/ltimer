/***************************************************************************//**
  @ingroup timer_cm4_systick
  @file ports/cm4_systick/clock.c
  Файл содержит реализацию функций для работы с системным счетчиком
  для Cortex-M4 с использованием системного таймера.
  @date 27.01.2014
  @author Borisov Alexey <borisov@lcard.ru>
 ******************************************************************************/
#include "clock.h"
#include "cmsis.h"
#include "lpc_pin.h"
#include "chip_lpc43xx.h"

extern uint32_t SystemCoreClock;

static volatile t_clock f_systicks;


/*************************************************************************
 * инициализация системного таймера
 * ***********************************************************************/
void clock_init_val(t_clock init_val) {
    /* инициализруем счетчик */
    f_systicks = init_val;
    SysTick_Config(SystemCoreClock / CLOCK_CONF_SECOND);
}


/* получить кол-во системных тиков из статичиской переменной */
t_clock clock_time(void) {
    return f_systicks;
}

/* обработка прерывания от системного таймера - обновление числа тиков */
void SysTick_IRQHandler(void) {
    f_systicks++;
}

