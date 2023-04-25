#define _XOPEN_SOURCE_EXTENDED
#include "Utils.h"

#include <cstdint>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace SBF;

namespace SBF {
namespace {
using std::ostringstream;
using std::string;
using std::vector;
}  // End namespace

vector<string> WordWrap(const string& text, const size_t max_width) {
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
    nextSpace = GetIndexOf(text, " ", thisLineCurrentPosition);
    if (nextSpace < 0) {
      nextSpace = textLength;
    }
    nextChunk = GetSubstring(text, thisLineCurrentPosition, nextSpace - thisLineCurrentPosition);
    auto nextChunkLength = nextChunk.size();
    if (nextChunkLength > 0) {
      auto needsSpace = thisLine.size() > 0;
      if (needsSpace) {
        thisLine = thisLine + " ";
      }
      thisLineLength = thisLine.size();
      if (nextChunkLength > max_width) {
        nextChunk = GetSubstring(text, thisLineCurrentPosition, max_width - thisLineLength);
        nextSpace = thisLineStartPosition + max_width;
        thisLine = thisLine + nextChunk;
        thisLineCurrentPosition = nextSpace;
      } else if (thisLineLength + nextChunkLength > max_width) {
        thisLine = MakeFitL(thisLine, max_width, L' ');
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
      thisLine = MakeFitL(thisLine, max_width, L'_');
      output += thisLine + (done ? "" : "\n");
      lines.push_back(thisLine);
      thisLine = "";
      thisLineLength = thisLine.size();
      thisLineStartPosition = thisLineCurrentPosition;
    }
  }

  return lines;
}

string RepeatChar(const size_t length, const char ch) {
  if (ch == '\0') {
    return RepeatChar(length, ' ');
  }

  string str = "";
  for (size_t i = 0; i < length; i++) {
    str += ch;
  }
  return str;
}

string Left(const string& text, const size_t length) {
  return text.substr(0, length);
}

string Right(const string& text, const size_t length) {
  size_t text_length = text.size();
  size_t starting_position = text_length - length;
  if (text_length >= length) {
    return text.substr(starting_position);
  } else {
    return text;
  }
}

string MakeFitC(const string& text, const size_t length, const char pad_character) {
  size_t text_length = text.size();
  size_t left_pad_length = length >= text_length ? (length - text_length) / 2 : 0;
  size_t right_pad_length = (length >= text_length + left_pad_length) ? (length - text_length - left_pad_length) : 0;
  string left_pad = RepeatChar(left_pad_length, pad_character != '\0' ? pad_character : ' ');
  string right_pad = RepeatChar(right_pad_length, pad_character != '\0' ? pad_character : ' ');
  size_t total_chop = (text_length >= length) ? text_length - length : 0;
  size_t left_chop = total_chop / 2;  // + 1
  string ret = left_pad + (text == "" ? "" : text.substr(left_chop, length)) + right_pad;
  return ret;
}

std::string MakeFitB(const std::string& prefix,
                     const std::string& suffix,
                     const size_t length,
                     const char pad_character) {
  return MakeFitL(MakeFitL(prefix, length - suffix.size(), pad_character != '\0' ? pad_character : ' ') + suffix,
                  length,
                  pad_character != '\0' ? pad_character : ' ');
}

string MakeFitL(const string& text, const size_t length, const char pad_character) {
  return Left(text + RepeatChar(length, pad_character != '\0' ? pad_character : ' '), length);
}

string MakeFitR(const string& text, const size_t length, const char pad_character) {
  return Right(RepeatChar(length, pad_character != '\0' ? pad_character : ' ') + text, length);
}

string GetSubstring(const string& text, const size_t start, const size_t length) {
  return text.substr(std::min<size_t>(start, text.length()), std::max<size_t>(length, 0));
}

size_t GetIndexOf(const string& text, const string& search, const size_t start) {
  return text.find(search, start);
}

bool is_whitespace(char ch) {
  return ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n' || ch == '\f' || ch == '\v';
}

string LeftTrim(const string& text) {
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

string RightTrim(const string& text) {
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

string ToLower(const string& text) {
  ostringstream os;
  for_each(text.begin(), text.end(), [&os](unsigned char ch) { os << (char)tolower(ch); });
  return os.str();
}
}  // End namespace SBF
