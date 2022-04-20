/**
 * @file WrongAnimal.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions for member functions of WrongAnimal class
 * @date 2022-04-07
 */

#include "WrongAnimal.hpp"

// default constructor
WrongAnimal::WrongAnimal(void) : type_("Any") {
  std::cout << L_GREEN << "Default constructor (WrongAnimal)\n" << RESET;
}

// destructor
WrongAnimal::~WrongAnimal(void) {
  std::cout << L_RED << "An instance of WrongAnimal class is destroyed\n"
            << RESET;
}

// copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& original) {
  std::cout << L_GREEN << "Copy constructor (WrongAnimal)\n" << RESET;
  *this = original;
}

// = operator overload
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
  type_ = rhs.type_;
  return *this;
}

// getter & setter
std::string WrongAnimal::getType(void) const { return type_; }

// makeSound
void WrongAnimal::makeSound(void) const { std::cout << "Lol Lol\n"; }
