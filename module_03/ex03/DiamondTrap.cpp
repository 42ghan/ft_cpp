/**
 * @file DiamondTrap.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions for member functions of DiamondTrap class
 * @date 2022-04-07
 */

#include "DiamondTrap.hpp"

// default constructor
DiamondTrap::DiamondTrap(void) {
  setHitPoints(100);
  setEnergyPoints(50);
  setAttackDamage(30);
  std::cout << L_GREEN << "Default constructor (DiamondTrap)\n" << RESET;
};

// destructor
DiamondTrap::~DiamondTrap(void) {
  std::cout << L_RED << "Destructor (DiamondTrap)\n" << RESET;
}

// constructor with a given name
DiamondTrap::DiamondTrap(const std::string& name) {
  name_ = name;
  setName(name + "_clap_name");
  setHitPoints(100);
  setEnergyPoints(50);
  setAttackDamage(30);
  std::cout << L_GREEN << "DiamondTrap <" << name << "> has been constructed\n"
            << RESET;
}

// copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& original) {
  std::cout << L_GREEN << "Copy constructor has been called (DiamondTrap)\n"
            << RESET;
  *this = original;
}

// = operator overload
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) {
  setName(rhs.getName());
  setHitPoints(rhs.getHitPoints());
  setEnergyPoints(rhs.getEnergyPoints());
  setAttackDamage(rhs.getAttackDamage());
  return *this;
}

// who am I
void DiamondTrap::whoAmI(void) {
  std::cout << "My Diamond name is <" << name_ << "> and my Clap name is <"
            << getName() << ">\n";
}
