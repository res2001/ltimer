/***************************************************************************//**
  @ingroup ltimer
  @defgroup ltimer_lpc17xx_rit Порт таймера для LPC17xx
  Порт для работы с таймером для микроконтроллеров семейства LPC17xx (Cortex-M3).
  Для получения системного счетчика использует RIT (Repetitive Interrupt Timer).
  *****************************************************************************/

/***************************************************************************//**
  @ingroup timer_lpc17xx_rit
  @file ports/lpc17xx_rit/lclock_arch.h
  Файл содержит определение типов и констант для работы с системным счетчиком
  в LPC17xx с использованием RIT.
  @author Borisov Alexey <borisov@lcard.ru>
 ******************************************************************************/


#ifndef LCLOCK_ARCH_H_
#define LCLOCK_ARCH_H_

#define LCLOCK_TICKS_PER_SECOND 1000

typedef unsigned int t_lclock_ticks;

#endif /* LCLOCK_ARCH_H_ */
