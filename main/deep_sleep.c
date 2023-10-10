#include "deep_sleep.h"

void deep_sleep_register_gpio_wakeup()
{
    const gpio_config_t config = {
        .pin_bit_mask = BIT(EXT_DEEP_SLEEP_PIN),
        .mode = GPIO_MODE_INPUT,
    };

    ESP_ERROR_CHECK(gpio_config(&config));
    ESP_ERROR_CHECK(esp_deep_sleep_enable_gpio_wakeup(BIT(EXT_DEEP_SLEEP_PIN), ESP_GPIO_WAKEUP_GPIO_HIGH));

    printf("Enabling GPIO wakeup on pins GPIO%d\n", EXT_DEEP_SLEEP_PIN);
}

void deep_sleep_task(){
    // set wakeup source
    deep_sleep_register_gpio_wakeup();
    while(1){
        // Register again as GPIO if wakeup
        //ESP_ERROR_CHECK(rtc_gpio_deinit(EXT_DEEP_SLEEP_PIN));
        if(gpio_get_level(EXT_DEEP_SLEEP_PIN) == 1){
            // Huge delay because the wakeup signal was being triggered at the same time
            // so the delay allow to go to sleep without waking up inmeadiately
            vTaskDelay(500/portTICK_PERIOD_MS);
            // Clear the display
            clear_led_matrix();            
            // enter deep sleep
            esp_deep_sleep_start();
        }
        vTaskDelay(50/portTICK_PERIOD_MS);
    }
}