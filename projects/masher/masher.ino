#include "Keyboard.h"

// define variables for pins
enum GPIOAssignments
{
  DELL = 2,
  HP = 3,
  LENOVO = 4,
  NETBOOT = 5,
  BLANCCO = 6,
  TOGGLE = 8
};

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

  if (switchState == 0)
  {
    Keyboard.press(KEY_F2);
  }
  else if (switchState == 1)
  {
    Keyboard.press(KEY_F10);
  }
  else if (switchState == 2)
  {
    Keyboard.press(KEY_F1);
  }
  else if (switchState == 3)
  {
    Keyboard.press(KEY_F12);
  }
  else if (switchState == 4)
  {
    Keyboard.press(KEY_ESC);
    Keyboard.press(' ');
  }
  // else if (switchState == 5)
  // {
  // TODO: add password functionallity
  // }

  // Adding delay to ensure the keypress is registered
  delay(mashDelay);
  // releasing any pressed keys
  Keyboard.releaseAll();
  // delaying again to ensure a proper gap betwen keypresses
  delay(mashDelay);
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