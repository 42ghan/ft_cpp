/**
 * @file AMateria.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief
 * @date 2022-04-08
 */

#include "AMateria.hpp"

// default constructor
AMateria::AMateria(void) {
  std::cout << L_GREEN << "Default constructor (AMateria)\n" << RESET;
}

// destructor
AMateria::~AMateria(void) {
  std::cout << L_RED << "An instance of AMateria class has been destroyed\n"
            << RESET;
}

// constructor with a given type
AMateria::AMateria(const std::string& type) : type_(type) {
  std::cout << L_GREEN << type << " AMateria has been constructed\n" << RESET;
}

// copy constructor
AMateria::AMateria(const AMateria& original) {
  *this = original;
  std::cout << L_GREEN << "Copy constructor (AMateria)\n" << RESET;
}

// = operator overload
AMateria& AMateria::operator=(const AMateria& rhs) {
  type_ = rhs.getType();
  return *this;
}

// getter & setter
const std::string& AMateria::getType(void) const { return type_; }

void AMateria::setType(cosnt std::string& new_type) { type_ = new_type; }
