// console_utils.h
#ifndef CONSOLE_UTILS_H
#define CONSOLE_UTILS_H

#include <cstdlib>
#ifdef _WIN32
#include <conio.h>
#include <windows.h>

inline void clear_screen() {
   system("cls");
}

// Windows already has _kbhit() and _getch()

#else // Linux/Unix
#include <cstdio>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

inline void clear_screen() {
   system("clear");
}

inline int kbhit() {
   struct termios oldt, newt;
   int            ch;
   int            oldf;

   tcgetattr(STDIN_FILENO, &oldt);
   newt = oldt;
   newt.c_lflag &= ~(ICANON | ECHO);
   tcsetattr(STDIN_FILENO, TCSANOW, &newt);
   oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
   fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

   ch = getchar();

   tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
   fcntl(STDIN_FILENO, F_SETFL, oldf);

   if (ch != EOF) {
      ungetc(ch, stdin);
      return 1;
   }
   return 0;
}

inline int getch() {
   struct termios oldattr, newattr;
   int            ch;
   tcgetattr(STDIN_FILENO, &oldattr);
   newattr = oldattr;
   newattr.c_lflag &= ~(ICANON | ECHO);
   tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
   ch = getchar();
   tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
   return ch;
}

// Make it compatible with Windows naming
inline int _kbhit() {
   return kbhit();
}
inline int _getch() {
   return getch();
}
#endif

#endif // CONSOLE_UTILS_H
