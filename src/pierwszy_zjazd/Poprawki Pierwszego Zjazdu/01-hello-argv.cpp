/*
 * Reading command line arguments.
 */

#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int
{
    if (argc < 2) {
        std::cerr << "za mało argumentów!\n";
        return 1;
    }
    if (argc > 2) {
        std::cerr << "Proszę podać tylko imię.\n";
        return 1;
    }

    auto const name = std::string{argv[1]};
    std::cout << "Hello, " << name << "!\n";

    return 0;
}
