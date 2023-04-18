#include "Utils.h"
#include "test.h"
#include <string>
#include <tuple>
#include <vector>

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
} // End namespace Test::Utils
using namespace Test::Utils;

TestResults main_test_Utils(int argc, char** argv) {
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
//size_t get_index_of(const string& text, const string& search, size_t start);
TestResults test_get_index_of() {
    return execute_suite<size_t, string, string, size_t>(make_test_suite(
        "SBF::get_index_of",
        get_index_of,
        vector<TestTuple<size_t, string, string, size_t>>({
            make_test<size_t, string, string, size_t>(
                "should get {0, \"\"} for invalid rank id 0",
                1,
                make_tuple(string(""), string(""), size_t(0))),
        })
    ));
}
//string get_substring(const string& text, int32_t var1, int32_t var2);
TestResults test_get_substring() {
    return TestResults();
}
//string left(const string& text, size_t length);
TestResults test_left() {
    return TestResults();
}
//string make_fit_l(const string& text, size_t length, char paddCh);
TestResults test_make_fit_l() {
    return TestResults();
}
//string string_dollar(size_t length, char ch);
TestResults test_string_dollar() {
    return TestResults();
}
//string word_wrap(const string& text, int maxWidth);
TestResults test_word_wrap() {
    return TestResults();
}
} // End namespace Test::Utils
