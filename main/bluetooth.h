#pragma once
#include "esp_nimble_hci.h"
#include "nimble/nimble_port.h"
#include "nimble/nimble_port_freertos.h"
#include "host/ble_hs.h"
#include "services/gap/ble_svc_gap.h"
#include "services/gatt/ble_svc_gatt.h"
#include "sdkconfig.h"
#include "nvs_flash.h"
#include <stdint.h>
#include "design_storage.h"

extern uint8_t led_design_int_bffr[8];

void ble_init();
void host_task(void *param);