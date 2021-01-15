#include <iostream>


// Zadanie 1.0.0.3 Mnożenie
auto ask_user_for_integer(std::string const prompt) -> int
{
    if (not prompt.empty()) {
        std::cout << prompt;
    }
    auto value = std::string{};
    std::getline(std::cin, value);
    return std::stoi(value);
}
auto main() -> int
{
    auto const a = ask_user_for_integer("a = ");
    auto const b = ask_user_for_integer("b = ");

    std::cout << "Wynik mnożenia: " << a*b << std::endl;
    return 0;
}
