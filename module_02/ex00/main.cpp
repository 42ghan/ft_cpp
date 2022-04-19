/**
 * @file main.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Fixed point class basic canonical form test
 * @date 2022-03-03
 */

#include "Fixed.hpp"

int main(void) {
  Fixed a;
  Fixed b(a);
  Fixed c;

  c = b;
  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;

  return 0;
}
