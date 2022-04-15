/**
 * @file main.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Conversion of scalar types
 * @date 2022-04-15
 */

#include "TypeConverter.hpp"

int main(int argc, char** argv) {
  std::string param;

  if (argc != 2) {
    std::cout << "* Error : wrong number of arguments *\n";
    return EXIT_FAILURE;
  }
  param = argv[1];
  size_t len = param.length();
  if (!len) {
    std::cout << "* Error : an empty parameter is not acceptable *\n";
    return EXIT_FAILURE;
  }
  int type = DetectType(param, len);

  switch (type) {
    case kChar:
      std::cout << "char!\n";
      break;
    case kInt:
      std::cout << "int!\n";
      break;
    case kFloat:
      std::cout << "float!\n";
      break;
    case kDouble:
      std::cout << "double!\n";
      break;
    default:
      std::cout << "Wrong input!\n";
  }

  return EXIT_SUCCESS;
}
