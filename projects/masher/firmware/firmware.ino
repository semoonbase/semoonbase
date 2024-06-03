
#include "core.hpp"
#include "key.hpp"

void setup()
{
  core::setup();
}

void loop()
{
  core::mash(gpio::Pin::DELL);
}
