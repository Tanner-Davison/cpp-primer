#include "Screen.hpp"

// Constructors
Screen::Screen(pos ht, pos wd, char c)
    : height(ht), width(wd), contents(ht * wd, c) {};
Screen::Screen(pos ht, pos wd)
    : height(ht), width(wd), contents(ht * wd, ' ') {};

// Member functions
char Screen::get() const { return contents[cursor]; }

Screen &Screen::move(pos r, pos c) {
  pos row = r * width;
  cursor = row + c;
  return *this;
};

void Screen::some_member() const { ++access_ctr; };
