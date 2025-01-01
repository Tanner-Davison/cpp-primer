// FIND STRING HEADER
#pragma once
#include <string>

// using std::cout, std::endl, std::string;

std::string::size_type find_char(const std::string &s, char c,
                                 std::string::size_type &occurs);
