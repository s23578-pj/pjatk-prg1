#include <iostream>
#include <s23578/student.h>
using namespace s23578;

auto main() -> int {
  s23578::Student nowy; // wersja z wpisywaniem
  // s23578::Student domyslne;         // wersja z wypisywaniem domyślnej
  nowy.read(); // wersja z wpisywaniem
  // domyślne = niezmieniona klasa     // wersja z wypisywaniem domyślnej
  // domyslne.myself();                // wersja z wypisywaniem domyślnej
  nowy.myself(); // wersja z wpisywaniem
  return 0;
}
