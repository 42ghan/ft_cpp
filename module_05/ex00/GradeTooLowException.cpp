#include "GradeTooLowException.hpp"

const char* GradeTooLowException::what(void) const throw() {
  return "This bureaucrat's grade is too low!\n";
}
