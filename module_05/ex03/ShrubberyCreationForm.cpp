/**
 * @file ShrubberyCreationForm.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions of member functions of ShrubberyCreationForm class
 * @date 2022-04-13
 */

#include "ShrubberyCreationForm.hpp"

#include "Bureaucrat.hpp"

// default constructor
ShrubberyCreationForm::ShrubberyCreationForm(void)
    : Form("ShrubberyCreation", 145, 137) {
  std::cout << L_GREEN << "Default constructor (ShrubberyCreationForm)\n"
            << RESET;
}

// destructor
ShrubberyCreationForm::~ShrubberyCreationForm(void) {
  std::cout << L_RED
            << "An instance of ShrubberyCreationForm has been destroyed\n"
            << RESET;
}

// constructor with a given target
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : Form("ShrubberyCreation", 145, 137), target_(target) {
  std::cout << L_GREEN << "ShrubberyCreationForm for " << target
            << " has been constructed\n"
            << RESET;
}

// copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(
    const ShrubberyCreationForm& original)
    : Form(original.getName(), original.getSignGrade(),
           original.getExecGrade()),
      target_(original.target_) {
  *this = original;
  std::cout << L_GREEN << "Copy constructor (ShrubberyCreationForm)\n" << RESET;
}

// = operator overload
ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& rhs) {
  setIsSigned(rhs.getIsSigned());
  return *this;
}

// getter
std::string ShrubberyCreationForm::getTarget(void) const { return target_; }

// execute overriding
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
  if (checkGrade(executor.getGrade())) {
    std::ofstream file(target_ + "_shrubbery");
    if (!file.is_open()) {
      std::cout << "Error : Failed to create a file\n";
      return;
    }
    file << ASCII_TREE;
    file.close();
  }
}
