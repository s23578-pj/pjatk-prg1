#include <ncurses.h>
void move_cursor(WINDOW *window) {
  int x = 0, y = 0;
  getyx(window, y, x);
  int key = 0;
  do {
    key = getch();
    switch (key) {
    case KEY_LEFT:
      x = (x + (COLS - 1)) % COLS;
      move(y, x);
      break;
    case KEY_RIGHT:
      x = (x + 1) % COLS;
      move(y, x);
      break;
    case KEY_UP:
      y = (y + (LINES - 1)) % LINES;
      move(y, x);
      break;
    case KEY_DOWN:
      y = (y + 1) % LINES;
      move(y, x);
      break;
    case KEY_F(3):
      getyx(window, y, x);
      printw("x: %d, y: %d", x, y);
      break;
    case KEY_F(2):
      y = x = 0;
      erase();
      break;
    }
    refresh();
  } while (key != 'q');
}
int main(void) {
  if (initscr() == NULL)
    return -1;
  if (keypad(stdscr, TRUE) == ERR)
    return -1;
  move_cursor(stdscr);
  if (endwin() == ERR)
    return -1;
  return 0;
}
