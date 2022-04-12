#ifndef GRADETOOLOWEXCEPTION_HPP
#define GRADETOOLOWEXCEPTION_HPP

#include <exception>

class GradeTooLowException : public std::exception {
  virtual const char* what(void) const throw();
};

#endif
