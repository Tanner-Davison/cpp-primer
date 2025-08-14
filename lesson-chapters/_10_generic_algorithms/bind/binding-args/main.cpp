// Copyright (c) 2025 Tanner Davison. All Rights Reserved.
// implementation used in lambdas/lambda-dups-biggies
#include <algorithm>
#include <functional>
#include <ios>
#include <iostream>

using namespace std::placeholders;

bool check_size(const std::string& s, std::string::size_type sz) {
   return s.size() >= sz;
}

int main() {
   // auto newCallable = bind(callable, arg_list);
   auto check6 = bind(check_size, _1, 6);
   auto str    = "Hello";

   bool b1 = check6(str);
   std::cout << "Hello is greater than 6 chars?" << std::boolalpha << b1 << std::endl;

   return 0;
}
