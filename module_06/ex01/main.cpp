/**
 * @file main.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Serialization
 * @date 2022-04-15
 */

#include <iostream>

#include "Data.hpp"

uintptr_t serialize(Data*);
Data* deserialize(uintptr_t);

int main(void) {
  Data data;

  data.name = "Daniel";
  data.age = 23;
  data.hobby = "table tennis";

  Data* data_ptr = deserialize(serialize(&data));

  std::cout << "name : " << data_ptr->name << "; age : " << data_ptr->age
            << "; hobby : " << data_ptr->hobby << "\n";
}
