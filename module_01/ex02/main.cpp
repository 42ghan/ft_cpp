/**
 * @file main.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Practice using references
 * @date 2022-02-26
 */

#include <iostream>
#include <string>

void ChangeReference(std::string &str_test) {
  std::cout << "STRING ADDRESS (REF) : " << &str_test << '\n';
  str_test = "NEW STRING";
}

int main(void) {
  std::string str = "HI THIS IS BRAIN";
  std::string &stringREF = str;
  std::string *stringPTR = &str;

  // address of str
  std::cout << "STRING'S ADDRESS : " << &str << '\n';
  std::cout << "STRING'S ADDRESS (PTR) : " << stringPTR << '\n';
  std::cout << "STRING'S ADDRESS (REF) : " << &stringREF << '\n';

  // value of str
  std::cout << "STRING VALUE : " << str << '\n';
  std::cout << "STRING VALUE (PTR) : " << *stringPTR << '\n';
  std::cout << "STRING VALUE (REF) : " << stringREF << '\n';

  std::cout << "\n==============================================\n\n";

  std::string test = "OLD STRING";
  std::string &testREF = test;

  std::cout << "STRING ITSELF : " << test << '\n';
  std::cout << "STRING REF : " << testREF << '\n';

  std::cout << "STRING ADDRESS : " << &test << '\n';
  ChangeReference(testREF);

  std::cout << "STRING ITSELF : " << test << '\n';
  std::cout << "STRING REF : " << testREF << '\n';

  return EXIT_SUCCESS;
}