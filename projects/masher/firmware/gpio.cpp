#include "gpio.hpp"

/**
 * @brief Set the pin as input with pullup
 * @param pin GPIO pin to set as input
 */
void makeInput(int pin)
{
    pinMode(pin, INPUT_PULLUP);
}

/// @brief Assigns the GPIO pin roles
void gpio::setup()
{
    makeInput(gpio::Pin::DELL);
    makeInput(gpio::Pin::HP);
    makeInput(gpio::Pin::LENOVO);
    makeInput(gpio::Pin::NETBOOT);
    makeInput(gpio::Pin::BLANCCO);
}