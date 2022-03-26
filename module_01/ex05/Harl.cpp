/**
 * @file Harl.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions of Harl class members
 * @date 2022-02-26
 */

#include "Harl.hpp"

// Harl class constructor
Harl::Harl(void) { std::cout << "An instance of Harl class is constructed\n"; }

// Harl class destructor
Harl::~Harl(void) { std::cout << "An instance of Harl class is destructed\n"; }

// private members
void Harl::debug(void) {
  std::cout << GREEN << "[DEBUG]\n"
            << "I love to get extra bacon for my "
               "7XL-double-cheese-triple-pickle-special-ketchup burger. I just "
               "love it!\n"
            << RESET;
}

void Harl::info(void) {
  std::cout << BLUE << "[INFO]\n"
            << "I cannot believe adding extra bacon cost more money. You don’t "
               "put enough! If you did I would not have to ask for it!\n"
            << RESET;
}

void Harl::warning(void) {
  std::cout << YELLOW << "[WARNING]\n"
            << "I think I deserve to have some extra bacon for free. I’ve been "
               "coming here for years and you just started working here last "
               "month.\n"
            << RESET;
}

void Harl::error(void) {
  std::cout << RED << "[ERROR]\n"
            << "This is unacceptable, I want to speak to the manager now.\n"
            << RESET;
}

// complain
void Harl::complain(std::string level) {
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning,
                              &Harl::error};

  for (int k = 0; k < 4; k++) {
    if (levels[k] == level) {
      (this->*f[k])();
      return;
    }
  }
  std::cout << "INVALID LOG LEVEL\n";
}