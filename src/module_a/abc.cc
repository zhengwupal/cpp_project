#include "pro/module_a/abc.h"

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/regex.hpp>
#include <iostream>
#include <map>
#include <stack>
#include <string>

// a hack square root calculation using simple operations
double mysqrt(double x) {
  if (x <= 0) {
    return 0;
  }

  double result = x;

  // do ten iterations
  for (int i = 0; i < 10; ++i) {
    if (result <= 0) {
      result = 0.1;
    }
    double delta = x - (result * result);
    result = result + 0.5 * delta / result;
    // std::cout << "Computing sqrt of " << x << " to be " << result <<
    // std::endl;
  }
  int *a = new int(3);
  std::cout << "a: " << *a << std::endl;
  return result;
}

void test1() {
  boost::regex re("(https?://www.ttufo.com/.+/.+/.+)(_\\d+)(.html?)");

  // string replace("http://www.ttufo.com/($1)/($2)/($3).htm($5)");
  // regex re("http://www.ttufo.com/(.+)/(.+)/(.+)(_.+).htm(l?)");

  std::string target("http://www.ttufo.com/ufo/201705/154053_3.html");

  boost::cmatch what;

  if (boost::regex_match(target.c_str(), what, re)) {
    std::cout << "match " << what.size() << std::endl;

    for (int i = 0; i < what.size(); i++) {
      std::cout << "what[" << i << "]: " << what[i]
                << ", first: " << what[i].first
                << ", second: " << what[i].second << std::endl;
    }
  } else {
    std::cout << "not match " << std::endl;
  }

  std::cout << "=====" << std::endl;

  boost::posix_time::time_duration td(1, 2, 3, 888);
  std::cout << td << std::endl;
}

void test3() {
  std::string s("1/1/1900");
  if (s.find("/") != std::string::npos) {
    std::cout << "found" << std::endl;
  }
}

void test4() {
  std::string expression{"This is (pezy)."};
  bool bSeen = false;
  std::stack<char> stk;
  for (const auto &s : expression) {
    if (s == '(') {
      bSeen = true;
      continue;
    } else if (s == ')')
      bSeen = false;

    if (bSeen) stk.push(s);
  }

  std::string repstr;
  while (!stk.empty()) {
    repstr += stk.top();
    stk.pop();
  }

  expression.replace(expression.find("(") + 1, repstr.size(), repstr);

  std::cout << expression << std::endl;
}

void test5() {
  std::map<std::string, size_t> counts;
  std::string word("abc");
  auto result = counts.insert({word, 1});  // result is pair
  std::cout << result.first->second << std::endl;
}