#include <iostream>

// Zadanie 2.0.0.2 Lista liczb(2)
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
    auto a = ask_user_for_integer("a = ");
    auto b = ask_user_for_integer("b = ");
    auto c = ask_user_for_integer("c = ");
        if(c == 0){
            std::cerr << "Do not divide by 0!" << std::endl; 
            return 1;
        }
    for(auto x = a; x < b; x++){
        if(x % c == 0){
        std::cout << x << std::endl;
        }
    }
    return 0;
}
