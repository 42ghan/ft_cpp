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
  const Animal* animals[42];

  for (int i = 0; i < 21; i++) animals[i] = new Dog();
  for (int k = 0; k < 21; k++) animals[k] = new Dog();

  for (int m = 0; m < 42; m++) delete animals[m];
  return EXIT_SUCCESS;
}
