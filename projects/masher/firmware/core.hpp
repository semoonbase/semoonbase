#pragma once
/// @file Core functions for the masher projects.
/// @details This file contains the core functions for the masher project.
///          This includes universal dependencies and module glue code.

#include "gpio.hpp"
#include "key.hpp"

namespace core
{
    /// @brief Maps a GPIOAssignment to a Keyboard Key.
    /// @param vendor Vedor assignment to get key for.
    /// @return Key to mash.
    kbemu::Key mapAssignment(gpio::Pin vendor);

    /// @brief Presses the desired key based on digital input
    /// @param key Vendor to mash BIOS key for.
    void mash_key(gpio::Pin vendor);

} // namespace core
