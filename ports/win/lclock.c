/***************************************************************************//**
  @ingroup ltimer_win
  @file ports/win/lclock.c
    Файл содержит реализацию функций для работы с системным счетчиком
    в OC Windows через функцию GetTickCount().
  @author Borisov Alexey <borisov@lcard.ru>
 ******************************************************************************/

#include "lclock.h"

void lclock_init_val(t_lclock_ticks init_val) {

}

char lclock_is_initialized(void) {
    return 1;
}

t_lclock_ticks lclock_get_ticks(void) {
    return GetTickCount();
}



