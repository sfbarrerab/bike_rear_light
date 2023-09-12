#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_event.h"
#include "esp_log.h"
#include "bluetooth.h"


void app_main()
{
    // Init ble procceses
    ble_init();

    nimble_port_freertos_init(host_task);      // 6 - Run the thread
}