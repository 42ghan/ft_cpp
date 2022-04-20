/**
 * @file WrongCat.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions for member functions of WrongCat class
 * @date 2022-04-07
 */

#include "WrongCat.hpp"

// default constructor
WrongCat::WrongCat(void) {
  type_ = "WrongCat";
  std::cout << L_GREEN << "Default constructor (WrongCat)\n" << RESET;
}

// destructor
WrongCat::~WrongCat(void) {
  std::cout << L_RED << "An instance of WrongCat class is destroyed\n" << RESET;
}

// copy constructor
WrongCat::WrongCat(const WrongCat& original) {
  *this = original;
  std::cout << L_GREEN << "Copy constructor (WrongCat)\n" << RESET;
}

// = operator overload
WrongCat& WrongCat::operator=(const WrongCat& rhs) {
  type_ = rhs.type_;
  return *this;
}

// make sound override
void WrongCat::makeSound(void) const { std::cout << "smh smh!\n"; }
