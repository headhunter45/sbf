#include "Random.h"

#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include "test.h"

namespace {
using namespace SBF;
using namespace Test;
using namespace std;
}  // End namespace

TestResults test_something() {
  return TestResults().skip("SBF::Random::*");
}

int main(int argc, char* argv[]) {
  TestResults results;

  results += test_something();

  PrintResults(cout, results);

  return results.failed() + results.errors();
}
