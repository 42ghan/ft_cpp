/**
 * @file PresidentialPardonForm.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A header file for PresidentialPardonForm class
 * @date 2022-04-13
 */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>

#include "Form.hpp"
#include "color.hpp"

class PresidentialPardonForm : public Form {
 private:
  std::string target_;

 public:
  PresidentialPardonForm(void);
  ~PresidentialPardonForm(void);
  PresidentialPardonForm(const std::string&);
  PresidentialPardonForm(const PresidentialPardonForm&);

  PresidentialPardonForm& operator=(const PresidentialPardonForm&);

  std::string getTarget(void) const;

  void execute(const Bureaucrat& executor) const;
};

#endif
