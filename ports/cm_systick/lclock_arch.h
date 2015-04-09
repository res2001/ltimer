/***************************************************************************//**
  @ingroup ltimer
  @defgroup ltimer_cm_systick Порт таймера для Cortex-M
  Порт для работы с таймером для микроконтроллеров с ядром Cortex-M.
  Для получения системного счетчика использует системный таймер (SysTick).
  *****************************************************************************/

/***************************************************************************//**
  @ingroup ltimer_cm_systick
  @file ports/cm_systick/lclock_arch.h
  Файл содержит определение типов и констант для работы с системным счетчиком
  для процессоров с ядром Cortex-M с использованием системного таймера.
  @author Borisov Alexey <borisov@lcard.ru>
 ******************************************************************************/


#ifndef LCLOCK_ARCH_H_
#define LCLOCK_ARCH_H_

#include "lcspec.h"

/** Количество тиков системного таймера в секунду */
#define LCLOCK_TICKS_PER_SECOND 1000
/** Тип для представления количества системных тиков */
typedef unsigned int t_lclock_ticks;


extern volatile t_lclock_ticks lclock_systicks;


static LINLINE t_lclock_ticks lclock_get_ticks(void) {
    return lclock_systicks;
}

#endif /* LCLOCK_ARCH_H_ */
