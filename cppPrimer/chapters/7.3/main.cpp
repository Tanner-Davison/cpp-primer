#include "Screen.hpp"
#include <algorithm> // for remove_if
#include <conio.h>   // for _kbhit and _getch
#include <iostream>
#include <thread>  // for sleep
#include <utility> // for pair
#include <vector>
#include <windows.h>

using pos = std::string::size_type;

struct CharPosition {
  char ch;
  pos position;
};

int main() {
  pos max_height = 10;
  pos max_width = 35;
  std::vector<CharPosition> active_chars;

  Screen myScreen(max_height, max_width, '.');

  while (true) {
    system("cls");

    // Reset screen to dots
    for (pos i = 0; i < max_height; i++) {
      for (pos j = 0; j < max_width; j++) {
        myScreen.set(i, j, '.');
      }
    }

    // Check for new char input
    if (_kbhit()) {
      char ch = _getch();
      if (ch == 'q' || ch == 'Q') {
        break;
      } else {
        // Add new character at start position (bottom right corner)
        active_chars.push_back(
            {ch, (max_height - 1) * max_width + (max_width - 1)});
      }
    }
    // Update and display all active characters
    for (auto &char_pos : active_chars) {
      if (char_pos.position < max_height * max_width) {
        pos row = char_pos.position / max_width;
        pos col = char_pos.position % max_width;
        myScreen.set(row, col, char_pos.ch);
      }
    }
    myScreen.display(std::cout);
    // Move all characters -   subtract 1 to move left
    for (auto &char_pos : active_chars) {
      char_pos.position -= 1;
    }
    // Remove characters that have moved off screen
    active_chars.erase(
        std::remove_if(active_chars.begin(), active_chars.end(),
                       [max_height, max_width](const CharPosition &cp) {
                         return cp.position >= max_height * max_width;
                       }),
        active_chars.end());

    std::this_thread::sleep_for(std::chrono::milliseconds(120));
  }
  return 0;
}
