/***************************************************************************//**
  @addtogroup ltimer
  @{
  @file lclock.h
  Файл содержит заголовки функций для работы с системным счетчиком. Сами функции
  реализуются портом для соответствующей платформы.
  @author Borisov Alexey <borisov@lcard.ru>
  *****************************************************************************/
#ifndef LCLOCK_H_
#define LCLOCK_H_

#include "lclock_arch.h"
#include "lcspec.h"

#ifndef LCLOCK_TICKS_PER_SECOND
    /** Константа, определяющее количество отсчетов системного счетчика в секунду */
    #define LCLOCK_TICKS_PER_SECOND 1000
#endif

#if LCLOCK_TICKS_PER_SECOND == 1000
    /** Макрос для перевода интервала в мс в количество системных клоков */
    #define LTIMER_MS_TO_CLOCK_TICKS(tout)  (tout)
    /** Макрос для перевода интервала в количестве системных клоков в интервал в мс */
    #define LTIMER_CLOCK_TICKS_TO_MS(tout)  (tout)
#else
    #define LTIMER_MS_TO_CLOCK_TICKS(tout) ((tout)*LCLOCK_TICKS_PER_SECOND/1000)
    #define LTIMER_CLOCK_TICKS_TO_MS(tout) ((tout)*1000/LCLOCK_TICKS_PER_SECOND)
#endif


/** Маска для выделения старшего бита в типе #t_lclock_ticks */
#define LCLOCK_HIGH_BIT        (((t_lclock_ticks)-1)/2 + 1)
/** Проверка установлен ли старший бит в интервале (если интервал получен
    разностью значений системных клоков, то можно использовать как признак,
    отрицательный ли интервал */
#define LCLOCK_IS_NEG(clock)   ((clock) & LCLOCK_HIGH_BIT)


#ifdef __cplusplus
extern "C" {
#endif
/** Инициализация системного счетчика заданным значением и его запуск */
void lclock_init_val(t_lclock_ticks init_val);
/** Получение текущего значения системного счетчика */
t_lclock_ticks lclock_get_ticks(void);

/** Запуск системного счетчика в случае, если его начальное значение не важно */
static LINLINE void lclock_init(void) {
    lclock_init_val(0);
}

/** Проверка, был ли уже инициализирован клок */
int lclock_is_initialized(void);

/** Запрет работы системного клока */
void lclock_disable(void);


#ifdef __cplusplus
}
#endif


#endif /* LCLOCK_H_ */

/** @} */
