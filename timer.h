#ifndef __TIMER_H__
#define __TIMER_H__



#include "clock.h"

typedef struct timer {
  t_clock start;
  t_clock interval;
} t_timer;

void timer_set(struct timer *t, t_clock interval);
void timer_reset(struct timer *t);
void timer_restart(struct timer *t);
int timer_expired(struct timer *t);
t_clock timer_expiration(t_timer* t);
int timer_expired_at(t_timer *t, t_clock cur_time);
void timer_set_at(t_timer *t, t_clock interval, t_clock start_time);
t_clock timer_expiration_from(t_timer* t, t_clock cur_time);



#endif /* __TIMER_H__ */

/** @} */

