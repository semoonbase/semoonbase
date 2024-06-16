#pragma once

#include "Keyboard.h"

namespace kbemu
{
    /// @brief Enumerates keybaord keys based on vendor.
    ///
    /// @details These are the keys that are pressed to take a PC's
    ///          firmware to the target menu.
    enum Key
    {
        DELL = KEY_F2,
        HP = KEY_F10,
        LENOVO = KEY_F1,
        NETBOOT = KEY_F12,
        HP_LOCAL = KEY_F9,
        ERASE_TOOL = KEY_ESC,
        NONE = KEY_KP_DOT,
        UNDEFINED = KEY_KP_ASTERISK,
    };

    /// @brief Initializes keyboard emulation.
    void setup();

}