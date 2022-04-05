/**
 * @file main.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief
 * @date 2022-03-26
 */

#include "Point.hpp"

int main(void) {
  Point a(1, 1);
  Point b(1, 3);
  Point c(3, 1);
  Point p(2, 1.2);
  if (bsp(a, b, c, p))
    std::cout << "The point is inside the triangle ABC\n";
  else
    std::cout << "The point is NOT inside the triangle ABC\n";
  return EXIT_SUCCESS;
}