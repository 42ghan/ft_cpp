/**
 * @file Span.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions of member functions of Span class
 * @date 2022-04-18
 */

#include "Span.hpp"

#include <sys/time.h>

#include <limits>

// default constructor
Span::Span(void) : max_len_(0) {}

// destructor
Span::~Span(void) {}

// constructor with a given max length
Span::Span(const unsigned int max_len) : max_len_(max_len) {}

// copy constructor
Span::Span(const Span& original) { *this = original; }

// = operator overload
Span& Span::operator=(const Span& rhs) {
  nums_vec_ = rhs.nums_vec_;
  max_len_ = rhs.max_len_;
  return *this;
}

// getters
std::vector<int> Span::getNumsVector(void) const { return nums_vec_; }

unsigned int Span::getMaxLength(void) const { return max_len_; }

// add number
void Span::addNumber(const int new_num) {
  if (nums_vec_.size() >= max_len_) throw OverflowException();
  nums_vec_.push_back(new_num);
}

// get shortest or longest span
unsigned int Span::shortestSpan(void) const {
  if (nums_vec_.empty() || nums_vec_.size() == 1) throw NoSpanException();
  std::vector<int> tmp = nums_vec_;
  std::sort(tmp.begin(), tmp.end());
  int diff = std::numeric_limits<int>::max();
  int new_diff;
  for (std::vector<int>::const_iterator itr = tmp.begin(); itr != tmp.end();
       ++itr) {
    if (itr != tmp.end() - 1) new_diff = *(itr + 1) - *(itr);
    if (new_diff < diff) diff = new_diff;
  }
  return diff;
}

unsigned int Span::longestSpan(void) const {
  if (nums_vec_.empty() || nums_vec_.size() == 1) throw NoSpanException();
  std::vector<int>::const_iterator begin = nums_vec_.begin();
  std::vector<int>::const_iterator end = nums_vec_.end();
  return *(std::max_element(begin, end)) - *(std::min_element(begin, end));
}

// fill numbers at once
int randomNumber(void) {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  srand(tv.tv_usec);
  return rand();
}

void Span::fillNumbers(void) {
  nums_vec_.resize(max_len_ + 100);
  std::generate_n(nums_vec_.begin(), max_len_, randomNumber);
}
