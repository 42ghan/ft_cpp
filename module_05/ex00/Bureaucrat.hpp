/**
 * @file Bureaucrat.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A header file for Bureaucrat class
 * @date 2022-04-12
 */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

#include "color.hpp"

class Bureaucrat {
 private:
  const std::string name_;
  unsigned int grade_;
  GradeTooHighException too_high_;
  GradeTooLowException too_low_;

 public:
  Bureaucrat(void);
  ~Bureaucrat(void);
  Bureaucrat(const std::string&, const unsigned int&);
  Bureaucrat(const Bureaucrat&);

  Bureaucrat& operator=(const Bureaucrat&);

  const std::string getName(void) const;
  unsigned int getGrade(void) const;

  Bureaucrat& operator++(void);
  Bureaucrat& operator--(void);
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif
