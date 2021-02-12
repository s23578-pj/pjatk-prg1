#include <iostream>

// Zadanie 2.0.0.8 Silnia (for)

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
  auto const x = ask_user_for_integer("x = ");
  for (auto i = 1; i <= x; i++) {
    Factorial = Factorial * i;
  }
  std::cout << x << "! = " << Factorial << std::endl;
  return 0;
}
