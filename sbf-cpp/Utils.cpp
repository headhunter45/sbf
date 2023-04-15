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
    using std::cout;
    using std::tuple;
    using std::wcerr;
    using std::string;
    using std::endl;
    using std::pair;
    using std::get;
    using std::make_tuple;
    using std::vector;

    string word_wrap(const string& text, int maxWidth) {
        string output = "";
        string thisLine = "";
        string nextChunk = "";
        int32_t thisLineStartPosition = 0;
        int32_t thisLineCurrentPosition = 0;
        int32_t nextSpace = -1;
        int32_t textLength = text.size();
        size_t thisLineLength = 0;

        bool done = false;

        while (!done) {
            nextSpace = get_index_of(text, " ", thisLineCurrentPosition);
            if (nextSpace < 0) {
                nextSpace = textLength;
            }
            nextChunk = get_substring(text, thisLineCurrentPosition, nextSpace - thisLineCurrentPosition);
            auto nextChunkLength = nextChunk.size();
            if (nextChunkLength > 0) {
                auto needsSpace = thisLine.size() > 0;
                if (needsSpace) {
                    thisLine = thisLine + " ";
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
                output += thisLine + (done ? "" : "\n");
                thisLine = "";
                thisLineLength = thisLine.size();
                thisLineStartPosition = thisLineCurrentPosition;
            }
        }

        return output;
    }

    string string_dollar(size_t length, char ch) {
        string str = "";
        for (size_t i = 0; i<length; i++) {
            str += ch;
        }
        return str;
    }

    string left(const string& text, size_t length) {
        return text.substr(0, length);
    }

    string make_fit_l(const string& text, size_t length, char paddCh) {
        return left(text + string_dollar(length, paddCh), length);
    }

    string get_substring(const string& text, const int32_t var1, const int32_t var2) {
        return text.substr(std::min<int32_t>(var1, text.length()-1), std::max(var2, 0));
    }

    size_t get_index_of(const string& text, const string& search, size_t start) {
        return text.find(search, start);
    }
} // End namespace SBF

// test_method_result main_test_Utils(int argc, char** argv) {
//     test_method_result results = std::make_tuple(1, 0);
    
//     return results;
// }
