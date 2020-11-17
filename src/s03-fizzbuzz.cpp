#include <iostream>
#include <string>

auto main(int, char* argv[]) -> int
{
    // if (argc == 0){
    // return 1;
    //}
    auto const liczba = std::stoi(argv[1]);
    int n             = 1;
    while (n <= liczba) {
        std::cout << n;
        if (n % 3 == 0 && n % 5 == 0) {
            std::cout << " fizzbuzz";
        } else if (n % 3 == 0) {
            std::cout << " fizz";
        } else if (n % 5 == 0) {
            std::cout << " buzz";
        } /*else {
         std::cout << i << " niepodzielna przez 3 ani 5 \n";
        }*/
        std::cout << std::endl;
        n++;
    }

    return 0;
}
