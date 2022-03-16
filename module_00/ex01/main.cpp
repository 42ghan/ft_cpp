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

  while (input != "EXIT" && !std::cin.eof()) {
    if (input != "EXIT") {
      std::cout << GREEN << BOLD << "write command > " << RESET;
      std::getline(std::cin, input);
    }
    if (input == "ADD")
      phone_book.AddContact();
    else if (input == "SEARCH")
      phone_book.SearchPhoneBook();
  }
  if (std::cin.eof()) std::cout << "\nEOF reached\n";
  return EXIT_SUCCESS;
}