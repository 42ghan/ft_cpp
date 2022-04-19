/**
 * @file Point.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief
 * @date 2022-04-05
 */

#include "Point.hpp"

// default constructor
Point::Point(void) : x_(Fixed(0)), y_(Fixed(0)) {}

// constructor (initialize x & y)
Point::Point(const float a, const float b) : x_(Fixed(a)), y_(Fixed(b)) {}

// Copy constructor
Point::Point(const Point& orig)
    : x_(Fixed(orig.getX())), y_(Fixed(orig.getY())) {}

// destructor
Point::~Point(void) {}

// Copy assignment operator overload
Point& Point::operator=(const Point& rhs) {
  (void)rhs;
  return *this;
}

// subtraction operator
Point Point::operator-(const Point& rhs) const {
  return Point((getX() - rhs.getX()).toFloat(),
               (getY() - rhs.getY()).toFloat());
}

// getters & setters
Fixed Point::getX(void) const { return x_; }

Fixed Point::getY(void) const { return y_; }
