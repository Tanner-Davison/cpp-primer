#pragma once
#include <iostream>
class Tracker {
private:
  static Tracker *mem2;
  Tracker(int sec_key);

public:
  static Tracker mem;
  Tracker();
  static Tracker *get_tracker_ptr();
  static Tracker &get_local_tracker();
  static void destroy();
  int get_id() const;
  static void increment_counter();

private:
  static int ptr_count;
  static int local_count;
  static int counter;
  static constexpr int constant_int = 50;
  int key;
  int id;
};
