
#include <avr/io.h>
#include <util/delay.h>

#include "core.h"
#include "key.h"

// AVR-GCC Compatibility
int main()
{
  setup();
  while (1)
  {
    loop();
  }
  return 0;
}

void setup()
{
  core::setup();
}

void loop()
{
  /// Read switches
  auto reading = gpio::readGPIO();

  if (gpio::isActive(reading))
  {
    // Try to reduce the reading to a single key
    kbemu::Key maybe_defined_key = core::tryReduceReport(reading);

    // Validate reduction
    if (maybe_defined_key != kbemu::Key::UNDEFINED)
    {
      // Key is defined, press it
      Keyboard.press(maybe_defined_key);
    } else {
      // TODO(Lucas): Flash LE_key != kbemu::Key::UNDEFINED)
    }
  }

  /// Debounce
  delay(50);
  Keyboard.releaseAll();
}
