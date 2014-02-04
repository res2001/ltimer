/***************************************************************************//**
  @ingroup timer_imx6_epit
  @file ports/imx6_epit/clock.c
  Файл содержит реализацию функций для работы с системным счетчиком
  для процессора imx6, использующую один из EPIT-таймеров.
  @date 30.10.2013
  @author Borisov Alexey <borisov@lcard.ru>
 ******************************************************************************/
#include <stdint.h>
#include "clock.h"
#include "core/ccm_pll.h"
#include "registers/regsepit.h"

//! @brief Available clock sources for the timers.
enum _timer_clock_sources  {
    CLKSRC_OFF = 0,     //!< clock source is OFF
    CLKSRC_IPG_CLK = 1, //!< clock source is peripheral clock
    CLKSRC_PER_CLK = 2, //!< clock source is high-freq reference clock
    CLKSRC_CLKIN = 3,   //!< clock source is external from a CLKIN input
    CLKSRC_CKIL = 3     //!< clock source is low-freq reference clock
};

static uint8_t f_initialized = 0;

/*************************************************************************
 * инициализация системного таймера
 * использует для этого RIT
 * ***********************************************************************/
void clock_init_val(t_clock init_val) {
    uint32_t freq = get_main_clock(IPG_CLK);
    uint32_t control_reg_tmp = 0;
    uint32_t base = REGS_EPIT_BASE(CLOCK_CONF_EPIT_INST);
    uint32_t prescaler = freq / CLOCK_CONF_SECOND;

    // enable the source clocks to the EPIT port
    clock_gating_config(base, CLOCK_ON);

    // start with a known state by disabling and reseting the module
    HW_EPIT_CR_WR(CLOCK_CONF_EPIT_INST, BM_EPIT_CR_SWR);

    // wait for the reset to complete
    while ((HW_EPIT_CR(CLOCK_CONF_EPIT_INST).B.SWR) != 0) ;

    // set the reference source clock for the counter
    control_reg_tmp |= BF_EPIT_CR_CLKSRC(CLKSRC_IPG_CLK);

    // set the counter clock prescaler value - 0 to 4095
    control_reg_tmp |= BF_EPIT_CR_PRESCALAR(prescaler-1);


    // set behavior for low power mode
    control_reg_tmp |= BM_EPIT_CR_WAITEN;

    control_reg_tmp |= BM_EPIT_CR_STOPEN;

    // make the counter start from a known value when enabled, this is loaded from
    // EPITLR register if RLD=reload_mode=1 or 0xFFFFFFFF if RLD=reload_mode=0
    control_reg_tmp |= BM_EPIT_CR_IOVW | BM_EPIT_CR_ENMOD;

    // finally write the control register
    HW_EPIT_CR_WR(CLOCK_CONF_EPIT_INST, control_reg_tmp);

    // finally, enable the counter
    HW_EPIT_CR_SET(CLOCK_CONF_EPIT_INST, BM_EPIT_CR_EN);

    f_initialized = 1;
}

int clock_is_initialized(void) {
    return f_initialized;
}


/* получить кол-во системных тиков из статичиской переменной */
t_clock clock_time(void) {
    uint32_t val = -HW_EPIT_CNR_RD(CLOCK_CONF_EPIT_INST);
    return val;
}



