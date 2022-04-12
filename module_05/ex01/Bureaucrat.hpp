/**
 * @file Bureaucrat.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A header file for Bureaucrat class
 * @date 2022-04-12
 */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

// #include "Form.hpp"
#include "color.hpp"

class Form;

class Bureaucrat {
 private:
  const std::string name_;
  unsigned int grade_;

  class GradeTooHighException : public std::exception {
    virtual const char* what(void) const throw() {
      return "This bureaucrat's grade is too high!\n";
    }
  };

  class GradeTooLowException : public std::exception {
    virtual const char* what(void) const throw() {
      return "This bureaucrat's grade is too low!\n";
    }
  };

 public:
  Bureaucrat(void);
  ~Bureaucrat(void);
  Bureaucrat(const std::string&, const unsigned int&);
  Bureaucrat(const Bureaucrat&);

  Bureaucrat& operator=(const Bureaucrat&);

  std::string getName(void) const;
  unsigned int getGrade(void) const;

  Bureaucrat& operator++(void);
  Bureaucrat& operator--(void);

  void signForm(Form&) const;
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif
