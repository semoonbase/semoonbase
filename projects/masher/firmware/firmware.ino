#include "Keyboard.h"

#include "config.h"
#include "core.hpp"

/// @brief  Set the pin as input with pullup
/// @param pin GPIO pin to set as input
void makeInput(int pin)
{
  pinMode(pin, INPUT_PULLUP);
}

void setup()
{
  makeInput(gpio::Pin::DELL);
  makeInput(gpio::Pin::HP);
  makeInput(gpio::Pin::LENOVO);
  makeInput(gpio::Pin::NETBOOT);
  makeInput(gpio::Pin::BLANCCO);
  Keyboard.begin();
}

void loop()
{
  mash(gpio::Pin::DELL);
}

/// @brief  High level key mashing function
/// @param vendor Vendor to mash key for
/// @return Error code
void mash(gpio::Pin vendor)
{
  core::mash_key(vendor);
  // Adding delay to ensure the keypress is registered
  delay(cfg::mashDelay);
  // releasing any pressed keys
  Keyboard.releaseAll();
  // delaying again to ensure a proper gap betwen keypresses
  delay(cfg::mashDelay);
}
