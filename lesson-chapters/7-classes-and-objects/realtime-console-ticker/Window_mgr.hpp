#pragma once
#include "Screen.hpp"
#include <iostream>
#include <vector>

class Window_mgr {
public:
  using ScreenIndex = std::vector<Screen>::size_type;
  Window_mgr();

  void clear(ScreenIndex i);
  ScreenIndex addScreen(const Screen &);

private:
  std::vector<Screen> screens;
};
