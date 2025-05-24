/**
 * @file stusb4500.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "stusb4500.h"
#include "stusb4500_registers.h"

#include <string.h>

// =============================================
// === Internal Helper Functions ===============
// =============================================

/**
 * @brief Convert millivolts to register value (50mV steps).
 * @param mV Voltage in millivolts (5000-20000).
 * @return uint16_t Register value.
 */
static uint16_t _mv_to_reg(uint16_t mV) {
    if (mV < STUSB4500_MIN_VOLTAGE_MV) mV = STUSB4500_MIN_VOLTAGE_MV;
    if (mV > STUSB4500_MAX_VOLTAGE_MV) mV = STUSB4500_MAX_VOLTAGE_MV;
    return (mV / 50) - 100;
}

/**
 * @brief Convert milliamps to register value (10mA steps).
 * @param mA Current in milliamps (500-5000).
 * @return uint16_t Register value.
 */
static uint16_t _ma_to_reg(uint16_t mA) {
    if (mA < STUSB4500_MIN_CURRENT_MA) mA = STUSB4500_MIN_CURRENT_MA;
    if (mA > STUSB4500_MAX_CURRENT_MA) mA = STUSB4500_MAX_CURRENT_MA;
    return (mA / 10) - 50;
}


bool stusb4500_init(stusb4500_t* const handle, const stusb4500_hal_t* const hal, const uint8_t address) 
{
    if (!handle || !handle->hal.i2c_write || !handle->hal.i2c_read) 
    {
        return false;
    }

    handle->hal = *hal;
    handle->address = address;

    return true;
}

bool stusb4500_set_config(const stusb4500_t* const handle, const stusb4500_config_t* const config) 
{
    
    if (!handle || !config || config->active_pdo_count < 1 || config->active_pdo_count > 3) 
    {
        return false;
    }

    bool status = 0;
    // Write PDO configurations
    for (uint8_t i = 0; i < config->active_pdo_count; i++) {
        uint8_t reg_voltage = STUSB4500_REG_DPM_SNK_PDO1_0 + (i * 4);
        uint8_t reg_current = STUSB4500_REG_DPM_SNK_PDO1_2 + (i * 4);

        uint16_t voltage_reg = _mv_to_reg(config->sink_pdos[i].voltage_mv);
        uint16_t current_reg = _ma_to_reg(config->sink_pdos[i].current_ma);
        
        status |= stusb4500_write_register(handle, reg_voltage, (voltage_reg >> 8) & 0xFF);
        status |= stusb4500_write_register(handle, reg_voltage + 1, voltage_reg & 0xFF);
        status |= stusb4500_write_register(handle, reg_current, (current_reg >> 8) & 0xFF);
        status |= stusb4500_write_register(handle, reg_current + 1, current_reg & 0xFF);
    }

    return status;
}

bool stusb4500_read_register(const stusb4500_t* const dev, const uint8_t reg, uint8_t* const value)
{
    if(dev == NULL || value == NULL)
        return 1;

    return (dev->hal.i2c_read(dev->address, reg, value, 1) == 0);
}

bool stusb4500_write_register(const stusb4500_t* const dev, const uint8_t reg, const uint8_t value)
{
    if(dev == NULL)
        return 0;

    return (dev->hal.i2c_write(dev->address, reg, &value, 1) == 0);
}
