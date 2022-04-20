/**
 * @file Animal.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A header file for Animal class
 * @date 2022-04-07
 */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

#include "color.hpp"

class Animal {
 protected:
  std::string type_;

 public:
  Animal(void);
  virtual ~Animal(void) = 0;
  Animal(const Animal&);

  Animal& operator=(const Animal&);
  std::string getType() const;

  virtual void makeSound(void) const = 0;
};

#endif
