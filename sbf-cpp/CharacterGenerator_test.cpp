#include "CharacterGenerator.h"

#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include "test.h"

namespace {
using namespace SBF;
using namespace Test;
using std::cout;
}  // End namespace

int main(int argc, char* argv[]) {
  TestResults results;

  results.skip("// TODO: SBF::CharacterGenerator::*");

  PrintResults(cout, results);

  return results.failed() + results.errors();
}
