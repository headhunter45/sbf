#define _XOPEN_SOURCE_EXTENDED
#include <iostream>
#include <cstdio>
#include <string>
#include <cstdint>

using namespace std;

int32_t get_index_of(wstring text, wstring search, uint32_t start);
int32_t get_index_of(const wchar_t* text, size_t size, const wchar_t* search, uint32_t start);
wstring make_wrap_lines(wstring text, int maxWidth, int maxLines);
wstring word_wrap(const wstring& text, int maxWidth);
wstring get_substring(wstring text, int32_t var1, int32_t var2);
wstring make_fit_l(wstring text, size_t length, wchar_t paddCh);
wstring left(wstring text, size_t length);
wstring stringDollar(size_t length, wchar_t ch);

int main(int argc, char* argv[]) {

    setlocale(LC_ALL, "");
    /*
    auto longText = L"Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.";
    auto shortText = L"dummy";
    auto len = wcslen(longText);
    auto firstIndex = get_index_of(longText, len, shortText, 0);
    auto secondIndex = get_index_of(longText, len, L"acid", 0);
    auto thirdIndex = get_index_of(longText, len, shortText, 100);
    auto fourthIndex = get_index_of(longText, len, shortText, len);
    auto pattern = L"test 1: %03i, test 2: %03i, test 3: %03i, test 4: %03i";
    wchar_t expectedOutput[2048] = {0};
    wchar_t actualOutput[2048] = {0};
    swprintf(expectedOutput, sizeof(expectedOutput), pattern, 22, -1, 120, -1);
    swprintf(actualOutput, sizeof(actualOutput), pattern, firstIndex, secondIndex, thirdIndex, fourthIndex);

    wcout << "Expected: " << expectedOutput << endl;
    wcout << "Actual:   " << actualOutput << endl;
    */

    // wcout << stringDollar(5, L'A') << endl; // Expected "AAAAA"
    // wcout << left(L"Microsoft QBasic", 5) << endl; // Expected "Micro"
    // wcout << make_fit_l(L"12", 5, L'_') << endl; // Expected "12___"
    // wcout << get_substring(L"1234567890", 1, 3) << endl; // Expected "234"
    // wcout << get_substring(L"Where is Paris?", 10-1, 5) << endl; // Expected "Paris"
    // wstring s1 = L"these are words";
    // wstring t1 = L"are";
    // wstring s2 = L"one two one two";
    // wstring t2 = L"two";
    // wcout << get_index_of(s1, t1, 0) << endl; // Expected 6
    // wcout << get_index_of(s1.c_str(), s1.size(), t1.c_str(), 0) << endl; // Expected 6
    // wcout << get_index_of(s2, t2, 0) << endl; // Expected 4
    // wcout << get_index_of(s2, t2, 5) << endl; // Expected 12
    // wcout << get_index_of(s2.c_str(), s2.size(), t2.c_str(), 0) << endl; // Expected 4
    // wcout << get_index_of(s2.c_str(), s2.size(), t2.c_str(), 5) << endl; // Expected 12

    wstring output = L"";
    wstring testStrings[] = {
        L"0123",
        L"01234",
        L"012345",
        L"01234567890",
        L"01 23 45 67 89 01",
        L"01 34 67 90 23 56 89",
    };
    int maxWidth = 5;
    int maxLines = 3;
    
    size_t i = 0;
    for (i=0; i<6; i++) {
        output = make_wrap_lines(testStrings[i], maxWidth, maxLines);
        wcout << output << endl;
    }

    return 0;
}

int32_t get_index_of(const wchar_t* text, size_t size, const wchar_t* search, uint32_t start) {
    if (start >= size) { return -1;}
    const wchar_t* base = text + start;
    auto substr = wcsstr(base, search);
    if (substr == nullptr) { return -1; }
    auto index = substr - text;
    return index;
}

int32_t get_index_of(wstring text, wstring search, uint32_t start) {
    return text.find(search, start);
}

wstring word_wrap(const wstring& text, int maxWidth) {
    return L"";
}

