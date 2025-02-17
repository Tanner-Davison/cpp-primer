#pragma once
#include <iostream>

class Screen {
public:
  using pos = std::string::size_type;
  // Constructors
  Screen() = default;
  Screen(pos ht, pos wd, char c);
  Screen(pos ht, pos wd);

  Screen(const Screen &) = default;

  // Member functions
  char get() const;
  Screen &move(pos r, pos c);
  void some_member() const;
  // Inline member functions
  inline char get(pos ht, pos wd) const;
  inline Screen &set(char);
  inline Screen &set(pos, pos, char);

private:
  mutable size_t access_ctr; // May change even a const object
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
};

// Inlined member functions
inline char Screen::get(pos r, pos c) const {
  pos row = r * width;
  return contents[row + c];
}
inline Screen &Screen::set(char c) {
  contents[cursor] = c;
  return *this;
};

inline Screen &Screen::set(pos r, pos col, char c) {
  contents[r * width + col] = c;
  return *this;
};
