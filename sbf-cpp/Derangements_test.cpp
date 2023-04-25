#include "Derangements.h"

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
}  // namespace

const DerangementType kDerangementAmnesia = {
    1,
    "Amnesia",
    R"---(You forget a segment of your past. Additionally in some cases a character can forget abilities and be unable to use them for the duration.)---",
    1,
};
const DerangementType kDerangementDelusionsOfGrandeur = {
    2,
    "Delusions of Grandeur",
    R"---(You imagine you are better than you are.)---",
    5,
};
const DerangementType kDerangementFantasy = {
    3,
    "Fantasy",
    R"---(You enter a self-created world where you are the forgotten hero.)---",
    3,
};
const DerangementType kDerangementManicDepression = {
    4,
    "Manic-Depression",
    R"---(You sink into deep and fitful depressions, showing no interest in anything which used to captivate your interests. You will go along with others rather than use the energy to resist. Occasional fits of great energy grab hold of you, and you will work for hours or even days on your projects. During this time you will resist even the need for sleep as you burn up blood and Willpower on your schemes.)---",
    7,
};
const DerangementType kDerangementMultiplePersonalities = {
    5,
    "Multiple Personalities",
    R"---(You possess a number of new personalities. You have amore than one Mature, and will switch between them. Thus you regain Willpower points in defferent ways at defferent times)---",
    4,
};
const DerangementType kDerangementObsession = {
    6,
    "Obsession",
    R"---(You become obsessed with some interest or fetish.)---",
    10,
};
const DerangementType kDerangementOvercompensation = {
    7,
    "Overcompensation",
    R"---(You make up for your moral weaknesses by playing up your strengths to an extreme. You don't think you can frenzy and won't stop it.)---",
    14,
};
const DerangementType kDerangementParanoia = {
    8,
    "Paranoia",
    R"---(You are convinced that you are being hunted. You hold even your closest Friends under suspicion.)---",
    9,
};
const DerangementType kDerangementPerfection = {
    9,
    "Perfection",
    R"---(All your energy is directed toward preventing anything from going wong. When it does you must make a self-control roll or frenzy.)---",
    13,
};
const DerangementType kDerangementRegression = {
    10,
    "Regression",
    R"---(You become childlike retreating to an earlier time when less was expected of you Willpower is regained inthe way a Child's is.)---",
    11,
};

TestResults test_GetDerangement() {
  return execute_suite<DerangementType, int>(make_test_suite(
      "SBF::GetDerangement",
      GetDerangement,
      vector<TestTuple<DerangementType, int>>({
          make_test<DerangementType, int>(
              "should get {0, \"\", \"\", 0} for invalid derangement id 0", {0, "", "", 0}, make_tuple(0)),
          make_test<DerangementType, int>(
              "should get amnesia for derangement id 1", kDerangementAmnesia, make_tuple(1)),
          make_test<DerangementType, int>(
              "should get delusions of grandeur for derangement id 2", kDerangementDelusionsOfGrandeur, make_tuple(2)),
          make_test<DerangementType, int>(
              "should get fantasy for derangement id 3", kDerangementFantasy, make_tuple(3)),
          make_test<DerangementType, int>(
              "should get manic-depression for derangement id 4", kDerangementManicDepression, make_tuple(4)),
          make_test<DerangementType, int>("should get multiple personalities for derangement id 5",
                                          kDerangementMultiplePersonalities,
                                          make_tuple(5)),
          make_test<DerangementType, int>(
              "should get obsession for derangement id 6", kDerangementObsession, make_tuple(6)),
          make_test<DerangementType, int>(
              "should get overcompensation for derangement id 7", kDerangementOvercompensation, make_tuple(7)),
          make_test<DerangementType, int>(
              "should get paranoia for derangement id 8", kDerangementParanoia, make_tuple(8)),
          make_test<DerangementType, int>(
              "should get perfection for derangement id 9", kDerangementPerfection, make_tuple(9)),
          make_test<DerangementType, int>(
              "should get regression for derangement id 10", kDerangementRegression, make_tuple(10)),
          make_test<DerangementType, int>(
              "should get {0, \"\", \"\", 0} for invalid derangement id 11", {0, "", "", 0}, make_tuple(11)),
      })));
}

TestResults test_FillDerangements() {
  auto fnToTest = []() -> string {
    ostringstream error_message;
    vector<DerangementType> expected = {
        kDerangementAmnesia,
        kDerangementDelusionsOfGrandeur,
        kDerangementFantasy,
        kDerangementManicDepression,
        kDerangementMultiplePersonalities,
        kDerangementObsession,
        kDerangementOvercompensation,
        kDerangementParanoia,
        kDerangementPerfection,
        kDerangementRegression,
    };
    vector<DerangementType> actual = {{-1, "This should be removed.", "This should be removed.", 255}};
    FillDerangements(actual);
    compare(error_message, expected, actual);
    string error = error_message.str();
    if (error.size() > 0) {
      return error;
    }
    return "no errors";
  };
  return execute_suite<string>(
      make_test_suite("SBF::FillDerangements",
                      fnToTest,
                      vector<TestTuple<string>>({
                          make_test<string>("should fill derangements", "no errors", make_tuple()),
                      })));
}

