/**
 * @file Brain.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions for member functions of Brain class
 * @date 2022-04-07
 */

#include "Brain.hpp"

// default constructor
Brain::Brain(void) {
  for (int i = 0; i < 100; i++) ideas_[i] = "🤩";
  std::cout << L_GREEN << "Default constructor (Brain)\n" << RESET;
}

// destructor
Brain::~Brain(void) {
  std::cout << L_RED << "An instance of Brain class has been destroyed\n"
            << RESET;
}

// copy constructor
Brain::Brain(const Brain& original) {
  *this = original;
  std::cout << L_GREEN << "Copy constructor (Brain)\n" << RESET;
}

// = operator overload
Brain& Brain::operator=(const Brain& rhs) {
  for (int i = 0; i < 100; i++) ideas_[i] = rhs.ideas_[i];
  return *this;
}

// getter & setter
const std::string* Brain::getIdeas(void) const { return ideas_; }

void Brain::setIdeas(const std::string* new_ideas) {
  for (int i = 0; i < 100; i++) ideas_[i] = new_ideas[i];
}
