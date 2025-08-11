#include <iostream>
#include <vector>

std::vector<int> *create_vec(const std::vector<int>::size_type &size) {
  std::vector<int> *rVec = new std::vector<int>(size);
  return rVec;
}

std::vector<int> *create_vec() {
  std::vector<int> *rVec = new std::vector<int>();
  return rVec;
}
void set_vec(std::vector<int> *pvec) {
  int val;
  std::vector<int>::size_type limit = pvec->size();
  if (limit == 0) {
    while (std::cin >> val && val != 0) {
      pvec->push_back(val);
    }
  } else {

    for (std::vector<int>::size_type i = 0; i < limit; ++i) {
      std::cin >> val;
      std::cin.ignore();
      if (val) {
        (*pvec)[i] = val;
      } else {
        std::cout << " please enter a valid value!" << std::endl;
        --i;
      }
    }
  }
}

void read_vec(std::vector<int> *pvec) {
  for (const auto num : *pvec) {
    std::cout << num << ", ";
  }
  std::cout << std::endl;
}
int main() {
  std::vector<int> *dyn_vec(create_vec(4));
  std::vector<int>::size_type SIZE = dyn_vec->size();
  bool has_size = SIZE > 0;
  if (!has_size) {
    std::cout << "Please Enter Numbers [Enter 0 to end]" << std::endl;
  } else {
    std::cout << "Please Enter: " << SIZE << " numbers." << std::endl;
  }
  set_vec(dyn_vec);
  read_vec(dyn_vec);
  delete dyn_vec;
  return 0;
}
