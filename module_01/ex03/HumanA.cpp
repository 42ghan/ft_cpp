/**
 * @file HumanA.cpp
 * @author your name (you@domain.com)
 * @brief Definitions of HumanA class members
 * @date 2022-02-26
 */

#include "HumanA.hpp"

// HumanA class constructor
HumanA::HumanA(const std::string name, Weapon &weapon)
    : name_(name), weapon_(weapon) {
  std::cout << GREEN << "Human A " << name << " is constructed\n" << RESET;
}

// HumanA class destructor
HumanA::~HumanA(void) {
  std::cout << RED << "Human A " << this->name_ << " is destructed\n" << RESET;
}

// attack
void HumanA::attack(void) const {
  std::cout << this->name_ << " attacks with his " << this->weapon_.getType()
            << '\n';
}