/**
 * @file Span.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A header file for Span class
 * @date 2022-04-18
 */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <vector>

class Span {
 private:
  std::vector<int> nums_vec_;
  unsigned int max_len_;

  class NoSpanException : public std::exception {
    virtual const char* what(void) const throw() {
      return "No span can be found!\n";
    }
  };

  class OverflowException : public std::exception {
    virtual const char* what(void) const throw() {
      return "Already reached max length!\n";
    }
  };

 public:
  Span(void);
  ~Span(void);
  Span(const unsigned int);
  Span(const Span&);

  Span& operator=(const Span&);

  std::vector<int> getNumsVector(void) const;
  unsigned int getMaxLength(void) const;
  unsigned int getLength(void) const;

  void addNumber(const int);
  int shortestSpan(void) const;
  int longestSpan(void) const;

  void fillNumbers(void);
};

#endif