/*
uint32_t word_wrap(wchar_t* dest, size_t size, const wchar_t* text, uint32_t columns) {
    uint32_t lineCount = 0;
    uint32_t thisLineStartPosition = 0;
    uint32_t thisLineCurrentPosition = 0;
    int32_t nextSpace = -1;
    size_t textLength = wcslen(text);
    wchar_t thisLine[2048] = {0};
    wchar_t nextChunk[2048] = {0};

    bool done = false;
    while (!done) {
        nextSpace = get_index_of(text, size, L" ", thisLineCurrentPosition);
        done = true;
    }

    return 0;
*/

wstring make_wrap_lines(wstring text, int maxWidth, int maxLines) {
    // ReDim output(maxLines) As String
    wstring output = L"";
    int32_t lineCount = 0;
    wstring thisLine = L"";
    wstring nextChunk = L"";
    int32_t thisLineStartPosition = 0;
    int32_t thisLineCurrentPosition = 0;
    int32_t nextSpace = -1;
    int32_t textLength = text.size();
    size_t thisLineLength = 0;

    while (lineCount < maxLines) {
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
            thisLine = make_fit_l(thisLine, maxWidth, L'_');
            output += thisLine + L"\n";
            lineCount = lineCount + 1;
            thisLine = L"";
            thisLineLength = thisLine.size();
            thisLineStartPosition = thisLineCurrentPosition;
        }
    }

    return output;
}

/*
//     Sub MakeWrapLines (lines() As String, text As String, maxWidth As Integer, maxLines As Integer)
//     ReDim lines(maxLines) As String
//     lineCount = 0
//     thisLine$ = ""
//     nextChunk$ = ""
//     thisLineStartPosition = 0
//     thisLineCurrentPosition = 0
//     nextSpace = -1
//     textLength = Len(text)

//     While (lineCount < maxLines)
//         nextSpace = GetIndexOf(text, " ", thisLineCurrentPosition)
//         If nextSpace < 0 Then nextSpace = textLength
//         nextChunk$ = GetSubstring(text, thisLineCurrentPosition, nextSpace - thisLineCurrentPosition)
//         nextChunkLength = Len(nextChunk$)
//         If nextChunkLength > 0 Then
//             needsSpace = Len(thisLine$) > 0
//             If needsSpace Then
//                 thisLine$ = thisLine$ + " "
//             End If
//             thisLineLength = Len(thisLine$)
//             If nextChunkLength > maxWidth Then
//                 nextChunk$ = GetSubstring(text, thisLineCurrentPosition, maxWidth - thisLineLength)
//                 nextSpace = thisLineStartPosition + maxWidth
//                 thisLine$ = thisLine$ + nextChunk$
//                 thisLineCurrentPosition = nextSpace
//             ElseIf thisLineLength + nextChunkLength > maxWidth Then
//                 thisLine$ = MakeFitL$(thisLine$, maxWidth, " ")
//             Else
//                 thisLine$ = thisLine$ + nextChunk$
//                 thisLineCurrentPosition = nextSpace + 1
//             End If
//             thisLineLength = Len(thisLine$)
//         Else
//             thisLineCurrentPosition = nextSpace + 1
//         End If
//         If thisLineLength >= maxWidth Or thisLineCurrentPosition > textLength Then
//             thisLine$ = MakeFitL$(thisLine$, maxWidth, "_")
//             lines(lineCount) = thisLine$
//             lineCount = lineCount + 1
//             thisLine$ = ""
//             thisLineLength = Len(thisLine$)
//             thisLineStartPosition = thisLineCurrentPosition
//         End If
//     Wend
// End Sub
}
*/

wstring stringDollar(size_t length, wchar_t ch) {
    wstring str = L"";
    for (size_t i = 0; i<length; i++) {
        str += ch;
    }
    return str;
}

wstring left(wstring text, size_t length) {
    return text.substr(0, length);
}

wstring make_fit_l(wstring text, size_t length, wchar_t paddCh) {
    return left(text + stringDollar(length, paddCh), length);
}

wstring get_substring(wstring text, int32_t var1, int32_t var2) {
    // wcout << L"get_substring|" << text << "|" << var1 << "|" << var2 << endl;
    return text.substr(std::min<int32_t>(var1, text.length()-1), std::max(var2, 0));
}
