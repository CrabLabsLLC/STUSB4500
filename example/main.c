
#include "stusb4500.h" 

// User-provided I²C functions

uint8_t i2c_read(uint8_t addr, uint8_t reg, uint8_t *data, uint16_t len) {
    // Platform-specific implementation
    return STUSB_OK;
}

uint8_t i2c_write(uint8_t addr, uint8_t reg, const uint8_t *data, uint16_t len) {
    // Platform-specific implementation
    return STUSB_OK;
}

int main() {
    stusb_handle_t handle;
    stusb_config_t config;
    
    // Initialize driver
    stusb4500_init(&handle, 0x28, i2c_read, i2c_write);

    // Get current configuration
    stusb4500_get_config(&handle, &config);

    // Modify configuration
    config.pdo[1].voltage_mv = 9000;  // 9V
    config.pdo[1].current_ma = 2000;  // 2A

    // Apply and save
    stusb4500_apply_config(&handle);
    stusb4500_save_config(&handle);

    return 0;
}