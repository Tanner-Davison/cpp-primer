#include "Screen.hpp"

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
