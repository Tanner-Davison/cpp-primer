#include <functional>
#include <iostream>
#include <vector>

using namespace std::placeholders;

bool check_size(std::string &s, std::string::size_type sz) {
  return s.size() <= sz;
};

int main() {
  std::string str{"Sally"};
  std::vector<int> lengths{3, 4, 6, 8};
  auto target =
      std::find_if(lengths.begin(), lengths.end(), bind(check_size, str, _1));
  if (target != lengths.end()) {
    std::cout << *target << " is greater than " << str << " = " << str.size()
              << std::endl;

  } else {
    std::cout << "No element found greater than " << str.size() << std::endl;
  }

  return 0;
}
