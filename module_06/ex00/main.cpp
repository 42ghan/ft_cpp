/**
 * @file main.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Conversion of scalar types
 * @date 2022-04-15
 */

#include "TypeConverter.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "* Error : wrong number of arguments *\n";
    return EXIT_FAILURE;
  }
  std::string param = argv[1];
  TypeConverter tc(param);
  tc.convert();
  return EXIT_SUCCESS;
}
