/**
 * @file Karen.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions of Karen class members
 * @date 2022-02-26
 */

#include "Karen.hpp"

// Karen class constructor
Karen::Karen(void) {
  std::cout << "An instance of Karen class is constructed\n";
}

// Karen class destructor
Karen::~Karen(void) {
  std::cout << "An instance of Karen class is destructed\n";
}

// private members
void Karen::debug(void) {
  std::cout << GREEN << "[DEBUG]\n"
            << "I love to get extra bacon for my "
               "7XL-double-cheese-triple-pickle-special-ketchup burger. I just "
               "love it!\n"
            << RESET;
}

void Karen::info(void) {
  std::cout << BLUE << "[INFO]\n"
            << "I cannot believe adding extra bacon cost more money. You don’t "
               "put enough! If you did I would not have to ask for it!\n"
            << RESET;
}

void Karen::warning(void) {
  std::cout << YELLOW << "[WARNING]\n"
            << "I think I deserve to have some extra bacon for free. I’ve been "
               "coming here for years and you just started working here last "
               "month.\n"
            << RESET;
}

void Karen::error(void) {
  std::cout << RED << "[ERROR]\n"
            << "This is unacceptable, I want to speak to the manager now.\n"
            << RESET;
}

// complain
void Karen::complain(std::string level) {
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  void (Karen::*f[4])() = {&Karen::debug, &Karen::info, &Karen::warning,
                           &Karen::error};

  for (int k = 0; k < 4; k++) {
    if (levels[k] == level) {
      (this->*f[k])();
      return;
    }
  }
  std::cout << "INVALID LOG LEVEL\n";
}