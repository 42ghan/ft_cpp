/**
 * @file ScavTrap.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions of member functions of ScavTrap
 * @date 2022-04-06
 */

#include "ScavTrap.hpp"

// default constructor
ScavTrap::ScavTrap(void)  {
  hit_points_ = 100;
  energy_points_ = 50;
  attack_damage_ = 20;
  std::cout << L_GREEN << "Default constructor (ScavTrap)\n" << RESET;
}

// destructor
ScavTrap::~ScavTrap(void) {
  std::cout << L_RED << "Destructor (ScavTrap)\n" << RESET;
}

// constructor with a given name
ScavTrap::ScavTrap(const std::string& name) {
  name_ = name;
  hit_points_ = 100;
  energy_points_ = 50;
  attack_damage_ = 20;
  std::cout << L_GREEN << "ScavTrap " << name << " has been constructed\n"
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
  name_ = rhs.name_;
  hit_points_ = rhs.hit_points_;
  energy_points_ = rhs.energy_points_;
  attack_damage_ = rhs.attack_damage_;
  return *this;
}

// guard gate
void ScavTrap::guardGate(void) {
  if (!hit_points_ || !energy_points_) { 
    std::cout << "Not enough HP / EP to perform the request task...\n";
    return;
  }
  std::cout << "ScavTrap " << name_ << " is now in Gate keeper mode\n";
}

// Scav attack
void ScavTrap::attack(const std::string& target) {
  if (!hit_points_ || !energy_points_) { 
    std::cout << "Not enough HP / EP to perform the request task...\n";
    return;
  }
  energy_points_--;
  std::cout << "ScavTrap " << name_ << " attacks " << target << ", causing "
            << attack_damage_ << " points of damage!\n";
}
