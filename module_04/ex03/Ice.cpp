/**
 * @file Ice.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief
 * @date 2022-04-08
 */

#include "Ice.hpp"

// default constructor
Ice::Ice(void) {
  type_ = "ice";
  std::cout << L_GREEN << "Default constructor (Ice)\n" << RESET;
}

// destructor
Ice::~Ice(void) {
  std::cout << L_RED << "An instance of Ice Materia has been destroyed\n"
            << RESET;
}

// copy constructor
Ice::Ice(const Ice& original) { *this = original; }

// = operator overload
Ice& Ice::operator=(const Ice& rhs) {
  (void)rhs;
  return *this;
}

// clone & use
Ice* Ice::clone(void) const { return new Ice(); }

void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << '\n';
}
