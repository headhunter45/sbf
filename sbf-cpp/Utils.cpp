#define _XOPEN_SOURCE_EXTENDED
#include <iostream>
#include <cstdio>
#include <string>
#include <cstdint>
#include <vector>
#include "Utils.h"
#include "test.h"

using namespace SBF;
using namespace Test;

namespace SBF {
    using std::wcout;
    using std::tuple;
    using std::wcerr;
    using std::wstring;
    using std::endl;
    using std::pair;
    using std::get;
    using std::make_tuple;
    using std::vector;

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

    size_t get_index_of(const wstring& text, const wstring& search, size_t start) {
        return text.find(search, start);
    }
} // End namespace SBF

// test_method_result main_test_Utils(int argc, char** argv) {
//     test_method_result results = std::make_tuple(1, 0);
    
//     return results;
// }
