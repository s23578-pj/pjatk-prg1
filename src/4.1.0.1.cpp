#include <iostream>
#include <string>
int main()
{
    std::cout << "Size in bites:" << std::endl;
    std::cout << "Size of char = " << sizeof(char) << std::endl;
    std::cout << "Size of int = " << sizeof(int) << std::endl;
    std::cout << "Size of unsigned short (uint16_t) = "
              << sizeof(unsigned short) << std::endl;
    std::cout << "Size of unsigned int (uint32_t) = " << sizeof(unsigned int)
              << std::endl;
    std::cout << "Size of unsigned = " << sizeof(unsigned) << std::endl;
    std::cout << "Size of long = " << sizeof(long) << std::endl;
    std::cout << "Size of float = " << sizeof(float) << std::endl;
    std::cout << "Size of double = " << sizeof(double) << std::endl;
    std::cout << "Size of std::string = " << sizeof(std::string) << std::endl;
    return 0;
}
