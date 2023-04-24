#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include "Menus.h"
#include "test.h"

namespace {
using namespace SBF;
using namespace Test;
using namespace std;
}  // End namespace

int main(int argc, char* argv[]) {
  TestResults results;

  PrintResults(cout, results);

  return results.failed() + results.errors();
}
