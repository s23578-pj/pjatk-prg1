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
    if (a < 3) {
        std::cout << "Minimal size is 3!" << std::endl;
        return 1;
    }
    for (int i = 1; a >= i; i++) {
        for (int j = 1; a >= j; j++) {
            if (j == 1 || j == a || i == 1 || i == a) {
                std::cout << x;
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
