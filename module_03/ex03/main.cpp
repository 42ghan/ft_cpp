/**
 * @file main.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Test for DiamondTrap class
 * @date 2022-04-06
 */

#include "DiamondTrap.hpp"

int main(void) {
  DiamondTrap dt("peter");

  dt.attack("john");
  dt.takeDamage(3);
  dt.beRepaired(5);
  dt.printStatus();
  dt.guardGate();
  dt.highFivesGuys();
  dt.whoAmI();

  dt.takeDamage(200);
  dt.whoAmI();
  
  return EXIT_SUCCESS;
}
