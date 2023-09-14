#include "nvs_wr.h"


uint64_t design_one;

void nvs_init(){
    // Initialize NVS
    esp_err_t nvs_err = nvs_flash_init();
    if (nvs_err == ESP_ERR_NVS_NO_FREE_PAGES || nvs_err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        // NVS partition was truncated and needs to be erased
        // Retry nvs_flash_init
        ESP_ERROR_CHECK(nvs_flash_erase());
        nvs_err = nvs_flash_init();
    }
    ESP_ERROR_CHECK( nvs_err );
}

void nvs_write(uint64_t data){
    nvs_handle_t nvs_handle;
    esp_err_t nvs_err;

    nvs_err = nvs_open("storage", NVS_READWRITE, &nvs_handle);
    if (nvs_err != ESP_OK) {
        printf("Error (%s) opening NVS handle!\n", esp_err_to_name(nvs_err));
    } else {
        // Write
        printf("Writing in NVS ... ");
        nvs_err = nvs_set_u64(nvs_handle, "Design1", data);
        printf((nvs_err != ESP_OK) ? "Failed!\n" : "Done\n");

        // Commit written value.
        // After setting any values, nvs_commit() must be called to ensure changes are written
        // to flash storage. Implementations may write to storage at other times,
        // but this is not guaranteed.
        printf("Committing updates in NVS ... ");
        nvs_err = nvs_commit(nvs_handle);
        printf((nvs_err != ESP_OK) ? "Failed!\n" : "Done\n");

        // Close
        nvs_close(nvs_handle);
    }

}

void nvs_read(){

    nvs_handle_t nvs_handle;
    esp_err_t nvs_err;

    nvs_err = nvs_open("storage", NVS_READWRITE, &nvs_handle);
    if (nvs_err != ESP_OK) {
        printf("Error (%s) opening NVS handle!\n", esp_err_to_name(nvs_err));
    } else {
        printf("Done\n");

        // Read
        printf("Reading default design one from NVS ... ");
        //int64_t design_one = 0; // value will default to 0, if not set yet in NVS
        nvs_err = nvs_get_u64(nvs_handle, "Design1", &design_one);
        switch (nvs_err) {
            case ESP_OK:
                printf("Done\n");
                printf("The data in the NVS is: %" PRIu64 "\n", design_one);
                break;
            case ESP_ERR_NVS_NOT_FOUND:
                printf("The value is not initialized yet!\n");
                break;
            default :
                printf("Error (%s) reading!\n", esp_err_to_name(nvs_err));
        }

    }

    // Close
    nvs_close(nvs_handle);
}