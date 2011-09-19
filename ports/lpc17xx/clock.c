/***************************************************************************//**
  @ingroup timer_lpc17xx_rit
  @file ports/lpc17xx/clock.c
  Файл содержит реализацию функций для работы с системным счетчиком
  в LPC17xx с использованием RIT.
  @date 16.09.2011
  @author Borisov Alexey <borisov@lcard.ru>
 ******************************************************************************/
#include "clock.h"
#include "LPC17xx.h"
#include "iolpc17XX.h"
#include "system_LPC17xx.h"


static volatile t_clock f_systicks;


/*************************************************************************
 * инициализация системного таймера
 * использует для этого RIT
 * ***********************************************************************/
void clock_init_val(t_clock init_val)
{
    /* инициализруем счетчик */
    f_systicks = init_val;

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
    NVIC->ISER[ 0 ] = LPC_NVIC_ISER0_ISE_RIT_Msk;
}


/* получить кол-во системных тиков из статичиской переменной */
t_clock clock_time(void)
{
    return f_systicks;
}

/* обработка прерывания от RIT - обновление числа тиков */
void RIT_IRQHandler(void)
{
    LPC_RIT->RICTRL |= LPC_RIT_RICTRL_RITINT_Msk;
    f_systicks++;
}

