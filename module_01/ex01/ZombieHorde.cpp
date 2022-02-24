/**
 * @file ZombieHorde.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Create a horde of zombies
 * @date 2022-02-24
 */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
  Zombie *horde = new Zombie[N];

  for (int idx = 0; idx < N; idx++) {
    std::stringstream ss;
    ss << idx;
    horde[idx].setName(name + ss.str());
  }
  return horde;
}
