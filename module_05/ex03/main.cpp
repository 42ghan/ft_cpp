#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  try {
    Intern someRandomIntern;
    Form* rrf;
    Bureaucrat brian("brian", 1);

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    brian.signForm(*rrf);
    brian.executeForm(*rrf);
    delete rrf;
    rrf = someRandomIntern.makeForm("presidential pardon", "John");
    brian.signForm(*rrf);
    brian.executeForm(*rrf);
    delete rrf;
    rrf = someRandomIntern.makeForm("shrubbery creation", "home");
    brian.signForm(*rrf);
    brian.executeForm(*rrf);
    delete rrf;
  } catch (std::exception& e) {
    std::cout << e.what();
  }

  return EXIT_SUCCESS;
}
