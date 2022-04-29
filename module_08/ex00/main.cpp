/**
 * @file main.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Find the first occurrence in all types of sequential containers
 * @date 2022-04-18
 */

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

int main(void) {
  try {
    std::cout << "====== VECTOR ======\n";
    std::vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    std::cout << "VEC : [";
    for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end();
         ++itr) {
      std::cout << ' ' << *itr;
      if (itr + 1 != vec.end()) std::cout << ',';
    }
    std::cout << " ]\n";

    std::vector<int>::iterator itr = easyfind<std::vector<int> >(vec, 3);
    std::cout << *itr << " is in the container\n";
    itr = easyfind<std::vector<int> >(vec, 8);
    std::cout << *itr << " is in the container\n";
  } catch (const std::exception& e) {
    std::cout << e.what();
  }

  try {
    std::cout << "====== LIST ======\n";
    std::list<int> lst;

    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);

    std::cout << "LIST : [";
    for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
      std::cout << ' ' << *itr;
      std::list<int>::iterator cpy = itr;
      if (++cpy != lst.end()) std::cout << ',';
    }
    std::cout << " ]\n";

    std::list<int>::iterator itr = easyfind<std::list<int> >(lst, 3);
    std::cout << *itr << " is in the container\n";
    itr = easyfind<std::list<int> >(lst, 8);
    std::cout << *itr << " is in the container\n";
  } catch (const std::exception& e) {
    std::cout << e.what();
  }

  try {
    std::cout << "====== DEQUE ======\n";
    std::deque<int> deque;

    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);
    deque.push_back(4);

    std::cout << "DEQUE : [";
    for (std::deque<int>::iterator itr = deque.begin(); itr != deque.end();
         ++itr) {
      std::cout << ' ' << *itr;
      std::deque<int>::iterator cpy = itr;
      if (++cpy != deque.end()) std::cout << ',';
    }
    std::cout << " ]\n";

    std::deque<int>::iterator itr = easyfind<std::deque<int> >(deque, 3);
    std::cout << *itr << " is in the container\n";
    itr = easyfind<std::deque<int> >(deque, 8);
    std::cout << *itr << " is in the container\n";
  } catch (const std::exception& e) {
    std::cout << e.what();
  }

  return EXIT_SUCCESS;
}
