/**
 * @file main.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Create a horde of zombies in heap memory area
 * @date 2022-02-24
 */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main(void) {
  int n = 100;
  Zombie *horde = zombieHorde(n, "yongjule");

  for (int k = 0; k < n; k++) horde[k].announce();
  delete[] horde;
  return EXIT_SUCCESS;
}