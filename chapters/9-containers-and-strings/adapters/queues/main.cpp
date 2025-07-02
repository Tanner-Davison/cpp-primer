#include <iostream>
#include <queue>

int main() {
  std::priority_queue<std::string> priority_str_que;
  for (size_t i = 0; i < 10; ++i) {
    int count = i;
    priority_str_que.emplace("String " + std::to_string(++count));
  }
  while (!priority_str_que.empty()) {
    std::cout << priority_str_que.top() << ", ";
    priority_str_que.pop();
  }
  if (priority_str_que.empty()) {
    std::cout << "\nqueue is empty." << std::endl;
  }
  return 0;
}
