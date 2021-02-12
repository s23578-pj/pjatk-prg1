#include <iostream>

// Zadanie 2.0.0.11 RYSOWANIE FIGURY (prostokąt)
auto ask_user_for_integer(std::string const prompt) -> int {
  if (not prompt.empty()) {
    std::cout << prompt;
  }
  auto value = std::string{};
  std::getline(std::cin, value);
  return std::stoi(value);
}
auto main() -> int {
  auto const xi = ask_user_for_integer("x = ");
  auto const y = ask_user_for_integer("y = ");
  for (int x = 0; x < xi; x++) {
    for (int d = 0; d < y; d++) {
      std::cout << "*";
    }
    std::cout << std::endl;
  }
  return 0;
}
