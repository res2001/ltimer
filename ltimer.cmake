# Файл для включения в проект на CMAKE.
# Перед включением необходимо определить переменные
#    LTIMER_DIR   - путь к директории, где находится ltimer.cmake
#    LCSPEC_DIR   - путь к директории, где находится файлы lcspec
#
# После включения будут установлены следующие перменные:
#   LTIMER_HEADERS - используемые заголовочные файлы
#   LTIMER_SOURCES - используемые файлы исходных кодов
#   LTIMER_LIBS    - используемые библиотеки

cmake_policy(PUSH)

cmake_minimum_required(VERSION 2.6)

include(CheckLibraryExists)


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
    if(${HAVE_LIBRT})
        set(LTIMER_LIBS ${TIMER_LIBS} rt)
    endif(${HAVE_LIBRT})
endif(UNIX)

cmake_policy(POP)
