#include <ncurses.h> /* ncurses.h includes stdio.h */
#include <string.h>

int main() {
  char mesg[] = "TODO: "; /* message to be appeared on the screen */
  char str[80];

  initscr(); /* start the curses mode */
  noecho();  /* Turn off echo mode*/

  int ch = getch();

  if (ch == 105) {
    printw("Hello, World\n");
    getch();
  } else {
    printw("Hello");
    getch();
  }
  refresh();
  getch();
  endwin();

  return 0;
}
