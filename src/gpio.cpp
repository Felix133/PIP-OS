#include "gpio.h"
#include <stdexcept>

GPIO::GPIO(const std::string &chipname) : chip(chipname) {}

GPIO::~GPIO() {
  // The gpiod::line destructor will automatically release the line
}

void GPIO::pinMode(int pin, bool isOutput) {
  auto line = chip.get_line(pin);
  if (isOutput) {
    line.request({"myapp", gpiod::line_request::DIRECTION_OUTPUT, 0});
  } else {
    line.request({"myapp", gpiod::line_request::DIRECTION_INPUT, 0});
  }
  lines[pin] = std::move(line);
}

void GPIO::digitalWrite(int pin, bool value) {
  if (lines.find(pin) == lines.end()) {
    throw std::runtime_error("Pin not configured");
  }
  lines[pin].set_value(value ? 1 : 0);
}

bool GPIO::digitalRead(int pin) {
  if (lines.find(pin) == lines.end()) {
    throw std::runtime_error("Pin not configured");
  }
  return lines[pin].get_value() == 1;
}