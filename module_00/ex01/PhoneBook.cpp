/**
 * @file Contact.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions of PhoneBook class member functions
 * @date 2022-02-23
 */

#include "PhoneBook.hpp"

// PhoneBook class constructor
PhoneBook::PhoneBook(void) : no_entries_(0) {}

// PhoneBook class destructor
PhoneBook::~PhoneBook(void) {}

// add a contact to the phonebook's contact list
void PhoneBook::AddContact(void) {
  const std::string field_names[5] = {"first name", "last name", "nick name",
                                      "phone number", "darkest secret"};
  std::string fields[5];

  std::cout << YELLOW << BOLD << "Fill information for a new contact\n"
            << RESET;
  for (int i = 0; i < 5; i++) {
    std::cout << "  " << field_names[i] << " : ";
    std::getline(std::cin, fields[i]);
    if (std::cin.eof())
      return;
    else if (!fields[i].length()) {
      std::cout << field_names[i] << " field cannot be empty\n";
      return;
    }
  }

  int idx = 0;
  if (this->no_entries_ != 8) idx = this->no_entries_++;
  this->contacts_[idx].FillContact(fields);
}

// display contacts when SEARCH command is executed
void PhoneBook::DisplayContacts(void) const {
  std::cout << " ---------- ---------- ---------- ---------- \n"
            << '|' << std::setw(10) << "index"
            << "|" << std::setw(10) << "first name"
            << "|" << std::setw(10) << "last name"
            << "|" << std::setw(10) << "nickname"
            << "|\n";
  for (int k = 0; k < this->no_entries_; k++) {
    std::string fields[3] = {this->contacts_[k].GetFirstName(),
                             this->contacts_[k].GetLastName(),
                             this->contacts_[k].GetNickname()};
    for (int l = 0; l < 3; l++) {
      if (fields[l].size() > 10) {
        fields[l].at(9) = '.';
        fields[l] = fields[l].erase(10);
      }
    }
    std::cout << " ---------- ---------- ---------- ---------- \n"
              << '|' << std::setw(10) << k << "|" << std::setw(10) << fields[0]
              << "|" << std::setw(10) << fields[1] << "|" << std::setw(10)
              << fields[2] << "|\n";
  }
  std::cout << " ---------- ---------- ---------- ---------- \n\n";
}

// display detailed information about the given index
void PhoneBook::DisplayDetails(void) const {
  std::string input;
  int input_flag = 0;

  std::cout << L_BLUE
            << "Write the index of the contact you want to check more detailed "
               "information of\n ==> "
            << RESET;
  while (!input_flag) {
    std::getline(std::cin, input);
    if (std::cin.eof()) return;
    if (input.size() == 1 && input[0] >= '0' && input[0] <= '7')
      input_flag = 1;
    else
      std::cout << L_RED << BOLD
                << "WRONT INPUT! Please write a number between 0 and 7\n"
                << L_BLUE << "==> " << RESET;
  }

  int idx;
  std::stringstream ss;

  ss.str(input);
  ss >> idx;
  if (idx + 1 > this->no_entries_) {
    std::cout << "  The requested contact is empty\n";
  } else {
    std::cout << BOLD << "Contact #" << input << RESET << '\n'
              << "  first name : " << this->contacts_[idx].GetFirstName()
              << '\n'
              << "  last name : " << this->contacts_[idx].GetLastName() << '\n'
              << "  nickname : " << this->contacts_[idx].GetNickname() << '\n'
              << "  phone number : " << this->contacts_[idx].GetPhoneNumber()
              << '\n'
              << "  darkest secret : "
              << this->contacts_[idx].GetDarkestSecret() << '\n';
  }
}

// search phone book entries
void PhoneBook::SearchPhoneBook(void) const {
  if (!this->no_entries_) {
    std::cout << "  Phone book is empty. Please add new contacts\n";
    return;
  }
  this->DisplayContacts();
  if (this->no_entries_) this->DisplayDetails();
}
