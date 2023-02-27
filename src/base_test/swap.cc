#include <future>
#include <iostream>
#include <string>
#include <vector>

#include "pro/base_test/move.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

template <typename T>
void myswap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

class A {
 public:
  A() : m_ptr(new int(0)) { std::cout << "constructor A" << std::endl; }
  ~A() {
    std::cout << "destructor A, m_ptr:" << m_ptr << std::endl;
    delete m_ptr;
    m_ptr = nullptr;
  }

 private:
  int *m_ptr;
};

A Get(bool flag) {
  A a;
  A b;
  std::cout << "ready return" << std::endl;
  if (flag)
    return a;
  else
    return b;
}

struct Person {
  string name;
  int age;
  //初始构造函数
  Person(string p_name, int p_age) : name(std::move(p_name)), age(p_age) {
    cout << "I have been constructed" << endl;
  }
  //拷贝构造函数
  Person(const Person &other) : name(std::move(other.name)), age(other.age) {
    cout << "I have been copy constructed" << endl;
  }
  //转移构造函数
  // Person(Person &&other) : name(std::move(other.name)), age(other.age) {
  //   cout << "I have been moved" << endl;
  // }
};

void swap() {
  // int a = 1;
  // int b = 2;
  // myswap(a, b);
  // std::cout << a << " " << b << std::endl;

  // A a = Get(false);
  // std::cout << "main finish" << std::endl;

  // vector<Person> e;
  // cout << "emplace_back:" << endl;
  // e.emplace_back("Jane", 23);  //不用构造类对象

  // vector<Person> p;
  // cout << "push_back:" << endl;
  // p.push_back(Person("Mike", 36));
}
