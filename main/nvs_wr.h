#pragma once
#include "nvs_flash.h"
#include "nvs.h"
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

void nvs_init();
void nvs_write(char* design_name, uint64_t data);
uint64_t nvs_read(char* design_name);