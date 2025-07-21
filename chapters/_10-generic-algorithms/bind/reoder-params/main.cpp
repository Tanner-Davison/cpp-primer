// implementation used in lambdas/lambda-dups-biggies
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std::placeholders;

bool isShorter(std::string &str1, std::string &str2) {
  return str1.size() < str2.size();
}

int main() {

  std::vector<std::string> str_vec{"Sally", "Sarah",    "Joshua", "Tommy",
                                   "Jacob", "Lindsey",  "Andrew", "Robert",
                                   "Jake",  "Lancaster"};

  // regular sort shortest to longest
  std::cout << "Shortest to longest" << std::endl;

  std::sort(str_vec.begin(), str_vec.end(), isShorter);
  for (const auto &word : str_vec) {
    std::cout << word << ", ";
  }

  std::cout << std::endl;

  // Reversed the param order with bind
  std::cout << "Longest to shortest" << std::endl;

  std::sort(str_vec.begin(), str_vec.end(), bind(isShorter, _2, _1));

  for (const auto &word : str_vec) {
    std::cout << word << ", ";
  }
  std::cout << std::endl;
  return 0;
}
