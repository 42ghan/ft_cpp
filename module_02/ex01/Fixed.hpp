/**
 * @file Fixed.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A header file for Fixed class
 * @date 2022-03-03
 */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
 private:
  int value_;
  static const int fractional_bits_ = 8;

 public:
  // canonical form
  Fixed(void);
  ~Fixed(void);
  Fixed(const Fixed&);
  Fixed& operator=(const Fixed&);

  Fixed(const int);
  Fixed(const float);

  float toFloat(void) const;
  int toInt(void) const;

  std::string& operator<<(const Fixed&);

  int getRawBits(void) const;
  void setRawBits(int const raw);
};

#endif