/**
 * @file main.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Tests for interface class
 * @date 2022-04-08
 */

#include "Character.hpp"
#include "MateriaSource.hpp"

void leak_check(void) {
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter* me = new Character("me");

  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);

  ICharacter* bob = new Character("bob");

  me->use(0, *bob);
  me->use(1, *bob);

  // test unequip
  me->unequip(1);
  me->use(1, *bob);
  me->use(0, *bob);

  // test full character slot
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  me->use(0, *bob);
  me->use(1, *bob);
  me->use(2, *bob);
  me->use(3, *bob);
  me->use(4, *bob);

  // test full materia src
  src->learnMateria(new Cure());
  src->learnMateria(new Ice());
  src->learnMateria(new Ice());

  delete bob;
  delete me;
  delete src;
}

int main() {
  leak_check();
  // system("leaks interface_and_recap");
  return 0;
}
