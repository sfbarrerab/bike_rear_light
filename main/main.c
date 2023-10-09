#include <stdio.h>
#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_event.h"
#include "esp_log.h"
#include "bluetooth.h"
#include "nvs_wr.h"
#include "led_matrix.h"
#include "design_storage.h"

void app_main()
{
    // Initialize NVS flash using
    nvs_init(); 

    // Init ble procceses
    ble_init();

    // Init the designs structure and store them in NVS
    init_designs_dic();

    // Init SPI for led matrix device
    init_matrix_led_spi();

    // Setup initial config for the led driver
    init_led_driver();
    
    // Run the ble thread
    nimble_port_freertos_init(host_task);     

    // Task to display the dictionary designs
    xTaskCreatePinnedToCore(&display_designs_task, "Display in LED matrix", 2048, NULL, 1, NULL, 1);
    // Task to store the values when changed
    xTaskCreatePinnedToCore(&store_new_designs, "Store new designs", 2048, NULL, 1, NULL, 1);

}