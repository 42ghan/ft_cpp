#include "Bureaucrat.hpp"

int main(void) {
  try {
    Bureaucrat bob("bob", 1);
    Bureaucrat james("james", 3);

    std::cout << james;
    ++james;
    std::cout << james;
    --james;
    std::cout << james;
    ++bob;
  } catch (std::exception& e) {
    std::cout << e.what();
  }

  try {
    Bureaucrat john("john", 150);
    --john;
  } catch (std::exception& e) {
    std::cout << e.what();
  }

  try {
    Bureaucrat jane("jane", 151);
  } catch (std::exception& e) {
    std::cout << e.what();
  }

  try {
    Bureaucrat jake("jake", 0);
  } catch (std::exception& e) {
    std::cout << e.what();
  }
  return EXIT_SUCCESS;
}
