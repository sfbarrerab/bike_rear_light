#pragma once
#include <stdint.h>

// Define a struct to hold the key-value pair
typedef struct designs_dic_t{
    int key;
    uint8_t value[8];
}designs_dic_t;

extern struct designs_dic_t designs_dic[5];