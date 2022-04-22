/**
 * @file Cure.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief
 * @date 2022-04-08
 */

#ifndef Cure_HPP
#define Cure_HPP

#include "AMateria.hpp"
#include "Character.hpp"

class Cure : public AMateria {
 public:
  Cure(void);
  virtual ~Cure(void);
  Cure(const Cure&);

  Cure& operator=(const Cure&);

  Cure* clone(void) const;
  void use(ICharacter&);
};

#endif
