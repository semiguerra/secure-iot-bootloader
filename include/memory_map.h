/**
 * @file memory_map.h
 * @brief Flash memory layout definitions for the A/B OTA architecture.
 * @author Jose Miguel Guerra Ramirez
 * @date 2026-06-19
 *
 * This header defines the physical memory boundaries for a 1MB Flash storage.
 * It divides the memory into the Bootloader section, two application banks
 * (Bank A and Bank B) for redundant updates, and a Non-Volatile Storage (NVS)
 * section for persistent state flags.
 */

#ifndef MEMORY_MAP_H
#define MEMORY_MAP_H

/* Bootloader Partition (32 KB) */
#define BOOTLOADER_START_ADDR  0x00000000
#define BOOTLOADER_MAX_SIZE    0x00008000  /**< 32 KB maximum capacity */

/* Application Bank A (480 KB) */
#define BANK_A_START_ADDR      0x00008000
#define BANK_A_MAX_SIZE        0x00078000  /**< 480 KB maximum capacity */

/* Application Bank B (480 KB) */
#define BANK_B_START_ADDR      0x00080000
#define BANK_B_MAX_SIZE        0x00078000  /**< 480 KB maximum capacity */

/* Non-Volatile Storage / Config (32 KB) */
#define NVS_START_ADDR         0x000F8000
#define NVS_MAX_SIZE           0x00008000  /**< 32 KB maximum capacity */

/* End of 1MB Flash Memory */
#define FLASH_END_ADDR         0x000FFFFF

#endif // MEMORY_MAP_H