/**
 * @file TypeConverter.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Definitions of member functions of TypeConverter class
 * @date 2022-04-15
 */

#include "TypeConverter.hpp"

// default constructor
TypeConverter::TypeConverter(void) {}

// destructor
TypeConverter::~TypeConverter(void) {}

// constructor with a given param
TypeConverter::TypeConverter(const std::string& param)
    : param_(param), len_(param.length()) {}

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
  return *this;
}

// getters
std::string TypeConverter::getParam(void) const { return param_; }

int TypeConverter::getType(void) const { return type_; }

char TypeConverter::getInChar(void) const { return in_char_; }

int TypeConverter::getInInt(void) const { return in_int_; }

float TypeConverter::getInFloat(void) const { return in_float_; }

double TypeConverter::getInDouble(void) const { return in_double_; }

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
int TypeConverter::detectType_(void) {
  if (len_ == 1) {
    if (param_.at(0) >= '0' && param_.at(0) <= '9') return kInt;
    return kChar;
  }
  if (param_ == "-inff" || param_ == "+inff" || param_ == "nanf") return kFloat;
  if (param_ == "-inf" || param_ == "+inf" || param_ == "nan") return kDouble;
  size_t idx = (param_.at(0) == '-' || param_.at(0) == '+') ? 1 : 0;
  size_t cnt_dot = countOccurrence_(".");
  if (!cnt_dot) {
    for (; idx < len_; idx++)
      if (param_.at(idx) < '0' || param_.at(idx) > '9') return kNa;
    return kInt;
  } else if (cnt_dot == 1) {
    bool is_dot = false;
    bool is_num = false;
    for (; idx < len_; idx++) {
      if (param_.at(idx) == '.') {
        is_dot = true;
        continue;
      }
      if (is_dot && is_num && param_.at(idx) == 'f' && idx + 1 == len_)
        return kFloat;
      if (param_.at(idx) < '0' || param_.at(idx) > '9') return kNa;
      is_num = true;
    }
    return kDouble;
  }
  return kNa;
}

// PRIVATE : converters for each actual type
void TypeConverter::convertChar_(void) {
  in_int_ = static_cast<int>(in_char_);
  in_float_ = static_cast<float>(in_char_);
  in_double_ = static_cast<double>(in_char_);

  printChar_();
  std::cout << "int: " << in_int_ << "\n";
  std::cout << "float: " << in_float_ << ".0f\n";
  std::cout << "double: " << in_double_ << ".0\n";
}

void TypeConverter::convertInt_(void) {
  in_char_ = static_cast<char>(in_int_);
  in_float_ = static_cast<float>(in_int_);
  in_double_ = static_cast<double>(in_int_);

  if (in_int_ < -127 || in_int_ > 127)
    std::cout << "char: impossible\n";
  else
    printChar_();
  printInt_();
  printFloat_();
  printDouble_();
}

void TypeConverter::convertFloat_(void) {
  in_char_ = static_cast<char>(in_float_);
  in_int_ = static_cast<int>(in_float_);
  in_double_ = static_cast<double>(in_float_);

  if (in_int_ < -127 || in_int_ > 127)
    std::cout << "char: impossible\n";
  else
    printChar_();
  printInt_();
  printFloat_();
  printDouble_();
}

void TypeConverter::convertDouble_(void) {
  in_char_ = static_cast<char>(in_double_);
  in_int_ = static_cast<int>(in_double_);
  in_float_ = static_cast<float>(in_double_);

  if (in_int_ < -127 || in_int_ > 127)
    std::cout << "char: impossible\n";
  else
    printChar_();
  printInt_();
  printFloat_();
  printDouble_();
}

// PRIVATE : check limits and print each type
void TypeConverter::printChar_(void) {
  if (in_char_ >= 32 && in_char_ <= 126)
    std::cout << "char: " << in_char_ << "\n";
  else
    std::cout << "char: Non displayble\n";
}

void TypeConverter::printInt_(void) {
  if (param_ == "nan" || param_ == "+inf" || param_ == "-inf" ||
      param_ == "nanf" || param_ == "+inff" || param_ == "-inff" ||
      param_.substr(0, param_.find(".")).length() > 11 ||
      in_int_ > std::numeric_limits<int>::max() ||
      in_int_ < std::numeric_limits<int>::min())
    std::cout << "int: impossible\n";
  else
    std::cout << "int: " << in_int_ << "\n";
}

void TypeConverter::printFloat_(void) {
  if (param_ == "nan" || param_ == "nanf")
    std::cout << "float: nanf\n";
  else if (param_ == "+inf" || param_ == "+inff")
    std::cout << "float: +inff\n";
  else if (param_ == "-inf" || param_ == "-inff")
    std::cout << "float: -inff\n";
  else if (in_float_ > std::numeric_limits<float>::max())
    std::cout << "float: +inff\n";
  else if (in_float_ < -1 * std::numeric_limits<float>::max())
    std::cout << "float: -inff\n";
  else {
    std::stringstream ss;
    ss << in_float_;
    std::string float_in_str = ss.str();
    if (float_in_str.find(".") == std::string::npos) float_in_str += ".0";
    std::cout << "float: " << float_in_str << "f\n";
  }
}

void TypeConverter::printDouble_(void) {
  if (param_ == "nan" || param_ == "nanf")
    std::cout << "double: nan\n";
  else if (param_ == "+inf" || param_ == "+inff")
    std::cout << "double: +inf\n";
  else if (param_ == "-inf" || param_ == "-inff")
    std::cout << "double: -inf\n";
  else if (in_double_ > std::numeric_limits<double>::max())
    std::cout << "double: +inf\n";
  else if (in_double_ < -1 * std::numeric_limits<double>::max())
    std::cout << "double: -inf\n";
  else {
    std::stringstream ss;
    ss << in_double_;
    std::string double_in_str = ss.str();
    if (double_in_str.find(".") == std::string::npos) double_in_str += ".0";
    std::cout << "double: " << double_in_str << "\n";
  }
}

// init actual type and convert
void TypeConverter::convert(void) {
  if (!len_) {
    std::cout << "* Error : an empty parameter is not acceptable *\n";
    return;
  }
  type_ = detectType_();
  std::stringstream ss;
  if (type_ == kFloat)
    ss.str(param_.substr(0, len_ - 1));
  else
    ss.str(param_);
  switch (type_) {
    case kChar:
      in_char_ = param_[0];
      convertChar_();
      break;
    case kInt:
      ss >> in_int_;
      convertInt_();
      break;
    case kFloat:
      ss >> in_float_;
      convertFloat_();
      break;
    case kDouble:
      ss >> in_double_;
      convertDouble_();
      break;
    default:
      std::cout << "* Error : no matching type *\n";
      return;
  }
}
