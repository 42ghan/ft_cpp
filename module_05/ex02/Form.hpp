/**
 * @file Form.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A header file for Form class
 * @date 2022-04-12
 */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

#include "color.hpp"

class Bureaucrat;

class Form {
 protected:
  const std::string name_;
  const unsigned int sign_grade_;
  const unsigned int exec_grade_;
  bool is_signed_;

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

  bool checkGrade(const unsigned int) const;

 public:
  Form(void);
  virtual ~Form(void) = 0;
  Form(const std::string&, const unsigned int, const unsigned int);
  Form(const Form&);

  Form& operator=(const Form&);

  std::string getName(void) const;
  unsigned int getSignGrade(void) const;
  unsigned int getExecGrade(void) const;
  bool getIsSigned(void) const;

  void beSigned(const Bureaucrat&);

  virtual void execute(const Bureaucrat& executor) const = 0;
};

std::ostream& operator<<(std::ostream&, const Form&);

#endif
