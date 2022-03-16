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
  void SetFirstName(const std::string);
  void SetLastName(const std::string);
  void SetNickname(const std::string);
  void SetPhoneNumber(const std::string);
  void SetDarkestSecret(const std::string);

 public:
  Contact(void);
  ~Contact(void);
  std::string GetFirstName(void) const;
  std::string GetLastName(void) const;
  std::string GetNickname(void) const;
  std::string GetPhoneNumber(void) const;
  std::string GetDarkestSecret(void) const;
  void FillContact(const std::string[]);
};

#endif