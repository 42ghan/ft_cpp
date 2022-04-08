/**
 * @file AMateria.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A header file for AMateria class
 * @date 2022-04-08
 */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

#include "color.hpp"

class ICharacter;

class AMateria {
 protected:
  std::string type_;

 public:
  AMateria(void);
  AMateria(const std::string&);
  virtual ~AMateria(void) = 0;
  AMateria(const AMateria&);

  AMateria& operator=(const AMateria&);

  const std::string& getType(void) const;
  void setType(const std::string&);

  virtual AMateria* clone(void) const = 0;
  virtual void use(ICharacter& target) = 0;
};

#endif
