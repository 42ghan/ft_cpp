/**
 * @file Form.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions of member functions of Form class
 * @date 2022-04-12
 */

#include "Form.hpp"

#include "Bureaucrat.hpp"

// default constructor
Form::Form(void) : sign_grade_(0), exec_grade_(0), is_signed_(0) {
  throw GradeTooHighException();
  std::cout << L_GREEN << "Default constructor (Form)\n" << RESET;
}

// destructor
Form::~Form(void) {
  std::cout << L_RED << "An instance of Form class has been destroyed\n"
            << RESET;
}

// constructor with a given name, a sign grade, a exec grade
Form::Form(const std::string& name, const unsigned int sign_grade,
           const unsigned int exec_grade)
    : name_(name),
      sign_grade_(sign_grade),
      exec_grade_(exec_grade),
      is_signed_(0) {
  if (sign_grade < 1 || exec_grade < 1) throw GradeTooHighException();
  if (sign_grade > 150 || exec_grade > 150) throw GradeTooLowException();
  std::cout << L_GREEN << "A form (name : " << name
            << ", sign grade : " << sign_grade
            << ", exec grade : " << exec_grade
            << ") has been created and is not signed yet\n"
            << RESET;
}

// copy constructor
Form::Form(const Form& original)
    : name_(original.getName()),
      sign_grade_(original.getSignGrade()),
      exec_grade_(original.getExecGrade()) {
  *this = original;
  std::cout << L_GREEN << "Copy constructor (Form)\n" << RESET;
}

// = operator overload
Form& Form::operator=(const Form& rhs) {
  is_signed_ = rhs.getIsSigned();
  return *this;
}

// getters & setters
std::string Form::getName(void) const { return name_; }

unsigned int Form::getSignGrade(void) const { return sign_grade_; }

unsigned int Form::getExecGrade(void) const { return exec_grade_; }

bool Form::getIsSigned(void) const { return is_signed_; }

// be signed
void Form::beSigned(const Bureaucrat& a) {
  if (a.getGrade() <= sign_grade_)
    is_signed_ = true;
  else
    throw GradeTooLowException();
}

// check grade
bool Form::checkGrade(const unsigned int grade) const {
  if (getExecGrade() < grade) throw GradeTooLowException();
  return true;
}

// << operator overload
std::ostream& operator<<(std::ostream& out, const Form& rhs) {
  out << "Form " << rhs.getName() << " (sign grade : " << rhs.getSignGrade()
      << ", exec grade : " << rhs.getExecGrade() << ",";
  if (rhs.getIsSigned())
    out << " signed)\n";
  else
    out << " not signed)\n";
  return out;
}
