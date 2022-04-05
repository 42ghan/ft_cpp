/**
 * @file Fixed.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions of fixed point class
 * @date 2022-03-03
 */

#include "Fixed.hpp"

// default constructor
Fixed::Fixed(void) : value_(0) {}

// int constructor
Fixed::Fixed(const int value) {
  int new_value = value;

  for (int i = 0; i < fractional_bits_; i++) {
    new_value *= 2;
  }
  setRawBits(new_value);
}

// float constructor
Fixed::Fixed(const float value) {
  float new_value = value;

  for (int i = 0; i < fractional_bits_; i++) {
    new_value *= 2;
  }
  setRawBits((int)roundf(new_value));
}

// copy constructor
Fixed::Fixed(const Fixed& original) { *this = original; }

// destructor
Fixed::~Fixed(void) {}

// assignment operation
Fixed& Fixed::operator=(const Fixed& rhs) {
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

// less than operation overload
bool Fixed::operator<(const Fixed& rhs) const {
  return getRawBits() < rhs.getRawBits();
}

// greater than operation overload
bool Fixed::operator>(const Fixed& rhs) const {
  return getRawBits() > rhs.getRawBits();
}

// less than or equal operation overload
bool Fixed::operator<=(const Fixed& rhs) const {
  return getRawBits() <= rhs.getRawBits();
}

// greater than or equal operation overload
bool Fixed::operator>=(const Fixed& rhs) const {
  return getRawBits() >= rhs.getRawBits();
}

// equl to operation overload
bool Fixed::operator==(const Fixed& rhs) const {
  return getRawBits() == rhs.getRawBits();
}

// not equl to operation overload
bool Fixed::operator!=(const Fixed& rhs) const {
  return getRawBits() != rhs.getRawBits();
}

// addition operation overload
Fixed Fixed::operator+(const Fixed& rhs) const {
  Fixed ret;

  ret.setRawBits(getRawBits() + rhs.getRawBits());
  return ret;
}

// subtraction operation overload
Fixed Fixed::operator-(const Fixed& rhs) const {
  Fixed ret;

  ret.setRawBits(getRawBits() - rhs.getRawBits());
  return ret;
}

// multiplication operation overload
Fixed Fixed::operator*(const Fixed& rhs) const {
  Fixed ret;

  ret.setRawBits(getRawBits() * rhs.getRawBits() / 256);
  return ret;
}

// division operation overload
Fixed Fixed::operator/(const Fixed& rhs) const {
  Fixed ret;

  ret.setRawBits(getRawBits() * 256 / rhs.getRawBits());
  return ret;
}

// prefix increment operation overload
Fixed& Fixed::operator++(void) {
  int prev = getRawBits();

  setRawBits(++prev);
  return *this;
}

// postfix increment operation overload
Fixed Fixed::operator++(int) {
  Fixed old = *this;

  operator++();
  return old;
}

// prefix decrement operation overload
Fixed& Fixed::operator--(void) {
  int prev = getRawBits();

  setRawBits(--prev);
  return *this;
}

// postfix decrement operation overload
Fixed Fixed::operator--(int) {
  Fixed old = *this;

  operator--();
  return old;
}

// min or max
Fixed& Fixed::min(Fixed& lhs, Fixed& rhs) {
  if (lhs <= rhs) return lhs;
  return rhs;
}

const Fixed& Fixed::min(const Fixed& lhs, const Fixed& rhs) {
  if (lhs <= rhs) return lhs;
  return rhs;
}

Fixed& Fixed::max(Fixed& lhs, Fixed& rhs) {
  if (lhs >= rhs) return lhs;
  return rhs;
}

const Fixed& Fixed::max(const Fixed& lhs, const Fixed& rhs) {
  if (lhs >= rhs) return lhs;
  return rhs;
}
