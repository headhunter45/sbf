#ifndef UTILS_H__
#define UTILS_H__
#include <string>

namespace SBF {
    using std::wstring;

    size_t get_index_of(const wstring& text, const wstring& search, size_t start);
    wstring word_wrap(const wstring& text, int maxWidth);
    wstring get_substring(const wstring& text, int32_t var1, int32_t var2);
    wstring make_fit_l(const wstring& text, size_t length, wchar_t paddCh);
    wstring left(const wstring& text, size_t length);
    wstring string_dollar(size_t length, wchar_t ch);

} // End namespace SBF
#endif // End !defined UTILS_H__
