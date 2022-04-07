/**
 * @file WrongCat.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A header file for WrongCat class
 * @date 2022-04-07
 */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include <string>

#include "WrongAnimal.hpp"
#include "color.hpp"

class WrongCat : public WrongAnimal {
 public:
  WrongCat(void);
  ~WrongCat(void);
  WrongCat(const WrongCat&);

  WrongCat& operator=(const WrongCat&);
  void makeSound(void) const;
};

#endif
