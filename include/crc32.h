/**
 * @file crc32.h
 * @brief CRC32 calculation algorithm for integrity verification.
 * @author Jose Miguel Guerra Ramirez
 * @date 2026-06-21
 *
 * This module provides a fast, Lookup Table (LUT) based CRC32 implementation.
 * While a bitwise approach saves ~1KB of Flash memory, the LUT approach is 
 * chosen to minimize boot time (Time-to-First-Instruction), allowing rapid 
 * validation of the NVS state and firmware payloads before handing over control.
 */

#ifndef CRC32_H
#define CRC32_H

#include <stdint.h>
#include <stddef.h>

/**
 * @brief Calculates the CRC32 checksum of a given data buffer.
 * * Uses the standard IEEE 802.3 polynomial (0xEDB88320).
 * * @param data Pointer to the buffer to be processed.
 * @param length Number of bytes in the buffer.
 * @param initial_crc Starting CRC value (use 0xFFFFFFFF for a new calculation).
 * @return The computed 32-bit CRC value.
 */
uint32_t crc32_calculate(const uint8_t *data, size_t length, uint32_t initial_crc);

#endif // CRC32_H