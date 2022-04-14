/**
 * @file RobotomyRequestForm.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A header file for RobotomyRequestForm class
 * @date 2022-04-13
 */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <sys/time.h>

#include <cstdlib>
#include <iostream>
#include <string>

#include "Form.hpp"
#include "color.hpp"

class Bureaucrat;

class RobotomyRequestForm : public Form {
 private:
  std::string target_;

 public:
  RobotomyRequestForm(void);
  ~RobotomyRequestForm(void);
  RobotomyRequestForm(const std::string&);
  RobotomyRequestForm(const RobotomyRequestForm&);

  RobotomyRequestForm& operator=(const RobotomyRequestForm&);

  std::string getTarget(void) const;

  void execute(const Bureaucrat& executor) const;
};

#endif
