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
    /** Макрос для перевода интервала в мс в количество отсчетов системного счетчика */
    #define LTIMER_MS_TO_CLOCK_TICKS(tout)  (tout)
    /** Макрос для перевода интервала в количестве отсчетов системного счетчика в интервал в мс */
    #define LTIMER_CLOCK_TICKS_TO_MS(tout)  (tout)
#else
    #define LTIMER_MS_TO_CLOCK_TICKS(tout) ((tout)*LCLOCK_TICKS_PER_SECOND/1000)
    #define LTIMER_CLOCK_TICKS_TO_MS(tout) ((tout)*1000/LCLOCK_TICKS_PER_SECOND)
#endif


/** Маска для выделения старшего бита в типе #t_lclock_ticks */
#define LCLOCK_HIGH_BIT        (((t_lclock_ticks)-1)/2 + 1)
/** Проверка, установлен ли старший бит для типа #t_lclock_ticks. Если
    переменная данного типа содержит интервал в отсчетах системного счетчика,
    полученный как разность значений отсчетов счетчика, то данный макрос
    можно использовать как признак, отрицательный ли интервал */
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

/** Проверка, был ли уже инициализирован системный счетчик */
int lclock_is_initialized(void);

/** Запрет работы системного счетчика */
void lclock_disable(void);

/** Для некоторых портов есть возможность реализовать пользовательскую функцию,
 * которая будет вызываться раз в мс. Для этого необходимо глобально определить
 * LCLOCK_USE_USER_MS_CB и реализовать функцию lclock_user_ms_cb() */
#ifdef LCLOCK_USE_USER_MS_CB
    extern void lclock_user_ms_cb(void);
#endif


#ifdef __cplusplus
}
#endif


#endif /* LCLOCK_H_ */

/** @} */
