#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
//Define Start of program, max amplitude selection and declaring "STAN`s"
#define START_LINIA 2
#define MAX 3
#define STAN_MAIN_MENU 0
#define STAN_MINIGRY 1
#define STAN_PRZYBORNIK 2
#define STAN_DANE 3

// Define the start, length, and end of "MiniGames" submenu
#define MINIGRY_MENU_START 14
#define MINIGRY_MENU_LEN 3
#define MINIGRY_MENU_END MINIGRY_MENU_START + MINIGRY_MENU_LEN - 1

// Define the start, length, and end of "ToolBox" submenu
#define PRZYBORNIK_MENU_START 14
#define PRZYBORNIK_MENU_LEN 3
#define PRZYBORNIK_MENU_END PRZYBORNIK_MENU_START + PRZYBORNIK_MENU_LEN - 1

// Define the start, length, and end of "DANE" submenu
#define DANE_MENU_START 14
#define DANE_MENU_LEN 2
#define DANE_MENU_END DANE_MENU_START + DANE_MENU_LEN - 1
// Mainly to show which button was pressed
#define INFOKOLUMNA 15
//
#define INFOWIERSZ START_LINIA + MAX + 3
#define STRZALA "<<--"
// Subprogramy
#include "The_Weather.cpp"
#include "calculator.cpp"
#include "credits.cpp"
#include "notepad.cpp"
#include "rejestracja.cpp"
#include "throw_a_dice.cpp"
#include "tic_tac_toe.cpp"
#include "zgadywanie.cpp"
//#include "information.cpp"
#define ENTER 0xa /*w ncurses można również użyć KEY_ENTER*/
#include <iostream>
#include <random>
#include <string>
#include <time.h>
#include <unistd.h>
#include <vector>

void menu_remove_strzala();
void przybornik_reset_strzala();
void minigry_reset_strzala();
void dane_reset_strzala();
void clear_submenu_area();

clock_t start, stop;
double czas;

