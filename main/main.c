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

    // Init the designs structure
    init_designs_dic();

    // Init SPI for led matrix device
    init_matrix_led_spi();

    // Setup initial config for the led driver
    init_led_driver();
    
    // Run the ble thread
    nimble_port_freertos_init(host_task);   

    // Convert the uint8_t array into a uint64_t

    // Write on NVS
    //nvs_write(DEFAULT_DESIGN_ONE);
    nvs_write(designs_dic[0].value);

    // Read the written value in NVS
    nvs_read();

    // Create the task to display the dictioanry designs
    xTaskCreatePinnedToCore(&display_designs_task, "Display in LED matrix", 2048, 1, 1, NULL, 1);


    // Print the design on the matrix led
    //draw_led_matrix(design_one);
}