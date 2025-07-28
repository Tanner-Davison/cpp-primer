#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <vector>

int main() {
  std::ostream_iterator<std::string> display(std::cout, "\n");
  std::ostream_iterator<int> print_iset(std::cout, " ");
  std::ostream_iterator<int> print_mset(std::cout, " ");
  std::vector<int> ivec;
  for (std::vector<int>::size_type i = 0; i != 10; ++i) {
    ivec.push_back(i);
    ivec.push_back(i);
  }
  std::set<int> iset(ivec.cbegin(), ivec.cend());
  std::multiset<int> mset(ivec.cbegin(), ivec.cend());

  display = "\niset: ";
  for (const int &num : iset) {
    print_iset = num;
  }
  std::cout << std::endl;
  display = "\nmset: ";
  for (const int &num : mset) {
    print_mset = num;
  }

  std::cout << "\n" << std::endl;
  std::cout << "ivec size: " << ivec.size() << std::endl;
  std::cout << "iset size: " << iset.size() << std::endl;
  std::cout << "mset size: " << mset.size() << std::endl;

  return 0;
}
