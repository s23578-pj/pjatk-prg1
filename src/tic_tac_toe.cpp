#include <iostream>

// Funkcja rysuje planszę gry w kółko i krzyżyk
//---------------------------------------------
void plansza(char t[]) {
  for (int i = 1; i <= 9; i++) {
    std::cout << " " << t[i] << " ";
    if (i % 3)
      std::cout << "|";
    else if (i != 9)
      std::cout << "\n---+---+---\n";
    else
      std::cout << std::endl;
  }
}

// Funkcja zwraca true, jeśli nastąpiła
// wygrana danego zawodnika
//-------------------------------------
bool wygrana(char t[], char g) {
  bool test;
  int i;

  test = false;
  for (i = 1; i <= 7; i += 3)
    test |= ((t[i] == g) && (t[i + 1] == g) && (t[i + 2] == g));
  for (i = 1; i <= 3; i++)
    test |= ((t[i] == g) && (t[i + 3] == g) && (t[i + 6] == g));
  test |= ((t[1] == g) && (t[5] == g) && (t[9] == g));
  test |= ((t[3] == g) && (t[5] == g) && (t[7] == g));
  if (test) {
    plansza(t);
    std::cout << "\nGAMER " << g << " WIN!!!\n\n";
    return true;
  }
  return false;
}

// Funkcja zwraca true, jeśli na planszy nie ma już
// żadnego wolnego pola na ruch.
//-------------------------------------------------
bool remis(char t[]) {
  for (int i = 1; i <= 9; i++)
    if (t[i] == ' ')
      return false;
  plansza(t);
  std::cout << "\nDRAW !!!\n\n";
  return true;
}

// Funkcja umożliwia ruch gracza
// Po ruchu następuje zamiana gracza
//------------------------------------
void ruch(char t[], char &gracz) {
  int r;

  plansza(t);
  std::cout << "\nGAMER " << gracz << " : Your turn : ";
  std::cin >> r;
  std::cout << "-----------------------\n\n";
  if ((r >= 1) && (r <= 9) && (t[r] == ' '))
    t[r] = gracz;
  gracz = (gracz == 'O') ? 'X' : 'O';
}

int tic_tack() {
  char p[10], g, w;

  std::cout << " \n\
                                                    ╔╦╗╦╔╗╔╦  ╔═╗╔═╗╔╦╗╔═╗╔═╗ \n\
                                                    ║║║║║║║║  ║ ╦╠═╣║║║║╣ ╚═╗ \n\
                                                    ╩ ╩╩╝╚╝╩  ╚═╝╩ ╩╩ ╩╚═╝╚═╝ \n\
    \n";

  do {
    std::cout << "Game in tic tac toe for 2 gamers (or 1 if u alone :( )\n"
                 "======================================\n\n";
    for (int i = 1; i <= 9; i++)
      p[i] = ' ';
    g = 'O';
    while (!wygrana(p, 'X') && !wygrana(p, 'O') && !remis(p))
      ruch(p, g);
    std::cout << "Do you wanna play again ? (T = YES) : ";
    std::cin >> w;
    while((w = getchar()) != '\n' && w != EOF)
    std::cout << "\n\n\n";
  } while ((w == 'T') || (w == 't'));
  return 0;
}
