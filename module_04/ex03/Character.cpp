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
  for (int i = 0; i < 4; i++) delete slot_[i];
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
  name_ = rhs.name_;

  for (int i = 0; i < 4; i++) {
    delete slot_[i];
    slot_[i] = NULL;
    if (rhs.slot_ + i != NULL) slot_[i] = rhs.slot_[i]->clone();
  }
  return *this;
}

// getters
const std::string& Character::getName(void) const { return name_; }

// equip, unequip & use
void Character::equip(AMateria* m) {
  for (int i = 0; i < 4; i++) {
    if (slot_[i] == NULL) {
      slot_[i] = m;
      return;
    }
  }
  std::cout << name_ << "'s slot is full!\n";
  delete m;
}

void Character::unequip(int idx) {
  if (idx < 0 || idx > 3) {
    std::cout << "The given index is out of range\n";
    return;
  }
  delete slot_[idx];
  slot_[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
  if (idx < 0 || idx > 3) {
    std::cout << "The given index is out of range\n";
    return;
  }
  if (slot_[idx] == NULL) {
    std::cout << "the selected index of Materia slot is empty! Use another "
                 "Materia!\n";
    return;
  }
  slot_[idx]->use(target);
}
