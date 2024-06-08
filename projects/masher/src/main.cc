
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
    /// Debounce
    delay(50);
    return;
  }
  else
  {
    /// Debounce
    delay(50);
  }

  /// Reduce to a single key

  /// Mash keys
  core::mash(gpio::Pin::DELL);
}
