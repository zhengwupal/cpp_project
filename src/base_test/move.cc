#include "pro/base_test/move.h"

#include <iostream>
#include <string>

void std_move() {
  std::string str = "test";
  std::string&& r = std::move(str);
  std::cout << r << std::endl;
  std::cout << str << std::endl;
  std::string t(std::move(r));
  std::cout << t << std::endl;
  std::cout << str << std::endl;
}