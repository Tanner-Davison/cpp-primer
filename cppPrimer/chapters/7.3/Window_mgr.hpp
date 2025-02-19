#pragma once
#include "Screen.hpp"
#include <iostream>
#include <vector>

class Window_mgr {
public:
  using ScreenIndex = std::vector<Screen>::size_type;
  Window_mgr() = default;

  void clear(ScreenIndex i);

private:
  std::vector<Screen> screens{Screen(24, 80, ' ')};
};
