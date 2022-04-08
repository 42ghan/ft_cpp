/**
 * @file Brain.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A header file for Brain class
 * @date 2022-04-07
 */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

#include "color.hpp"

class Brain {
 private:
  std::string ideas_[100];

 public:
  Brain(void);
  virtual ~Brain(void);
  Brain(const Brain&);

  Brain& operator=(const Brain&);

  const std::string* getIdeas(void) const;
  void setIdeas(const std::string*);
};

#endif
