#pragma once

#include <gpiod.hpp>
#include <string>
#include <unordered_map>

class GPIO {
public:
  GPIO(const std::string &chipname = "gpiochip5");
  ~GPIO();

  void pinMode(int pin, bool isOutput);
  void digitalWrite(int pin, bool value);
  bool digitalRead(int pin);

private:
  gpiod::chip chip;
  std::unordered_map<int, gpiod::line> lines;
};