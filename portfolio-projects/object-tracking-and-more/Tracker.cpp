#include "./Tracker.hpp"

// static definitions
int Tracker::ptr_count = 1;
int Tracker::counter = 1;
int Tracker::local_count = 1;
Tracker *Tracker::mem2 = nullptr;
Tracker Tracker::mem;
Tracker::Tracker() : id(counter++) {};
Tracker::Tracker(int sec_key) : id(sec_key) {
  // Singlton created
}
// static constexpr definitions
constexpr int Tracker::constant_int;

Tracker *Tracker::get_tracker_ptr() {
  if (!mem2) {
    mem2 = new Tracker(ptr_count++);
  }
  return mem2;
}
int Tracker::get_id() const { return id; };
Tracker &Tracker::get_local_tracker() {
  static Tracker mem;
  return mem;
}
void Tracker::destroy() {
  delete mem2;
  mem2 = nullptr;
};
