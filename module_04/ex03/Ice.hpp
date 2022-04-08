/**
 * @file Ice.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief
 * @date 2022-04-08
 */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
 public:
  Ice(void);
  ~Ice(void);
  Ice(const Ice&);

  Ice& operator=(const Ice&);

  Ice* clone(void) const;
  void use(ICharacter&);
};

#endif
