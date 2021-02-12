#include <iostream>

auto amax(int a[], int n, int max) -> int {
  max = a[0];
  a[n] = {};
  std::cout << std::endl << "Maksymalna wartość wynosi: " << std::endl;
  for (int x = 0; x < n; x++) {
    if (max < a[x]) {
      max = a[x];
    }
  }
  std::cout << max << std::endl;
  return max;
}

int main() {
  const int n = 10;
  int a[n] = {1, -5, 3, 2, 6, 1, 2, 7, 2, 2};
  int max = a[0];
  amax(a, n, max);
  return 0;
}
