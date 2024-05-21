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

int previousButtonState = HIGH;
int switchState = 0;
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
  //
  int buttonState = digitalRead(buttonPin);

  // Only reading the switch state if the button is pressed
  if (buttonState == LOW && previousButtonState == HIGH)
  {
    //
  }

  // Releasing the keyboard if the button is not pressed to allow bios configuration
  if (buttonState == HIGH && previousButtonState == LOW)
  {
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
  // else if (switchState == 5){
  // TODO: add password functionallity
  // }
  previousButtonState = buttonState;
}
