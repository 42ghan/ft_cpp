/**
 * @file FragTrap.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions for member functions of FragTrap class
 * @date 2022-04-07
 */

#include "FragTrap.hpp"

// default constructor
FragTrap::FragTrap(void) {
  hit_points_ = 100;
  energy_points_ = 100;
  attack_damage_ = 30;
  std::cout << L_GREEN << "Default constructor (FragTrap)\n" << RESET;
}

// destructor
FragTrap::~FragTrap(void) {
  std::cout << L_RED << "Destructor (FragTrap)\n" << RESET;
}

// constructor with a given name
FragTrap::FragTrap(const std::string& name) {
  name_ = name;
  hit_points_ = 100;
  energy_points_ = 100;
  attack_damage_ = 30;
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
  name_ = rhs.name_;
  hit_points_ = rhs.hit_points_;
  energy_points_ = rhs.energy_points_;
  attack_damage_ = rhs.attack_damage_;
  return *this;
}

// highfive guys
void FragTrap::highFivesGuys(void) {
  if (!hit_points_) {
    std::cout << "Not enough HP to perform the request task...\n";
    return;
  }
  std::cout << "FragTrap " << name_ << " high five! 🙌\n";
}
