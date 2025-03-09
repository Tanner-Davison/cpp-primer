#include <ncurses.h>

int main() {
  // Initialize ncurses
  initscr();
  cbreak();              // Line buffering disabled
  noecho();              // Don't echo keypresses
  keypad(stdscr, TRUE);  // Enable function keys

  // Clear the screen and print message
  clear();
  mvprintw(5, 10, "Press any key to continue...");
  refresh();

  // This is the correct way to use getch() on Mac with ncurses
  int ch = getch();

  // Show what key was pressed
  mvprintw(7, 10, "You pressed: %c", ch);
  refresh();
  getch();

  // Clean up
  endwin();
  return 0;
}
