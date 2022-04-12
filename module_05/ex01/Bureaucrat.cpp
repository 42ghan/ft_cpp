/**
 * @file Bureaucrat.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions of member functions of Bureaucrat class
 * @date 2022-04-12
 */

#include "Bureaucrat.hpp"

#include "Form.hpp"

// default constructor
Bureaucrat::Bureaucrat(void) : grade_(0) {
  if (grade_ < 1) throw GradeTooHighException();
  std::cout << L_GREEN << "Default constructor (Bureaucrat)\n" << RESET;
}

// destructor
Bureaucrat::~Bureaucrat(void) {
  std::cout << L_RED << "An instance of Bureaucrat is destroyed\n" << RESET;
}

// constructor with a given name and grade
Bureaucrat::Bureaucrat(const std::string& name, const unsigned int& grade)
    : name_(name), grade_(grade) {
  if (grade < 1) throw GradeTooHighException();
  if (grade > 150) throw GradeTooLowException();
  std::cout << L_GREEN << name << " with grade, " << grade
            << " has been constructed\n"
            << RESET;
}

// copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& original) {
  *this = original;
  std::cout << L_GREEN << "Copy constructor (Bureaucrat)\n" << RESET;
}

// = operator overload
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
  grade_ = rhs.getGrade();
  return *this;
}

// getters
std::string Bureaucrat::getName(void) const { return name_; }

unsigned int Bureaucrat::getGrade(void) const { return grade_; }

// increment || decrement
Bureaucrat& Bureaucrat::operator++(void) {
  if (getGrade() <= 1) throw GradeTooHighException();
  grade_--;
  return *this;
}

Bureaucrat& Bureaucrat::operator--(void) {
  if (getGrade() >= 150) throw GradeTooLowException();
  grade_++;
  return *this;
}

// sign form
void Bureaucrat::signForm(Form& form) const {
  if (form.getSignGrade() >= grade_) 
    std::cout << name_ << " signed " << form.getName() << '\n';
  else
    std::cout << name_ << " couldn't sign " << form.getName()
              << " because his/her grade is not high enough to sign the form\n";
  form.beSigned(*this);
}

// << operator overload
std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs) {
  out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << '\n';
  return out;
}
