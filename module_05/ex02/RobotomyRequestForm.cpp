/**
 * @file RobotomyRequestForm.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions of member functions of RobotomyRequestForm class
 * @date 2022-04-13
 */

#include "RobotomyRequestForm.hpp"

#include "Bureaucrat.hpp"

// default constructor
RobotomyRequestForm::RobotomyRequestForm(void)
    : Form("RobotomyRequest", 72, 45) {
  std::cout << L_GREEN << "Default constructor (RobotomyRequestForm)\n"
            << RESET;
}

// destructor
RobotomyRequestForm::~RobotomyRequestForm(void) {
  std::cout << L_RED
            << "An instance of RobotomyRequestForm has been destroyed\n"
            << RESET;
}

// constructor with a given target
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : Form("RobotomyRequest", 72, 45), target_(target) {
  std::cout << L_GREEN << "RobotomyRequestForm for " << target
            << " has been constructed\n"
            << RESET;
}

// copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& original)
    : Form(original.getName(), original.getSignGrade(),
           original.getExecGrade()),
      target_(original.target_) {
  *this = original;
  std::cout << L_GREEN << "Copy constructor (RobotomyRequestForm)\n" << RESET;
}

// = operator overload
RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& rhs) {
  setIsSigned(rhs.getIsSigned());
  return *this;
}

// getter
std::string RobotomyRequestForm::getTarget(void) const { return target_; }

// execute overriding
void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
  struct timeval time;

  if (checkGrade(executor.getGrade())) {
    gettimeofday(&time, NULL);
    srand(time.tv_usec);
    std::cout << "Drrrrrrrrrrrrrrrrrr\n";
    if (rand() % 2)
      std::cout << target_ << " has been robotomized successfully!\n";
    else
      std::cout << "Failed to robotomize " << target_ << "...\n";
  }
}
