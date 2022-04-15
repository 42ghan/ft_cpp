/**
 * @file serialization.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Serialization and deserialization
 * @date 2022-04-15
 */

#include <iostream>

#include "Data.hpp"

uintptr_t serialize(Data* ptr) {
  std::cout << "==== SERIALIZATION ====\n";
  return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
  std::cout << "==== DESERIALIZATION ====\n";
  return reinterpret_cast<Data*>(raw);
}
