#include <iostream>
#include <string>
// Zadanie 1.0.0.6 Relacja między liczbami
auto ask_user_for_integer(std::string const prompt) -> int {
  if (not prompt.empty()) {
    std::cout << prompt;
  }
  auto value = std::string{};
  std::getline(std::cin, value);
  return std::stoi(value);
}
auto main() -> int {
  auto const a = ask_user_for_integer(" a = ");
  auto const b = ask_user_for_integer(" b = ");
  if (a > 0 || a < 0) {
    std::cout << std::endl << "Wynik" << std::endl;
    if (a == b) {
      std::cout << a << " == " << b << std::endl;
    }
    if (a < b) {
      std::cout << a << " < " << b << std::endl;
    }
    if (a > b) {
      std::cout << a << " > " << b << std::endl;
    }
  }
  return 0;
}
