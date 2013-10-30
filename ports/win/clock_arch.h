/***************************************************************************//**
  @ingroup timer
  @defgroup timer_win Порт таймера для Windows
  Порт для работы с таймером в ОС Windows. Для получения системного счетчика
  использует функцию WinApi GetTickCount().
  *****************************************************************************/
/***************************************************************************//**
  @ingroup timer_win
  @file ports/win/clock_arch.h
  Файл содержит определение типов и констант для работы с системным счетчиком
  в OC Windows через функцию GetTickCount().
  @date 10.06.2011
  @author Borisov Alexey <borisov@lcard.ru>
 ******************************************************************************/

#ifndef CLOCK_ARCH_H_
#define CLOCK_ARCH_H_

#ifndef WIN32_LEAN_AND_MEAN
    #define WIN32_LEAN_AND_MEAN
#endif
#include "Windows.h"

/* GetTickCount() возвращает счетчик в милисекундах */
#define CLOCK_CONF_SECOND 1000

/* GetTickCount() возвращает в качестве значения DWORD */
typedef DWORD t_clock;

#endif /* CLOCK_ARCH_H_ */
