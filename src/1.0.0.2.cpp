#include <iostream>
#include <string>

// Zadanie 1.0.0.2 Dodawanie
auto main(int argc, char *argv[]) -> int {
  if (argc == 0) {
    return 1;
  }
  auto const a = std::stoi(argv[1]);
  auto const b = std::stoi(argv[2]);
  std::cout << (a + b) << "\n";
  return 0;
}
