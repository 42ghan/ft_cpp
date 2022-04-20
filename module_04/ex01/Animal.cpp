/**
 * @file Animal.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions for member functions of Animal class
 * @date 2022-04-07
 */

#include "Animal.hpp"

// default constructor
Animal::Animal(void) : type_("Any") {
  std::cout << L_GREEN << "Default constructor (Animal)\n" << RESET;
}

// destructor
Animal::~Animal(void) {
  std::cout << L_RED << "An instance of Animal class is destroyed\n" << RESET;
}

// copy constructor
Animal::Animal(const Animal& original) {
  std::cout << L_GREEN << "Copy constructor (Animal)\n" << RESET;
  *this = original;
}

// = operator overload
Animal& Animal::operator=(const Animal& rhs) {
  type_ = rhs.type_;
  return *this;
}

// getter
std::string Animal::getType(void) const { return type_; }

// makeSound
void Animal::makeSound(void) const { std::cout << "Blah Blah\n"; }
