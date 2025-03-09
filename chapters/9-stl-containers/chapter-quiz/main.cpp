#include <algorithm>
#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <typeinfo>
#include <vector>

bool num_compare(const std::vector<int> &vec, const std::list<int> &li) {
  auto beg = vec.begin();
  auto beglist = li.begin();
  bool allEqual = true;
  while (beg != vec.end() && beglist != li.end()) {
    if (*beg != *beglist) {
      allEqual = false;
      break;
    } else {
      ++beg;
      ++beglist;
    }
  }
  return allEqual;
}
int main() {
  // const Char * to " " literals adds a null terminating character at the end
  // \0;
  //
  //
  // example
  std::vector<const char *> cPtrs{"Tanner", "Andrew", "Nathan",
                                  "Nate",   "Eear",   "Rapper"};

  std::array<std::string, 10> my_strings{"hello", "world", "Tom",
                                         "Jerry", "are",   "you"};
  std::array<std::string, 10>::size_type i = my_strings.size();
  for (unsigned int x = 0; x < i; ++x) {
    std::cout << my_strings[x] << " ";
  }
  std::cout << typeid(std::array<std::string, 10>::value_type).name()
            << std::endl;
  ;
  std::cout << std::endl;
  // const char* examples
  for (auto &word : cPtrs) {
    for (int i = 0; word[i] != '\0'; ++i) {
      std::cout << word[i];
    }
    std::cout << std::endl;
  }

  // six ways to initialize a vector
  std::vector<int> vec1{1};
  std::vector<int> vec2 = vec1;
  std::vector<int> vec3(vec1);
  std::vector<int> vec4 = {01};
  std::vector<int> vec5(1, 1);
  std::vector<int> vec6(1);

  // How would you initialize a vector<double> from a list <int>?
  // From a vector<int>?
  //
  std::list<int> my_list{3, 4, 6};
  auto begin = my_list.begin();
  auto end = my_list.end();
  std::vector<double> my_dub_list(begin, end);

  for (auto &num : my_dub_list) {
    std::cout << num << ", ";
  }
  std::cout << std::endl;
  // Write a program to assign the elements from a list of char* pointers to
  // C-style character strings to a vector of strings
  std::list<const char *> charPtrs{"a", "b", "c", "d"};
  std::vector<std::string> stringVector;
  stringVector.assign(charPtrs.begin(), charPtrs.end());
  for (const auto &l : stringVector) {
    std::cout << l;
  }
  std::cout << std::endl;
  // Compare elements in a list<int> to elements in a vector<int>
  std::vector<int> nums{1, 2, 3, 4, 5, 6};
  std::list<int> numslist{1, 2, 3, 4, 5, 6};
  if (num_compare(nums, numslist)) {
    std::cout << "Elements of containers are of equal size" << std::endl;
  };
  // using insert
  auto numsbeg = nums.begin() + 1;
  auto bracedList = {9, 8, 7};
  nums.insert(numsbeg, bracedList);
  for (const auto &num : nums) {
    std::cout << num << ", ";
  }
  std::cout << std::endl;
  std::vector<std::string> insertTest;
  insertTest.insert(insertTest.begin(), my_strings.begin(), my_strings.end());
  auto iter = insertTest.begin();
  std::string word = "";
  while (std::cin >> word) {
    if (word == "quit") {
      break;
    }
    iter = insertTest.insert(iter, word);
  }
  std::sort(insertTest.begin(), insertTest.end());

  for (const auto &word : insertTest) {
    std::cout << word << ", ";
  }
  std::cout << std::endl;
  // Write a program to copy elements from a list<int> into two deques The
  // even-valued elements should go into one deque and the odd into another
  std::list<int> input_nums;
  std::deque<int> evens;
  std::deque<int> odds;
  int temp;
  while (std::cin >> temp) {
    if (temp == 0) {
      break;
    }
    if ((temp % 2) == 0) {
      evens.emplace_back(temp);
    } else {
      odds.emplace_back(temp);
    }
  }
  std::cout << "Evens: ";
  for (const auto &evenNum : evens) {
    std::cout << evenNum << ",";
  }
  std::cout << "\nOdds: ";
  for (const auto &oddNum : odds) {
    std::cout << oddNum << ",";
  }

  return 0;
}
