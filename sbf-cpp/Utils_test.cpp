#include "Utils.h"

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

TestResults test_GetIndexOf() {
  string long_text =
      "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's "
      "standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to "
      "make a type specimen book. It has survived not only five centuries, but also the leap into electronic "
      "typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset "
      "sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker "
      "including versions of Lorem Ipsum.";
  return execute_suite<size_t, string, string, size_t>(make_test_suite(
      "SBF::Utils::GetIndexOf(const std::string &text, const std::string &search, const size_t start)",
      GetIndexOf,
      vector<TestTuple<size_t, string, string, size_t>>({
          make_test<size_t, string, string, size_t>(
              "should get 0 for the first word in a string", 0, make_tuple(long_text, string("Lorem"), size_t(0))),
          make_test<size_t, string, string, size_t>("should get the location of a word in the larger string",
                                                    22,
                                                    make_tuple(long_text, string("dummy"), size_t(0))),
          make_test<size_t, string, string, size_t>(
              "should get -1 for the location of a word that is not int the string",
              -1,
              make_tuple(long_text, string("acid"), size_t(0))),
          make_test<size_t, string, string, size_t>(
              "should should get the location of a subsequent word within the string",
              120,
              make_tuple(long_text, string("dummy"), size_t(100))),
          make_test<size_t, string, string, size_t>(
              "should get -1 for the location of a word that is before start location in the string",
              -1,
              make_tuple(long_text, string("dummy"), size_t(long_text.size()))),
          make_test<size_t, string, string, size_t>("should get the location of a word within a simple string",
                                                    6,
                                                    make_tuple(string("these are words"), string("are"), size_t(0))),
          make_test<size_t, string, string, size_t>("should get the first location of a word within the string",
                                                    4,
                                                    make_tuple(string("one two one two"), string("two"), size_t(0))),
          make_test<size_t, string, string, size_t>("should get the second location of a word within the string",
                                                    12,
                                                    make_tuple(string("one two one two"), string("two"), size_t(5))),
      })));
}

TestResults test_GetSubstring() {
  return execute_suite<string, string, size_t, size_t>(make_test_suite(
      "SBF::Utils::GetSubstring(const std::string &text, const size_t start, const size_t length)",
      GetSubstring,
      vector<TestTuple<string, string, size_t, size_t>>({
          make_test<string, string, size_t, size_t>(
              "should get an empty string if start is too big", "", make_tuple(string("asdf"), size_t(6), size_t(2))),
          make_test<string, string, size_t, size_t>(
              "should get an empty string if count is 0", "", make_tuple(string("asdf"), size_t(0), size_t(0))),
          make_test<string, string, size_t, size_t>(
              "should get a string that starts at 0", "as", make_tuple(string("asdf"), size_t(0), size_t(2))),
          make_test<string, string, size_t, size_t>(
              "should get the whole string", "asdf", make_tuple(string("asdf"), size_t(0), size_t(4))),
          make_test<string, string, size_t, size_t>("should get a partial string if count is too big",
                                                    "asdf",
                                                    make_tuple(string("asdf"), size_t(0), size_t(8))),
          make_test<string, string, size_t, size_t>(
              "should get a substring", "234", make_tuple(string("1234567890"), size_t(1), size_t(3))),
          make_test<string, string, size_t, size_t>(
              "should get a word", "Paris", make_tuple(string("Where is Paris?"), size_t(9), size_t(5))),
      })));
}

TestResults test_Left() {
  return execute_suite<string, string, size_t>(make_test_suite(
      "SBF::Utils::Left(const std::string& text, const size_t length)",
      Left,
      vector<TestTuple<string, string, size_t>>({
          make_test<string, string, size_t>(
              "should get a substring", "Micro", make_tuple(string("Microsoft QBasic"), size_t(5))),
          make_test<string, string, size_t>("should get the whole string if length is equal to text.size()",
                                            "Microsoft QBasic",
                                            make_tuple(string("Microsoft QBasic"), size_t(16))),
          make_test<string, string, size_t>("should get the whole string if length is greater than text.size()",
                                            "Microsoft QBasic",
                                            make_tuple(string("Microsoft QBasic"), size_t(20))),
          make_test<string, string, size_t>(
              "should get an empty string if length is 0", "", make_tuple(string("Microsoft QBasic"), size_t(0))),
          make_test<string, string, size_t>(
              "should get an empty string if text is empty", "", make_tuple(string(""), size_t(1))),
      })));
}

