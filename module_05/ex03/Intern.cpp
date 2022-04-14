/**
 * @file Intern.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions of member functions of Intern class
 * @date 2022-04-14
 */

#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// default constructor
Intern::Intern(void) {
  std::cout << L_GREEN << "Default constructor (Intern)\n" << RESET;
}

// destructor
Intern::~Intern(void) {
  std::cout << L_RED << "An instance of Intern has been destroyed\n" << RESET;
}

// copy constructor
Intern::Intern(const Intern& original) {
  *this = original;
  std::cout << L_GREEN << "Copy constructor (Intern)\n" << RESET;
}

// = operator overload
Intern& Intern::operator=(const Intern& rhs) {
  (void)rhs;
  return *this;
}

// allocate different types of forms
Form* Intern::allocShrubberyCreation(const std::string& target) {
  return new ShrubberyCreationForm(target);
}

Form* Intern::allocRobotomyRequest(const std::string& target) {
  return new RobotomyRequestForm(target);
}

Form* Intern::allocPresidentialPardon(const std::string& target) {
  return new PresidentialPardonForm(target);
}

// make form
Form* Intern::makeForm(const std::string& form_name,
                       const std::string& target) {
  std::string names[3] = {"shrubbery creation", "robotomy request",
                          "presidential pardon"};
  Form* (Intern::*f[3])(const std::string&) = {
      &Intern::allocShrubberyCreation, &Intern::allocRobotomyRequest,
      &Intern::allocPresidentialPardon};

  for (int i = 0; i < 3; i++) {
    if (names[i] == form_name) {
      Form* ret = (this->*f[i])(target);
      std::cout << "Intern creates " << form_name << '\n';
      return ret;
    };
  }
  std::cout << "* ERROR : the requested form does not exist\n";
  return NULL;
}
