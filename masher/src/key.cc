#include "key.h"
#include "Keyboard.h"

#ifdef UNIT_TEST
#include <gtest/gtest.h>
#include "KeyboardLayout_en_US.h"
#endif

void kbemu::setup()
{
    Keyboard_ Keyboard = Keyboard_();
    Keyboard.begin();
}

#ifdef UNIT_TEST
TEST(kbemu, setup_interface)
{
    kbemu::setup();
}
#endif