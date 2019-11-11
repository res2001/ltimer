/***************************************************************************//**
  @ingroup ltimer_linux
  @file ports/linux/lclock.c
  Файл содержит реализацию функций для работы с системным счетчиком в OC Linux
  через clock_gettime() из librt.
  @date 16.09.2011
  @author Borisov Alexey <borisov@lcard.ru>
 ******************************************************************************/

#include "lclock.h"
#include <time.h>
#include <stddef.h>


#ifdef HAVE_CONFIG_H
    #include "config.h"
#endif

#ifdef HAVE_SYS_TIMERS_H
    #include <sys/timers.h>
#endif



#ifdef NO_CLOCKGETTIME
    #include <sys/time.h>
#else

#ifdef CLOCK_MONOTONIC
    #define LTIMER_CLK_ID CLOCK_MONOTONIC
#else
    #define LTIMER_CLK_ID TIMEOFDAY
#endif

#endif

void lclock_init_val(t_lclock_ticks init_val) {
    /* инициализация системного таймера не требуется */
}

char lclock_is_initialized(void) {
    return 1;
}

t_lclock_ticks lclock_get_ticks(void) {
#ifdef NO_CLOCKGETTIME
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec*1000 + tv.tv_usec/1000;
#else
    struct timespec tp;
    clock_gettime(LTIMER_CLK_ID, &tp);
    return tp.tv_sec*1000 + tp.tv_nsec/1000000;
#endif
}



