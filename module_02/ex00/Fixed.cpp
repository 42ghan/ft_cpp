/**
 * @file Fixed.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions of fixed point class
 * @date 2022-03-03
 */

#include "Fixed.hpp"

// default constructor
Fixed::Fixed(void) : value_(0) { std::cout << "Default constructor called\n"; }

// destructor
Fixed::~Fixed(void) { std::cout << "Destructor called\n"; }

// copy constructor
Fixed::Fixed(const Fixed& original) {
  std::cout << "Copy constructor called\n";
  value_ = original.getRawBits();
}

// assignment operation
Fixed& Fixed::operator=(const Fixed& rhs) {
  std::cout << "Assignment operator called\n";
  value_ = rhs.getRawBits();
  return *this;
}

// returns the raw value of the fixed point value
int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called\n";
  return value_;
}

// sets the raw value of the fixed point value
void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called\n";
  value_ = raw;
}
