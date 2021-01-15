#include <ncurses.h>
 
#include <unistd.h>
#define START_LINIA 2
#define MAX 7 
#define INFOKOLUMNA 15
#define INFOWIERSZ START_LINIA+MAX+3
#define STRZALA "<<---"
#define ENTER 0xa /*w ncurses można również użyć KEY_ENTER*/
int main() {
  int klawisz, wybor=1;
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  noecho();
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_BLACK);
  clear();
  move(1, 1);
  printw("MENU");
  attrset(COLOR_PAIR(2));
  mvprintw(START_LINIA+1, 3, "Wybor 1");
  mvprintw(START_LINIA+2, 3, "Wybor 2");
  mvprintw(START_LINIA+3, 3, "Wybor 3");
  mvprintw(START_LINIA+4, 3, "Wybor 4");
  mvprintw(START_LINIA+5, 3, "Wybor 5");
  mvprintw(START_LINIA+6, 3, "Wybor 6");
  mvprintw(START_LINIA+7, 3, "Wybor 7");
  refresh();
  attroff(COLOR_PAIR(2));
  attrset(COLOR_PAIR(1) | A_BOLD);
  mvprintw((START_LINIA+1), 15, STRZALA);
  klawisz = getch();
#ifdef BEEP
  beep();
#endif
  while ((klawisz != 'q') && (klawisz != ERR) ) {
    move(INFOWIERSZ, INFOKOLUMNA);
    clrtoeol();
    mvprintw(INFOWIERSZ,INFOKOLUMNA, "Klawisz %d -- 0%o -- 0x%x -- %c", klawisz, klawisz, klawisz, klawisz);
    switch (klawisz) {
      case KEY_UP:
        if (wybor == 1) {
          klawisz = getch();
#ifdef BEEP
          beep();
#endif
          continue;
        }
        --wybor;
        move((START_LINIA+wybor+1), 15);
        clrtoeol();
        mvprintw((START_LINIA+wybor), 15, STRZALA);
        break;
      case KEY_DOWN:
        if (wybor == MAX) {
          klawisz = getch();
#ifdef BEEP
          beep();
#endif
          continue;
        }
        ++wybor;
        move((START_LINIA+wybor-1), 15);
        clrtoeol();
        mvprintw((START_LINIA+wybor), 15, STRZALA);
        break;
      case KEY_HOME:
        if (wybor == 1) {
          klawisz = getch();
#ifdef BEEP
          beep();
#endif
          continue;
        }
        move((START_LINIA+wybor), 15);
        clrtoeol();
        wybor = 1;
        mvprintw((START_LINIA+1), 15, STRZALA);
        break;
      case KEY_END:
        if (wybor == MAX) {
          klawisz = getch();
#ifdef BEEP
          beep();
#endif
          continue;
        }
        move((START_LINIA+wybor), 15);
        clrtoeol();
        wybor = MAX;
        mvprintw((START_LINIA+MAX), 15, STRZALA);
        break;
      case ENTER:
        move(LINES-1, 1);
        clrtoeol();
        mvprintw(LINES-1, 1, "Zatwierdzono: %d", wybor);
        refresh();
        break;
      default: 
        klawisz = getch(); 
#ifdef BEEP
        beep();
#endif
        continue;
        break;
    }
    refresh();
    usleep(50000);
    klawisz = getch();
#ifdef BEEP
    beep();
#endif
  }
  endwin();
  
}
