#include "Date.hpp"
#include <iomanip>
#include <sstream>

bool Date::isValid() const {
    if (year < 1900 || year > 2100) return false;
    if (month < 1 || month > 12) return false;
    
    // Days per month (non-leap year)
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Check for leap year
    if (month == 2) {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeap) daysInMonth[1] = 29;
    }
    
    return day >= 1 && day <= daysInMonth[month - 1];
}

std::string Date::toString() const {
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(4) << year << "-"
        << std::setw(2) << month << "-"
        << std::setw(2) << day;
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.toString();
    return os;
}

std::istream& operator>>(std::istream& is, Date& date) {
    int y, m, d;
    char dash1, dash2;
    
    if (is >> y >> dash1 >> m >> dash2 >> d) {
        if (dash1 == '-' && dash2 == '-') {
            date.setYear(y);
            date.setMonth(m);
            date.setDay(d);
        } else {
            is.setstate(std::ios::failbit);
        }
    }
    
    return is;
} 