/*
 * SPDX-FileCopyrightText: 2022-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include "unity.h"
#include "mcp23017.h"
#include "i2c_bus.h"
#include "esp_log.h"

#define I2C_MASTER_SCL_IO           21          /*!< gpio number for I2C master clock IO21*/
#define I2C_MASTER_SDA_IO           22          /*!< gpio number for I2C master data  IO15*/
#define I2C_MASTER_NUM              I2C_NUM_1   /*!< I2C port number for master dev */
#define I2C_MASTER_TX_BUF_DISABLE   0           /*!< I2C master do not need buffer */
#define I2C_MASTER_RX_BUF_DISABLE   0           /*!< I2C master do not need buffer */
#define I2C_MASTER_FREQ_HZ          100000      /*!< I2C master clock frequency */

static i2c_bus_handle_t i2c_bus = NULL;
static mcp23017_handle_t device = NULL;

static void mcp23017_test_init()
{
    i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = I2C_MASTER_SDA_IO,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_io_num = I2C_MASTER_SCL_IO,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = I2C_MASTER_FREQ_HZ,
    };
    i2c_bus = i2c_bus_create(I2C_MASTER_NUM, &conf);
    device = mcp23017_create(i2c_bus, 0x20);
    TEST_ASSERT(i2c_bus != NULL);
    TEST_ASSERT(device != NULL);
    TEST_ASSERT(ESP_OK == mcp23017_check_present(device));
}

static void mcp23017_test_deinit()
{
    mcp23017_delete(&device);
    TEST_ASSERT(device == NULL);
    i2c_bus_delete(&i2c_bus);
    TEST_ASSERT(i2c_bus == NULL);
}

static void mcp23017_test_read_write()
{
    uint8_t cnt = 5;
    TEST_ASSERT(ESP_OK == mcp23017_set_io_dir(device, 0x00, MCP23017_GPIOA)); //A:OUTPUT, B:INPUT
    TEST_ASSERT(ESP_OK == mcp23017_set_io_dir(device, 0xff, MCP23017_GPIOB));
    while (cnt--) {

        /*****Interrupt Test******/
        // mcp23017_interrupt_en(device, MCP23017_PIN15, 1, 0x0000); //1: compared against DEFVAL register.
        // vTaskDelay(1000 / portTICK_RATE_MS);
        // printf("Intf:%d\n",  mcp23017_get_int_flag(device));

        /*****Normal Test*****/
        TEST_ASSERT(ESP_OK == mcp23017_write_io(device, cnt, MCP23017_GPIOA));
        printf("GPIOA write = :%x\n", cnt);
        uint8_t read = mcp23017_read_io(device, MCP23017_GPIOB);
        printf("GPIOB read = :%x\n", read);
        TEST_ASSERT_EQUAL_UINT8(cnt, read);
        vTaskDelay(300 / portTICK_RATE_MS);
    }
}

TEST_CASE("Device mcp23017 test, connect A-B port together", "[mcp23017][iot][device]")
{
    mcp23017_test_init();
    mcp23017_test_read_write();
    mcp23017_test_deinit();
}
