# makefile для включения в проект.
#
# на входе принимает параметры:
#  TARGET_CPU (или может быть переопределен через LTIMER_TARGET) - если явно
#                не установлена переменная LTIMER_PORT, то по данной переменной
#                выбирается подходящий порт
#  LTIMER_PORT - опционально можно явно указать порт (на случай, если несколько
#                портов могут относится к одной архитектуре)
#  LTIMER_DIR  - путь к данному файлу относительно директории сборки проекта
#                (по-умолчанию lib/ltimer)
#  LSCPEC_DIR  - путь к определениям к lcspec (по-умолчанию lib/lcspec)
#
# устанавливает следующие параметры:
#  LTIMER_SRC      - исходные файлы на C
#  LTIMER_INC_DIRS - директории с заголовками, которые должны быть добавлены
#                    в список директорий для поиска заголовков проекта

LCSPEC_DIR ?= ./lib/lcspec
LTIMER_DIR ?= ./lib/ltimer
LTIMER_TARGET ?= $(TARGET_CPU)


ifndef LTIMER_PORT
    ifeq ($(LTIMER_TARGET), lpc17xx)
        LTIMER_PORT = cm_systick
    else ifeq ($(LTIMER_TARGET), lpc43xx)
        LTIMER_PORT = cm_systick
    else ifeq ($(LTIMER_TARGET), lpc11u6x)
        LTIMER_PORT = cm_systick
    else ifeq ($(LTIMER_TARGET), bf609)
        LTIMER_PORT = bf_core_tmr
    else ifeq ($(LTIMER_TARGET), imx6)
        LTIMER_PORT = imx6_epit
    endif
endif

ifndef LTIMER_PORT
    $(error unknown port. LTIMER_PORT or one of supported target in LTIMER_TARGET or TARGET_CPU must be specified)
endif

LTIMER_SRC := $(LTIMER_DIR)/ports/$(LTIMER_PORT)/lclock.c
LTIMER_INC_DIRS := $(LCSPEC_DIR) $(LTIMER_DIR) $(LTIMER_DIR)/ports/$(LTIMER_PORT)
