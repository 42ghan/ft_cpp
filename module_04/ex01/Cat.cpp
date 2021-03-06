/**
 * @file Cat.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions for member functions of Cat class
 * @date 2022-04-07
 */

#include "Cat.hpp"

// default constructor
Cat::Cat(void) : brain_(new Brain()) {
  type_ = "Cat";
  std::cout << L_GREEN << "Default constructor (Cat)\n" << RESET;
}

// destructor
Cat::~Cat(void) {
  delete brain_;
  std::cout << L_RED << "An instance of Cat class is destroyed\n" << RESET;
}

// copy constructor
Cat::Cat(const Cat& original) : brain_(new Brain()) {
  *this = original;
  std::cout << L_GREEN << "Copy constructor (Cat)\n" << RESET;
}

// = operator overload
Cat& Cat::operator=(const Cat& rhs) {
  type_ = rhs.type_;
  brain_->setIdeas(rhs.brain_->getIdeas());
  return *this;
}

// make sound override
void Cat::makeSound(void) const { std::cout << "Meow Meow!\n"; }

// getter
Brain* Cat::getBrain(void) const { return brain_; }
