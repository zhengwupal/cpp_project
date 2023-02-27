#ifndef INCLUDE_PRO_DESIGN_PATTERN_STRATEGY_H_
#define INCLUDE_PRO_DESIGN_PATTERN_STRATEGY_H_

#include <iostream>

using std::cout;
using std::endl;

class Strategy {
public:
  virtual void AlgorithmInterface() = 0;
  virtual ~Strategy(){};
};

class ConcreteStrategyA : public Strategy {
public:
  void AlgorithmInterface() { cout << "I am from ConcreteStrategyA." << endl; }
};

class ConcreteStrategyB : public Strategy {
public:
  void AlgorithmInterface() { cout << "I am from ConcreteStrategyB." << endl; }
};

class ConcreteStrategyC : public Strategy {
public:
  void AlgorithmInterface() { cout << "I am from ConcreteStrategyC." << endl; }
};

class Context {
public:
  Context(Strategy *pStrategyArg) : pStrategy(pStrategyArg) {}
  void ContextInterface() { pStrategy->AlgorithmInterface(); }

private:
  Strategy *pStrategy;
};

#endif  // INCLUDE_PRO_DESIGN_PATTERN_STRATEGY_H_