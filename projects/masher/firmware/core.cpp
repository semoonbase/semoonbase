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

kbemu::Key core::mapAssignment(gpio::Pin vendor)
{
    using namespace kbemu;
    switch (vendor)
    {
    case DELL:
        return Key::DELL;
    case HP:
        return Key::HP;
    case LENOVO:
        return Key::LENOVO;
    case NETBOOT:
        return Key::NETBOOT;

    default:
        return -1;
    }
}

kbemu::Key core::mapKey(gpio::Pin vendor)
{
    using namespace kbemu;
    switch (vendor)
    {
    case gpio::Pin::DELL:
        return kbemu::DELL;
    case gpio::Pin::HP:
        return kbemu::Key::DELL;
    case gpio::Pin::LENOVO:
        return kbemu::Key::LENOVO;
    case gpio::Pin::NETBOOT:
        return kbemu::Key::NETBOOT;
    case gpio::Pin::BLANCCO:
        return kbemu::Key::BLANCCO;
    }
}

// TODO(lucas): Move into switching module
/// @brief  High level key mashing function
/// @param vendor Vendor to mash key for
/// @return Error code
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