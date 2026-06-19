/**
 * @file nvs_state.h
 * @brief Non-Volatile Storage (NVS) state definitions for the bootloader.
 * @author Jose Miguel Guerra Ramirez
 * @date 2026-06-19
 *
 * This file defines the data structure stored in the isolated NVS flash sector.
 * The bootloader reads this structure upon every reset to determine the active
 * application bank, detect pending OTA updates, and manage automatic rollbacks
 * in case of a crash or invalid signature.
 */

#ifndef NVS_STATE_H
#define NVS_STATE_H

#include <stdint.h>

/* Magic bytes for bank identification to avoid accidental 0x00 or 0xFF evaluations */
#define BANK_A_ACTIVE 0xAA
#define BANK_B_ACTIVE 0xBB

#define MAX_BOOT_ATTEMPTS 3

#pragma pack(push, 1)

/**
 * @struct nvs_state_t
 * @brief Persistent state structure (32 bytes aligned).
 */
typedef struct {
    uint8_t  active_bank;      /**< Active partition to boot (0xAA for Bank A, 0xBB for Bank B) */
    uint8_t  update_pending;   /**< Set to 1 when a new payload is written but not yet verified */
    uint8_t  is_verified;      /**< Set to 1 after a successful ECDSA/RSA signature verification */
    uint8_t  boot_attempts;    /**< Incremented on boot, cleared on app success. Triggers rollback if > MAX */
    uint32_t state_crc32;      /**< CRC32 of this struct to detect flash memory corruption */
    uint8_t  _reserved[24];    /**< Padding to align the structure strictly to 32 bytes */
} nvs_state_t;

#pragma pack(pop)

#endif // NVS_STATE_H