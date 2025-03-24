#include <iostream>
#include <queue>

int main() {
  std::priority_queue<std::string> strQue;
  for (size_t i = 0; i < 10; ++i) {
    int count = i;
    strQue.emplace("String " + std::to_string(++count));
  }
  while (!strQue.empty()) {
    std::cout << strQue.top() << ", ";
    strQue.pop();
  }
  if (strQue.empty()) {
    std::cout << "\nqueue is empty." << std::endl;
  }
  return 0;
}
