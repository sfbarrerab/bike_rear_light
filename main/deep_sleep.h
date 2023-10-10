#pragma once
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include <stdint.h>
#include "esp_sleep.h"
#include "sdkconfig.h"
#include "driver/rtc_io.h"
#include "esp_system.h"
#include "led_matrix.h"

#define EXT_DEEP_SLEEP_PIN 3

void deep_sleep_task();