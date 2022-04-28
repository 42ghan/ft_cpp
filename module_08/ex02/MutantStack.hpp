/**
 * @file MutantStack.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A header file for MutantStack class
 * @date 2022-04-19
 */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <iterator>
#include <stack>
#include <vector>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  typedef typename std::stack<T>::container_type::iterator iterator;
  typedef typename std::stack<T>::container_type::const_iterator const_iterator;
  MutantStack(void);
  ~MutantStack(void);
  MutantStack(const MutantStack&);

  MutantStack& operator=(const MutantStack&);

  iterator begin(void);
  iterator end(void);
  iterator rbegin(void);
  iterator rend(void);

  const_iterator begin(void) const;
  const_iterator end(void) const;
  const_iterator rbegin(void) const;
  const_iterator rend(void) const;
};

// default constructor
template <typename T>
MutantStack<T>::MutantStack(void) {}

// destructor
template <typename T>
MutantStack<T>::~MutantStack(void) {}

// copy constructor
template <typename T>
MutantStack<T>::MutantStack(const MutantStack& original) {
  *this = original;
}

// = operator overload
template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& rhs) {
  std::stack<T>::c = rhs.c;
  return *this;
}

// iterators
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void) {
  return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void) {
  return std::stack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::rbegin(void) {
  return std::stack<T>::c.rbegin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::rend(void) {
  return std::stack<T>::c.rend();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin(void) const {
  return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end(void) const {
  return std::stack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::rbegin(void) const {
  return std::stack<T>::c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::rend(void) const {
  return std::stack<T>::c.rend();
}

#endif
