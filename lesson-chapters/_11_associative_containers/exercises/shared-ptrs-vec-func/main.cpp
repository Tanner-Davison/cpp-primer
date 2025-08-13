#include <iostream>
#include <memory>
#include <vector>

std::shared_ptr<std::vector<int>>
create_vec(const std::vector<int>::size_type &size) {
  return std::make_shared<std::vector<int>>(std::vector<int>(size));
}

std::shared_ptr<std::vector<int>> create_vec() {
  std::shared_ptr<std::vector<int>> shared_vec_ref =
      std::make_shared<std::vector<int>>(std::vector<int>());
  return shared_vec_ref;
}
void set_vec(std::shared_ptr<std::vector<int>> &shared_vec_ref) {
  std::cout << "Ref count in set_vec: " << shared_vec_ref.use_count()
            << std::endl;
  int val;
  std::vector<int>::size_type limit = shared_vec_ref->size();
  if (limit == 0) {
    while (std::cin >> val && val != 0) {
      shared_vec_ref->push_back(val);
    }
  } else {

    for (std::vector<int>::size_type i = 0; i < limit; ++i) {
      std::cin >> val;
      std::cin.ignore();
      if (val) {
        (*shared_vec_ref)[i] = val;
      } else {
        std::cout << " please enter a valid value!" << std::endl;
        --i;
      }
    }
  }
}

void read_vec(std::shared_ptr<std::vector<int>> &shared_vec_ref) {

  std::cout << "Ref count in set_vec: " << shared_vec_ref.use_count()
            << std::endl;
  for (const auto num : *shared_vec_ref) {
    std::cout << num << ", ";
  }
  std::cout << std::endl;
}
int main() {
  std::shared_ptr<std::vector<int>> shared_vec = create_vec(3);

  std::vector<int>::size_type SIZE = shared_vec->size();
  bool has_size = SIZE > 0;
  if (!has_size) {
    std::cout << "Please Enter Numbers [Enter 0 to end]" << std::endl;
  } else {
    std::cout << "Please Enter: " << SIZE << " numbers." << std::endl;
  }
  set_vec(shared_vec);
  std::cout << "Ref count in shared_vec: " << shared_vec.use_count()
            << std::endl;
  read_vec(shared_vec);

  std::cout << "Ref count in shared_vec: " << shared_vec.use_count();
  return 0;
}
