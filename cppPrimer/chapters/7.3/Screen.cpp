#include "Screen.hpp"
#include <algorithm> // for remove_if

// Constructors
Screen::Screen(pos ht, pos wd, char ch)
    : height(ht), width(wd), contents(ht * wd, ch) {};
Screen::Screen(pos ht, pos wd)
    : height(ht), width(wd), contents(ht * wd, ' ') {};

// Member functions
char Screen::get() const { return contents[cursor]; }
void Screen::some_member() const { ++access_ctr; };
Screen &Screen::move(pos r, pos c) {
  pos row = r * width;
  cursor = row + c;
  return *this;
};
void Screen::set_looping(bool do_loop) {
  if (!do_loop) {
    pos max_height = height;
    pos max_width = width;
    active_chars.erase(
        std::remove_if(active_chars.begin(), active_chars.end(),
                       [max_height, max_width](const CharPosition &cp) {
                         return cp.position >= max_height * max_width;
                       }),
        active_chars.end());

  } else {
    for (auto &char_pos : active_chars) {
      if (char_pos.position == 0) {
        char_pos.position = ((width * height) - 1);
      }
    }
  }
};
void Screen::update_and_display() {
  for (auto &char_pos : active_chars) {
    if (char_pos.position < height * width) {
      pos row = char_pos.position / width;
      pos col = char_pos.position % width;
      set(row, col, char_pos.ch);
    }
  }
};
