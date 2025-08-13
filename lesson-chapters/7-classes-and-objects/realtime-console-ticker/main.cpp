// this file is included in /projects as ticker-loop
#include "Screen.hpp"
#include <conio.h>
#include <iostream>
#include <thread> // for sleep

#include <windows.h>

void end_result(Screen &screen) {
  screen.reset(' ');
  screen.update_and_display();
  screen.display(std::cout);
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

int main() {
  Screen::pos max_height = 10, max_width = 35;

  char character = '.';
  Screen myScreen(max_height, max_width, character);

  while (true) {
    system("cls");
    // Reset screen to dots
    myScreen.reset(character);
    // Check for new char input
    if (!myScreen.handle_input()) {
      system("cls");
      end_result(myScreen);
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
