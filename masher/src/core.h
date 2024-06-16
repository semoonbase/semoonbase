#pragma once
/// @file Core functions for the masher projects.
/// @details This file contains the core functions for the masher project.
///          This includes universal dependencies and module glue code.

#include "gpio.h"
#include "key.h"

namespace core
{
    /// @brief  Initialize the core module and its dependencies.
    void setup();

    /**
     * @brief Maps a GPIOAssignment to a Keyboard Key.
     * @param vendor Vedor assignment to get key for.
     * @return Key to mash.
     */
    kbemu::Key mapKey(gpio::Pin vendor);

    /**
     * @brief Fallibly reduce the GPIOReading to a single key
     */
    kbemu::Key tryReduceReport(gpio::GPIOReading reading);

    void mash(gpio::Pin vendor);
} // namespace core
