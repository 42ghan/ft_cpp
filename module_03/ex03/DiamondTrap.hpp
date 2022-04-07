/**
 * @file DiamondTrap.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief
 * @date 2022-04-07
 */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <string>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
 private:
  std::string name_;

 public:
  DiamondTrap(void);
  DiamondTrap(const std::string&);
  ~DiamondTrap(void);
  DiamondTrap(const DiamondTrap&);

  DiamondTrap& operator=(const DiamondTrap&);

  void whoAmI(void);
};

#endif
