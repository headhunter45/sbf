#include "Character.h"

#include <iostream>

#include "test.h"
using namespace SBF;
using namespace Test;
using namespace std;

int main(int argc, char* argv[]) {
  TestResults results;

  results.skip("// TODO: SBF::Character::*");

  PrintResults(cout, results);

  return results.failed() + results.errors();
}
