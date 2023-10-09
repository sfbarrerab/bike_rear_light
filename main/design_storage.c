#include "design_storage.h"

designs_dic_t prev_designs_dic[NUMBER_OF_DESIGNS];
designs_dic_t current_designs_dic[NUMBER_OF_DESIGNS];

uint64_t default_designs[NUMBER_OF_DESIGNS] = { DEFAULT_DESIGN_ONE, DEFAULT_DESIGN_TWO, DEFAULT_DESIGN_THREE, 
                                                DEFAULT_DESIGN_FOUR, DEFAULT_DESIGN_FIVE, DEFAULT_DESIGN_SIX};

void init_designs_dic(){
    // Init keys
    for(uint8_t i = 0; i < NUMBER_OF_DESIGNS; i++){
        snprintf(prev_designs_dic[i].key, sizeof(prev_designs_dic[i].key), "Design %d", i);
        snprintf(current_designs_dic[i].key, sizeof(current_designs_dic[i].key), "Design %d", i);
    }

    // Init values and store them in the nvs memory if needed
    for(uint8_t i = 0; i < NUMBER_OF_DESIGNS; i++){
        
        // Read the current value
        prev_designs_dic[i].value = nvs_read(prev_designs_dic[i].key);

        // If there is no design write the default design
        if(prev_designs_dic[i].value == 0){
            nvs_write(prev_designs_dic[i].key,default_designs[i]);
        }

        // Read again the values
        prev_designs_dic[i].value = nvs_read(prev_designs_dic[i].key);

        // Initialize the current designs dictionary with the same previous values
        current_designs_dic[i].value = prev_designs_dic[i].value;
    }

}

void store_new_designs(){
    int design_has_change = 0;
    int number_of_design_changed;
    while(1){
        // Check if there is a change in the design
        for(uint8_t i = 0; i < NUMBER_OF_DESIGNS; i++){
            if(current_designs_dic[i].value != prev_designs_dic[i].value){
                design_has_change = 1;
                number_of_design_changed = i;
            }
        }

        if(design_has_change){
            // write the new design in the memory
            nvs_write(current_designs_dic[number_of_design_changed].key,current_designs_dic[number_of_design_changed].value);
            // update the prev designs
            prev_designs_dic[number_of_design_changed].value = current_designs_dic[number_of_design_changed].value;
            // update trigger variable
            design_has_change = 0;
        }

        vTaskDelay(100/portTICK_PERIOD_MS);
    }
}