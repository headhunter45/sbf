#ifndef BACKGROUNDS_H__
#define BACKGROUNDS_H__
#include <string>
#include <vector>

namespace SBF {
    const int kBackgroundPoints = 5;
    const int kBackgroundAlliesId = 1;
    const std::wstring kBackgroundAlliesLabel = L"Allies";
    const int kBackgroundContactsId = 2;
    const std::wstring kBackgroundContactsLabel = L"Contacts";
    const int kBackgroundFameId = 3;
    const std::wstring kBackgroundFameLabel = L"Fame";
    const int kBackgroundGenerationId = 4;
    const std::wstring kBackgroundGenerationLabel = L"Generation";
    const int kBackgroundHerdId = 5;
    const std::wstring kBackgroundHerdLabel = L"Herd";
    const int kBackgroundInfluenceId = 6;
    const std::wstring kBackgroundInfluenceLabel = L"Influence";
    const int kBackgroundMentorId = 7;
    const std::wstring kBackgroundMentorLabel = L"Mentor";
    const int kBackgroundResourcesId = 8;
    const std::wstring kBackgroundResourcesLabel = L"Resources";
    const int kBackgroundRetainersId = 9;
    const std::wstring kBackgroundRetainersLabel = L"Retainers";
    const int kBackgroundStatusId = 10;
    const std::wstring kBackgroundStatusLabel = L"Status";
    const int kBackgroundsCount = 10;
    const std::wstring kBackgroundLabels[] = {
        L"",
        kBackgroundAlliesLabel,
        kBackgroundContactsLabel,
        kBackgroundFameLabel,
        kBackgroundGenerationLabel,
        kBackgroundHerdLabel,
        kBackgroundInfluenceLabel,
        kBackgroundMentorLabel,
        kBackgroundResourcesLabel,
        kBackgroundRetainersLabel,
        kBackgroundStatusLabel,
    };
    const std::wstring& GetBackgroundLabel(int backgroundId);
    void FillBackgroundLabels(std::vector<std::wstring> backgroundLabels);
} // End namespace SBF
#endif // End !defined BACKGROUNDS_H__