TestResults test_Right() {
  return execute_suite<string, string, size_t>(make_test_suite(
      "SBF::Utils::Right(const std::string& text, const size_t length)",
      Right,
      vector<TestTuple<string, string, size_t>>({
          make_test<string, string, size_t>(
              "should get a substring", "Basic", make_tuple(string("Microsoft QBasic"), size_t(5))),
          make_test<string, string, size_t>("should get the whole string if length is equal to text.size()",
                                            "Microsoft QBasic",
                                            make_tuple(string("Microsoft QBasic"), size_t(16))),
          make_test<string, string, size_t>("should get the whole string if length is greater than text.size()",
                                            "Microsoft QBasic",
                                            make_tuple(string("Microsoft QBasic"), size_t(20))),
          make_test<string, string, size_t>(
              "should get an empty string if length is 0", "", make_tuple(string("Microsoft QBasic"), size_t(0))),
          make_test<string, string, size_t>(
              "should get an empty string if text is empty", "", make_tuple(string(""), size_t(1))),
      })));
}

TestResults test_MakeFitB() {
  return TestResults().skip(
      "SBF::Utils::MakeFitB(const std::string &prefix, const std::string &suffix, const size_t length)");
}

TestResults test_MakeFitC() {
  return execute_suite<string, string, int32_t, char>(make_test_suite(
      "SBF::Utils::MakeFitC(const std::string &text, const size_t length)",
      MakeFitC,
      vector<TestTuple<string, string, int32_t, char>>({
          make_test<string, string, int32_t, char>(
              "should truncate a string that is too long", "soft ", make_tuple(string("Microsoft QBasic"), 5, 'A')),
          make_test<string, string, int32_t, char>(
              "should pad a string that is too short", "AAMicroAAA", make_tuple(string("Micro"), 10, 'A')),
          make_test<string, string, int32_t, char>(
              "should return a string that is perfectly sized", "Micro", make_tuple(string("Micro"), 5, 'A')),
          make_test<string, string, int32_t, char>("should pad the string with spaces if padCh is the null character",
                                                   "  Micro   ",
                                                   make_tuple(string("Micro"), 10, '\0')),
          make_test<string, string, int32_t, char>(
              "should return a padded string even if text is empty", "ZZZZZZZZZZ", make_tuple(string(""), 10, 'Z')),
      })));
}

TestResults test_MakeFitL() {
  return execute_suite<string, string, int32_t, char>(make_test_suite(
      "SBF::Utils::MakeFitL(const std::string &text, const size_t length)",
      MakeFitL,
      vector<TestTuple<string, string, int32_t, char>>({
          make_test<string, string, int32_t, char>(
              "should truncate a string that is too long", "Micro", make_tuple(string("Microsoft QBasic"), 5, 'A')),
          make_test<string, string, int32_t, char>(
              "should pad a string that is too short", "MicroAAAAA", make_tuple(string("Micro"), 10, 'A')),
          make_test<string, string, int32_t, char>(
              "should return a string that is perfectly sized", "Micro", make_tuple(string("Micro"), 5, 'A')),
          make_test<string, string, int32_t, char>("should pad the string with spaces if padCh is the null character",
                                                   "Micro     ",
                                                   make_tuple(string("Micro"), 10, '\0')),
          make_test<string, string, int32_t, char>(
              "should return a padded string even if text is empty", "ZZZZZZZZZZ", make_tuple(string(""), 10, 'Z')),
      })));
}

