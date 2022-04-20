/**
 * @file main.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Test for ClapTrap class
 * @date 2022-04-06
 */

#include "ClapTrap.hpp"

int main(void) {
  ClapTrap ct("peter");

  ct.attack("john");
  ct.takeDamage(3);
  ct.beRepaired(5);
  ct.printStatus();
  return EXIT_SUCCESS;
}
