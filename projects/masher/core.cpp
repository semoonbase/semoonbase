#include "Keyboard.h"
#include "core.hpp"
#include "gpio.hpp"
#include "key.hpp"
#include "config.h"

void core::setup()
{
    gpio::setup();
    kbemu::setup();
}

/**
 * Maps a GPIO vendor pin to a corresponding keyboard key.
 *
 * @param vendor The GPIO pin representing the vendor.
 * @return The corresponding keyboard key.
 */
kbemu::Key core::mapKey(gpio::Pin vendor)
{
    using namespace gpio;
    using namespace kbemu;
    switch (vendor)
    {
    case Pin::DELL:
        return Key::DELL;
    case Pin::HP:
        return Key::DELL;
    case Pin::LENOVO:
        return Key::LENOVO;
    case Pin::NETBOOT:
        return Key::NETBOOT;
    case Pin::ESCAPE:
        return Key::ESCAPE;
    case Pin::SPACE:
        return Key::SPACE;
    default:
        return Key::ESCAPE;
    }
}

/*
 * TODO(lucas): Move into switching module
 * @brief  High level key mashing function
 * @param vendor Vendor to mash key for
 * @return Error code
 */
void core::mash(gpio::Pin vendor)
{
    Keyboard.press(mapKey(vendor));

    // Adding delay to ensure the keypress is registered
    delay(cfg::mashDelay);
    // releasing any pressed keys
    Keyboard.releaseAll();
    // delaying again to ensure a proper gap betwen keypresses
    delay(cfg::mashDelay);
}