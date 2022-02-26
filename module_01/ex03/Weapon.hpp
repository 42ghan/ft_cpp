/**
 * @file Weapon.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A header file for Weapon class
 * @date 2022-02-26
 */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

/* ANSI CODES FOR TEXT DECORATION */
#define GREEN "\033[32m"
#define L_GREEN "\033[1;32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define L_RED "\033[1;31m"
#define BLUE "\033[34m"
#define L_BLUE "\033[1;34m"
#define PURPLE "\033[35m"
#define L_PURPLE "\033[1;35m"
#define MUTED "\033[130m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define UP "\033[A"
#define DOWN "\033[B"
#define RIGHT "\033[C"
#define LEFT "\033[D"
#define CUT "\033[K"
#define SAVE "\033[s"
#define RESTORE "\033[u"

class Weapon {
 private:
  std::string type_;

 public:
  Weapon(std::string);
  ~Weapon(void);
  const std::string& getType(void) const;
  void setType(std::string);
};

#endif
