#include <iostream>
#include <stdlib.h>
#include <unistd.h>

int the_weather(void) {
  std::cout
      << "Check if our Firefox is installed because the page opens only on it!"
      << std::endl;
  sleep(2.0);
  system("firefox -new-tab https://pogoda.interia.pl/");
  return 0;
}
