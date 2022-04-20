/**
 * @file PresidentialPardonForm.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions of member functions of PresidentialPardonForm class
 * @date 2022-04-13
 */

#include "PresidentialPardonForm.hpp"

#include "Bureaucrat.hpp"

// default constructor
PresidentialPardonForm::PresidentialPardonForm(void)
    : Form("PresidentialPardon", 25, 5) {
  std::cout << L_GREEN << "Default constructor (PresidentialPardonForm)\n"
            << RESET;
}

// destructor
PresidentialPardonForm::~PresidentialPardonForm(void) {
  std::cout << L_RED
            << "An instance of PresidentialPardonForm has been destroyed\n"
            << RESET;
}

// constructor with a given target
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : Form("PresidentialPardon", 25, 5), target_(target) {
  std::cout << L_GREEN << "PresidentialPardonForm for " << target
            << " has been constructed\n"
            << RESET;
}

// copy constructor
PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& original)
    : Form(original.getName(), original.getSignGrade(),
           original.getExecGrade()),
      target_(original.getTarget()) {
  *this = original;
  std::cout << L_GREEN << "Copy constructor (PresidentialPardonForm)\n"
            << RESET;
}

// = operator overload
PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& rhs) {
  is_signed_ = rhs.getIsSigned();
  return *this;
}

// getter
std::string PresidentialPardonForm::getTarget(void) const { return target_; }

// execute overriding
void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
  if (checkGrade(executor.getGrade()))
    std::cout << target_ << " has been pardoned by Zaphod Beeblebrox.\n";
}
