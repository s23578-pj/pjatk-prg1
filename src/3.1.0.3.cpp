#include <iostream>

auto asum(int a[], int n, int suma) -> int {
  suma = 0;
  a[n] = {};
  std::cout << std::endl << "Suma tych wartości wynosi: " << std::endl;
  for (int x = 0; x < n; x++) {
    suma += a[x];
  }
  std::cout << suma << std::endl;
  return suma;
}

int main() {
  int suma = 0;
  const int n = 10;
  int a[n] = {1, 5, 3, 2, 6, 1, 2, 7, 2, 2};
  asum(a, n, suma);
  return 0;
}
