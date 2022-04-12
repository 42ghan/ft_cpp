/**
 * @file Bureaucrat.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions of member functions of Bureaucrat class
 * @date 2022-04-12
 */

#include "Bureaucrat.hpp"

// default constructor
Bureaucrat::Bureaucrat(void) : grade_(0) {
  if (grade_ < 1) throw too_high_;
  std::cout << L_GREEN << "Default constructor (Bureaucrat)\n" << RESET;
}

// destructor
Bureaucrat::~Bureaucrat(void) {
  std::cout << L_RED << "An instance of Bureaucrat is destroyed\n" << RESET;
}

// constructor with a given name and grade
Bureaucrat::Bureaucrat(const std::string& name, const unsigned int& grade)
    : name_(name), grade_(grade) {
  if (grade < 1) throw too_high_;
  if (grade > 150) throw too_low_;  
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
const std::string Bureaucrat::getName(void) const { return name_; }

unsigned int Bureaucrat::getGrade(void) const { return grade_; }

// increment || decrement
Bureaucrat& Bureaucrat::operator++(void) {
  grade_--;
  if (getGrade() < 1) throw too_high_;
  return *this;
}

Bureaucrat& Bureaucrat::operator--(void) {
  grade_++;
  if (getGrade() > 150) throw too_low_;
  return *this;
}

// << operator overload
std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs) {
  out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << '\n';
  return out;
}
