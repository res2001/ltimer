/***************************************************************************//**
  @file clock_arch.c
  Файл содержит определение типов и констант для работы с системным счетчиком
  в OC Windows через функцию GetTickCount().
  @date 10.06.2011
  @author Borisov Alexey <borisov@lcard.ru>
 ******************************************************************************/

#ifndef CLOCK_ARCH_H_
#define CLOCK_ARCH_H_

#include "Windows.h"

/* GetTickCount() возвращает счетчик в милисекундах */
#define CLOCK_CONF_SECOND 1000

/* GetTickCount() возвращает в качестве значения DWORD */
typedef DWORD t_clock;

#endif /* CLOCK_ARCH_H_ */
