#include <iostream>
#include <string>

auto main(int, char* argv[]) -> int
{
    auto liczba = std::stoi(argv[1]);

    // std::cout << "jesteśmy tu\n";
    for (int i = liczba; i >= 0; --i) {
        std::cout << i << "... \n";
    }
    std::cout << "Koniec skryptu :D \n";
    return 0;
}