TestResults test_MakeFitR() {
  return execute_suite<string, string, int32_t, char>(make_test_suite(
      "SBF::Utils::MakeFitR(const std::string &text, const size_t length)",
      MakeFitR,
      vector<TestTuple<string, string, int32_t, char>>({
          make_test<string, string, int32_t, char>(
              "should truncate a string that is too long", "Basic", make_tuple(string("Microsoft QBasic"), 5, 'A')),
          make_test<string, string, int32_t, char>(
              "should pad a string that is too short", "AAAAAMicro", make_tuple(string("Micro"), 10, 'A')),
          make_test<string, string, int32_t, char>(
              "should return a string that is perfectly sized", "Micro", make_tuple(string("Micro"), 5, 'A')),
          make_test<string, string, int32_t, char>("should pad the string with spaces if padCh is the null character",
                                                   "     Micro",
                                                   make_tuple(string("Micro"), 10, '\0')),
          make_test<string, string, int32_t, char>(
              "should return a padded string even if text is empty", "ZZZZZZZZZZ", make_tuple(string(""), 10, 'Z')),
      })));
}

TestResults test_LeftTrim() {
  return execute_suite<string, string>(make_test_suite(
      "SBF::Utils::LeftTrim(const std::string &text)",
      LeftTrim,
      vector<TestTuple<string, string>>({
          make_test<string, string>("should trim a string with spaces",
                                    "this is a string with spaces on either end     ",
                                    make_tuple(string("     this is a string with spaces on either end     "))),
          make_test<string, string>("should trim a string with tabs",
                                    "this is a string with tabs on either end\t\t\t\t",
                                    make_tuple(string("\t\t\t\tthis is a string with tabs on either end\t\t\t\t"))),
          make_test<string, string>("should trim a string with newlines",
                                    "this is a string with newlines on either end\n\n\n\n",
                                    make_tuple(string("\n\n\n\nthis is a string with newlines on either end\n\n\n\n"))),
          make_test<string, string>(
              "should trim a string with carrige returns",
              "this is a string with carriage returns on either end\r\r\r\r",
              make_tuple(string("\r\r\r\rthis is a string with carriage returns on either end\r\r\r\r"))),
          make_test<string, string>(
              "should trim a string with mixed whitespace",
              "this is a string with mixed whitespace on either end\f\v\r\n\t ",
              make_tuple(string(" \t\n\r\v\fthis is a string with mixed whitespace on either end\f\v\r\n\t "))),
          make_test<string, string>("should get an unmodified string if there is nothing to trim",
                                    "this is a string that won't be trimmed",
                                    make_tuple(string("this is a string that won't be trimmed"))),
          make_test<string, string>("should get an empty string for an empty string", "", make_tuple(string(""))),
          make_test<string, string>(
              "should get an empty string for an all whitespace string", "", make_tuple(string(" \t\n\r\r\n\t "))),
      })));
}

TestResults test_RightTrim() {
  return execute_suite<string, string>(make_test_suite(
      "SBF::Utils::RightTrim(const std::string &text)",
      RightTrim,
      vector<TestTuple<string, string>>({
          make_test<string, string>("should trim a string with spaces",
                                    "     this is a string with spaces on either end",
                                    make_tuple(string("     this is a string with spaces on either end     "))),
          make_test<string, string>("should trim a string with tabs",
                                    "\t\t\t\tthis is a string with tabs on either end",
                                    make_tuple(string("\t\t\t\tthis is a string with tabs on either end\t\t\t\t"))),
          make_test<string, string>("should trim a string with newlines",
                                    "\n\n\n\nthis is a string with newlines on either end",
                                    make_tuple(string("\n\n\n\nthis is a string with newlines on either end\n\n\n\n"))),
          make_test<string, string>(
              "should trim a string with carrige returns",
              "\r\r\r\rthis is a string with carriage returns on either end",
              make_tuple(string("\r\r\r\rthis is a string with carriage returns on either end\r\r\r\r"))),
          make_test<string, string>(
              "should trim a string with mixed whitespace",
              " \t\n\r\v\fthis is a string with mixed whitespace on either end",
              make_tuple(string(" \t\n\r\v\fthis is a string with mixed whitespace on either end\f\v\r\n\t "))),
          make_test<string, string>("should get an unmodified string if there is nothing to trim",
                                    "this is a string that won't be trimmed",
                                    make_tuple(string("this is a string that won't be trimmed"))),
          make_test<string, string>("should get an empty string for an empty string", "", make_tuple(string(""))),
          make_test<string, string>(
              "should get an empty string for an all whitespace string", "", make_tuple(string(" \t\n\r\r\n\t "))),
      })));
}

