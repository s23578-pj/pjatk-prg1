#include <iostream>

auto init(int a[], int n) -> void {
  a[n] = {};
  std::cout << "Twoja tablica o rozmiarze n równej " << n
            << " ma wartości równe:" << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  const int n = 5;
  int a[n] = {};
  init(a, n);
  return 0;
}
