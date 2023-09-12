#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_event.h"
#include "esp_log.h"
#include "bluetooth.h"
#include "nvs_wr.h"


void app_main()
{
    // Initialize NVS flash using
    nvs_init(); 

    // Init ble procceses
    ble_init();
    
    // Run the ble thread
    nimble_port_freertos_init(host_task);   

    // Write on NVS
    nvs_write(DEFAULT_DESIGN_ONE);
    nvs_read();
}