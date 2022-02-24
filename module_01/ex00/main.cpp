/**
 * @file main.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief BraiiiiiiinnnzzzZ
 * @date 2022-02-24
 */

#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main(void) {
  Zombie zombie_stack("ghan");
  Zombie *zombie_heap = newZombie("jiskim");

  zombie_stack.announce();
  zombie_heap->announce();
  randomChump("yongjule");
  delete zombie_heap;
  return EXIT_SUCCESS;
}