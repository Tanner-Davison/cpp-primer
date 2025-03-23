#include <forward_list>
#include <iostream>
#include <list>
#include <vector>

// My result for quiz 9.3.4 / #9.28 page 352
void find_insert_string(std::forward_list<std::string> &flist,
                        const std::string &str1, const std::string &str2) {
  auto prev = flist.before_begin();
  auto curr = flist.begin();

  while (curr != flist.end()) {
    if (*curr == str1) {
      flist.insert_after(curr, str2);
      return;
    }
    prev = curr;
    ++curr;
  }

  flist.insert_after(prev, str2);
}

int main() {
  int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> ivec;
  std::list<int> ilist;
  for (int i = 0; i < 11; ++i) {
    ivec.push_back(ia[i]);
    ilist.push_back(ia[i]);
  }
  auto vecIt = ivec.begin();
  auto listIt = ilist.begin();
  while (vecIt != ivec.end()) {
    if (*vecIt % 2) {
      vecIt = ivec.erase(vecIt);
    } else {
      ++vecIt;
    }
  }
  while (listIt != ilist.end()) {
    if (*listIt % 2 == 0) {
      listIt = ilist.erase(listIt);
      ++listIt;
    } else {
      ++listIt;
    }
  }

  std::cout << "Evens: ";
  for (const auto &num : ivec) {
    std::cout << num << ",";
  }
  std::cout << std::endl;
  std::cout << "Odds: ";
  for (const auto &num : ilist) {
    std::cout << num << ",";
  }
  std::cout << std::endl;
  std::forward_list<int> flist = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto prev = flist.before_begin();
  auto curr = flist.begin();
  while (curr != flist.end()) {
    if (*curr % 2 == 0) {
      curr = flist.erase_after(prev);
    } else {
      prev = curr;
      ++curr;
    }
  }
  std::cout << "\nForward List: ";
  for (const auto &num : flist) {
    std::cout << num << ", ";
  }
  std::cout << std::endl;
  std::list<int> my_strings{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  auto erased = std::erase_if(my_strings, [](int num) { return num % 2; });

  std::cout << erased << " numbers removed from (erase_if)" << std::endl;

  // 9.2.8
  std::forward_list<std::string> strList = {"Alpha", "Bravo", "Charlie"};
  std::string find_this = "Charlie";
  std::string replace_with = "Delta";
  find_insert_string(strList, find_this, replace_with);
  std::cout << "Forward list function: " << std::endl;
  for (const auto &str : strList) {
    std::cout << str << ", ";
  }
  std::cout << std::endl;
  return 0;
}
