#include "design_storage.h"

struct designs_dic_t designs_dic[5];

uint64_t uint8_array_to_uint64(const uint8_t uint8_array[8]) {
    uint64_t result = 0;
    
    for (int i = 0; i < 8; i++) {
        result |= (uint64_t)uint8_array[i] << (8 * (7 - i));
    }
    
    return result;
}

void init_designs_dic(){
    
}