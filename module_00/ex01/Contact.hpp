/**
 * @file Contact.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A header file for Contact class
 * @date 2022-02-23
 */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
 private:
  std::string first_name_;
  std::string last_name_;
  std::string nickname_;
  std::string phone_number_;
  std::string darkest_secret_;

 public:
  Contact(void);
  ~Contact(void);
  std::string GetFirstName(void);
  std::string GetLastName(void);
  std::string GetNickname(void);
  std::string GetPhoneNumber(void);
  std::string GetDarkestSecret(void);
  void SetFirstName(std::string);
  void SetLastName(std::string);
  void SetNickname(std::string);
  void SetPhoneNumber(std::string);
  void SetDarkestSecret(std::string);
  void FillContact(std::string[]);
};

#endif