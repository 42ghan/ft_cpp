/**
 * @file ICharacter.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A header file for ICharacter class
 * @date 2022-04-08
 */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>

#include "AMateria.hpp"

class ICharacter {
 public:
  virtual ~ICharacter(void){};
  virtual const std::string& getName(void) const = 0;
  virtual void equip(AMateria* m) = 0;
  virtual void unequip(int idx) = 0;
  virtual void use(int idx, ICharacter& target) = 0;
};

#endif
