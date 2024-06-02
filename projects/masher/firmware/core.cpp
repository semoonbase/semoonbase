#include "Keyboard.h"
#include "core.hpp"
#include "gpio.hpp"
#include "key.hpp"

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

void core::mash_key(gpio::Pin vendor)
{
    using namespace kbemu;
    switch (vendor)
    {
    case gpio::Pin::DELL:
        Keyboard.press(Key::DELL);
        break;
    case gpio::Pin::HP:
        Keyboard.press(Key::HP);
        break;
    case gpio::Pin::LENOVO:
        Keyboard.press(Key::LENOVO);
        break;
    case gpio::Pin::NETBOOT:
        Keyboard.press(Key::NETBOOT);
        break;
    case gpio::Pin::BLANCCO:
        Keyboard.press(KEY_ESC);
        Keyboard.press(' ');
        // TODO
        break;
    default:
        break;
    }
}