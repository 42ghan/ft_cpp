/**
 * @file Brain.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions for member functions of Brain class
 * @date 2022-04-07
 */

#include "Brain.hpp"

Brain::Brain(void) {
  std::cout << L_GREEN << "Default constructor (Brain)\n" << RESET;
}

Brain::~Brain(void) {
  std::cout << L_RED << "An instance of Brain class has been destroyed\n"
            << RESET;
}

Brain::Brain(const Brain& original) {
  *this = original;
  std::cout << L_GREEN << "Copy constructor (Brain)\n" << RESET;
}

Brain& Brain::operator=(const Brain& rhs) {
  const std::string* rhs_ideas = rhs.getIdeas();
  for (int i = 0; i < 100; i++) ideas_[i] = rhs_ideas[i];
  return *this;
}

const std::string* Brain::getIdeas(void) const { return ideas_; }
