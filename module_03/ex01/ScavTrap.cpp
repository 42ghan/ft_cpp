/**
 * @file ScavTrap.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions of member functions of ScavTrap
 * @date 2022-04-06
 */

#include "ScavTrap.hpp"

// default constructor
ScavTrap::ScavTrap(void) {
  setHitPoints(100);
  setEnergyPoints(50);
  setAttackDamage(20);
  std::cout << L_GREEN << "Default constructor (ScavTrap)\n" << RESET;
};

// destructor
ScavTrap::~ScavTrap(void) {
  std::cout << L_RED << "Destructor (ScavTrap)\n" << RESET;
}

// constructor with a given name
ScavTrap::ScavTrap(const std::string& name) {
  setName(name);
  setHitPoints(100);
  setEnergyPoints(50);
  setAttackDamage(20);
  std::cout << L_GREEN << "ScavTrap <" << name << "> has been constructed\n"
            << RESET;
}

// copy constructor
ScavTrap::ScavTrap(const ScavTrap& original) {
  std::cout << L_GREEN << "Copy constructor has been called (ScavTrap)\n"
            << RESET;
  *this = original;
}

// = operator overload
ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
  setName(rhs.getName());
  setHitPoints(rhs.getHitPoints());
  setEnergyPoints(rhs.getEnergyPoints());
  setAttackDamage(rhs.getAttackDamage());
  return *this;
}

void ScavTrap::guardGate(void) {
  std::cout << "ScavTrap <" << getName() << "> is now in Gate keeper mode\n";
}

void ScavTrap::attack(const std::string& target) {
  energy_points_--;
  std::cout << "ScavTrap <" << getName() << "> attacks <" << target
            << ">, causing <" << getAttackDamage() << "> points of damage!\n";
}
