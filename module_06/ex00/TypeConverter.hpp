/**
 * @file TypeConverter.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A header file for TypeConverter class
 * @date 2022-04-15
 */

#ifndef TYPECONVERTER_HPP
#define TYPECONVERTER_HPP

#include <exception>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

enum Types { kChar, kInt, kFloat, kDouble, kNa };

class TypeConverter {
 private:
  std::string param_;
  size_t len_;
  int type_;
  char in_char_;
  long in_int_;
  float in_float_;
  double in_double_;

  size_t countOccurrence_(const std::string&);
  int detectType_(void);
  void convertChar_(void);
  void convertInt_(void);
  void convertFloat_(void);
  void convertDouble_(void);
  void printChar_(void);
  void printInt_(void);
  void printFloat_(void);
  void printDouble_(void);

 public:
  TypeConverter(void);
  TypeConverter(const std::string&);
  ~TypeConverter(void);
  TypeConverter(const TypeConverter&);

  TypeConverter& operator=(const TypeConverter&);

  std::string getParam(void) const;
  int getType(void) const;
  char getInChar(void) const;
  int getInInt(void) const;
  float getInFloat(void) const;
  double getInDouble(void) const;

  void convert(void);
};

#endif
