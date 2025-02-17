#pragma once
#include <iostream>

class Screen {
public:
  using pos = std::string::size_type;
  // Constructors
  Screen() = default;
  Screen(const Screen &) = default;
  Screen(pos ht, pos wd, char ch);
  Screen(pos ht, pos wd);

  // Member functions
  char get() const;
  void some_member() const;
  Screen &move(pos r, pos c);

  // Inline member functions
  inline char get(pos ht, pos wd) const;
  inline Screen &set(char);
  inline Screen &set(pos, pos, char);
  inline pos get_width() const;
  inline pos get_height() const;
  inline Screen &display(std::ostream &os);
  inline const Screen &display(std::ostream &os) const;

  // Private Member Functions
private:
  void do_display(std::ostream &os) const {
    for (pos row = 0; row < height; ++row) {
      pos row_start = row * width;
      os.write(&contents[row_start], width);
      os << "\n";
    }
  };

  // private data members
private:
  mutable size_t access_ctr; // May change even a const object
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
};

// ###  CLASS END ###
// Inline member functions --------------------------------
//
inline char Screen::get(pos row_p, pos ch_p) const {
  pos row = row_p * width;
  return contents[row + ch_p];
}
// set
inline Screen &Screen::set(char ch) {
  contents[cursor] = ch;
  return *this;
};
// set
inline Screen &Screen::set(pos row, pos col, char ch) {
  contents[row * width + col] = ch;
  return *this;
};
// get width
inline std::string::size_type Screen::get_width() const { return width; };
// get height
inline std::string::size_type Screen::get_height() const { return height; };

// display
inline Screen &Screen::display(std::ostream &os) {
  do_display(os);
  return *this;
};
// const display
inline const Screen &Screen::display(std::ostream &os) const {
  do_display(os);
  return *this;
};
