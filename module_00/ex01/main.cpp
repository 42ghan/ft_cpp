/**
 * @file main.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @date 2022-02-22
 */

#include "Contact.hpp"
#include "PhoneBook.hpp"

void AddContact(void) {
  std::string fields[5];
  std::string fields;

  for (int i = 0; i < 5; i++) std::getline(std::cin, fields[i]);

  Contact contact(fields[0], fields[1], fields[2], fields[3], fields[4]);
  contact.PrintContact();
}

int main(void) {
  std::string input;

  while (input != "EXIT") {
    if (input != "EXIT") {
      std::cout << "write command > ";
      std::getline(std::cin, input);
    }
    if (input == "ADD")
      AddContact();
    else if (input == "SEARCH")
      std::cout << "SEARCH\n";
    else if (input != "EXIT")
      std::cout << input << ": is not a valid command\n";
  }
  if (input == "EXIT") {
    std::cout << "bye\n";
    return (EXIT_SUCCESS);
  }
  std::cout << input;
  return (EXIT_SUCCESS);
}