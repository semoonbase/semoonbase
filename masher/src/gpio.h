#pragma once

#include "Keyboard.h"

namespace gpio
{
    /**
     * @brief GPIO pin assignment enumeration.
     */
    enum Pin
    {
        DELL = 1,
        HP = 2,
        LENOVO = 3,
        NETBOOT = 4,
        HP_LOCAL = 5,
        ERASE_TOOL = 6,
    };

    /**
     * @brief GPIO reading struct.
     */
    struct GPIOReading
    {
        int dell;
        int hp;
        int lenovo;
        int netboot;
        int hp_local;
        int erase_tool;
    };

    /**
     * @brief Give a zerod GPIOReading object.
     */
    GPIOReading zeroReading();

    /**
     * @brief GPIO switch reading function.
     */
    GPIOReading readGPIO();

    /**
     * @brief GPIO pin active check function.
     *
     * @param reading The GPIO reading to check.
     * @return True if any pin is active, false otherwise.
     *
     * @details This function checks if any of the pins in the GPIO reading are HIGH.
     */
    bool isActive(GPIOReading reading);

    /**
     * @brief Module setup function.
     */
    void setup();
}