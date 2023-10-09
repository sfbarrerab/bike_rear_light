#include "design_storage.h"

designs_dic_t designs_dic[NUMBER_OF_DESIGNS];

void init_designs_dic(){
    for(uint8_t i = 0; i <= NUMBER_OF_DESIGNS; i++){
        designs_dic[i].key = i;
    }

    designs_dic[0].value = DEFAULT_DESIGN_ONE;
    designs_dic[1].value = DEFAULT_DESIGN_TWO;
    designs_dic[2].value = DEFAULT_DESIGN_THREE;
    designs_dic[3].value = DEFAULT_DESIGN_FOUR;
    designs_dic[4].value = DEFAULT_DESIGN_FIVE;
    designs_dic[5].value = DEFAULT_DESIGN_SIX;
}