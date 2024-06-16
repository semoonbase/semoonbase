#include "Arduino.h"
#include "gpio.h"

#ifdef UNIT_TEST
#include <gtest/gtest.h>
#include "KeyboardLayout_en_US.h"
#endif

/**
 * @brief Set the pin as input with pullup
 * @param pin GPIO pin to set as input
 */
void makeInput(int pin)
{
    pinMode(pin, INPUT_PULLUP);
}

/**
 * @brief Setup the GPIO pins
 */
void gpio::setup()
{
    makeInput(gpio::Pin::DELL);
    makeInput(gpio::Pin::HP);
    makeInput(gpio::Pin::LENOVO);
    makeInput(gpio::Pin::NETBOOT);
    makeInput(gpio::Pin::HP_LOCAL);
    makeInput(gpio::Pin::ERASE_TOOL);
}

#ifdef UNIT_TEST
TEST(gpio, setup_interface)
{
    gpio::setup();
}

#endif
/**
 * @brief Read the state of all GPIO pins
 * @return GPIOReading struct containing the state of each pin
 */
gpio::GPIOReading gpio::readGPIO()
{
    GPIOReading reading;
    reading.dell = digitalRead(gpio::Pin::DELL);
    reading.hp = digitalRead(gpio::Pin::HP);
    reading.lenovo = digitalRead(gpio::Pin::LENOVO);
    reading.netboot = digitalRead(gpio::Pin::NETBOOT);
    reading.hp_local = digitalRead(gpio::Pin::HP_LOCAL);
    reading.erase_tool = digitalRead(gpio::Pin::ERASE_TOOL);
    return reading;
}

/**
 * @brief Give a zerod GPIOReading object.
 */
gpio::GPIOReading gpio::zeroReading() {
    GPIOReading reading;
    reading.dell = 0;
    reading.hp = 0;
    reading.lenovo = 0;
    reading.netboot = 0;
    reading.hp_local = 0;
    reading.erase_tool = 0;
    return reading;
}

/**
 * @brief Checks if any of the GPIO pins are active.
 *
 * @param reading The GPIOReading object containing the pin states.
 * @return true if any of the pins are active, false otherwise.
 */
bool gpio::isActive(GPIOReading reading)
{
    if (reading.dell == HIGH || reading.hp == HIGH || reading.lenovo == HIGH || reading.netboot == HIGH || reading.hp_local == HIGH || reading.erase_tool == HIGH)
    {
        return true;
    }
    else
    {
        // No pin is active
        return false;
    }
}