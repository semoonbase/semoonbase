
#include "core.hpp"
#include "key.hpp"

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
