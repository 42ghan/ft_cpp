/**
 * @file main.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Test for ScavTrap class
 * @date 2022-04-06
 */

#include "ScavTrap.hpp"

int main(void) {
  ScavTrap st("peter");

  st.attack("john");
  st.takeDamage(3);
  st.beRepaired(5);
  st.printStatus();
  st.guardGate();
  return EXIT_SUCCESS;
}