int main(int argc, char *argv[]) {

  rdd();
  start = clock();
  int klawisz, wybor = 1, stan = STAN_MAIN_MENU;
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  noecho();

  // Make sure that the terminal supports colors
  if (!has_colors()) {
    // if not, exit and return -1 (error code)
    return -1;
  }

  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_BLACK);
  init_pair(3, COLOR_WHITE, COLOR_BLACK);
  clear();
  move(1, 1);
  mvprintw(1, 50, "MENU");
  attrset(COLOR_PAIR(2) | A_BOLD);
  mvprintw(START_LINIA + 1, 3, "[1] MiniGames");
  mvprintw(START_LINIA + 2, 3, "[2] ToolBox");
  mvprintw(START_LINIA + 3, 3, "[3] Data");
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

    // Create a variable to be used later
    int next_menu_position;
    switch (klawisz) {
    case 'b':
      // If we are in the main_menu state, get a new character and continue
      if (stan == STAN_MAIN_MENU) {
        klawisz = getch();
        continue;
      }
      // Otherwise, clear the submenu area
      clear_submenu_area();

      // Set our state to the main menu state
      stan = STAN_MAIN_MENU;
      // Set our "choice" to 1 so we start on "Minigry"
      wybor = 1;
      // Print the selection arrow
      mvprintw(START_LINIA + wybor, 25, STRZALA);
      mvchgat(START_LINIA + wybor, 25, -1, A_BOLD, 1, NULL);
      break;
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
      case STAN_MINIGRY: // Minigame (minigry) state has its own submenu
        next_menu_position = START_LINIA + wybor;
        // Check to see if we are out of bounds of the submenu
        // If so, increment wybor by one to bring back in bounds
        if (next_menu_position < MINIGRY_MENU_START)
          wybor++;

        // Erase the selection icon from the previous selection
        minigry_reset_strzala();

        // Print the new selection icon
        mvprintw((START_LINIA + wybor), 20, STRZALA);
        break;
      case STAN_PRZYBORNIK: // Toolbox (przybornik) state has its own submenu
        next_menu_position = START_LINIA + wybor;
        // Check to see if we are out of bounds of the submenu
        // If so, increment wybor by one to bring back in bounds
        if (next_menu_position < PRZYBORNIK_MENU_START)
          wybor++;

        // Erase the selection icon from the previous selection
        przybornik_reset_strzala();

        // Print the new selection icon
        mvprintw((START_LINIA + wybor), 20, STRZALA);
        break;
      case STAN_DANE: // DANE state has its own submenu
        next_menu_position = START_LINIA + wybor;
        // Check to see if we are out of bounds of the submenu
        // If so, increment wybor by one to bring back in bounds
        if (next_menu_position < DANE_MENU_START)
          wybor++;

        // Erase the selection icon from the previous selection
        dane_reset_strzala();

        // Print the new selection icon
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
      case STAN_MINIGRY: // Minigame (minigry) state has its own submenu
        next_menu_position = START_LINIA + wybor;
        // Check to see if we are out of bounds of the submenu
        // If so, decrement wybor by one to bring back in bounds
        if (next_menu_position > MINIGRY_MENU_END)
          wybor--;

        // Erase the selection icon from the previous selection
        minigry_reset_strzala();

        // Print the new selection icon
        mvprintw((START_LINIA + wybor), 20, STRZALA);
        break;
      case STAN_PRZYBORNIK: // Minigame (minigry) state has its own submenu
        next_menu_position = START_LINIA + wybor;
        // Check to see if we are out of bounds of the submenu
        // If so, decrement wybor by one to bring back in bounds
        if (next_menu_position > PRZYBORNIK_MENU_END)
          wybor--;

        // Erase the selection icon from the previous selection
        przybornik_reset_strzala();

        // Print the new selection icon
        mvprintw((START_LINIA + wybor), 20, STRZALA);
        break;
      case STAN_DANE: // Minigame (minigry) state has its own submenu
        next_menu_position = START_LINIA + wybor;
        // Check to see if we are out of bounds of the submenu
        // If so, decrement wybor by one to bring back in bounds
        if (next_menu_position > DANE_MENU_END)
          wybor--;

        // Erase the selection icon from the previous selection
        dane_reset_strzala();

        // Print the new selection icon
        mvprintw((START_LINIA + wybor), 20, STRZALA);
        break;
      }
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

      mvprintw(LINES - 1, 1, "Zatwierdzono: %d       Press 'B' to back or 'Q' to logout", wybor);
      attrset(COLOR_PAIR(3) | A_REVERSE | A_BOLD);

      if (wybor == 1) {
        stan = STAN_MINIGRY;
        // set our "choice" number to 12 (used to be 11)
        wybor = 12;
        mvprintw(10, 40, "Wybrana opcja: Minigra");
        clrtoeol();
        refresh();
        mvprintw(12, 3, "To play, choose a game below");
        mvprintw(14, 3, "Quessing Game");
        mvprintw(15, 3, "Throw a Dice");
        mvprintw(16, 3, "Tic Tac Toe!");
        clrtoeol();

        // Remove the selection arrow from the main menu
        menu_remove_strzala();

        // Add the selection arrow to the submenu
        mvprintw(MINIGRY_MENU_START, 20, STRZALA);
        mvchgat(MINIGRY_MENU_START, 20, -1, A_BOLD, 1, NULL);
      } else if (wybor == 12 && stan == STAN_MINIGRY) {
        mvprintw(12, 3, "Quessing Game");
        clrtoeol();

        // End ncurses (so things like cout work)
        endwin();

        system("clear");
        zgadywanie();

        // Restart ncurses
        initscr();
      } else if (wybor == 13 && stan == STAN_MINIGRY) {
        mvprintw(12, 3, "Throw a Dice");
        clrtoeol();
        endwin();
        system("clear");
        dice();
        initscr();
      } else if (wybor == 14 && stan == STAN_MINIGRY) {
        mvprintw(12, 3, "Tic Tac Toe!");
        clrtoeol();
        endwin();
        system("clear");
        tic_tack();
        initscr();
      } else if (wybor == 2) {
        stan = STAN_PRZYBORNIK;
        wybor = 12;

        mvprintw(10, 40, "Selected option: ToolBox");
        clrtoeol();
        refresh();
        mvprintw(12, 3, "Your list:");
        clrtoeol();
        mvprintw(14, 3, "Calculator");
        clrtoeol();
        mvprintw(15, 3, "Notepad*");
        clrtoeol();
        mvprintw(16, 3, "The Weather");
        clrtoeol();

        // Remove the selection arrow from the main menu
        menu_remove_strzala();

        // Add the selection arrow to the submenu
        mvprintw(PRZYBORNIK_MENU_START, 20, STRZALA);
        mvchgat(PRZYBORNIK_MENU_START, 20, -1, A_BOLD, 1, NULL);
      } else if (wybor == 12 && stan == STAN_PRZYBORNIK) {
        mvprintw(12, 3, "Last open: calculator");
        clrtoeol();
        // End ncurses (so things like cout work)
        endwin();
        system("clear");

        calculator(argc, argv);
        // Restart ncurses
        initscr();
      } else if (wybor == 13 && stan == STAN_PRZYBORNIK) {
        mvprintw(12, 3, "Last open: Notepad*");
        clrtoeol();
        // End ncurses (so things like cout work)
        endwin();
        system("clear");

        notepad();
        // Restart ncurses
        initscr();
      } else if (wybor == 14 && stan == STAN_PRZYBORNIK) {
        mvprintw(12, 3, "Last open: The Weather");
        clrtoeol();
        endwin();
        system("clear");
        the_weather();
        initscr();
      } else if (wybor == 3) {
        stan = STAN_DANE;
        wybor = 12;

        mvprintw(10, 40, "Selected option: Data");
        clrtoeol();
        refresh();
        mvprintw(12, 3, "Your list:");
        clrtoeol();
        mvprintw(14, 3, "Information");
        clrtoeol();
        mvprintw(15, 3, "Credits");
        clrtoeol();

        // Remove the selection arrow from the main menu
        menu_remove_strzala();

        // Add the selection arrow to the submenu
        mvprintw(DANE_MENU_START, 20, STRZALA);
        mvchgat(DANE_MENU_START, 20, -1, A_BOLD, 1, NULL);
      } else if (wybor == 12 && stan == STAN_DANE) {
        mvprintw(12, 3, "Last option: Information");
        clrtoeol();
        stop = clock();
        czas = (double)(stop - start) / CLOCKS_PER_SEC;
        mvprintw(25, 3, "Session Time: %f", czas);
        std::vector<std::string> datauser;
        load_userdata(datauser);
        mvprintw(16, 3, "Your Credentials");
        mvprintw(18, 3, "Login: %s", datauser[0].c_str());
        mvprintw(19, 3, "E-mail: %s", datauser[2].c_str());
        mvprintw(20, 3, "Name: %s", datauser[3].c_str());
        mvprintw(21, 3, "Surname: %s", datauser[4].c_str());
        mvprintw(22, 3, "Index number: %s", datauser[5].c_str());
        mvprintw(23, 3, "Date of birth: %s", datauser[6].c_str());

        /*
        endwin();
        system("clear");

        credits();
        // Restart ncurses
        initscr();
        */
      } else if (wybor == 13 && stan == STAN_DANE) {
        mvprintw(12, 3, "Last option: Credits");
        clrtoeol();
        // End ncurses (so things like cout work)
        endwin();
        system("clear");

        credits();
        // Restart ncurses
        initscr();
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

// Remove the selection arrow from the main menu
void menu_remove_strzala() {
  move(3, 25);
  clrtoeol();
  move(4, 25);
  clrtoeol();
  move(5, 25);
  clrtoeol();
  refresh();
}

// Remove the selection arrow from the "minigry" submenu
void minigry_reset_strzala() {
  // From menu start to menu end, clear to end of line
  for (int i = 0; i < MINIGRY_MENU_LEN; i++) {
    move(MINIGRY_MENU_START + i, 20);
    clrtoeol();
  }
  refresh();
}

// Remove the selection arrow from the "przybornik" submenu
void przybornik_reset_strzala() {
  // From menu start to menu end, clear to end of line
  for (int i = 0; i < PRZYBORNIK_MENU_LEN; i++) {
    move(PRZYBORNIK_MENU_START + i, 20);
    clrtoeol();
  }
  refresh();
}
void dane_reset_strzala() {
  // From menu start to menu end, clear to end of line
  for (int i = 0; i < DANE_MENU_LEN; i++) {
    move(DANE_MENU_START + i, 20);
    clrtoeol();
  }
  refresh();
}
// Clear the entire "submenu" area (all text and menus)
void clear_submenu_area() {
  for (int i = 0; i + 10 < LINES - 1; i++) {
    move(i + 10, 0);
    clrtoeol();
  }
}
