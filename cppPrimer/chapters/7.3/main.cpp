#include "Screen.hpp"
#include <conio.h>
#include <iostream>
#include <thread> // for sleep

#include <windows.h>

using pos = std::string::size_type;

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
    if (!myScreen.handle_input()) {
      break;
    };
    // Update and display all active characters
    myScreen.update_and_display();
    // Osstream specifier
    myScreen.display(std::cout);
    myScreen.move_left();

    // dictates character loop true for infinite repeating
    myScreen.set_looping(true);
    // frame timing
    std::this_thread::sleep_for(std::chrono::milliseconds(120));
  }
  return 0;
}
