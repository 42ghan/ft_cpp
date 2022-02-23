#include "PhoneBook.hpp"

// PhoneBook class constructor
PhoneBook::PhoneBook(void) { this->no_entries = 0; }

// PhoneBook class destructor
PhoneBook::~PhoneBook(void) {}

// add a contact to the phonebook's contact list
void PhoneBook::AddContact(void) {
  std::string fields[5];
  std::string field_names[5] = {"first name", "last name", "nick name",
                                "phone number", "darkest secret"};

  std::cout << YELLOW << BOLD << "Fill information for a new contact\n"
            << RESET;
  for (int i = 0; i < 5; i++) {
    std::cout << "  " << field_names[i] << " : ";
    std::getline(std::cin, fields[i]);
  }

  if (this->no_entries == 7) this->no_entries = 0;
  this->contacts[this->no_entries++].FillContact(fields);
}

// display contacts when SEARCH command is executed
void PhoneBook::DisplayContacts(void) {
  std::cout << " ---------- ---------- ---------- ---------- \n"
            << '|' << std::setw(10) << "index"
            << "|" << std::setw(10) << "first name"
            << "|" << std::setw(10) << "last name"
            << "|" << std::setw(10) << "nickname"
            << "|\n";

  for (int k = 0; k < 8; k++) {
    std::string fields[3] = {this->contacts[k].GetFirstName(),
                             this->contacts[k].GetLastName(),
                             this->contacts[k].GetNickname()};
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
void PhoneBook::DisplayDetails(void) {
  std::string input;
  int flag = 0;

  std::cout << L_BLUE
            << "Write the index of the contact you want to check more detailed "
               "information of\n ==> "
            << RESET;
  while (!flag) {
    std::getline(std::cin, input);
    if (input.size() == 1 && input[0] >= '0' && input[0] <= '7')
      flag = 1;
    else
      std::cout << L_RED << BOLD
                << "WRONT INPUT! Please write a number between 0 and 7\n"
                << L_BLUE << "==> " << RESET;
  }

  const int idx = std::stoi(input, nullptr);
  std::cout << BOLD << "Contact #" << input << RESET << '\n'
            << "  first name : " << this->contacts[idx].GetFirstName() << '\n'
            << "  last name : " << this->contacts[idx].GetLastName() << '\n'
            << "  nickname : " << this->contacts[idx].GetNickname() << '\n'
            << "  phone number : " << this->contacts[idx].GetPhoneNumber()
            << '\n'
            << "  darkest secret : " << this->contacts[idx].GetDarkestSecret()
            << '\n';
}
