/**
 * @file Zombie.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions of Zombie class members
 * @date 2022-02-24
 */

#include "Zombie.hpp"

// Zombie class default constructor
Zombie::Zombie(void) {
  std::cout << GREEN << "A new zombie is born!\n" << RESET;
};

// Zombie class constructor
Zombie::Zombie(std::string name) {
  this->name_ = name;
  std::cout << GREEN << '<' << this->name_ << "> is born !\n" << RESET;
}

// Zombie class destructor
Zombie::~Zombie(void) {
  std::cout << L_RED << '<' << this->name_ << "> is deaDDDDD...\n" << RESET;
}

// announce BraiiiiiiinnnzzzZ...
void Zombie::announce(void) const {
  std::cout << L_BLUE << '<' << this->name_ << "> BraiiiiiiinnnzzzZ...\n"
            << RESET;
}

// setter for name
void Zombie::setName(std::string name) { this->name_ = name; }
