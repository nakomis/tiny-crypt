#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    Serial.println("tiny-crypt ESP32 — ready");
    // CRYPT-3: initialise ATECC608A over I2C here
}

void loop() {
}
