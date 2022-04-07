/**
 * @file FragTrap.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief
 * @date 2022-04-07
 */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
 public:
  FragTrap(void);
  FragTrap(const std::string&);
  ~FragTrap(void);
  FragTrap(const FragTrap&);

  FragTrap& operator=(const FragTrap&);
  void highFivesGuys(void);
};

#endif
