/***************************************************************************//**
  @ingroup ltimer
  @defgroup ltimer_imx6_epit Порт таймера для процессора iMX6
  Порт для работы с таймером для процессоров iMX6 от Freescale на базе таймера EPIT.
  Для данного порта необходим файл в проекте lclock_conf.h, который бы задавал номер 
  используемого EPIT-таймера
  *****************************************************************************/

/***************************************************************************//**
  @ingroup ltimer_imx6_epit
  @file ports/imx6_epit/lclock_arch.h
  Файл содержит определение типов и констант для работы с системным таймером
  для процессоров iMX6 от Freescale на базе таймера EPIT.
  @author Borisov Alexey <borisov@lcard.ru>
 ******************************************************************************/
 
 
#ifndef LCLOCK_ARCH_H_
#define LCLOCK_ARCH_H_

#include "lclock_conf.h"

#ifndef LCLOCK_TICKS_PER_SECOND
    #define LCLOCK_TICKS_PER_SECOND 1000000
#endif

typedef unsigned int t_lclock_ticks;

#endif /* LCLOCK_ARCH_H_ */
