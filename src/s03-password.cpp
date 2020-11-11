#include <iostream>
#include <string>

auto ask_user_for_password(std::string prompt) -> int
{
    std::cout << prompt << "password:";
    auto n = std::string();
    std::getline(std::cin, n);
    return std::stoi(n);
}   

 auto main () -> int
{
    auto const a = ask_user_for_password(" a = ");
    if (a != student) {
        std::cout <<"Nie poprawne hasło\n";
    else (a = student) {
        std::cout <<"ok!\n";
    }
    std::cout << a << "\n";
        return 0;
}
