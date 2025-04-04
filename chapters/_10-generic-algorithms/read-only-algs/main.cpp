#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>
// accumulate <int>
// accumulate <string>
//
int main() {
  std::vector<int> nums{20, 32, 44, 55, 66};
  std::vector<int> nums_copy{20, 32, 44, 55, 66};
  std::vector<std::string> strs{"Hello ", "world ", ", ", " how are you ",
                                "today "};
  std::cout << std::accumulate(nums.begin(), nums.end(), 0) << std::endl;
  std::cout << std::accumulate(strs.cbegin(), strs.cend(), std::string(""));
  if (std::equal(nums.cbegin(), nums.cend(), nums_copy.begin())) {
    std::cout << "nums == nums_copy" << std::endl;
  } else {
    std::cout << "nums !== nums_copy"
  }
  return 0;
}
