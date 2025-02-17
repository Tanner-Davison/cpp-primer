#include "Screen.hpp"
#include <conio.h> // for _kbhit and _getch
#include <iostream>
#include <thread> // for sleep
#include <windows.h>

using pos = std::string::size_type;

bool handle_input(Screen &screen) {
  if (_kbhit()) {
    char ch = _getch();
    if (ch == 'q' || ch == 'Q') {
      return false;
    } else {
      screen.update_active_chars(ch);
    }
  }
  return true;
}

int main() {
  pos max_height = 10;
  pos max_width = 35;
  char character = '.';
  Screen myScreen(max_height, max_width, character);

  while (true) {
    system("cls");
    // Reset screen to dots
    myScreen.reset(character);
    // Check for new char input
    if (!handle_input(myScreen)) {
      break;
    };
    // Update and display all active characters
    myScreen.update_and_display();
    // Osstream specifier
    myScreen.display(std::cout);
    myScreen.move_left();
    // control loop *false for no looping
    myScreen.set_looping(true);
    // frame timing
    std::this_thread::sleep_for(std::chrono::milliseconds(120));
  }
  return 0;
}
