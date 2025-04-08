#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
int main() {
  std::vector<const char *> csty{"hello world", "how are you today"};
  std::vector<const char *> csty_cop{"hello world", "how are you today"};
  std::vector<int> nums{20, 32, 44, 55, 66};
  std::vector<int> nums_copy{20, 32, 44, 55, 66};

  std::vector<std::string> strs{"Hello ", "world ", ", ", " how are you ",
                                "today "};
  std::cout << "std::accumulate(nums) : --> "
            << std::accumulate(nums.begin(), nums.end(), 0) << std::endl;
  std::cout << "std::accumulate(strs) : --> "
            << std::accumulate(strs.cbegin(), strs.cend(), std::string(""))
            << std::endl;

  bool csty_compare = std::equal(csty.cbegin(), csty.cend(), csty_cop.cbegin());
  if (csty_compare) {
    std::cout << "\nstd::equal(const csty, const csty_cop)csty == csty_cop"
              << std::endl;
  } else {
    std::cout << "\nstd::equal(const csty, const csty_cop)csty !== csty_cop"
              << std::endl;
  }
  if (std::equal(nums.cbegin(), nums.cend(), nums_copy.begin())) {
    std::cout << "std::equal(nums ,nums_copy) : --> nums == nums_copy"
              << std::endl;
  } else {
    std::cout << "std::equal(nums, nums_copy) : --> nums !== nums_copy"
              << std::endl;
  }
  return 0;
}
