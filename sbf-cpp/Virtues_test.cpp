#include "Virtues.h"

#include <iostream>
#include <string>
#include <tuple>
#include <vector>

#include "test.h"

namespace {
using namespace SBF;
using namespace Test;
using namespace std;
}  // End namespace

const std::string kVirtueUnknownLabel = "";
const std::string kVirtueSelfControlLabel = "Self-Control";
const std::string kVirtueCourageLabel = "Courage";
const std::string kVirtueConscienceLabel = "Conscience";
const std::string kVirtueLabels[] = {
    kVirtueUnknownLabel,
    kVirtueSelfControlLabel,
    kVirtueCourageLabel,
    kVirtueConscienceLabel,
};

TestResults test_GetVirtueLabel() {
  return execute_suite<string, int>(make_test_suite(
      "SBF::GetVirtueLabel",
      GetVirtueLabel,
      vector<TestTuple<string, int>>({
          make_test<string, int>("should get \"\" for invalid virtue id 0", "", make_tuple(0)),
          make_test<string, int>("should get \"Self-Control\" for virtue id 1", "Self-Control", make_tuple(1)),
          make_test<string, int>("should get \"Courage\" for virtue id 2", "Courage", make_tuple(2)),
          make_test<string, int>("should get \"Conscience\" for virtue id 3", "Conscience", make_tuple(3)),
          make_test<string, int>("should get \"\" for invalid virtue id 4", "", make_tuple(4)),
      })));
}

TestResults test_FillVirtueLabels() {
  auto fnToTest = []() -> string {
    ostringstream error_message;
    vector<string> expected = {
        kVirtueSelfControlLabel,
        kVirtueCourageLabel,
        kVirtueConscienceLabel,
    };
    vector<string> actual = {"This should be removed."};
    FillVirtueLabels(actual);
    compare(error_message, expected, actual);
    string error = error_message.str();
    if (error.size() > 0) {
      return error;
    }
    return "no errors";
  };
  return execute_suite<string>(make_test_suite("SBF::FillVirtueLabels",
                                               fnToTest,
                                               vector<TestTuple<string>>({
                                                   make_test<string>("should fill ranks", "no errors", make_tuple()),
                                               })));
}

int main(int argc, char* argv[]) {
  TestResults results;

  results += test_GetVirtueLabel();
  results += test_FillVirtueLabels();

  PrintResults(cout, results);

  return results.failed() + results.errors();
}
