#include <sys/time.h>

#include <cstdlib>
#include <exception>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
  struct timeval tv;
  int rand_num;

  gettimeofday(&tv, NULL);
  srand(tv.tv_usec);
  rand_num = rand() % 3;
  if (!rand_num) {
    std::cout << "A has been created!\n";
    return new A();
  } else if (rand_num == 1) {
    std::cout << "B has been created!\n";
    return new B();
  }
  std::cout << "C has been created!\n";
  return new C();
}

void identify(Base* p) {
  Base* check_ptrs[3] = {dynamic_cast<A*>(p), dynamic_cast<B*>(p),
                         dynamic_cast<C*>(p)};
  for (int i = 0; i < 3; i++) {
    if (check_ptrs[i]) {
      switch (i) {
        case 0:
          std::cout << "This object is A (ptr)\n";
          break;
        case 1:
          std::cout << "This object is B (ptr)\n";
          break;
        default:
          std::cout << "This object is C (ptr)\n";
      }
      return;
    }
  }
}

void identify(Base& p) {
  try {
    Base& check_a = dynamic_cast<A&>(p);
    check_a = A();
    std::cout << "This object is A (ref)\n";
    return;
  } catch (std::exception& e) {
  }
  try {
    Base& check_b = dynamic_cast<B&>(p);
    check_b = B();
    std::cout << "This object is B (ref)\n";
    return;
  } catch (std::exception& e) {
  }
  try {
    Base& check_c = dynamic_cast<C&>(p);
    check_c = C();
    std::cout << "This object is C (ref)\n";
    return;
  } catch (std::exception& e) {
  }
}

int main(void) {
  Base* base_ptr = generate();
  identify(base_ptr);
  identify(*base_ptr);
  delete base_ptr;
  return EXIT_SUCCESS;
}
