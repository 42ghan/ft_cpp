/**
 * @file easyfind.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief easyfind function template that finds the first occurrence of the
 * second param in the first param
 * @date 2022-04-18
 */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
void checkFound(typename T::iterator itr, typename T::iterator end, int value) {
  if (itr != end)
    std::cout << "Found " << *itr << "!\n";
  else
    std::cout << "Cannot find " << value << " ...\n";
}

template <typename T>
typename T::iterator easyfind(T& container, int value) {
  typename T::iterator itr = container.begin();
  for (; itr != container.end(); ++itr)
    if (*itr == value) break;
  return itr;
}

#endif
