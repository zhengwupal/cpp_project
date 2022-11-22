#ifndef DEF_H_
#define DEF_H_

#include <string>

void test2();

class IBase {
 public:
  virtual ~IBase(){};  // destructor, use it to call destructor of the inherit
                       // classes
  virtual void Describe() = 0;  // pure virtual method
};

class Tester : public IBase {
 public:
  Tester(std::string name);
  // virtual ~Tester();
  ~Tester();
  void Describe();
  void Show(const std::string &str);

 private:
  std::string privatename;
};

#endif  // DEF_H_