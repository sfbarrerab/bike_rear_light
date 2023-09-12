#pragma once
#include "nvs_flash.h"
#include "nvs.h"
#include <stdio.h>
#include <inttypes.h>

#define DEFAULT_DESIGN_ONE 0x423C7EDBFF66A581ULL


void nvs_init();
void nvs_write(int64_t data);
void nvs_read();