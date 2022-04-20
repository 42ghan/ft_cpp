/**
 * @file main.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Test for ClapTrap class
 * @date 2022-04-06
 */

#include "ClapTrap.hpp"

int main(void) {
  ClapTrap ct("peter");
  ClapTrap ct1("heinz");

  ct = ct1;
  ct1 = ClapTrap("jake");

  ct.attack("john");
  ct.takeDamage(3);
  ct.beRepaired(5);
  ct.printStatus();
  ct1.takeDamage(100);
  ct1.beRepaired(30);
  ct1.printStatus();
  return EXIT_SUCCESS;
}
