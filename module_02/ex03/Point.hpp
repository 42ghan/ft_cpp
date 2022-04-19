/**
 * @file Point.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Point class that represents a point in 2D space
 * @date 2022-04-05
 */

#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>
#include <iostream>

#include "Fixed.hpp"

class Point {
 private:
  const Fixed x_;
  const Fixed y_;

 public:
  Point(void);
  Point(const float, const float);
  Point(const Point&);
  ~Point(void);

  Point& operator=(const Point&);
  Point operator-(const Point& rhs) const;

  Fixed getX(void) const;
  Fixed getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
