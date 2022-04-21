#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  try {
    Form empty;
  } catch (std::exception& e) {
    std::cout << e.what();
  }

  try {
    Form too_low("too_low", 151, 100);
  } catch (std::exception& e) {
    std::cout << e.what();
  }

  try {
    Form too_low("too_low", 100, 155);
  } catch (std::exception& e) {
    std::cout << e.what();
  }

  try {
    Bureaucrat john("john", 5);
    Bureaucrat jake("jake", 3);
    Form abc("abc", 3, 1);

    std::cout << abc;
    jake.signForm(abc);
    std::cout << abc;
    john.signForm(abc);

  } catch (std::exception& e) {
    std::cout << e.what();
  }
  return EXIT_SUCCESS;
}
