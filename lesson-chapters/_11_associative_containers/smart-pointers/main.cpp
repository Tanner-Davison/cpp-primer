#include "StrBlob.hpp"
#include <iostream>

int *create_int(const int num) {
  int *nInt = new int(num);
  return nInt;
}

void create_better_int(const int num) {
  int *temp_num = new int(num);
  std::cout << *temp_num << std::endl;
  delete temp_num;
}

int main() {
  StrBlob blob({"sarah", "jackie", "bob"});
  StrBlob blob2 = blob;

  // int* p1 = new int;    // default-initialized (garbage)
  int *p2 = new int(); // value-initialized to 0
  int *p3 = new int{}; // value-initialized to 0

  auto pi = create_int(34);
  std::cout << "Factory-created int: " << *pi << std::endl;

  std::cout << "Better factory int: ";
  create_better_int(1999);

  // std::cout << *p1 << "\n";  // Would produce garbage
  std::cout << "p2: " << *p2 << "\n";
  std::cout << "p3: " << *p3 << "\n";

  if (!blob.empty()) {
    std::cout << "\nFront element: " << blob.front() << std::endl;
    std::cout << "Ref count [blob]: " << blob.use_count() << std::endl;
    std::cout << "Ref count [blob2]: " << blob2.use_count() << std::endl;
  } else {
    std::cout << "blob is empty" << std::endl;
  }

  delete pi;
  pi = nullptr;
  std::cout << "pi after deletion: " << pi << std::endl;

  delete p2;
  delete p3;

  return 0;
}
