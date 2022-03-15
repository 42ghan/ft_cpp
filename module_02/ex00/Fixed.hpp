/**
 * @file Fixed.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A header file for Fixed class
 * @date 2022-03-03
 */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
 private:
  int fixed_pt_;
  static const int fractional_bit_;

 public:
  // canonical form
  Fixed(void);
  ~Fixed(void);
  Fixed(const Fixed&);
  Fixed& operator=(const Fixed&);

  int getRawBits(void) const;
  void setRawBits(int const raw);
};

#endif