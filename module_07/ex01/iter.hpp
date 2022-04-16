/**
 * @file iter.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Template function iter
 * @date 2022-04-17
 */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <class T>
void printT(T elem) {
  std::cout << elem << '\n';
}

template <class T>
void iter(T* arr, size_t len, void (*f)(T)) {
  for (size_t i = 0; i < len; i++) f(arr[i]);
}

#endif
