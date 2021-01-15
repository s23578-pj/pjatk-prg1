#include <iostream>
#include <string>

// Zadanie 1.0.0.4 Większa liczba
auto ask_user_for_integer(std::string const prompt) -> int
{
    if(not prompt.empty()) {
    std::cout << prompt;
    }
    auto value = std::string{};
    std::getline(std::cin, value);
    return std::stoi(value);
    }
auto main() -> int
{
    auto const a = ask_user_for_integer(" a = ");
    auto const b = ask_user_for_integer(" b = ");
    if(a > b)
    {
        std::cout <<"Bigger number is: "<< a << std::endl;
    }
    else if(b > a)
    {
        std::cout <<"Bigger number is: "<< b << std::endl;
    }
    return 0;
}
