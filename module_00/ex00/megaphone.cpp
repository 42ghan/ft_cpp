/**
 * @file megaphone.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A program that capitalize all small cases letters
 * @date 2022-02-19
 */

#include <iostream>
#include <string>

int main(int argc, char **argv) {
  if (argc == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  else {
    for (int i = 1; i < argc; i++) {
      std::string arg = argv[i];
      const int len = arg.length();
      for (int k = 0; k < len; k++) {
        arg[k] = std::toupper(arg[k]);
      }
      std::cout << arg;
    }
  }
  std::cout << '\n';
  return EXIT_SUCCESS;
}
