// Copyright (c) 2025 Tanner Davison. All rights reserved

//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  * of this software and associated documentation files (the "Software"), to
//  deal * in the Software without restriction, including without limitation the
//  rights * to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell * copies of the Software, and to permit persons to whom the
//  Software is * furnished to do so, subject to the following conditions: * * -
//  This copyright notice and permission notice shall be included in all *
//  copies or substantial portions of the Software. * * THE SOFTWARE IS PROVIDED
//  "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR * IMPLIED, INCLUDING BUT
//  NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, * FITNESS FOR A PARTICULAR
//  PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE * AUTHORS OR COPYRIGHT
//  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER * LIABILITY, WHETHER IN AN
//  ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, * OUT OF OR IN
//  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN * THE SOFTWARE.

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
// included subjects

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return (a - b); }
int multiply(int a, int b) { return (a * b); }

int calculate(int a, int b, int (*operation)(int, int)) {
  return operation(a, b);
}
// see chapters/7
int (*getOperation(char op))(int, int) {
  switch (op) {
  case '+':
    return &add;
  case '-':
    return &subtract;
  case '*':
    return &multiply;
  default:
    return nullptr;
  }
}

bool (*pf)(int &num, int &num2) = [](int &num, int &num2) {
  return num == num2;
};

bool isLarger(std::string &str1, std::string &str2) {
  return str1.size() > str2.size();
}

bool (*strBool)(const std::string &, const std::string &);

std::string lengthCompare(std::string &str, std::string &str2) {
  return str.size() > str2.size() ? str : str2;
}

std::string concatStrings(std::string &str1, std::string &str2,
                          bool (*pf)(std::string &, std::string &)) {

  return pf(str1, str2) ? (str1 += str2) : str2 += str1;
}

std::string concatStrings(std::string &str1, std::string &str2) {
  return (str1 += str2);
}
int testme(int num) { return (num * 3); }
std::string (*strPf)(std::string &str1, std::string &str2);

int main() {
  int (*func_ptr)(int, int) = getOperation('+');
  int sum = func_ptr(5, 3);
  int testNum = 24;
  int (*ptrtest)(int num) = testme;
  std::cout << ptrtest(testNum);
  std::cout << "\nSum: of 5 + 3 = " << sum << std::endl;
  int num1 = 100;
  int num2 = 100;
  bool result = pf(num1, num2);
  if (result) {
    std::cout << "They are equal" << std::endl;
  }
  std::string name = "Tanner";
  std::string name2 = "Davison";
  strPf = lengthCompare;
  std::string strResult = strPf(name, name2);
  std::cout << strResult << std::endl;
  strPf = concatStrings;
  std::string concatted = strPf(name, name2);
  std::string names = "Longer";
  std::string names2 = "shorterer";
  std::string concattedWithBool = concatStrings(names, names2, isLarger);
  std::cout << concattedWithBool << std::endl;
  std::transform(concatted.begin(), concatted.end(), concatted.begin(),
                 ::toupper);
  std::cout << concatted << std::endl;

  ;
  return 0;
}
