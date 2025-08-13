#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

void read_vec(std::vector<int> &vec) {
  for (const auto &num : vec) {
    std::cout << num << ", ";
  }
  std::cout << std::endl;
}

int main() {
  // Fill example
  std::vector<int> my_ints(20);
  std::fill(my_ints.begin(), my_ints.end(), 1);
  std::cout << "std::fill(beg,end, fill_value)" << std::endl;
  read_vec(my_ints);

  // add to container using iota (increments like start_count++ until the
  // container reaches the end)
  std::vector<int> iota_ints(20);
  int start_count = 1;
  std::iota(iota_ints.begin(), iota_ints.end(), start_count);
  std::cout << "\nstd::iota(beg, end, start)" << std::endl;
  read_vec(iota_ints);

  // fill_n
  std::vector<int> fill_n_example{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::fill_n(fill_n_example.begin(), fill_n_example.size(), 0);
  std::cout << "\nstd::fill_n example:" << std::endl;
  read_vec(fill_n_example);

  // add using generate()
  std::vector<int> gen_nums(20);
  int gen_count = 0;
  std::cout << "\nstd::generate(beg, end, start count) (by 5's)" << std::endl;
  std::generate(begin(gen_nums), end(gen_nums),
                [&gen_count]() { return gen_count += 5; });
  read_vec(gen_nums);
  return 0;
}
