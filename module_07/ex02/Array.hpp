/**
 * @file Array.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Template class Array
 * @date 2022-04-18
 */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <exception>
#include <limits>

template <class T>
class Array {
 private:
  T* array_;
  unsigned int size_;

  class IndexOutOfBound : public std::exception {
    virtual const char* what(void) const throw() {
      return "The given index is out of bound!";
    }
  };

 public:
  Array(void);
  Array(const unsigned int);
  ~Array(void);
  Array(const Array&);

  Array& operator=(const Array&);

  T& operator[](const long);
  T operator[](const long) const;

  unsigned int size(void) const;
  T* getArray(void) const;
};

// default constructor
template <class T>
Array<T>::Array(void) : array_(new T[0]), size_(0) {}

// constructor with a given size
template <class T>
Array<T>::Array(const unsigned int n) : array_(new T[n]), size_(n) {}

// destructor
template <class T>
Array<T>::~Array(void) {
  delete[] array_;
}

// copy constructor
template <class T>
Array<T>::Array(const Array<T>& original) : array_(NULL) {
  *this = original;
}

// = operator overload
template <class T>
Array<T>& Array<T>::operator=(const Array<T>& rhs) {
  T* rhs_array = rhs.getArray();

  delete[] array_;
  array_ = new T[rhs.size()];
  for (unsigned int i = 0; i < rhs.size(); i++) array_[i] = rhs_array[i];
  size_ = rhs.size();
  return *this;
}

// [] operator overload
template <class T>
T& Array<T>::operator[](const long idx) {
  if (idx < 0 || idx >= (long)std::numeric_limits<unsigned int>::max() ||
      (unsigned int)(idx + 1) > size_)
    throw IndexOutOfBound();
  return *(array_ + idx);
}

template <class T>
T Array<T>::operator[](const long idx) const {
  if (idx < 0 || idx >= (long)std::numeric_limits<unsigned int>::max() ||
      (unsigned int)(idx + 1) > size_)
    throw IndexOutOfBound();
  return *(array_ + idx);
}

// get size of the array
template <class T>
unsigned int Array<T>::size(void) const {
  return size_;
}

// get starting pointer of array
template <class T>
T* Array<T>::getArray(void) const {
  return array_;
}

#endif
