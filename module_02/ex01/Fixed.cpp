/**
 * @file Fixed.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions of fixed point class
 * @date 2022-03-03
 */

#include "Fixed.hpp"

// default constructor
Fixed::Fixed(void) : value_(0) { std::cout << "Default constructor called\n"; }

// int constructor
Fixed::Fixed(const int value) {
  int new_value = value;

  std::cout << "Int constructor called\n";
  for (int i = 0; i < fractional_bits_; i++) {
    new_value *= 2;
  }
  setRawBits(new_value);
}

// float constructor
Fixed::Fixed(const float value) {
  float new_value = value;

  std::cout << "Float constructor called\n";
  for (int i = 0; i < fractional_bits_; i++) {
    new_value *= 2;
  }
  setRawBits((int)roundf(new_value));
}

// copy constructor
Fixed::Fixed(const Fixed& original) {
  std::cout << "Copy constructor called\n";
  *this = original;
}

// destructor
Fixed::~Fixed(void) { std::cout << "Destructor called\n"; }

// assignment operation
Fixed& Fixed::operator=(const Fixed& rhs) {
  std::cout << "Copy assignment operator called\n";
  value_ = rhs.getRawBits();
  return *this;
}

// returns the raw value of the fixed point value
int Fixed::getRawBits(void) const { return value_; }

// sets the raw value of the fixed point value
void Fixed::setRawBits(int const raw) { value_ = raw; }

// converts the fixed point value to a floating point value
float Fixed::toFloat(void) const { return (float)getRawBits() / 256; }

// converts the fixed point value to an integer value
int Fixed::toInt(void) const { return (int)roundf(toFloat()); }

// insertion operation overload
std::ostream& operator<<(std::ostream& out, const Fixed& rhs) {
  out << rhs.toFloat();
  return out;
}