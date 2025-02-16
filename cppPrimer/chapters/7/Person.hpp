#pragma once
#include <iostream>
#include <string>

class Person {
  std::string name;
  std::string address;

public:
  Person() = default;
  Person(std::string nameP, std::string addressP)
      : name(nameP), address(addressP) {};

  const std::string &get_name() const { return name; }
  const std::string &get_address() const { return address; }
  void set_name(std::string new_name) { this->name = new_name; }
  void set_address(std::string new_address) { this->address = new_address; }
  Person &add(Person &other) {
    name += (" " + other.name);
    address += (" " + other.address);
    return *this;
  }
  friend std::istream &read_person(std::istream &is, Person &person) {
    is >> person.name;
    std::getline(is >> std::ws, person.address);
    return is;
  }
  friend std::ostream &print_person(std::ostream &os, const Person &personP);
};

inline std::ostream &print_person(std::ostream &os, const Person &personP) {
  os << "Name: " << personP.name << "\nAddress: " << personP.address;
  return os;
}
