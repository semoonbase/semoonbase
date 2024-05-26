
#include "Keyboard.h"

/// @brief Enumerates the GPIO assignments.
enum GPIOAssignment
{
    DELL = 2,
    HP = 3,
    LENOVO = 4,
    NETBOOT = 5,
    BLANCCO = 6,
    PASSWD = 7,
    TOGGLE = 14,
};

/// @brief Enumerates keybaord keys based on vendor.
///
/// @details These are the keys that are pressed to take a PC's
///          firmware to the target menu.
enum VendorKey
{
    DELL_KEY = KEY_F2,
    HP_KEY = KEY_F10,
    LENOVO_KEY = KEY_F1,
    NETBOOT_KEY = KEY_F12,
};

/// @brief Maps a GPIOAssignment to a Keyboard Key.
/// @param vendor Vedor assignment to get key for.
/// @return Key to mash.
VendorKey mapAssignment(GPIOAssignment vendor)
{
    switch (vendor)
    {
    case DELL:
        return DELL_KEY;
    case HP:
        return HP_KEY;
    case LENOVO:
        return LENOVO_KEY;
    case NETBOOT:
        return NETBOOT_KEY;

    default:
        return -1;
    }
}