#include "def.h"

#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

#include "abc.h"
#include "yaml-cpp/yaml.h"

using json = nlohmann::json;
void test2() {
  boost::posix_time::time_duration td(10, 21, 30);
  std::cout << td << std::endl;

  std::cout << std::endl;

  test1();

  std::cout << std::endl;

  json ex1 = json::parse(R"(
  {
    "pi": 3.141,
    "happy": true
  })");

  std::cout << ex1.dump(4) << std::endl;
}