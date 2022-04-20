/**
 * @file FragTrap.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions for member functions of FragTrap class
 * @date 2022-04-07
 */

#include "FragTrap.hpp"

// default constructor
FragTrap::FragTrap(void) {
  setHitPoints(100);
  setEnergyPoints(100);
  setAttackDamage(30);
  std::cout << L_GREEN << "Default constructor (FragTrap)\n" << RESET;
}

// destructor
FragTrap::~FragTrap(void) {
  std::cout << L_RED << "Destructor (FragTrap)\n" << RESET;
}

// constructor with a given name
FragTrap::FragTrap(const std::string& name) {
  setName(name);
  setHitPoints(100);
  setEnergyPoints(100);
  setAttackDamage(30);
  std::cout << L_GREEN << "FragTrap " << name << " has been constructed\n"
            << RESET;
}

// copy constructor
FragTrap::FragTrap(const FragTrap& original) {
  std::cout << L_GREEN << "Copy constructor has been called (FragTrap)\n"
            << RESET;
  *this = original;
}

// = operator overload
FragTrap& FragTrap::operator=(const FragTrap& rhs) {
  setName(rhs.getName());
  setHitPoints(rhs.getHitPoints());
  setEnergyPoints(rhs.getEnergyPoints());
  setAttackDamage(rhs.getAttackDamage());
  return *this;
}

// highfive guys
void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap " << getName() << " high five! 🙌\n";
}
