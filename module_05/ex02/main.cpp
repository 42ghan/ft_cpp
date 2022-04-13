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
    Bureaucrat bob("bob", 150);

    std::cout << "================ Shrubbery ================\n";
    james.executeForm(s_form);
    std::cout << "\n================ Robotomy ================\n";
    james.executeForm(r_form);
    std::cout << "\n================ PresidentialPardon ================\n";
    james.executeForm(p_form);
  } catch (std::exception& e) {
    std::cout << e.what();
  }
  return EXIT_SUCCESS;
}
