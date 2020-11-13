#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int
{
    if (argc == 0)
        return 1;
    int i         = 1;
    std::string n = "-n";
    if (argv[1] == n) {
        i = 2;
        while (i <= argc) {
            std::cout << argv[1] << ", ";
            i++;
        }
    }
    while (i <= argc) {
        std::cout << "\n" << argv[1] << ", " << std::endl;
        i++;
    }
    return 0;
}
