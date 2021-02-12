#include <iostream>
int main() {

  int liczba = 0, cyfra = 0;
  std::cout << "MENU\n \n"
            << "[1] Minigry\n"
            << "[2] Przybornik\n"
            << "[3] Informacje\n \n";
  do {
    std::cout
        << "Wybierz kategorie wprowadzając odpowiadającą jej cyfrze [1-3]: ";
    std::cin >> liczba;
    if (liczba != 1 && liczba != 2 && liczba != 3) {
      std::cout << "Wprowadź odpowiedni numer \n";
    }
  } while (liczba != 1 && liczba != 2 && liczba != 3);

  switch (liczba) {
  case 1:
    std::cout << "Wybrana opcja: Minigra \n" << std::endl;
    std::cout << "Wybierz jedną z gier poniżej poprzez odpowiednią cyfrę by "
                 "móc zagrać. \n";
    std::cout << "[1] Losowanie liczby\n"
              << "[2] Snajper\n"
              << std::endl;

    do {
      std::cin >> cyfra;
      if (cyfra != 1 && cyfra != 2) {
        std::cout << "Wprowadź poprawny numer \n";
      }
    } while (cyfra != 1 && cyfra != 2);

    switch (cyfra) {
    case 1:
      std::cout << "Wybrano opcję Losowanie Liczby\n";
      break;
    case 2:
      std::cout << "Wybrano opcje Snajper\n";
      break;
    }
    break;
  case 2:
    std::cout << "Wybrana opcja: Przybornik \n" << std::endl;
    std::cout
        << " ▄         ▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄            ▄            ▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄  ▄▄        ▄  ▄▄▄▄▄▄▄▄▄▄▄ \n\
▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░▌          ▐░▌          ▐░░░░░░░░░░▌ ▐░░░░░░░░░░░▌▐░░▌      ▐░▌▐░░░░░░░░░░░▌\n\
▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀▀▀ ▐░▌          ▐░▌          ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌▐░▌░▌     ▐░▌▐░█▀▀▀▀▀▀▀▀▀ \n\
▐░▌       ▐░▌▐░▌          ▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌▐░▌    ▐░▌▐░▌          \n\
▐░▌   ▄   ▐░▌▐░█▄▄▄▄▄▄▄▄▄ ▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌ ▐░▌   ▐░▌▐░█▄▄▄▄▄▄▄▄▄ \n\
▐░▌  ▐░▌  ▐░▌▐░░░░░░░░░░░▌▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌  ▐░▌  ▐░▌▐░░░░░░░░░░░▌\n\
▐░▌ ▐░▌░▌ ▐░▌▐░█▀▀▀▀▀▀▀▀▀ ▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌   ▐░▌ ▐░▌▐░█▀▀▀▀▀▀▀▀▀ \n\
▐░▌▐░▌ ▐░▌▐░▌▐░▌          ▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌    ▐░▌▐░▌▐░▌          \n\
▐░▌░▌   ▐░▐░▌▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌▐░▌     ▐░▐░▌▐░█▄▄▄▄▄▄▄▄▄ \n\
▐░░▌     ▐░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░▌ ▐░░░░░░░░░░░▌▐░▌      ▐░░▌▐░░░░░░░░░░░▌\n\
 ▀▀       ▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀   ▀▀▀▀▀▀▀▀▀▀▀  ▀        ▀▀  ▀▀▀▀▀▀▀▀▀▀▀ \n";

    break;
  case 3:
    std::cout << "Wybrana Opcja: Dane" << std::endl;
    break;
  }
  return 0;
}
