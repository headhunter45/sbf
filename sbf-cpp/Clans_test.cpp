#include "Clans.h"

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

TestResults test_GetClanLabel() {
  return execute_suite<string, int>(make_test_suite(
      "SBF::GetClanLabel",
      GetClanLabel,
      vector<TestTuple<string, int>>({
          make_test<string, int>("should get \"\" for invalid clan 0", "", make_tuple(0)),
          make_test<string, int>("should get \"Anarch\" for clan 1 kClanAnarch", "Anarch", make_tuple(1)),
          make_test<string, int>("should get \"Assamite\" for clan 2 kClanAssamite", "Assamite", make_tuple(2)),
          make_test<string, int>("should get \"Baali\" for clan 3 kClanBaali", "Baali", make_tuple(3)),
          make_test<string, int>("should get \"Brujah\" for clan 4 kClanBrujah", "Brujah", make_tuple(4)),
          make_test<string, int>("should get \"Caitiff\" for clan 5 kClanCaitiff", "Caitiff", make_tuple(5)),
          make_test<string, int>(
              "should get \"Cappadocian\" for clan 6 kClanCappadocian", "Cappadocian", make_tuple(6)),
          make_test<string, int>("should get \"Gangrel\" for clan 7 kClanGangrel", "Gangrel", make_tuple(7)),
          make_test<string, int>("should get \"Giovanni\" for clan 8 kClanGiovanni", "Giovanni", make_tuple(8)),
          make_test<string, int>("should get \"Inconnu\" for clan 9 kClanInconnu", "Inconnu", make_tuple(9)),
          make_test<string, int>("should get \"Lasombra\" for clan 10 kClanLasombra", "Lasombra", make_tuple(10)),
          make_test<string, int>("should get \"Malkavian\" for clan 11 kClanMalkavian", "Malkavian", make_tuple(11)),
          make_test<string, int>("should get \"Nosferatu\" for clan 12 kClanNosferatu", "Nosferatu", make_tuple(12)),
          make_test<string, int>("should get \"Ravanos\" for clan 13 kClanRavanos", "Ravanos", make_tuple(13)),
          make_test<string, int>("should get \"Settite\" for clan 14 kClanSettite", "Settite", make_tuple(14)),
          make_test<string, int>("should get \"Toreador\" for clan 15 kClanToreador", "Toreador", make_tuple(15)),
          make_test<string, int>("should get \"Tremere\" for clan 16 kClanTremere", "Tremere", make_tuple(16)),
          make_test<string, int>("should get \"Tzismice\" for clan 17 kClanTzismice", "Tzismice", make_tuple(17)),
          make_test<string, int>("should get \"Ventrue\" for clan 18 kClanVentrue", "Ventrue", make_tuple(18)),
          make_test<string, int>("should get \"\" for invalid clan 19", "", make_tuple(19)),
      })));
}

TestResults test_FillClanLabels() {
  return execute_suite<string>(make_test_suite(
      "SBF::FillClanLabels",
      []() -> string {
        ostringstream error_message;
        vector<string> expected = {"Anarch",
                                   "Assamite",
                                   "Baali",
                                   "Brujah",
                                   "Caitiff",
                                   "Cappadocian",
                                   "Gangrel",
                                   "Giovanni",
                                   "Inconnu",
                                   "Lasombra",
                                   "Malkavian",
                                   "Nosferatu",
                                   "Ravanos",
                                   "Settite",
                                   "Toreador",
                                   "Tremere",
                                   "Tzismice",
                                   "Ventrue"};
        vector<string> actual = {"This should be removed."};
        FillClanLabels(actual);
        compare(error_message, expected, actual);
        string error = error_message.str();
        if (error.size() > 0) {
          return error;
        }
        return "no errors";
      },
      vector<TestTuple<string>>({
          make_test<string>("should fill clan labels", "no errors", make_tuple()),
      })

          ));
}

int main(int argc, char* argv[]) {
  TestResults results;

  results += test_GetClanLabel();
  results += test_FillClanLabels();

  return results.failed() + results.errors();
}
