#include <iostream>
#include <string>
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
    char x = '*';
    auto const a = ask_user_for_integer("a= ");
    if (a < 2) {
        std::cout << "Wrong input minimal size is 2!" << std::endl;
        return 1;
    }
    for (int i = a; i >= 1; i--) {
        for (int j = i; j > 0; j--) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
