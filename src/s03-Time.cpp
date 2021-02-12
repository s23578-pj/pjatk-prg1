#include <iostream>
#include <s23578/Time.h>
#include <sstream>

s23578::Time::Time(size_t h, size_t m, size_t s)
    : hour(h), minute(m), second(s) {}

auto s23578::Time::Timesy() -> void {
  while (hour < 60) {
    system("clear");
    next_second();
    if (hour < 10) {
      std::cout << "0";
    }
    std::cout << hour << ":";
    if (minute < 10) {
      std::cout << "0";
    }
    std::cout << minute << ":";

    if (second < 10) {
      std::cout << "0";
    }
    std::cout << second << std::endl;
    time_of_day();
    std::cout << std::endl;
  }
}

auto s23578::Time::next_hour() -> void {
  ++hour;
  if (hour > 23) {
    hour = 0;
    next_second();
  }
}

auto s23578::Time::next_minute() -> void {
  ++minute;
  if (minute > 59) {
    minute = 0;
    next_hour();
  }
}

auto s23578::Time::next_second() -> void {
  ++second;
  if (second > 60) {
    second = 0;
    next_minute();
  }
}

auto s23578::Time::time_of_day() -> void {

  if (hour < 10 && hour >= 5) {

    std::cout << "morning";

  } else if (hour < 18 && hour >= 10) {

    std::cout << "The day";

  } else if (hour < 21 && hour >= 18) {

    std::cout << "evening";

  } else if (hour < 5 || hour >= 21) {

    std::cout << "night";
  }
}

auto main() -> int {
  s23578::Time time;
  time.Timesy();
  return 0;
}
