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
namespace {
using std::string;
using std::to_string;
}  // End namespace

vector<string> word_wrap(const string& text, const size_t max_width) {
  vector<string> lines;
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
      lines.push_back(thisLine);
      thisLine = "";
      thisLineLength = thisLine.size();
      thisLineStartPosition = thisLineCurrentPosition;
    }
  }

  return lines;
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

string right(const string& text, const size_t length) {
  size_t text_length = text.size();
  size_t starting_position = text_length - length;
  if (text_length >= length) {
    return text.substr(starting_position);
  } else {
    return text;
  }
}

string make_fit_c(const string& text, const size_t length, const char pad_character) {
  size_t text_length = text.size();
  size_t left_pad_length = length >= text_length ? (length - text_length) / 2 : 0;
  size_t right_pad_length = (length >= text_length + left_pad_length) ? (length - text_length - left_pad_length) : 0;
  string left_pad = string_dollar(left_pad_length, pad_character != '\0' ? pad_character : ' ');
  string right_pad = string_dollar(right_pad_length, pad_character != '\0' ? pad_character : ' ');
  size_t total_chop = (text_length >= length) ? text_length - length : 0;
  size_t left_chop = total_chop / 2;  // + 1
  string ret = left_pad + (text == "" ? "" : text.substr(left_chop, length)) + right_pad;
  return ret;
}

std::string make_fit_b(const std::string& prefix,
                       const std::string& suffix,
                       const size_t length,
                       const char pad_character) {
  return make_fit_l(make_fit_l(prefix, length - suffix.size(), pad_character != '\0' ? pad_character : ' ') + suffix,
                    length,
                    pad_character != '\0' ? pad_character : ' ');
}

string make_fit_l(const string& text, const size_t length, const char pad_character) {
  return left(text + string_dollar(length, pad_character != '\0' ? pad_character : ' '), length);
}

string make_fit_r(const string& text, const size_t length, const char pad_character) {
  return right(string_dollar(length, pad_character != '\0' ? pad_character : ' ') + text, length);
}

string get_substring(const string& text, const size_t start, const size_t length) {
  return text.substr(std::min<size_t>(start, text.length()), std::max<size_t>(length, 0));
}

size_t get_index_of(const string& text, const string& search, const size_t start) {
  return text.find(search, start);
}

bool is_whitespace(char ch) {
  return ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n' || ch == '\f' || ch == '\v';
}

string left_trim(const string& text) {
  if (text == "") {
    return "";
  }
  size_t index = 0;
  size_t length = text.size();
  while (index < length) {
    if (is_whitespace(text.at(index))) {
      index++;
    } else {
      return text.substr(index);
    }
  }
  return "";
}

string right_trim(const string& text) {
  if (text == "") {
    return "";
  }
  size_t last_index = text.size() - 1;
  size_t index = last_index;

  while (index != string::npos) {
    if (is_whitespace(text.at(index))) {
      index--;
    } else {
      return text.substr(0, index + 1);
    }
  }
  return "";
}

std::string itos(int i) {
  return to_string(i);
}
}  // End namespace SBF
