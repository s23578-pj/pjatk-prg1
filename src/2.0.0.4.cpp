#include <iostream>

// Zadanie 2.0.0.4 Liczba pierwsza
auto ask_user_for_integer(std::string const prompt) -> int 
{
    if (not prompt.empty()) {
    std::cout << prompt;
    }
    auto value = std::string{};
    std::getline(std::cin, value);
    return std::stoi(value);
    }
int main()
{
    do
    {
        int i, m = 0, counter = 0;

        std::cout << "Enter the Number to check Prime: " << std::endl;
        auto n = ask_user_for_integer("n = ");
        
        if(n < 2 && n > -1)
        {
            std::cout << "Number is not Prime" << std::endl;
            continue;
        }        
        else if(n < 0)
        {
            std::cout << "This is not a positive number" << std::endl;
            continue;        

        }
        m = n / 2;
        for (i = 2; i <= m; i++)
        {
            if (n % i == 0)
            {
                std::cout << "Number is not Prime." << std::endl;
                counter = 1;
                break;
            }
        }
        if (counter == 0)
        {
            std::cout << "Number is Prime." << std::endl;
        }
    } while (true);

    return 0;
}
