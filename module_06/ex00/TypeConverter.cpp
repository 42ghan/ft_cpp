/**
 * @file TypeConverter.cpp
 * @author your name (you@domain.com)
 * @brief Definitions of member functions of TypeConverter class
 * @date 2022-04-15
 */

#include "TypeConverter.hpp"

// default constructor
TypeConverter::TypeConverter(void) {}

// destructor
TypeConverter::~TypeConverter(void) {}

// constructor with a given param
TypeConverter::TypeConverter(const std::string& param) : param_(param){};

// copy constructor
TypeConverter::TypeConverter(const TypeConverter& original) {
  *this = original;
}

// = operator overload
TypeConverter& TypeConverter::operator=(const TypeConverter& rhs) {
  param_ = rhs.getParam();
  type_ = rhs.getType();
  in_char_ = rhs.getInChar();
  in_int_ = rhs.getInInt();
  in_float_ = rhs.getInFloat();
  in_double_ = rhs.getInDouble();
}

// getters
std::string getParam(void) const { return param_; }

int getType(void) const { return type_; }

char getInChar(void) const { return in_char_; }

int getInInt(void) const { return in_int_; }

float getInFloat(void) const { return in_float_; }

double getInDouble(void) const { return in_double_; }

// PRIVATE : count occurence of a pattern in param
size_t TypeConverter::countOccurrence_(const std::string& pattern) {
  size_t cnt = 0;
  size_t pos;

  pos = param_.find(pattern);
  while (pos != std::string::npos) {
    cnt++;
    pos = param_.find(pattern, pos + 1);
  }
  return cnt;
}

// PRIVATE : detect type of the given param
int TypeConverter::detectType_(const size_t len) {
  if (len == 1) {
    if (param_.at(0) >= '0' && param_.at(0) <= '9') return kInt;
    return kChar;
  }
  if (param_ == "-inff" || param_ == "+inff" || param_ == "nanf") return kFloat;
  if (param_ == "-inf" || param_ == "+inf" || param_ == "nan") return kDouble;
  size_t idx = (param_.at(0) == '-' || param_.at(0) == '+') ? 1 : 0;
  size_t cnt_dot = CountOccurrence(param_, ".");
  if (!cnt_dot) {
    for (; idx < len; idx++)
      if (param_.at(idx) < '0' || param_.at(idx) > '9') return kNa;
    return kInt;
  } else if (cnt_dot == 1) {
    bool is_dot = false;
    bool is_num = false;
    for (; idx < len; idx++) {
      if (param_.at(idx) == '.') {
        is_dot = true;
        continue;
      }
      if (is_dot && is_num && param_.at(idx) == 'f' && idx + 1 == len)
        return kFloat;
      if (param_.at(idx) < '0' || param_.at(idx) > '9') return kNa;
      is_num = true;
    }
    return kDouble;
  }
  return kNa;
}

// PRIVATE : init actual type
bool TypeConverter::initActualType_(void) {
  size_t len = param_.length();

  if (!len) {
    std::cout << "* Error : an empty parameter is not acceptable *\n";
    return false;
  }
  type_ = detectType_(len);
  stringstream ss;
  ss.str(param_);
  switch (type_) {
    case kChar:
      ss >> in_char_;
      break;
    case kInt:
      ss >> in_int_;
      break;
    case kFloat:
      ss >> in_float_;
      break;
    case kDouble:
      ss >> in_double_;
      break;
    default:
      std::cout << "* Error : no matching type *\n";
      return false;
  }
  return true;
}

// convert and print
void TypeConverter::convert(void) {
  switch (type_) {
    default:
      in_char_
  }
}