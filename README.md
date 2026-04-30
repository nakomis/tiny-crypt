# tiny-crypt — ATtiny85 + ATECC608A crypto experimentation platform

## Support

If you find this useful, please consider buying me a coffee:

[![Donate with PayPal](https://www.paypalobjects.com/en_GB/i/btn/btn_donate_SM.gif)](https://www.paypal.com/donate?hosted_button_id=Q3BESC73EWVNN&custom=tiny-crypt)

## Table of Contents

<!-- toc -->
<!-- tocstop -->

## Overview

A hands-on exploration of embedded cryptography using the Microchip ATECC608A/B/C secure element,
driven by an ATtiny85 (via V-USB) and an ESP32. Features a working U2F hardware security key as
the centrepiece demo.

**Hardware:**
- Microchip ATECC608A/B/C — ECC P-256 secure element (SOIC-8, I²C)
- ATtiny85 — 8-bit AVR microcontroller (SOIC-8 or DIP-8)
- ESP32 — 32-bit Xtensa MCU with Wi-Fi/Bluetooth

**Toolchain:** PlatformIO + VS Code

## Architecture Diagram

![Architecture](docs/architecture/tiny-crypt.svg)

## Repository Layout

| Directory | Purpose |
|-----------|---------|
| `attiny85/` | ATtiny85 firmware — U2F key, V-USB, ATECC608A driver |
| `esp32/`    | ESP32 firmware — I²C master, signing demos, serial interface |
| `docs/`     | Wiring diagrams, architecture, notes, and blog material |
| `scripts/`  | Host-side Python utilities (provisioning, verification) |

## Getting Started

### Prerequisites

- [PlatformIO](https://platformio.org/) (VS Code extension or CLI)
- An ATECC608A/B/C on a SOIC-8 breakout board
- An ATtiny85 (SOIC-8 or DIP-8)
- An ESP32 development board
- A spare ESP32 or Arduino to act as ISP programmer for the ATtiny85

### Wiring

See `docs/wiring/` for circuit diagrams for each configuration.

### Building

```bash
# ESP32 target
cd esp32
pio run

# ATtiny85 target
cd attiny85
pio run
```

## Features

1. **Provision** — generate an ECC P-256 key pair inside the ATECC608A, lock the slot
2. **Sign & verify** — send data to the chip, receive a signature, verify on the host over serial
3. **ESP32 ↔ ATECC608A** — ESP32 as I²C master; sign and verify end-to-end
4. **U2F hardware key** — ATtiny85 + V-USB presenting as a USB HID security key, ATECC608A doing the crypto

## Architecture Diagrams

`docs/architecture/tiny-crypt.drawio` is the source for the diagram above.
The SVG is auto-regenerated on commit by the pre-commit hook in `.githooks/pre-commit`.

To activate the hook after cloning:

```bash
git config core.hooksPath .githooks
```

## Support

If you find this useful, please consider buying me a coffee:

[![Donate with PayPal](https://www.paypalobjects.com/en_GB/i/btn/btn_donate_SM.gif)](https://www.paypal.com/donate?hosted_button_id=Q3BESC73EWVNN&custom=tiny-crypt)
