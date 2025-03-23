#include "Person.hpp"

Person::Person(std::string nameP, std::string addressP)
    : name(nameP), address(addressP) {}
Person::Person(const Person &) = default;

const std::string &Person::get_name() const { return name; }

const std::string &Person::get_address() const { return address; }

void Person::set_name(std::string new_name) { this->name = new_name; }

void Person::set_address(std::string new_address) {
  this->address = new_address;
}

Person &Person::add(Person &other) {
  name += (" " + other.name);
  address += (" " + other.address);
  return *this;
}

std::istream &read_person(std::istream &is, Person &person) {
  is >> person.name;
  std::getline(is >> std::ws, person.address); // std::ws essentially ignores
  return is; // trailing whitespace before address
}

std::ostream &print_person(std::ostream &os, const Person &personP) {
  os << "Name: " << personP.name << "\nAddress: " << personP.address;
  return os;
}
