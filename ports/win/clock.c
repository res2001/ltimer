/***************************************************************************//**
  @ingroup timer_win
  @file ports/win/clock.c
  Файл содержит реализацию функций для работы с системным счетчиком в OC Windows
  через функцию GetTickCount().
  @date 16.09.2011
  @author Borisov Alexey <borisov@lcard.ru>
 ******************************************************************************/

#include "clock.h"

void clock_init_val(t_clock init_val)
{
    /* инициализация системного таймера. не требуется */
}

t_clock clock_time(void)
{
    return GetTickCount();
}



