#pragma once

class Debug {
public:
  constexpr Debug() : hw(false), io(false), other(false) {};
  constexpr Debug(bool hwp, bool iop, bool otherp)
      : hw(hwp), io(iop), other(otherp) {};
  constexpr Debug(bool h) : hw(h), io(false), other(false) {};
  constexpr Debug(bool h, bool i) : hw(h), io(i), other(false) {};

  constexpr bool any() const { return hw || io || other; }
  void set_io(bool i) { io = i; }
  void set_hw(bool h) { hw = h; }
  void set_other(bool o) { hw = o; }

private:
  bool hw, io, other;
};
