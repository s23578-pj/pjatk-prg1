#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int
{
    if (argc == 0) {
        return 1;
    }

    if (argv[1] == std::string("-n")) {
        for (int i = 2; i < argc; i++) {
            std::cout << argv[i] << " " << std::endl;
        }
    } else if (argv[1] == std::string("-l")) {
        for (int i = 2; i < argc; i++) {
            std::cout << argv[i] << std::endl;
        }
        std::cout << std::endl;
    } else if (argv[1] == std::string("-r")) {
        if (argv[2] == std::string("-l")) {
            for (int i = argc - 1; i >= 3; i--) {
                std::cout << argv[i] << std::endl;
            }
            std::cout << std::endl;
        } else if (argv[2] == std::string("-n")) {
            for (int i = argc - 1; i >= 3; i--) {
                std::cout << argv[i] << " ";
            }
        } else {
            for (int i = argc - 1; i >= 2; i--) {
                std::cout << argv[i] << " ";
            }
            std::cout << std::endl;
        }
    } else {
        for (int i = 1; i < argc; i++) {
            std::cout << argv[i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
