/**
 * @file HumanA.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A header file for HumanA class
 * @date 2022-02-26
 */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanA {
 private:
  std::string name_;
  Weapon &weapon_;

 public:
  HumanA(const std::string, Weapon &);
  ~HumanA(void);
  void attack(void) const;
};

#endif
