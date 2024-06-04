#pragma once

#include "Keyboard.h"

namespace gpio
{
    typedef enum Pin
    {
        DELL = 2,
        HP = 3,
        LENOVO = 4,
        NETBOOT = 5,
        BLANCCO = 6,
    };

    void setup();
}