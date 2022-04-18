#include <iostream>

#include "Span.hpp"

int main(void) {
  try {
    std::cout << "==== basic test ====\n";
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what();
  }

  try {
    std::cout << "\n==== randomly generate long sequence ====\n";
    Span test_long = Span(100000);
    test_long.fillNumbers();

    std::cout << test_long.shortestSpan() << std::endl;
    std::cout << test_long.longestSpan() << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what();
  }

  try {
    std::cout << "\n==== empty ====\n";
    Span empty;

    std::cout << empty.shortestSpan() << std::endl;
    std::cout << empty.longestSpan() << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what();
  }

  try {
    std::cout << "\n==== one elem ====\n";
    Span one(1);

    std::cout << one.shortestSpan() << std::endl;
    std::cout << one.longestSpan() << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what();
  }

  try {
    std::cout << "\n==== full ====\n";
    Span full(3);

    full.addNumber(100);
    full.addNumber(200);
    full.addNumber(300);
    full.addNumber(400);

    std::cout << full.shortestSpan() << std::endl;
    std::cout << full.longestSpan() << std::endl;

  } catch (const std::exception& e) {
    std::cout << e.what();
  }

  return 0;
}
