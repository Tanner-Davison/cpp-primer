// example of custom overloaded  literals
#include <iostream>
struct Duration {
  int seconds;
  Duration(int s) : seconds(s) {}
  Duration operator+(const Duration &other) {
    return Duration(seconds + other.seconds);
  }
};
constexpr Duration operator""_seconds(unsigned long long s) {
  return Duration(s);
}

constexpr Duration operator""_minutes(unsigned long long m) {
  return Duration(m * 60);
}

int main() {
  auto total = 0_seconds + 525600_minutes;               // minutes in a year
  std::cout << total.seconds << " seconds" << std::endl; // 31,536,000
}
