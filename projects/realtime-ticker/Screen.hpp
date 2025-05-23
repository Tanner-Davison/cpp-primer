#pragma once
#include <iostream>
#include <vector>
// forward declartion
// class Window_mgr;

struct CharPosition {
  using pos = std::string::size_type;
  char ch;
  pos position;
};
class Window_mgr;
class Screen {
public:
  // friend class Window_mgr;
  friend Window_mgr;
  friend std::ostream &storeOn(std::ostream &, Screen &);
  friend CharPosition;
  using pos = std::string::size_type;
  std::vector<CharPosition> active_chars;
  // Constructors
  Screen() = default;
  Screen(const Screen &) = default;
  Screen(pos ht, pos wd, char ch);
  Screen(pos ht, pos wd);

  // Member functions
  char get() const;
  void some_member() const;
  void set_looping(bool do_loop);
  Screen &move(pos r, pos c);
  void update_and_display();
  bool handle_input();

  inline char get(pos ht, pos wd) const;
  inline Screen &display(std::ostream &os);
  inline const Screen &display(std::ostream &os) const;
  inline void update_active_chars(char ch);
  inline void move_left();
  inline void reset(const char &character);

  // Private Member Functions
private:
  inline Screen &set(char);
  inline Screen &set(pos, pos, char);
  inline pos get_width() const;
  inline pos get_height() const;

  void do_display(std::ostream &os) const {
    for (pos row = 0; row < height; ++row) {
      pos row_start = row * width;
      os.write(&contents[row_start], width);
      os << "\n";
    }
  }
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
}
// overloaded set
inline Screen &Screen::set(pos row, pos col, char ch) {
  contents[row * width + col] = ch;
  return *this;
}
// get width
inline std::string::size_type Screen::get_width() const { return width; }
// get height
inline std::string::size_type Screen::get_height() const { return height; }
// display
inline Screen &Screen::display(std::ostream &os) {
  do_display(os);
  return *this;
}
// const display
inline const Screen &Screen::display(std::ostream &os) const {
  do_display(os);
  return *this;
}
// update active_chars
inline void Screen::update_active_chars(char ch) {
  active_chars.push_back({ch, ((height * width) - 1)});
}
// move left
inline void Screen::move_left() {
  for (auto &char_pos : active_chars) {
    char_pos.position -= 1;
  }
}
// Reset
inline void Screen::reset(const char &character) {
  for (pos i = 0; i < height; i++) {
    for (pos j = 0; j < width; j++) {
      set(i, j, character);
    }
  }
}
// extern functions
extern std::ostream &storeOn(std::ostream &, Screen &);
