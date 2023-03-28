#define _XOPEN_SOURCE_EXTENDED
#include <iostream>
#include <cstdio>
#include <string>
#include <cstdint>
#include <vector>

using namespace std;
using std::wcout;

typedef tuple<size_t, uint32_t> test_method_result;

size_t get_index_of(const wstring& text, const wstring& search, size_t start);
wstring word_wrap(const wstring& text, int maxWidth);
wstring get_substring(const wstring& text, int32_t var1, int32_t var2);
wstring make_fit_l(const wstring& text, size_t length, wchar_t paddCh);
wstring left(const wstring& text, size_t length);
wstring string_dollar(size_t length, wchar_t ch);
void do_pass_fail(bool passed, uint32_t& failureCount);

uint32_t do_pass_fail(bool passed) {
    if (passed) {
        wcout << "Result: PASS" << endl;
        return 0;
    } else {
        wcout << "Result: FAILURE" << endl;
        return 1;
    }
}

// Want to call with something like r = test_fn<string_dollar, wstring, size_t, wchar_t>(L"AAAAA", 5, L'A');
// template<typename _F1, typename _T1, typename... _T2>
// test_method_result test_fn(vector<pair<_T1, tuple<_T2...>>> tests) {
//     size_t testsRun = 0;
//     uint32_t failures = 0;
//     wcout << "Testing function " << "..." << endl;
//     for_each(tests.begin(), tests.end(), [testsRun, failures](pair<_T1, tuple<_T2...>> data) {
//         const auto& expected = pair.first;
//           // TODO: expand _T2/data.second into a series of parameters to use when calling _F1.
//         const auto& actual = _F1(get<0>(data)...);//get_index_of(get<0>(pair.second), get<1>(pair.second), get<2>(pair.second));
//         wcout << "Expected: " << expected << endl;
//         wcout << "Actual:   " << actual << endl;
//         failureCount += do_pass_fail(expected == actual);
//     });
//     wcout << failures << " failures" << endl;
//     return make_tuple(testsRun, failures);
// }

test_method_result test_get_index_of() {
    wstring longText = L"Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.";
    uint32_t failureCount = 0;
    vector<pair<size_t, const tuple<const wstring, const wstring, size_t>>> tests = {
        pair(22, make_tuple(longText, L"dummy", 0)),
        pair(-1, make_tuple(longText, L"acid", 0)),
        pair(120, make_tuple(longText, L"dummy", 100)),
        pair(-1, make_tuple(longText, L"dummy", longText.size())),
        pair(6, make_tuple(L"these are words", L"are", 0)),
        pair(4, make_tuple(L"one two one two", L"two", 0)),
        pair(12, make_tuple(L"one two one two", L"two", 5)),
    };

    wcout << "Testing function get_index_of(const wstring&, const wstring&, size_t)" << endl;
    for_each(tests.begin(), tests.end(), [&failureCount](const pair<size_t, const tuple<const wstring&, const wstring&, size_t>>& pair) {
        const auto& expected = pair.first;
        const auto& actual = get_index_of(get<0>(pair.second), get<1>(pair.second), get<2>(pair.second));
        wcout << "Expected: " << expected << endl;
        wcout << "Actual:   " << actual << endl;
        failureCount += do_pass_fail(expected == actual);
    });
    wcout << failureCount << " failures" << endl;

    return make_tuple(tests.size(), failureCount);
}

test_method_result test_string_dollar() {
    uint32_t failureCount = 0;
    vector<pair<const wstring, const tuple<size_t, wchar_t>>> tests = {
        pair(L"AAAAA", make_tuple(5, L'A')),
    };

    wcout << "Testing function string_dollar(size_t, wchar_t)" << endl;
    for_each(tests.begin(), tests.end(), [&failureCount](const pair<const wstring&, const tuple<size_t, wchar_t>>& pair) {
        const auto& expected = pair.first;
        const auto& actual = string_dollar(get<0>(pair.second), get<1>(pair.second));
        wcout << "Expected " << expected << endl;
        wcout << "Actual:  " << actual << endl;
        failureCount += do_pass_fail(expected == actual);
    });
    wcout << failureCount << " failures" << endl;

    return make_tuple(tests.size(), failureCount);
}

