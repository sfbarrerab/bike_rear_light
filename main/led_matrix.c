#include "led_matrix.h"

spi_device_handle_t led_matrix_spi_hndl;

void init_matrix_led_spi(){

    esp_err_t ret;

    spi_bus_config_t bus_config = {
        .miso_io_num = PIN_NUM_MISO,
        .mosi_io_num = PIN_NUM_MOSI,
        .sclk_io_num = PIN_NUM_CLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = 32,
    };

    spi_device_interface_config_t devcfg = {
        .clock_speed_hz = 1000000, // Clock out at 1 MHz with 1 us cycle
        .mode = 0,                 // data is sampled on the rising edge of the clock pulse and shifted out on the falling edge of the clock pulse.
        .spics_io_num = PIN_NUM_CS,     
        .flags = SPI_DEVICE_HALFDUPLEX,
        .queue_size = 1,
        .pre_cb = NULL,
        .post_cb = NULL,
    };

    
    // Initialize the SPI
    ret = spi_bus_initialize(SPI2_HOST, &bus_config, SPI_DMA_CH_AUTO);
    ESP_ERROR_CHECK(ret);

    // Add the device to the SPI handler
    ret = spi_bus_add_device(SPI2_HOST, &devcfg, &led_matrix_spi_hndl);
    ESP_ERROR_CHECK(ret);
    
    // Set to no decode mode 
}

// Function to transform NVS data for transmiting  in the SPI line

void int64ToArrayInt8(uint64_t num64, uint8_t num8_array[8]) {
    for (int i = 0; i < 8; i++) {
        num8_array[i] = (uint8_t)(num64 >> (i * 8));
    }
}

void spi_write(uint8_t addr, uint8_t value){
    uint8_t data[2] = {addr,value}; 
    spi_transaction_t spi_transaction = {
        .tx_buffer = data,
        .length = 16,    
    };
    spi_device_transmit(led_matrix_spi_hndl,&spi_transaction);
}

void init_led_driver(){
    spi_write(DECODE_MOD_ADDR,0);
    spi_write(INTENSITY_ADDR,7);
    spi_write(SCAN_LIMIT_ADDR,7);
    spi_write(SHUTDOWN_ADDR,1);
    spi_write(DISPLAY_TEST_ADDR,0);
}

void clear_led_matrix(){
    for(uint8_t i = 1; i < 9; i++){
        spi_write(i,0);
    }
}


void draw_led_matrix(uint64_t data){

    // Call the function to convert int64 to int8 array
    uint8_t num8_array[8] = {0};

    // Call the function to convert int64 to int8 array
    int64ToArrayInt8(data, num8_array);

    // clear display
    clear_led_matrix();

    // print the input design
    for(uint8_t i = 0; i < 8; i++){
        spi_write(i+1,num8_array[i]);
    }

}

void display_designs_task(){
    while(1){
        draw_led_matrix(designs_dic[0].value);
        vTaskDelay(5000/portTICK_PERIOD_MS);
    }
}