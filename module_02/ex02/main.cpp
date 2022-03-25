/**
 * @file main.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Fixed point class advanced
 * @date 2022-03-03
 */

#include "Fixed.hpp"

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));
  Fixed const c(2.5f);
  Fixed const d(2);

  std::cout << "\n==INITIAL VALUES==\n";
  std::cout << "a is " << a << std::endl;
  std::cout << "b is " << b << std::endl;
  std::cout << "c is " << c << std::endl;
  std::cout << "d is " << d << std::endl;

  std::cout << "\n==COMPARISON==\n";
  std::cout << "a < b : " << (a < b) << std::endl;
  std::cout << "a > b : " << (a > b) << std::endl;
  std::cout << "a <= b : " << (a <= b) << std::endl;
  std::cout << "a >= b : " << (a >= b) << std::endl;

  std::cout << "\n==ARITHMETIC==\n";
  std::cout << "c + d : " << c + d << std::endl;
  std::cout << "c - d : " << c - d << std::endl;
  std::cout << "c * d : " << c * d << std::endl;
  std::cout << "c / d : " << c / d << std::endl;

  std::cout << "\n==INCREMENT==\n";
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;

  std::cout << "\n==DECREMENT==\n";
  std::cout << a << std::endl;
  std::cout << --a << std::endl;
  std::cout << a << std::endl;
  std::cout << a-- << std::endl;
  std::cout << a << std::endl;

  std::cout << "\n==MIN/MAX==\n";
  std::cout << b << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;
  std::cout << Fixed::min(c, d) << std::endl;

  return 0;
}