test_method_result test_left() {
    uint32_t failureCount = 0;
    vector<pair<const wstring, const tuple<const wstring, size_t>>> tests = {
        pair(L"Micro", make_tuple(L"Microsoft QBasic", 5)),
    };

    wcout << "Testing function left(wstring, size_t)" << endl;
    for_each(tests.begin(), tests.end(), [&failureCount](const pair<const wstring&, const tuple<const wstring&, size_t>>& pair) {
        const auto& expected = pair.first;
        const auto& actual = left(get<0>(pair.second), get<1>(pair.second));
        wcout << "Expected: " << expected << endl;
        wcout << "Actual:   " << actual << endl;
        failureCount += do_pass_fail(expected == actual);
    });
    wcout << failureCount << " failures" << endl;

    return make_tuple(tests.size(), failureCount);
}

test_method_result test_make_fit_l() {
    uint32_t failureCount = 0;
    vector<pair<const wstring, const tuple<const wstring, size_t, wchar_t>>> tests = {
        pair(L"12___", make_tuple(L"12", 5, L'_')),
    };

    wcout << "Testing function make_fit_l(const wstring&, size_t, const wchar_t)" << endl;
    for_each(tests.begin(), tests.end(), [&failureCount](const pair<const wstring&, const tuple<const wstring&, size_t, wchar_t>>& pair) {
        const auto& expected = pair.first;
        const auto& actual = make_fit_l(get<0>(pair.second), get<1>(pair.second), get<2>(pair.second));
        wcout << "Expected: " << expected << endl;
        wcout << "Actual:   " << actual << endl;
        failureCount += do_pass_fail(expected == actual);
    });
    wcout << failureCount << " failures" << endl;

    return make_tuple(tests.size(), failureCount);
}

test_method_result test_get_substring() {
    uint32_t failureCount = 0;
    vector<pair<const wstring, const tuple<const wstring, size_t, size_t>>> tests = {
        pair(L"234", make_tuple(L"1234567890", 1, 3)),
        pair(L"Paris", make_tuple(L"Where is Paris?", 10-1, 5)),
    };

    wcout << "Testing function get_substring(const wstring&, const size_t, const size_t)" << endl;
    for_each(tests.begin(), tests.end(), [&failureCount](const pair<const wstring&, const tuple<const wstring&, size_t, size_t>>& pair) {
        const auto& expected = pair.first;
        const auto& actual = get_substring(get<0>(pair.second), get<1>(pair.second), get<2>(pair.second));
        wcout << "Expected: " << expected << endl;
        wcout << "Actual:   " << actual;
        failureCount += do_pass_fail(expected == actual);
    });
    wcout << failureCount << " failures" << endl;

    return make_tuple(tests.size(), failureCount);
}

test_method_result test_word_wrap() {
    uint32_t failureCount = 0;
    wstring output = L"";
    vector<pair<wstring, wstring>> tests = {
        {L"0123_", L"0123"},
        {L"01234", L"01234"},
        {L"01234\n5____", L"012345"},
        {L"01234\n56789\n0____", L"01234567890"},
        {L"01 23\n45 67\n89 01", L"01 23 45 67 89 01"},
        {L"01 34\n67 90\n23 56\n89___", L"01 34 67 90 23 56    89      "},
    };

    wcout << "Testing function word_wrap(const wstring&, const size_t)" << endl;
    int maxWidth = 5;
    for_each(tests.begin(), tests.end(), [&failureCount, maxWidth](const pair<const wstring&, const wstring&>& pair ) {
        const auto& expected = pair.first;
        const auto& actual = word_wrap(pair.second, maxWidth);
        wcout << "Expected:" << endl << expected << endl;
        wcout << "Actual:" << endl << actual << endl;
        failureCount += do_pass_fail(expected == actual);
    });
    wcout << failureCount << " failures" << endl;
    return make_tuple(tests.size(), failureCount);
}

