#pragma once

class Tracker {
public:
  Tracker();
  Tracker(int);
  int get_id() const;
  static void increment_counter();

private:
  static int curr_num;
  static int counter;
  int id;
};
