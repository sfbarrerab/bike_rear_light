#pragma once
#include <stdint.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "nvs_wr.h"

#define NUMBER_OF_DESIGNS 6

// all the designs are transposed to match let the C port in the left side
#define DEFAULT_DESIGN_ONE 0x1BBC6E78786EBC1BULL
#define DEFAULT_DESIGN_TWO 0x619A2F3C3C2F9A61ULL
#define DEFAULT_DESIGN_THREE 0x809AEB7C7CEB9A80ULL
#define DEFAULT_DESIGN_FOUR 0x1ABC4E7C4EBC1A00ULL
#define DEFAULT_DESIGN_FIVE 0x6064AEFEFAA20C00ULL
#define DEFAULT_DESIGN_SIX 0xF0577F57F3010700ULL

// Define a struct to hold the key-value pair
typedef struct designs_dic_t{
    char key[20];
    uint64_t value;
}designs_dic_t;

extern designs_dic_t prev_designs_dic[NUMBER_OF_DESIGNS];
extern designs_dic_t current_designs_dic[NUMBER_OF_DESIGNS];

void init_designs_dic();
void store_new_designs();