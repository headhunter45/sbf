#include "Backgrounds.h"
#include <string>
#include <vector>

namespace SBF {
std::string GetBackgroundLabel(int backgroundId) {
    if (backgroundId > 0 && backgroundId <= kBackgroundsCount) {
        return kBackgroundLabels[backgroundId];
    }
    return "";
}

void FillBackgroundLabels(std::vector<std::string>& labels) {
    labels.clear();
    for (int id = 1; id <= kBackgroundsCount; id++) {
        labels.push_back(kBackgroundLabels[id]);
    }
}
} // End namespace SBF
