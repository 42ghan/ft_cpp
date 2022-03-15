/**
 * @file Fixed.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief
 * @date 2022-03-03
 */

#include "Fixed.hpp"

const int Fixed::fractional_bit_ = 8;

// default constructor
Fixed::Fixed(void) : value_(0) {
  std::cout << "Default constructor called\n";
}

// const int parameter constructor
Fixed::Fixed(int const nbr) {
  std::cout << "Int constructor called\n";
  int int_value = nbr;
  value_ = int_value << 8;
}

// const float parameter constructor
Fixed::Fixed(float const nbr) {
  std::cout << "Float constructor called\n";
}

// destructor
Fixed::~Fixed(void) { std::cout << "Destructor called\n"; }

// copy constructor
Fixed::Fixed(const Fixed& original) {
  std::cout << "Copy constructor called\n";
  *this = original;
  value_ = original.getRawBits();
}

// assignment operation
Fixed& Fixed::operator=(const Fixed& rhs) {
  value_ = rhs.value_;
  std::cout << "Assignment operator called\n";
  return *this;
}

// returns the raw value_ of the fixed point value_
int Fixed::getRawBits(void) const {
  std::cout << "getRawbits member function called\n";
  return this->value_;
}

// sets the raw value_ of the fixed point value_
void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called\n";
  value_ = raw;
}
