/**
 * @file ScavTrap.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A header file for ScavTrap class
 * @date 2022-04-06
 */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>

#include "ClapTrap.hpp"
#include "color.hpp"

class ScavTrap : virtual public ClapTrap {
 public:
  ScavTrap(void);
  ScavTrap(const std::string&);
  ~ScavTrap(void);
  ScavTrap(const ScavTrap&);

  ScavTrap& operator=(const ScavTrap&);

  void guardGate(void);
  void attack(const std::string& target);
};

#endif