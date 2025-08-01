#include "Date.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    std::cout << "=== Date Constructor Exercise ===\n\n";

    // 1. Create a vector of dates
    std::vector<Date> dates;
    
    // Add some dates
    dates.push_back(Date(2024, 1, 15));
    dates.push_back(Date(2023, 12, 25));
    dates.push_back(Date(2024, 2, 29));  // Leap year
    dates.push_back(Date(2023, 6, 10));
    dates.push_back(Date(2024, 3, 1));

    std::cout << "1. Original dates:\n";
    for (const auto& date : dates) {
        std::cout << "   " << date << (date.isValid() ? " (valid)" : " (invalid)") << std::endl;
    }
    std::cout << "\n";

    // 2. Sort dates (they will be sorted by year, then month, then day)
    std::sort(dates.begin(), dates.end(), 
              [](const Date& a, const Date& b) {
                  if (a.getYear() != b.getYear()) return a.getYear() < b.getYear();
                  if (a.getMonth() != b.getMonth()) return a.getMonth() < b.getMonth();
                  return a.getDay() < b.getDay();
              });

    std::cout << "2. Sorted dates:\n";
    for (const auto& date : dates) {
        std::cout << "   " << date << std::endl;
    }
    std::cout << "\n";

    // 3. Find dates in a specific year
    int target_year = 2024;
    auto it = std::find_if(dates.begin(), dates.end(),
                           [target_year](const Date& date) {
                               return date.getYear() == target_year;
                           });

    std::cout << "3. Dates in " << target_year << ":\n";
    while (it != dates.end()) {
        std::cout << "   " << *it << std::endl;
        it = std::find_if(++it, dates.end(),
                          [target_year](const Date& date) {
                              return date.getYear() == target_year;
                          });
    }
    std::cout << "\n";

    // 4. Count leap year dates
    int leap_year_count = std::count_if(dates.begin(), dates.end(),
                                        [](const Date& date) {
                                            int year = date.getYear();
                                            return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
                                        });

    std::cout << "4. Leap year dates found: " << leap_year_count << std::endl;

    // 5. Input validation example
    std::cout << "\n5. Date input validation:\n";
    std::cout << "   Enter a date (YYYY-MM-DD): ";
    
    Date input_date;
    if (std::cin >> input_date) {
        if (input_date.isValid()) {
            std::cout << "   Valid date: " << input_date << std::endl;
        } else {
            std::cout << "   Invalid date: " << input_date << std::endl;
        }
    } else {
        std::cout << "   Invalid input format\n";
    }

    return 0;
} 