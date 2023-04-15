#ifndef GENDERS_H__
#define GENDERS_H__
#include <string>
#include <vector>

namespace SBF {
    const int kGenderMaleId = 1;
    const std::string kGenderMaleLabel = "Male";
    const int kGenderFemaleId = 2;
    const std::string kGenderFemaleLabel = "Female";
    const int kGenderTransMaleId = 3;
    const std::string kGenderTransMaleLabel = "Trans-Male";
    const int kGenderTransFemaleId = 4;
    const std::string kGenderTransFemaleLabel = "Trans-Female";
    const int kGenderNonBinaryId = 5;
    const std::string kGenderNonBinaryLabel = "Non-Binary";
    const int kGendersCount = 5;
    const std::string kGenderLabels[] = {
        "",
        kGenderMaleLabel,
        kGenderFemaleLabel,
        kGenderTransMaleLabel,
        kGenderTransFemaleLabel,
        kGenderNonBinaryLabel,
    };
    const std::string& GetGenderLabel(int genderId);
    void FillGenderLabels(std::vector<std::string> genderLabels);
} // End namespace SBF
#endif // End !defined GENDERS_H__
