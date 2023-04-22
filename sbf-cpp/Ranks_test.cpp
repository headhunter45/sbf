#include "Ranks.h"

#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include "test.h"

using namespace SBF;
using namespace Test;
using namespace std;

namespace Test::Ranks {
TestResults test_RankType_operator_extract();
TestResults test_RankType_operator_equal_to();
TestResults test_RankType_operator_not_equal_to();
TestResults test_GetRank();
TestResults test_FillRanks();
}  // End namespace Test::Ranks

using namespace Test::Ranks;

TestResults main_test_Ranks(int argc, char** argv) {
  TestResults results;

  results += test_RankType_operator_extract();
  results += test_RankType_operator_equal_to();
  results += test_RankType_operator_not_equal_to();
  results += test_GetRank();
  results += test_FillRanks();

  return results;
}

namespace Test::Ranks {
TestResults test_GetRank() {
  return execute_suite<RankType, int>(make_test_suite(
      "SBF::GetRank",
      GetRank,
      vector<TestTuple<RankType, int>>({
          make_test<RankType, int>("should get {0, \"\"} for invalid rank id 0", RankType({0, ""}), make_tuple(0)),
          make_test<RankType, int>(
              "should get {1, \"Primary\"} for rank id 1", RankType({1, "Primary"}), make_tuple(1)),
          make_test<RankType, int>(
              "should get {2, \"Secondary\"} for rank id 2", RankType({2, "Secondary"}), make_tuple(2)),
          make_test<RankType, int>(
              "should get {3, \"Tertiary\"} for rank id 3", RankType({3, "Tertiary"}), make_tuple(3)),
          make_test<RankType, int>("should get {0, \"\"} for invalid rank id 6", RankType({0, ""}), make_tuple(6)),
      })));
}

TestResults test_FillRanks() {
  auto fnToTest = []() -> string {
    ostringstream error_message;
    vector<RankType> expected = {
        kRankPrimary,
        kRankSecondary,
        kRankTertiary,
    };
    vector<RankType> actual = {{-5, "This should be removed."}};
    FillRanks(actual);
    compare(error_message, expected, actual);
    string error = error_message.str();
    if (error.size() > 0) {
      return error;
    }
    return "no errors";
  };
  return execute_suite<string>(make_test_suite("SBF::FillRanks",
                                               fnToTest,
                                               vector<TestTuple<string>>({
                                                   make_test<string>("should fill ranks", "no errors", make_tuple()),
                                               })));
}

TestResults test_RankType_operator_extract() {
  auto fnToTest = [](const RankType& rank) -> string {
    ostringstream os;
    os << rank;
    return os.str();
  };
  return execute_suite<string, RankType>(make_test_suite(
      "SBF::RankType::operator<<",
      fnToTest,
      vector<TestTuple<string, RankType>>({
          make_test<string, RankType>(
              "should print an invalid rank", "Rank: {id: 0, label: \"\"}", make_tuple((RankType){0, ""})),
          make_test<string, RankType>(
              "should print primary", "Rank: {id: 1, label: \"Primary\"}", make_tuple(kRankPrimary)),
          make_test<string, RankType>(
              "should print secondary", "Rank: {id: 2, label: \"Secondary\"}", make_tuple(kRankSecondary)),
          make_test<string, RankType>(
              "should print tertiary", "Rank: {id: 3, label: \"Tertiary\"}", make_tuple(kRankTertiary)),
      })));
}

TestResults test_RankType_operator_equal_to() {
  return execute_suite<bool, RankType, RankType>(make_test_suite(
      "SBF::RankType::operator==",
      [](const RankType& left, const RankType& right) { return left == right; },
      vector<TestTuple<bool, RankType, RankType>>({
          make_test<bool, RankType, RankType>(
              "should return true when comparing an rank to itself", true, make_tuple(kRankPrimary, kRankPrimary)),
          make_test<bool, RankType, RankType>(
              "should return true when comparing two different instances created with the same values",
              true,
              make_tuple(kRankSecondary, RankType({kRankSecondaryId, kRankSecondaryLabel}))),
          make_test<bool, RankType, RankType>("should return false when comparing two different rank gropus",
                                              false,
                                              make_tuple(kRankPrimary, kRankTertiary)),
      })));
}

TestResults test_RankType_operator_not_equal_to() {
  return execute_suite<bool, RankType, RankType>(make_test_suite(
      "SBF::RankType::operator!=",
      [](const RankType& left, const RankType& right) { return left != right; },
      vector<TestTuple<bool, RankType, RankType>>({
          make_test<bool, RankType, RankType>(
              "should return false when comparing an rank to itself", false, make_tuple(kRankPrimary, kRankPrimary)),
          make_test<bool, RankType, RankType>(
              "should return false when comparing two different instances created with the same values",
              false,
              make_tuple(kRankSecondary, RankType({kRankSecondaryId, kRankSecondaryLabel}))),
          make_test<bool, RankType, RankType>("should return true when comparing two different rank gropus",
                                              true,
                                              make_tuple(kRankSecondary, kRankTertiary)),
      })));
}
}  // namespace Test::Ranks
