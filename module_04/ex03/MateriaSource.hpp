/**
 * @file MateriaSource.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief
 * @date 2022-04-08
 */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
 private:
  AMateria *srcs_;

 public:
  MateriaSource(void);
  ~MateriaSource(void);
  MateriaSource(const MateriaSource &);

  MateriaSource &operator=(const MateriaSource &);

  void learnMateria(AMateria *);
  AMateria *createMateria(const std::string &);
};

#endif
