/**
 * @file stusb4500_types.h
 * @brief User-facing types, enums, and structs for configuring and monitoring STUSB4500.
 * @version 1.1
 * @date 2025-04-30
 *
 * This header defines:
 * - Configuration enums and structs for device setup
 * - Status structures for runtime monitoring
 * - Interrupt flag and mask macros for alert handling
 */
#ifndef STUSB4500_TYPES_H
#define STUSB4500_TYPES_H

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

typedef bool (*stusb4500_i2c_write_t)(const uint8_t dev_addr, const uint8_t reg_addr, const void* const data, const uint8_t len);
typedef bool (*stusb4500_i2c_read_t)(const uint8_t dev_addr, const uint8_t reg_addr, void* const data, const uint8_t len);

typedef bool (*stusb4500_gpio_write_t)(const bool state);
typedef bool (*stusb4500_gpio_read_t)(bool* const state);

/** @defgroup STUSB4500_Enums Configuration and Status Enums
 *  @brief Enumerations for configuration fields
 *  @{ */

/** @brief CC pull-up/pull-down role */
typedef enum {
    STUSB4500_ROLE_UFP = 0,  ///< Upward Facing Port (sink)
    STUSB4500_ROLE_DFP = 1   ///< Downward Facing Port (source)
} stusb4500_port_role_t;

/** @brief Attached device type on Type-C connector */
typedef enum {
    STUSB4500_DEV_NONE      = 0, ///< No device attached
    STUSB4500_DEV_SINK      = 1, ///< Sink attached
    STUSB4500_DEV_SOURCE    = 2, ///< Source attached
    STUSB4500_DEV_DEBUG_ACC = 3  ///< Debug accessory
} stusb4500_attached_device_t;

/** @brief PDO voltage/current supply type */
typedef enum {
    STUSB4500_PDO_FIXED_SUPPLY = 0, ///< Fixed supply
    STUSB4500_PDO_BATTERY      = 1, ///< Battery supply
    STUSB4500_PDO_VARIABLE     = 2, ///< Variable supply
    STUSB4500_PDO_RESERVED     = 3  ///< Reserved
} stusb4500_pdo_type_t;

/** @brief VBUS voltage threshold options for OVP/UVP */
typedef enum {
    STUSB4500_VOLTAGE_5V  = 0x0, ///< ~5V threshold
    STUSB4500_VOLTAGE_9V  = 0x3, ///< ~9V threshold
    STUSB4500_VOLTAGE_15V = 0x7, ///< ~15V threshold
    STUSB4500_VOLTAGE_20V = 0xA  ///< ~20V threshold
} stusb4500_vbus_threshold_t;

/** @brief VBUS sink disconnect threshold */
typedef enum {
    STUSB4500_DISCONNECT_VBUS_LOW  = 0, ///< Low threshold
    STUSB4500_DISCONNECT_VBUS_MED  = 1, ///< Medium threshold
    STUSB4500_DISCONNECT_VBUS_HIGH = 2  ///< High threshold
} stusb4500_disconnect_threshold_t;

/** @} */ // end STUSB4500_Enums

/** @defgroup STUSB4500_Config Device Configuration Structures
 *  @brief User-level configuration types
 *  @{ */

/** VBUS monitoring configuration */
typedef struct 
{
    stusb4500_vbus_threshold_t ovp_level;       ///< Over-voltage protection threshold
    stusb4500_vbus_threshold_t uvp_level;       ///< Under-voltage protection threshold
    stusb4500_disconnect_threshold_t disc_th;   ///< VBUS disconnect threshold
} stusb4500_vbus_cfg_t;

/** Sink PDO structure */
typedef struct 
{
    stusb4500_pdo_type_t type;  ///< Supply type
    uint16_t voltage_mv;        ///< Voltage in millivolts
    uint16_t current_ma;        ///< Current in milliamps
} stusb4500_sink_pdo_t;

/** Main device configuration */
typedef struct 
{
    stusb4500_port_role_t      port_role;              ///< UFP or DFP
    uint8_t                    active_pdo_count;       ///< Number of active PDOs (1-3)
    stusb4500_sink_pdo_t       sink_pdos[3];           ///< PDO configurations
    bool                       vbus_discharge_enable;  ///< Enable VBUS discharge
    struct
    {
        uint8_t                    discharge_time;         ///< Discharge time code
        stusb4500_vbus_cfg_t       vbus_monitor;           ///< VBUS threshold config
    } advanced;
    
} stusb4500_config_t;

/** @} */ // end STUSB4500_Config

/** @defgroup STUSB4500_Status Runtime Status Structures
 *  @brief Data structures for status and interrupts
 *  @{ */

/** Live device status flags */
typedef struct 
{
    bool                      attached;        ///< Device attached
    stusb4500_attached_device_t attached_dev;  ///< Attached device type
    bool                      vbus_ready;      ///< VBUS ready
    bool                      vbus_vsafe0v;    ///< VSAFE0V state
    bool                      vbus_valid;      ///< VBUS valid sink
    bool                      cc_fault;        ///< CC fault indicator
    uint8_t                   pe_state;        ///< Policy engine FSM state
} stusb4500_status_t;

/** Snapshot of alert flags and masks */
typedef struct 
{
    bool port_status_alert;     ///< Issue with the status
    bool typec_mon_alert;       ///< Issue with type c
    bool cc_fault_alert;        ///< Issue with CC coms
    bool protocol_fault_alert;  ///< Issue with the protocol
} stusb4500_interrupt_status_t;

/** @} */ // end STUSB4500_Status

typedef struct 
{
    stusb4500_i2c_write_t i2c_write;
    stusb4500_i2c_read_t i2c_read;

} stusb4500_hal_t;

typedef struct 
{
    stusb4500_hal_t hal;
    uint8_t address;
} stusb4500_t;

#ifdef __cplusplus
}
#endif

#endif /* STUSB4500_TYPES_H */