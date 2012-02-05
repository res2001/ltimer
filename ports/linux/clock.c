/***************************************************************************//**
  @ingroup timer_linux
  @file ports/linux/clock.c
  Файл содержит реализацию функций для работы с системным счетчиком в OC Linux
  через clock_gettime() из librt.
  @date 16.09.2011
  @author Borisov Alexey <borisov@lcard.ru>
 ******************************************************************************/

#include "clock.h"
#include "time.h"

void clock_init_val(t_clock init_val)
{
    /* инициализация системного таймера. не требуется */
}

t_clock clock_time(void)
{
    struct timespec tp;
    clock_gettime(CLOCK_MONOTONIC, &tp);
    return tp.tv_sec*1000 + tp.tv_nsec/1000000;
}



