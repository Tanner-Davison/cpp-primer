#pragma once
#include <iostream>

class Person {
public:
  std::string name;
  std::string address;
  Person(std::string nameP, std::string addressP)
      : name(nameP), address(addressP) {};
  const std::string &get_name() const { return name; }
  const std::string &get_address() const { return address; }
  void set_name(std::string new_name) { this->name = new_name; }
  void set_address(std::string new_address) { this->address = new_address; }
  std::istream &read_person(std::istream &is, Person &personP) {
    is >> personP.name >> personP.address;
    return is;
  }
  std::ostream &print_person(std::ostream &os, Person personP) {
    os << "Name: " << personP.name << " Address: " << personP.address;
    return os;
  }
};
