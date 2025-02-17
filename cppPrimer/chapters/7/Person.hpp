#pragma once
#include <iostream>
#include <string>

class Person {
private:
  std::string name;
  std::string address;

public:
  // constructors
  Person() = default;
  Person(const Person &);
  Person(std::string nameP, std::string addressP);

  // member functions
  const std::string &get_name() const;
  const std::string &get_address() const;
  void set_name(std::string new_name);
  void set_address(std::string new_address);
  Person &add(Person &other);

  // friend functions
  friend std::istream &read_person(std::istream &is, Person &person);
  friend std::ostream &print_person(std::ostream &os, const Person &personP);
};

// Forward declarations
std::istream &read_person(std::istream &is, Person &person);
std::ostream &print_person(std::ostream &os, const Person &personP);
