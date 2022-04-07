/**
 * @file main.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Tests for Polymorphism
 * @date 2022-04-07
 */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();
  j->makeSound();
  meta->makeSound();
  delete j;
  delete i;
  delete meta;

  std::cout << "========== WRONG VERSION ==========\n";

  const WrongAnimal* wrong_meta = new WrongAnimal();
  const WrongAnimal* k = new WrongCat();

  std::cout << k->getType() << " " << std::endl;
  k->makeSound();
  wrong_meta->makeSound();
  delete k;
  delete wrong_meta;

  return EXIT_SUCCESS;
}
