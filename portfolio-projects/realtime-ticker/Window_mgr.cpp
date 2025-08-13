#include "Window_mgr.hpp"
void Window_mgr::clear(ScreenIndex i) {
  // s is a reference to the screen we want to clear
  Screen &s = screens[i];

  s.contents = std::string(s.height * s.width, ' ');
};
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s) {
  screens.push_back(s);
  return screens.size() - 1;
}
