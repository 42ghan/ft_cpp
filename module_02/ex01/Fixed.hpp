/**
 * @file Fixed.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A header file for Fixed class
 * @date 2022-03-03
 */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
 private:
  int value_;
  static const int fractional_bits_ = 8;

 public:
  // canonical form
  Fixed(void);
  Fixed(const int);
  Fixed(const float);
  Fixed(const Fixed&);
  ~Fixed(void);

  Fixed& operator=(const Fixed&);

  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;
};

std::ostream& operator<<(std::ostream&, const Fixed&);

#endif
