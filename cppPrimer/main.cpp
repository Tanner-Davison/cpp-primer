#include <array>
#include <cstddef>
#include <iostream>
#include <vector>

int (*func(int param1 = 10))[10] {
  static int arrP[10];
  if (param1 > 0) {
    for (int i = 1; i < 11; ++i) {
      arrP[i - 1] = i;
    }
    return &arrP;
  }
  return nullptr;
}
typedef std::string::size_type sz;

std::vector<int> *funcVec(sz arrSz = 10) {
  if (arrSz > 0) {
    static std::vector<int> arrPtr;
    for (sz i = 0; i < arrSz; ++i) {
      arrPtr.emplace_back(i);
    }
    return &arrPtr;
  }
  return {};
}
inline std::string &shorterString(std::string &one, std::string &two) {
  return one.size() < two.size() ? one : two;
}
inline std::vector<int> allInts;

constexpr int scale(std::string::size_type sz) { return 2 * sz; }
template <typename T, std::size_t X, std::size_t Y> struct Matrix {
  std::array<T, X * Y> mat{};

  // Multidimensional operator[] in C++23
  T &operator[](std::size_t x, std::size_t y) { return mat[y * X + x]; }

  // Const version for read-only access
  const T &operator[](std::size_t x, std::size_t y) const {
    return mat[y * X + x];
  }
};

int main() {

  std::cout << '\n';

  Matrix<int, 3, 3> mat;
  for (auto i : {0, 1, 2}) {
    for (auto j : {0, 1, 2})
      mat[i, j] = (i * 3) + j; // (2)
  }
  for (auto i : {0, 1, 2}) {
    for (auto j : {0, 1, 2}) {
      if (i == 1 && j == 0 || i == 2 && j == 0) {
        std::cout << "\n";
      }
      std::cout << " [" << i << "," << j << "]" << mat[i, j];
    }
  }

  std::cout << '\n';
  return 0;
}
