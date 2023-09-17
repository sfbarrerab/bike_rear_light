#pragma once
#include "nvs_flash.h"
#include "nvs.h"
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define DEFAULT_DESIGN_ONE 0x423C7EDBFF66A581ULL

extern uint64_t design_one;

void nvs_init();
void nvs_write(uint64_t data);
void nvs_read();