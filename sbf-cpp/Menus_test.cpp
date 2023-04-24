#include "Menus.h"

#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include "Colors.h"
#include "test.h"

using namespace SBF;
using namespace Test;
using namespace std;

namespace Test::Menus {
TestResults test_MenuItem_constructor();
TestResults test_MenuItem_constructor_string_int();
TestResults test_MenuItem_constructor_string_int_int();
TestResults test_MenuItem_constructor_string_int_uint8_t();
TestResults test_MenuStyle_constructor();
TestResults test_MenuStyle_Adjust();
TestResults test_GetRandomMenuItemId();
TestResults test_BuildMenu();
TestResults test_BuildMenuWithValues();
TestResults test_BuildMenuWithColors();
TestResults test_PrintMenu();
TestResults test_GetTitle();
TestResults test_GetTitleWithoutValue();
TestResults test_PrintWithMaybeColor();
string escape_string(const string& text, const string& pattern = "\033", const string& replace = "\\033");
}  // End namespace Test::Menus

using namespace Test::Menus;

TestResults main_test_Menus(int argc, char* argv[]) {
  TestResults results;

  results += test_MenuItem_constructor();
  results += test_MenuItem_constructor_string_int();
  results += test_MenuItem_constructor_string_int_int();
  results += test_MenuItem_constructor_string_int_uint8_t();
  results += test_MenuStyle_constructor();
  results += test_MenuStyle_Adjust();
  results += test_GetRandomMenuItemId();
  results += test_BuildMenu();
  results += test_BuildMenuWithValues();
  results += test_BuildMenuWithColors();
  results += test_PrintMenu();
  results += test_GetTitle();
  results += test_GetTitleWithoutValue();
  results += test_PrintWithMaybeColor();

  PrintResults(cout, results);

  return results;
}

int main(int argc, char* argv[]) {
  TestResults results = main_test_Menus(argc, argv);

  return results.failed() + results.errors();
}

namespace Test::Menus {
TestResults test_MenuItem_constructor() {
  return TestResults().skip("// TODO: test_MenuItem_constructor");
}

TestResults test_MenuItem_constructor_string_int() {
  return TestResults().skip("// TODO: test_MenuItem_constructor_string_int");
}

TestResults test_MenuItem_constructor_string_int_int() {
  return TestResults().skip("// TODO: test_MenuItem_constructor_string_int_int");
}

TestResults test_MenuItem_constructor_string_int_uint8_t() {
  return TestResults().skip("// TODO: test_MenuItem_constructor_string_int_uint8_t");
}

TestResults test_MenuStyle_constructor() {
  return TestResults().skip("// TODO: test_MenuStyle_constructor");
}

TestResults test_MenuStyle_Adjust() {
  return TestResults().skip("// TODO: test_Menu_Style_Adjust");
}

TestResults test_GetRandomMenuItemId() {
  return TestResults().skip("// TODO: test_GetRandomMenuItemId");
}

TestResults test_BuildMenu() {
  return TestResults().skip("// TODO: test_BuildMenu");
}

TestResults test_BuildMenuWithValues() {
  return TestResults().skip("// TODO: test_BuildMenuWithValues");
}

TestResults test_BuildMenuWithColors() {
  return TestResults().skip("// TODO: test_BuildMenuWithColors");
}

TestResults test_PrintMenu() {
  return TestResults().skip("// TODO: test_PrintMenu");
}

TestResults test_GetTitle() {
  return TestResults().skip("// TODO: test_GetTitle");
}

TestResults test_GetTitleWithoutValue() {
  return TestResults().skip("// TODO: test_GetTitleWithoutValue");
}

TestResults test_PrintWithMaybeColor() {
  auto fnToTest = [](const string& text, uint8_t text_color, bool use_colors) -> string {
    SetForegroundColor(kColorDefaultForeground);
    SetBackgroundColor(kColorDefaultBackground);
    ostringstream error_message;
    ostringstream os;
    PrintWithMaybeColor(os, text, text_color, use_colors);
    if (GetForegroundColor() != kColorDefaultForeground) {
      error_message << " Foreground color was changed to " << GetForegroundColor();
    }
    if (GetBackgroundColor() != kColorDefaultBackground) {
      error_message << " Background color was changed to " << GetBackgroundColor();
    }
    if (error_message.str().size() > 0) {
      return error_message.str();
    }
    return escape_string(os.str());
  };
  return execute_suite(
      make_test_suite("SBF::PrintWithMaybeColor",
                      fnToTest,
                      vector<TestTuple<string, string, uint8_t, bool>>({
                          make_test<string, string, uint8_t, bool>(
                              "should write \"Hello, world!\" in dark yellow and reset the color afterward",
                              "\\033[38;5;3mHello, world!\\033[38;5;15m",
                              make_tuple(string("Hello, world!"), kColorDarkYellow, true)),
                          make_test<string, string, uint8_t, bool>(
                              "should print \"much less than we should\" without changing the color",
                              "much less than we should",
                              make_tuple(string("much less than we should"), kColorDarkGreen, false)),
                      })));
}

string escape_string(const string& text, const string& pattern, const string& replace) {
  return regex_replace(text, regex(pattern), replace);
}
}  // namespace Test::Menus
