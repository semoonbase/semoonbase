#include "Keyboard.h"
// define variables for pins
const int selectDell = 2;
const int selectHP = 3;
const int selectLenovo = 4;
const int selectNetboot = 5;
const int selectBlancco = 6;
// TODO: add password functionallity
// const int selectPassword = 7;
const int buttonPin = 8;
bool buttonToggle = false;
int switchState = 0;
// Delay on the rising and falling edges of the simulated keypress in milliseconds
int mashDelay = 100;

void setup()
{
  // Declare the inputs as Pullups
  pinMode(selectDell, INPUT_PULLUP);
  pinMode(selectHP, INPUT_PULLUP);
  pinMode(selectLenovo, INPUT_PULLUP);
  pinMode(selectNetboot, INPUT_PULLUP);
  pinMode(selectBlancco, INPUT_PULLUP);
  // TODO: add password functionallity
  // pinmode(selectPassword, INPUT_PULLUP);
  pinMode(buttonPin, INPUT_PULLUP);
  Keyboard.begin();
}

void loop()
{
  // Toggling the internal state of the button if it is pressed
  int buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH)
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
