#include <iostream>
using namespace std;

auto quick_sort(int *tab, int lewy, int prawy) -> void {
  if (prawy <= lewy)
    return;

  int i = lewy - 1, j = prawy + 1,
      pivot = tab[(lewy + prawy) / 2]; // wybieramy punkt odniesienia

  while (1) {
    // szukam elementu wiekszego lub rownego piwot stojacego
    // po prawej stronie wartosci pivot
    while (pivot > tab[++i])
      ;

    // szukam elementu mniejszego lub rownego pivot stojacego
    // po lewej stronie wartosci pivot
    while (pivot < tab[--j])
      ;

    // jesli liczniki sie nie minely to zamień elementy ze soba
    // stojace po niewlasciwej stronie elementu pivot
    if (i <= j)
      // funkcja swap zamienia wartosciami tab[i] z tab[j]
      std::swap(tab[i], tab[j]);
    else
      break;
  }

  if (j > lewy)
    quick_sort(tab, lewy, j);
  if (i < prawy)
    quick_sort(tab, i, prawy);
}
int main() {
  int *tab, n;

  // cout<<"Ile liczb będziesz chciał posortować? ";
  do {
    std::cout << "Ile liczb będziesz chciał posortować? ";
    std::cin >> n;
    if (n < 2) {
      std::cerr << "Wpisz 2 lub więcej liczb by sortowanie miało sens."
                << std::endl;
    } else {
      break;
    }
  } while (true);
  tab = new int[n]; // przydzielenie pamięci na elementy tablicy
  // wczytanie liczb
  for (int i = 0; i < n; i++) {
    std::cin >> tab[i];
  }
  quick_sort(tab, 0, n - 1);

  // wypisanie posortowanych elementów
  for (int i = 0; i < n; i++) {
    std::cout << tab[i] << " ";
  }
  std::cout << endl;

  return 0;
}
