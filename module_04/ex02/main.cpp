/**
 * @file main.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Tests for abstract class
 * @date 2022-04-07
 */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  // const Animal* meta = new Animal();

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();
  j->makeSound();
  delete j;
  delete i;

  return EXIT_SUCCESS;
}
