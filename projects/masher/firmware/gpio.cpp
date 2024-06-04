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
    makeInput(gpio::Pin::ESCAPE);
    makeInput(gpio::Pin::SPACE);
}


/**
 * @brief Read the state of all GPIO pins
 * @return GPIOReading struct containing the state of each pin
 */
GPIOReading readGPIO()
{
    GPIOReading reading;
    reading.dell = digitalRead(gpio::Pin::DELL);
    reading.hp = digitalRead(gpio::Pin::HP);
    reading.lenovo = digitalRead(gpio::Pin::LENOVO);
    reading.netboot = digitalRead(gpio::Pin::NETBOOT);
    reading.esc = digitalRead(gpio::Pin::ESCAPE);
    reading.space = digitalRead(gpio::Pin::SPACE);
    return reading;
}

bool isActive(GPIOReading reading)
{
    if (reading.dell == HIGH || reading.hp == HIGH || reading.lenovo == HIGH || reading.netboot == HIGH || reading.esc == HIGH || reading.space == HIGH)
    {
        return true;
    }
    else
    {
        // No pin is active
        return false;
    }
}