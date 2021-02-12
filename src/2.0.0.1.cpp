#include <iostream>
// Zadanie 2.0.0.1 Lista liczb
auto ask_user_for_integer(std::string const prompt) -> int {
  if (not prompt.empty()) {
    std::cout << prompt;
  }
  auto value = std::string{};
  std::getline(std::cin, value);
  return std::stoi(value);
}
auto main() -> int {
  auto a = ask_user_for_integer("a = ");
  auto b = ask_user_for_integer("b = ");
  for (auto x = a; x < b; x++) {
    std::cout << x << std::endl;
  }
  return 0;
}
