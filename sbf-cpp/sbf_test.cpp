#include "sbf.h"

#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include "test.h"

using namespace SBF;
using namespace Test;
using namespace std;

namespace Test::sbf {}  // End namespace Test::sbf

using namespace Test::sbf;

TestResults main_test_sbf(int argc, char* argv[]) {
  TestResults results;
  return results;
}

int main(int argc, char* argv[]) {
  TestResults results = main_test_sbf(argc, argv);

  PrintResults(cout, results);

  return results.failed() + results.errors();
}

namespace Test::sbf {}  // namespace Test::sbf
