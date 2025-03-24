#pragma once
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Date {
private:
  unsigned int month;
  unsigned int day;
  unsigned int year;

  static std::unordered_map<std::string, unsigned int> monthMap;

  static std::unordered_map<std::string, unsigned int> initMonthMap() {
    std::unordered_map<std::string, unsigned int> m;
    m["january"] = m["jan"] = 1;
    m["february"] = m["feb"] = 2;
    m["march"] = m["mar"] = 3;
    m["april"] = m["apr"] = 4;
    m["may"] = 5;
    m["june"] = m["jun"] = 6;
    m["july"] = m["jul"] = 7;
    m["august"] = m["aug"] = 8;
    m["september"] = m["sep"] = 9;
    m["october"] = m["oct"] = 10;
    m["november"] = m["nov"] = 11;
    m["december"] = m["dec"] = 12;
    return m;
  };
  std::string toLower(const std::string &str);
  std::vector<unsigned int> extractNumbers(const std::string &str);
  std::string extractMonthName(const std::string &str);

public:
  Date(std::string date);
  void display() const;
  unsigned int getDay() const { return day; }
  unsigned int getMonth() const { return month; }
  unsigned int getYear() const { return year; }
};
