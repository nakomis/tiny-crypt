# tiny-crypt

ATtiny85 + ATECC608A crypto experimentation platform — embedded crypto, U2F hardware key, ESP32 integration.

## Stack

- **Toolchain**: PlatformIO + VS Code
- **Languages**: C/C++
- **Firmware targets**: ATtiny85 (V-USB, U2F), ESP32 (I²C master, signing demos)
- **Hardware**: Microchip ATECC608A/B/C secure element (SOIC-8, I²C, ECC P-256)
- **Host utilities**: Python scripts for provisioning and verification

## Repository layout

| Directory | Purpose |
|-----------|---------|
| `attiny85/` | ATtiny85 PlatformIO project — U2F key firmware, V-USB, ATECC608A I²C driver |
| `esp32/`    | ESP32 PlatformIO project — I²C master, signing/verification demos |
| `docs/`     | Wiring diagrams, architecture diagrams, notes |
| `scripts/`  | Host-side Python utilities |

## Key architectural decisions

- ATtiny85 uses **V-USB** (software USB) to present as a USB HID device for U2F
- ATECC608A communicates over **I²C** from both ATtiny85 and ESP32
- Private keys are **generated inside the ATECC608A and never exported** — provisioning uses `GenKey`, signing uses `Sign`
- U2F (FIDO 1.x) rather than full FIDO2/CTAP2 — ATtiny85 flash constraints (~8 KB total)
- This project uses shepherd drones for boilerplate code generation

## Building

```bash
# ESP32
cd esp32 && pio run

# ATtiny85
cd attiny85 && pio run
```

## Programming the ATtiny85

Use an ESP32 flashed with the ArduinoISP sketch as the ISP programmer.
Wire ESP32 SPI pins → ATtiny85 MOSI/MISO/SCK/RESET. Select "Arduino as ISP" programmer in PlatformIO.

## Architecture diagrams

Source: `docs/architecture/tiny-crypt.drawio` — SVG auto-regenerated on commit by `.githooks/pre-commit`.

To activate the hook after cloning:
```bash
git config core.hooksPath .githooks
```
