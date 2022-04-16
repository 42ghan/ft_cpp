/**
 * @file whatever.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Test template functions
 * @date 2022-04-16
 */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <class T>
void swap(T &a, T &b) {
  T tmp;

  tmp = a;
  a = b;
  b = tmp;
}

template <class T>
T min(T a, T b) {
  return a < b ? a : b;
}

template <class T>
T max(T a, T b) {
  return a > b ? a : b;
}

#endif
