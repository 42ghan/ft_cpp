/**
 * @file main.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A phonebook program that can store upto 8 contacts
 * @date 2022-02-22
 */

#include "PhoneBook.hpp"

int main(void) {
  std::string input;
  PhoneBook phone_book;

  while (input != "EXIT") {
    if (input != "EXIT") {
      std::cout << GREEN << BOLD << "write command > " << RESET;
      std::getline(std::cin, input);
    }
    if (input == "ADD")
      phone_book.AddContact();
    else if (input == "SEARCH") {
      phone_book.DisplayContacts();
      phone_book.DisplayDetails();
    }
  }
  if (input == "EXIT") return (EXIT_SUCCESS);
  std::cout << input;
  return (EXIT_SUCCESS);
}