test_method_result operator+(const test_method_result& first, const test_method_result second) {
    return make_tuple(get<0>(first) + get<0>(second), get<1>(first) + get<1>(second));
}

int main(int argc, char* argv[]) {
    // TODO: Come up with a good way to enable/disable tests.
    // Maybe replace the expected, params pairs with another tuple for enabled, expected, params.
    // Maybe have the test functions take an enabled bool param.

    setlocale(LC_ALL, "");
    // TODO: Define operator+= for test_method_result
    test_method_result results;
    results = results + test_get_index_of();
    results = results + test_word_wrap();
    results = results + test_get_substring();
    results = results + test_make_fit_l();
    results = results + test_left();
    results = results + test_string_dollar();

    // TODO Count the tests. Have the test_* functions return a pair or tuple of total, failures or total/pass/fail/error or exception.
    // 18 tests
    wcout << "Total tests ran: " << get<0>(results) << endl;
    wcout << "Total failures: " << get<1>(results) << endl;

    return 0;
}

size_t get_index_of(const wstring& text, const wstring& search, size_t start) {
    return text.find(search, start);
}

wstring word_wrap(const wstring& text, int maxWidth) {
    wstring output = L"";
    wstring thisLine = L"";
    wstring nextChunk = L"";
    int32_t thisLineStartPosition = 0;
    int32_t thisLineCurrentPosition = 0;
    int32_t nextSpace = -1;
    int32_t textLength = text.size();
    size_t thisLineLength = 0;

    bool done = false;

    while (!done) {
        nextSpace = get_index_of(text, L" ", thisLineCurrentPosition);
        if (nextSpace < 0) {
            nextSpace = textLength;
        }
        nextChunk = get_substring(text, thisLineCurrentPosition, nextSpace - thisLineCurrentPosition);
        auto nextChunkLength = nextChunk.size();
        if (nextChunkLength > 0) {
            auto needsSpace = thisLine.size() > 0;
            if (needsSpace) {
                thisLine = thisLine + L" ";
            }
            thisLineLength = thisLine.size();
            if (nextChunkLength > maxWidth) {
                nextChunk = get_substring(text, thisLineCurrentPosition, maxWidth - thisLineLength);
                nextSpace = thisLineStartPosition + maxWidth;
                thisLine = thisLine + nextChunk;
                thisLineCurrentPosition = nextSpace;
            } else if(thisLineLength + nextChunkLength > maxWidth) {
                thisLine = make_fit_l(thisLine, maxWidth, L' ');
            } else {
                thisLine = thisLine + nextChunk;
                thisLineCurrentPosition = nextSpace + 1;
            }
            thisLineLength = thisLine.size();
        } else {
            thisLineCurrentPosition = nextSpace + 1;
        }
        if (thisLineLength >= maxWidth || thisLineCurrentPosition > textLength) {
            if (thisLineCurrentPosition > textLength) {
                done = true;
            }
            thisLine = make_fit_l(thisLine, maxWidth, L'_');
            output += thisLine + (done ? L"" : L"\n");
            thisLine = L"";
            thisLineLength = thisLine.size();
            thisLineStartPosition = thisLineCurrentPosition;
        }
    }

    return output;
}

wstring string_dollar(size_t length, wchar_t ch) {
    wstring str = L"";
    for (size_t i = 0; i<length; i++) {
        str += ch;
    }
    return str;
}

wstring left(const wstring& text, size_t length) {
    return text.substr(0, length);
}

wstring make_fit_l(const wstring& text, size_t length, wchar_t paddCh) {
    return left(text + string_dollar(length, paddCh), length);
}

wstring get_substring(const wstring& text, const int32_t var1, const int32_t var2) {
    return text.substr(std::min<int32_t>(var1, text.length()-1), std::max(var2, 0));
}
