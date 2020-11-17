#include <iostream>
#include <string>

auto main(int, char* argv[]) -> int
{
    auto const poprawnehaslo = std::string{argv[1]};
    auto haslo               = std::string{};
    std::cout << "Podaj haslo:\n";
    std::getline(std::cin, haslo);

    while (haslo != poprawnehaslo) {
        std::cout << "jeszcze raz:";
        std::getline(std::cin, haslo);
    }
    std::cout << "ok!\n";
    return 0;
}
