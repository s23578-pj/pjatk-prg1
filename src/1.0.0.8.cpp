#include <iostream>


// Zadanie 1.0.0.8 Największa
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
    auto const c = ask_user_for_integer(" c = ");
    
    if( a == b && a == c && b == c)
    {
        std::cout << "No one is higher. All are the same" << std::endl;
        return 1;
    }
    if(a > b)
    {
        if (a > c)
        {
            std::cout << a << std::endl;
        }
        else
        {
            std::cout << c << std::endl;
        }
    }
    else if(b > c)
    {
        std::cout << b << std::endl;
    }
    else
    {
        std::cout << c << std::endl;
    }
    return 0;
}

