#include "StrBlob.hpp"
#include <iostream>

int main() {
  StrBlob blob({"sarah", "jackie", "bob"});
  StrBlob blob2 = blob;
  if (!blob.empty()) {
    std::cout << "\nFront: " << blob.front();
    std::cout << "\nRef count[blob]: " << blob.use_count();
    std::cout << "\nRef count[blob2]: " << blob2.use_count() << std::endl;
  } else {
    std::cout << "blob is empty" << std::endl;
  }

  return 0;
}
