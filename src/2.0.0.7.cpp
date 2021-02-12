#include <iostream>

// Zadanie 2.0.0.7 Suma Podzielnych
auto ask_user_for_integer(std::string const prompt) -> int {
  if (not prompt.empty()) {
    std::cout << prompt;
  }
  auto value = std::string{};
  std::getline(std::cin, value);
  return std::stoi(value);
}
auto main() -> int {
  auto l = ask_user_for_integer("Limit = ");
  auto d = ask_user_for_integer("Dzielnik = ");

  int s = 0;
  for (auto i = l; 1 <= i; i--) {
    if (i % d == 0) {
      s = s + i;
      std::cout << "Suma = " << s << std::endl;
    }
  }
  return 0;
}
