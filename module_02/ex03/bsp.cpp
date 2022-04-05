/**
 * @file bsp.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Binary space partitioning
 * @date 2022-04-05
 */

#include "Point.hpp"

Fixed crossProductZ(const Point& a, const Point& b) {
  return a.getX() * b.getY() - b.getX() * a.getY();
}

bool isSameSide(const Point& a, const Point& b, const Point& c,
                const Point& p) {
  if (crossProductZ(b - a, c - a) * crossProductZ(b - a, p - a) >
      Fixed())
    return true;
  return false;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  if (isSameSide(a, b, c, point) && isSameSide(b, c, a, point) &&
      isSameSide(c, a, b, point))
    return true;
  return false;
}
