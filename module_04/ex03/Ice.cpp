/**
 * @file Ice.cpp
 * @author your name (you@domain.com)
 * @brief
 * @date 2022-04-08
 */

#include "Ice.hpp"

// default constructor
Ice::Ice(void) {
  setType("ice");
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
Ice& Ice::operator=(const Ice& rhs) { return *this; }

// clone & use
Ice* Ice::clone(void) const { return new Ice(); }

void Ice::use(ICharacter& name) {
  std::cout << "* shoots an ice bolt at " << name << '\n';
}