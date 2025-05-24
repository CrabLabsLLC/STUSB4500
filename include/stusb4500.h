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

#include "stusb4500_types.h"

#ifdef __cplusplus
extern "C" {
#endif


// =============================================
// === Public API Functions ====================
// =============================================

/**
 * @brief Initialize the STUSB4500 handle.
 * @param handle Pointer to the STUSB4500 handle.
 * @return stusb4500_status_t Operation status.
 */
bool stusb4500_init(stusb4500_t* const dev, const stusb4500_hal_t* const hal, const uint8_t address);

/**
 * @brief Configure PDOs and device settings.
 * @param handle Pointer to the STUSB4500 handle.
 * @param config Pointer to the configuration structure.
 * @return stusb4500_status_t Operation status.
 */
bool stusb4500_set_config(const stusb4500_t* const dev, const stusb4500_config_t* config);

/**
 * @brief Reset the STUSB4500.
 * @param handle Pointer to the STUSB4500 handle.
 * @return stusb4500_status_t Operation status.
 */
bool stusb4500_reset(const stusb4500_t* const handle);

/**
 * @brief Read a register from the STUSB4500.
 * @param handle Pointer to the STUSB4500 handle.
 * @param reg Register address.
 * @param value Pointer to store the read value.
 * @return stusb4500_status_t Operation status.
 */
bool stusb4500_read_register(const stusb4500_t* const dev, const uint8_t reg, uint8_t* const value);

/**
 * @brief Write a register to the STUSB4500.
 * @param handle Pointer to the STUSB4500 handle.
 * @param reg Register address.
 * @param value Value to write.
 * @return stusb4500_status_t Operation status.
 */
bool stusb4500_write_register(const stusb4500_t* const dev, const uint8_t reg, const uint8_t value);

#ifdef __cplusplus
}
#endif

#endif // STUSB4500_H