#pragma once
#include "Screen.hpp"
#include <iostream>
#include <vector>

class Window_mgr {
public:
  Window_mgr() = default;

private:
  std::vector<Screen> screens{Screen(24, 80, ' ')};
};
