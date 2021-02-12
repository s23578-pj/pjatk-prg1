#include <cstdlib>
#include <iostream>

auto sort_asc(int a[], int n) -> void {
  for (int i = 0; i < n; i++)
    for (int j = 1; j < n - i; j++) // pętla wewnętrzna
      if (a[j - 1] > a[j])
        // zamiana miejscami
        std::swap(a[j - 1], a[j]);
}

int main() {
  int *a, n;

  do {
    std::cout << " Ile liczb będziesz chciał posortować rosnąco? ";
    std::cin >> n;
    if (n < 2) {
      std::cerr << " Wpisz 2 lub więcej liczb by sortowanie miało sens. "
                << std::endl;
    } else {
      break;
    }
  } while (true);
  a = new int[n]; // przydzielenie pamięci na elementy tablicy
  // wczytanie liczb
  for (int i = 0; i < n; i++)
    std::cin >> a[i];

  sort_asc(a, n);

  // wypisanie posortowanych elementów
  for (int i = 0; i < n; i++)
    std::cout << a[i] << " ";

  std::cout << std::endl;
  return 0;
}
