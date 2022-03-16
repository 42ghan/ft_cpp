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
std::string Contact::GetFirstName(void) const { return this->first_name_; }

std::string Contact::GetLastName(void) const { return this->last_name_; }

std::string Contact::GetNickname(void) const { return this->nickname_; }

std::string Contact::GetPhoneNumber(void) const { return this->phone_number_; }

std::string Contact::GetDarkestSecret(void) const {
  return this->darkest_secret_;
}

// Contact class setters
void Contact::SetFirstName(const std::string input) {
  this->first_name_ = input;
}

void Contact::SetLastName(const std::string input) { this->last_name_ = input; }

void Contact::SetNickname(const std::string input) { this->nickname_ = input; }

void Contact::SetPhoneNumber(const std::string input) {
  this->phone_number_ = input;
}

void Contact::SetDarkestSecret(const std::string input) {
  this->darkest_secret_ = input;
}

// fill a contact at once
void Contact::FillContact(const std::string fields[]) {
  this->SetFirstName(fields[0]);
  this->SetLastName(fields[1]);
  this->SetNickname(fields[2]);
  this->SetPhoneNumber(fields[3]);
  this->SetDarkestSecret(fields[4]);
}
