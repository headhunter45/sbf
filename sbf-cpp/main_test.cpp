#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include "Menus.h"
#include "test.h"

using namespace SBF;
using namespace Test;
using namespace std;

namespace Test::Menus {}  // End namespace Test::Menus

using namespace Test::Menus;

TestResults main_test_Menus(int argc, char* argv[]) {
  TestResults results;
  return results;
}

int main(int argc, char* argv[]) {
  TestResults results = main_test_Menus(argc, argv);

  PrintResults(cout, results);

  return results.failed() + results.errors();
}

namespace Test::Menus {}  // namespace Test::Menus
