#include <iostream>

#include "Array.hpp"

#define MAX_VAL 750

void subject(void) {
  Array<int> numbers(MAX_VAL);
  int* mirror = new int[MAX_VAL];

  srand(time(NULL));
  for (int i = 0; i < MAX_VAL; i++) {
    const int value = rand();
    numbers[i] = value;
    mirror[i] = value;
  }

  // SCOPE
  {
    Array<int> tmp = numbers;
    Array<int> test(tmp);
  }

  for (int i = 0; i < MAX_VAL; i++) {
    if (mirror[i] != numbers[i]) {
      std::cerr << "didn't save the same value!!" << std::endl;
    }
  }

  try {
    numbers[-2] = 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    numbers[MAX_VAL] = 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  for (int i = 0; i < MAX_VAL; i++) {
    numbers[i] = rand();
  }

  delete[] mirror;  //
}

void my(void) {
  std::cout << "\n ====== my test ====== \n";
  Array<char> characters(26);
  Array<char> char_empty;

  for (int i = 0; i < 26; i++) {
    characters[i] = 'A' + i;
  }
  std::cout << "Size of Characters Array : " << characters.size() << "\n";

  try {
    characters[26] = '\0';
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  for (int i = 0; i < 26; i++) {
    std::cout << "characters[" << i << "] : " << characters[i] << '\n';
  }
  Array<char> cpy;
  cpy = characters;
  cpy[25] = 'z';
  for (int i = 0; i < 26; i++) {
    std::cout << "original : " << characters[i] << " ------ "
              << "cpy : " << cpy[i] << '\n';
  }
}

int main(void) {
  subject();
  my();
  // system("leaks array");
  return EXIT_SUCCESS;
}
