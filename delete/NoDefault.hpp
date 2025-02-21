#pragma once

class Tracker {
public:
  Tracker();
  Tracker(int);
  int get_id() const;

private:
  static int curr_num;
  int id;
};
