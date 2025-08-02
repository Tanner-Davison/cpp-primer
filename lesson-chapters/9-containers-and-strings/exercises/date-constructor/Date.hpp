#pragma once
#include <iostream>
#include <string>

class Date {
private:
    int year;
    int month;
    int day;

public:
    // Constructors
    Date() : year(1900), month(1), day(1) {}
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    
    // Member functions
    void setYear(int y) { year = y; }
    void setMonth(int m) { month = m; }
    void setDay(int d) { day = d; }
    
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
    
    // Utility functions
    bool isValid() const;
    std::string toString() const;
    
    // Friend functions for I/O
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
    friend std::istream& operator>>(std::istream& is, Date& date);
};

// Forward declarations
std::ostream& operator<<(std::ostream& os, const Date& date);
std::istream& operator>>(std::istream& is, Date& date); 