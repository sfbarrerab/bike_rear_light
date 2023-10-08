#include "design_storage.h"

designs_dic_t designs_dic[NUMBER_OF_DESIGNS];

void init_designs_dic(){
    for(uint8_t i = 0; i < NUMBER_OF_DESIGNS; i++){
        designs_dic[i].key = i;
    }

    designs_dic[0].value = DEFAULT_DESIGN_ONE;
}