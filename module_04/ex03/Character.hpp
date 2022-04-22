/**
 * @file Character.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief
 * @date 2022-04-08
 */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>

#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "color.hpp"

class Character : public ICharacter {
 private:
  std::string name_;
  AMateria* slot_[4];

 public:
  Character(void);
  Character(const std::string&);
  virtual ~Character(void);
  Character(const Character&);

  Character& operator=(const Character&);

  const std::string& getName(void) const;

  void equip(AMateria*);
  void unequip(int);

  void use(int, ICharacter&);
};

#endif
