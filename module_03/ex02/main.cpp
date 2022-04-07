/**
 * @file main.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Test for FragTrap class
 * @date 2022-04-06
 */

#include "FragTrap.hpp"

int main(void) {
  FragTrap ft("peter");

  ft.attack("john");
  ft.takeDamage(3);
  ft.beRepaired(5);
  ft.printStatus();
  ft.highFivesGuys();
  return EXIT_SUCCESS;
}
