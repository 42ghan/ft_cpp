/**
 * @file Cure.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief
 * @date 2022-04-08
 */

#include "Cure.hpp"

// default constructor
Cure::Cure(void) {
  std::cout << L_GREEN << "Default constructor (Cure)\n" << RESET;
}

// destructor
Cure::~Cure(void) {
  std::cout << L_RED << "An instance of Cure Materia has been destroyed\n"
            << RESET;
}

// copy constructor
Cure::Cure(const Cure& original) {
  *this = original;
  std::cout << L_GREEN << "Copy constructor (Cure)\n" << RESET;
}

// = operator overload
Cure& Cure::operator=(const Cure& rhs) { return *this; }

// clone & use
Cure* Cure::clone(void) const { return new Cure(); }

void Cure::user(ICharacter& name) {
  std::cout << "* heals " << name << "'s wounds *\n";
}
