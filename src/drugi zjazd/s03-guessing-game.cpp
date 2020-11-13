#include <cstdlib>
#include <ctime>
#include <iostream>
int main()
{
    srand(time(NULL));
    int losuj = ((std::rand() % 50) + 7);
    // std::cout << "Wylosowanie pierwsze: " << losuj << std::endl;
    std::cout << "Chose number from 1-100\n";

    while (true) {
        std::cout << "Your number:";
        int zgaduj_liczbe;
        std::cin >> zgaduj_liczbe;
        if (losuj == zgaduj_liczbe) {
            std::cout << "just right!\n";
            break;
        } else if (zgaduj_liczbe > losuj) {
            std::cout << "Number too big!\n";
        } else if (zgaduj_liczbe < losuj) {
            std::cout << "Number too small!\n";
        }
    }
    return 0;
}
