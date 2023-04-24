#include "Disciplines.h"

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

TestResults test_GetDisciplineLabel() {
  return execute_suite<string, int>(make_test_suite(
      "SBF::GetDisciplineLabel",
      GetDisciplineLabel,
      vector<TestTuple<string, int>>({
          make_test<string, int>("should get \"\" for invalid discipline id 0", "", make_tuple(0)),
          make_test<string, int>("should get \"Animalism\" for id 1", "Animalism", make_tuple(1)),
          make_test<string, int>("should get \"Auspex\" for id 2", "Auspex", make_tuple(2)),
          make_test<string, int>("should get \"Bardo\" for id 3", "Bardo", make_tuple(3)),
          make_test<string, int>("should get \"Celerity\" for id 4", "Celerity", make_tuple(4)),
          make_test<string, int>("should get \"Chimestry\" for id 5", "Chimestry", make_tuple(5)),
          make_test<string, int>("should get \"Dementation\" for id 6", "Dementation", make_tuple(6)),
          make_test<string, int>("should get \"Dominate\" for id 7", "Dominate", make_tuple(7)),
          make_test<string, int>("should get \"Fortitude\" for id 8", "Fortitude", make_tuple(8)),
          make_test<string, int>("should get \"Melpominee\" for id 9", "Melpominee", make_tuple(9)),
          make_test<string, int>("should get \"Mortis\" for id 10", "Mortis", make_tuple(10)),
          make_test<string, int>("should get \"Mytherceria\" for id 11", "Mytherceria", make_tuple(11)),
          make_test<string, int>("should get \"Necromancy\" for id 12", "Necromancy", make_tuple(12)),
          make_test<string, int>("should get \"Obeah\" for id 13", "Obeah", make_tuple(13)),
          make_test<string, int>("should get \"Obfuscate\" for id 14", "Obfuscate", make_tuple(14)),
          make_test<string, int>("should get \"Obtenebration\" for id 15", "Obtenebration", make_tuple(15)),
          make_test<string, int>("should get \"Potence\" for id 16", "Potence", make_tuple(16)),
          make_test<string, int>("should get \"Presence\" for id 17", "Presence", make_tuple(17)),
          make_test<string, int>("should get \"Protean\" for id 18", "Protean", make_tuple(18)),
          make_test<string, int>("should get \"Quietus\" for id 19", "Quietus", make_tuple(19)),
          make_test<string, int>("should get \"Serpentis\" for id 20", "Serpentis", make_tuple(20)),
          make_test<string, int>("should get \"Spiritus\" for id 21", "Spiritus", make_tuple(21)),
          make_test<string, int>("should get \"Thanantosis\" for id 22", "Thanantosis", make_tuple(22)),
          make_test<string, int>("should get \"Thaumaturgy\" for id 23", "Thaumaturgy", make_tuple(23)),
          make_test<string, int>("should get \"Vicissitude\" for id 24", "Vicissitude", make_tuple(24)),
          make_test<string, int>("should get \"\" for invalid discipline id 25", "", make_tuple(25)),
      })));
}

TestResults test_FillDisciplineLabels() {
  auto fnToTest = []() -> string {
    ostringstream error_message;
    vector<string> expected = {
        kDisciplineAnimalismLabel,   kDisciplineAuspexLabel,      kDisciplineBardoLabel,
        kDisciplineCelerityLabel,    kDisciplineChimestryLabel,   kDisciplineDementationLabel,
        kDisciplineDominateLabel,    kDisciplineFortitudeLabel,   kDisciplineMelpomineeLabel,
        kDisciplineMortisLabel,      kDisciplineMytherceriaLabel, kDisciplineNecromancyLabel,
        kDisciplineObeahLabel,       kDisciplineObfuscateLabel,   kDisciplineObtenebrationLabel,
        kDisciplinePotenceLabel,     kDisciplinePresenceLabel,    kDisciplineProteanLabel,
        kDisciplineQuietusLabel,     kDisciplineSerpentisLabel,   kDisciplineSpiritusLabel,
        kDisciplineThanantosisLabel, kDisciplineThaumaturgyLabel, kDisciplineVicissitudeLabel,
    };
    vector<string> actual = {"This should be removed."};
    FillDisciplineLabels(actual);
    compare(error_message, expected, actual);
    string error = error_message.str();
    if (error.size() > 0) {
      return error;
    }
    return "no errors";
  };
  return execute_suite<string>(
      make_test_suite("SBF::FillDisciplineLabels",
                      fnToTest,
                      vector<TestTuple<string>>({
                          make_test<string>("should fill disciplines", "no errors", make_tuple()),
                      })));
}

int main(int argc, char* argv[]) {
  TestResults results;

  results += test_GetDisciplineLabel();
  results += test_FillDisciplineLabels();

  return results.failed() + results.errors();
}
