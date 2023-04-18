#include "Disciplines.h"
#include <string>
#include <vector>

namespace SBF {
using std::string;
using std::vector;

string GetDisciplineLabel(int disciplineId) {
    if (disciplineId > 0 && disciplineId <= kDisciplinesCount) {
        return kDisciplines[disciplineId];
    }

    return "";
}

void FillDisciplineLabels(vector<string>& labels) {
    labels.clear();
    for (int id = 1; id <= kDisciplinesCount; id++) {
        labels.push_back(GetDisciplineLabel(id));
    }
}
} // End namespace SBF
