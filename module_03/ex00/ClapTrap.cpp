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
};

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
  setName(rhs.getName());
  setHitPoints(rhs.getHitPoints());
  setEnergyPoints(rhs.getEnergyPoints());
  setAttackDamage(rhs.getAttackDamage());
  return *this;
}

// required functions
void ClapTrap::attack(const std::string& target) {
  energy_points_--;
  std::cout << "ClapTrap <" << getName() << "> attacks <" << target
            << ">, causing <" << getAttackDamage() << "> points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (amount > hit_points_)
    hit_points_ = 0;
  else
    hit_points_ -= amount;
  std::cout << "ClapTrap <" << getName() << "> has taken <" << amount
            << "> points of damage...\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
  hit_points_ += amount;
  energy_points_--;
  std::cout << "ClapTrap <" << getName()
            << "> repaired itself, and as a result, hit points have been "
               "increased by <"
            << amount << ">\n";
}

// display current status of the ClapTrap instance
void ClapTrap::printStatus(void) const {
  std::cout << "==============================================================="
               "=======\n"
            << "name : " << getName() << ", hit points : " << getHitPoints()
            << ", energy points : " << getEnergyPoints()
            << ", attack damage : " << getAttackDamage()
            << "\n============================================================="
               "=========\n";
}

// getters & setters
std::string ClapTrap::getName(void) const { return name_; }

unsigned int ClapTrap::getHitPoints(void) const { return hit_points_; }

unsigned int ClapTrap::getEnergyPoints(void) const { return energy_points_; }

unsigned int ClapTrap::getAttackDamage(void) const { return attack_damage_; }

void ClapTrap::setName(const std::string new_name) { name_ = new_name; };

void ClapTrap::setHitPoints(const unsigned int new_hp) {
  hit_points_ = new_hp;
};

void ClapTrap::setEnergyPoints(const unsigned int new_ep) {
  energy_points_ = new_ep;
};

void ClapTrap::setAttackDamage(const unsigned int new_damage) {
  attack_damage_ = new_damage;
};
