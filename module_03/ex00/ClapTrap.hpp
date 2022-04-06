/**
 * @file ClapTrap.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A header file for ClapTrap class
 * @date 2022-04-05
 */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

#include "color.hpp"

class ClapTrap {
 private:
  std::string name_;
  unsigned int hit_points_;
  unsigned int energy_points_;
  unsigned int attack_damage_;

  std::string getName(void) const;
  unsigned int getHitPoints(void) const;
  unsigned int getEnergyPoints(void) const;
  unsigned int getAttackDamage(void) const;

  void setName(const std::string);
  void setHitPoints(const unsigned int);
  void setEnergyPoints(const unsigned int);
  void setAttackDamage(const unsigned int);

 public:
  ClapTrap(void);
  ClapTrap(const std::string&);
  ~ClapTrap(void);
  ClapTrap(const ClapTrap&);

  ClapTrap& operator=(const ClapTrap&);

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void printStatus(void) const;
};

#endif
