#include <iostream>
#include <string>
#include <vector>

void Foreach(std::vector<std::string> &strs, void(func)(const std::string &)) {
  for (const auto &s : strs) {
    func(s);
  }
}
int main() {
  std::vector<std::string> str_vec{"Susan", "Alan",  "Brad",   "Rebecca",
                                   "Troy",  "Roger", "Andrew", "Anthony"};

  auto lambda = [](const std::string &val) {
    std::cout << "Value: " << val << std::endl;
  };

  Foreach(str_vec, lambda);

  std::cout << std::endl;
  return 0;
}
