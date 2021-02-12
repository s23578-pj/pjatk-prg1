#include <iostream>

auto search(int a[], int n, int needle) -> int {
  needle = 0;
  a[n] = {};
  std::cout << "Twoja tablica o rozmiarze n równej " << n
            << " ma wartości równe:" << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl
            << "Twoja szukana wartość needle: " << needle << std::endl;
  std::string z = "";
  for (int x = 0; x < n; x++) {
    if (a[x] == needle) {
      std::cout << "Twój index wartości tej tablicy równej needle wynosi: " << x
                << std::endl;
      z = "";
      break;
    } else {
      z = "nie znaleziono: -1";
    }
  }

  std::cout << z << std::endl;
  return needle;
}

int main() {
  const int n = 10;
  int a[n] = {1, -5, 3, 2, 6, 1, 2, 7, 2, 2};
  int needle = 0;
  search(a, n, needle);
  return 0;
}
