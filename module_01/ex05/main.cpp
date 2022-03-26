/**
 * @file main.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Harl logger
 * @date 2022-03-01
 */

#include "Harl.hpp"

int main(void) {
  Harl Harl;

  Harl.complain("DEBUG");
  Harl.complain("INFO");
  Harl.complain("WARNING");
  Harl.complain("ERROR");
  Harl.complain("blah");
  return EXIT_SUCCESS;
}