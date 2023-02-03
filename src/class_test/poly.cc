#include "pro/class_test/poly.h"

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "pro/class_test/bulk_quote.h"
#include "pro/class_test/disc_quote.h"
#include "pro/class_test/limit_quote.h"
#include "pro/class_test/quote.h"

void no_poly() {
  std::vector<Quote> v;
  for (unsigned i = 1; i != 10; ++i)
    v.push_back(Bulk_quote("sss", i * 10.1, 10, 0.3));

  double total = 0;
  for (const auto& b : v) {
    total += b.net_price(20);
  }
  std::cout << total << std::endl;

  std::cout << "======================\n\n";
}

void poly() {
  std::vector<std::shared_ptr<Quote>> pv;

  for (unsigned i = 1; i != 2; ++i)
    pv.push_back(
        std::make_shared<Bulk_quote>(Bulk_quote("sss", i * 10.1, 10, 0.3)));

  // double total_p = 0;
  // for (auto p : pv) {
  //   total_p += p->net_price(20);
  // }
  // std::cout << total_p << std::endl;
}

class A {
 public:
  // default constructor
  A() : s("default") {}

  // copy constructor
  A(const A& o) : s(o.s) { std::cout << "move failed!\n"; }

  // move constructor
  A(A&& o) : s(std::move(o.s)) {}

  std::string printObj() { return s; }

 private:
  std::string s;
};

A temp(A a) { return a; }
