/*
 * SPDX-FileCopyrightText: 2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/*!< Keyboard active level */
#define KBD_ATTIVE_LEVEL      1
#define KBD_TICKS_INTERVAL_US 1000

/*!< Keyboard matrix GPIO */
#define KBD_ROW_NUM  6
#define KBD_COL_NUM  17

#define KBD_ROW_IO_0 4
#define KBD_ROW_IO_1 5
#define KBD_ROW_IO_2 6
#define KBD_ROW_IO_3 7
#define KBD_ROW_IO_4 15
#define KBD_ROW_IO_5 16

#define KBD_COL_IO_0 1
#define KBD_COL_IO_1 2
#define KBD_COL_IO_2 42
#define KBD_COL_IO_3 41
#define KBD_COL_IO_4 40
#define KBD_COL_IO_5 39
#define KBD_COL_IO_6 38
#define KBD_COL_IO_7 37
#define KBD_COL_IO_8 36
#define KBD_COL_IO_9 35
#define KBD_COL_IO_10 45
#define KBD_COL_IO_11 48
#define KBD_COL_IO_12 47
#define KBD_COL_IO_13 21
#define KBD_COL_IO_14 14
#define KBD_COL_IO_15 13
#define KBD_COL_IO_16 12

#define KBD_OUTPUT_IOS {KBD_ROW_IO_0, KBD_ROW_IO_1, KBD_ROW_IO_2, KBD_ROW_IO_3, KBD_ROW_IO_4, KBD_ROW_IO_5}
#define KBD_INPUT_IOS  {KBD_COL_IO_0, KBD_COL_IO_1, KBD_COL_IO_2, KBD_COL_IO_3, KBD_COL_IO_4, KBD_COL_IO_5, \
                        KBD_COL_IO_6, KBD_COL_IO_7, KBD_COL_IO_8, KBD_COL_IO_9, KBD_COL_IO_10, KBD_COL_IO_11,\
                        KBD_COL_IO_12, KBD_COL_IO_13, KBD_COL_IO_14, KBD_COL_IO_15, KBD_COL_IO_16}

/*!< WS2812 power control GPIO */
#define KBD_WS2812_POWER_IO  1

/*!< Battery monitor GPIO */
#define KBD_BATTERY_MONITOR_IO  2

#ifdef __cplusplus
}
#endif
