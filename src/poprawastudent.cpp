#include <iostream>
#include <array>
/*
auto main() -> int 
{
    int x = 7;
    int d = -2;
    while(x > d){
        std::cout << x << std::endl;
        --x;   
        }
    return 0;
}
//========================
auto main() -> int
{
    int D = 5;
    for(int X = D ; X >= -10 ; X--)
        std::cout << X << std::endl;
    return 0;
}


auto main() -> int
{
    
    std::array<int, 8> tab;    
    for(auto x = 0; x < 8 ; x++) {
        tab[x] = (x+1)*2;
            std::cout << tab[x] << std::endl;
    }return 0;
}
*/
auto main() -> int
{   
    for(int x = 1 ; x <= 5 ; x++)
    {
        for(int d = 0; d < x ; d++)
        {
            std::cout << "*";
        }
    std::cout << std::endl;
    }
    return 0;
}

