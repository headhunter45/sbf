#include "Backgrounds.h"

#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include "test.h"

using namespace SBF;
using namespace Test;
using namespace std;

namespace Test::Backgrounds {
TestResults test_GetBackgroundLabel();
TestResults test_FillBackgroundLabels();
}  // namespace Test::Backgrounds

using namespace Test::Backgrounds;

TestResults main_test_Backgrounds(int argc, char* argv[]) {
  TestResults results;

  results += test_GetBackgroundLabel();
  results += test_FillBackgroundLabels();

  return results;
}

int main(int argc, char* argv[]) {
  TestResults results = main_test_Backgrounds(argc, argv);

  PrintResults(cout, results);

  return results.failed() + results.errors();
}

namespace Test::Backgrounds {
TestResults test_GetBackgroundLabel() {
  return execute_suite<string, int>(make_test_suite(
      "SBF::GetBackgroundLabel",
      GetBackgroundLabel,
      vector<TestTuple<string, int>>({
          make_test<string, int>("should get \"\" for invalid background 0", "", make_tuple(0)),
          make_test<string, int>(
              "should get \"Allies\" for background 1 kBackgroundAlliesLabel", "Allies", make_tuple(1)),
          make_test<string, int>(
              "should get \"Contacts\" for background 2 kBackgroundContactsLabel", "Contacts", make_tuple(2)),
          make_test<string, int>("should get \"Fame\" for background 3 kBackgroundFameLabel", "Fame", make_tuple(3)),
          make_test<string, int>(
              "should get \"Generation\" for background 4 kBackgroundGenerationLabel", "Generation", make_tuple(4)),
          make_test<string, int>("should get \"Herd\" for background 5 kBackgroundHerdLabel", "Herd", make_tuple(5)),
          make_test<string, int>(
              "should get \"Influence\" for background 6 kBackgroundInfluenceLabel", "Influence", make_tuple(6)),
          make_test<string, int>(
              "should get \"Mentor\" for background 7 kBackgroundMentorLabel", "Mentor", make_tuple(7)),
          make_test<string, int>(
              "should get \"Resources\" for background 8 kBackgroundResourcesLabel", "Resources", make_tuple(8)),
          make_test<string, int>(
              "should get \"Retainers\" for background 9 kBackgroundRetainersLabel", "Retainers", make_tuple(9)),
          make_test<string, int>(
              "should get \"Status\" for background 10 kBackgroundStatusLabel", "Status", make_tuple(10)),
          make_test<string, int>("should get \"\" for invalid background 11", "", make_tuple(11)),
      })));
}

TestResults test_FillBackgroundLabels() {
  return execute_suite<string>(make_test_suite(
      "SBF::FillBackgroundLabels",
      []() -> string {
        ostringstream error_message;
        vector<string> expected = {"Allies",
                                   "Contacts",
                                   "Fame",
                                   "Generation",
                                   "Herd",
                                   "Influence",
                                   "Mentor",
                                   "Resources",
                                   "Retainers",
                                   "Status"};
        vector<string> actual = {"This should be removed."};
        FillBackgroundLabels(actual);
        compare(error_message, expected, actual);
        string error = error_message.str();
        if (error.size() > 0) {
          return error;
        }
        return "no errors";
      },
      vector<TestTuple<string>>({
          make_test<string>("should fill background labels", "no errors", make_tuple()),
      })

          ));
}
}  // End namespace Test::Backgrounds
