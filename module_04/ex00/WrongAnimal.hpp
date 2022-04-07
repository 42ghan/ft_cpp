/**
 * @file WrongAnimal.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A header file for WrongAnimal class
 * @date 2022-04-07
 */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

#include "color.hpp"

class WrongAnimal {
 protected:
  std::string type_;

 public:
  WrongAnimal(void);
  virtual ~WrongAnimal(void);
  WrongAnimal(const WrongAnimal&);

  WrongAnimal& operator=(const WrongAnimal&);
  std::string getType() const;
  void setType(const std::string&);

  void makeSound(void) const;
};

#endif
