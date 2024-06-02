#pragma once

#include "Keyboard.h"

namespace gpio
{
    /// @brief Enumerates the GPIO assignments.
    typedef enum Pin
    {
        DELL = 2,
        HP = 3,
        LENOVO = 4,
        NETBOOT = 5,
        BLANCCO = 6,
    };

    /// @brief Assigns the GPIO pin roles
    void assign_pins();

}