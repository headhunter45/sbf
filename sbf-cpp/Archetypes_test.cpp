#include "Archetypes.h"

#include <iostream>
#include <sstream>

#include "test.h"
using namespace SBF;
using namespace Test;
using namespace std;

namespace Test::Archetypes {
TestResults test_GetArchetypeLabel();
TestResults test_FillArchetypeLabels();
}  // End namespace Test::Archetypes

using namespace Test::Archetypes;

TestResults main_test_Archetypes(int argc, char* argv[]) {
  TestResults results;

  results += test_GetArchetypeLabel();
  results += test_FillArchetypeLabels();

  return results;
}

int main(int argc, char* argv[]) {
  TestResults results = main_test_Archetypes(argc, argv);

  PrintResults(cout, results);

  return results.failed() + results.errors();
}

namespace Test::Archetypes {
TestResults test_GetArchetypeLabel() {
  return execute_suite<string, int>(make_test_suite(
      "SBF::GetArchetypeLabel",
      GetArchetypeLabel,
      vector<TestTuple<string, int>>({
          make_test<string, int>("should return \"\" for id 0", "", make_tuple(0)),
          make_test<string, int>("should return \"Architect\" for id 1", "Architect", make_tuple(1)),
          make_test<string, int>("should return \"Autocrat\" for id 2", "Autocrat", make_tuple(2)),
          make_test<string, int>("should return \"Barbarian\" for id 3", "Barbarian", make_tuple(3)),
          make_test<string, int>("should return \"Bon Vivant\" for id 4", "Bon Vivant", make_tuple(4)),
          make_test<string, int>("should return \"Bravo\" for id 5", "Bravo", make_tuple(5)),
          make_test<string, int>("should return \"Caregiver\" for id 6", "Caregiver", make_tuple(6)),
          make_test<string, int>("should return \"Caretaker\" for id 7", "Caretaker", make_tuple(7)),
          make_test<string, int>("should return \"Celebrant\" for id 8", "Celebrant", make_tuple(8)),
          make_test<string, int>("should return \"Child\" for id 9", "Child", make_tuple(9)),
          make_test<string, int>("should return \"Conformist\" for id 10", "Conformist", make_tuple(10)),
          make_test<string, int>("should return \"Conniver\" for id 11", "Conniver", make_tuple(11)),
          make_test<string, int>("should return \"Curmudgeon\" for id 12", "Curmudgeon", make_tuple(12)),
          make_test<string, int>("should return \"Defender\" for id 13", "Defender", make_tuple(13)),
          make_test<string, int>("should return \"Deviant\" for id 14", "Deviant", make_tuple(14)),
          make_test<string, int>("should return \"Director\" for id 15", "Director", make_tuple(15)),
          make_test<string, int>("should return \"Fanatic\" for id 16", "Fanatic", make_tuple(16)),
          make_test<string, int>("should return \"Gallant\" for id 17", "Gallant", make_tuple(17)),
          make_test<string, int>("should return \"Innovator\" for id 18", "Innovator", make_tuple(18)),
          make_test<string, int>("should return \"Jester\" for id 19", "Jester", make_tuple(19)),
          make_test<string, int>("should return \"Judge\" for id 20", "Judge", make_tuple(20)),
          make_test<string, int>("should return \"Loaner\" for id 21", "Loaner", make_tuple(21)),
          make_test<string, int>("should return \"Martyr\" for id 22", "Martyr", make_tuple(22)),
          make_test<string, int>("should return \"Monster\" for id 23", "Monster", make_tuple(23)),
          make_test<string, int>("should return \"Penitent\" for id 24", "Penitent", make_tuple(24)),
          make_test<string, int>("should return \"Rebel\" for id 25", "Rebel", make_tuple(25)),
          make_test<string, int>("should return \"Rogue\" for id 26", "Rogue", make_tuple(26)),
          make_test<string, int>("should return \"Survivor\" for id 27", "Survivor", make_tuple(27)),
          make_test<string, int>("should return \"Traditionalist\" for id 28", "Traditionalist", make_tuple(28)),
          make_test<string, int>("should return \"Tyrant\" for id 29", "Tyrant", make_tuple(29)),
          make_test<string, int>("should return \"Visionary\" for id 30", "Visionary", make_tuple(30)),
          make_test<string, int>("should return \"\" for an invalid id", "", make_tuple(31)),
      })));
}

TestResults test_FillArchetypeLabels() {
  return execute_suite<string>(make_test_suite(
      "SBF::FillArchetypeLabels",
      []() -> string {
        ostringstream error_message;
        vector<string> expected = {"Architect", "Autocrat",  "Barbarian", "Bon Vivant",     "Bravo",    "Caregiver",
                                   "Caretaker", "Celebrant", "Child",     "Conformist",     "Conniver", "Curmudgeon",
                                   "Defender",  "Deviant",   "Director",  "Fanatic",        "Gallant",  "Innovator",
                                   "Jester",    "Judge",     "Loaner",    "Martyr",         "Monster",  "Penitent",
                                   "Rebel",     "Rogue",     "Survivor",  "Traditionalist", "Tyrant",   "Visionary"};
        vector<string> actual = {"This should be removed."};
        FillArchetypeLabels(actual);
        compare(error_message, expected, actual);
        string error = error_message.str();
        if (error.size() > 0) {
          return error;
        }
        return "no errors";
      },
      vector<TestTuple<string>>({
          make_test<string>("should fill archetype labels", "no errors", make_tuple()),
      })));
}
}  // End namespace Test::Archetypes
