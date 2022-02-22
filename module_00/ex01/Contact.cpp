#include "Contact.hpp"

// Contact class constructor
Contact::Contact(std::string a, std::string b, std::string c, std::string d,
                 std::string e)
    : first_name_(a),
      last_name_(b),
      nick_name_(c),
      phone_number_(d),
      darkest_secret_(e) {}

// Contact class destructor
Contact::~Contact() {}
