#include "Keyboard.h"

// define variables for pins
enum GPIOAssignment
{
  DELL = 2,
  HP = 3,
  LENOVO = 4,
  NETBOOT = 5,
  BLANCCO = 6,
  TOGGLE = 8
};

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

// TODO: add password functionallity
// const int selectPassword = 7;
// TODO(Lucas): Remove global mutable state
bool buttonToggle = false;
int switchState = 0;
// Delay on the rising and falling edges of the simulated keypress in milliseconds
int mashDelay = 100;

void pinInput(int pin)
{
  pinMode(pin, INPUT_PULLUP);
}

void setup()
{
  // Declare the inputs as Pullups
  pinInput(DELL);
  pinInput(HP);
  pinInput(LENOVO);
  pinInput(NETBOOT);
  pinInput(BLANCCO);
  // TODO: add password functionallity
  // pinmode(selectPassword, INPUT_PULLUP);
  pinMode(TOGGLE, INPUT_PULLUP);
  Keyboard.begin();
}

void loop()
{
  // Handle togglingg of keyboard output
  maybe_toggle(digitalRead(TOGGLE));

  mash(DELL);
}

/// @brief Handles toggling of keyboard functionality
/// @param reading Reading from the digital input.
void maybe_toggle(int reading)
{
  if (reading == HIGH)
  {
    buttonToggle = not(buttonToggle);
    // Reading the switch state when the button is toggled on
    if (buttonToggle == true)
    {
    }
    // Releasing the keyboard when the button is toggled off
    if (buttonToggle == false)
    {
      Keyboard.end();
    }
  }
  return;
}

/// @brief  High level key mashing function
/// @param vendor Vendor to mash key for
/// @return Error code
int mash(GPIOAssignment vendor)
{
  mash_key(vendor);
  // Adding delay to ensure the keypress is registered
  delay(mashDelay);
  // releasing any pressed keys
  Keyboard.releaseAll();
  // delaying again to ensure a proper gap betwen keypresses
  delay(mashDelay);
}

/// @brief Presses the desired key based on digital input
/// @param key Vendor to mash BIOS key for.
int mash_key(GPIOAssignment vendor)
{
  switch (vendor)
  {
  case DELL:
    Keyboard.press(DELL_KEY);
    break;
  case HP:
    Keyboard.press(HP_KEY);
    break;
  case LENOVO:
    Keyboard.press(LENOVO_KEY);
    break;
  case NETBOOT:
    Keyboard.press(NETBOOT_KEY);
    break;
  case BLANCCO:
    Keyboard.press(KEY_ESC);
    Keyboard.press(' ');
    // TODO
    break;
  default:
    break;
  }
}