TestResults test_DerangementType_operator_extract() {
  return execute_suite<string, DerangementType>(make_test_suite(
      "SBF::DerangementType::operator<<",
      [](const DerangementType& derangement) {
        ostringstream os;
        os << derangement;
        return os.str();
      },
      vector<TestTuple<string, DerangementType>>({
          make_test<string, DerangementType>("should print amnesia",
                                             "Derangement: {id: 1, label: \"Amnesia\", description: \""
                                                 + kDerangementAmnesia.description + "\", textColor: 1}",
                                             make_tuple(kDerangementAmnesia)),
          make_test<string, DerangementType>("should print delusions of grandeur",
                                             "Derangement: {id: 2, label: \"Delusions of Grandeur\", description: \""
                                                 + kDerangementDelusionsOfGrandeur.description + "\", textColor: 5}",
                                             make_tuple(kDerangementDelusionsOfGrandeur)),
          make_test<string, DerangementType>("should print fantasy",
                                             "Derangement: {id: 3, label: \"Fantasy\", description: \""
                                                 + kDerangementFantasy.description + "\", textColor: 3}",
                                             make_tuple(kDerangementFantasy)),
          make_test<string, DerangementType>("should print manic depression",
                                             "Derangement: {id: 4, label: \"Manic-Depression\", description: \""
                                                 + kDerangementManicDepression.description + "\", textColor: 7}",
                                             make_tuple(kDerangementManicDepression)),
          make_test<string, DerangementType>("should print multiple personalities",
                                             "Derangement: {id: 5, label: \"Multiple Personalities\", description: \""
                                                 + kDerangementMultiplePersonalities.description + "\", textColor: 4}",
                                             make_tuple(kDerangementMultiplePersonalities)),
          make_test<string, DerangementType>("should print obsession",
                                             "Derangement: {id: 6, label: \"Obsession\", description: \""
                                                 + kDerangementObsession.description + "\", textColor: 10}",
                                             make_tuple(kDerangementObsession)),
          make_test<string, DerangementType>("should print overcompensation",
                                             "Derangement: {id: 7, label: \"Overcompensation\", description: \""
                                                 + kDerangementOvercompensation.description + "\", textColor: 14}",
                                             make_tuple(kDerangementOvercompensation)),
          make_test<string, DerangementType>("should print paranoia",
                                             "Derangement: {id: 8, label: \"Paranoia\", description: \""
                                                 + kDerangementParanoia.description + "\", textColor: 9}",
                                             make_tuple(kDerangementParanoia)),
          make_test<string, DerangementType>("should print perfection",
                                             "Derangement: {id: 9, label: \"Perfection\", description: \""
                                                 + kDerangementPerfection.description + "\", textColor: 13}",
                                             make_tuple(kDerangementPerfection)),
          make_test<string, DerangementType>("should print regression",
                                             "Derangement: {id: 10, label: \"Regression\", description: \""
                                                 + kDerangementRegression.description + "\", textColor: 11}",
                                             make_tuple(kDerangementRegression)),
          make_test<string, DerangementType>(
              "should print an unknown derangement",
              "Derangement: {id: 0, label: \"MyLabel\", description: \"My Description\", textColor: 5}",
              make_tuple((DerangementType){0, "MyLabel", "My Description", 5})),
      })));
}

TestResults test_DerangementType_operator_equal_to() {
  return execute_suite<bool, DerangementType, DerangementType>(make_test_suite(
      "SBF::DerangementType::operator==",
      [](const DerangementType& left, const DerangementType& right) { return left == right; },
      vector<TestTuple<bool, DerangementType, DerangementType>>({
          make_test<bool, DerangementType, DerangementType>(
              "should return true when comparing a derangement to itself",
              true,
              make_tuple(kDerangementDelusionsOfGrandeur, kDerangementDelusionsOfGrandeur)),
          make_test<bool, DerangementType, DerangementType>(
              "should return true when comparing two different instances created with the same values",
              true,
              make_tuple(kDerangementFantasy, DerangementType({3, "Fantasy", kDerangementFantasy.description, 3}))),
          make_test<bool, DerangementType, DerangementType>(
              "should return false when comparing two different derangements",
              false,
              make_tuple(kDerangementManicDepression, kDerangementParanoia)),
      })));
}

TestResults test_DerangementType_operator_not_equal_to() {
  return execute_suite<bool, DerangementType, DerangementType>(make_test_suite(
      "SBF::DerangementType::operator!=",
      [](const DerangementType& left, const DerangementType& right) { return left != right; },
      vector<TestTuple<bool, DerangementType, DerangementType>>({
          make_test<bool, DerangementType, DerangementType>(
              "should return false when comparing a derangement to itself",
              false,
              make_tuple(kDerangementDelusionsOfGrandeur, kDerangementDelusionsOfGrandeur)),
          make_test<bool, DerangementType, DerangementType>(
              "should return false when comparing two different instances created with the same values",
              false,
              make_tuple(kDerangementFantasy, DerangementType({3, "Fantasy", kDerangementFantasy.description, 3}))),
          make_test<bool, DerangementType, DerangementType>(
              "should return true when comparing two different derangements",
              true,
              make_tuple(kDerangementManicDepression, kDerangementParanoia)),
      })));
}

int main(int argc, char* argv[]) {
  TestResults results;

  results += test_DerangementType_operator_extract();
  results += test_DerangementType_operator_equal_to();
  results += test_DerangementType_operator_not_equal_to();
  results += test_GetDerangement();
  results += test_FillDerangements();

  return results.failed() + results.errors();
}
