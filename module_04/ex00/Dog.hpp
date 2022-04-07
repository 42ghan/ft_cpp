/**
 * @file Dog.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A header file for Dog class
 * @date 2022-04-07
 */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>

#include "Animal.hpp"
#include "color.hpp"

class Dog : public Animal {
 public:
  Dog(void);
  ~Dog(void);
  Dog(const Dog&);

  Dog& operator=(const Dog&);
  void makeSound(void) const;
};

#endif
