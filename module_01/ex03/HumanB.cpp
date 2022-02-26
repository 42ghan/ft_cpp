/**
 * @file HumanB.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions of HumanB class members
 * @date 2022-02-26
 */

#include "HumanB.hpp"

// HumanB class constructor
HumanB::HumanB(const std::string name) : name_(name) {
  std::cout << GREEN << "Human B " << name << " is constructed\n" << RESET;
}

// HumanB class destructor
HumanB::~HumanB(void) {
  std::cout << RED << "Human B " << this->name_ << " is destructed\n" << RESET;
}

// attack
void HumanB::attack(void) const {
  std::cout << this->name_ << " attacks with his " << this->weapon_->getType()
            << '\n';
}

// setWeapon
void HumanB::setWeapon(Weapon &weapon) { this->weapon_ = &weapon; }