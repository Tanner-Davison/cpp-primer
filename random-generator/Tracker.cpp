#include "./Tracker.hpp"

// static definitions
int Tracker::curr_num = 1;
int Tracker::counter = 1;

// static constexpr definitions
constexpr int Tracker::constant_int;

// constructors
Tracker::Tracker() : id(this->curr_num) { ++curr_num; };
Tracker::Tracker(int numP) { curr_num += numP; };

// member functions
int Tracker::get_id() const { return this->id; };
void Tracker::increment_counter() { ++counter; };
