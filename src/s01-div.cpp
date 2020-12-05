#include <iostream> // for std::cout , std::cerr , and std::cin
#include <string>

auto main(int argc, char *argv[]) -> int {
  if (argc == 0) {
    return 1;
  }

  auto const a = std::stoi(argv[1]);
  auto const b = std::stoi(argv[2]);

  if (b == 0) {
    std::cout << "Nie wolno dzielić przez 0\n";
  }

  std::cout << (a / b) << "\n";
  return 0;
}
