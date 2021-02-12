#include <iostream>

// Zadanie 2.0.0.9 WHILE
auto ask_user_for_integer(std::string const prompt) -> int {
  if (not prompt.empty()) {
    std::cout << prompt;
  }
  auto value = std::string{};
  std::getline(std::cin, value);
  return std::stoi(value);
}
auto main() -> int {
  auto Factorial = 1;
  auto i = 0;
  auto n = 1;

  auto const x = ask_user_for_integer("x = ");
  while (i < x) {
    Factorial = n * Factorial;
    i++;
    n++;
  }
  std::cout << x << "! = " << Factorial << std::endl;
  return 0;
}
