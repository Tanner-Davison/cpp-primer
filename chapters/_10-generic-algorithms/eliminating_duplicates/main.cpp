#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

//-------Deleting Duplicate Strings
void elim_dups(std::vector<std::string> &strs) {
  std::sort(strs.begin(), strs.end());
  auto end_unique = std::unique(strs.begin(), strs.end());
  strs.erase(end_unique, strs.end());
}
//---------------------------
//----Deleting Duplicate Numbers
void elim_num_dups(std::vector<int> &nums) {
  std::sort(begin(nums), end(nums));
  auto end_unique_nums = std::unique(begin(nums), end(nums));
  nums.erase(end_unique_nums, nums.end());
}
//------------------------
int main() {
  //--------Strings
  std::vector<std::string> str_vec{"Sally", "Sally", "Tom",  "Tanner",
                                   "Roger", "Jared", "Jared"};
  elim_dups(str_vec);
  for (const auto &word : str_vec) {
    std::cout << word << ", ";
  }
  std::cout << std::endl;

  //---------Numbers
  std::vector<int> num_vec{1, 2, 3, 4, 5, 6, 6, 6, 7, 8, 8, 9, 10, 10};
  elim_num_dups(num_vec);
  for (const auto num : num_vec) {
    std::cout << num << ", ";
  }
  std::cout << std::endl;
}
