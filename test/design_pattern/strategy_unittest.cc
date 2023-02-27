#include "pro/design_pattern/strategy.h"

#include <gtest/gtest.h>

#include <iostream>

namespace {

TEST(DesignPattern, Strategy) {
  Strategy *pStrategyA = new ConcreteStrategyA;
  Strategy *pStrategyB = new ConcreteStrategyB;
  Strategy *pStrategyC = new ConcreteStrategyC;
  Context *pContextA = new Context(pStrategyA);
  Context *pContextB = new Context(pStrategyB);
  Context *pContextC = new Context(pStrategyC);
  pContextA->ContextInterface();
  pContextB->ContextInterface();
  pContextC->ContextInterface();

  if (pStrategyA) delete pStrategyA;
  if (pStrategyB) delete pStrategyB;
  if (pStrategyC) delete pStrategyC;

  if (pContextA) delete pContextA;
  if (pContextB) delete pContextB;
  if (pContextC) delete pContextC;
}

}  // namespace