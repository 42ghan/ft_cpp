#include <iostream>

#include "MutantStack.hpp"

int main() {
  std::cout << "\n=========== mstack ===========\n";

  MutantStack<int> mstack;

  mstack.push(5);
  mstack.push(17);

  std::cout << "Current top : " << mstack.top() << std::endl;

  mstack.pop();

  std::cout << "Current size : " << mstack.size() << std::endl;

  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();

  ++it;
  --it;
  std::cout << "PRINT STACK : \n";
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }

  std::cout << "\n=========== original stack copy constructor ===========\n";
  std::stack<int> s(mstack);
  std::cout << s.top() << "\n";
  s.pop();
  std::cout << s.top() << "\n";

  std::cout << "\n=========== mstack copy constructor ===========\n";
  MutantStack<int> second(mstack);

  second.pop();
  second.push(7);

  MutantStack<int>::iterator sec = second.begin();
  MutantStack<int>::iterator sece = second.end();

  ++sec;
  --sec;
  std::cout << "PRINT STACK : \n";
  while (sec != sece) {
    std::cout << *sec << std::endl;
    ++sec;
  }
  return 0;
}
