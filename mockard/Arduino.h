#pragma once

#define HIGH 0x1
#define LOW 0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

#include <cstddef>
#include <cstdint>

void pinMode(uint8_t pin, uint8_t val);
int digitalRead(uint8_t pin);
