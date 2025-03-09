#include <array>
#include <iostream>
#include <list>
#include <typeinfo>
#include <vector>

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
  return 0;
}
