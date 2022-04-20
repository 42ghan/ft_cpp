/**
 * @file ClapTrap.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions for ClapTrap class
 * @date 2022-04-06
 */

#include "ClapTrap.hpp"

// default constructor
ClapTrap::ClapTrap(void)
    : hit_points_(10), energy_points_(10), attack_damage_(0) {
  std::cout << L_GREEN << "Default constructor (ClapTrap)\n" << RESET;
}

// destructor
ClapTrap::~ClapTrap(void) {
  std::cout << L_RED << "Destructor (ClapTrap)\n" << RESET;
}

// constructor with a given name
ClapTrap::ClapTrap(const std::string& name)
    : name_(name), hit_points_(10), energy_points_(10), attack_damage_(0) {
  std::cout << L_GREEN << "ClapTrap <" << name << "> has been constructed\n"
            << RESET;
}

// copy constructor
ClapTrap::ClapTrap(const ClapTrap& original) {
  std::cout << L_GREEN << "Copy constructor has been called (ClapTrap)\n"
            << RESET;
  *this = original;
}

// = operator overload
ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
  name_ = rhs.name_;
  hit_points_ = rhs.hit_points_;
  energy_points_ = rhs.energy_points_;
  attack_damage_ = rhs.attack_damage_;
  return *this;
}

// required functions
void ClapTrap::attack(const std::string& target) {
  if (!hit_points_ || !energy_points_) { 
    std::cout << "Not enough HP / EP to perform the request task...\n";
    return;
  }
  energy_points_--;
  std::cout << "ClapTrap " << name_ << " attacks " << target << ", causing "
            << attack_damage_ << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (amount > hit_points_)
    hit_points_ = 0;
  else
    hit_points_ -= amount;
  std::cout << "ClapTrap " << name_ << " has taken " << amount
            << " points of damage...\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (!hit_points_ || !energy_points_) { 
    std::cout << "Not enough HP / EP to perform the request task...\n";
    return;
  }
  hit_points_ += amount;
  energy_points_--;
  std::cout << "ClapTrap " << name_
            << " repaired itself, and as a result, hit points have been "
               "increased by "
            << amount << "\n";
}

// display current status of the ClapTrap instance
void ClapTrap::printStatus(void) const {
  std::cout << "==============================================================="
               "=======\n"
            << "name : " << name_ << ", hit points : " << hit_points_
            << ", energy points : " << energy_points_
            << ", attack damage : " << attack_damage_
            << "\n============================================================="
               "=========\n";
}
