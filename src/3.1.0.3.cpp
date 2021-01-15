#include <iostream>

auto iota (int a [], int n) -> void
{
    a[n]= {};
    std::cout << "Tablica, której początkiem jest zmienna start " << n <<  std::endl;
    for ( int i= 0; i<n; i++) {
        std::cout << a[i]++ << " ";  
    }
    std::cout<<std::endl;
}

int main () 
{
    
    const int n = 10;
    int a[n]= {1,5,3,2,6,1,2,7};
    iota (a, n);
    return 0;
}
