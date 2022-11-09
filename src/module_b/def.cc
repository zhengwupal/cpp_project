#include "def.h"

#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>

#include "abc.h"

void test2() {
  boost::posix_time::time_duration td(10, 21, 30);
  std::cout << td << std::endl;

  std::cout << std::endl;

  test1();
}