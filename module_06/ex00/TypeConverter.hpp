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
#include <sstream>
#include <string>

enum Types { kChar, kInt, kFloat, kDouble, kNa };

class TypeConverter {
 private:
  std::string param_;
  int type_;
  char in_char_;
  int in_int_;
  float in_float_;
  double in_double_;

  size_t countOccurrence_(const std::string&);
  int detectType_(const size_t);
  void initActualType_(void);

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
