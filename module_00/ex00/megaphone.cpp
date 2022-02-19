/**
 * @file megaphone.cpp
 * @author ghan
 * @date 2022-02-19
 */

#include <cctype>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  if (argc == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  else {
    for (int i = 1; i < argc; i++) {
      std::string arg = argv[i];
      for (int k = 0; arg[k]; k++) {
        arg[k] = toupper(arg[k]);
      }
      std::cout << arg;
    }
  }
  std::cout << std::endl;
  return (EXIT_SUCCESS);
}
