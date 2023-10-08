#pragma once
#include <stdint.h>

#define NUMBER_OF_DESIGNS 5
#define DEFAULT_DESIGN_ONE 0x423C7EDBFF66A581ULL

// Define a struct to hold the key-value pair
typedef struct designs_dic_t{
    int key;
    uint64_t value;
}designs_dic_t;

extern designs_dic_t designs_dic[NUMBER_OF_DESIGNS];

void init_designs_dic();