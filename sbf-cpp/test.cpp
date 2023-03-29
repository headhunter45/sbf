#define _XOPEN_SOURCE_EXTENDED
#include <iostream>
#include <cstdio>
#include <string>
#include <cstdint>
#include <vector>

// using namespace std;
using std::wcout;
using std::tuple;
using std::wcerr;
using std::wstring;
using std::endl;
using std::pair;
using std::get;
using std::make_tuple;
using std::vector;

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

// Call like this `auto results = test_fn(L"left", left, vector({pair(L"Micro", make_tuple(L"Microsoft QBasic", 5))}));`
template<typename _T1, typename F, typename... T2>
test_method_result test_fn(wstring testName, F f, vector<pair<_T1, tuple<T2...>>> tests) {
    size_t testsRun = 0;
    uint32_t failures = 0;
    wcout << L"Testing function " << testName << endl;

    for_each(tests.begin(), tests.end(), [&testsRun, &failures, testName, &f](pair<_T1, tuple<T2...>> data) {
        const auto& expected = data.first;
        const auto& actual = std::apply(f, data.second);
        testsRun++;
        wcout << "Expected: " << expected << endl;
        wcout << "Actual:   " << actual << endl;
        failures += do_pass_fail(expected == actual);
        if (expected!=actual) {
            wcerr << testName << L" failed for " << get<0>(data.second) << endl;
        }
    });

    wcout << failures << L" failures" << endl;
    return make_tuple(testsRun, failures);
}

test_method_result operator+(const test_method_result& first, const test_method_result second) {
    return make_tuple(get<0>(first) + get<0>(second), get<1>(first) + get<1>(second));
}

// TODO: define operator<< for std::tuple
// TODO: Define operator+= for test_method_result

int main(int argc, char* argv[]) {
    // TODO: Come up with a good way to enable/disable tests.
    // Maybe replace the expected, params pairs with another tuple for enabled, expected, params.
    // Maybe have the test functions take an enabled bool param.

    setlocale(LC_ALL, "");

    test_method_result results;

    wstring longText = L"Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.";
    results = results + test_fn(L"get_index_of", get_index_of,
        vector<pair<size_t, tuple<wstring, wstring, size_t>>>({
        pair(22, make_tuple(longText, L"dummy", 0)),
        pair(-1, make_tuple(longText, L"acid", 0)),
        pair(120, make_tuple(longText, L"dummy", 100)),
        pair(-1, make_tuple(longText, L"dummy", longText.size())),
        pair(6, make_tuple(L"these are words", L"are", 0)),
        pair(4, make_tuple(L"one two one two", L"two", 0)),
        pair(12, make_tuple(L"one two one two", L"two", 5)),
    }));

    results = results + test_fn(L"get_substring", get_substring, vector({
        pair(L"234", make_tuple(L"1234567890", 1, 3)),
        pair(L"Paris", make_tuple(L"Where is Paris?", 10-1, 5)),
    }));

    results = results + test_fn(L"left", left, vector({
        pair(L"Micro", make_tuple(L"Microsoft QBasic", 5)),
    }));

    results = results + test_fn(L"make_fit_l", make_fit_l, vector({
        pair(L"12___", make_tuple(L"12", 5, L'_')),
    }));

    results = results + test_fn(L"string_dollar", string_dollar, vector({
        pair(L"AAAAA", make_tuple(5, L'A')),
    }));

    results = results + test_fn(L"word_wrap", word_wrap, vector({
        pair(L"0123_", make_tuple(L"0123", 5)),
        pair(L"01234", make_tuple(L"01234", 5)),
        pair(L"01234\n5____", make_tuple(L"012345", 5)),
        pair(L"01234\n56789\n0____", make_tuple(L"01234567890", 5)),
        pair(L"01 23\n45 67\n89 01", make_tuple(L"01 23 45 67 89 01", 5)),
        pair(L"01 34\n67 90\n23 56\n89___", make_tuple(L"01 34 67 90 23 56    89      ", 5)),
    }));

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
