/**
 * @file Dog.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions for member functions of Dog class
 * @date 2022-04-07
 */

#include "Dog.hpp"

// default constructor
Dog::Dog(void) {
  type_ = "Dog";
  std::cout << L_GREEN << "Default constructor (Dog)\n" << RESET;
}

// destructor
Dog::~Dog(void) {
  std::cout << L_RED << "An instance of Dog class is destroyed\n" << RESET;
}

// copy constructor
Dog::Dog(const Dog& original) {
  *this = original;
  std::cout << L_GREEN << "Copy constructor (Dog)\n" << RESET;
}

// = operator overload
Dog& Dog::operator=(const Dog& rhs) {
  type_ = rhs.type_;
  return *this;
}

// make sound override
void Dog::makeSound(void) const { std::cout << "Woof Woof!\n"; }
