#include "Colors.h"

#include <iostream>
#include <regex>
#include <string>
#include <tuple>
#include <vector>

#include "test.h"

namespace {
using namespace SBF;
using namespace Test;
using namespace std;
}  // End namespace

namespace SBF {
extern uint8_t g_foreground_color;
extern uint8_t g_background_color;
}  // namespace SBF

string escape_string(const string& text, const string& pattern = "\033", const string& replace = "\\033") {
  return regex_replace(text, regex(pattern), replace);
}

TestResults test_FillColors() {
  return execute_suite<string>(make_test_suite(
      "SBF::FillColors",
      []() -> string {
        ostringstream error_message;
        vector<uint8_t> expected = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
        vector<uint8_t> actual = {255};
        FillColors(actual);
        compare(error_message, expected, actual);
        string error = error_message.str();
        if (error.size() > 0) {
          return error;
        }
        return "no errors";
      },
      vector<TestTuple<string>>({
          make_test<string>("should fill colors", "no errors", make_tuple()),
      })));
}

TestResults test_GetBackgroundColor() {
  auto fnToTest = [](uint8_t background_color) -> uint8_t {
    SBF::g_background_color = background_color;
    return GetBackgroundColor();
  };
  return execute_suite<uint32_t, uint32_t>(make_test_suite(
      "SBF::GetBackgroundColor",
      fnToTest,
      vector<TestTuple<uint32_t, uint32_t>>({
          make_test<uint32_t, uint32_t>(
              "should get kColorDarkBlack when background color is 0", kColorDarkBlack, make_tuple(0U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorDarkBlue when background color is 1", kColorDarkRed, make_tuple(1U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorDarkGreen when background color is 2", kColorDarkGreen, make_tuple(2U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorDarkCyan when background color is 3", kColorDarkYellow, make_tuple(3U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorDarkRed when background color is 4", kColorDarkBlue, make_tuple(4U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorDarkMagenta when background color is 5", kColorDarkMagenta, make_tuple(5U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorDarkYellow when background color is 6", kColorDarkCyan, make_tuple(6U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorDarkWhite when background color is 7", kColorDarkWhite, make_tuple(7U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorBrightBlack when background color is 8", kColorBrightBlack, make_tuple(8U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorBrightBlue when background color is 9", kColorBrightRed, make_tuple(9U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorBrightGreen when background color is 10", kColorBrightGreen, make_tuple(10U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorBrightCyan when background color is 11", kColorBrightYellow, make_tuple(11U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorBrightRed when background color is 12", kColorBrightBlue, make_tuple(12U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorBrightMagenta when background color is 13", kColorBrightMagenta, make_tuple(13U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorBrightYellow when background color is 14", kColorBrightCyan, make_tuple(14U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorBrightWhite when background color is 15", kColorBrightWhite, make_tuple(15U)),
      })));
}

TestResults test_GetForegroundColor() {
  auto fnToTest = [](uint8_t foreground_color) -> uint8_t {
    SBF::g_foreground_color = foreground_color;
    return GetForegroundColor();
  };
  return execute_suite<uint32_t, uint32_t>(make_test_suite(
      "SBF::GetForegroundColor",
      fnToTest,
      vector<TestTuple<uint32_t, uint32_t>>({
          make_test<uint32_t, uint32_t>(
              "should get kColorDarkBlack when foreground color is 0", kColorDarkBlack, make_tuple(0U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorDarkBlue when foreground color is 1", kColorDarkRed, make_tuple(1U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorDarkGreen when foreground color is 2", kColorDarkGreen, make_tuple(2U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorDarkCyan when foreground color is 3", kColorDarkYellow, make_tuple(3U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorDarkRed when foreground color is 4", kColorDarkBlue, make_tuple(4U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorDarkMagenta when foreground color is 5", kColorDarkMagenta, make_tuple(5U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorDarkYellow when foreground color is 6", kColorDarkCyan, make_tuple(6U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorDarkWhite when foreground color is 7", kColorDarkWhite, make_tuple(7U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorBrightBlack when foreground color is 8", kColorBrightBlack, make_tuple(8U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorBrightBlue when foreground color is 9", kColorBrightRed, make_tuple(9U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorBrightGreen when foreground color is 10", kColorBrightGreen, make_tuple(10U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorBrightCyan when foreground color is 11", kColorBrightYellow, make_tuple(11U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorBrightRed when foreground color is 12", kColorBrightBlue, make_tuple(12U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorBrightMagenta when foreground color is 13", kColorBrightMagenta, make_tuple(13U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorBrightYellow when foreground color is 14", kColorBrightCyan, make_tuple(14U)),
          make_test<uint32_t, uint32_t>(
              "should get kColorBrightWhite when foreground color is 15", kColorBrightWhite, make_tuple(15U)),
      })));
}

TestResults test_SetBackgroundColor() {
  // TODO: Test that SetBackgroundColor returns the previous background color.
  auto fnToTest = [](uint8_t color) -> uint8_t {
    SBF::g_background_color = 255;
    SetBackgroundColor(color);
    return SBF::g_background_color;
  };
  return execute_suite<uint32_t, uint32_t>(make_test_suite(
      "SBF::SetBackgroundColor",
      fnToTest,
      vector<TestTuple<uint32_t, uint32_t>>({
          make_test<uint32_t, uint32_t>(
              "should set background color to kColorDarkBlack when color is 0", kColorDarkBlack, make_tuple(0U)),
          make_test<uint32_t, uint32_t>(
              "should set background color to kColorDarkBlue when color is 4", kColorDarkBlue, make_tuple(4U)),
          make_test<uint32_t, uint32_t>(
              "should set background color to kColorDarkGreen when color is 2", kColorDarkGreen, make_tuple(2U)),
          make_test<uint32_t, uint32_t>(
              "should set background color to kColorDarkCyan when color is 6", kColorDarkCyan, make_tuple(6U)),
          make_test<uint32_t, uint32_t>(
              "should set background color to kColorDarkRed when color is 1", kColorDarkRed, make_tuple(1U)),
          make_test<uint32_t, uint32_t>(
              "should set background color to kColorDarkMagenta when color is 5", kColorDarkMagenta, make_tuple(5U)),
          make_test<uint32_t, uint32_t>(
              "should set background color to kColorDarkYellow when color is 3", kColorDarkYellow, make_tuple(3U)),
          make_test<uint32_t, uint32_t>(
              "should set background color to kColorDarkWhite when color is 7", kColorDarkWhite, make_tuple(7U)),
          make_test<uint32_t, uint32_t>(
              "should set background color to kColorBrightBlack when color is 8", kColorBrightBlack, make_tuple(8U)),
          make_test<uint32_t, uint32_t>(
              "should set background color to kColorBrightBlue when color is 12", kColorBrightBlue, make_tuple(12U)),
          make_test<uint32_t, uint32_t>(
              "should set background color to kColorBrightGreen when color is 10", kColorBrightGreen, make_tuple(10U)),
          make_test<uint32_t, uint32_t>(
              "should set background color to kColorBrightCyan when color is 14", kColorBrightCyan, make_tuple(14U)),
          make_test<uint32_t, uint32_t>(
              "should set background color to kColorBrightRed when color is 9", kColorBrightRed, make_tuple(9U)),
          make_test<uint32_t, uint32_t>("should set background color to kColorBrightMagenta when color is 13",
                                        kColorBrightMagenta,
                                        make_tuple(13U)),
          make_test<uint32_t, uint32_t>("should set background color to kColorBrightYellow when color is 11",
                                        kColorBrightYellow,
                                        make_tuple(11U)),
          make_test<uint32_t, uint32_t>(
              "should set background color to kColorBrightWhite when color is 15", kColorBrightWhite, make_tuple(15U)),
      })));
}

TestResults test_SetForegroundColor() {
  // TODO: Test that SetForegroundColor returns the previous background color.
  auto fnToTest = [](uint8_t color) -> uint8_t {
    SBF::g_foreground_color = 255;
    SetForegroundColor(color);
    return SBF::g_foreground_color;
  };
  return execute_suite<uint32_t, uint32_t>(make_test_suite(
      "SBF::SetForegroundColor",
      fnToTest,
      vector<TestTuple<uint32_t, uint32_t>>({
          make_test<uint32_t, uint32_t>(
              "should set foreground color to kColorDarkBlack when color is 0", kColorDarkBlack, make_tuple(0U)),
          make_test<uint32_t, uint32_t>(
              "should set foreground color to kColorDarkBlue when color is 4", kColorDarkBlue, make_tuple(4U)),
          make_test<uint32_t, uint32_t>(
              "should set foreground color to kColorDarkGreen when color is 2", kColorDarkGreen, make_tuple(2U)),
          make_test<uint32_t, uint32_t>(
              "should set foreground color to kColorDarkCyan when color is 6", kColorDarkCyan, make_tuple(6U)),
          make_test<uint32_t, uint32_t>(
              "should set foreground color to kColorDarkRed when color is 1", kColorDarkRed, make_tuple(1U)),
          make_test<uint32_t, uint32_t>(
              "should set foreground color to kColorDarkMagenta when color is 5", kColorDarkMagenta, make_tuple(5U)),
          make_test<uint32_t, uint32_t>(
              "should set foreground color to kColorDarkYellow when color is 3", kColorDarkYellow, make_tuple(3U)),
          make_test<uint32_t, uint32_t>(
              "should set foreground color to kColorDarkWhite when color is 7", kColorDarkWhite, make_tuple(7U)),
          make_test<uint32_t, uint32_t>(
              "should set foreground color to kColorBrightBlack when color is 8", kColorBrightBlack, make_tuple(8U)),
          make_test<uint32_t, uint32_t>(
              "should set foreground color to kColorBrightBlue when color is 12", kColorBrightBlue, make_tuple(12U)),
          make_test<uint32_t, uint32_t>(
              "should set foreground color to kColorBrightGreen when color is 10", kColorBrightGreen, make_tuple(10U)),
          make_test<uint32_t, uint32_t>(
              "should set foreground color to kColorBrightCyan when color is 14", kColorBrightCyan, make_tuple(14U)),
          make_test<uint32_t, uint32_t>(
              "should set foreground color to kColorBrightRed when color is 9", kColorBrightRed, make_tuple(9U)),
          make_test<uint32_t, uint32_t>("should set foreground color to kColorBrightMagenta when color is 13",
                                        kColorBrightMagenta,
                                        make_tuple(13U)),
          make_test<uint32_t, uint32_t>("should set foreground color to kColorBrightYellow when color is 11",
                                        kColorBrightYellow,
                                        make_tuple(11U)),
          make_test<uint32_t, uint32_t>(
              "should set foreground color to kColorBrightWhite when color is 15", kColorBrightWhite, make_tuple(15U)),
      })));
}

TestResults test_Reset() {
  string suite_name = "SBF::Reset";
  string test_name = "should write the reset code to the stream";
  string expected = "\\033[m";
  auto fnToTest = []() -> string {
    ostringstream os;
    os << Reset;
    return escape_string(os.str());
  };
  return execute_suite(make_test_suite(
      suite_name, fnToTest, vector<TestTuple<string>>({make_test<string>(test_name, expected, make_tuple())})));
}

TestResults test_ForegroundColor() {
  auto fnToTest = [](uint8_t color) -> string {
    SetForegroundColor(color);
    ostringstream os;
    os << ForegroundColor;
    return escape_string(os.str());
  };
  return execute_suite(
      make_test_suite("SBF::ForegroundColor",
                      fnToTest,
                      vector<TestTuple<string, uint8_t>>({
                          make_test<string, uint8_t>("should write \"\\033[38;5;15m\" kColorBrightWhite to the stream",
                                                     "\\033[38;5;15m",
                                                     make_tuple(kColorBrightWhite)),
                          make_test<string, uint8_t>("should write \"\\033[38;5;11m\" kColorBrightYellow to the stream",
                                                     "\\033[38;5;11m",
                                                     make_tuple(kColorBrightYellow)),
                          make_test<string, uint8_t>("should write \"\\033[38;5;2m\" kColorDarkGreen to the stream",
                                                     "\\033[38;5;2m",
                                                     make_tuple(kColorDarkGreen)),
                          make_test<string, uint8_t>("should write \"\\033[38;5;4m\" kColorDarkBlue to the stream",
                                                     "\\033[38;5;4m",
                                                     make_tuple(kColorDarkBlue)),
                      })));
}

TestResults test_BackgroundColor() {
  auto fnToTest = [](uint8_t color) -> string {
    SetBackgroundColor(color);
    ostringstream os;
    os << BackgroundColor;
    return escape_string(os.str());
  };
  return execute_suite(
      make_test_suite("SBF::BackgroundColor",
                      fnToTest,
                      vector<TestTuple<string, uint8_t>>({
                          make_test<string, uint8_t>("should write \"\\033[48;5;15m\" kColorBrightWhite to the stream",
                                                     "\\033[48;5;15m",
                                                     make_tuple(kColorBrightWhite)),
                          make_test<string, uint8_t>("should write \"\\033[48;5;11m\" kColorBrightYellow to the stream",
                                                     "\\033[48;5;11m",
                                                     make_tuple(kColorBrightYellow)),
                          make_test<string, uint8_t>("should write \"\\033[48;5;2m\" kColorDarkGreen to the stream",
                                                     "\\033[48;5;2m",
                                                     make_tuple(kColorDarkGreen)),
                          make_test<string, uint8_t>("should write \"\\033[48;5;4m\" kColorDarkBlue to the stream",
                                                     "\\033[48;5;4m",
                                                     make_tuple(kColorDarkBlue)),
                      })));
}

TestResults test_Colors() {
  // TODO: Find a way to check for the presence of both colors and no extra characters without regard to their order.
  auto fnToTest = [](uint8_t foreground_color, uint8_t background_color) -> string {
    SetForegroundColor(foreground_color);
    SetBackgroundColor(background_color);
    ostringstream os;
    os << SBF::Colors;
    return escape_string(os.str());
  };
  return execute_suite(make_test_suite(
      "SBF::ForegroundColor",
      fnToTest,
      vector<TestTuple<string, uint8_t, uint8_t>>({
          make_test<string, uint8_t, uint8_t>("should write \"\\033[38;5;15m\\033[48;5;6m\" to the stream",
                                              "\\033[38;5;15m\\033[48;5;6m",
                                              make_tuple(kColorBrightWhite, kColorDarkCyan)),
          make_test<string, uint8_t, uint8_t>("should write \"\\033[38;5;11m\\033[48;5;2m\" to the stream",
                                              "\\033[38;5;11m\\033[48;5;2m",
                                              make_tuple(kColorBrightYellow, kColorDarkGreen)),
          make_test<string, uint8_t, uint8_t>("should write \"\\033[38;5;2m\\033[48;5;13m\" to the stream",
                                              "\\033[38;5;2m\\033[48;5;13m",
                                              make_tuple(kColorDarkGreen, kColorBrightMagenta)),
          make_test<string, uint8_t, uint8_t>("should write \"\\033[38;5;4m\\033[48;5;1m\" to the stream",
                                              "\\033[38;5;4m\\033[48;5;1m",
                                              make_tuple(kColorDarkBlue, kColorDarkRed)),
      })));
}

TestResults test_TrueColorForeground() {
  // TODO: test_TrueColorForeground();
  return TestResults().skip("// TODO: test_TrueColorForeground");
}

TestResults test_TrueColorBackground() {
  // TODO: test_TrueColorBackground();
  return TestResults().skip("// TODO: test_TrueColorBackground");
}

int main(int argc, char* argv[]) {
  TestResults results;

  results += test_FillColors();
  results += test_GetBackgroundColor();
  results += test_GetForegroundColor();
  results += test_SetBackgroundColor();
  results += test_SetForegroundColor();
  results += test_Reset();
  results += test_ForegroundColor();
  results += test_BackgroundColor();
  results += test_Colors();
  results += test_TrueColorForeground();
  results += test_TrueColorBackground();

  PrintResults(cout, results);

  return results.failed() + results.errors();
}
