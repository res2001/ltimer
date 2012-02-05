/***************************************************************************//**
  @addtogroup timer
  @{
  @file clock.h
  Файл содержит заголовки функций для работы с системным счетчиком. Сами функции
  реализуются портом для соответствующей платформы.
  @date 27.08.2010
  @author Borisov Alexey <borisov@lcard.ru>
  *****************************************************************************/
#ifndef CLOCK_H_
#define CLOCK_H_

#include "clock_arch.h"
#include "lcspec.h"

#ifndef CLOCK_CONF_SECOND
    /** Константа, определяющее количество отсчетов симтемного счетчика в секунду */
    #define CLOCK_CONF_SECOND 1000
#endif

#ifdef __cplusplus
extern "C" {
#endif
/** Инициализация системного счетчика заданным значением и его запуск */
void clock_init_val(t_clock init_val);
/** Получение текущего значения системного счетчика */
t_clock clock_time(void);

#ifdef __cplusplus
}
#endif


/** Запуск системного счетчика в случае, если его начальное значение не важно */
static LINLINE void clock_init(void)
{
    clock_init_val(0);
}


#endif /* CLOCK_H_ */

/** @} */
