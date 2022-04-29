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

class NoOccurrenceException : public std::exception {
  const char* what(void) const throw() { return "No occurrence is found\n"; }
};

template <typename T>
typename T::iterator easyfind(T& container, int value) {
  typename T::iterator itr =
      std::find(container.begin(), container.end(), value);
  if (itr == container.end()) throw NoOccurrenceException();
  return itr;
}

#endif
