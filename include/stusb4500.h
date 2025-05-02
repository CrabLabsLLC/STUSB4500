/**
 * @file stusb4500.h
 * @brief STUSB4500 USB PD Sink Controller Library (Platform-Agnostic)
 * @version 1.1
 * @date 2023-10-21
 * @license MIT
 */

#ifndef STUSB4500_H
#define STUSB4500_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// =============================================
// === Constants and Enums =====================
// =============================================
#define STUSB4500_NVM_UNLOCK             0x95 /** @brief NVM unlock command */

#define STUSB4500_NVM_LOCK               0x00 /** @brief NVM lock command */

#define STUSB4500_MIN_VOLTAGE_MV         5000  /** @brief Minimum/maximum PDO voltage (mV) */
#define STUSB4500_MAX_VOLTAGE_MV         20000

#define STUSB4500_MIN_CURRENT_MA         500 /** @brief Minimum/maximum PDO current (mA) */
#define STUSB4500_MAX_CURRENT_MA         5000

/** @brief Error codes for STUSB4500 operations */
typedef enum {
    STUSB4500_OK = 0,                /**< Operation successful */
    STUSB4500_ERR_I2C,               /**< I²C communication error */
    STUSB4500_ERR_INVALID_PDO,       /**< Invalid PDO configuration */
    STUSB4500_ERR_NVM_LOCKED,        /**< NVM is write-protected */
    STUSB4500_ERR_NOT_CONNECTED,     /**< No source connected */
    STUSB4500_ERR_VBUS_FAULT,        /**< VBUS fault detected */
} stusb4500_status_t;

/** @brief PDO (Power Data Object) configuration */
typedef struct {
    uint16_t voltage_mV;  /**< Voltage in mV (5000-20000) */
    uint16_t current_mA;  /**< Current in mA (500-5000) */
} stusb4500_pdo_t;

/** @brief Device configuration structure */
typedef struct {
    uint8_t pdo_count;            /**< Number of PDOs (1-3) */
    stusb4500_pdo_t pdo[3];       /**< PDO configurations */
    bool power_only_above_5v;      /**< Enable VBUS only if >5V negotiated */
    bool req_src_current;          /**< Request source's max current */
    uint8_t vbus_discharge_time;   /**< Discharge time coefficient (1-15) */
} stusb4500_config_t;

/** @brief Interrupt event flags */
typedef enum {
    STUSB4500_EVENT_NONE = 0,        /**< No event */
    STUSB4500_EVENT_PD_CONTRACT,     /**< New PD contract negotiated */
    STUSB4500_EVENT_VBUS_FAULT,      /**< VBUS fault detected */
    STUSB4500_EVENT_OVERTEMP,        /**< Over-temperature detected */
    STUSB4500_EVENT_DEBUG_ACCESSORY, /**< Debug accessory connected */
} stusb4500_event_t;

/** @brief I²C write function pointer */
typedef bool (*stusb4500_i2c_write_t)(uint8_t dev_addr, uint8_t reg_addr, const uint8_t *data, uint8_t len);

/** @brief I²C read function pointer */
typedef bool (*stusb4500_i2c_read_t)(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data, uint8_t len);

/// @brief GPIO Writing functions
typedef bool (*stusb4500_gpio_write_t)(const bool state);

/// @brief 
typedef bool (*stusb4500_gpio_read_t)(bool* const state);

/** @brief Interrupt callback function type */
typedef void (*stusb4500_event_callback_t)(const stusb4500_event_t event, stusb4500_pdo_t* const pdo);

typedef struct 
{
    stusb4500_i2c_write_t i2c_write;  /**< Platform I²C write function */
    stusb4500_i2c_read_t  i2c_read;   /**< Platform I²C read function */
    
    // Optional Functions to make life easier
    stusb4500_gpio_write_t reset_write;
    stusb4500_gpio_read_t power_ok2_read;
    stusb4500_gpio_read_t power_ok3_read; 
    stusb4500_gpio_read_t ab_side_read;
    stusb4500_gpio_read_t attach_read;  
    stusb4500_gpio_read_t gpio_read;
}

/** @brief STUSB4500 device handle */
typedef struct 
{
    uint8_t i2c_addr;                 /**< I²C address (default: 0x28) */
} stusb4500_handle_t;

// =============================================
// === Public API Functions ====================
// =============================================

/**
 * @brief Initialize the STUSB4500 handle.
 * @param handle Pointer to the STUSB4500 handle.
 * @return stusb4500_status_t Operation status.
 */
stusb4500_status_t stusb4500_init(stusb4500_handle_t *handle);

/**
 * @brief Configure PDOs and device settings.
 * @param handle Pointer to the STUSB4500 handle.
 * @param config Pointer to the configuration structure.
 * @return stusb4500_status_t Operation status.
 */
stusb4500_status_t stusb4500_set_config(stusb4500_handle_t *handle, const stusb4500_config_t *config);

/**
 * @brief Enable interrupt handling (attach callback).
 * @param handle Pointer to the STUSB4500 handle.
 * @param callback Function to call on events (NULL to disable).
 * @return stusb4500_status_t Operation status.
 */
stusb4500_status_t stusb4500_attach_interrupt(stusb4500_handle_t *handle, stusb4500_event_callback_t callback);

/**
 * @brief 
 * 
 */
void stusb4500_handle_interrupt(stusb4500_handle_t* const handle);

/**
 * @brief Get the currently negotiated PDO.
 * @param handle Pointer to the STUSB4500 handle.
 * @param pdo Pointer to store the negotiated PDO.
 * @return stusb4500_status_t Operation status.
 */
stusb4500_status_t stusb4500_get_negotiated_pdo(stusb4500_handle_t *handle, stusb4500_pdo_t *pdo);

/**
 * @brief Enable/disable dead battery mode.
 * @param handle Pointer to the STUSB4500 handle.
 * @param enable true to enable, false to disable.
 * @return stusb4500_status_t Operation status.
 */
stusb4500_status_t stusb4500_enable_dead_battery_mode(stusb4500_handle_t *handle, bool enable);

/**
 * @brief Reset the STUSB4500.
 * @param handle Pointer to the STUSB4500 handle.
 * @return stusb4500_status_t Operation status.
 */
stusb4500_status_t stusb4500_reset(stusb4500_handle_t *handle);

/**
 * @brief Read a register from the STUSB4500.
 * @param handle Pointer to the STUSB4500 handle.
 * @param reg Register address.
 * @param value Pointer to store the read value.
 * @return stusb4500_status_t Operation status.
 */
stusb4500_status_t stusb4500_read_register(stusb4500_handle_t *handle, uint8_t reg, uint8_t *value);

/**
 * @brief Write a register to the STUSB4500.
 * @param handle Pointer to the STUSB4500 handle.
 * @param reg Register address.
 * @param value Value to write.
 * @return stusb4500_status_t Operation status.
 */
stusb4500_status_t stusb4500_write_register(stusb4500_handle_t *handle, uint8_t reg, uint8_t value);

/**
 * @brief Unlock NVM for writing.
 * @param handle Pointer to the STUSB4500 handle.
 * @return stusb4500_status_t Operation status.
 */
stusb4500_status_t stusb4500_unlock_nvm(stusb4500_handle_t *handle);

/**
 * @brief Lock NVM after writing.
 * @param handle Pointer to the STUSB4500 handle.
 * @return stusb4500_status_t Operation status.
 */
stusb4500_status_t stusb4500_lock_nvm(stusb4500_handle_t *handle);

#ifdef __cplusplus
}
#endif

#endif // STUSB4500_H