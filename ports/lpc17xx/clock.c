/*
 * systicks.c
 *
 */

#include "clock.h"
#include "LPC17xx.h"
#include "iolpc17XX.h"
#include "system_LPC17xx.h"


volatile t_clock g_systicks;


/*************************************************************************
 * инициализация системного таймера
 * использует для этого RIT
 * ***********************************************************************/
void clock_init_val(t_clock init_val)
{
    g_systicks = init_val;

    LPC_SC->PCONP |= LPC_SC_PCONP_PCRIT_Msk;

    LPC_RIT->RICTRL =0;
    LPC_RIT->RICOUNTER = 0;
    LPC_RIT->RICOMPVAL = SystemCoreClock / (4 * 1000);
    LPC_RIT->RIMASK = 0x0;

    LPC_RIT->RICTRL = LPC_RIT_RICTRL_RITENCLR_Msk | LPC_RIT_RICTRL_RITEN_Msk | LPC_RIT_RICTRL_RITENBR_Msk;

    NVIC->ISER[ 0 ] = LPC_NVIC_ISER0_ISE_RIT_Msk;
}


//получить кол-во системных тиков
t_clock clock_time(void)
{
    return g_systicks;
}

//обработка прерывания от RIT - обновление числа тиков
void RIT_IRQHandler(void)
{
    LPC_RIT->RICTRL |= LPC_RIT_RICTRL_RITINT_Msk;
    g_systicks++;
}

