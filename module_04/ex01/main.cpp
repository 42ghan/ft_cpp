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
  for (int i = 0; i < 21; i++) animals[21 + i] = new Cat();
  for (int i = 0; i < 42; i++) delete animals[i];

  std::cout << "============= What's in Dog A and B's brain? =============\n";
  const Dog a;
  const Dog b(a);
  const std::string* s1 = a.getBrain()->getIdeas();
  const std::string* s2 = b.getBrain()->getIdeas();
  std::string cpy_test[100];

  for (int i = 0; i < 100; i++) cpy_test[i] = "🐕";

  for (int i = 0; i < 100; i++)
    std::cout << s1[i] << " ----- " << s2[i] << '\n';
  std::cout << "============= cpy test =============\n";
  a.getBrain()->setIdeas(cpy_test);
  for (int i = 0; i < 100; i++)
    std::cout << s1[i] << " ----- " << s2[i] << '\n';

  std::cout << "============= What's in Cat A and B's brain? =============\n";
  const Cat c;
  const Cat d(c);
  const std::string* s3 = c.getBrain()->getIdeas();
  const std::string* s4 = d.getBrain()->getIdeas();

  for (int i = 0; i < 100; i++)
    std::cout << s3[i] << " ----- " << s4[i] << '\n';
  std::cout << "============= cpy test =============\n";
  for (int i = 0; i < 100; i++) cpy_test[i] = "🐈";
  c.getBrain()->setIdeas(cpy_test);
  for (int i = 0; i < 100; i++)
    std::cout << s3[i] << " ----- " << s4[i] << '\n';

  return EXIT_SUCCESS;
}
