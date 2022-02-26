/**
 * @file Weapon.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions of Weapon class members
 * @date 2022-02-26
 */

#include "Weapon.hpp"

// Weapon class constructor
Weapon::Weapon(std::string type) : type_(type) {
  std::cout << GREEN << type << " is constructed\n" << RESET;
}

// Weapon class destructor
Weapon::~Weapon(void) {
  std::cout << RED << this->type_ << " is destructed\n" << RESET;
}

// getter
const std::string& Weapon::getType(void) const { return this->type_; }

// setter
void Weapon::setType(std::string new_type) { this->type_ = new_type; }