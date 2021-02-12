#include <iostream>

// Zadanie 1.0.0.5 Wartość absolutna
auto main() -> int {
  auto a = 0;
  std::cout << "Insert Your number" << std::endl;
  std::cin >> a;
  if (a < 0) {
    std::cout << "Absolute value of Your number is: " << (-1) * a << std::endl;
  } else {
    std::cout << a << std::endl;
  }
  return 0;
}
