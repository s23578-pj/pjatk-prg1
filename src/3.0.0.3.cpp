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

void swap(int* a, int* b)
{
    std::cout << *a << " " << *b << std::endl;
    std::cout << *b << " " << *a << std::endl;
}

auto main() -> int
{
    auto a = ask_user_for_integer("a= ");
    auto b = ask_user_for_integer("b= ");
    if (a == b) {
        std::cout << "Numbers have to be diffrence!" << std::endl;
        return 1;
    }
    int* wa = &a;
    int* wb = &b;
    swap(wa, wb);
    return 0;
}
