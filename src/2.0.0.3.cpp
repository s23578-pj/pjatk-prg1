#include <iostream>

// Zadanie 2.0.0.3 Lista Liczb(3)
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
    auto s = ask_user_for_integer("s = ");
        if(s == 0){
            std::cerr << "\n<<ERROR!>>\n" << "s` value cannot be 0!"<< std::endl;
            return 1;    
        }
    std::cout << std::endl;
    if(s > 0){
        for(auto x = a; x < b; x = (x+s)){
            std::cout << x << std::endl;
        }
    }
        else if(s < 0){
        for(auto x = b; x < a; x = (x-s)){
            std::cout << x << std::endl;
        }
    }
    return 0;
}

