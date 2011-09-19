/***************************************************************************//**
  @ingroup timer
  @defgroup timer_lpc17xx_rit Порт таймера для LPC17xx
  Порт для работы с таймером для микроконтроллеров семейства LPC17xx (Cortex-M3).
  Для получения системного счетчика использует RIT (Repetitive Interrupt Timer).
  *****************************************************************************/

/***************************************************************************//**
  @ingroup timer_lpc17xx_rit
  @file ports/lpc17xx/clock_arch.h
  Файл содержит определение типов и констант для работы с системным счетчиком
  в LPC17xx с использованием RIT.
  @date 10.06.2011
  @author Borisov Alexey <borisov@lcard.ru>
 ******************************************************************************/


#ifndef CLOCK_ARCH_H_
#define CLOCK_ARCH_H_

#define CLOCK_CONF_SECOND 1000

typedef unsigned int t_clock;

#endif /* SYSTIC_ARCH_H_ */
