#ifndef VIRTUES_H__
#define VIRTUES_H__
#include <string>
#include <vector>

namespace SBF {
    const int kVirtuePoints = 7;
    const int kVirtueSelfControlId = 1;
    const std::wstring kVirtueSelfControlLabel = L"Self-Control";
    const int kVirtueCourageId = 2;
    const std::wstring kVirtueCourageLabel = L"Courage";
    const int kVirtueConscienceId = 3;
    const std::wstring kVirtueConscienceLabel = L"Conscience";
    const int kVirtuesCount = 3;
    const std::wstring kVirtues[] = {
        L"",
        kVirtueSelfControlLabel,
        kVirtueCourageLabel,
        kVirtueConscienceLabel,
    };
    const std::wstring GetVirtueLabel(int virtueId);
    void FillVirtueLabels(std::vector<std::wstring> virtueLabels);
} // End namespace SBF
#endif // End !defined VIRTUES_H__
