#include "Utils.h"

#include <string>
#include <tuple>
#include <vector>

#include "test.h"

using namespace SBF;
using namespace Test;
using namespace std;

namespace Test::Utils {
TestResults test_get_index_of();
TestResults test_get_substring();
TestResults test_left();
TestResults test_make_fit_l();
TestResults test_string_dollar();
TestResults test_word_wrap();
}  // End namespace Test::Utils

using namespace Test::Utils;

TestResults main_test_Utils(int argc, char* argv[]) {
  TestResults results;

  results += test_get_index_of();
  results += test_get_substring();
  results += test_left();
  results += test_make_fit_l();
  results += test_string_dollar();
  results += test_word_wrap();

  return results;
}

namespace Test::Utils {
TestResults test_get_index_of() {
  string long_text =
      "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's "
      "standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to "
      "make a type specimen book. It has survived not only five centuries, but also the leap into electronic "
      "typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset "
      "sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker "
      "including versions of Lorem Ipsum.";
  return execute_suite<size_t, string, string, size_t>(make_test_suite(
      "SBF::get_index_of",
      get_index_of,
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

TestResults test_get_substring() {
  return execute_suite<string, string, size_t, size_t>(make_test_suite(
      "SBF::get_substring",
      get_substring,
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

TestResults test_left() {
  return execute_suite<string, string, size_t>(make_test_suite(
      "SBF::left",
      SBF::left,
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

TestResults test_make_fit_l() {
  return execute_suite<string, string, int32_t, char>(make_test_suite(
      "SBF::make_fit_l",
      make_fit_l,
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

TestResults test_string_dollar() {
  return execute_suite<string, size_t, char>(make_test_suite(
      "SBF::string_dollar",
      string_dollar,
      vector<TestTuple<string, size_t, char>>({
          make_test<string, size_t, char>("should make a string", "YYYYY", make_tuple(size_t(5), 'Y')),
          make_test<string, size_t, char>(
              "should make a string of spaces if ch is the null character", "     ", make_tuple(size_t(5), '\0')),
          make_test<string, size_t, char>("should make an empty string if length is 0", "", make_tuple(size_t(0), 'C')),
      })));
}

// string word_wrap(const string& text, int maxWidth);
TestResults test_word_wrap() {
  return execute_suite<string, string, int32_t>(make_test_suite(
      "SBF::word_wrap",
      word_wrap,
      vector<TestTuple<string, string, int32_t>>({
          make_test<string, string, int32_t>(
              "should return the string if it is shorter than max_width", "0123_", make_tuple(string("0123"), 5)),
          make_test<string, string, int32_t>(
              "should return the string if its length is equal to max_width", "01234", make_tuple(string("01234"), 5)),
          make_test<string, string, int32_t>("should wrap a string to two lines if it has no whitespace",
                                             "01234\n5____",
                                             make_tuple(string("012345"), 5)),
          make_test<string, string, int32_t>("should wrap a string to three lines if it has no whitespace",
                                             "01234\n56789\n0____",
                                             make_tuple(string("01234567890"), 5)),
          make_test<string, string, int32_t>("should wrap a string with even spacing",
                                             "01 23\n45 67\n89 01",
                                             make_tuple(string("01 23 45 67 89 01"), 5)),
          make_test<string, string, int32_t>("should collapse whitespace to a single space",
                                             "01 34\n67 90\n23 56\n89___",
                                             make_tuple(string("01 34 67 90 23 56    89      "), 5)),
          // TODO: Treat newlines and tabs in text as spaces.
      })));
}
}  // End namespace Test::Utils
