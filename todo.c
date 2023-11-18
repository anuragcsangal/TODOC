#include <ncurses.h> /* ncurses.h includes stdio.h */
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

struct Todo {
  char statement[100];
  unsigned int completed;
};

void printTodo(struct Todo T) {
  mvprintw(0, 0, "You Entered: %s", &T.statement);
  mvprintw(0, 100, "%d\n", T.completed);
}

void addNewTodo(struct Todo T) {
  getstr(T.statement);
  T.completed = 0;
}

int main() {
  FILE *fp;
  fp = fopen("todo.txt", "w");

  initscr(); /* start the curses mode */
  noecho();  /* Turn off echo mode*/

  while (1) {
    clear();
    printw("Press 'i' to enter new todo");
    int ch = getch();

    if (ch == 105) {
      clear();
      mvprintw(LINES, 0, "INSERT");
      struct Todo todo;

      echo(); // Turn on echo mode so to get the todo statement and print it.
      char mesg[] = "TODO: "; /* message to be appeared on the screen */
      mvprintw(0, 0, "%s", mesg);
      getstr(todo.statement);
      todo.completed = 0;
      addNewTodo(todo);
      printTodo(todo);
      fprintf(fp, "%s", todo.statement);
      fclose(fp);
      refresh();
      getch();
    } else if (ch == 113) {
      break;
    }
  }
  endwin();
  return 0;
}
