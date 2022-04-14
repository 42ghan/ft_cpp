#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  try {
    Bureaucrat james("james", 1);
    ShrubberyCreationForm s_form("home");
    RobotomyRequestForm r_form("john");
    PresidentialPardonForm p_form("jake");

    james.signForm(s_form);
    james.signForm(r_form);
    james.signForm(p_form);
    std::cout << "================ Shrubbery ================\n";
    james.executeForm(s_form);
    std::cout << "\n================ Robotomy ================\n";
    james.executeForm(r_form);
    std::cout << "\n================ PresidentialPardon ================\n";
    james.executeForm(p_form);
  } catch (std::exception& e) {
    std::cout << e.what();
  }

  try {
    Bureaucrat bob("bob", 7);
    ShrubberyCreationForm s_form("work");
    RobotomyRequestForm r_form("brian");
    PresidentialPardonForm p_form("bono");

    bob.signForm(s_form);
    bob.signForm(r_form);
    bob.signForm(p_form);
    std::cout << "================ Shrubbery ================\n";
    bob.executeForm(s_form);
    std::cout << "\n================ Robotomy ================\n";
    bob.executeForm(r_form);
    std::cout << "\n================ PresidentialPardon ================\n";
    bob.executeForm(p_form);
  } catch (std::exception& e) {
    std::cout << e.what();
  }

  return EXIT_SUCCESS;
}
