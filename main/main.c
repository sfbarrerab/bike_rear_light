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


void app_main()
{
    // Initialize NVS flash using
    nvs_init(); 

    // Init ble procceses
    ble_init();

    // Init SPI for led matrix device
    init_matrix_led_spi();

    // Setup initial config for the led driver
    init_led_driver();
    
    // Run the ble thread
    nimble_port_freertos_init(host_task);   

    // Write on NVS
    nvs_write(DEFAULT_DESIGN_ONE);

    // Read the written value in NVS
    nvs_read();

    // Print the design on the matrix led
    draw_led_matrix(design_one);
}