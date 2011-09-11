/*
 * systics.h
 *
 *  Created on: 27.08.2010
 *      Author: borisov
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "clock_arch.h"


#ifndef CLOCK_CONF_SECOND
    #define CLOCK_CONF_SECOND 1000
#endif

void clock_init(t_clock init_val);
t_clock clock_time(void);


#endif /* SYSTICS_H_ */
