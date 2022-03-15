/**
 * @file Fixed.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions of fixed point class
 * @date 2022-03-03
 */

#include "Fixed.hpp"

const int Fixed::fractional_bit_ = 8;

// default constructor
Fixed::Fixed(void) : fixed_pt_(0) {
  std::cout << "Default constructor called\n";
}

// destructor
Fixed::~Fixed(void) { std::cout << "Destructor called\n"; }

// copy constructor
Fixed::Fixed(const Fixed& original) {
  std::cout << "Copy constructor called\n";
  *this = original;
  fixed_pt_ = original.getRawBits();
}

// assignment operation
Fixed& Fixed::operator=(const Fixed& rhs) {
  fixed_pt_ = rhs.fixed_pt_;
  std::cout << "Assignment operator called\n";
  return *this;
}

// returns the raw value of the fixed point value
int Fixed::getRawBits(void) const {
  std::cout << "getRawbits member function called\n";
  return this->fixed_pt_;
}

// sets the raw value of the fixed point value
void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called\n";
  fixed_pt_ = raw;
}
