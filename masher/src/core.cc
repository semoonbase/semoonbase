#include "Keyboard.h"
#include "core.h"
#include "gpio.h"
#include "key.h"

#ifdef UNIT_TEST
#include <gtest/gtest.h>
#include "KeyboardLayout_en_US.h"
#endif

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
        return Key::HP;
    case Pin::LENOVO:
        return Key::LENOVO;
    case Pin::NETBOOT:
        return Key::NETBOOT;
    case Pin::HP_LOCAL:
        return Key::HP_LOCAL;
    case Pin::ERASE_TOOL:
        return Key::ERASE_TOOL;
    default:
        return Key::UNDEFINED;
    }
}

#ifdef UNIT_TEST
TEST(core, mapKey)
{
    EXPECT_EQ(core::mapKey(gpio::Pin::DELL), KEY_F2);
    EXPECT_EQ(core::mapKey(gpio::Pin::HP), KEY_F10);
    EXPECT_EQ(core::mapKey(gpio::Pin::LENOVO), KEY_F1);
    EXPECT_EQ(core::mapKey(gpio::Pin::NETBOOT), KEY_F12);
    EXPECT_EQ(core::mapKey(gpio::Pin::HP_LOCAL), KEY_F9);
    EXPECT_EQ(core::mapKey(gpio::Pin::ERASE_TOOL), KEY_ESC);
}
#endif

/// @brief Count the number of active pins in a GPIOReading
int countActive(gpio::GPIOReading reading) {
    return reading.dell + reading.hp + reading.lenovo + reading.netboot + reading.hp_local + reading.erase_tool;
}

#ifdef UNIT_TEST
TEST(core, countActive)
{
    gpio::GPIOReading reading = gpio::zeroReading();
    EXPECT_EQ(countActive(reading), 0);
    reading.dell = 1;
    EXPECT_EQ(countActive(reading), 1);
    reading.hp = 1;
    EXPECT_EQ(countActive(reading), 2);
    reading.lenovo = 1;
    EXPECT_EQ(countActive(reading), 3);
    reading.netboot = 1;
    EXPECT_EQ(countActive(reading), 4);
    reading.hp_local = 1;
    EXPECT_EQ(countActive(reading), 5);
    reading.erase_tool = 1;
    EXPECT_EQ(countActive(reading), 6);
}
#endif

/**
 * @brief Fallibly reduce the GPIOReading to a single key
 */
kbemu::Key core::tryReduceReport(gpio::GPIOReading reading) {
    using namespace gpio;
    using namespace kbemu;
    
    if (countActive(reading) > 1) return Key::UNDEFINED; 

    if (reading.dell) return Key::DELL;
    if (reading.hp) return Key::HP;
    if (reading.lenovo) return Key::LENOVO;
    if (reading.hp_local) return Key::HP_LOCAL;
    if (reading.netboot) return Key::NETBOOT;
    if (reading.erase_tool) return Key::ERASE_TOOL;

    if (!isActive(reading)) return Key::NONE;
    return Key::UNDEFINED;
}


#ifdef UNIT_TEST
TEST(core, tryReduceReport_off)
{
    gpio::GPIOReading reading = gpio::zeroReading();
    EXPECT_EQ(core::tryReduceReport(reading), kbemu::Key::NONE);
}

TEST(core, tryReduceReport_multi)
{
    gpio::GPIOReading reading = gpio::zeroReading();
    reading.dell = 1;
    reading.hp = 1;
    EXPECT_EQ(core::tryReduceReport(reading), kbemu::Key::UNDEFINED);
}

TEST(core, tryReduceReport_Dell)
{
    gpio::GPIOReading reading = gpio::zeroReading();
    reading.dell = 1;
    EXPECT_EQ(core::tryReduceReport(reading), kbemu::Key::DELL);
}

TEST(core, tryReduceReport_HP)
{
    gpio::GPIOReading reading = gpio::zeroReading();
    reading.hp = 1;
    EXPECT_EQ(core::tryReduceReport(reading), kbemu::Key::HP);
}

TEST(core, tryReduceReport_Lenovo)
{
    gpio::GPIOReading reading = gpio::zeroReading();
    reading.lenovo = 1;
    EXPECT_EQ(core::tryReduceReport(reading), kbemu::Key::LENOVO);
}

TEST(core, tryReduceReport_HP_Local)
{
    gpio::GPIOReading reading = gpio::zeroReading();
    reading.hp_local = 1;
    EXPECT_EQ(core::tryReduceReport(reading), kbemu::Key::HP_LOCAL);
}

TEST(core, tryReduceReport_Netboot)
{
    gpio::GPIOReading reading = gpio::zeroReading();
    reading.netboot = 1;
    EXPECT_EQ(core::tryReduceReport(reading), kbemu::Key::NETBOOT);
}

TEST(core, tryReduceReport_EraseTool)
{
    gpio::GPIOReading reading = gpio::zeroReading();
    reading.erase_tool = 1;
    EXPECT_EQ(core::tryReduceReport(reading), kbemu::Key::ERASE_TOOL);
}
#endif
