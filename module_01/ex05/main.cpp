/**
 * @file main.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Karen logger
 * @date 2022-03-01
 */

#include "Karen.hpp"

int main(void) {
  Karen karen;

  karen.complain("DEBUG");
  karen.complain("INFO");
  karen.complain("WARNING");
  karen.complain("ERROR");
  karen.complain("blah");
  return EXIT_SUCCESS;
}