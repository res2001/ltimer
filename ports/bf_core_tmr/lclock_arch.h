/***************************************************************************//**
  @ingroup ltimer
  @defgroup ltimer_bf_core_tmr Порт таймера для BlackFin
  Порт для работы с таймером для сигнальных процессоров BlackFin от Analog Devices.
  Для получения системного счетчика использует таймер ядра
  *****************************************************************************/

/***************************************************************************//**
  @ingroup ltimer_bf_core_tmr
  @file ports/bf_core_tmr/lclock_arch.h
  Файл содержит определение типов и констант для работы с системным счетчиком
  для процессоров BlackFin
  @author Borisov Alexey <borisov@lcard.ru>
 ******************************************************************************/


#ifndef LCLOCK_ARCH_H_
#define LCLOCK_ARCH_H_

#include "lcspec.h"

#ifndef LCLOCK_TICKS_PER_SECOND
    /** Количество тиков системного таймера в секунду */
    #define LCLOCK_TICKS_PER_SECOND 1000
#endif

/** Тип для представления количества системных тиков */
typedef unsigned int t_lclock_ticks;


extern volatile t_lclock_ticks lclock_systicks;


static LINLINE t_lclock_ticks lclock_get_ticks(void) {
    return lclock_systicks;
}

#endif /* LCLOCK_ARCH_H_ */
