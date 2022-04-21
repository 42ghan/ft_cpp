/**
 * @file DiamondTrap.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions for member functions of DiamondTrap class
 * @date 2022-04-07
 */

#include "DiamondTrap.hpp"

// default constructor
DiamondTrap::DiamondTrap(void) : ClapTrap("_clap_name") {
  hit_points_ = 100;
  energy_points_ = 50;
  attack_damage_ = 30;
  std::cout << L_GREEN << "Default constructor (DiamondTrap)\n" << RESET;
}

// destructor
DiamondTrap::~DiamondTrap(void) {
  std::cout << L_RED << "Destructor (DiamondTrap)\n" << RESET;
}

// constructor with a given name
DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name") {
  name_ = name;
  hit_points_ = 100;
  energy_points_ = 50;
  attack_damage_ = 30;
  std::cout << L_GREEN << "DiamondTrap " << name << " has been constructed\n"
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
  name_ = rhs.name_;
  hit_points_ = rhs.hit_points_;
  energy_points_ = rhs.energy_points_;
  attack_damage_ = rhs.attack_damage_;
  return *this;
}

// who am I
void DiamondTrap::whoAmI(void) {
  if (!hit_points_) {
    std::cout << "Not enough HP to perform the request task...\n";
    return;
  }
  std::cout << "My Diamond name is " << name_ << " and my Clap name is "
            << ClapTrap::name_ << "\n";
}
