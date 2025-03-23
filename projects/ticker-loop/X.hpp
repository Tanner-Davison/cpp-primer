#pragma once

class Y;

class X {
public:
  friend Y;
  Y *yptr;
};
