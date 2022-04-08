/**
 * @file Cat.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A header file for Cat class
 * @date 2022-04-07
 */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Brain.hpp"
#include "color.hpp"

class Cat : public Animal {
 private:
  Brain* brain_;

 public:
  Cat(void);
  ~Cat(void);
  Cat(const Cat&);

  Cat& operator=(const Cat&);
  void makeSound(void) const;
  Brain* getBrain(void) const;
};

#endif
