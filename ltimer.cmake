# Файл для включения в проект на CMAKE.
# Перед включением необходимо определить переменные
#    LTIMER_DIR   - путь к директории, где находится ltimer.cmake
#    LCSPEC_DIR   - путь к директории, где находится файлы lcspec
#
# После включения будут установлены следующие перменные:
#   LTIMER_HEADERS      - используемые заголовочные файлы
#   LTIMER_SOURCES      - используемые файлы исходных кодов
#   LTIMER_LIBS         - используемые библиотеки
#   LTIMER_DEFINITIONS  - используемые определения компилятора

cmake_policy(PUSH)

cmake_minimum_required(VERSION 2.6)

include(CheckLibraryExists)
include(CheckFunctionExists)


set (LTIMER_HEADERS 
     ${LTIMER_DIR}/ltimer.h
     ${LCSPEC_DIR}/lcspec.h
    )



if(UNIX)
    set(LTIMER_SOURCES ${LTIMER_DIR}/ports/linux/lclock.c)
    include_directories(${LTIMER_DIR}/ports/linux)
elseif(WIN32)
    set(LTIMER_SOURCES ${LTIMER_DIR}/ports/win/lclock.c)
    include_directories(${LTIMER_DIR}/ports/win)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "QNX4")
    set(LTIMER_SOURCES ${LTIMER_DIR}/ports/linux/lclock.c)
    include_directories(${LTIMER_DIR}/ports/linux)
endif(UNIX)

include_directories(${LCSPEC_DIR} ${LTIMER_DIR})

if(UNIX)
    check_library_exists(rt clock_gettime "" HAVE_LIBRT)
    if(HAVE_LIBRT)
        set(LTIMER_LIBS ${TIMER_LIBS} rt)
    else(HAVE_LIBRT)
        set(CMAKE_REQUIRED_INCLUDES time.h)
        # проверяем наличие clock_gettime вне librt.
        # если нет, то можем откатиться к gettimeofday
        check_function_exists("clock_gettime" HAVE_CLOCKGETTIME)

        if(NOT HAVE_CLOCKGETTIME)
            set(LTIMER_DEFINITIONS NO_CLOCKGETTIME)
         endif(NOT HAVE_CLOCKGETTIME)
    endif(HAVE_LIBRT)
endif(UNIX)

cmake_policy(POP)
