/*
 * SPDX-FileCopyrightText: 2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define KBD_ATTIVE_LEVEL      1
#define KBD_TICKS_INTERVAL_US 500

#define KBD_ROW_NUM  6
#define KBD_COL_NUM  18

#define KBD_ROW_IO_0 37
#define KBD_ROW_IO_1 38
#define KBD_ROW_IO_2 39
#define KBD_ROW_IO_3 40
#define KBD_ROW_IO_4 41
#define KBD_ROW_IO_5 42

#define KBD_COL_IO_0 7
#define KBD_COL_IO_1 8
#define KBD_COL_IO_2 9
#define KBD_COL_IO_3 10
#define KBD_COL_IO_4 11
#define KBD_COL_IO_5 12
#define KBD_COL_IO_6 13
#define KBD_COL_IO_7 14
#define KBD_COL_IO_8 15
#define KBD_COL_IO_9 16
#define KBD_COL_IO_10 17
#define KBD_COL_IO_11 18
#define KBD_COL_IO_12 20
#define KBD_COL_IO_13 21
#define KBD_COL_IO_14 47
#define KBD_COL_IO_15 48
#define KBD_COL_IO_16 45
#define KBD_COL_IO_17 35

#define KBD_OUTPUT_IOS {KBD_ROW_IO_0, KBD_ROW_IO_1, KBD_ROW_IO_2, KBD_ROW_IO_3, KBD_ROW_IO_4, KBD_ROW_IO_5}
#define KBD_INPUT_IOS  {KBD_COL_IO_0, KBD_COL_IO_1, KBD_COL_IO_2, KBD_COL_IO_3, KBD_COL_IO_4, KBD_COL_IO_5, \
                        KBD_COL_IO_6, KBD_COL_IO_7, KBD_COL_IO_8, KBD_COL_IO_9, KBD_COL_IO_10, KBD_COL_IO_11,\
                        KBD_COL_IO_12, KBD_COL_IO_13, KBD_COL_IO_14, KBD_COL_IO_15, KBD_COL_IO_16, KBD_COL_IO_17}

#ifdef __cplusplus
}
#endif