TestResults test_RepeatChar() {
  return execute_suite<string, size_t, char>(make_test_suite(
      "SBF::Utils::RepeatChar(const size_t length, const char ch)",
      RepeatChar,
      vector<TestTuple<string, size_t, char>>({
          make_test<string, size_t, char>("should make a string", "YYYYY", make_tuple(size_t(5), 'Y')),
          make_test<string, size_t, char>(
              "should make a string of spaces if ch is the null character", "     ", make_tuple(size_t(5), '\0')),
          make_test<string, size_t, char>("should make an empty string if length is 0", "", make_tuple(size_t(0), 'C')),
      })));
}

TestResults test_RegexReplace() {
  return TestResults()
      .skip(
          "SBF::Utils::RegexReplace(const string& text, const string& pattern, const string& replace) // TODO: Fill "
          "this in.")
      .skip("SBF::Utils::RegexReplace(const string& text, regex regex, const string& replace) // TODO: Fill this in.");
}

TestResults test_WordWrap() {
  // TODO: Treat newlines and tabs in text as spaces.
  auto fnToTest = [](string text, int32_t column_width, vector<string> expected) -> string {
    ostringstream error_message;
    try {
      vector<string> actual = WordWrap(text, column_width);
      compare(error_message, expected, actual);
    } catch (const exception& ex) {
      error_message << ex.what();
    } catch (...) {
      error_message << "threw something that was not an exception";
    }
    string error_string = error_message.str();
    if (error_string.size() > 0) {
      return error_message.str();
    }
    return "no errors";
  };
  return execute_suite<string, string, int32_t, vector<string>>(make_test_suite(
      "SBF::Utils::WordWrap(const std::string &text, const size_t max_width)",
      fnToTest,
      vector<TestTuple<string, string, int32_t, vector<string>>>({
          make_test<string, string, int32_t, vector<string>>("should return the string if it is shorter than max_width",
                                                             "no errors",
                                                             make_tuple(string("0123"), 5, vector<string>({"0123_"}))),
          make_test<string, string, int32_t, vector<string>>(
              "should return the string if its length is equal to max_width",
              "no errors",
              make_tuple(string("01234"), 5, vector<string>({"01234"}))),
          make_test<string, string, int32_t, vector<string>>(
              "should wrap a string to two lines if it has no whitespace",
              "no errors",
              make_tuple(string("012345"), 5, vector<string>({"01234", "5____"}))),
          make_test<string, string, int32_t, vector<string>>(
              "should wrap a string to three lines if it has no whitespace",
              "no errors",
              make_tuple(string("01234567890"), 5, vector<string>({"01234", "56789", "0____"}))),
          make_test<string, string, int32_t, vector<string>>(
              "should wrap a string with even spacing",
              "no errors",
              make_tuple(string("01 23 45 67 89 01"), 5, vector<string>({"01 23", "45 67", "89 01"}))),
          make_test<string, string, int32_t, vector<string>>(
              "should collapse whitespace to a single space",
              "no errors",
              make_tuple(
                  string("01 34 67 90 23 56    89      "), 5, vector<string>({"01 34", "67 90", "23 56", "89___"}))),

      })));
}

int main(int argc, char* argv[]) {
  TestResults results;

  results += test_GetIndexOf();
  results += test_GetSubstring();
  results += test_Left();
  results += test_LeftTrim();
  results += test_MakeFitC();
  results += test_MakeFitL();
  results += test_MakeFitR();
  results += test_RegexReplace();
  results += test_Right();
  results += test_RightTrim();
  results += test_RepeatChar();
  results += test_WordWrap();

  PrintResults(cout, results);

  return results.failed() + results.errors();
}
