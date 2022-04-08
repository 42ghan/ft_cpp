/**
 * @file MateriaSource.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief
 * @date 2022-04-08
 */

#include "MateriaSource.hpp"

// default constructor
MateriaSource::MateriaSource(void) : idx_(0) {
  for (int i = 0; i < 4; i++) sources_[i] = NULL;
  std::cout << L_GREEN << "Default constructor (MateriaSource)\n" << RESET;
}

// destructor
MateriaSource::~MateriaSource(void) {
  std::cout << L_RED << "An instance of MateriaSource has been destoryed\n"
            << RESET;
}

// copy constructor
MateriaSource::MateriaSource(const MateriaSource& original) {
  *this = original;
  std::cout << L_GREEN << "Copy constructor (MateriaSource)\n" << RESET;
}

// = operator overload
MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
  const AMateria* rhs_sources = rhs.getSources();
  idx_ = rhs.getIdx();

  for (int i = 0; i < 4; i++) {
    delete sources_[i];
    sources_[i] = NULL;
    if (rhs_sources + i != NULL) sources_[i] = rhs_sources[i].clone();
  }
  return *this;
}

// getters
const AMateria* MateriaSource::getSources(void) const { return sources_[0]; }

int MateriaSource::getIdx(void) const { return idx_; }

// learn & create
void MateriaSource::learnMateria(AMateria* m) {
  if (idx_ >= 4) {
    std::cout << "MateriaSources are full!\n";
    return;
  }
  sources_[idx_++] = m;
}

AMateria* MateriaSource::createMateria(const std::string& type) {
  for (int i = 0; i < 4; i++) {
    if (sources_[i] == NULL) continue;
    if (type == sources_[i]->getType()) return sources_[i]->clone();
  }
  return NULL;
}
