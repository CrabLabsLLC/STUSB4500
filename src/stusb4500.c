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


stusb4500_status_t stusb4500_init(stusb4500_handle_t *handle) {
    if (!handle || !handle->i2c_write || !handle->i2c_read || !handle->delay_ms) {
        return STUSB4500_ERR_I2C;
    }
    return STUSB4500_OK;
}

stusb4500_status_t stusb4500_set_config(stusb4500_handle_t *handle, const stusb4500_config_t *config) {
    if (!handle || !config || config->pdo_count < 1 || config->pdo_count > 3) {
        return STUSB4500_ERR_INVALID_PDO;
    }

    // Unlock NVM before writing
    stusb4500_status_t status = stusb4500_unlock_nvm(handle);
    if (status != STUSB4500_OK) return status;

    // Write PDO configurations
    for (uint8_t i = 0; i < config->pdo_count; i++) {
        uint8_t reg_voltage = STUSB4500_REG_PDO1_VOLTAGE + (i * 4);
        uint8_t reg_current = STUSB4500_REG_PDO1_CURRENT + (i * 4);

        uint16_t voltage_reg = _mv_to_reg(config->pdo[i].voltage_mV);
        uint16_t current_reg = _ma_to_reg(config->pdo[i].current_mA);

        status |= stusb4500_write_register(handle, reg_voltage, (voltage_reg >> 8) & 0xFF);
        status |= stusb4500_write_register(handle, reg_voltage + 1, voltage_reg & 0xFF);
        status |= stusb4500_write_register(handle, reg_current, (current_reg >> 8) & 0xFF);
        status |= stusb4500_write_register(handle, reg_current + 1, current_reg & 0xFF);
    }

    // Apply global settings
    uint8_t ctrl_reg = (config->power_only_above_5v << 1) | (config->req_src_current << 0);
    status |= stusb4500_write_register(handle, STUSB4500_REG_NVM_CTRL, ctrl_reg);

    // Lock NVM after writing
    status |= stusb4500_lock_nvm(handle);
    return status;
}

stusb4500_status_t stusb4500_get_negotiated_pdo(stusb4500_handle_t *handle, stusb4500_pdo_t *pdo) {
    if (!handle || !pdo) return STUSB4500_ERR_I2C;

    uint8_t status_reg;
    stusb4500_status_t status = stusb4500_read_register(handle, STUSB4500_REG_STATUS, &status_reg);
    if (status != STUSB4500_OK) return status;

    uint8_t active_pdo = (status_reg >> 4) & 0x03;  // Bits 4-5 indicate active PDO
    if (active_pdo == 0) return STUSB4500_ERR_NOT_CONNECTED;

    uint8_t reg_voltage = STUSB4500_REG_PDO1_VOLTAGE + ((active_pdo - 1) * 4);
    uint8_t reg_current = STUSB4500_REG_PDO1_CURRENT + ((active_pdo - 1) * 4);

    uint16_t voltage_reg, current_reg;
    status |= stusb4500_read_register(handle, reg_voltage, (uint8_t*)&voltage_reg);
    status |= stusb4500_read_register(handle, reg_current, (uint8_t*)&current_reg);

    pdo->voltage_mV = (voltage_reg + 100) * 50;  // Convert back to mV
    pdo->current_mA = (current_reg + 50) * 10;   // Convert back to mA
    return status;
}

stusb4500_status_t stusb4500_unlock_nvm(stusb4500_handle_t *handle) {
    return stusb4500_write_register(handle, STUSB4500_REG_NVM_CTRL, STUSB4500_NVM_UNLOCK);
}

stusb4500_status_t stusb4500_lock_nvm(stusb4500_handle_t *handle) {
    return stusb4500_write_register(handle, STUSB4500_REG_NVM_CTRL, STUSB4500_NVM_LOCK);
}

stusb4500_status_t stusb4500_reset(stusb4500_handle_t *handle) {
    stusb4500_status_t status = stusb4500_write_register(handle, STUSB4500_REG_NVM_CTRL, 0x80);
    handle->delay_ms(100);  // Wait for reset
    return status;
}