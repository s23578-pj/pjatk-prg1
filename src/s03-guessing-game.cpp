#include <iostream>
#include <random>
#include <string>
auto ask_user_for_integer() -> int {
  std::cout << "Chose number from 1-100\n";
  auto n = std::string();
  std::getline(std::cin, n);
  return std::stoi(n);
}
int main() {
  std::random_device rd;
  std::uniform_int_distribution<int> sto(1, 100);
  int losuj = sto(rd);
  while (true) {
    int zgaduj_liczbe = ask_user_for_integer();
    if (losuj == zgaduj_liczbe) {
      std::cout << "just right!\n";
      break;
    } else if (zgaduj_liczbe > losuj) {
      std::cout << "Number too big!\n";
    } else if (zgaduj_liczbe < losuj) {
      std::cout << "Number too small!\n";
    }
  }
  return 0;
}
