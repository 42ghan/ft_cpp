#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void test(void) {
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
    rrf = someRandomIntern.makeForm("wrong", "home");
  } catch (std::exception& e) {
    std::cout << e.what();
  }
}

int main(void) {
  test();
  system("leaks coffee_making");

  return EXIT_SUCCESS;
}
