#include <iostream>

inline void clearScreen() {
#ifdef _WIN32
  std::system("cls");
#else
  system("clear");
#endif
}
