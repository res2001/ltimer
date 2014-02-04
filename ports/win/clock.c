/***************************************************************************//**
  @ingroup timer_win
  @file ports/win/clock.c
  Р¤Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ СЂРµР°Р»РёР·Р°С†РёСЋ С„СѓРЅРєС†РёР№ РґР»СЏ СЂР°Р±РѕС‚С‹ СЃ СЃРёСЃС‚РµРјРЅС‹Рј СЃС‡РµС‚С‡РёРєРѕРј РІ OC Windows
  С‡РµСЂРµР· С„СѓРЅРєС†РёСЋ GetTickCount().
  @date 16.09.2011
  @author Borisov Alexey <borisov@lcard.ru>
 ******************************************************************************/

#include "clock.h"

void clock_init_val(t_clock init_val) {
    /* инициализация системного таймера не требуется */
}

int clock_is_initialized(void) {
    return 1;
}

t_clock clock_time(void) {
    return GetTickCount();
}



