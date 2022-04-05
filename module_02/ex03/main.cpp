/**
 * @file main.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief
 * @date 2022-03-26
 */

#include "Point.hpp"

int main(void) {
  std::cout << "=======A (0, 0) / B (0, 3) / C (3, 0) / P (1.5, 1.5) =======\n";
  Point a(0, 0);
  Point b(0, 3);
  Point c(3, 0);
  Point p(1.5, 1.5);

  if (bsp(a, b, c, p))
    std::cout << "The point is inside the triangle ABC\n";
  else
    std::cout << "The point is NOT inside the triangle ABC\n";

  std::cout << "======= A (1.3, 1) / B (0.567, 3) / C (3, 0.23) / P (1.3, 1) "
               "=======\n";
  Point A(1.3, 1);
  Point B(0.567, 3);
  Point C(3, 0.23);
  Point P(1.3, 1);

  if (bsp(A, B, C, P))
    std::cout << "The point is inside the triangle ABC\n";
  else
    std::cout << "The point is NOT inside the triangle ABC\n";

  std::cout << "=======A (-1.23, -1.23) / B (1.23, -1.23) / C (0, 1.23) / P "
               "(0, 0) =======\n";
  Point AA(-1.23, -1.23);
  Point BB(1.23, -1.23);
  Point CC(0, 1.23);
  Point PP(0, 0);

  if (bsp(AA, BB, CC, PP))
    std::cout << "The point is inside the triangle ABC\n";
  else
    std::cout << "The point is NOT inside the triangle ABC\n";
  return EXIT_SUCCESS;
}
