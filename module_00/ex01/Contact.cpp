/**
 * @file Contact.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions of Contact class member functions
 * @date 2022-02-23
 */

#include "Contact.hpp"

// Contact class default constructor
Contact::Contact(void) {}

// Contact class destructor
Contact::~Contact(void) {}

// Contact class getters
std::string Contact::GetFirstName(void) { return this->first_name_; }
std::string Contact::GetLastName(void) { return this->last_name_; }
std::string Contact::GetNickname(void) { return this->nickname_; }
std::string Contact::GetPhoneNumber(void) { return this->phone_number_; }
std::string Contact::GetDarkestSecret(void) { return this->darkest_secret_; }

// Contact class setters
void Contact::SetFirstName(std::string input) { this->first_name_ = input; }
void Contact::SetLastName(std::string input) { this->last_name_ = input; }
void Contact::SetNickname(std::string input) { this->nickname_ = input; }
void Contact::SetPhoneNumber(std::string input) { this->phone_number_ = input; }
void Contact::SetDarkestSecret(std::string input) {
  this->darkest_secret_ = input;
}

// Fill a contact at once
void Contact::FillContact(std::string fields[]) {
  this->first_name_ = fields[0];
  this->last_name_ = fields[1];
  this->nickname_ = fields[2];
  this->phone_number_ = fields[3];
  this->darkest_secret_ = fields[4];
}
