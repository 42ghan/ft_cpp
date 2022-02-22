#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
 private:
  std::string first_name_;
  std::string last_name_;
  std::string nick_name_;
  std::string phone_number_;
  std::string darkest_secret_;

 public:
  Contact(std::string, std::string, std::string, std::string, std::string);
  ~Contact();
  void PrintContact() {
    std::cout << this->first_name_ << '\n';
    std::cout << this->last_name_ << '\n';
    std::cout << this->nick_name_ << '\n';
    std::cout << this->phone_number_ << '\n';
    std::cout << this->darkest_secret_ << '\n';
  }
};

#endif