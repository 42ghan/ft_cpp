/**
 * @file main.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief
 * @date 2022-03-01
 */

#include "Karen.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Wrong number of arguments\n";
    return EXIT_FAILURE;
  }

  Karen karen;

  karen.complain(argv[1]);
}