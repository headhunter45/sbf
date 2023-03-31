#ifndef GENDERS_H__
#define GENDERS_H__
#include <string>
#include <vector>

namespace SBF {
    const int kGenderMaleId = 1;
    const std::wstring kGenderMaleLabel = L"Male";
    const int kGenderFemaleId = 2;
    const std::wstring kGenderFemaleLabel = L"Female";
    const int kGenderTransMaleId = 3;
    const std::wstring kGenderTransMaleLabel = L"Trans-Male";
    const int kGenderTransFemaleId = 4;
    const std::wstring kGenderTransFemaleLabel = L"Trans-Female";
    const int kGenderNonBinaryId = 5;
    const std::wstring kGenderNonBinaryLabel = L"Non-Binary";
    const int kGendersCount = 5;
    const std::wstring kGenderLabels[] = {
        L"",
        kGenderMaleLabel,
        kGenderFemaleLabel,
        kGenderTransMaleLabel,
        kGenderTransFemaleLabel,
        kGenderNonBinaryLabel,
    };
    const std::wstring& GetGenderLabel(int genderId);
    void FillGenderLabels(std::vector<std::wstring> genderLabels);
} // End namespace SBF
#endif // End !defined GENDERS_H__
