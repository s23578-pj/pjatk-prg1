#include <iostream>

auto iota (int a [], int n, int start) -> void
{
    start = 5;
    a[n]= {start};
    std::cout << "Tablica, której początkiem jest zmienna start " << n <<  std::endl;
    for ( int i= 0; i<n; i++) {
        std::cout << start++ << " ";  
    }
    std::cout<<std::endl;
}

int main () 
{
    int start = 5;
    const int n = 10;
    int a[n]= {start};
    iota (a, n, start);
    return 0;
}
