#include "Random.h"

#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include "test.h"

using namespace SBF;
using namespace Test;
using namespace std;

namespace Test::Random {
TestResults test_something();
}  // End namespace Test::Random

using namespace Test::Random;

TestResults main_test_Random(int argc, char* argv[]) {
  TestResults results;

  results += test_something();

  PrintResults(cout, results);

  return results;
}

int main(int argc, char* argv[]) {
  TestResults results = main_test_Random(argc, argv);

  return results.failed() + results.errors();
}

namespace Test::Random {
TestResults test_something() {
  return TestResults().skip("SBF::Random::*");
}

}  // namespace Test::Random
