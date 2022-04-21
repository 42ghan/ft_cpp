/**
 * @file Intern.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A header file for Intern class
 * @date 2022-04-14
 */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

#include "color.hpp"

class Form;

class Intern {
 private:
  Form* allocShrubberyCreation(const std::string& target);
  Form* allocRobotomyRequest(const std::string& target);
  Form* allocPresidentialPardon(const std::string& target);

 public:
  Intern(void);
  ~Intern(void);
  Intern(const Intern&);

  Intern& operator=(const Intern&);

  Form* makeForm(const std::string& form_name, const std::string& target);
};

#endif
