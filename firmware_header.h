/**
 * @file firmware_header.h
 * @brief Firmware header definition for the OTA system (A/B Bootloader).
 * @author Jose Miguel Guerra Ramirez
 * @date 2026-06-19
 *
 * This file defines the exact 128-byte metadata structure that must
 * prepend any valid firmware image. The Bootloader uses this header
 * to verify integrity, versioning, and cryptographic authenticity
 * before handing over control to the new code, ensuring node security.
 */

#ifndef FIRMWARE_HEADER_H
#define FIRMWARE_HEADER_H

#include <stdint.h>

/* Force 1-byte alignment to prevent compiler-injected padding.
 * This ensures the structure maintains its exact size when transmitted
 * over LPWAN networks (NB-IoT) and when written to Flash memory sectors.
 */
#pragma pack(push, 1)

/**
 * @struct firmware_header_t
 * @brief Immutable firmware metadata structure (128 bytes).
 */
typedef struct {
    uint32_t magic_word;     /**< Valid image identifier (e.g., 0x54464721 for "TFG!") */
    uint32_t version;        /**< Version counter for Anti-Rollback protection */
    uint32_t hardware_id;    /**< Target SoC identifier (e.g., nRF9160 or STM32) */
    uint32_t payload_size;   /**< Size in bytes of the attached executable binary */
    uint32_t payload_crc32;  /**< CRC32 of the binary for rapid network integrity validation */
    uint8_t  signature[64];  /**< ECDSA/RSA digital signature for Secure Boot */
    uint8_t  _reserved[44];  /**< Manual padding to align exactly to 128 bytes */
} firmware_header_t;

#pragma pack(pop)

#endif // FIRMWARE_HEADER_H