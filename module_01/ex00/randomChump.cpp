/**
 * @file randomChump.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definition of randomChump function
 * @date 2022-02-24
 */

#include "Zombie.hpp"

// create a Zombie in the stack memory area and announce
void randomChump(std::string name) {
  Zombie zombie(name);

  zombie.announce();
}