#include <iostream>

auto amin(int a[], int n, int min) -> int {
  min = a[0];
  a[n] = {};
  std::cout << std::endl << "Minimalna wartość wynosi: " << std::endl;
  for (int x = 0; x < n; x++) {
    if (min > a[1]) {
      min = a[x];
    }
  }
  std::cout << min << std::endl;
  return min;
}

int main() {
  const int n = 10;
  int a[n] = {1, -5, 3, 2, 6, 1, 2, 7, 2, 2};
  int min = a[0];
  amin(a, n, min);
  return 0;
}
