#include <benchmark/benchmark.h>

#include "pro/module_a/abc.h"

static void BM_StringCreation(benchmark::State& state) {
  for (auto _ : state) std::string empty_string;
}
// Register the function as a benchmark
BENCHMARK(BM_StringCreation);

// Define another benchmark
static void BM_StringCopy(benchmark::State& state) {
  std::string x = "hello";
  for (auto _ : state) std::string copy(x);
}
BENCHMARK(BM_StringCopy);

static void BM_MySqrt(benchmark::State& state) {
  double x = 120;
  for (auto _ : state) mysqrt(x);
}
BENCHMARK(BM_MySqrt);

BENCHMARK_MAIN();