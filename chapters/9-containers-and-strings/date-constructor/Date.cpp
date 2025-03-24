#include "Date.hpp"

std::unordered_map<std::string, unsigned int> Date::monthMap =
    Date::initMonthMap();

Date::Date(std::string date) {
  day = 1;
  month = 1;
  year = 1900;
  // extract all numbers
  std::vector<unsigned int> numbers = extractNumbers(date);
  std::string monthName = extractMonthName(date);
  monthName = toLower(monthName);

  if (!monthName.empty() && monthMap.find(monthName) != monthMap.end()) {
    month = monthMap.at(monthName);
    if (numbers.size() >= 1)
      day = numbers[0];
    if (numbers.size() >= 2)
      year = numbers[1];
  } else if (numbers.size() >= 3) {
    if (numbers[0] >= 1000) {
      // year-month-day format
      year = numbers[0];
      month = numbers[1];
      day = numbers[2];
    } else {
      // month-day-year format
      month = numbers[0];
      day = numbers[1];
      year = numbers[2];
    }
    if (month > 12) {
      std::swap(month, day);
    }
  }
  if (month < 1 || month > 12)
    month = 1;
  if (day < 1 || day > 31)
    day = 1;
};
void Date::display() const {
  std::cout << month << "/" << day << "/" << year << std::endl;
}

std::string Date::toLower(const std::string &str) {
  std::string result = str;
  std::transform(result.begin(), result.end(), result.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return result;
}
std::vector<unsigned int> Date::extractNumbers(const std::string &str) {
  std::vector<unsigned int> numbers;
  std::size_t start = 0;
  while (start < str.length()) {
    std::size_t pos = str.find_first_of("0123456789", start);
    if (pos == std::string::npos)
      break;

    std::size_t end = str.find_first_not_of("0123456789", pos);
    if (end == std::string::npos)
      end = str.length();

    std::string numStr = str.substr(pos, end - pos);
    numbers.push_back(std::stoul(numStr));

    // Make sure we always advance, even if end == start
    start = (end > start) ? end : start + 1;
  }
  return numbers;
}
std::string Date::extractMonthName(const std::string &str) {
  std::size_t pos = str.find_first_not_of("0123456789,/. ");
  if (pos == std::string::npos) {
    return "";
  }
  std::size_t end = str.find_first_of("0123456789,/. ", pos);
  if (end == std::string::npos) {
    end = str.length();
  }
  return str.substr(pos, end - pos);
};
