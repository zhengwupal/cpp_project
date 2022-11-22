#include "def.h"

#include <fmt/core.h>
#include <yaml-cpp/yaml.h>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

#include "abc.h"

void descriptor(IBase* obj) { obj->Describe(); }

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

  std::cout << std::endl;

  YAML::Node primes = YAML::Load("[2, 3, 5, 7, 11]");
  for (std::size_t i = 0; i < primes.size(); i++) {
    std::cout << primes[i].as<int>() << std::endl;
  }

  std::cout << "=============================" << std::endl;

  std::cout << std::endl << "Tester Testing..." << std::endl;
  Tester* obj1 = new Tester("Declared with Tester");
  descriptor(obj1);
  delete obj1;

  std::cout << std::endl << "IBase Testing..." << std::endl;
  IBase* obj2 = new Tester("Declared with IBase");
  descriptor(obj2);
  delete obj2;

  // this is a bad usage of the object since it is created with "new" but there
  // are no "delete"
  std::cout << std::endl << "Tester not defined..." << std::endl;
  descriptor(new Tester("Not defined"));

  std::cout << "=============================" << std::endl;

  Tester t("aaa");
  t.Show("sssssssssssss");

  std::cout << "=============================" << std::endl;
  fmt::print("Hello, world!\n");
}

Tester::Tester(std::string name) {
  std::cout << "Tester constructor" << std::endl;
  this->privatename = name;
}

Tester::~Tester() { std::cout << "Tester destructor" << std::endl; }

void Tester::Describe() {
  std::cout << "I'm Tester [" << this->privatename << "]" << std::endl;
}

void Tester::Show(const std::string& str) {
  // str = std::string("aaaaaaaaaaaaaaa");
  std::cout << str << std::endl;
}