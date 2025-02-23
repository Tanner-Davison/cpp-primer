#pragma once

class Tracker {
public:
  static Tracker mem;
  static Tracker *mem2;

  Tracker();
  // I can use the static member as a default argument
  Tracker(int = counter);

  int get_id() const;
  static void increment_counter();

private:
  static int curr_num;
  static int counter;
  static constexpr int constant_int = 50;
  int id;
};
