#include "./Tracker.hpp"

int Tracker::curr_num = 1;
int Tracker::counter = 1;
Tracker::Tracker() : id(this->curr_num) { ++curr_num; };
Tracker::Tracker(int numP) { curr_num += numP; };
int Tracker::get_id() const { return this->id; };
void Tracker::increment_counter() { ++counter; };
