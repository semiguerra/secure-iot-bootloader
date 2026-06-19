# Secure A/B Bootloader for IoT Nodes

## Project Context & Motivation
This repository serves as the foundational architecture for my Telematics Engineering Final Degree Project (TFG).
The broader objective of the TFG is to design a fault-tolerant, secure IoT node for interurban transport monitoring using LPWAN cellular networks (NB-IoT). 

Before developing the application layer and the network stack, a robust deployment mechanism is mandatory. I created this project from scratch to demonstrate low-level C programming, flash memory management, and applied cryptography. It acts as a standalone portfolio piece showcasing how to build a highly resilient, bare-metal deployment system capable of surviving network drops and preventing malicious code execution in constrained remote environments.

## Architecture Overview
Updating firmware over-the-air (OTA) on remote nodes presents significant risks. This bootloader implements a Secure Boot architecture with an A/B dual-bank memory layout to ensure High Availability and seamless Disaster Recovery without requiring physical intervention.

### Key Technical Features
* **A/B Dual-Bank Architecture:** Ensures the device always has a valid fallback image if an OTA update fails, crashes, or loses power during flashing.
* **Network-Optimized Header (128-byte):** The metadata header is read and validated first. This allows the node to reject invalid, incompatible, or older payloads immediately, saving critical NB-IoT bandwidth and battery life.
* **Anti-Rollback Protection:** Strict version control prevents the re-installation of older, potentially vulnerable firmware versions.
* **Cryptographic Verification:** Uses ECDSA/RSA signatures to verify firmware authenticity before yielding execution control.
* **Watchdog-Driven Rollback:** Automatically reverts to the previous working bank if the newly installed firmware fails to boot properly.

## Memory Map (1MB Flash)
The physical flash is strictly partitioned to guarantee spatial isolation between the bootloader, the redundant applications, and the persistent state flags.

| Partition | Size | Start Address | End Address |
| :--- | :--- | :--- | :--- |
| **Bootloader** | 32 KB | `0x00000000` | `0x00007FFF` |
| **Bank A (App)** | 480 KB | `0x00008000` | `0x0007FFFF` |
| **Bank B (App)** | 480 KB | `0x00080000` | `0x000F7FFF` |
| **NVS (State)** | 32 KB | `0x000F8000` | `0x000FFFFF` |

## Current Status
Developing core data structures and memory boundaries.