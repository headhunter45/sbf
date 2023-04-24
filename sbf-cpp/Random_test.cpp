#include "Random.h"

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

  return results;
}

namespace Test::Random {
TestResults test_something() {
  return TestResults().skip("SBF::Random::*");
}

}  // namespace Test::Random
