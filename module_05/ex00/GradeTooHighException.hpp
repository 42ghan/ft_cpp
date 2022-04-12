#ifndef GRADETOOHIGHEXCEPTION_HPP
#define GRADETOOHIGHEXCEPTION_HPP

#include <exception>

class GradeTooHighException : public std::exception {
  virtual const char* what(void) const throw();
};

#endif
