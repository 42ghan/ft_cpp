/**
 * @file HumanB.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A header file for HumanB class
 * @date 2022-02-26
 */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanB {
 private:
  std::string name_;
  Weapon *weapon_;

 public:
  HumanB(const std::string);
  ~HumanB(void);
  void attack(void) const;
  void setWeapon(Weapon &);
};

#endif
