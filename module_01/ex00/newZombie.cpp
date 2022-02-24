/**
 * @file newZombie.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definition of newZombie function
 * @date 2022-02-24
 */

#include "Zombie.hpp"

// allocate a zombie object and return the allocated object
Zombie *newZombie(std::string name) { return new Zombie(name); }
