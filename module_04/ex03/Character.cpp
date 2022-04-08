/**
 * @file Character.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief
 * @date 2022-04-08
 */

#include "Character.hpp"

// default constructor
Character::Character(void) {
  for (int i = 0; i < 4; i++) slot_[i] = NULL;
  std::cout << L_GREEN << "Default constructor (Character)\n" << RESET;
}

// destructor
Character::~Character(void) {
  std::cout << L_RED << "An instance of Character has been destroyed\n"
            << RESET;
}

// constructor with given name
Character::Character(const std::string& name) : name_(name) {
  for (int i = 0; i < 4; i++) slot_[i] = NULL;
  std::cout << L_GREEN << "Character " << name << " has been constructed\n"
            << RESET;
}

// copy constructor
Character::Character(const Character& original) {
  *this = original;
  std::cout << L_GREEN << "Copy constructor (Character)\n" << RESET;
}

// = operator overload
Character& Character::operator=(const Character& rhs) {
  const AMateria* rhs_slot = rhs.getSlot();

  name_ = rhs.getName();
  for (int i = 0; i < 4; i++) {
    delete slot_[i];
    slot_[i] = NULL;
    if (rhs_slot + i != NULL)
      slot_[i] = rhs_slot[i].getType() == "ice" ? new Ice(rhs_slot[i])
                                                : new Cure(rhs_slot[i]);
  }
}

// getters
const std::string& Character::getName(void) const { return name_; }

const AMateria* Character::getSlot(void) const { return slot_; };

// equip, unequip & use
void Character::equip(AMateria* m) {
  static int idx;
  slot_[idx++] = m;
  if (idx == 4) idx = 0;
}

void Character::unequip(int idx) { delete slot_[idx]; }

void Character::use(int idx, Character& target) { slot_[idx]->use(target); }