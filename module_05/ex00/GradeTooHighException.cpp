#include "GradeTooHighException.hpp"

const char* GradeTooHighException::what(void) const throw() {
  return "This bureaucrat's grade is too high!\n";
}
