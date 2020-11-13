#include <iostream>
#include <string>

auto main(int, char* argv[]) -> int
{
    // if (argc == 0){
    // return 1;
    //}
    auto const n = std::stoi(argv[1]);

    for (int i = 1; i <= n; ++i) {
        std::cout << i << ", ";
    }
    std::cout << "\n\n";
    int i = 1;
    while (i <= n) {
        if (i % 3 == 0 && i % 5 == 0) {
            std::cout << i << " fizzbuzz \n";
        } else if (i % 3 == 0) {
            std::cout << i << " fizz \n";
        } else if (i % 5 == 0) {
            std::cout << i << " buzz \n";
        }
        i++;
    }

    return 0;
}
