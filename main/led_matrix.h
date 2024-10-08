#pragma once
#include "driver/spi_master.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include <stdint.h>
#include "design_storage.h"

#define PIN_NUM_CLK 8
#define PIN_NUM_MISO 9
#define PIN_NUM_MOSI 10
#define PIN_NUM_CS 20


#define DECODE_MOD_ADDR 0X9
#define INTENSITY_ADDR 0XA
#define SCAN_LIMIT_ADDR 0XB
#define SHUTDOWN_ADDR 0XC
#define DISPLAY_TEST_ADDR 0XF

void init_matrix_led_spi();
void clear_led_matrix();
void init_led_driver();
void draw_led_matrix(uint64_t data);
void display_designs_task();