#include "Character.h"

#include <iostream>

#include "test.h"
using namespace SBF;
using namespace Test;
using namespace std;

TestResults main_test_Character(int argc, char* argv[]) {
  TestResults results;

  PrintResults(cout, results);

  return results;
}

int main(int argc, char* argv[]) {
  TestResults results = main_test_Character(argc, argv);

  return results.failed() + results.errors();
}
