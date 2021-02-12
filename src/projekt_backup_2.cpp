#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#define START_LINIA 2
#define MAX 3
#define STAN_MAIN_MENU 0
#define STAN_MINIGRY 1
#define STAN_PRZYBORNIK 2

#define INFOKOLUMNA 15
#define INFOWIERSZ START_LINIA + MAX + 3
#define STRZALA "<<--"
#include "rejestracja.cpp"
#include "zgadywanie.cpp"
#define ENTER 0xa /*w ncurses można również użyć KEY_ENTER*/
#include <iostream>
#include <random>
#include <string>
#include <unistd.h>
int main() {
  rdd();
  int klawisz, wybor = 1, stan = STAN_MAIN_MENU;
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  noecho();
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_BLACK);
  init_pair(3, COLOR_WHITE, COLOR_BLACK);
  clear();
  move(1, 1);
  mvprintw(1, 50, "MENU");
  attrset(COLOR_PAIR(2) | A_BOLD);
  mvprintw(START_LINIA + 1, 3, "[1] Minigry");
  mvprintw(START_LINIA + 2, 3, "[2] Przybornik");
  mvprintw(START_LINIA + 3, 3, "[3] Dane");
  refresh();
  attroff(COLOR_PAIR(2));
  attrset(COLOR_PAIR(1) | A_BOLD);
  mvprintw((START_LINIA + 1), 25, STRZALA);
  klawisz = getch(); // odczytuje tylko po jednym znaku naraz, więc jeśli chcemy
                     // odczytać drugi znak znajdujący się w buforze, wywołujemy
                     // ponownie funkcję

  while ((klawisz != 'q') && (klawisz != ERR)) {
    move(INFOWIERSZ, INFOKOLUMNA);
    clrtoeol();
    // mvprintw(INFOWIERSZ,INFOKOLUMNA, "Klawisz %d -- 0%o -- 0x%x -- %c",
    // klawisz, klawisz, klawisz, klawisz);
    switch (klawisz) {
    case KEY_UP:
      if (wybor == 1) {
        klawisz = getch();

        continue;
      }
      --wybor;
      switch (stan) {
      case STAN_MAIN_MENU:
        move((START_LINIA + wybor + 1), 25);
        clrtoeol();
        mvprintw((START_LINIA + wybor), 25, STRZALA);
        break;
      case STAN_MINIGRY:
        move((START_LINIA + wybor + 1), 20);

        clrtoeol();
        mvprintw((START_LINIA + wybor), 20, STRZALA);
        break;
      }
      break;
    case KEY_DOWN:
      if (wybor == MAX) {
        klawisz = getch();

        continue;
      }
      ++wybor;
      switch (stan) {
      case STAN_MAIN_MENU:

        move((START_LINIA + wybor - 1), 25);
        clrtoeol();
        mvprintw((START_LINIA + wybor), 25, STRZALA);
        break;
      case STAN_MINIGRY:

        move((START_LINIA + wybor - 1), 20);
        clrtoeol();
        mvprintw((START_LINIA + wybor), 20, STRZALA);
        break;
      }
      break;
      move((START_LINIA + wybor - 1), 25);
      clrtoeol();
      mvprintw((START_LINIA + wybor), 25, STRZALA);
      break;
    case KEY_HOME:
      if (wybor == 1) {
        klawisz = getch();

        continue;
      }
      move((START_LINIA + wybor), 25);
      clrtoeol();
      wybor = 1;
      mvprintw((START_LINIA + 1), 25, STRZALA);
      break;
    case KEY_END:
      if (wybor == MAX) {
        klawisz = getch();

        continue;
      }
      move((START_LINIA + wybor), 75);
      clrtoeol();
      wybor = MAX;
      mvprintw((START_LINIA + MAX), 75, STRZALA);
      break;
    case ENTER:
      move(LINES - 1, 1);
      clrtoeol();
      mvprintw(LINES - 1, 1, "Zatwierdzono: %d", wybor);
      attrset(COLOR_PAIR(3) | A_REVERSE | A_BOLD);
      if (wybor == 1) {
        stan = STAN_MINIGRY;
        wybor = 11;

        mvprintw(10, 40, "Wybrana opcja: Minigra");
        clrtoeol();
        refresh();
        mvprintw(12, 3, "Wybierz gre ponizej aby zagrac");
        mvprintw(14, 3, "Zgadnij Liczbe");
        mvprintw(15, 3, "Snajper");
        clrtoeol();
      }
      if (wybor == 12) {
        mvprintw(12, 3, "Zgadywanie Liczby");
        clrtoeol();
        system("clear");
        zgadywanie();
      }
      if (wybor == 13) {
        mvprintw(12, 3, "Snajper");
        clrtoeol();
      } else if (wybor == 2) {
        stan = STAN_PRZYBORNIK;
        wybor = 11;

        mvprintw(10, 40, "Wybrana opcja: Przybornik");
        clrtoeol();
        refresh();
        mvprintw(12, 3, "Oto twoja lista:");
        mvprintw(14, 3, "Kalkulator");
        mvprintw(15, 3, "Pogoda");
        clrtoeol();
      } else if (wybor == 3) {
        mvprintw(10, 40, "Wybrana opcja: Dane");
        clrtoeol();
      }
      attroff(COLOR_PAIR(3));
      attrset(COLOR_PAIR(1) | A_BOLD);
      break;
    default:
      klawisz = getch();

      continue;
      break;
    }

    refresh();
    usleep(50000);
    klawisz = getch();
  }
  endwin();
}
