#include <string>

#include "iter.hpp"

int main(void) {
  std::cout << "====== int ======\n";
  int int_arr[10];

  for (int i = 0; i < 10; i++) int_arr[i] = i;
  iter(int_arr, 10, printT);

  std::cout << "====== float ======\n";
  float float_arr[10];

  for (int i = 0; i < 10; i++) float_arr[i] = i + .42;
  iter(float_arr, 10, printT);

  std::cout << "====== char ======\n";
  char char_arr[10];

  for (int i = 0; i < 10; i++) char_arr[i] = 'a' + i;
  iter(char_arr, 10, printT);

  std::cout << "====== string ======\n";
  std::string str_arr[10];

  for (int i = 0; i < 10; i++) {
    str_arr[i] = "str";
    str_arr[i] += 'A' + i;
  };
  iter(str_arr, 10, printT);
  return EXIT_SUCCESS;
}
