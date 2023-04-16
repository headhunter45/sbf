#include "Colors.h"
#include "test.h"
#include <string>
#include <tuple>
#include <vector>

using namespace SBF;
using namespace Test;
using namespace std;

namespace Test::Colors {
TestResults test_FillColors();
TestResults test_GetBackgroundColor();
TestResults test_GetForegroundColor();
TestResults test_SetBackgroundColor();
TestResults test_SetForegroundColor();
} // End namespace Test::Colors
using namespace Test::Colors;
namespace SBF {
    extern uint8_t g_foregroundColor;
    extern uint8_t g_backgroundColor;
}
TestResults main_test_Colors(int argc, char** argv) {
    TestResults results;
    
    results += test_FillColors();
    results += test_GetBackgroundColor();
    results += test_GetForegroundColor();
    results += test_SetBackgroundColor();
    results += test_SetForegroundColor();

    return results;
}
namespace Test::Colors {
TestResults test_FillColors() {
    return execute_suite<string>(make_test_suite(
        "SBF::FillColors",
        []()->string {
            ostringstream error_message;
            vector<uint8_t> expected = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
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
            make_test<string>(
                "should fill colors",
                "no errors",
                make_tuple()),
        })
    ));
}

TestResults test_GetBackgroundColor() {
    auto fnToTest = [](uint8_t background_color)->uint8_t {
        SBF::g_backgroundColor = background_color;
        return GetBackgroundColor();
    };
    return execute_suite<uint32_t, uint32_t>(make_test_suite(
        "SBF::GetBackgroundColor",
        fnToTest,
        vector<TestTuple<uint32_t, uint32_t>>({
            make_test<uint32_t, uint32_t>(
                "should get kColorDarkBlack when background color is 0",
                kColorDarkBlack,
                make_tuple(0U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorDarkBlue when background color is 1",
                kColorDarkBlue,
                make_tuple(1U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorDarkGreen when background color is 2",
                kColorDarkGreen,
                make_tuple(2U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorDarkCyan when background color is 3",
                kColorDarkCyan,
                make_tuple(3U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorDarkRed when background color is 4",
                kColorDarkRed,
                make_tuple(4U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorDarkMagenta when background color is 5",
                kColorDarkMagenta,
                make_tuple(5U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorDarkOrange when background color is 6",
                kColorDarkOrange,
                make_tuple(6U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorDarkYellow when background color is 6",
                kColorDarkYellow,
                make_tuple(6U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorDarkWhite when background color is 7",
                kColorDarkWhite,
                make_tuple(7U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorBrightBlack when background color is 8",
                kColorBrightBlack,
                make_tuple(8U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorBrightBlue when background color is 9",
                kColorBrightBlue,
                make_tuple(9U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorBrightGreen when background color is 10",
                kColorBrightGreen,
                make_tuple(10U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorBrightCyan when background color is 11",
                kColorBrightCyan,
                make_tuple(11U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorBrightRed when background color is 12",
                kColorBrightRed,
                make_tuple(12U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorBrightMagenta when background color is 13",
                kColorBrightMagenta,
                make_tuple(13U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorBrightOrange when background color is 14",
                kColorBrightOrange,
                make_tuple(14U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorBrightYellow when background color is 14",
                kColorBrightYellow,
                make_tuple(14U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorBrightWhite when background color is 15",
                kColorBrightWhite,
                make_tuple(15U)),
        })
    ));
}

TestResults test_GetForegroundColor() {
    auto fnToTest = [](uint8_t foreground_color)->uint8_t {
        SBF::g_foregroundColor = foreground_color;
        return GetForegroundColor();
    };
    return execute_suite<uint32_t, uint32_t>(make_test_suite(
        "SBF::GetForegroundColor",
        fnToTest,
        vector<TestTuple<uint32_t, uint32_t>>({
           make_test<uint32_t, uint32_t>(
                "should get kColorDarkBlack when foreground color is 0",
                kColorDarkBlack,
                make_tuple(0U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorDarkBlue when foreground color is 1",
                kColorDarkBlue,
                make_tuple(1U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorDarkGreen when foreground color is 2",
                kColorDarkGreen,
                make_tuple(2U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorDarkCyan when foreground color is 3",
                kColorDarkCyan,
                make_tuple(3U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorDarkRed when foreground color is 4",
                kColorDarkRed,
                make_tuple(4U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorDarkMagenta when foreground color is 5",
                kColorDarkMagenta,
                make_tuple(5U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorDarkOrange when foreground color is 6",
                kColorDarkOrange,
                make_tuple(6U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorDarkYellow when foreground color is 6",
                kColorDarkYellow,
                make_tuple(6U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorDarkWhite when foreground color is 7",
                kColorDarkWhite,
                make_tuple(7U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorBrightBlack when foreground color is 8",
                kColorBrightBlack,
                make_tuple(8U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorBrightBlue when foreground color is 9",
                kColorBrightBlue,
                make_tuple(9U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorBrightGreen when foreground color is 10",
                kColorBrightGreen,
                make_tuple(10U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorBrightCyan when foreground color is 11",
                kColorBrightCyan,
                make_tuple(11U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorBrightRed when foreground color is 12",
                kColorBrightRed,
                make_tuple(12U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorBrightMagenta when foreground color is 13",
                kColorBrightMagenta,
                make_tuple(13U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorBrightOrange when foreground color is 14",
                kColorBrightOrange,
                make_tuple(14U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorBrightYellow when foreground color is 14",
                kColorBrightYellow,
                make_tuple(14U)),
            make_test<uint32_t, uint32_t>(
                "should get kColorBrightWhite when foreground color is 15",
                kColorBrightWhite,
                make_tuple(15U)),    
        })
    ));
}

TestResults test_SetBackgroundColor() {
    auto fnToTest = [](uint8_t color)->uint8_t {
        SBF::g_backgroundColor = 255;
        SetBackgroundColor(color);
        return SBF::g_backgroundColor;
    };
    return execute_suite<uint32_t, uint32_t>(make_test_suite(
        "SBF::SetBackgroundColor",
        fnToTest,
        vector<TestTuple<uint32_t, uint32_t>>({
            make_test<uint32_t, uint32_t>(
                "should set background color to kColorDarkBlack when color is 0",
                kColorDarkBlack,
                make_tuple(0U)),
            make_test<uint32_t, uint32_t>(
                "should set background color to kColorDarkBlue when color is 1",
                kColorDarkBlue,
                make_tuple(1U)),
            make_test<uint32_t, uint32_t>(
                "should set background color to kColorDarkGreen when color is 2",
                kColorDarkGreen,
                make_tuple(2U)),
            make_test<uint32_t, uint32_t>(
                "should set background color to kColorDarkCyan when color is 3",
                kColorDarkCyan,
                make_tuple(3U)),
            make_test<uint32_t, uint32_t>(
                "should set background color to kColorDarkRed when color is 4",
                kColorDarkRed,
                make_tuple(4U)),
            make_test<uint32_t, uint32_t>(
                "should set background color to kColorDarkMagenta when color is 5",
                kColorDarkMagenta,
                make_tuple(5U)),
            make_test<uint32_t, uint32_t>(
                "should set background color to kColorDarkOrange when color is 6",
                kColorDarkOrange,
                make_tuple(6U)),
            make_test<uint32_t, uint32_t>(
                "should set background color to kColorDarkYellow when color is 6",
                kColorDarkYellow,
                make_tuple(6U)),
            make_test<uint32_t, uint32_t>(
                "should set background color to kColorDarkWhite when color is 7",
                kColorDarkWhite,
                make_tuple(7U)),
            make_test<uint32_t, uint32_t>(
                "should set background color to kColorBrightBlack when color is 8",
                kColorBrightBlack,
                make_tuple(8U)),
            make_test<uint32_t, uint32_t>(
                "should set background color to kColorBrightBlue when color is 9",
                kColorBrightBlue,
                make_tuple(9U)),
            make_test<uint32_t, uint32_t>(
                "should set background color to kColorBrightGreen when color is 10",
                kColorBrightGreen,
                make_tuple(10U)),
            make_test<uint32_t, uint32_t>(
                "should set background color to kColorBrightCyan when color is 11",
                kColorBrightCyan,
                make_tuple(11U)),
            make_test<uint32_t, uint32_t>(
                "should set background color to kColorBrightRed when color is 12",
                kColorBrightRed,
                make_tuple(12U)),
            make_test<uint32_t, uint32_t>(
                "should set background color to kColorBrightMagenta when color is 13",
                kColorBrightMagenta,
                make_tuple(13U)),
            make_test<uint32_t, uint32_t>(
                "should set background color to kColorBrightOrange when color is 14",
                kColorBrightOrange,
                make_tuple(14U)),
            make_test<uint32_t, uint32_t>(
                "should set background color to kColorBrightYellow when color is 14",
                kColorBrightYellow,
                make_tuple(14U)),
            make_test<uint32_t, uint32_t>(
                "should set background color to kColorBrightWhite when color is 15",
                kColorBrightWhite,
                make_tuple(15U)),
        })
    ));
}

TestResults test_SetForegroundColor() {
    auto fnToTest = [](uint8_t color)->uint8_t {
        SBF::g_foregroundColor = 255;
        SetForegroundColor(color);
        return SBF::g_foregroundColor;
    };
    return execute_suite<uint32_t, uint32_t>(make_test_suite(
        "SBF::SetForegroundColor",
        fnToTest,
        vector<TestTuple<uint32_t, uint32_t>>({
            make_test<uint32_t, uint32_t>(
                "should set foreground color to kColorDarkBlack when color is 0",
                kColorDarkBlack,
                make_tuple(0U)),
            make_test<uint32_t, uint32_t>(
                "should set foreground color to kColorDarkBlue when color is 1",
                kColorDarkBlue,
                make_tuple(1U)),
            make_test<uint32_t, uint32_t>(
                "should set foreground color to kColorDarkGreen when color is 2",
                kColorDarkGreen,
                make_tuple(2U)),
            make_test<uint32_t, uint32_t>(
                "should set foreground color to kColorDarkCyan when color is 3",
                kColorDarkCyan,
                make_tuple(3U)),
            make_test<uint32_t, uint32_t>(
                "should set foreground color to kColorDarkRed when color is 4",
                kColorDarkRed,
                make_tuple(4U)),
            make_test<uint32_t, uint32_t>(
                "should set foreground color to kColorDarkMagenta when color is 5",
                kColorDarkMagenta,
                make_tuple(5U)),
            make_test<uint32_t, uint32_t>(
                "should set foreground color to kColorDarkOrange when color is 6",
                kColorDarkOrange,
                make_tuple(6U)),
            make_test<uint32_t, uint32_t>(
                "should set foreground color to kColorDarkYellow when color is 6",
                kColorDarkYellow,
                make_tuple(6U)),
            make_test<uint32_t, uint32_t>(
                "should set foreground color to kColorDarkWhite when color is 7",
                kColorDarkWhite,
                make_tuple(7U)),
            make_test<uint32_t, uint32_t>(
                "should set foreground color to kColorBrightBlack when color is 8",
                kColorBrightBlack,
                make_tuple(8U)),
            make_test<uint32_t, uint32_t>(
                "should set foreground color to kColorBrightBlue when color is 9",
                kColorBrightBlue,
                make_tuple(9U)),
            make_test<uint32_t, uint32_t>(
                "should set foreground color to kColorBrightGreen when color is 10",
                kColorBrightGreen,
                make_tuple(10U)),
            make_test<uint32_t, uint32_t>(
                "should set foreground color to kColorBrightCyan when color is 11",
                kColorBrightCyan,
                make_tuple(11U)),
            make_test<uint32_t, uint32_t>(
                "should set foreground color to kColorBrightRed when color is 12",
                kColorBrightRed,
                make_tuple(12U)),
            make_test<uint32_t, uint32_t>(
                "should set foreground color to kColorBrightMagenta when color is 13",
                kColorBrightMagenta,
                make_tuple(13U)),
            make_test<uint32_t, uint32_t>(
                "should set foreground color to kColorBrightOrange when color is 14",
                kColorBrightOrange,
                make_tuple(14U)),
            make_test<uint32_t, uint32_t>(
                "should set foreground color to kColorBrightYellow when color is 14",
                kColorBrightYellow,
                make_tuple(14U)),
            make_test<uint32_t, uint32_t>(
                "should set foreground color to kColorBrightWhite when color is 15",
                kColorBrightWhite,
                make_tuple(15U)),
        })
    ));
}
} // End namespace Test::Colors
