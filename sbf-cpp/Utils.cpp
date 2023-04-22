#define _XOPEN_SOURCE_EXTENDED
#include "Utils.h"

#include <cstdint>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#include "test.h"

using namespace SBF;
using namespace Test;

namespace SBF {
using std::string;

string word_wrap(const string& text, const size_t max_width) {
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
      if (nextChunkLength > max_width) {
        nextChunk = get_substring(text, thisLineCurrentPosition, max_width - thisLineLength);
        nextSpace = thisLineStartPosition + max_width;
        thisLine = thisLine + nextChunk;
        thisLineCurrentPosition = nextSpace;
      } else if (thisLineLength + nextChunkLength > max_width) {
        thisLine = make_fit_l(thisLine, max_width, L' ');
      } else {
        thisLine = thisLine + nextChunk;
        thisLineCurrentPosition = nextSpace + 1;
      }
      thisLineLength = thisLine.size();
    } else {
      thisLineCurrentPosition = nextSpace + 1;
    }
    if (thisLineLength >= max_width || thisLineCurrentPosition > textLength) {
      if (thisLineCurrentPosition > textLength) {
        done = true;
      }
      thisLine = make_fit_l(thisLine, max_width, L'_');
      output += thisLine + (done ? "" : "\n");
      thisLine = "";
      thisLineLength = thisLine.size();
      thisLineStartPosition = thisLineCurrentPosition;
    }
  }

  return output;
}

string string_dollar(const size_t length, const char ch) {
  if (ch == '\0') {
    return string_dollar(length, ' ');
  }

  string str = "";
  for (size_t i = 0; i < length; i++) {
    str += ch;
  }
  return str;
}

string left(const string& text, const size_t length) {
  return text.substr(0, length);
}

string make_fit_l(const string& text, const size_t length, const char pad_character) {
  return left(text + string_dollar(length, pad_character != '\0' ? pad_character : ' '), length);
}

string get_substring(const string& text, const size_t start, const size_t length) {
  return text.substr(std::min<size_t>(start, text.length()), std::max<size_t>(length, 0));
}

size_t get_index_of(const string& text, const string& search, const size_t start) {
  return text.find(search, start);
}
}  // End namespace SBF
